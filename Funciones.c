/*
  Simulacion de una calculadora que pueda sumar, restar, multiplicar, dividir, potencia y factorial
  Paola Montserrat Osorio García
  ICI 1º
  18/10/23
*/

#include <stdio.h>
#include <locale.h>
#include <math.h>

float n1=0, n2=0;

void sum (float a,float b);
void res ();
float mult(float a, float b);
float div ();
void pot (float a, float b);


int main (){

    setlocale( LC_ALL, "" );

    int op=0; 
    float resultado=0;

    do {
    printf("\n\tMENU\n1.Suma\n2.Resta\n3.Multiplicación\n4.División\n5.Potencia\n6.Factorial\n7.Salir\n\nElige una opcion: ");
    n1=0, n2=0, op=0;
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
          sum(n1,n2);
          printf("\n");
          break;
        case 2:
          res();
          printf("\n");
          break;
        case 3:
          resultado = mult(n1,n2);
          printf("\nLa multiplicación de ambos numeros es %.4f", resultado);
          printf("\n");
          break;
        case 4:
          resultado = div();
          printf("\nLa division del primero entre el segundo es %.4f", resultado);
          printf("\n");
          break;
        case 5:
          pot(n1,n2);
          printf("\n");
          break;
        case 6:
          break;
        case 7:
          printf("Salir");
          break;
        default:
          break;
      }  

    } while (op!=7); 

  return 0;
}

void sum(float a, float b)
{
  printf("\nLa suma de ambos numeros es %.4f", a+b);
}

void res()
{
  float a=n1, b=n2;
  printf("\nLa resta del primero menos el segundo es %.4f", a-b);
}

float mult(float a, float b)
{
  float result= a*b;
  return (result);
}

float div()
{
  float a=n1, b=n2, division=a/b;
  return (division);
}

void pot(float a, float b)
{
  printf("\nLa potencia de %.4f a la %.4f, es %.4f", a, b, pow(a,b))
}
