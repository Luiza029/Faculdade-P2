class Funcionario:
    def __init__(self, nome, cpf):
        self.nome = nome
        self.cpf = cpf

    def exibir_dados(self):
        print(f"Funcionario: {self.nome} | {self.cpf}")
    
class Professor(Funcionario):
    def __init__(self, nome, cpf, disciplina):
        super().__init__(nome,cpf) # vai puxar a class mãe (Funcionario)
        self.disciplina = disciplina
    
    def exibir_dados(self):
        print(f"Professor: {self.nome} | Desciplina: {self.disciplina} | CPF: {self.cpf}")
    