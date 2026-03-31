class ContaBancaria:
    def __init__(self, titular, saldo): #O que é esse self
        self.titular = titular
        self.saldo = saldo
    
    #Métodos
    def depositar(self, valor):
        self.saldo += valor

    def sacar(self,valor):
        if self.saldo > valor:
            self.saldo -= valor
            return f"Prazer, {self.titular}! Seu saldo da conta é de R$ {self.saldo}"
        else:
            return f"Vc n pode sacar o dinheiro! Saldo insuficiente"

titular = input("Digite o nome do titular: ")
saldo = float(input("Digite o saldo da conta: "))
c1 = ContaBancaria(titular, saldo)
valor = float(input("Digite o valor a ser depositado: "))
c1.depositar(valor)
sacar = float(input("Qual valor vc deseja sacar: "))
print(c1.sacar(sacar))
