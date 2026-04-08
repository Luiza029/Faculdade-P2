class Produto:
    def __init__(self, nome, preco, estoque):
        self.nome = nome
        self.preco = preco
        self.estoque = estoque

    def soma(self):
        return f"O preço total dos produtos é R${self.estoque * self.preco}"
    
    def vender(self, qtd):
        if self.estoque > qtd:
            self.estoque -= qtd
            print(f"Vc vendeu {qtd} do produto {self.nome}. Agr vc so tem {self.estoque} no estoque")
            return True
        else:
            print(f"Vc n possui estoque suficiente para vender essa quantidade de produto. Atualmente no seu estoque tem {self.estoque}")
            return False 
        
    def repor(self, qtd_repor):
        self.estoque += qtd_repor
        return f"Vc repois no estoque {qtd_repor}. Agr vc possui {self.estoque}"

    def mensagem1(self):
        return f"O produto {self.nome} tem {self.estoque} no estoque e cada um custa R${self.preco}"
    
    def mensagem2(self):
        return f"Agora o produto {self.nome} tem {self.estoque} no estoque e o total agr é de R${self.preco * self.estoque}"
    
    def decoracao(self):
        return "=*=" * 20

nome = input("Digite o nome do produto: ")
preco = float(input("Digite o preço do produto: "))
estoque = int(input("Digite a quantidade total no estoque: "))
p1 = Produto(nome, preco, estoque)
print()
print(p1.mensagem1())
print(p1.soma())
print()

print(p1.decoracao())

while(True):
    qtd = int(input("Quantas quantidades do produto vc quer vender: "))
    
    if p1.vender(qtd):
        break

print()
repor = int(input("Quantas quantidades do produto vc deseja repor no estoque após a venda: "))
print(p1.repor(repor))
print()
print(p1.mensagem2())
print(p1.decoracao())
