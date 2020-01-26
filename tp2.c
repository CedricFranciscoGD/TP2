#include <stdio.h>
// Bibliothèque permettant de générer des nombres aléatoire pour programmer le comportement du monstre
#include <stdlib.h>
#include <time.h>



int main (){
	//Variables
	int pdvAspicot = 10;
	int pdmAspicot = 10;
	int pdvSalameche = 10;
	int pdmSalameche = 20;
	int pdvCarapuce = 20;
	int pdmCarapuce = 10;
	int pdvBulbizarre = 15;
	int pdmBulbizarre = 15;
	int atkLegere = 1;
	//Variable comportement joueur
	int choixAction = 0;
	//Variable comportement Monstre
	int i = 0;
	int coutSort = 3;
	int coutAntidote = 5;

	printf("Un Aspicot sauvage apparait\n");
	printf("Aspicot sauvage a %d points de vie\n", pdvAspicot);
	printf("Vous avez %d points de vie \n", pdvSalameche);


	while (pdvAspicot > 0 && pdvSalameche > 0 )
	{
		if (pdmSalameche<10)
		{
			printf("Vous recuperez 1 pt de magie\n");
			pdmSalameche ++;
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
			pdvAspicot--;
			printf("Aspicot a %d points de vie! \n", pdvAspicot);
		}
		

		else if (choixAction == 2)
		{
			printf("Vous vous protegez de Aspicot votre defense est multipliee par 4 ! \n");
			printf("Vous avez %d point de vie ! \n", pdvSalameche);
			
		}


		else if (choixAction == 3)
		{
			printf("Vous lancez un sort sur Aspicot \n");
			pdvAspicot--;
			printf("Il vous reste %d points de magie \n", pdmSalameche -= coutSort);
			printf("Aspicot a %d points de vie! \n", pdvAspicot);
			printf("Aspicot est empoisonne ! \n");
			printf("Le poison fait son effet Aspicot perd 1 point de vie ! \n");
			printf("Aspicot a %d points de vie \n", pdvAspicot -= 1 );
		}

		// N'ayant pas réussi à faire perdurer le poison, mon antidote sera un soin de 3 pv contre 5 pts de magie.
		else if (choixAction == 4)
		{
			printf("Vous utilisez un sort d'antidote \n");
			printf("Vous recuperez 3 points de vie\n");
			printf("Vous avez %d points de vie\n", pdvSalameche += 3 );
			printf("Il vous reste %d points de magie \n", pdmSalameche -= coutAntidote);

		}


// Condition qui devrait empecher Aspicot de m'envoyer un sort si sa reserve de magie est insuffisante mais qui ne marche pas.
// Je n'arrive pas a bloquer (ce n'est pas faute d'avoir essayé différentes méthodes).
	if (pdmAspicot < coutSort)
	{
		printf("Aspicot lance piqure ! \n");
		pdvSalameche-- ;
		printf("Vous avez %d point de vie ! \n", pdvSalameche);
	}

		if (pdmAspicot<10)
		{
			printf("Aspicot recupere 1 pt de magie\n");
			pdmAspicot ++;
		}

		

		

		if (choixAction == 1 || choixAction == 3 || choixAction == 4)
		{
			printf("Aspicot attaque Dard Venin \n");
			pdvSalameche-- ;
			printf("Vous avez %d point de vie ! \n", pdvSalameche);
			printf("Vous etes empoisonne\n");
			printf("Le poison fait son effet vous perdez 1 point de vie\n");
			printf("Il vous reste %d point de vie\n", pdvSalameche-= 1 );
			printf("Aspicot a %d points de magie \n", pdmAspicot -= coutSort);
		}

		else if (choixAction == 2)
		{
			printf("Aspicot attaque Dard Venin \n");
			printf("Ce n'est pas tres efficace...\n");
			printf("Vous etes empoisonne\n");
			printf("Le poison fait son effet vous perdez 1 point de vie \n");
			printf("Il vous reste %d point de vie\n", pdvSalameche-= 1 );
			printf("Aspicot a %d points de magie \n", pdmAspicot-= coutSort);
		}

			
		
	}

		

			if (pdvAspicot == 0 )
				{	printf("Aspicot est mort !!! \n");
					
				}
			else if (pdvSalameche == 0)
				{
				printf("Vous etes mort !!! \n");
				
				}	

	return 0;
}