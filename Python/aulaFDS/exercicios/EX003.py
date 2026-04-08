class ContaBancaria:
    def __init__(self, titular, saldo = 50):
        self.titular = titular
        self.saldo = saldo

    def depositar(self, valor):
        if valor < 0:
            return f"Impossivel depositar um valor negativo na conta"
        else:
            self.saldo += valor

        return f"Vc acabou de depositar {valor} na sua conta. Agr vc possui {self.saldo}"

    def sacar(self, valor):
        if self.saldo >= valor:
            self.saldo -= valor
            return f"Prazer {self.titular}! No momento vc possui {self.saldo} na conta"
        
        else:
            return "Saldo insufuciente"
        
    def transferir(self, valor, conta):
        if valor >= self.saldo:
            return f"Vc n possui valor suficiente para transferir dinheiro para outra conta"
        else:
            novoSaldo = self.saldo - valor
            return f"Vc acabou de trasnferir {valor} para a conta de {conta}. No momento vc possui {novoSaldo}"
            
        
c1 = ContaBancaria("Luiza", 1_900)
print(c1.transferir(200, "Amanda"))
