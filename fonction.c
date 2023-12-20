#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int saisien ()
{
    int n ;
    printf("donner le nombre dentreprise = ");
    scanf("%d",&n);
    return n;
}

//***********************************************************************************************************************************//

EMPLOYE saisieemp ()
{
    EMPLOYE emp ;
    printf("\ndonner le nom d'employe:\n");
    scanf("%s",&emp.nom);

    printf("\ndonner le numero d'employe:\n");
    scanf("%d",&emp.numero);

    printf("\ndonner le diplome d'employe:\n");
    scanf("%s",&emp.diplome);

    printf("\ndonner le nmbre dexperience:\n");
    scanf("%d",&emp.nombreexpErience);

    printf("\ndonner la note d'employe donnee par sa entreprise precedante:\n");
    scanf("%d",&emp.note);

    return emp ;

}

//***********************************************************************************************************************************//
int saisienbrof()
{
    OF of;
    printf("\ndonner le nbre d'offre d'emploi:\n");
    scanf("%d",&of.nbredoffredemploi);
    return of.nbredoffredemploi ;
}


//***********************************************************************************************************************************//
OF saisieof ()
{
    OF of ;
    int i ;
    printf("\ndonner le salaire d'offre d'emploi suivant:\n");
    scanf("%f",&of.salaire);

    printf("\ndonner la mission d'offre d'emploi:\n");
    scanf("%s",&of.mission);

    printf ("\ndonner le nbre d'employe qui veulent cet offre d'emploi:\n");
    scanf("%d",&of.nbredemployer);


    of.employe=(EMPLOYE*)malloc(of.nbredemployer*sizeof(EMPLOYE));
    printf(" \n-------------saisie des employers--------------- \n");
    for (i=0; i<of.nbredemployer; i++)
    {
        of.employe[i]= saisieemp();
    }


    return of ;
}

//***********************************************************************************************************************************//
void saisient (ENT*e,int d)
{
    int j ;
    printf ("\n donner le nom d'entreprise :\n ");
    scanf("%s",e->Nom) ;

    printf ("\n donner la localisation d'entreprise: \n ");
    scanf("%s",e->Localisation) ;

    printf ("\n donner le nombre d'employes d'entreprise :\n ");
    scanf("%d",&e->Nombredemployes) ;

    e->offredemploi = (OF*)malloc(d*sizeof(OF));
    for(j=0; j<d; j++)
        e->offredemploi[j] = saisieof();


}

//***********************************************************************************************************************************//

void affichageof (OF of )
{
    {
        printf("\n--------------------------------------------------------------------------------------\n");
        printf("\n le salaire d'offre d'emploi est : %f \n",of.salaire);
        printf("\n la mission d'offre d'emploi est : %s \n",of.mission);
        printf ("\n le nbre d'employe est: %d \n",of.nbredemployer);

        printf(" \n-------------affichage des employes--------------- \n");
        for (int i=0; i<of.nbredemployer; i++)
        {
            printf("\n le nom d'employe est : %s\n",of.employe[i].nom);
            printf("\nle numero d'employe est : %d\n",of.employe[i].numero);
            printf("\nle diplome d'employe est: %s\n",of.employe[i].diplome);
            printf("\nle nmbre dexperience: %d\n",of.employe[i].nombreexpErience);
            printf("\n...................................................................................\n");

        }
    }
}

//***********************************************************************************************************************************//
void affichageent(ENT* tab,int n,int d)
{
    OF of ;
    int i,j;
    printf("\n***********AFFICHAGE**************\n");

    for (i=0; i<n; i++)
    {
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf ("\n l'entreprise : %s localise en : %s a un nombre d'employe : %d \n ",tab[i].Nom,tab[i].Localisation,tab[i].Nombredemployes);
        for (j=0; j<d; j++)
        {
            affichageof((tab[i].offredemploi[j])) ;
        }
    }
}

//***********************************************************************************************************************************//
int menu1()
{
    int choix ;
    printf("\nmenu1:\n1-saisie \n2-affichage \n3-acceder aux traitements \n4-gestion d'offre demploi\n5-resultat\n6-fichier binaire de structure\n7-fichier binaire index\n8-quitter \n") ;
    scanf("%d",&choix);
    return choix;
}

//***********************************************************************************************************************************//
int menu2()
{
    int d ;
    printf("\nmenu2:\n1-affichage des employes diplomes en informatique\n2-afficher le salaire le plus grand entre les entreprises\n3-afficher les entreprises localisees dans le grand Tunis\n4-afficher loffre demploi dont le nombre d'employees demandes est plus grand\n5-afficher l'employe qui a le plus d'experience \n6-return\n ");
    scanf("%d",&d);
    return d;
}

