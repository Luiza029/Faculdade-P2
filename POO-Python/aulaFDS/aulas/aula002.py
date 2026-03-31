class CalcularArea:
    def __init__(self, a, b):
        self.baseMenor = a
        self.baseMaior = b
    
    def getArea(self): # o get serve para quando vc quer calcular algo, devolver valor ou reutilizar esse calculo para outro metodo
        return self.baseMaior * self.baseMenor
    
    def getperimetro(self):
        return 2 * (self.baseMenor + self.baseMaior)

    def descricao(self):
        print(f"A área do retângulo é {self.getArea()} e o perimetro é {self.getperimetro()}")
    
a1 = CalcularArea(3,2)
a1.descricao()
