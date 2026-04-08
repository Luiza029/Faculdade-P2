#Declaraçao de Class
class Gafanhoto:
    def __init__(self): #Método Construtor
        #Atributo de Instância
        self.nome = ""
        self.idade = 0

    #Método de Intância
    def aniversario(self):
        self.idade += 1

    def mensagem(self):
        return f"{self.nome} é Gafanhoto e tem {self.idade} anos de idade."

#Declaração de Objetos
g1 = Gafanhoto()
g1.nome = "Maria"
g1.idade = 17
g1.aniversario()
print(g1.mensagem())

g2 = Gafanhoto()
g2.nome = "Mauro"
g2.idade = 20
print(g2.mensagem())