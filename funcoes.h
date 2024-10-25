struct Instrumento {
    char nome[30];
    float preco;
};

struct CartNo {
    struct Instrumento item;
    struct CartNo* proximo;
};

struct User {
    char name[30];
    char email[80];
    char pass[10];
    struct CartNo* cart;  
};

void menup();
void lojaMenu();
void verCarrinho(struct User* user);
void adicionarAoCarrinho(struct User* user, struct Instrumento item);
void comprarInstrumento(struct User* user);
void excluirInstrumento(struct User* user, int posicao);
void finalizarCompra(struct User* user);
void cadastrar(struct User* v, int* qtd);
int autenticar(struct User* v, int qtd, char email[], char pass[]);
