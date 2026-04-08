class Ponto2D:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def Calculardistancia(self, outro_ponto):
        pontoX = (outro_ponto.x - self.x) ** 2
        prontoy = (outro_ponto.y - self.y) ** 2
        pontoXY = (pontoX + prontoy) ** 0.5
        return pontoXY
    
    def mover(self, dx, dy):
        self.x += dx
        self.y += dy
    
    def descricao(self):
        return f"Valor({self.x},{self.y})"

p1 = Ponto2D(2,-1)

print("Antes de Mover")
print(p1.descricao())

print("Depois de Mover")
p1.mover(3,4)
print(p1.descricao())