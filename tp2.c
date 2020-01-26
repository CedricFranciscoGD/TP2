#include <stdio.h>
// Bibliothèque permettant de générer des nombres aléatoire pour programmer le comportement du monstre
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
    
    int Soin = 4;

    //attaques
	int atkLegere = 1;
    int atkLourde = 3;
    
	//Variable comportement joueur
	int choixAction = 0;
    int choixCible = 0;
    int choixCibleEnnemi = 0;
    int choixActionEnnemi = 0;
	//Variable comportement Monstre
	int i = 0;
	int coutSort = 3;
	int coutAntidote = 5;
    
    

	printf("Un Aspicot sauvage apparait\n");
	printf("Aspicot sauvage a %d points de vie\n", pdvAspicot);
	printf("Vous avez %d points de vie \n", pdvSalameche);



// Boucle de combat 
	while (nombreAmi > 0 || nombreEnnemi >0)
	{
        //-------------------------------------------------------------------------------------------------------------------------
        //TOUR DE SALAMECHE
        if (pdmSalameche<10)
        {
            printf("Salameche recupere 1 pt de magie\n");
            pdmSalameche ++;
        }
        printf("C'est le tour de Salameche que souhaitez vous faire ? \n");
        printf("Tapez 1 pour lancer une attaque lourde\n");
        printf("Tapez 2 pour vous defendre\n");
        printf("Tapez 3 pour lancer flammeche\n");
        printf("Tapez 4 pour utiliser un sort d'antidote\n");
        printf("Tapez 5 pour aggro un nouvel ennemi\n");
        scanf("%d", &choixAction);

        if (choixAction == 1)
        {
            printf("Qui voulez vous attaquer ? Aspicot = 4, Abo = 5, Smogo = 6\n");
            scanf("%d", &choixCible);
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
            scanf("%d", &choixCible);
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
        printf("Tapez 3 pour lancer un sort de soin\n");
        printf("Tapez 4 pour utiliser un sort d'antidote\n");
        printf("Tapez 5 pour aggro un nouvel ennemi\n");
        scanf("%d", &choixAction);

        if (choixAction == 1)
        {
            printf("Qui voulez vous attaquer ? Aspicot = 4, Abo = 5, Smogo = 6\n");
            scanf("%d", &choixCible);
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
            printf("Qui voulez vous soigner ? Salamèche = 1, Bulbizarre = 2, Carapuce = 3.\n");
            scanf("%d", &choixCible);
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
        printf("Tapez 3 pour lancer un sort de d'aggro\n");
        printf("Tapez 4 pour utiliser un sort d'antidote\n");
        printf("Tapez 5 pour aggro un nouvel ennemi\n");
        scanf("%d", &choixAction);

        if (choixAction == 1)
        {
            printf("Qui voulez vous attaquer ? Aspicot = 4, Abo = 5, Smogo = 6\n");
            scanf("%d", &choixCible);
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
            aggroCarapuce == 1;
            printf("Il vous reste %d points de magie \n", pdmCarapuce -= coutSort);
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
        
        printf("C'est au tour d'Aspicot.");
        
        if (pdmAspicot<10)
        {
            printf("Aspicot recupere 1 pt de magie\n");
            pdmAspicot ++;
        }
        
        for (i = 0; i < 1; i++)
        {
            choixActionEnnemi = printf("%d\n", 1 + rand()%3);
        }
        
        if (choixActionEnnemi == 1)
        {
            for (i = 0; i < 1; i++)
            {
                choixCibleEnnemi = printf("%d\n", 1 + rand()%3);
            }
            
            if (idSalameche == choixCibleEnnemi)
            {
                pdvSalameche -= atkLegere;
                printf("Salameche a %d points de vie! \n", pdvSalameche);
            }
            
            if (idBulbizarre == choixCibleEnnemi)
            {
                pdvBulbizarre -= atkLegere;
                printf("Bulbizarre a %d points de vie! \n", pdvBulbizarre);
            }
            if (idCarapuce == choixCibleEnnemi)
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
            for (i = 0; i < 1; i++)
            {
                choixCibleEnnemi = printf("%d\n", 1 + rand()%3);
            }
            
            if (idSalameche == choixCibleEnnemi)
            {
                dotSalameche == 1;
                printf("Salameche est empoisonné ! \n", pdvSalameche);
            }
            
            if (idBulbizarre == choixCibleEnnemi)
            {
                dotBulbizarre == 1;
                printf("Bulbizarre est empoisonné ! \n", pdvBulbizarre);
            }
            if (idCarapuce == choixCibleEnnemi)
            {
                dotCarapuce == 1;
                printf("Carapuce est empoisonné ! \n", pdvCarapuce);
            }
        }

        
        //-----------------------------------------------------------------
        //TOUR ABO
        
        printf("C'est au tour d'Abo.");
        
        if (pdmAbo<10)
        {
            printf("Aspicot recupere 1 pt de magie\n");
            pdmAbo ++;
        }
        
        for (i = 0; i < 1; i++)
        {
            choixActionEnnemi = printf("%d\n", 1 + rand()%3);
        }
        
        if (choixActionEnnemi == 1)
        {
            for (i = 0; i < 1; i++)
            {
                choixCibleEnnemi = printf("%d\n", 1 + rand()%3);
            }
            
            if (idSalameche == choixCibleEnnemi)
            {
                pdvSalameche -= atkLegere;
                printf("Salameche a %d points de vie! \n", pdvSalameche);
            }
            
            if (idBulbizarre == choixCibleEnnemi)
            {
                pdvBulbizarre -= atkLegere;
                printf("Bulbizarre a %d points de vie! \n", pdvBulbizarre);
            }
            if (idCarapuce == choixCibleEnnemi)
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
            for (i = 0; i < 1; i++)
            {
                choixCibleEnnemi = printf("%d\n", 1 + rand()%3);
            }
            
            if (idSalameche == choixCibleEnnemi)
            {
                dotSalameche == 1;
                printf("Salameche est empoisonné ! \n", pdvSalameche);
            }
            
            if (idBulbizarre == choixCibleEnnemi)
            {
                dotBulbizarre == 1;
                printf("Bulbizarre est empoisonné ! \n", pdvBulbizarre);
            }
            if (idCarapuce == choixCibleEnnemi)
            {
                dotCarapuce == 1;
                printf("Carapuce est empoisonné ! \n", pdvCarapuce);
            }
        }
        
        
        //---------------------------------------------------------------------------------------------
        //TOUR SMOGO
        
        printf("C'est au tour de Smogo.");
        
        if (pdmSmogo<10)
        {
            printf("Aspicot recupere 1 pt de magie\n");
            pdmAspicot ++;
        }
        
        for (i = 0; i < 1; i++)
        {
            choixActionEnnemi = printf("%d\n", 1 + rand()%3);
        }
        
        if (choixActionEnnemi == 1)
        {
            for (i = 0; i < 1; i++)
            {
                choixCibleEnnemi = printf("%d\n", 1 + rand()%3);
            }
            
            if (idSalameche == choixCibleEnnemi)
            {
                pdvSalameche -= atkLegere;
                printf("Salameche a %d points de vie! \n", pdvSalameche);
            }
            
            if (idBulbizarre == choixCibleEnnemi)
            {
                pdvBulbizarre -= atkLegere;
                printf("Bulbizarre a %d points de vie! \n", pdvBulbizarre);
            }
            if (idCarapuce == choixCibleEnnemi)
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
            for (i = 0; i < 1; i++)
            {
                choixCibleEnnemi = printf("%d\n", 1 + rand()%3);
            }
            
            if (idSalameche == choixCibleEnnemi)
            {
                dotSalameche == 1;
                printf("Salameche est empoisonné ! \n", pdvSalameche);
            }
            
            if (idBulbizarre == choixCibleEnnemi)
            {
                dotBulbizarre == 1;
                printf("Bulbizarre est empoisonné ! \n", pdvBulbizarre);
            }
            if (idCarapuce == choixCibleEnnemi)
            {
                dotCarapuce == 1;
                printf("Carapuce est empoisonné ! \n", pdvCarapuce);
            }
        }
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
            if (pdvAspicot <= 0 )
                {	printf("Aspicot est mort !!! \n");

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

                }

            else if (pdvCarapuce <= 0)
                {
                printf("Carapuce etes mort !!! \n");

                }

            else if (pdvSmogo <= 0)
                {
                printf("Smogo etes mort !!! \n");

                }
    }
    printf("FIN DE TOUR");
return 0;
}