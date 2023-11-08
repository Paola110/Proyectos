#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
#define SPEED ios_base::sync_with_stdio(0);

int main() {
    SPEED; 

    int A[10][10],B[10][10],R[10][10];
    int columA, filA, columB,filB;
    int i,j,z;

    srand (time (NULL));

    do{
        printf("\n\nBienvenido al menu: \n\n");
        printf("\n Proporciona la dimension de la matriz A, minimo 2 máximo 10, fila y columna, separados por comas \n");
        scanf ("%d,%d",&filA, &columA);
        printf("\n Proporciona la dimension de la matriz B, minimo 2 máximo 10, fila y columna, separados por comas \n");
        scanf ("%d,%d",&filB,&columB);
        if (columA!=filB){
            printf("\nNo se puede hacer la multiplicacion si el numero de filas de la matriz A\nes diferente del numero de columnas de la matriz B, ingresa nuevamente los datos.");
        }
        if (columA<2||columA>10||columB<2||columB>10||filA<2||filA>10){
            printf("\nLas dimenciones deben ser de minimo 2 y maximo 10\n\nProporciona los datos nuevamente\n");
        }
    } while (columA<2||columA>10||columB<2||columB>10||filA<2||filA>10||columA!=filB);
    
    printf ("\n\n Matriz A\n\n");
    
    for(i=0;i<filA;i++) {
        printf ("\n");
        for(j=0;j<columA;j++){
            A[i][j]=rand()%9+1;
            printf("%d\t",A[i][j]);
        }
    }

    printf ("\n\n Matriz B\n\n");

    for(i=0;i<filB;i++){
        printf ("\n");
        for(j=0;j<columB;j++){
            B[i][j]=rand()%9+1;
            printf("%d\t",B[i][j]);
        }
    }

    //Multiplicar Matrices

    printf("\n\nMatriz resultante\n\n");

    for(i=0;i<filA;i++){
        for(j=0;j<columB;j++){
            R[i][j]=0;
            for(z=0;z<filB;z++){
                R[i][j]=R[i][j]+(A[i][z]*B[z][j]);
            }
        }
    }

    for(i=0;i<filA;i++){
        printf("\n");
        for(j=0;j<columB;j++){

            printf("\t%d",R[i][j]);

        }
    }

    printf("\n\n");
    system("pause");
	return 0;
}
