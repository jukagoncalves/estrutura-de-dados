#include <stdio.h>
#include <string.h>

#define MAX_LIVROS 50
typedef struct{
	char titulo[50];
	char autor[50];
	int ano;
} Livro;

int adicionarLivro(Livro biblioteca[], int *quantidade, Livro novo){
	biblioteca[*quantidade] = novo;
	(*quantidade)++;
	return 1;
}

void listarLivros(Livro biblioteca[], int quantidade){
	int i;
	
	if(quantidade == 0){
		printf("Nenhum livro cadastrado!");
	}
	
	printf("\nLIVROS CADASTRADOS:\n");
	for(i=0; i<quantidade; i++){
		printf("%d : %s | %s | %d\n",i+1, biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].ano);
	}
}

int verificarDuplicidade(Livro biblioteca[], int quantidade, Livro novo) {
	int i;
    for (i = 0; i < quantidade; i++) {
        // Compara título e autor. Se ambos forem iguais, é duplicado.
        if (strcmp(biblioteca[i].titulo, novo.titulo) == 0 && 
            strcmp(biblioteca[i].autor, novo.autor) == 0) {
            return 1; // Encontrou duplicata
        }
    }
    return 0; // Não encontrou
}

int main(){
	Livro biblioteca[MAX_LIVROS];
	int option;
	int quantidade = 0;
	
	
	do{
		printf("\n===== BIBLIOTECA DIGITAL UFLA =====\n");
    	printf("1 - Adicionar livro\n");
    	printf("2 - Listar livros\n");
    	printf("3 - Sair\n");
    	printf("Digite sua opçao (1,2,0): ");
    	scanf("%d", &option);
    	getchar(); // limpar buffer
    	
		if((option > 3) || (option < 1)){
		printf("Digite uma opçao correta!");
		}
    	
    	if(option == 1){
    		if(quantidade >= MAX_LIVROS){
    			printf("Limite de livros atingido!");
			} else{
			Livro novo;
			
			printf("Titulo: ");
			fgets(novo.titulo, sizeof(novo.titulo), stdin);
			novo.titulo[strcspn(novo.titulo, "\n")] = '\0';
			
			printf("Autor: ");
			fgets(novo.autor, sizeof(novo.autor), stdin);
			novo.autor[strcspn(novo.autor, "\n")] = '\0';
			
			printf("Ano: ");
			scanf("%d", &novo.ano);
			getchar();
			
			if(verificarDuplicidade(biblioteca, quantidade, novo)){
				printf("Erro: Este livro ja foi cadastrado");
			} else{
				adicionarLivro(biblioteca, &quantidade, novo);
				printf("Livro cadastrado com sucesso!\n");
				}
			}
		}
		if(option ==2){
			listarLivros(biblioteca, quantidade);
		}
	} while(option != 3);
	
	if(option == 3){
		printf("Encerrando catalogo");
	}
	return 0;
}
