typedef struct{
    int id;
    char nome[100];
    char vetAutor[100];
    int pagina;
} Livro;

void inserirLivro(Livro livro1, Livro *vetLivros);
void removerLivro(int id, Livro *vetLivro);