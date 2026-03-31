class ContaBancaria:
    def __init__(self, conta, saldo):
        self.conta = conta
        self.saldo = saldo
    
    def imprimirSaldo(self):
        return(f"O número da sua conta é {self.conta} que tem um saldo de {self.saldo}")

conta = int(input("Digite o numero da sua conta: "))
saldo = float(input("Digite o saldo da sua conta: "))
c1 = ContaBancaria(conta, saldo)
print(c1.imprimirSaldo())
