#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    int matricula;
} Usuario;

typedef struct No {
    Usuario usuario;
    struct No* proximo;
} No;

// Ponteiro global para a cabeça (início) da lista.
// Começa como NULL, indicando que a lista está vazia.
No* lista_de_usuarios = NULL;

void inserirUsuario();
void exibirUsuarios();
void removerUsuario();
void limparMemoria();

int main() {
    char entrada_do_usuario[10]; // Buffer para ler a entrada do menu como texto
    int opcao = 0;

    do {
        printf("\n--- Cadastro de Usuarios da Biblioteca ---\n");
        printf("1. Inserir usuario\n");
        printf("2. Exibir usuarios cadastrados\n");
        printf("3. Remover usuario pela matricula\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");

        // LEITURA ROBUSTA: Lê a linha inteira para evitar erros de buffer.
        if (fgets(entrada_do_usuario, sizeof(entrada_do_usuario), stdin) != NULL) {
            // CONVERSÃO SEGURA: Converte o texto lido para um número inteiro.
            opcao = atoi(entrada_do_usuario);
        } else {
            // Em caso de erro de leitura, define a opção de saída para encerrar.
            opcao = 4;
        }

        switch (opcao) {
            case 1:
                inserirUsuario();
                break;
            case 2:
                exibirUsuarios();
                break;
            case 3:
                removerUsuario();
                break;
            case 4:
                printf("\nEncerrando o sistema...\n");
                break;
            default:
                printf("\nERRO: Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 4);

    // Antes de terminar, libera toda a memória alocada para os nós da lista.
    limparMemoria();

    return 0;
}

void inserirUsuario() {
    char buffer_leitura[100];
    Usuario novo_usuario;

    printf("\n-- Inserir Novo Usuario --\n");
    printf("Digite o nome: ");
    // Lê o nome de forma segura, permitindo espaços.
    fgets(novo_usuario.nome, sizeof(novo_usuario.nome), stdin);
    // Remove o caractere '\n' que o fgets captura no final.
    novo_usuario.nome[strcspn(novo_usuario.nome, "\n")] = 0;

    printf("Digite a matricula: ");
    // Usa a mesma técnica robusta para ler a matrícula.
    fgets(buffer_leitura, sizeof(buffer_leitura), stdin);
    novo_usuario.matricula = atoi(buffer_leitura);

    // Validação para garantir que a matrícula não seja zero.
    if (novo_usuario.matricula == 0) {
        printf("\nERRO: Matricula invalida.\n");
        return;
    }
    
    // VERIFICAÇÃO DE DUPLICIDADE: Percorre a lista para checar a matrícula.
    No* atual = lista_de_usuarios;
    while (atual != NULL) {
        if (atual->usuario.matricula == novo_usuario.matricula) {
            printf("\nERRO: Matricula %d ja foi cadastrada!\n", novo_usuario.matricula);
            return; // Interrompe a função se encontrar duplicata.
        }
        atual = atual->proximo;
    }

    // ALOCAÇÃO: Cria um novo nó na memória.
    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("\nERRO: Falha ao alocar memoria para o novo usuario!\n");
        return;
    }

    // INSERÇÃO: Insere o novo nó no início da lista.
    novo_no->usuario = novo_usuario;
    novo_no->proximo = lista_de_usuarios; // O novo nó aponta para o antigo início da lista.
    lista_de_usuarios = novo_no;         // A cabeça da lista agora é o novo nó.

    printf("\nUsuario inserido com sucesso!\n");
}

void exibirUsuarios() {
    No* atual = lista_de_usuarios;

    if (atual == NULL) {
        printf("\nNenhum usuario cadastrado no momento.\n");
        return;
    }

    printf("\n--- Lista de Usuarios Cadastrados ---\n");
    while (atual != NULL) {
        printf("Nome: %-20s | Matricula: %d\n", atual->usuario.nome, atual->usuario.matricula);
        atual = atual->proximo; // Avança para o próximo nó.
    }
    printf("---------------------------------------\n");
}

void removerUsuario() {
    char buffer_leitura[100];
    int matricula_remover;

    if (lista_de_usuarios == NULL) {
        printf("\nNao ha usuarios para remover.\n");
        return;
    }

    printf("\nInforme a matricula do usuario a ser removido: ");
    fgets(buffer_leitura, sizeof(buffer_leitura), stdin);
    matricula_remover = atoi(buffer_leitura);

    No* atual = lista_de_usuarios;
    No* anterior = NULL;

    // Procura o nó que contém a matrícula a ser removida.
    while (atual != NULL && atual->usuario.matricula != matricula_remover) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("\nERRO: Usuario com a matricula %d nao encontrado.\n", matricula_remover);
        return;
    }

    // Caso 1: O nó a ser removido é o primeiro da lista.
    if (anterior == NULL) {
        lista_de_usuarios = atual->proximo; // A cabeça da lista passa a ser o segundo nó.
    } else {
    // Caso 2: O nó está no meio ou no fim da lista.
        anterior->proximo = atual->proximo; // O nó anterior "pula" o nó atual.
    }

    free(atual); // Libera a memória do nó que foi removido.
    printf("\nUsuario removido com sucesso.\n");
}

void limparMemoria() {
    No* atual = lista_de_usuarios;
    No* proximo_no;

    while (atual != NULL) {
        proximo_no = atual->proximo; // Guarda a referência para o próximo.
        free(atual);                 // Libera o nó atual.
        atual = proximo_no;          // Avança para o próximo.
    }
}
