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

  int opcion, opcion2, n, i=0, j=0, todos=0, sf=0, fila[4]={0, 0, 0, 0}, sc=0, columna[4]= {0, 0, 0, 0};
  int matriz4[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}; 
  
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
  /*
  if (opcion== 1 || opcion==2 || opcion==3){
    opcion2=opcion;
    opcion=1;
  }
  */
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
        if(opcion2 == 1){
          printf("\nLa suma de todos los numeros es: %d\n", todos);
        } else if (opcion2 == 2){
          for (i=0; i<4; i++){
            printf("\nLa suma de los numeros de la fila %d es %d ", i+1, fila[i]);
          }
        } else if ( opcion2== 3){
          for(i=0; i<4; i++){
            printf("\nLa suma de los numeros de la columna %d es %d ", i+1, columna[i]);
          }
        }
      break;   
  }  
  
  } while (opcion!=9);
  return 0;
}