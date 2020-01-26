#include <stdio.h>
// Bibliothèque permettant de générer des nombres aléatoire pour programmer le comportement du monstre
#include <stdlib.h>
#include <time.h>



int main (){
	//Variables
	int nombreEnnemi = 1;

	int pdvAspicot = 10;
	int pdmAspicot = 10;

	int pdvAbo = 12;
	int pdmAbo = 12;

	int pdvSmogo = 20;
	int pdmSmogo = 20;

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

	//Barre d'exp des pokémons alliés
	//Tableau
	int exp[3];

	//0 = Salamèche
	//1 = Bulbizarre
	//2 = Carapuce
	exp[0] = 0;
	exp[1] = 0;
	exp[2] = 0;

	//LVL 
	int lvl[3];

	//0 = Salamèche
	//1 = Bulbizarre
	//2 = Carapuce
	lvl[0] = 1;
	lvl[1] = 1;
	lvl[2] = 1;




	printf("Un Aspicot sauvage apparait\n");
	printf("Aspicot sauvage a %d points de vie\n", pdvAspicot);
	printf("Vous avez %d points de vie \n", pdvSalameche);



// Boucle de combat 
	while (pdvAspicot > 0 && pdvSalameche > 0 )
	{
		//-------------------------------------------------------------------------------------------------------------------------
		//TOUR DE SALAMECHE
		if (pdmSalameche<10)
		{
			printf("Salameche recupere 1 pt de magie\n");
			pdmSalameche ++;
		}
		printf("C'est le tour de Salameche que souhaitez vous faire ? \n");
		printf("Tapez 1 pour lancer une attaque legere\n");
		printf("Tapez 2 pour vous defendre\n");
		printf("Tapez 3 pour lancer un sort de type poison\n");
		printf("Tapez 4 pour utiliser un sort d'antidote\n");
		printf("Tapez 5 pour aggro un nouvel ennemi\n");
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

		else if (choixAction == 5)
		{	
			if (nombreEnnemi == 1 )
			{
			printf("Abo apparait ! \n");
			printf("Abo a %d points de vie et %d points de magie \n ", pdvAbo, pdmAbo);
			nombreEnnemi++;
			}
			else if (nombreEnnemi == 2)
			{
				printf("Smogo apparait ! \n");
				printf("Smogo a %d points de vie et %d points de magie \n ", pdvSmogo, pdmSmogo);
				nombreEnnemi++;
			}
			
			else if (nombreEnnemi == 3)
			{
				printf("Nombre maximum d'ennemi atteint, choisissez une autre action ! \n ");
				scanf("%d", &choixAction);
			}
		}
		//FIN DU TOUR DE SALAMECHE 
		//--------------------------------------------------------------------------------------------------------------------------------


		//-------------------------------------------------------------------------------------------------------------------------
		//TOUR DE BULBIZARRE
		if (pdmBulbizarre<10)
		{
			printf("Bulbizarre recupere 1 pt de magie\n");
			pdmBulbizarre ++;
		}
		printf("C'est le tour de Bulbizarre que souhaitez vous faire ? \n");
		printf("Tapez 1 pour lancer une attaque legere\n");
		printf("Tapez 2 pour vous defendre\n");
		printf("Tapez 3 pour lancer un sort de type poison\n");
		printf("Tapez 4 pour utiliser un sort d'antidote\n");
		printf("Tapez 5 pour aggro un nouvel ennemi\n");
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
			printf("Vous avez %d point de vie ! \n", pdvBulbizarre);
			
		}


		else if (choixAction == 3)
		{
			printf("Vous lancez un sort sur Aspicot \n");
			pdvAspicot--;
			printf("Il vous reste %d points de magie \n", pdmBulbizarre -= coutSort);
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
			printf("Vous avez %d points de vie\n", pdvBulbizarre += 3 );
			printf("Il vous reste %d points de magie \n", pdmBulbizarre -= coutAntidote);

		}

		else if (choixAction == 5)
		{	
			if (nombreEnnemi == 1 )
			{
			printf("Abo apparait ! \n");
			printf("Abo a %d points de vie et %d points de magie \n ", pdvAbo, pdmAbo);
			nombreEnnemi++;
			}
			else if (nombreEnnemi == 2)
			{
				printf("Smogo apparait ! \n");
				printf("Smogo a %d points de vie et %d points de magie \n ", pdvSmogo, pdmSmogo);
				nombreEnnemi++;
			}
			
			else if (nombreEnnemi == 3)
			{
				printf("Nombre maximum d'ennemi atteint, choisissez une autre action ! \n ");
				scanf("%d", &choixAction);
			}
		}
		//FIN DU TOUR DE BULBIZARRE 
		//--------------------------------------------------------------------------------------------------------------------------------





		//-------------------------------------------------------------------------------------------------------------------------
		//TOUR DE CARAPUCE
		if (pdmBulbizarre<10)
		{
			printf("Carapuce recupere 1 pt de magie\n");
			pdmCarapuce ++;
		}
		printf("C'est le tour de Carapuce que souhaitez vous faire ? \n");
		printf("Tapez 1 pour lancer une attaque legere\n");
		printf("Tapez 2 pour vous defendre\n");
		printf("Tapez 3 pour lancer un sort de type poison\n");
		printf("Tapez 4 pour utiliser un sort d'antidote\n");
		printf("Tapez 5 pour aggro un nouvel ennemi\n");
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
			printf("Vous avez %d point de vie ! \n", pdvCarapuce);
			
		}


		else if (choixAction == 3)
		{
			printf("Vous lancez un sort sur Aspicot \n");
			pdvAspicot--;
			printf("Il vous reste %d points de magie \n", pdmCarapuce -= coutSort);
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
			printf("Vous avez %d points de vie\n", pdvCarapuce += 3 );
			printf("Il vous reste %d points de magie \n", pdmCarapuce -= coutAntidote);

		}

		else if (choixAction == 5)
		{	
			if (nombreEnnemi == 1 )
			{
			printf("Abo apparait ! \n");
			printf("Abo a %d points de vie et %d points de magie \n ", pdvAbo, pdmAbo);
			nombreEnnemi++;
			}
			else if (nombreEnnemi == 2)
			{
				printf("Smogo apparait ! \n");
				printf("Smogo a %d points de vie et %d points de magie \n ", pdvSmogo, pdmSmogo);
				nombreEnnemi++;
			}
			
			else if (nombreEnnemi == 3)
			{
				printf("Nombre maximum d'ennemi atteint, choisissez une autre action ! \n ");
				scanf("%d", &choixAction);
			}
		}
		//FIN DU TOUR DE CARAPUCE 
		//--------------------------------------------------------------------------------------------------------------------------------



