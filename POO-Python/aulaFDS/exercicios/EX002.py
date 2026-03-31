class Aluno:
    def __init__(self, nome, nota1, nota2):
        self.nome = nome
        self.n1 = nota1
        self.n2 = nota2
    
    def calcularMedia(self):
        self.media = (self.n1 + self.n2) / 2
    
    def situacao(self):
        if self.media >= 7:
            return "Aprovado"
        else:
            return "Reprovado"

a1 = Aluno("Luiza", 2.1, 10)
a1.calcularMedia()
print(a1.situacao())