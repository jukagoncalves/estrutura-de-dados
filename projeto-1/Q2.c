#include <stdio.h>

#define LINHAS 5
#define COLUNAS 5
char sala_estudo[LINHAS][COLUNAS];
int i,j;

void iniciarSala(){	
	for(i=0; i<LINHAS; i++){
		for(j=0; j<COLUNAS; j++){
			sala_estudo[i][j] = 'L'; //LIVRE
		}
	}
}

void mostrarMapa(){
	printf("\nMAPA (L = Livre, X = Reservado):\n");
	for(i=0; i<LINHAS; i++){
		for(j=0; j<COLUNAS; j++){
			printf("%c", sala_estudo[i][j]);
		}
		printf("\n");
	}
}

void reservarLugar(){
	int fileira, estacao;
	
	printf("Informe a fileira (1-5): ");
	scanf("%d", &fileira);
	printf("Informe a estação (1-5): ");
	scanf("%d", &estacao);
	
	if((fileira < 0 || fileira > LINHAS) || (estacao < 0 || estacao > COLUNAS)){
		printf("Digite a posição corretamente!");
		return;
	}
	
	fileira --; //linha vai de 0 a 4
	estacao --; //coluna vai de 0 a 4
	
	if(sala_estudo[fileira][estacao] == 'L'){
		sala_estudo[fileira][estacao] = 'X'; //OCUPADO
		printf("Reserva garantida com sucesso");
	} else {
		printf("Posição ja reservada. Escolha outra");
	}
}

int main(){
	int opcao;
	
	iniciarSala();
	
	do{
		printf("\nReservas | Sala de Estudos\n");
		printf("1. Visualizar mapa de estaçoes\n");
		printf("2. Reservar Posição (fileira, estação)\n");
		printf("3. Sair\n");
		printf("Escolha uma opção (1-3): ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				mostrarMapa();
				break;
			case 2:
				reservarLugar();
				break;
			case 3:
				printf("Encerrando reservas");
				break;
			default:
				printf("Opção incorreta, digite novamente!");				
		}
	}while(opcao != 3);
	
	return 0;
}