// Condition qui devrait empecher Aspicot de m'envoyer un sort si sa reserve de magie est insuffisante mais qui ne marche pas.
// Je n'arrive pas a bloquer (ce n'est pas faute d'avoir essayé différentes méthodes).


// DEBUT TOUR ENNEMIS
//----------------------------------------------------------------------------------------------------
// TOUR ASPICOT 

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

		

			if (pdvAspicot <= 0 )
				{	
					printf("Aspicot est mort !!! \n");
					printf("Vos pokemons ont gagne +5 points d'experience \n");
					exp[0]+=5;
					exp[1]+=5;
					exp[2]+=5;
					printf("Salameche a %d points d'experience\n", exp[0] );
					printf("Bulbizarre a %d points d'experience\n", exp[1] );
					printf("Carapuce a %d points d'experience\n", exp[2] );
				}

			else if (pdvSalameche <= 0)
				{
				printf("Salameche etes mort !!! \n");
				
				}	

			else if (pdvBulbizarre <= 0)
				{
				printf("Bulbizarre etes mort !!! \n");
				
				}

			else if (pdvAbo <= 0)
				{
				printf("Abo etes mort !!! \n");
				printf("Vos pokémons ont gagné 10 points d'exp\n");
				exp[0]+=10;
				exp[1]+=10;
				exp[2]+=10;
				printf("Salameche a %d points d'experience\n", exp[0] );
				printf("Bulbizarre a %d points d'experience\n", exp[1] );
				printf("Carapuce a %d points d'experience\n", exp[2] );
				}

			else if (pdvCarapuce <= 0)
				{
				printf("Carapuce etes mort !!! \n");
				
				}
				
			else if (pdvSmogo <= 0)
				{
				printf("Smogo etes mort !!! \n");
				printf("Vos pokémons ont gagné 20 points d'exp\n");
				exp[0]+=20;
				exp[1]+=20;
				exp[2]+=20;
				printf("Salameche a %d points d'experience\n", exp[0] );
				printf("Bulbizarre a %d points d'experience\n", exp[1] );
				printf("Carapuce a %d points d'experience\n", exp[2] );
			}

			while(exp[0]>= 5 && exp[1]>= 5 && exp[2]>= 5)
			{
				lvl[0] ++;
				exp[0] -=5;
				printf("Salameche vient de monter LVL %d \n", lvl[0]);
				lvl[1] ++;
				exp[1] -=5;
				printf("Bulbizarre vient de monter LVL %d \n", lvl[1]);
				lvl[2] ++;
				exp[2] -=5;
				printf("Carapuce vient de monter LVL %d \n", lvl[2]);

			}

			

	return 0;
}