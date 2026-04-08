class Pessoa:
    def __init__(self, nome, idade, tipo):
        self.nome = nome
        self.idade = idade
        self.tipo = tipo

    def descricao(self):
        print(f"Pessoa: {self.nome} | Idade: {self.idade} | Tipo: {self.tipo}", end=" | ")
    
class Aluno(Pessoa):
    def __init__(self, nome, idade, tipo, matricula, curso):
        super().__init__(nome, idade, tipo)
        self.matricula = matricula
        self.curso = curso
    
    def descricaoAluno(self):
        super().descricao()
        print(f"Matrícula: {self.matricula} | Curso: {self.curso}")

class Professor(Pessoa):
    def __init__(self, nome, idade, tipo, disciplina, salario):
        super().__init__(nome, idade, tipo)
        self.disciplina = disciplina
        self.salario = salario

    def descricaoProfessor(self):
        super().descricao()
        print(f"Disciplina: {self.disciplina} | Salário: R${self.salario}")

P1 = Pessoa("Luiza", 19, "Aluno")
A1 = Aluno("Luiza", 19, "Aluno", 1200, "Ciências Da Computação")
A1.descricaoAluno()
print()
P2 = Pessoa("Amanda", 67, "Professor")
PP2 = Professor("Amanda", 67, "Professor", "Matemática", "90.000")
PP2.descricaoProfessor()
