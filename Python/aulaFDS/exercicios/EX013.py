class Animal:
    def __init__(self, nome, idade):
        self.nome = nome
        self.idade = idade
    
    def descricao(self):
        print(f"Nome: {self.nome} | Idade: {self.idade}", end=" | ")

class Gato(Animal):
    def __init__(self, nome, idade, cor):
        super().__init__(nome, idade)
        self.cor = cor
    
    def descricaoGato(self):
        super().descricao()
        print(f"Cor: {self.cor}")

class Cachorro(Animal):
    def __init__(self, nome, idade, raca):
        super().__init__(nome, idade)
        self.raca = raca
    
    def descricaoCachorro(self):
        super().descricao()
        print(f"Raça: {self.raca}")

class Passaro(Animal):
    def __init__(self, nome, idade, voa):
        super().__init__(nome, idade)
        self.voa = voa

    def descricaoPassaro(self):
        super().descricao()
        print(f"Sabe Voar: {self.voa}")

A1 = Animal("Luigi", 5)
G1 = Gato("Luigi", 5, "Loiro")
G1.descricaoGato()

print()

A2 = Animal("Loki", 4)
C2 = Cachorro("Loki", 4, "Pastor Alemão")
C2.descricaoCachorro()

print()

A3 = Animal("Papagaito", 3)
P3 = Passaro("Papagaito", 3, "Sim")
P3.descricaoPassaro()