#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da fila
typedef struct Estudante {
    char nome[100];
    char livro[100];
    struct Estudante *prox;
} Estudante;

// Estrutura da fila com ponteiros para início e fim
typedef struct {
    Estudante *inicio;
    Estudante *fim;
} Fila;

void inicializarFila(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

int filaVazia(Fila *f) {
    return (f->inicio == NULL);
}

void registrarChegada(Fila *f, char nome[], char livro[]) {
    Estudante *novo = (Estudante*) malloc(sizeof(Estudante));
    strcpy(novo->nome, nome);
    strcpy(novo->livro, livro);
    novo->prox = NULL;

    if (filaVazia(f)) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;

    printf("Registro efetuado.\n");
}

void chamarProximo(Fila *f) {
    if (filaVazia(f)) {
        printf("Nenhum estudante na fila.\n");
        return;
    }

    Estudante *removido = f->inicio;
    printf("Chamando: %s | \"%s\"\n", removido->nome, removido->livro);

    f->inicio = removido->prox;
    if (f->inicio == NULL) {
        f->fim = NULL; // fila ficou vazia
    }
    free(removido);
}

void exibirPendencias(Fila *f) {
    if (filaVazia(f)) {
        printf("Nenhum estudante aguardando.\n");
        return;
    }

    printf("\n--- Pendências de Atendimento ---\n");
    Estudante *atual = f->inicio;
    while (atual != NULL) {
        printf("%s | \"%s\"\n", atual->nome, atual->livro);
        atual = atual->prox;
    }
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    int opcao;
    char nome[100], livro[100];

    do {
        printf("\nBalcão de Empréstimos\n");
        printf("1. Registrar chegada (nome, título do livro)\n");
        printf("2. Chamar próximo para atendimento\n");
        printf("3. Exibir pendências de atendimento\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch (opcao) {
            case 1:
                printf("Nome: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Título do livro: ");
                fgets(livro, sizeof(livro), stdin);
                livro[strcspn(livro, "\n")] = '\0';

                registrarChegada(&fila, nome, livro);
                break;

            case 2:
                chamarProximo(&fila);
                break;

            case 3:
                exibirPendencias(&fila);
                break;

            case 4:
                printf("Encerrando atendimento.\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}
 
