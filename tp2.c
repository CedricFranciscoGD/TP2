#include <stdio.h>
// Bibliothèque permettant de générer des nombres aléatoire pour programmer le comportement du monstre
#include <stdlib.h>
#include <time.h>



int main (){
	//Variables
	int pointDeVie = 10;
	int pointDeMagie = 10;
	int mesPdv = 15;
	int mesPdm = 10;
	int atkLegere = 1;
	//Variable comportement joueur
	int choixAction = 0;
	//Variable comportement Monstre
	int i = 0;
	int coutSort = 3;
	int coutAntidote = 5;

	printf("Un Aspicot sauvage apparait\n");
	printf("Aspicot sauvage a %d points de vie\n", pointDeVie);
	printf("Vous avez %d points de vie \n", mesPdv);


	while (pointDeVie > 0 && mesPdv > 0 )
	{
		if (mesPdm<10)
		{
			printf("Vous recuperez 1 pt de magie\n");
			mesPdm ++;
		}
		printf("C'est votre tour que souhaitez vous faire ? \n");
		printf("Tapez 1 pour lancer une attaque legere\n");
		printf("Tapez 2 pour vous defendre\n");
		printf("Tapez 3 pour lancer un sort de type poison\n");
		printf("Tapez 4 pour utiliser un sort d'antidote\n");
		scanf("%d", &choixAction);
		
		if (choixAction == 1)
		{
			printf("Vous lancez une attaque legere sur Aspicot ! \n");
			pointDeVie--;
			printf("Aspicot a %d points de vie! \n", pointDeVie);
		}
		

		else if (choixAction == 2)
		{
			printf("Vous vous protegez de Aspicot votre defense est multipliee par 4 ! \n");
			printf("Vous avez %d point de vie ! \n", mesPdv);
			
		}


		else if (choixAction == 3)
		{
			printf("Vous lancez un sort sur Aspicot \n");
			pointDeVie--;
			printf("Il vous reste %d points de magie \n", mesPdm -= coutSort);
			printf("Aspicot a %d points de vie! \n", pointDeVie);
			printf("Aspicot est empoisonne ! \n");
			printf("Le poison fait son effet Aspicot perd 1 point de vie ! \n");
			printf("Aspicot a %d points de vie \n", pointDeVie -= 1 );
		}

		// N'ayant pas réussi à faire perdurer le poison, mon antidote sera un soin de 3 pv contre 5 pts de magie.
		else if (choixAction == 4)
		{
			printf("Vous utilisez un sort d'antidote \n");
			printf("Vous recuperez 3 points de vie\n");
			printf("Vous avez %d points de vie\n", mesPdv += 3 );
			printf("Il vous reste %d points de magie \n", mesPdm -= coutAntidote);

		}


// Condition qui devrait empecher Aspicot de m'envoyer un sort si sa reserve de magie est insuffisante mais qui ne marche pas.
// Je n'arrive pas a bloquer (ce n'est pas faute d'avoir essayé différentes méthodes).
	if (pointDeMagie < coutSort)
	{
		printf("Aspicot lance piqure ! \n");
		mesPdv-- ;
		printf("Vous avez %d point de vie ! \n", mesPdv);
	}

		if (pointDeMagie<10)
		{
			printf("Aspicot recupere 1 pt de magie\n");
			pointDeMagie ++;
		}

		

		

		if (choixAction == 1 || choixAction == 3 || choixAction == 4)
		{
			printf("Aspicot attaque Dard Venin \n");
			mesPdv-- ;
			printf("Vous avez %d point de vie ! \n", mesPdv);
			printf("Vous etes empoisonne\n");
			printf("Le poison fait son effet vous perdez 1 point de vie\n");
			printf("Il vous reste %d point de vie\n", mesPdv-= 1 );
			printf("Aspicot a %d points de magie \n", pointDeMagie -= coutSort);
		}

		else if (choixAction == 2)
		{
			printf("Aspicot attaque Dard Venin \n");
			printf("Ce n'est pas tres efficace...\n");
			printf("Vous etes empoisonne\n");
			printf("Le poison fait son effet vous perdez 1 point de vie \n");
			printf("Il vous reste %d point de vie\n", mesPdv-= 1 );
			printf("Aspicot a %d points de magie \n", pointDeMagie-= coutSort);
		}

			
		
	}

		

			if (pointDeVie == 0 )
				{	printf("Aspicot est mort !!! \n");
					
				}
			else if (mesPdv == 0)
				{
				printf("Vous etes mort !!! \n");
				
				}	

	return 0;
}