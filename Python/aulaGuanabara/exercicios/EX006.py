from rich.panel import Panel
from rich.console import Console

class Churrasco:
    def __init__(self, nome, qtd):
        self.titulo = nome
        self.qtd_pessoas = qtd
    
    def etiqueta(self):
        console = Console()

        #posso criar variaceis normais
        total_carne = self.qtd_pessoas * 0.4
        total =  total_carne * 82.40
        totalPorPessoa = total / self.qtd_pessoas

        texto = (
            f"Analisando [green]{self.titulo}[/green] com [blue]{self.qtd_pessoas} convidados[/blue]\n"
            f"Cada participante comerá 0.4kg e cada Kg custa R$82.40\n"
            f"Recomendado comprar [blue]{total_carne:,.2f}Kg[/blue] de carne\n"
            f"O custo total será de [green]R${total:,.2f}[/green]\n"
            f"Cada pessoa pagará [yellow]R${totalPorPessoa:,.2f}[/yellow]"
        )

        caixa = Panel(texto, title=f"{self.titulo}", expand=False)
        console.print(caixa)


nome = input("Digite o nome do churrasco: ")
qtd = int(input("Difite a quantidade de pessoas: "))
c1 = Churrasco(nome, qtd)

c1.etiqueta()