//***********************************************************************************************************************************//
int menu3()
{
    int choix ;
    printf("menu3:\n1-ajouter un offre demploi\n2-supprimerun offre demploi\n3-retourne\n");
    scanf("%d",&choix);
    return choix;
}

//***********************************************************************************************************************************//
void traitement1 (ENT*tab,int n,int*s)
{
    int i,j ;
    printf("\n-------------traitement 1 :affichage des employes diplomes en informatique--------------- \n");

    for (int i = 0; i<n; i++)
    {
        for(j=0; j<*s; j++)
        {
            if (strcmp(tab[i].offredemploi[j].employe->diplome, "informatique") == 0)
            {
                printf ("\n %s est diplome(e) en informatique \n",tab[i].offredemploi[j].employe->nom) ;
            }

        }
    }
    printf("\n il n y a pas un autre diplome en informatique\n");

}

//***********************************************************************************************************************************//
void traitement2(ENT* tab, int n, int* s)
{
    printf("\n------------- Traitement 2 : Le salaire le plus grand entre les entreprises --------------- \n");
    if (n == 1)
    {
        printf("Malheureusement, il n'existe qu'une seule entreprise.\n");
        return;
    }

    int i, j, indice = 0;
    float maxi;
    maxi = tab[0].offredemploi[0].salaire;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < *s; j++)
        {
            if (tab[i].offredemploi[j].salaire > maxi)
            {
                maxi= tab[i].offredemploi[j].salaire;
                indice = i;
            }
        }
    }

    printf("L'entreprise '%s' a le plus grand salaire : %.2f DT\n", tab[indice].Nom, maxi);
}

//***********************************************************************************************************************************//
void traitement3 (ENT* tab,int n)
{
    int i ;
    printf("\n-------------traitement 3 :les entreprises localisees dans le grand Tunis --------------- \n");
    for (i=0; i<n; i++)
    {
        if((strcmp(tab[i].Localisation,"tunis")==0)||(strcmp(tab[i].Localisation,"ariana")==0)||(strcmp(tab[i].Localisation,"benarous")==0)||(strcmp(tab[i].Localisation,"manouba")==0))
            printf("\n%s est situee dans le grand tunis\n",tab[i].Nom);
    }
}

//********************************************************************************************************************************************//

void traitement4(ENT* tab, int n, int *s)
{
    int i, j;
    printf("\n-------------traitement 4 : offre d'emploi dont le nombre d'employés demandés est le plus grand--------------- \n");
    int max = tab[0].offredemploi[0].nbredemployer;
    int k = 0, h = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < *s; j++)
        {
            if (max < tab[i].offredemploi[j].nbredemployer)
            {
                max = tab[i].offredemploi[j].nbredemployer;
                k = i;
                h = j;
            }
        }
    }
    printf("\nLe nombre maximal d'employes demandes est : %d\n", max);
    printf("Offre d'emploi avec le nombre maximum d'employes demandes : %s\n", tab[k].offredemploi[h].mission);
}

//***************************************************************************************************************************************//
void traitement5(ENT* tab,int n,int*s)
{
    printf("\n-------------traitement 5 :l'employe qui a le plus d'experience--------------- \n");
    int i,j;
    int max1 ;
    int p =0,l=0 ;
    max1=tab[0].offredemploi[0].employe->nombreexpErience ;
    for(i=0; i<n; i++)
    {
        for(j=0; j<*s; j++)
        {
            if ( max1 <tab[i].offredemploi[j].employe->nombreexpErience)
            {
                max1=tab[i].offredemploi[j].employe->nombreexpErience ;
                p=i;
                l=j;
            }
        }
    }
    printf("l'employe qui a le plus d'experience : %s , avec nombre d'experience = %d ",tab[p].offredemploi[l].employe->nom,max1) ;
}

//****************************************************************************************************//

int existanceent (ENT *e,int n)
{
    int d=0 ;
    char ch [50];
    printf ("\ndonner le nom de l'entreprise que tu veux ajouter l'offre demploi dedans=\n");
    scanf("%s",&ch);


    if(strcmp(e->Nom,ch)==0)
    {
        d=1;
    }

    return d ;
}
//****************************************************************************************************//

