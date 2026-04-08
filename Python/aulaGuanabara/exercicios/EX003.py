#Exercicio do Gustavo Guanabara

class ContaBancaria:
    def __init__(self, id, nome, saldo):
        self.id = id
        self. titular = nome 
        self.saldo = saldo
    
    def __str__(self):
        return f"A conta {self.id} de {self.titular} tem R${self.saldo:,.2f} de saldo"
    
    def deposito(self, valor):
        self.saldo += valor

    def sacar(self,valor):
        if valor > self.saldo:
            print(f"Saque Negado! Vc atualmente possui R${self.saldo} na conta")
        else:
            self.saldo -= valor
            print(f"Saque de R${valor} Permitido")


c1 = ContaBancaria(112, "Gustavo", 3000)
c1.deposito(500)
c1.sacar(2000)
print(c1)