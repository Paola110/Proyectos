#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define TAM 31

int main(){
    printf("\nJoshua Veloz");
    int i, arriba=0;
    float grados,dia[TAM],temp, mayor=0;
    srand(time(NULL));

    printf("\n\n  Temperatura de AGS durante octubre\n\n");
    for (i=0;i<=TAM;i++){
        grados=rand()% 19+13;
        dia[i]=grados;
        if(i==0){
            mayor=dia[i];
        } else if(dia[i]>mayor){
            mayor=dia[i];
        }
        printf("\nDia %d = %.2f grados centigrados",i+1,dia[i]);
        temp+=grados;
    }
    printf("\n\nEl promedio de temperatura para el mes de octubre fue de: %.2f grados centigrados", temp/31);

    for (i=0; i<TAM;i++){
        if (dia[i]>(temp/31)){
            arriba++;
        }
    }

    printf("\n\n%d dias estuvieron por encima de la temperatura promedio", arriba);

    printf("\n\nLos dias que estuvieron por debajo de la temperatura promedio de %.2f fueron:\n", temp/31 );
    
    for (i=0; i<TAM;i++){
        if (dia[i]<(temp/31)){
           printf("\nEl dia %d con =%.2f grados centigrados",i+1,dia[i]);
        }
    }

    printf("\n\nLa temperatura más alta registrada fue de %.2f\n\nLos dias con la temperadura más alta fueron: ", mayor);

    for(i=0;i<TAM; i++){
        if(dia[i]==mayor){
            printf("el dia %d, ", i+1);
        }
    }

    }