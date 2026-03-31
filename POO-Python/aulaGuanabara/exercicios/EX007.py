from rich import print

class livro:
    def __init__(self, titulo, pag):
        self.titulo = titulo
        self.paginas = pag
        self.pag_atual = 1
        print(f"Vc acabou de abrir o livro [red]{self.titulo}[/red]' que tem {self.paginas} Páginas no Total. Vc agr esta na página 1")

    def avancar(self, qtd):
        nova_pagina = self.pag_atual + qtd

        if nova_pagina >= self.paginas: 
            for paginas in range(self.pag_atual + 1, self.paginas + 1):
                print(f"Pag. {paginas} ->", end=" ")
            
            self.pag_atual = self.paginas
            print(f"[red]Parabéns! Vc finalizou o livro '{self.titulo}'[/red]")

        else:
            for paginas in range(self.pag_atual + 1, nova_pagina + 1):
                print(f"Pag. {paginas} ->", end=" ")
            
            self.pag_atual = nova_pagina
            print(f"\nVc avançou {qtd} páginas e agora esta na {self.pag_atual}")

l1 = livro("10 Coisas que Aprendi", 20)
l1.avancar(5)
l1.avancar(10)
l1.avancar(100)