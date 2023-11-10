#include <stdio.h>
#include <locale.h>


void creavector(int arr[]){
	int i;

	printf("\nIngrese los 5 números del vector separados por enter o espacios\n");
	for (i=0; i<5; i++){
		scanf("%d", &arr[i]);
	}
	return;
}

void mayormenor(int arr2[]){
	int i, men=0, may=0;

	for (i=0; i<5; i++){
		printf("%d  ", arr2[i]);
	}

	printf("\nBuscaremos número mayor y menor del vector\n");
	
    for (i=0; i<5; i++){
		if (i=0){
			men=arr2[i];
			may=arr2[i];
		}
		if (men<arr2[i]&& i=!0){
			men=arr2[i];
		}
		if (may>arr2[i]&& i=!0){
			may=arr2[i];
		}
	}
	return;
}

int main(){
	
    setlocale(LC_ALL, "spanish");
		
	int arr[5], arr2[5], i=0, men=0, may=0;
	
	printf("\nBienvenido, entremos a la funcion crear vector\n");
	creavector(arr);
	
    for (i=0; i<5; i++){
        arr2[i]=arr[i];
    }

	printf("\nAhora entremos a la funcion mayor menor\n");
	mayormenor(arr2);
	return 0;
}
 



