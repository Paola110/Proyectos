/*
  Simulacion de una calculadora que pueda sumar, restar, multiplicar, dividir, potencia y factorial
  Paola Montserrat Osorio García
  ICI 1º
  18/10/23
*/

#include <stdio.h>
#include <locale.h>


int main (){

    setlocale( LC_ALL, "" );

    int op=0;
    float n1=0, n2=0;

    printf("\n\tMENU\n1.Suma\n2.Resta\n3.Multiplicación\n4.División\n5.Potencia\n6.Factorial\n7.Salir\n\nElige una opcion: ");
 
    do{
      scanf("%i", &op);
      if (op<1 || op>7){
        printf("\nError: debe ser una opcion entre 1 y 7\n\nElige una opcion: ");
      }
      if (op>0 && op<6){
        printf("\n\nDame el primer numero: ");
        scanf("%f",&n1);
        printf("\n\nDame el segundo numero: ");
        scanf("%f",&n2);
      } else if (op==6){
        printf("\n\nDame el numero a factrizar: ");
        scanf("%f",&n1);
      }
    }while(op<1 || op>7);
 
    switch (op){
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        break;
      case 7:
        printf("Salir");
        exit(0);
      default:
        break;
    }  
  return 0;
}