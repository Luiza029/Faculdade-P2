#Declaraçao de Class
class Gafanhoto:
    def __init__(self, nome, idade): #Método Construtor
        #Atributo de Instância
        self.nome = nome
        self.idade = idade

    #Método de Intância
    def aniversario(self):
        self.idade += 1

    #def mensagem(self):
       #return f"{self.nome} é Gafanhoto e tem {self.idade} anos de idade."

    def __str__(self):
        return f"{self.nome} é Gafanhoto e tem {self.idade} anos de idade." 

#Declaração de Objetos
g1 = Gafanhoto("Maria", 17)
g1.aniversario()
print(g1)

g2 = Gafanhoto("Mauro", 53)
print(g2)