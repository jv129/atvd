
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 60;


//struct
typedef struct {
	char nome[11];
	char simbolo;
	int cont; 
}Piloto;

//função: 1 para criar os corredores e a quantidade deles 
//recebe o vetor de  de pilotos e devolve a quantidade e pilotos
int CriarPiloto(Piloto pilotos[]){
	int quantPlayers;
	printf("Digite a quantida de players:");
	scanf(" %d", &quantPlayers);
	for(int i = 0; i < quantPlayers; i++){
		while(1){
			printf("Digite o nome e o símbolo do piloto:");
			scanf(" %s", pilotos[i].nome);
			scanf(" %c", &pilotos[i].simbolo);
			pilotos[i].cont = 0;
			if(strlen(pilotos[i].nome) <= 10)
				break;
			else{
				printf("NOME NÃO ACEITO\n");
				system("sleep 2");
				system("clear");
			}
			
		}
		
	}
	return quantPlayers;
}


//função 2: para sortear o a evolução dos players
void Corrida(Piloto pilotos[], int quantPilotos){
	for(int i = 0; i < quantPilotos; i++){
		pilotos[i].cont += rand()%3 + 1;
	}
}

//função 3 organização do vetor maior primeiro
void Organizar(Piloto pilotos[], int quantPilotos){
	for(int i = 1; i < quantPilotos; i++){
		for(int j = i; j > 0; j--){
			if(pilotos[j - 1].cont < pilotos[j].cont){
				Piloto aux = pilotos[j];
				pilotos[j] = pilotos[j - 1];
				pilotos[j - 1] = aux;
			}
		}
	}
}

//função 4 print da corrida
void printCorrida(Piloto pilotos[], int quantPilotos){
	for(int i = 0; i < quantPilotos; i++){
		printf(" %s", pilotos[i].nome);
		if(strlen(pilotos[i].nome) < 10){
			for(int j = 0; j < 10 - strlen(pilotos[i].nome) ; j++){
				printf(" ");
			}
		}
		for(int j = 0; j < pilotos[i].cont; j++){
			printf("%c", pilotos[i].simbolo);
		}
		printf("\n");
	}
}


int main()
{
	srand(time(NULL));
	Piloto pilotos[100];
	int quantPilotos = CriarPiloto(pilotos), posicao = -1;
	while(1){
		Corrida(pilotos, quantPilotos);
		Organizar(pilotos, quantPilotos);
		printCorrida(pilotos, quantPilotos);
		system("sleep 1");
		system("clear");
		for(int i = 0; i < quantPilotos; i++){
			if(pilotos[i].cont >= 60){
				posicao = i; break;
			}
		}
		if(posicao != -1)
			break;
	}
	printf("O vencedor foi %s ", pilotos[posicao].nome);
	return 0;
}

