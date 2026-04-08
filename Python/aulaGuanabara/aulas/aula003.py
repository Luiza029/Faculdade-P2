from rich import print
from rich.panel import Panel
from rich.table import Table
#Vai mostrar o erro de uma forma mais bonita e facil de entender
from rich.traceback import install
install()

print("Olá, [red]Mundo[/red]")

caixa = Panel("Esse aq é um painel de exemplo", title="Mensagem")
print(caixa)

tabela = Table(title="Tabela de Preços")
tabela.add_column("Nome")
tabela.add_column("Preço")

tabela.add_row("Lápis", "1.50")
tabela.add_row("Caneta", "5.00")
tabela.add_row("Caderno", "15.00")
tabela.add_row("Borracha", "3.50")
print(tabela)

print(50/0)