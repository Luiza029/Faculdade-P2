from rich.panel import Panel
from rich.console import Console

class Produto:
    def __init__(self, nome, preco):
        self.nome = nome
        self.preco = preco
    
    def etiqueta(self):
        console = Console()

        texto = (
            f"{self.nome}\n"
            f"--------------------\n"
            f".....{self.preco:,.2f}....."
        )

        caixa = Panel(texto, title="Produto", expand=False)
        console.print(caixa)

p1 = Produto("Iphone 17 Pro Max", 10_000)
p2 = Produto("Notbook Gamer", 5_500)
p3 = Produto("Monitor Gamer 144hz", 1_500)
p4 = Produto("Teclado MX Keys Mini", 700)

p1.etiqueta()
p2.etiqueta()
p3.etiqueta()
p4.etiqueta()