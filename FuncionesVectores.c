#include <stdio.h>
#include <locale.h>


void creavector(int arr[]);
void mymn(int arr[]);

int main(){
	
    setlocale(LC_ALL, "spanish");
		
	int arr[5], arr2[5], i=0, men=0, may=0, maymen[2];
	
	printf("\nBienvenido, entremos a la funcion crear vector\n");
	creavector(arr);
	mymn(arr);
	return 0;
}

void creavector(int arr[]){
	int i;

	printf("\nIngrese los 5 números del vector separados por enter o espacios\n");
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
		arr[i]<men ? men=arr[i];
		arr[i]>may ? may=arr[i];
	}

	printf("De estos números, el menor es %d y el mayor es %d", men, may);
}