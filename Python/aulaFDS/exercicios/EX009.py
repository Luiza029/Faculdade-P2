class Animal:
    def __init__(self, dono, data):
        self.dono = dono
        self.data = data

    def exibir_Dados(self):
        print(f"Dono: {self.dono} | Nascimento: {self.data}")


class Gato(Animal): 
    def __init__(self, dono, data, vacinado, aspecto):
        super().__init__(dono, data)
        self.aspecto = aspecto
        self.vacinado = vacinado

    def descricao(self):
        print(f"Dono: {self.dono} | Nascimento: {self.data} | Vacinado: {self.vacinado} | Aspecto: {self.aspecto}")

A1 = Gato("Jubileu", "32/13/9090", "Vacinado", "Olhudo")
A1.descricao()