#include <stdio.h>
#include <locale.h>


void creavector(int arr[]){
	int i;

	printf("\nIngrese los 5 números del vector separados por enter o espacios\n");
	for (i=0; i<5; i++){
		scanf("%d", &arr[i]);
	}
}

int mayormenor(int arr[]){
	int i, men=0, may=0;
	
	printf("\nBuscaremos número mayor y menor del vector\n");
	
    for (i=0; i<5; i++){
		if (i=0){
			men=arr[i];
			may=arr[i];
		}
		if (men<arr[i]){
			men=arr[i];
		}
		if (may>arr[i]){
			may=arr[i];
		}
	}
	
}

int main(){
	
    setlocale(LC_ALL, "spanish");
		
	int arr[5], i=0, men=0, may=0;
	
	printf("\nBienvenido, entremos a la funcion crear vector\n");
	creavector(arr);

    for (i=0; i<5; i++){
        printf("%d  ", arr[i]);
    }
	printf("\nAhora entremos a la funcion mayor menor\n");
	mayormenor(arr);
    printf("\nEl menor es %d y el mayor es %d\n", men, may);
	return 0;
}
 



