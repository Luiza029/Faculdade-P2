class Produto:
    def __init__(self, nome, preco):
        self.nome = nome
        self.preco = preco

    def aplicarDesconto(self, percentual):
        self.preco -= self.preco * (percentual / 100)

    
    def aumentarPreco(self, percentual):
        self.preco += self.preco * (percentual / 100)
    
    def mensagem(self):
       return f"O produto {self.nome} agora custa {self.preco}"
            

p1 = Produto("Mouse", 100)
p1.aplicarDesconto(20)
print(p1.mensagem())