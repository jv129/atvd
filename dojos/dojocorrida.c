#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct{
	char nome[100], simb;
	int contJ; 
}Jogador;
int main()
{
	srand(time(NULL));
	
	int nJog, cont = 0;
	printf("Digite o numero de jogadores:\n");
	scanf(" %d", &nJog);
	Jogador jogadores[nJog];
	
	for ( int i = 0; i < nJog; i++)
	{
		do{
			printf("Digite o nome do jogador %d\n e o símbolo\n", cont + 1);
			scanf(" %s %c", jogadores[cont].nome, &jogadores[cont].simb);
		}while(strlen(jogadores[cont].nome) >= 10);
		cont++;
	}
	
	for (int i = 0; i < nJog; i++)
	{
		jogadores[i].contJ = 0;
	}
	while(1){
		for (int i = 0; i < nJog; i++)	{
			jogadores[i].contJ+= rand() % 3 + 1;
		}
	}
	return 0;
}

