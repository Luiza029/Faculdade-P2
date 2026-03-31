class Aluno:
    def __init__(self, nome, nota1, nota2):
        self.nome = nome
        self.nota1 = nota1
        self.nota2 = nota2
    
    def CalcularMedia(self):
        if 0<= self.nota1 <= 10 and 0 <= self.nota2 <= 10:
            self.media = (self.nota1 + self.nota2) / 2 # Nao necessarimente vou ter criar self no init, posso colocar self em qual quer def
        else:
            self.media = None
    
    def situacao(self): 
        if self.media == None:
            return f"Digite notas entre 0 e 10"
        elif self.media >= 7:
            return f"Aluno Aprovado"
        elif self.media > 5 and self.media <= 6.9:
            return f"Aluno em Recuperação"
        else:
            return f"Aluno Reprovado"
    
a1 = Aluno("Luiza", 11, -1)
a1.CalcularMedia() # Lembrar de chamar a funcao
print(a1.situacao())