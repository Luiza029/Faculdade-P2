class Funcionario:
    def __init__(self, nome, salario):
        self.nome = nome
        self.salario = salario
    
    def descricao(self):
        print(f"\tNome: {self.nome} | Salário: R${self.salario}", end=" | ")

class Gerente(Funcionario):
    def __init__(self, nome, salario, departamento):
        super().__init__(nome, salario)
        self.departamento = departamento
    
    def descricaoGerente(self):
        super().descricao()
        print(f"Departamento: {self.departamento}")
    
class Estagiario(Funcionario):
    def __init__(self, nome, salario, hrs_trabalhadas):
        super().__init__(nome, salario)
        self.horas = hrs_trabalhadas
    
    def descricaoEstagio(self):
        super().descricao()
        print(f"Horas Trabalhadas: {self.horas}")


print()
F1 = Funcionario("Luiza", 10_000)
F1 = Gerente("Luiza", 10_000, "TI")
F1.descricaoGerente()
print()
F2 = Funcionario("Amanda", 1000)
F2 = Estagiario("Amanda", 1000, 123)
F2.descricaoEstagio()
print()