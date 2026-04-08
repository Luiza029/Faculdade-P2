class Produto:
    def __init__(self, nome, preco):
        self.nome = nome 
        self.preco = preco
    
    def mostrar(self):
        print(f"O produto {self.nome}, custa ${self.preco}")

class Carrinho: 
    def __init__(self):
        self.lista_produtos = []
    
    def adicionarProduto(self, produto):
        self.lista_produtos.append(produto)

    def removerProduto(self, produto):
        self.lista_produtos.remove(produto)
    
    def calcular(self):
        total = 0
        for produto in self.lista_produtos:
            total += produto.preco
        return total

p1 = Produto("Mouse", 100)
p2 = Produto("Teclado", 200)
p3 = Produto("Café", 800)

c1 = Carrinho()
c1.adicionarProduto(p1)
c1.adicionarProduto(p2)
c1.adicionarProduto(p3)
print(c1.calcular())