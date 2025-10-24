#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char descricao[100];      
    struct No* prox;          
} No;

typedef struct {
    No* topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = NULL;
}

int pilhaVazia(Pilha* p) {
    return (p->topo == NULL);
}

// Empilha (push)
void push(Pilha* p, char descricao[]) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: Memória insuficiente.\n");
        return;
    }
    strcpy(novo->descricao, descricao);
    novo->prox = p->topo;  // novo nó aponta para o antigo topo
    p->topo = novo;        // agora o novo é o topo
    printf("Operacao registrada.\n");
}

// Desempilha (pop)
void pop(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Nenhuma operacao para desfazer.\n");
        return;
    }
    No* temp = p->topo;
    printf("Ultima operacao desfeita: %s\n", temp->descricao);
    p->topo = temp->prox; // topo aponta para o próximo
    free(temp);           // libera memória
}

void listarRecursivo(No* no) {
    if (no == NULL) return;
    listarRecursivo(no->prox);  // vai até o final
    printf("%s\n", no->descricao); // imprime na "volta" da recursão
}

void listarOperacoes(Pilha* p) {
    if (pilhaVazia(p)) {
        printf("Nenhuma operacao registrada.\n");
        return;
    }
    printf("Operacoes (ordem cronologica):\n");
    listarRecursivo(p->topo);
}

// Libera toda a memória da pilha
void liberar(Pilha* p) {
    while (!pilhaVazia(p)) {
        pop(p);
    }
}

int main() {
    Pilha historico;
    inicializar(&historico);

    int opcao;
    char descricao[100];

    do {
        printf("\nHistorico de Operacoes\n");
        printf("1. Registrar nova operacao (descricao)\n");
        printf("2. Desfazer ultima operacao\n");
        printf("3. Listar operacoes registradas\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpa o buffer do teclado

        switch (opcao) {
            case 1:
                printf("Descricao: ");
                fgets(descricao, sizeof(descricao), stdin);
                descricao[strcspn(descricao, "\n")] = '\0'; 
                push(&historico, descricao);
                break;
            case 2:
                pop(&historico);
                break;
            case 3:
                listarOperacoes(&historico);
                break;
            case 4:
                printf("Encerrando historico.\n");
                liberar(&historico);
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 4);

    return 0;
}

