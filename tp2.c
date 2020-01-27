#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
	//Variables
	int nombreEnnemi = 1;
    int nombreAmi = 3;

    //Aspicot
    int idAspicot = 4;
	int pdvAspicot = 10;
	int pdmAspicot = 10;
    int dotApiscot = 0;

    //Abo
    int idAbo = 5;
	int pdvAbo = 12;
	int pdmAbo = 12;
    int dotAbo = 0;

    //Smogo
    int idSmogo = 6;
	int pdvSmogo = 20;
	int pdmSmogo = 20;
    int dotSmogo = 0;
    
    //Salameche
    int idSalameche = 1;
	int pdvSalameche = 10;
	int pdmSalameche = 20;
    int dotSalameche = 0;
    
    int flammeche = 5;
    int coutFlammeche = 5;

    //Carapuce
    int idCarapuce = 3;
    int aggroCarapuce = 0;
	int pdvCarapuce = 20;
	int pdmCarapuce = 10;
    int dotCarapuce = 0;

    //Bulbizarre
    int idBulbizarre = 2;
	int pdvBulbizarre = 15;
	int pdmBulbizarre = 15;
    int dotBulbizarre = 0;
    
    //capacités
	int atkLegere = 1;
    int atkLourde = 3;
    int Soin = 4;
    
	//Variables comportements combat
	int choixAction = 0;
    int choixCible = 0;
    int choixCibleEnnemi = 0;
    int choixActionEnnemi = 0;
	int i = 0;
	int coutSort = 3;
	int coutAntidote = 5;
    int dmgPoison = 1;

	//Barre d'exp des pokémons alliés
	//Tableau
	int exp[3];

	//0 = Salamèche
	exp[0] = 0;
    //1 = Bulbizarre
	exp[1] = 0;
    //2 = Carapuce
	exp[2] = 0;

	//LVL 
	int lvl[3];

	//0 = Salamèche
	lvl[0] = 1;
    //1 = Bulbizarre
	lvl[1] = 1;
    //2 = Carapuce
	lvl[2] = 1;

    
    //Initialisation combat
	printf("Salameche a %d points de vie \n", pdvSalameche);
    printf("Bulbizarre a %d points de vie \n", pdvBulbizarre);
    printf("Carapuce a %d points de vie \n", pdvCarapuce);
    
    printf("Un Aspicot sauvage apparait\n");
	printf("Aspicot sauvage a %d points de vie\n", pdvAspicot);
    
    // Boucle de combat 
	while (nombreAmi > 0 || nombreEnnemi >0)
	{
        //--------------------------------------------------------------------------------------------------------------------------------------------------------------
        //TOUR DE SALAMECHE
        if (pdmSalameche<10)
        {
            printf("Salameche recupere 1 pt de magie\n");
            pdmSalameche ++;
        }
        
        if (dotSalameche != 0)
        {
            printf("Salameche souffre du poison (%dHP)", pdvSalameche -= dmgPoison);
        }
        
        printf("C'est le tour de Salameche, que souhaitez vous faire ? \n");
        printf("=>Tapez 1 pour lancer une attaque lourde\n");
        printf("=>Tapez 2 pour vous defendre\n");
        printf("=>Tapez 3 pour lancer flammeche\n");
        printf("=>Tapez 4 pour utiliser un sort d'antidote\n");
        printf("=>Tapez 5 pour aggro un nouvel ennemi\n");
        printf("\n");
        scanf("%d", &choixAction);
        printf("\n");

        if (choixAction == 1)
        {
            printf("Qui voulez vous attaquer ? Aspicot = 4, Abo = 5, Smogo = 6\n");
            printf("\n");
            scanf("%d", &choixCible);
            printf("\n");
            printf("Vous lancez une attaque lourde ! \n");
            if (choixCible == idAspicot)
            {
                pdvAspicot -= atkLourde;
                printf("Aspicot a %d points de vie! \n", pdvAspicot);
            }
            if (choixCible == idAbo)
            {
                pdvAbo -= atkLourde;
                printf("Abo a %d points de vie! \n", pdvAbo);
            }
            if (choixCible == idSmogo)
            {
                pdvSmogo -= atkLourde;
                printf("Smogo a %d points de vie! \n", pdvSmogo);
            }
        }

        else if (choixAction == 2)
        {
            printf("Vous vous protegez et votre defense est multipliee par 4 ! \n");
            printf("Vous avez %d point de vie ! \n", pdvSalameche);

        }

        else if (choixAction == 3)
        {
            printf("Vous lancez flammeche \n");
            printf("Qui voulez vous attaquer ? Aspicot = 4, Abo = 5, Smogo = 6\n");
            printf("\n");
            scanf("%d", &choixCible);
            printf("\n");
            if (choixCible == idAspicot)
            {
                pdvAspicot -= flammeche;
                printf("Aspicot a %d points de vie! \n", pdvAspicot);
            }
            if (choixCible == idAbo)
            {
                pdvAbo -= flammeche;
                printf("Abo a %d points de vie! \n", pdvAbo);
            }
            if (choixCible == idSmogo)
            {
                pdvSmogo -= flammeche;
                printf("Smogo a %d points de vie! \n", pdvSmogo);
            }
            printf("Il vous reste %d points de magie \n", pdmSalameche -= coutFlammeche);
        }

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
                printf("\n");
                scanf("%d", &choixAction);
                printf("\n");
            }
        }
        //--------------------------------------------------------------------------------------------------------------------------------------------------------------
        //TOUR DE BULBIZARRE

        if (pdmBulbizarre<10)
        {
            printf("Bulbizarre recupere 1 pt de magie\n");
            pdmBulbizarre ++;
        }
        
        if (dotBulbizarre != 0)
        {
            printf("Salameche souffre du poison (%dHP)", pdvBulbizarre -= dmgPoison);
        }
        
        printf("C'est le tour de Bulbizarre, que souhaitez vous faire ?\n");
        printf("=>Tapez 1 pour lancer une attaque legere\n");
        printf("=>Tapez 2 pour vous defendre\n");
        printf("=>Tapez 3 pour lancer un sort de soin\n");
        printf("=>Tapez 4 pour utiliser un sort d'antidote\n");
        printf("=>Tapez 5 pour aggro un nouvel ennemi\n");
        printf("\n");
        scanf("%d", &choixAction);
        printf("\n");

        if (choixAction == 1)
        {
            printf("Qui voulez vous attaquer ? Aspicot = 4, Abo = 5, Smogo = 6\n");
            printf("\n");
            scanf("%d", &choixCible);
            printf("\n");
            printf("Vous lancez une attaque legere ! \n");
            if (choixCible == idAspicot)
            {
                pdvAspicot -= atkLegere;
                printf("Aspicot a %d points de vie! \n", pdvAspicot);
            }
            if (choixCible == idAbo)
            {
                pdvAbo -= atkLegere;
                printf("Abo a %d points de vie! \n", pdvAbo);
            }
            if (choixCible == idSmogo)
            {
                pdvSmogo -= atkLegere;
                printf("Smogo a %d points de vie! \n", pdvSmogo);
            }
        }


        else if (choixAction == 2)
        {
            printf("Vous vous protegez et votre defense est multipliee par 4 ! \n");
            printf("Vous avez %d point de vie ! \n", pdvBulbizarre);

        }


        else if (choixAction == 3)
        {
            printf("Bulbizarre utilise Soin ! \n");
            printf("Qui voulez vous soigner ? Salameche = 1, Bulbizarre = 2, Carapuce = 3.\n");
            printf("\n");
            scanf("%d", &choixCible);
            printf("\n");
            if (choixCible == idSalameche)
            {
                pdvSalameche += Soin;
                printf("Salameche a %d points de vie! \n", pdvSalameche);
            }
            if (choixCible == idBulbizarre)
            {
                pdvBulbizarre += Soin;
                printf("Bulbizarre a %d points de vie! \n", pdvBulbizarre);
            }
            if (choixCible == idCarapuce)
            {
                pdvCarapuce += Soin;
                printf("Carapuce a %d points de vie! \n", pdvSalameche);
            }
            printf("Il vous reste %d points de magie \n", pdmBulbizarre -= coutSort);
        }

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
                printf("\n");
                scanf("%d", &choixAction);
                printf("\n");
            }
        }
        //--------------------------------------------------------------------------------------------------------------------------------------------------------------
        //TOUR DE CARAPUCE
        
        if (pdmBulbizarre<10)
        {
            printf("Carapuce recupere 1 pt de magie\n");
            pdmCarapuce ++;
        }
        
        if (dotCarapuce != 0)
        {
            printf("Salameche souffre du poison (%d)", pdvCarapuce -= dmgPoison);
        }
        
        printf("C'est le tour de Carapuce, que souhaitez vous faire ?\n");
        printf("=>Tapez 1 pour lancer une attaque legere\n");
        printf("=>Tapez 2 pour vous defendre\n");
        printf("=>Tapez 3 pour lancer un sort de d'aggro\n");
        printf("=>Tapez 4 pour utiliser un sort d'antidote\n");
        printf("=>Tapez 5 pour aggro un nouvel ennemi\n");
        printf("\n");
        scanf("%d", &choixAction);
        printf("\n");

        if (choixAction == 1)
        {
            printf("Qui voulez vous attaquer ? Aspicot = 4, Abo = 5, Smogo = 6\n");
            printf("\n");
            scanf("%d", &choixCible);
            printf("\n");
            printf("Vous lancez une attaque legere ! \n");
            if (choixCible == idAspicot)
            {
                pdvAspicot -= atkLegere;
                printf("Aspicot a %d points de vie! \n", pdvAspicot);
            }
            if (choixCible == idAbo)
            {
                pdvAbo -= atkLegere;
                printf("Abo a %d points de vie! \n", pdvAbo);
            }
            if (choixCible == idSmogo)
            {
                pdvSmogo -= atkLegere;
                printf("Smogo a %d points de vie! \n", pdvSmogo);
            }
        }


        else if (choixAction == 2)
        {
            printf("Vous vous protegez et votre defense est multipliee par 4 ! \n");
            printf("Vous avez %d point de vie ! \n", pdvCarapuce);

        }


        else if (choixAction == 3)
        {
            printf("Carapuce utilise Aggro ! \n");
            aggroCarapuce = 1;
            printf("Il vous reste %d points de magie \n", pdmCarapuce -= coutSort);
        }

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
                printf("\n");
                scanf("%d", &choixAction);
                printf("\n");
            }
        }
        //--------------------------------------------------------------------------------------------------------------------------------------------------------------
        //TOUR ENNEMIS
        // TOUR ASPICOT 

        printf("C'est au tour d'Aspicot.\n");
        
        if (pdmAspicot<10)
        {
            printf("Aspicot recupere 1 pt de magie\n");
            pdmAspicot ++;
        }
        
        //RANDOM ACTION ENNEMI
        
        if (choixActionEnnemi == 1)
        {
            printf("Il attaque !\n");
            //RANDOM ENNEMI
            
            if (idSalameche == choixCibleEnnemi && aggroCarapuce == 0)
            {
                pdvSalameche -= atkLegere;
                printf("Salameche a %d points de vie! \n", pdvSalameche);
            }
            
            if (idBulbizarre == choixCibleEnnemi && aggroCarapuce == 0)
            {
                pdvBulbizarre -= atkLegere;
                printf("Bulbizarre a %d points de vie! \n", pdvBulbizarre);
            }
            if (idCarapuce == choixCibleEnnemi || aggroCarapuce == 1)
            {
                pdvCarapuce -= atkLegere;
                printf("Carapuce a %d points de vie! \n", pdvCarapuce);
            }
            
        }
        
         else if (choixActionEnnemi == 2)
        {
            printf("Aspicot se protege et sa defense est multipliee ! \n");
            printf("Aspicot a %d point de vie ! \n", pdvAspicot);

        }
        
        else if (choixActionEnnemi == 3)
        {            
            printf("Il attaque !\n");
            
            //RANDOM ENNEMI
            
            if (idSalameche == choixCibleEnnemi && aggroCarapuce == 0)
            {
                dotSalameche == 1;
                printf("Salameche est empoisonne ! \n", pdvSalameche);
            }
            
            if (idBulbizarre == choixCibleEnnemi && aggroCarapuce == 0)
            {
                dotBulbizarre == 1;
                printf("Bulbizarre est empoisonne ! \n", pdvBulbizarre);
            }
            if (idCarapuce == choixCibleEnnemi || aggroCarapuce == 1)
            {
                dotCarapuce == 1;
                printf("Carapuce est empoisonne ! \n", pdvCarapuce);
            }
        }        
        //--------------------------------------------------------------------------------------------------------------------------------------------------------------
        //TOUR ABO
        
        printf("C'est au tour d'Abo.\n");
        
        if (pdmAbo<10)
        {
            printf("Abo recupere 1 pt de magie\n");
            pdmAbo ++;
        }
        
        //RANDOM ENNEMI
        
        if (choixActionEnnemi == 1)
        {            
            printf("Il attaque !\n");
            
            //RANDOM ENNEMI
            
            if (idSalameche == choixCibleEnnemi && aggroCarapuce == 0)
            {
                pdvSalameche -= atkLegere;
                printf("Salameche a %d points de vie! \n", pdvSalameche);
            }
            
            if (idBulbizarre == choixCibleEnnemi && aggroCarapuce == 0)
            {
                pdvBulbizarre -= atkLegere;
                printf("Bulbizarre a %d points de vie! \n", pdvBulbizarre);
            }
            if (idCarapuce == choixCibleEnnemi || aggroCarapuce == 1)
            {
                pdvCarapuce -= atkLegere;
                printf("Carapuce a %d points de vie! \n", pdvCarapuce);
            }
            
        }
        
         else if (choixActionEnnemi == 2)
        {
            printf("Abo se protege et sa defense est multipliee ! \n");
            printf("Aspicot a %d point de vie ! \n", pdvAbo);

        }
        
        else if (choixActionEnnemi == 3)
        {            
            printf("Il attaque !\n");
            
            //RANDOM ENNEMI
            
            if (idSalameche == choixCibleEnnemi && aggroCarapuce == 0)
            {
                dotSalameche == 1;
                printf("Salameche est empoisonne ! \n", pdvSalameche);
            }
            
            if (idBulbizarre == choixCibleEnnemi && aggroCarapuce == 0)
            {
                dotBulbizarre == 1;
                printf("Bulbizarre est empoisonne ! \n", pdvBulbizarre);
            }
            if (idCarapuce == choixCibleEnnemi || aggroCarapuce == 1)
            {
                dotCarapuce == 1;
                printf("Carapuce est empoisonne ! \n", pdvCarapuce);
            }
        }
        //--------------------------------------------------------------------------------------------------------------------------------------------------------------
        //TOUR SMOGO
        
        printf("C'est au tour de Smogo. \n");
        
        if (pdmSmogo<10)
        {
            printf("Smogo recupere 1 pt de magie\n");
            pdmAspicot ++;
        }
        
        //RANDOM ENNEMI
        
        if (choixActionEnnemi == 1)
        {
            printf("Il attaque !\n");
            
            //RANDOM ENNEMI
            
            if (idSalameche == choixCibleEnnemi && aggroCarapuce == 0)
            {
                pdvSalameche -= atkLegere;
                printf("Salameche a %d points de vie! \n", pdvSalameche);
            }
            
            if (idBulbizarre == choixCibleEnnemi && aggroCarapuce == 0)
            {
                pdvBulbizarre -= atkLegere;
                printf("Bulbizarre a %d points de vie! \n", pdvBulbizarre);
            }
            if (idCarapuce == choixCibleEnnemi || aggroCarapuce == 1)
            {
                pdvCarapuce -= atkLegere;
                printf("Carapuce a %d points de vie! \n", pdvCarapuce);
            }
            
        }
        
         else if (choixActionEnnemi == 2)
        {
            printf("Smogo se protege et sa defense est multipliee ! \n");
            printf("Smogo a %d point de vie ! \n", pdvSmogo);

        }
        
        else if (choixActionEnnemi == 3)
        {
            printf("Il attaque !\n");
            
            //RANDOM ENNEMI
            
            if (idSalameche == choixCibleEnnemi && aggroCarapuce == 0)
            {
                dotSalameche == 1;
                printf("Salameche est empoisonne ! \n", pdvSalameche);
            }
            
            if (idBulbizarre == choixCibleEnnemi && aggroCarapuce == 0)
            {
                dotBulbizarre == 1;
                printf("Bulbizarre est empoisonne ! \n", pdvBulbizarre);
            }
            if (idCarapuce == choixCibleEnnemi || aggroCarapuce == 1)
            {
                dotCarapuce == 1;
                printf("Carapuce est empoisonne ! \n", pdvCarapuce);
            }
        }

        //--------------------------------------------------------------------------------------------------------------------------------------------------------------
        //XP SYSTEM
        
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
				printf("Salameche est mort !!! \n");
				
				}	

			else if (pdvBulbizarre <= 0)
				{
				printf("Bulbizarre est mort !!! \n");
				
				}

			else if (pdvAbo <= 0)
				{
				printf("Abo etes mort !!! \n");
				printf("Vos pokemons ont gagne 10 points d'exp\n");
				exp[0]+=10;
				exp[1]+=10;
				exp[2]+=10;
				printf("Salameche a %d points d'experience\n", exp[0] );
				printf("Bulbizarre a %d points d'experience\n", exp[1] );
				printf("Carapuce a %d points d'experience\n", exp[2] );
				}

			else if (pdvCarapuce <= 0)
				{
				printf("Carapuce est mort !!! \n");
				
				}
				
			else if (pdvSmogo <= 0)
				{
				printf("Smogo est mort !!! \n");
				printf("Vos pokemons ont gagne 20 points d'exp\n");
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

    }
return 0;
}