# Versão 1.5 
# Melhoradas as cores, mas a palette ainda não está 100% idêntica a da versão Atari.

"""
Demon Attack - Python/Pygame Port
Original Java version: Copyright (C) 2011 meatfighter.com
Python port based on the original logic.

Requer: pip install pygame
Controles:
  Seta Esquerda / A  - Mover para esquerda
  Seta Direita / D   - Mover para direita
  B ou Espaço        - Atirar
  P                  - Pausar
"""

import pygame
import math
import random
import sys

# ---------------------------------------------------------------------------
# Constantes
# ---------------------------------------------------------------------------
SCALE_X        = 4
SCALE_Y        = 2
GAME_W, GAME_H = 160, 210
WIN_W,  WIN_H  = GAME_W * SCALE_X, GAME_H * SCALE_Y

FPS            = 60
DEMON_REFORM_SPEED = 0.035
BULLET_DELTA_ANGLE = 0.5

# Índices para arrays de bala (enemy)
BULLET_X       = 0
BULLET_Y       = 1
BULLET_ANGLE   = 2
BULLET_DEMON_X = 3
BULLET_OFFSET_X= 4
BULLET_RADIUS  = 5

# Índices para arrays de demônio
DEMON_X             = 0
DEMON_Y             = 1
DEMON_SPRITE        = 2
DEMON_ROW           = 3
DEMON_START_Y       = 4
DEMON_DELTA_Y       = 5
DEMON_PERCENT_Y     = 6
DEMON_DELTA_PERCENT_Y=7
DEMON_START_X       = 8
DEMON_DELTA_X       = 9
DEMON_PERCENT_X     = 10
DEMON_DELTA_PERCENT_X=11
DEMON_FORMING       = 12
DEMON_X2            = 13
DEMON_DELTA_X2      = 14
DEMON_HIDDEN        = 15
DEMON_EXPLODING     = 16
DEMON_EXPLODING_INDEX=17
DEMON_DELAY         = 18
DEMON_BIRD          = 19
DEMON_SHOOTER       = 20
DEMON_DIVING        = 21
DEMON_DIVING_Y      = 22

SCORE_COLOR  = (0xDF, 0xB7, 0x55)
PLAYER_COLOR = (0xB8, 0x46, 0xA2)
PLAYER_BULLET_COLOR = (0xD4, 0x8C, 0xFC)
ENEMY_BULLET_COLOR  = (0xFC, 0x90, 0x90)


# ---------------------------------------------------------------------------
# Utilitários de cor
# ---------------------------------------------------------------------------
def hsb_to_rgb(h, s, v):
    """Converte HSB/HSV para RGB (componentes 0-1)."""
    import colorsys
    r, g, b = colorsys.hsv_to_rgb(h, s, v)
    return (int(r * 255), int(g * 255), int(b * 255))


def argb_int_to_rgb(argb):
    r = (argb >> 16) & 0xFF
    g = (argb >> 8)  & 0xFF
    b =  argb        & 0xFF
    return (r, g, b)


# ---------------------------------------------------------------------------
# Descompressão de sprites a partir da string S do original Java
# ---------------------------------------------------------------------------
# A string S contém dados de sprite comprimidos em Unicode (cada char = 16 bits).
# Reproduzimos a mesma string aqui.
S = (
    "\u3e00\u2626\u2626\u2626\u3e26\u1c00\u1818\u1818\u1818\u1818"
    "\u3e00\u3232\u3c30\u3202\u3e32\u3e00\u3232\u1c30\u3230\u3e32"
    "\u3200\u3232\u3232\u7e32\u3030\u3e00\u0232\u303e\u3230\u3e32"
    "\u3e00\u3232\u3e02\u3232\u3e32\u3e00\u3232\u1830\u0c18\u0c0c"
    "\u3e00\u2626\u3e26\u3232\u3e32\u3e00\u3232\u3e32\u3230\u3e32"
    "\u02fc\u9112\u9191\u9291\ufc02\u00ff\u2ac5\uea2a\u2a2a\uff00"
    "\u00ff\ua598\ub585\u99a5\uff00\u403f\u924c\u8282\u4c92\u3f40"
    "\u1414\u1414\u3636\u7777\u6363\u6363\u8010\uf840\u62c4\u0032"
    "\u2000\u8e00\uc073\u0060\u4000\u980f\ue070\u00c0\u0000\uf0c0"
    "\u2428\u0022\u6000\u26f8\u4121\u0002\uf030\u2428\u8444\u0008"
    "\u0824\u2712\uf94d\u0040\u5000\u2410\u784c\u0090\u2000\u2050"
    "\ub840\u006c\u124c\u31e1\u3219\u00e4\u0e20\ue111\u1931\u00f2"
    "\u2600\u1109\uf1e1\u00f9\ue2fc\u2242\u0412\u0008\ue418\u24c4"
    "\u2414\u0004\u2810\uc4c4\u2224\u0020\u6000\u9090\u6090\u0000"
    "\u0000\ua0c0\u00c0\u0000\u0000\u8080\u0000\u0000\u9000\u2004"
    "\u0002\u0022\u1240\u2000\u1002\u0002\u0208\u0040\u0410\u0011"
    "\u2804\u1610\u0428\u0000\u0221\u0528\u2048\u0002\u4209\u0128"
    "\u2088\u0004\u3e08\u4163\u2241\u0000\u0000\u6b36\u4141\u0000"
    "\u6341\u1436\u0008\u0000\u0021\u0000\u0001\u0024\u0110\u0002"
    "\u4010\u0209\u0000\u2200\u0841\u0000\u0208\u4020\u0008\u0820"
    "\u0040\u0050\u4000\u8020\u0060\u0000\uc080\u0060"
)


