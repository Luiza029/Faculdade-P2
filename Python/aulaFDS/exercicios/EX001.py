class Pessoa:
    def __init__(self, nome, idade):
        self.nome = nome
        self.idade = idade

    def aniversario(self):
        self.idade += 1

    
    def apresentar(self):
        return f"Olá, meu nome é {self.nome} e eu tenho {self.idade}"
    
p1 = Pessoa("Luiza", 20)
p1.aniversario()
print(p1.apresentar())

