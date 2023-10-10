/*
  Menu con 8 ejercicios con matrices
    1. De una matriz de 4*4 con numeros enteros imprima la matriz y la suma de todos los elementos de la matriz.
    2. De una matriz de 4*4 con numeros enteros imprima la matriz y la suma de los elementos por fila.
    3. De una matriz de 4*4 con numeros enteros imprima la matriz y la suma de los elementos por columna.
    4. Multiplicar una matriz n*n por un escalar, dejando el resultado en otra matriz, al final imprimir las dos matrices y el escalar
    5. Suma de dos matrices cuadradas, dejando el resultado en una tercera matriz e imprimir las tres matrices 
    6. Ordenar una matriz de menor a mayor y mostrar en pantalla la matriz original, la matriz ordenada de menor a mayor
    7. Ordenar una matriz de mayor a menor y mostrar en pantalla la matriz original, la matriz ordenada de mayor a menor    
    8. Crear una matriz identidad y mostrarla en la pantalla
  Paola Montserrat Osorio García
  ICI 1º
  09/10/23
*/

#include <stdio.h>

int main (){

  int opcion=0, numero=0, n=0, m=0, escalar=0,x=0, y=0, i=0, j=0, todos=0, sf=0, fila[4]={0, 0, 0, 0}, sc=0, columna[4]= {0, 0, 0, 0};
  int matriz4[4][4];
  
  do {
  printf("\n\n\t\tMenu");
  printf("\n          Elige una opcion");
  printf("\n1. Suma de los elementos de una matriz");
  printf("\n2. Suma de los elementos de una matriz por fila");
  printf("\n3. Suma de los elementos de una matriz por columna");
  printf("\n4. Multiplicar una matriz por un escalar (numero al azar)");
  printf("\n5. Suma de dos matrices cuadradas");
  printf("\n6. Ordenar una matriz de menor a mayor");
  printf("\n7. Ordenar una matriz de mayor a menor");
  printf("\n8. Crear una matriz identidad");
  printf("\n9. Salir\n");
  
  scanf("%d", &opcion);
  
  while(opcion<1 || opcion>9){
    printf("\nError: Debes darme un numero entre 1 y 9\n");
      scanf("%d", &opcion);
  }
  
  switch (opcion){
    case 1:
    case 2:
    case 3:
        for (i=0; i<4; i++){
          for (j=0; j<4; j++){
            matriz4[i][j] = 0;
          }
        }
        for(i=0; i<4; i++){
        for (j=0; j<4; j++){
        printf("Dame el numero entero de la posicion %d , %d\n", i+1, j+1);
        scanf("%d", &matriz4[i][j]);
        todos= todos + matriz4[i][j];
        fila[i] = fila[i]+ matriz4[i][j];
        columna[j] = columna[j]+ matriz4[i][j];
        }
        }

        printf("\n");  
        for(i=0; i<4; i++){
        for (j=0; j<4; j++){
          printf("%d ", matriz4[i][j]);
        }
        printf("\n");
        }
        printf("\n");
        if(opcion == 1){
          printf("\nLa suma de todos los numeros es: %d\n", todos);
          todos=0;
        } else if (opcion == 2){
          for (i=0; i<4; i++){
            printf("\nLa suma de los numeros de la fila %d es %d ", i+1, fila[i]);
          }
        } else if ( opcion == 3){
          for(i=0; i<4; i++){
            printf("\nLa suma de los numeros de la columna %d es %d ", i+1, columna[i]);
          }
        }
        for (i=0; i<4; i++){
          fila[i]=0;
          columna[i]=0;
        }
      break;   
  case 4:
  case 6:
  case 7:
  case 8:
        }
        do{
        printf("\nDame el numero entero de filas y el numero entero de columnas de tu matriz separadas por enter o espacio: \n");
        scanf("%d %d", &n, &m);
        if (n<0 || m<0){
          printf("Error: No pueden ser filas o columnas negativas.\n");
        }
        }while (n<0 || m<0);
        int matriz[n][m], matriz2[n][m];
        for (i=0; i<4; i++){
          for (j=0; j<4; j++){
            matriz[i][j] = 0;
            matriz2[i][j]=0;
          }
        if(opcion==4){
        printf("\nDame el numero por el que quiere multipliacar (escalar): \n");
        scanf("%d", &escalar);
        for(i=0; i<n; i++){
        for (j=0; j<m; j++){
        printf("Dame el numero entero de la posicion %d , %d\n", i+1, j+1);
        scanf("%d", &matriz[i][j]);
        matriz2[i][j] = matriz[i][j] * escalar;
        }
        }
        for (i=0; i<n; i++){
          for (j=0; j<m; j++){
            printf(" %d  ", matriz[i][j]);
          }
          printf("\n");
        }
        printf("\n");
        for (i=0; i<n; i++){
          for (j=0; j<m; j++){
            printf(" %d  ", matriz2[i][j]);
          }
          printf("\n");
        }
        printf("\n");
        printf("El escalar era %d", escalar);
        }
        if (opcion==6 || opcion==7){
        for(i=0; i<n; i++){
        for (j=0; j<m; j++){
        printf("Dame el numero entero de la posicion %d , %d\n", i+1, j+1);
        scanf("%d", &matriz[i][j]);
        matriz2[i][j]= matriz[i][j];
        }
        }
          for (i=0; i<n; i++){
            for (j=0; j<m; j++){
              for (x=0;i<n; i++){
                for(y=0; j<m; j++){
                    if (matriz2[x][y]< matriz2[i][j]){
                    numero = matriz2[i][j];
                    matriz2[i][j] = matriz2[x][y];
                    matriz2[x][y]= numero;
                    }
                }
              }
            }
          }
          for (i=0; i<n; i++){
          for (j=0; j<m; j++){
            printf(" %d  ", matriz[i][j]);
          }
          printf("\n");
          }
          printf("\n");
          for (i=0; i<n; i++){
          for (j=0; j<m; j++){
            printf(" %d  ", matriz2[i][j]);
          }
          printf("\n");
          }
        }
    break;
    }
    } while (opcion!=9);
  return 0;
}