void ajoutoffre(ENT *e,int n,int*s)
{
    int index = existanceent(e,n);

    if (index ==1)
    {
        e->offredemploi=(OF*)realloc (e->offredemploi,(*s+1)*sizeof(OF));
        e->offredemploi[*s]=saisieof() ;
        *s=*s+1;

    }
    else
    {
        printf("\nEntreprise non existante.\n");
    }
}
//***********************************************************************************************//
int existanceentsup (ENT *e,int n)
{
    int b=0 ;
    char ch1 [50];
    printf ("\ndonner le nom de l'entreprise que tu veux supprimer l'offre demploi dedans=\n");
    scanf("%s",&ch1);
    if(strcmp(e->Nom,ch1)==0)
    {
        b=1;
    }
    return b ;
}
//************************************************************************************************//
int indiceof (ENT*e,int n,int*s)
{
    int i,j ;
    int d= -1;
    char ch [50];
    int b=0 ;
    char ch1 [50];
    printf ("\ndonner le nom de l'entreprise que tu veux supprimer l'offre demploi dedans=\n");
    scanf("%s",&ch1);
    for(j=0; j<n; j++)
    {
        if(strcmp(e[j].Nom,ch1)==0)
        {
            b=j;
            printf ("\ndonner la mission de l'offre demploi que vous voulez supprimer=\n");
            scanf("%s",&ch);
            for(i=0; i<*s; i++)
            {
                if(strcmp(e[b].offredemploi[i].mission,ch)==0)
                {
                    d=i ;
                }
            }
        }
    }
    return d ;

}
//*******************************************************************************************//
void supprimerOffre(ENT* e, int n,int*s)
{
    int i ;
    int index2= indiceof(e,n,s);
    if (index2!=-1)
    {
        for(i=index2; i<*s-1; i++)
        {
            e->offredemploi[i]=e->offredemploi[i+1];
        }
        e->offredemploi=(OF*)realloc (e->offredemploi,(*s-1)*sizeof(OF));
        *s=*s-1;

        printf("\n la suppression est reussite\n");
    }
    else
    {
        printf("\nvos donnees ne sont pas correctes assurez-vous de vos donnees\n");
    }
}



//**********************************************************************//

void resultat1(ENT *e,  RESULTAT *t,int d,int n)
{
    int i, j, k,v,maxScore,m=0;
    int Comp[n];
    char ** Comp1;
    Comp1 = malloc(n*sizeof(char*));
    for(i=0; i<n; i++)
        Comp1[i]=malloc(20*sizeof(char));
    char ch[20];

    for (i = 0; i < n; i++)
    {
        maxScore = (e[0].offredemploi[0].employe[0].note) * 2;

        for (j = 0; j < d; j++)
        {
            m=e[i].offredemploi[j].nbredemployer;

            for (k = 0; k < m; k++)
            {
                t[k].score = (e[i].offredemploi[j].employe[k].note) * 2;

                strcpy(t[k].nom, e[i].offredemploi[j].employe[k].nom);

                if ( t[k].score >= maxScore)
                {
                    maxScore = t[k].score;
                    strcpy(Comp1[i],t[k].nom);
                }
            }
        }
        Comp[i]=maxScore ;
    }
    maxScore = Comp[0];
    for (i=0; i<n ; i++)
    {
        if (maxScore<=Comp[i])
        {
            maxScore=Comp[i];
            v=i;
        }
    }
    printf("L'employe avec le score le plus eleve dans l'entreprise %s est : %s, avec un score de : %d\n", e[v].Nom, Comp1[v], maxScore);

}
//*****************************************************************************//


void AfficherEnt(ENT e,int d)
{
    int j ;
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf ("\n l'entreprise : %s localise en : %s a un nombre d'employe : %d \n ",e.Nom,e.Localisation,e.Nombredemployes);
    for (j=0; j<d; j++)
    {
        affichageof((e.offredemploi[j])) ;
    }
}
void AffichageEntreprise(FILE *binaryFileRead,FILE *binaryFileWrite,int d)
{
    ENT readEnterprise;
    ENT myEnterprise;

    binaryFileWrite = fopen("enterprise_data.bin", "wb");
    if (binaryFileWrite == NULL)exit(-1);
    saisient(&myEnterprise,d);
    fwrite(&myEnterprise, sizeof(ENT), 1, binaryFileWrite);

    fclose(binaryFileWrite);

    binaryFileRead = fopen("enterprise_data.bin", "rb");
    if (binaryFileRead == NULL)exit(-1);
    fread(&readEnterprise, sizeof(ENT), 1, binaryFileRead);

    fclose(binaryFileRead);
    AfficherEnt(readEnterprise,d);
}



//**********************************************************************************//