def make_sprite(width, height, rows_data, color):
    """Cria um Surface pygame a partir de uma lista de linhas (bytes)."""
    surf = pygame.Surface((width, height), pygame.SRCALPHA)
    surf.fill((0, 0, 0, 0))
    for y, row_bits in enumerate(rows_data):
        for x in range(8):
            if row_bits & (1 << x):
                surf.set_at((x, y), color)
                if width == 16:
                    surf.set_at((15 - x, y), color)
    return surf


def decode_player_sprites():
    """Decodifica dígitos (0-9), logo IMAGIC e nave do jogador."""
    sprites = [None] * 32

    for i in range(15):
        k = 10 if i < 14 else 12
        surf = pygame.Surface((8, k), pygame.SRCALPHA)
        surf.fill((0, 0, 0, 0))
        color = SCORE_COLOR if i < 14 else PLAYER_COLOR
        for y in range(k):
            char_idx = i * 5 + (y >> 1)
            j = ord(S[char_idx])
            if y & 1:
                j >>= 8
            j &= 0xFF
            for x in range(8):
                if j & 1:
                    surf.set_at((x, y), color)
                j >>= 1
        sprites[i] = surf

    return sprites


class JavaRandom:
    """Reimplementação exata de java.util.Random (LCG de 48 bits).
    Necessária para reproduzir as paletas de cor idênticas ao jogo Java original."""
    def __init__(self, seed):
        self._seed = (seed ^ 0x5DEECE66D) & ((1 << 48) - 1)

    def _next(self, bits):
        self._seed = (self._seed * 0x5DEECE66D + 0xB) & ((1 << 48) - 1)
        return self._seed >> (48 - bits)

    def next_float(self):
        return self._next(24) / (1 << 24)


def build_palette(k):
    """Gera a paleta de 8 cores para o nível k, idêntica ao Java original."""
    rng = JavaRandom(18 + (k << 3))
    palette = [0xFF] * 8
    for _ in range(3):
        offset = 6.28 * rng.next_float()
        scale  = 0.3 * (1 + rng.next_float())
        for j in range(8):
            palette[j] = (palette[j] << 8) & 0xFFFFFF00
            val = int(180 + 75 * math.sin(scale * j + offset))
            palette[j] |= (val & 0xFF)
    return [((p >> 16) & 0xFF, (p >> 8) & 0xFF, p & 0xFF) for p in palette]


def decode_enemy_sprites(k, palette):
    """Decodifica 12 sprites inimigos para o nível k."""
    enemy_sprites = []
    for i in range(12):
        z = 16 if i < 9 else 8
        surf = pygame.Surface((z, 8), pygame.SRCALPHA)
        surf.fill((0, 0, 0, 0))
        for y in range(8):
            if i < 3:
                char_idx = 76 + 12 * ((k >> 1) % 6) + (i << 2) + (y >> 1)
            else:
                char_idx = 148 + ((i - 3) << 2) + (y >> 1)
            j = ord(S[char_idx])
            if y & 1:
                j >>= 8
            j &= 0xFF
            color = palette[7 - y]
            for x in range(8):
                if j & 1:
                    surf.set_at((x, y), color)
                    if z == 16:
                        surf.set_at((15 - x, y), color)
                j >>= 1
        enemy_sprites.append(surf)
    return enemy_sprites


def decode_player_exploding_sprites(palette):
    """Decodifica 8 sprites de explosão do jogador."""
    result = []
    for i in range(8):
        surf = pygame.Surface((16, 48), pygame.SRCALPHA)
        surf.fill((0, 0, 0, 0))
        for y in range(6):
            char_idx = 184 + i * 3 + (y >> 1)
            j = ord(S[char_idx])
            if y & 1:
                j >>= 8
            j &= 0xFF
            color = palette[7 - y]
            for x in range(8):
                if j & 1:
                    for row in range(2):
                        ry = (y << 3) + row
                        surf.set_at((x,      ry), color)
                        surf.set_at((15 - x, ry), color)
                j >>= 1
        result.append(surf)
    return result


