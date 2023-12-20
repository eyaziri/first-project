#ifndef OFFRE_DEMPLOI_H_INCLUDED
#define OFFRE_DEMPLOI_H_INCLUDED

typedef struct
{
    char nom[50];
    int score;
}  RESULTAT;

struct employe
{
    int nombreexpErience ;
    char nom [30] ;
    int numero ;
    char diplome[30] ;
    int note ;
    RESULTAT*resultt;
};
typedef struct employe EMPLOYE ;

struct offredemploi
{
    float salaire ;
    char mission [30] ;
    int nbredemployer ;
    int nbredoffredemploi;
    EMPLOYE *employe;
};
typedef struct offredemploi OF;
struct entreprise
{
    char Nom[20];
    char Localisation[20];
    int Nombredemployes;
    OF*offredemploi;

};
typedef struct entreprise ENT;







EMPLOYE saisieemp () ;
OF saisieof () ;
void saisient (ENT*,int) ;
int saisienbrof() ;
void affichageent(ENT*,int,int);
void affichageof (OF) ;
void traitement1 (ENT*,int,int*);
void traitement2 (ENT*,int,int*) ;
void traitement3 (ENT*,int);
void traitement4 (ENT*,int,int*);
void traitement5 (ENT*,int,int*);
int menu1();
int menu2();
int menu3();
void ajoutoffre(ENT*,int,int*);
int existanceent (ENT*,int);
int indiceof (ENT*,int,int*) ;
void supprimerOffre(ENT*,int,int*) ;
int existanceentsup (ENT*,int) ;
void resultat1(ENT*, RESULTAT*,int,int);

void AffichageEntreprise(FILE *,FILE *,int);
void AfficherEnt(ENT ,int );
void AfficherUneEntreprise(FILE *, int , int );
void AfficherEtModifier(FILE *, int, int );

void remplirEtAfficherFichierEntreprisesIndexe(FILE *, FILE *, int );


#endif // OFFRE_DEMPLOI_H_INCLUDED
