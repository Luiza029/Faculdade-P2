class Vetor2D:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    def adicao(self, v):
        soma_x = self.x + v.x
        soma_y = self.y + v.y
        return Vetor2D(soma_x, soma_y)
    
    def subtracao(self, v):
        sub_x = self.x - v.x
        sub_y = self.y - v.y
        return Vetor2D(sub_x, sub_y)
    
    def produto_escalar(self, v):
        return self.x * v.x + self.y *v.y
    
    def descricao(self):
        print(f"Vetor: ({self.x}, {self.y})")

V = Vetor2D(1,3)
W = Vetor2D(4,9)

soma = V.adicao(W)
sub = V.subtracao(W)
prod_Escalar = V.produto_escalar(W)

print("Soma")
soma.descricao()
print("Subtrção")
sub.descricao()
print("Produto Escalar")
print(prod_Escalar)