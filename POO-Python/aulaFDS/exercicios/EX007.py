class Personagem:
    def __init__(self, nome, vida, ataque):
        self.nome = nome
        self.vida = vida
        self.ataque = ataque

    def receberDano(self, valor):
        self.vida -= valor

        if self.vida > 0:
            print(f"A vida do personagem é {self.vida}")
        else:
            print(f"A vida do personagem é {self.vida}")
    
    def atacar(self, outroPersonagem):
        outroPersonagem.receberDano(self.ataque)
    
    def estavivo(self):
        if self.vida > 0:
            print("Personagem VIVO")
        else:
            print("Personagem MORTO")

p1 = Personagem("Guerreiro", 100, 80)
p2 = Personagem("Mago", 80, 15)

p1.atacar(p2)
p2.estavivo()

print()

p2.atacar(p1)
p1.estavivo()