# ---------------------------------------------------------------------------
# Criação das cores do chão e vidas extras
# ---------------------------------------------------------------------------
def build_floor_colors():
    """Retorna floor_colors[120][7]."""
    fc = []
    for i in range(120):
        row = []
        for j_idx in range(7):
            w = math.sin(6 * math.pi * i / 119)
            h_val = (234 + j_idx - (i << 1)) / 360.0
            s_val = 0.51 + 0.08 * j_idx
            v_val = 0.94 - 0.06 * j_idx - 0.25 * w * w
            row.append(hsb_to_rgb(h_val % 1.0, s_val, max(0.0, v_val)))
        fc.append(row)
    return fc


def build_extra_lives_colors():
    colors = []
    for i in range(100):
        h_val = i / 100.0
        s_val = 0.46
        v_val = 0.65 + 0.35 * math.cos(0.594245 + 0.35 * i)
        colors.append(hsb_to_rgb(h_val, s_val, max(0.0, min(1.0, v_val))))
    return colors


def build_exploding_flash_colors():
    colors = []
    for i in range(16):
        intensity = int(math.sin(0.196 * i) * 255)
        intensity = max(0, min(255, intensity))
        colors.append((intensity, intensity, intensity))
    return colors


# ---------------------------------------------------------------------------
# Classe principal do jogo
# ---------------------------------------------------------------------------
class DemonAttack:
    def __init__(self):
        pygame.init()
        self.screen = pygame.display.set_mode((WIN_W, WIN_H))
        pygame.display.set_caption("Demon Attack")
        self.clock  = pygame.time.Clock()
        self.buffer = pygame.Surface((GAME_W, GAME_H))

        # Pré-computar recursos visuais
        self.floor_colors        = build_floor_colors()
        self.extra_lives_colors  = build_extra_lives_colors()
        self.exploding_flash_colors = build_exploding_flash_colors()

        self.font = pygame.font.Font(None, 18);
        
        # Sprites do jogador / dígitos
        self.sprites = decode_player_sprites() + [None] * 17  # índices 0-31

        # Sprites de explosão do jogador (nível 2 da paleta)
        palette2 = build_palette(2)
        expl_sprites = decode_player_exploding_sprites(palette2)
        for i in range(8):
            self.sprites[15 + i] = expl_sprites[i]

        # Cache de sprites inimigos por nível
        self._enemy_sprite_cache = {}

        self._reset_state(demo=True)

    # ------------------------------------------------------------------
    def _get_enemy_sprites(self, level):
        if level not in self._enemy_sprite_cache:
            pal = build_palette(level)
            self._enemy_sprite_cache[level] = decode_enemy_sprites(level, pal)
        return self._enemy_sprite_cache[level]

    # ------------------------------------------------------------------
    def _reset_state(self, demo=False):
        self.rng              = random.Random()
        self.level            = -1
        self.score            = 0
        self.player_x         = 76
        self.player_bullet_x  = 79
        self.player_bullet_y  = 175.0
        self.player_bullet_spd= 4.0
        self.fire_released    = True
        self.advance_sprite   = 0
        self.extra_lives      = 2
        self.extra_demons     = 5
        self.next_level_delay = 1
        self.shoot_timer      = 1.0
        self.shoot_counter    = 1
        self.player_exploding = 0
        self.game_over        = 0
        self.shooting         = False
        self.shoot            = False
        self.lasers           = False
        self.tiny_enemies     = False
        self.demon_speed      = 0.0
        self.shoot_delay      = 0.0
        self.bullet_speed     = 0.0
        self.demo_mode        = demo
        self.demo_target_x    = 76
        self.demo_shoot_delay = 0
        self.game_over_delay  = 0
        self.no_shoot_delay   = 0
        self.paused           = False
        self.pause_released   = True
        self.demons           = []
        self.bullets          = []
        self.demons_in_rows   = [[] for _ in range(4)]       

    # ------------------------------------------------------------------
    def _new_demon(self, row, hidden_extra=0, sprite_override=None):
        j = 16 + self.rng.randint(0, 95)
        d = [0.0] * 32
        d[DEMON_X]          = -32.0
        d[DEMON_X2]         = 160.0
        d[DEMON_Y]          = 40.0 + (row << 5)
        d[DEMON_ROW]        = row
        d[DEMON_SPRITE]     = sprite_override if sprite_override is not None else 0
        d[DEMON_PERCENT_Y]  = 1.0
        d[DEMON_PERCENT_X]  = 0.0
        d[DEMON_FORMING]    = 1.0
        d[DEMON_DELTA_X]    = (j + 32) * DEMON_REFORM_SPEED
        d[DEMON_DELTA_X2]   = (j - 160) * DEMON_REFORM_SPEED
        d[DEMON_HIDDEN]     = 30 + hidden_extra
        return d

    # ------------------------------------------------------------------
    def _advance_level(self):
        if self.extra_lives < 6:
            self.extra_lives += 1
        self.level += 1
        if self.level == 84:
            self.game_over = 1
            return
        lv = self.level
        self.demon_speed  = (0.4 + 0.2 * lv / 11) if lv <= 11 else (0.6 + 0.2 * (lv - 11) / 72)
        self.shoot_delay  = 30 if lv > 30 else 60 - lv
        self.bullet_speed = 3.0 if lv > 11 else 1.5 + 1.5 * lv / 11
        self.lasers       = ((lv >> 1) & 1) == 1
        self.player_bullet_spd = min(8.0, 4 + 4.0 * lv / 11)
        self.extra_demons = 5
        self.tiny_enemies = (lv % 12) > 9

        # Criar 3 demônios iniciais
        for i in range(3):
            d = self._new_demon(i, hidden_extra=50 * (2 - i), sprite_override=i)
            self.demons.append(d)
            self.demons_in_rows[i].append(d)

    # ------------------------------------------------------------------
    def update(self, keys_pressed, keys_down):
        # Tecla de pausa
        if pygame.K_p not in keys_down:
            self.pause_released = True
        if self.pause_released and pygame.K_p in keys_down:
            self.pause_released = False
            self.paused = not self.paused

        # Tecla de disparo liberada
        shoot_key = pygame.K_b in keys_down or pygame.K_SPACE in keys_down
        if not shoot_key:
            self.fire_released = True

        if self.paused or self.level == 84:
            return

        # ---- Início / reinício do jogo -----------------------------------
        if self.demo_mode or self.game_over == 119:
            if self.fire_released and shoot_key:
                self.fire_released = False
                self._reset_state(demo=False)
                return

        # ---- Contagem de game over ---------------------------------------
        if self.game_over > 0:
            if self.game_over < 119:
                self.game_over += 1
                self.game_over_delay = 0
            elif self.game_over_delay < 600:
                self.game_over_delay += 1
            else:
                self._reset_state(demo=True)
            return

        # ---- Explosão do jogador -----------------------------------------
        if self.player_exploding > 0:
            # Mantém no_shoot_delay ativo durante toda a explosão para que os
            # demônios não atirem enquanto o jogador ainda não reapareceu.
            self.no_shoot_delay = max(self.no_shoot_delay, 1)
            self.player_exploding -= 1
            if self.player_exploding == 0:
                self.player_x        = 76
                self.player_bullet_x = 79
                self.player_bullet_y = 175.0
                # Margem extra de proteção após o reaparecimento.
                self.no_shoot_delay  = 30
                if not self.demo_mode:
                    if self.extra_lives == 0:
                        self.game_over = 1
                    else:
                        self.extra_lives += 1
                        
            # NÃO retorna aqui: demônios continuam se movendo normalmente.

        # ---- Movimento do jogador (apenas quando não está explodindo) -----
        elif self.player_exploding == 0:
            left_key  = pygame.K_LEFT  in keys_down or pygame.K_a in keys_down
            right_key = pygame.K_RIGHT in keys_down or pygame.K_d in keys_down

            if self.demo_mode:
                if   self.player_x < self.demo_target_x: self.player_x += 1
                elif self.player_x > self.demo_target_x: self.player_x -= 1
                else: self.demo_target_x = 25 + self.rng.randint(0, 109)

                if self.player_bullet_y == 175:
                    self.player_bullet_x = self.player_x + 3
                    self.demo_shoot_delay -= 1
                    if self.demo_shoot_delay < 0:
                        self.demo_shoot_delay = 15 + self.rng.randint(0, 29)
                        self.player_bullet_y -= 1
                elif self.player_bullet_y < 12:
                    self.player_bullet_y = 175.0
                    self.player_bullet_x = self.player_x + 3
                else:
                    self.player_bullet_y -= self.player_bullet_spd
            else:
                if left_key  and self.player_x > 25:  self.player_x -= 1
                if right_key and self.player_x < 135: self.player_x += 1

                if self.player_bullet_y == 175:
                    self.player_bullet_x = self.player_x + 3
                    if self.fire_released and shoot_key:
                        self.fire_released = False
                        self.player_bullet_y -= 1
                elif self.player_bullet_y < 12:
                    self.player_bullet_y = 175.0
                    self.player_bullet_x = self.player_x + 3
                else:
                    self.player_bullet_y -= self.player_bullet_spd

        # ---- Balas inimigas ----------------------------------------------
        i = len(self.bullets) - 1
        while i >= 0:
            bullet = self.bullets[i]
            bullet[BULLET_Y]     += self.bullet_speed
            bullet[BULLET_ANGLE] += BULLET_DELTA_ANGLE
            bullet[BULLET_X]      = (bullet[BULLET_DEMON_X]
                                     + bullet[BULLET_OFFSET_X]
                                     + (bullet[BULLET_RADIUS]
                                        if math.sin(bullet[BULLET_ANGLE]) > 0.5
                                        else 0))
            if bullet[BULLET_Y] > 190:
                self.bullets.pop(i)
                i -= 1
                continue

            # Colisão com o jogador
            if (self.player_exploding == 1
                    and bullet[BULLET_Y] <= 185
                    and bullet[BULLET_Y] >= 175
                    and bullet[BULLET_X] >= self.player_x
                    and bullet[BULLET_X] <= self.player_x + 7):
                self.bullets.clear()  # remove todas as balas para evitar hits múltiplos
                self.player_exploding = 63
                break
            i -= 1

        # ---- Padrão de disparo inimigo -----------------------------------
        self.shoot = False
        if self.no_shoot_delay > 0:
            self.no_shoot_delay -= 1
        elif self.player_exploding == 0:
            self.shoot_timer -= 1
            if self.shoot_timer <= 0:
                if self.shooting:
                    self.shoot = True
                    self.shoot_counter -= 1
                    if self.shoot_counter == 0:
                        self.shooting    = False
                        self.shoot_timer = self.shoot_delay
                    else:
                        self.shoot_timer += (2 if self.lasers else 8) / max(self.bullet_speed, 0.01)
                else:
                    self.shooting      = True
                    self.shoot_counter = ((6 if self.lasers else 3)
                                         + (min(self.level, 10) >> 1)
                                         + self.rng.randint(0, (5 if self.lasers else 2)))
                    self.shoot_timer   = 1

        # ---- Próximo nível -----------------------------------------------
        if self.next_level_delay > 0:
            if self.game_over == 0:
                self.next_level_delay -= 1
                if self.next_level_delay == 0:
                    self._advance_level()
        elif (self.extra_demons == 0 and len(self.demons) == 0
              and self.player_exploding == 0 and len(self.bullets) == 0):
            self.next_level_delay = 99
        else:
            if self.level > 3:
                # Pássaro em mergulho?
                if len(self.demons_in_rows[2]) == 1:
                    d = self.demons_in_rows[2][0]
                    if (d[DEMON_BIRD] == 1 and d[DEMON_DIVING] == 0
                            and len(self.demons_in_rows[3]) == 0):
                        self.demons_in_rows[2].remove(d)
                        self.demons_in_rows[3].append(d)
                        d[DEMON_DIVING_Y] = d[DEMON_Y]
                        d[DEMON_DIVING]   = 1
                        d[DEMON_PERCENT_X]= 0
                        d[DEMON_DELTA_X]  = (-self.demon_speed
                                             if d[DEMON_X] < self.player_x
                                             else self.demon_speed)
                        d[DEMON_ROW]      = 3

                # Demônios descem para preencher lacunas
                for ii in range(1, -1, -1):
                    if len(self.demons_in_rows[ii + 1]) == 0:
                        for jj in range(len(self.demons_in_rows[ii]) - 1, -1, -1):
                            dd = self.demons_in_rows[ii].pop(jj)
                            dd[DEMON_ROW] += 1
                            self.demons_in_rows[ii + 1].append(dd)

            # Preencher lacunas com novos demônios se disponíveis
            if self.extra_demons > 0:
                for ii in range(2, -1, -1):
                    if len(self.demons_in_rows[ii]) == 0:
                        if not self.demo_mode:
                            self.extra_demons -= 1
                        j_val = 16 + self.rng.randint(0, 95)
                        nd = [0.0] * 32
                        nd[DEMON_X]         = -32.0
                        nd[DEMON_X2]        = 160.0
                        nd[DEMON_Y]         = 40.0 + (ii << 5)
                        nd[DEMON_PERCENT_Y] = 1.0
                        nd[DEMON_PERCENT_X] = 0.0
                        nd[DEMON_FORMING]   = 1.0
                        nd[DEMON_DELTA_X]   = (j_val + 32) * DEMON_REFORM_SPEED
                        nd[DEMON_DELTA_X2]  = (j_val - 160) * DEMON_REFORM_SPEED
                        nd[DEMON_HIDDEN]    = 30
                        nd[DEMON_ROW]       = ii
                        self.demons.append(nd)
                        self.demons_in_rows[ii].append(nd)

            # ---- Atualizar demônios --------------------------------------
            i = len(self.demons) - 1
            while i >= 0:
                demon = self.demons[i]

                # Avançar sprite
                if self.advance_sprite == 0:
                    demon[DEMON_SPRITE] = (demon[DEMON_SPRITE] + 1) % 4

                if demon[DEMON_HIDDEN] > 0:
                    demon[DEMON_HIDDEN] -= 1

                elif demon[DEMON_FORMING] == 1:
                    demon[DEMON_PERCENT_X] += DEMON_REFORM_SPEED
                    demon[DEMON_X]  += demon[DEMON_DELTA_X]
                    demon[DEMON_X2] += demon[DEMON_DELTA_X2]
                    if demon[DEMON_PERCENT_X] >= 1:
                        demon[DEMON_FORMING] = 0
                        demon[DEMON_X] += 8

                elif demon[DEMON_EXPLODING] == 1:
                    demon[DEMON_DELAY] += 1
                    if demon[DEMON_DELAY] == 5:
                        demon[DEMON_DELAY] = 0
                        demon[DEMON_EXPLODING_INDEX] += 1
                        if demon[DEMON_EXPLODING_INDEX] == 3:
                            if self.level > 3 and demon[DEMON_BIRD] == 0:
                                # Criar pássaros
                                demon[DEMON_BIRD]    = 1
                                demon[DEMON_EXPLODING] = 0
                                demon[DEMON_SHOOTER] = 1
                                demon[DEMON_PERCENT_X] = 1

                                bird = [0.0] * 32
                                bird[DEMON_X]       = demon[DEMON_X] + 8
                                bird[DEMON_Y]       = demon[DEMON_Y]
                                bird[DEMON_ROW]     = demon[DEMON_ROW]
                                bird[DEMON_PERCENT_Y]= 1.0
                                bird[DEMON_PERCENT_X]= 1.0
                                bird[DEMON_BIRD]    = 1
                                self.demons.append(bird)
                                self.demons_in_rows[int(demon[DEMON_ROW])].append(bird)
                            else:
                                self.demons_in_rows[int(demon[DEMON_ROW])].remove(demon)
                                self.demons.pop(i)
                                i -= 1
                                continue

                else:
                    if demon[DEMON_DIVING] == 1:
                        demon[DEMON_Y] = (demon[DEMON_DIVING_Y]
                                         + 16 * math.sin(math.pi * demon[DEMON_PERCENT_X]))
                        demon[DEMON_DIVING_Y] += 0.25
                        demon[DEMON_PERCENT_X]+= self.demon_speed * 0.07
                        demon[DEMON_X]        += demon[DEMON_DELTA_X]
                        if demon[DEMON_PERCENT_X] >= 1:
                            demon[DEMON_PERCENT_X] = 0
                            if demon[DEMON_DELTA_X] < 0:
                                if demon[DEMON_X] < self.player_x - 8:
                                    demon[DEMON_DELTA_X] = self.demon_speed
                            else:
                                if demon[DEMON_X] > self.player_x + 8:
                                    demon[DEMON_DELTA_X] = -self.demon_speed

                        # Colisão mergulho x jogador
                        if (self.player_exploding == 1
                                and demon[DEMON_Y] >= 171
                                and demon[DEMON_Y] <= 185
                                and demon[DEMON_X] + 7 >= self.player_x
                                and demon[DEMON_X] <= self.player_x + 7):
                            if self.demons_in_rows[3]:
                                self.demons_in_rows[3].pop(0)
                            self.demons.pop(i)
                            self.bullets.clear()  # remove todas as balas para evitar hits múltiplos
                            self.player_exploding = 63
                            i -= 1
                            continue
                        elif demon[DEMON_Y] > 182:
                            if self.demons_in_rows[3]:
                                self.demons_in_rows[3].pop(0)
                            self.demons.pop(i)
                            i -= 1
                            continue

                    else:
                        shooter = (demon[DEMON_ROW] == 2
                                   and (demon[DEMON_BIRD] == 0
                                        or demon[DEMON_SHOOTER] == 1)
                                   and len(self.demons_in_rows[3]) == 0)

                        # Disparo inimigo
                        if self.shooting and shooter:
                            if (False):
                                if self.lasers or self.rng.random() < 0.5:
                                    b1 = [0.0] * 32
                                    b1[BULLET_DEMON_X]  = demon[DEMON_X]
                                    offset1 = ((4 if (self.lasers or demon[DEMON_BIRD] == 0) else 0)
                                               + (0 if self.lasers else self.rng.randint(0, 2)))
                                    b1[BULLET_OFFSET_X] = offset1
                                    b1[BULLET_X]        = demon[DEMON_X] + offset1
                                    b1[BULLET_Y]        = demon[DEMON_Y] + 8
                                    b1[BULLET_RADIUS]   = 1 if (demon[DEMON_BIRD] == 1) else (0 if self.lasers else 1)
                                    self.bullets.append(b1)

                                    if demon[DEMON_BIRD] == 0 or not self.lasers:
                                        b2 = [0.0] * 32
                                        b2[BULLET_DEMON_X]  = demon[DEMON_X]
                                        offset2 = ((0 if demon[DEMON_BIRD] == 1 else 4)
                                                   + (3 if self.lasers else self.rng.randint(0, 2))
                                                   + 4)
                                        b2[BULLET_OFFSET_X] = offset2
                                        b2[BULLET_X]        = demon[DEMON_X] + offset2
                                        b2[BULLET_Y]        = demon[DEMON_Y] + 8
                                        b2[BULLET_RADIUS]   = 0 if self.lasers else 1
                                        self.bullets.append(b2)
                                else:
                                    b1 = [0.0] * 32
                                    b1[BULLET_DEMON_X]  = demon[DEMON_X]
                                    offset1 = ((0 if demon[DEMON_BIRD] == 1 else 4)
                                               + self.rng.randint(0, 7))
                                    b1[BULLET_OFFSET_X] = offset1
                                    b1[BULLET_X]        = demon[DEMON_X] + offset1
                                    b1[BULLET_Y]        = demon[DEMON_Y] + 8
                                    b1[BULLET_RADIUS]   = 0 if self.lasers else 1
                                    self.bullets.append(b1)

                        else:
                            # Movimento em Y
                            if demon[DEMON_PERCENT_Y] >= 1:
                                demon[DEMON_PERCENT_Y] = 0
                                demon[DEMON_START_Y]   = demon[DEMON_Y]
                                dy_target = (40 + (int(demon[DEMON_ROW]) << 5)
                                             + self.rng.randint(0, 13 if demon[DEMON_ROW] == 2 else 29)
                                             - demon[DEMON_Y])
                                demon[DEMON_DELTA_Y]   = dy_target
                                dy = abs(dy_target)
                                if dy < 1: dy = 1
                                demon[DEMON_DELTA_PERCENT_Y] = ((0.9 + 0.1 * self.rng.random())
                                                                * self.demon_speed * 1.57 / dy)
                            else:
                                demon[DEMON_PERCENT_Y] += demon[DEMON_DELTA_PERCENT_Y]
                                demon[DEMON_Y] = (demon[DEMON_START_Y]
                                                  + demon[DEMON_DELTA_Y]
                                                  * math.sin(demon[DEMON_PERCENT_Y]))

                            # Movimento em X
                            if demon[DEMON_PERCENT_X] >= 1:
                                demon[DEMON_PERCENT_X] = 0
                                demon[DEMON_START_X]   = demon[DEMON_X]
                                if self.rng.randint(0, 10) == 1:
                                    x_target = self.rng.randint(0, 143)
                                else:
                                    if (demon[DEMON_ROW] < 2
                                            or (demon[DEMON_BIRD] == 1
                                                and demon[DEMON_SHOOTER] == 0)):
                                        y_val = self.player_x + 8 + self.rng.randint(0, 135 - self.player_x)
                                        z_val = self.rng.randint(0, max(0, self.player_x - 9))
                                        left  = demon[DEMON_X] + 4 < self.player_x
                                        if left:
                                            x_target = y_val if self.player_x < 57 else z_val
                                        else:
                                            x_target = z_val if self.player_x > 103 else y_val
                                    else:
                                        x_target = self.player_x - 28 + self.rng.randint(0, 47)
                                demon[DEMON_DELTA_X] = x_target - demon[DEMON_X]
                                dx = abs(demon[DEMON_DELTA_X])
                                if dx < 1: dx = 1
                                demon[DEMON_DELTA_PERCENT_X] = ((0.9 + 0.1 * self.rng.random())
                                                                 * self.demon_speed * 1.57 / dx)
                            else:
                                demon[DEMON_PERCENT_X] += demon[DEMON_DELTA_PERCENT_X]
                                demon[DEMON_X] = (demon[DEMON_START_X]
                                                  + demon[DEMON_DELTA_X]
                                                  * math.sin(demon[DEMON_PERCENT_X]))
                                if shooter and self.level > 7:
                                    for bul in self.bullets:
                                        bul[BULLET_DEMON_X] = demon[DEMON_X]

                # Colisão bala do jogador x demônio
                if (self.player_bullet_y < 175
                        and self.player_bullet_y <= demon[DEMON_Y] + 7
                        and self.player_bullet_y + 7 >= demon[DEMON_Y]
                        and self.player_bullet_x >= demon[DEMON_X] + (4 if (demon[DEMON_BIRD] == 0 and self.tiny_enemies) else 0)
                        and self.player_bullet_x <= demon[DEMON_X] + (7 if demon[DEMON_BIRD] == 1 else (11 if self.tiny_enemies else 15))):
                    demon[DEMON_EXPLODING]       = 1
                    demon[DEMON_EXPLODING_INDEX] = 0
                    demon[DEMON_DELAY]           = 0
                    self.player_bullet_y = 175.0
                    self.player_bullet_x = self.player_x + 3
                    if not self.demo_mode:
                        pts = 10 + 5 * (self.level >> 1)
                        pts = min(pts, 35)
                        pts <<= int(demon[DEMON_BIRD] + demon[DEMON_DIVING])
                        self.score += pts

                i -= 1

        # Contador de avanço de sprite
        if self.advance_sprite == 0:
            self.advance_sprite = 8
        else:
            self.advance_sprite -= 1

    # ------------------------------------------------------------------
    def render(self):
        buf = self.buffer

        # Fundo
        if self.player_exploding > 47:
            bg_color = self.exploding_flash_colors[63 - self.player_exploding]
        else:
            bg_color = (50,50,50)
        buf.fill(bg_color, (0, 20, 160, 168))

        enemy_spr = self._get_enemy_sprites(self.level)

        if self.game_over == 0:
            # Balas inimigas
            for bullet in self.bullets:
                pygame.draw.rect(buf, ENEMY_BULLET_COLOR,
                                 (int(bullet[BULLET_X]), int(bullet[BULLET_Y]), 1, 4))

            # Demônios
            for demon in self.demons:
                dx, dy = int(demon[DEMON_X]), int(demon[DEMON_Y])
                j_spr  = 1 if demon[DEMON_SPRITE] == 3 else int(demon[DEMON_SPRITE])

                if demon[DEMON_EXPLODING] == 1:
                    ei = int(demon[DEMON_EXPLODING_INDEX])
                    if demon[DEMON_BIRD] == 1:
                        buf.blit(enemy_spr[6 + ei], (dx, dy))
                    else:
                        buf.blit(enemy_spr[(6 if self.level > 3 else 3) + ei], (dx, dy))

                elif demon[DEMON_FORMING] == 1:
                    # Duas metades se unindo
                    src = enemy_spr[j_spr + 3]
                    w, h = src.get_size()
                    # Metade esquerda
                    left_region = pygame.Rect(0, 0, w // 2, h)
                    buf.blit(src, (dx, dy), left_region)
                    # Metade direita (espelhada)
                    right_region = pygame.Rect(w // 2, 0, w // 2, h)
                    right_surf = pygame.transform.flip(
                        src.subsurface(right_region), True, False)
                    buf.blit(right_surf, (int(demon[DEMON_X2]) + w // 2, dy))

                else:
                    spr_idx = (9 + j_spr) if demon[DEMON_BIRD] == 1 else j_spr
                    if spr_idx < len(enemy_spr):
                        buf.blit(enemy_spr[spr_idx], (dx, dy))

            # Jogador / explosão
            if self.player_exploding > 0:
                idx = (self.player_exploding >> 3) + 15
                if idx < len(self.sprites) and self.sprites[idx]:
                    buf.blit(self.sprites[idx], (self.player_x - 4, 153))
            else:
                pygame.draw.rect(buf, PLAYER_BULLET_COLOR,
                                 (self.player_bullet_x, int(self.player_bullet_y), 1, 8))
                if self.sprites[14]:
                    buf.blit(self.sprites[14], (self.player_x, 174))

        # Barra de cabeçalho
        buf.fill(bg_color, (0, 0, 160, 20))
        if self.demo_mode and self.score == 0:
            for ii in range(4):
                if self.sprites[10 + ii]:
                    buf.blit(self.sprites[10 + ii], (63 + (ii << 3), 6))
        else:
            j_score = self.score
            x_pos   = 95
            while True:
                digit = j_score % 10
                if self.sprites[digit]:
                    buf.blit(self.sprites[digit], (x_pos, 6))
                x_pos   -= 8
                j_score //= 10
                if j_score == 0:
                    break

        # Chão / kill screen
        if self.level < 84:
            go_idx = min(self.game_over, 119)
            fc_row = self.floor_colors[go_idx]
            for ii in range(7):
                buf.fill(fc_row[ii], (0, 188 + ii, 160, 1))
            buf.fill(fc_row[6], (0, 195, 160, 15))

            if not self.demo_mode:
                el_color = self.extra_lives_colors[min(self.next_level_delay, 99)]
                for ii in range(self.extra_lives):
                    ox = 17 + (ii << 3)
                    buf.fill(el_color, (ox,     190, 1, 3))
                    buf.fill(el_color, (ox + 1, 188, 1, 3))
                    buf.fill(el_color, (ox + 2, 190, 1, 3))
        else:
            buf.fill(bg_color, (0, 20, 160, 190))

        if(self.demo_mode == False):
            self.texto = self.font.render(f"Level: {self.level + 1}", False, (255,255,255))
            buf.blit(self.texto,(60,195))
        

        # Escalonar para a tela
        pygame.transform.scale(buf, (WIN_W, WIN_H), self.screen)
        pygame.display.flip()

    # ------------------------------------------------------------------
    def run(self):
        while True:
            keys_pressed = pygame.key.get_pressed()
            keys_down    = set()
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    pygame.quit()
                    sys.exit()
                if event.type == pygame.KEYDOWN:
                    keys_down.add(event.key)

            # Combinar teclas pressionadas continuamente
            if keys_pressed[pygame.K_LEFT]:  keys_down.add(pygame.K_LEFT)
            if keys_pressed[pygame.K_RIGHT]: keys_down.add(pygame.K_RIGHT)
            if keys_pressed[pygame.K_a]:     keys_down.add(pygame.K_a)
            if keys_pressed[pygame.K_d]:     keys_down.add(pygame.K_d)
            if keys_pressed[pygame.K_b]:     keys_down.add(pygame.K_b)
            if keys_pressed[pygame.K_SPACE]: keys_down.add(pygame.K_SPACE)

            self.update(keys_pressed, keys_down)
            self.render()
            self.clock.tick(FPS)


# ---------------------------------------------------------------------------
if __name__ == "__main__":
    game = DemonAttack()
    game.run()