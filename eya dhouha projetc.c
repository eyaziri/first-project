#include <stdio.h>
#include <stdlib.h>
#include "offre demploi.h"
#include "C:\Users\eyazi\OneDrive\Bureau\1ere soutenance\fonction.c"
#include <string.h>
int main()
{
    int n,r,j,i,a,b,o,p=0,k=0,sc;
    char ch [50] ;
    char ch1 [50] ;
    char ch2 [50] ;
    int estValide=1;
    OF off ;
    EMPLOYE empl ;
    float maximum ;
    int max1,index;
    int entrepriseExistante = 0;
    int max ,position_index;
    int choix2,choix1,choix3,choix4 ;
    RESULTAT*t;
    n = saisien() ;
    ENT tab[n] ;
    int d=saisienbrof() ;
    int*s;
    s=&d;
    FILE *binaryFileRead ;
    FILE *binaryFileWrite;
    FILE*f;
    FILE *f_index;
    FILE*f_entreprise ;


    while(1)
    {
        choix1=menu1();
        switch(choix1)
        {
        case 1:

            for (i = 0; i < n; i++)
            {

                saisient(&tab[i],*s);


            }
            break;
        case 2 :
            affichageent(tab,n,*s);
            break ;
        case 3:
            a=1;
            while (a==1)
            {
                choix2=menu2();
                switch(choix2)
                {
                case 1 :
                    traitement1(tab,n,s);
                    break;
                case 2 :
                    traitement2(tab,n,s);
                    break ;
                case 3:
                    traitement3(tab,n);
                    break ;
                case 4 :
                    traitement4(tab,n,s) ;
                    break ;
                case 5 :
                    traitement5(tab,n,s);
                    break ;

                case 6:
                    a=0;
                    break;

                default :
                    break ;
                }
            }
            break ;
        case 4 :
            b=1;
            while (b==1)
            {
                choix3=menu3();
                switch(choix3)
                {
                case 1 :

                    for (i = 0; i < n; i++)
                    {
                        ajoutoffre(&tab[i],n,s);
                    }
                    break;
                case 2 :
                    supprimerOffre(tab,n,s) ;
                    break;

                case 3 :
                    b=0 ;
                    break;
                default:
                    break ;
                }
            }
            break ;

        case 5 :

            t=( RESULTAT*)malloc(50*sizeof( RESULTAT));
            if (!t)exit(-1);
            resultat1(tab,t,n,d) ;

            break ;
        case 6 :

            AffichageEntreprise(binaryFileRead,binaryFileWrite,d);
            printf("\n\ndonnerl'index de l'entreprise que tu veux l'afficher\n\n");
            scanf("%d",&index);
            AfficherUneEntreprise(binaryFileRead,index,d);
            AfficherEtModifier(f,n,d);
            break ;

        case 7:

        remplirEtAfficherFichierEntreprisesIndexe(f_entreprise, f_index,d);

             break;
        case 8:
            return 0;
        default :
            break ;
        }
    }
}
