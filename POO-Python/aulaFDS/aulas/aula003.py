class Pessoa:

    def __init__(self, nome, idade, altura, peso):
        self.nome = nome
        self.idade = idade
        self.altura = altura
        self.peso = peso

    def getIMC(self):
        return self.peso / (self.altura * self.altura)
    
    def getCategoria(self):
        if self.getIMC() <= 18.5:
            return ("Abaixo do Peso")
        elif self.getIMC() <= 25:
            return ("Peso Normal")
        elif self.getIMC() <= 30:
            return ("Acima do peso")
        else:
            return ("Obesidade")
    
    def descricao(self):
        print(f"O seu IMC é {self.getIMC():.2f} e sua categoria esta em {self.getCategoria()}")

p1 = Pessoa("Luiza", 19, 1.60, 60)
print(p1.descricao())