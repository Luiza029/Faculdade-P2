class Veiculo:
    def __init__(self, marca, ano):
        self.marca = marca
        self.ano = ano

    def descricao(self):
        print(f"Marca: {self.marca} | Ano: {self.ano}", end=" | ")

class Carro(Veiculo):
    def __init__(self, marca, ano, portas, combustiveis):
        super().__init__(marca, ano)
        self.portas = portas
        self.combustiveis = combustiveis
    
    def descricaoCarro(self):
        super().descricao()
        print(f"Portas: {self.portas} | Combustível {self.combustiveis}")

class Moto(Veiculo):
    def __init__(self, marca, ano, cilindrada, km):
        super().__init__(marca, ano)
        self.cilindrada = cilindrada
        self.km = km
    
    def descricaoMoto(self):
        super().descricao()
        print(f"Cilindrada: {self.cilindrada} | Km Rodado: {self.km}")

V1 = Veiculo("Mercedes", "2026")
C1 = Carro("Mercedes", "2026", 3, "Gasolina")
C1.descricaoCarro()

print()

V2 = Veiculo("X6", "2026")
M2 = Moto("X6", "2026", "Sim", 100)
M2.descricaoMoto()