void AfficherUneEntreprise(FILE *binaryFileRead, int index, int d)
{
    ENT readEnterprise;

    binaryFileRead = fopen("enterprise_data.bin", "rb");
    if (binaryFileRead == NULL) exit(-1);

    fseek(binaryFileRead, index * sizeof(ENT), SEEK_SET);
    fread(&readEnterprise, sizeof(ENT), 1, binaryFileRead);

    fclose(binaryFileRead);
    AfficherEnt(readEnterprise, d);
}
//*****************************************************************************//
void AfficherEtModifier(FILE *f, int n, int d)
{
    int pos;
    printf("\nSaisir la position de l'entreprise a afficher et modifier :\n ");
    scanf("%d", &pos);

    AfficherUneEntreprise(f, pos - 1, d);

    ENT updatedEnterprise;
    printf("\n\n Modifier les details de l'entreprise :\n\n");
    printf("\nEntrez le nouveau nom de l'entreprise : \n");
    scanf("%s", updatedEnterprise.Nom);

    printf("\nEntrez la nouvelle localisation de l'entreprise : \n");
    scanf("%s", updatedEnterprise.Localisation);

    printf("\nEntrez le nouveau nombre d'employes : \n");
    scanf("%d", &updatedEnterprise.Nombredemployes);
    updatedEnterprise.offredemploi = (OF*)malloc(d * sizeof(OF));
    for (int i = 0; i < d; ++i)
    {
        printf("\nEntrez une nouvelle valeur pour offredemploi[%d] : \n", i+1);

        printf("\nDonnez le salaire de l'offre d'emploi : \n");
        scanf("%f", &updatedEnterprise.offredemploi[i].salaire);

        printf("\nDonnez la mission de l'offre d'emploi : \n");
        scanf("%s", updatedEnterprise.offredemploi[i].mission);

        printf("\nDonnez le nombre d'employes recherches pour cette offre d'emploi : \n");
        scanf("%d", &updatedEnterprise.offredemploi[i].nbredemployer);

        updatedEnterprise.offredemploi[i].employe = (EMPLOYE*)malloc(updatedEnterprise.offredemploi[i].nbredemployer * sizeof(EMPLOYE));
        printf("\n-------------saisie des employes--------------- \n");
        for (int j = 0; j < updatedEnterprise.offredemploi[i].nbredemployer; j++)
        {
            updatedEnterprise.offredemploi[i].employe[j] = saisieemp();
        }
    }
    FILE *binaryFileWrite = fopen("enterprise_data.bin", "rb+");
    if (binaryFileWrite == NULL) exit(-1);

    fseek(binaryFileWrite, (pos - 1) * sizeof(ENT), SEEK_SET);
    fwrite(&updatedEnterprise, sizeof(ENT), 1, binaryFileWrite);

    fclose(binaryFileWrite);


    AfficherUneEntreprise(f, pos - 1, d);
}

//*******************************************************************************//
void remplirEtAfficherFichierEntreprisesIndexe(FILE *f_entreprise, FILE *f_index, int d) {
    ENT myEnterprise;
    long position;
    int i, j;

    f_entreprise = fopen("enterprise.bin", "wb+");
    f_index = fopen("index.bin", "wb+");

    if (f_entreprise == NULL || f_index == NULL) {
        printf("Erreur lors de l'ouverture des fichiers.\n");
        return;
    }

    fseek(f_entreprise, 0, SEEK_END);
    saisient(&myEnterprise, d);
    fwrite(&myEnterprise, sizeof(ENT), 1, f_entreprise);
    position = ftell(f_entreprise);
    fwrite(&position, sizeof(long), 1, f_index);

    fclose(f_index);
    fclose(f_entreprise);

    f_entreprise = fopen("enterprise.bin", "rb");
    f_index = fopen("index.bin", "rb");

    if (f_entreprise == NULL || f_index == NULL) {
        printf("Erreur lors de la lecture des fichiers.\n");
        return;
    }

    printf("\n\n ----------Affichage fichier index----------\n\n");
    while (fread(&position, sizeof(long), 1, f_index) != 0) {
        printf("\n%d", position);
    }

    rewind(f_index);
    printf("\n\n----------Affichage fichier entreprise--------\n\n");
    while (fread(&position, sizeof(long), 1, f_index) != 0) {
        fseek(f_entreprise, position, SEEK_SET);
        fread(&myEnterprise, sizeof(ENT), 1, f_entreprise);
        printf("\n\nL'entreprise : %s   localisee en : %s    a un nombre d'employes : %d \n\n",
               myEnterprise.Nom, myEnterprise.Localisation, myEnterprise.Nombredemployes);

        for (i = 0; i < d; i++) {
            printf("Offre d'emploi %d:\n\n", i + 1);
            printf("\nSa mission est : %s, son nombre d'employes : %d, et son salaire : %.2f\n",
                   myEnterprise.offredemploi[i].mission, myEnterprise.offredemploi[i].nbredemployer,
                   myEnterprise.offredemploi[i].salaire);

            for (j = 0; j < myEnterprise.offredemploi[i].nbredemployer; j++) {
                printf("\nEmploye %d: Nom: %s, Experience: %d\n",
                       j + 1, myEnterprise.offredemploi[i].employe[j].nom,
                       myEnterprise.offredemploi[i].employe[j].nombreexpErience);
            }
        }
    }

    fclose(f_index);
    fclose(f_entreprise);
}
