class Funcionario: 
    def __init__(self, nome, salario, cargo):
        self.nome = nome
        self.salario = salario
        self.cargo = cargo
    
    def aumentarSalario(self, percentual):
        self.salario = self.salario + (self.salario * percentual / 100) # Formula de aumentar o salario
    
    def bonus(self):
        if self.cargo == "Gerente":
            self.salario = self.salario + (self.salario * 0.2)

        elif self.cargo == "Analista":
            self.salario = self.salario + (self.salario * 0.1)
            
        else:
            self.salario = self.salario + (self.salario * 0.05)

    def mensagem(self):
        return f"O seu novo salario é: {self.salario:.2f}"

f1 = Funcionario("Luiza", 1500, "Gerente")
f1.aumentarSalario(50)
f1.bonus()
print(f1.mensagem())