class Funcionario:
    def __init__(self, nome, cargo, setor):
        self.nome = nome
        self.cargo = cargo
        self.setor = setor
    
    def __str__(self):
        return f"Olá, meu nome é {self.nome}, meu cargo é {self.cargo} e trbalho no setor {self.setor}"


nome = input("Digite seu nome: ")
cargo = input("Digite seu cargo: ")
setor = input("Digite seu setor: ")
f1 = Funcionario(nome, cargo, setor)
print(f1)