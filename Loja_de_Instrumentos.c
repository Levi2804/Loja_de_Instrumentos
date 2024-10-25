#include <stdio.h>
#include <locale.h>
#include "funcoes.h"

int main() {
    setlocale(LC_ALL, "Portuguese");

    struct User usuarios[100];
    int qtdUsuarios = 0;
    int opcao, usuarioAutenticado;

    printf("Bem-vindo ao sistema da loja Mandacaru Music!\n");

    do {
        menup();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Função cadastrar a ser implementada
                break;

            case 2:
                // Função de login a ser implementada
                break;

            case 3:
                // Função de listagem de usuários a ser implementada
                break;

            case 0:
                printf("Saindo do sistema...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
