/*
	Ejercicio de funciones con vectores y matrices
	Osorio Garci Paola Montserrat
	Alan Torres Ruiz
	ICI 1º
	10/11/2023
*/

#include <stdio.h>

#define COL 3

void cantiaimpu(float impu[]);
void impuapli(float impu[], float apli[][COL]);

int main(){	
		
	float impu[3], apli[3][3]; 
	int i=0;
	
	printf("\nBienvenido, entremos a la funci%cn para introducir sus cantidades\n", 162);
	cantiaimpu(impu);
	printf("\nSus cantidades con impuesto del 5 porciento aplicado son:\n\n");
	for (i=0; i<3; i++){
		printf(" %.3f ", impu[i]*1.05);
	}

	printf("\n");
	printf("\nAhora entremos a la funci%cn para ingresar los intereses y aplicarlos\n", 162);
	impuapli(impu, apli);
	return 0;
}

void cantiaimpu(float impu[]){
	int i;

	printf("\nIngrese los 3 n%cmeros a aplicar 5 porciento de interes separados por enter o espacios\n", 163);
	for (i=0; i<3; i++){
		scanf("%f", &impu[i]);
	}
	return;
}

void impuapli(float impu[], float apli[][COL]){
	int i=0, j=0;

	for (i=0; i<3; i++){
			apli[0][i]=impu[i];
			printf("\nIngresa el interes a aplicar a la cantidad #%d, ejemplo 5 porciento: ", i+1);
			scanf("%f", &apli[1][i]);
			apli[2][i]= apli[0][i]+(apli[0][i]*(apli[1][i]/100));
	}

	for (i=0; i<3; i++){
		if (i==0){
			printf("\n\n.Sus cantidades son: ");
		} else if (i==1){
			printf ("\n\nLos intereses a aplicar son: ");
		} else if (i==2){
			printf ("\n\nLas cantidades con interes aplicado son: ");
		}
		for (j=0; j<3; j++){
			printf(" %.3f ", apli[i][j]);
		}
	}

}