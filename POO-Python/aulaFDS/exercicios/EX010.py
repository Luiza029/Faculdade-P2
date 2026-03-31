class Animal:
    def __init__(self, dono, nascimento):
        self.dono = dono
        self.nascimento = nascimento

    def descricao(self):
        print(f"Dono: {self.dono} | Nascimento: {self.nascimento}", end=" | ")

class Cachorro(Animal):
    def __init__(self, dono, nascimento, raca, vacinacao):
        super().__init__(dono, nascimento)
        self.raca = raca
        self.vacinacao = vacinacao

    def descricao(self):
        super().descricao()
        print(f"Raça: {self.raca} | Vacinação: {self.vacinacao}")

A1 = Animal("Amanda", "12/09/2113")
C1 = Cachorro("Amanda", "12/09/2113", "Labrador", "Sim")
C1.descricao()