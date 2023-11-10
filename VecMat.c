#include <stdio.h>


void creavector(int arr[]);
void mymn(int arr[]);

int main(){	
		
	int arr[5], arr2[5], i=0, men=0, may=0, maymen[2];
	
	printf("\nBienvenido, entremos a la funci%cn crear vector\n", 162);
	creavector(arr);
	printf("\nSu vector es\n\n");
	for (i=0; i<5; i++){
		printf(" %d ", arr[i]);
	}
	printf("\n");
	printf("\nAhora entremos a la funci%cn para buscar el mayor y el menor de los valores\n", 162);
	mymn(arr);
	return 0;
}

void creavector(int arr[]){
	int i;

	printf("\nIngrese los 5 n%cmeros del vector separados por enter o espacios\n", 163);
	for (i=0; i<5; i++){
		scanf("%d", &arr[i]);
	}
	return;
}

void mymn(int arr[]){
	int i, may, men;

	men=arr[0];
	may=arr[0];

	for (i=0; i<5; i++){
		arr[i]<men ? men=arr[i] : men;
		arr[i]>may ? may=arr[i] : may;
	}

	printf("\nDe estos n%cmeros, el menor es %d y el mayor es %d\n",163, men, may);
}