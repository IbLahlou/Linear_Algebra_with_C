#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** alloc_Tab2D(int);
void init_Tab(int**, int);
void aff_Tab(int**, int);
int det_Tab(int**, int);



int main()
{
    int n;
    int** T=NULL;
    printf("\t\t -----Calcul du DET-----");
    do
    {
        printf("\n\n");
        printf("Entrer l'ordre de la Matrice :  ");
        scanf("%d", &n);
    }
    while(n<=0);
    T = alloc_Tab2D(n);
    printf("\n\n");
    init_Tab(T,n);
    aff_Tab(T,n);
    printf("\n\n");
    printf("Le det de cette Matrice est :  %d",det_Tab(T,n));
    printf("\n\n");

    return 0;
}


int** alloc_Tab2D(int nl)  // allocation de l'espace
{
    int i;
    int** tab=NULL;
    tab = (int**) malloc(sizeof(int*)*nl);
    if(tab==NULL)
    {
        printf("\nERREUR");
        exit(0);
    }
    for(i=0; i<nl; i++)
    {
        tab[i] = (int*) malloc(sizeof(int)*nl);
        if(tab[i]==NULL)
        {
            printf("\nERREUR");
            exit(1);
        }
    }
    return tab;
}

void init_Tab(int **M, int nl) // initialisation des valeurs du tableau
{
    int i,j;
    for(i=0; i<nl; i++)
        for(j=0; j<nl; j++)
        {
            printf("Enter la valeur a la ligne : %d, cologne : %d   :  ", i+1,j+1);
            scanf("%d", &M[i][j]);
        }
}

void aff_Tab(int **M, int nl)  // affichage du tableau
{
    int i,j;
    for(i=0; i<nl; i++)
    {
        printf("\n");
        for(j=0; j<nl; j++)
            printf("\t %d", M[i][j]);
    }
}

int det_Tab(int **M, int nl) //Calcul du determinant
{
    int **tab=NULL;
    int i,j,n,T=0;
    if (nl==1)
        return M[0][0];
    else if (nl==2)
        return (M[0][0] * M[1][1] - M[1][0] * M[0][1]);
    else
    {
        tab =alloc_Tab2D(nl-1);
        for(n=0; n<nl; n++)
        {
            for(i=0; i<nl-1; i++)
                for(j=0; j<nl-1; j++)
                {
                    if(i<n)
                    {
                        tab[i][j]= pow(-1,i+j+3) * M[i][j+1];
                    }
                    else
                    {
                        tab[i][j]= pow(-1,i+j+4) * M[i+1][j+1];
                    }
                }
            T += M[n][0] * det_Tab(tab,nl-1);
        }
        return T;
    }
}
