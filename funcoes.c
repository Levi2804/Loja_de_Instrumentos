#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

void menup() {
    printf("1 Cadastrar\n");
    printf("2 Login\n");
    printf("3 Listar\n");
    printf("0 Sair\n");
}

void lojaMenu() {
    printf("\n--- Menu da Loja Mandacaru Music ---\n");
    printf("1 Comprar Instrumento\n");
    printf("2 Ver Carrinho\n");
    printf("3 Editar Compra\n");
    printf("4 Excluir Instrumentos da Compra\n");
    printf("5 Finalizar Compra\n");
    printf("0 Sair\n");
}

void verCarrinho(struct User* user) {
    printf("\n--- Carrinho de Compras ---\n");
    if (user->cart == NULL) {
        printf("Seu carrinho está vazio.\n");
    } else {
        struct CartNo* current = user->cart;
        int i = 1;
        while (current != NULL) {
            printf("%d. %s - R$%.2f\n", i++, current->item.nome, current->item.preco);
            current = current->proximo;
        }
    }
}

void adicionarAoCarrinho(struct User* user, struct Instrumento item) {
    struct CartNo* novoNo = (struct CartNo*)malloc(sizeof(struct CartNo));
    novoNo->item = item;
    novoNo->proximo = NULL;

    if (user->cart == NULL) {
        user->cart = novoNo;
    } else {
        struct CartNo* temp = user->cart;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoNo;
    }
}

void comprarInstrumento(struct User* user) {
    struct Instrumento instrumentos[8] = {
        {"Violão", 250.00},
        {"Guitarra", 1200.00},
        {"Baixo", 800.00},
        {"Teclado", 1500.00},
        {"Bateria", 3000.00},
        {"Sanfona", 4000.00},
        {"Ukulele", 350.00},
        {"Microfone", 150.00}
    };

    int escolha;
    printf("\n--- Comprar Instrumento ---\n");
    for (int i = 0; i < 8; i++) {
        printf("%d. %s - R$%.2f\n", i + 1, instrumentos[i].nome, instrumentos[i].preco);
    }
    printf("Escolha um instrumento para adicionar ao carrinho (0 para voltar): ");
    scanf("%d", &escolha);

    if (escolha > 0 && escolha <= 8) {
        adicionarAoCarrinho(user, instrumentos[escolha - 1]);
        printf("%s adicionado ao carrinho!\n", instrumentos[escolha - 1].nome);
    } else if (escolha != 0) {
        printf("Opção inválida! Tente novamente.\n");
    }
}

void excluirInstrumento(struct User* user, int posicao) {
    if (user->cart == NULL) {
        printf("Seu carrinho está vazio. Não há nada para excluir.\n");
        return;
    }

    struct CartNo* temp = user->cart;

    if (posicao == 1) {
        user->cart = temp->proximo;
        free(temp);
        printf("Instrumento excluído com sucesso!\n");
        return;
    }

    for (int i = 1; temp != NULL && i < posicao - 1; i++) {
        temp = temp->proximo;
    }

    if (temp == NULL || temp->proximo == NULL) {
        printf("Posição inválida.\n");
        return;
    }

    struct CartNo* next = temp->proximo->proximo;
    free(temp->proximo);
    temp->proximo = proximo;
    printf("Instrumento excluído com sucesso!\n");
}

void finalizarCompra(struct User* user) {
    float total = 0.0;

    if (user->cart == NULL) {
        printf("Seu carrinho está vazio. Não há nada para finalizar.\n");
        return;
    }

    printf("\n--- Finalizar Compra ---\n");
    verCarrinho(user);

    struct CartNo* current = user->cart;
    while (current != NULL) {
        total += current->item.preco;
        struct CartNo* temp = current;
        current = current->next;
        free(temp);
    }
    user->cart = NULL;

    printf("Total da compra: R$%.2f\n", total);
    printf("Pagamento realizado com sucesso!\n");
}

void cadastrar(struct User* v, int* qtd) {
    printf("Informe o nome do usuário: \n");
    scanf(" %[^\n]", v[*qtd].name);

    printf("Informe o email do usuário: \n");
    scanf(" %[^\n]", v[*qtd].email);

    printf("Informe a senha do usuário: \n");
    scanf("%s", v[*qtd].pass);

    v[*qtd].cart = NULL;
    (*qtd)++;
}

int autenticar(struct User* v, int qtd, char email[], char pass[]) {
    for (int i = 0; i < qtd; i++) {
        if (strcmp(v[i].email, email) == 0 && strcmp(v[i].pass, pass) == 0) {
            return i; 
        }
    }
    return -1;
}
