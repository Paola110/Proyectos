#include <ctype.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declarar afuera las matrices nos ayudara a editarlas en varias funciones.
int matriz_claves[10];                 // Arreglo para claves
float matriz_salarios[10];             // Arreglo para salarios
char nombres_concatenados[10][1][35];  // Arreglo para nombres concatenados

int matriz_claves_ordenadas[10];                 // Arreglo para claves ordenadas
float matriz_salarios_ordenados[10];             // Arreglo para salarios ordenados
char nombres_concatenados_ordenados[10][1][35];  // Arreglo para nombres concatenados ordenados

int nRecords = 0;

char allCaps(char s[]) {
  int i, len;
  len = strlen(s);

  for (i = 0; i < len; i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      s[i] = s[i] - 32;
    }
  }
  return s[len];
}

void printArt(int artNum) {
  if (artNum == 1) {
    printf(
        "    _____     ______           _     _                         \n"
        "   /    /|_   | ___ \\         (_)   | |                       \n"
        "  /    //  /| | |/ /__  __ _ _ __| | _ __ ___  ___         \n"
        " (====|/  //  |    // _ \\/ _` | / __| __| '__/ _ \\/ __|      \n"
        "  (=====|/   | |\\ \\  __/ (_| | \\_ \\ || | | (_) \\_ \\  \n"
        " (====|/      \\_| \\_\\___|\\__, |_|___/\\__|_|  \\___/|___/  \n"
        "                          __/ |                                \n"
        "                         |___/                                 \n");
  } else if (artNum == 2) {
    printf(
        ">>----------------------------------------<<\n"
        "||         Seleccione una opción          ||\n"
        ">>----------------------------------------<<\n"
        "|| [1] Mostrar todos los registros        ||\n"
        "|| [2] Agregar un registro nuevo          ||\n"
        "||  *  Eliminar un registro buscando por: ||\n"
        "||     [3] Clave                          ||\n"
        "||     [4] Nombre                         ||\n"
        "||  *  Modificar un registro por:         ||\n"
        "||     [5] Clave                          ||\n"
        "||     [6] Nombre                         ||\n"
        "||     [7] Salario                        ||\n"
        "||  *  Buscar un registro por:            ||\n"
        "||     [8] Nombre                         ||\n"
        "||     [9] Clave                          ||\n"
        "||  *  Ordenar alfabéticamente por:       ||\n"
        "||     [10] Clave                         ||\n"
        "||     [11] Nombre                        ||\n"
        "||     [12] Salario                       ||\n"
        ">>----------------------------------------<<\n"
        "||               [13] SALIR               ||\n"
        ">>----------------------------------------<<\n");
  } else if (artNum == 3) {
    printf(
        "\n"
        "\\    /\\    * ------------- * \n"
        " )  ( ')·  | ¡Hasta luego! | \n"
        "(  /  )    * ------------- * \n"
        " \\(__)|          FIN         \n");
  }
}

int menuChoice() {
  int menu_choice_num;            // var Opción del menú seleccionada
  bool valid_option_num = false;  // var Opción del menú válida o no válida

  while (valid_option_num == false) {
    if (scanf("%d", &menu_choice_num),
        menu_choice_num < 1 || 13 < menu_choice_num || getchar() != '\n') {
      printf("\n*Opción inválida*\n\n");
      while (getchar() != '\n')
        ;  // NO BORRAR - Es para que siga leyendo el input aun que el usuario
           // ingrese un Enter

    } else {
      valid_option_num = true;
    }
  }

  return menu_choice_num;
}

void createDataBase() {
  char matriz_nombres[10][3][35];  // Matriz para nombres y apellidos
  // Variables para crear las matrices
  srand(time(0));                   // Para obtener numeros random
  int nom = 0, ape = 0, punto = 0;  // Variables numeros de nombre y apellido
  float salario = 0;                // Variable para salario
  int i = 0, j=0;

  // Arreglo de los nombres predeterminados de donde se sacaran los random
  char NOMBRESRANDOM[20][32] = {
      "SOFIA",    "MARIA JOSE", "VALENTINA",      "REGINA",       "CAMILA",
      "VALERIA",  "XIMENA",     "MARIA FERNANDA", "VICTORIA",     "RENATA",
      "SANTIAGO", "MATEO",      "SEBASTIAN",      "LEONARDO",     "MATIAS",
      "EMILIANO", "DANIEL",     "GAEL",           "MIGUEL ANGEL", "DIEGO"};
  // Arreglo de los apellidos predeterminados de donde se sacaran los random
  char APELLIDOSRANDOM[25][20] = {
      "GONZALEZ", "DIAZ",        "SANCHEZ",   "GOMEZ",    "GARCIA",
      "FLORES",   "LOPEZ",       "MEDINA",    "VERA",     "VARGAS",
      "CRUZ",     "MALDONADO",   "HERNÁNDEZ", "MARTINEZ", "RODRIGUEZ",
      "SILVANO",  "DE LA TORRE", "DE LUNA",   "LINO",     "CARLOS",
      "ORTIZ",    "DE LA ROSA",  "DE LEÓN",   "RIOS",     "ACOSTA"};

  for (i = 0; i < 10; i++) {
    // Se saca un numero random entre 0 y 20 y se pone en la matriz_nombres el
    // nombre sacado de nombres random Luego se concatena a su respectivo nombre
    // em la matriz nombres_concatenados
    nom = rand() % 20;
    strcpy(matriz_nombres[0][i], NOMBRESRANDOM[nom]);
    strcpy(nombres_concatenados[0][i],
           NOMBRESRANDOM[nom]);  // Concatenamos los nombres, servira para su
                                 // busqueda y mejor administracion
    strcat(nombres_concatenados[0][i], " ");
    // Se saca un numero random entre 0 y 25 y se pone en la matriz_nombres el
    // apellido paterno sacado de apellidos random Luego se concatena a su
    // respectivo nombre em la matriz nombres_concatenados
    ape = rand() % 25;
    strcpy(matriz_nombres[1][i], APELLIDOSRANDOM[ape]);
    strcat(nombres_concatenados[0][i],
           APELLIDOSRANDOM[ape]);  // Concatenamos los nombres, servira para su
                                   // busqueda
    strcat(nombres_concatenados[0][i], " ");
    // Se saca un numero random entre o y 25 y se pone en la matriz_nombres el
    // apellido materno sacado de apellidos random Luego se concatena a su
    // respectivo nombre em la matriz nombres_concatenados
    ape = rand() % 25;
    strcpy(matriz_nombres[2][i], APELLIDOSRANDOM[ape]);
    strcat(nombres_concatenados[0][i],
           matriz_nombres[2][i]);  // Concatenamos los nombres, servira para su
                                   // busqueda

    matriz_claves[i] =
        1000 +
        rand() % 8999;  // Hacemos que la clave sea un numero random entre 1000
                        // y 8999 para que sea un numero de 4 digitos

    punto = 1 + rand() % 17;  // Con esto sacamos un numero random para dividir
                              // y que el salario tenga punto decimal
    salario = 100 + rand() % 1000;  // Sacamos un numero random para el salario
    salario = salario / punto;  // Dividimos el salario entre punto para que sea
                                // un numero con punto decimal
    matriz_salarios[i] = salario;  // Metemos el salario al arreglo de salarios

    nRecords++;  // Incrementamos por 1 el número de registros

    for (j=0; j<nRecords; j++){
		matriz_claves_ordenadas[j]=matriz_claves[j];
		matriz_salarios_ordenados[j] = matriz_salarios[j];
		strcpy(nombres_concatenados_ordenados[0][j], nombres_concatenados[0][j]);
	}
  }
}

void printDataBase() {
  int i = 0, l = 0, s = 0, j = 0;

  printf("\n\n");

  for (i = 0; i < nRecords; i++) {
    printf("\n[%i] %s", i + 1, nombres_concatenados[0][i]);

    l = strlen(nombres_concatenados[0][i]);
    s = 32 - l;

    for (j = 0; j <= s; j++) {
      printf(" ");
    }
    s = 0;
    l = 0;

    printf("| %i | $%.2f \n", matriz_claves[i], matriz_salarios[i]);
  }
  printf("\n\n");
}

void printDataBase_Sorted() {
	
  int i = 0, l = 0, s = 0, j = 0;

  printf("\n\n");

  for (i = 0; i < nRecords; i++) {
    printf("\n[%i] %s", i + 1, nombres_concatenados_ordenados[0][i]);

    l = strlen(nombres_concatenados_ordenados[0][i]);
    s = 32 - l;

    for (j = 0; j <= s; j++) {
      printf(" ");
    }
    s = 0;
    l = 0;

    printf("| %i | $%.2f \n", matriz_claves_ordenadas[i], matriz_salarios_ordenados[i]);
  }
  printf("\n\n");
}

int buscarNombre() {
  int i = 0, cont = 0, low = 0, high = 0;  // Variables para buscar
  char nombre_a_encontrar[50];

  int record_choice;  // var para guardar la selección de los registros
                      // encontrados
  bool valid_record_choice =
      false;             // var para validar que la selección sea un número
  int foundRecords[10];  // arreglo que guarda las ocurrencias encontradas

  for (i = 0; i < 10; i++) {
    foundRecords[i] = -1;
  }

  // Pedir el nombre a buscar, ya sea nombre completo, nombre solo o apellido
  printf(
      "\n[!] Advertencia Si pone un espacio antes o después no se leerá "
      "correctamente (Ej. 'Maria', 'Maria')\nIngrese el nombre de la persona "
      "que busca: ");
  // Usamos fgets para permitir espacios
  // gets(nombre_a_encontrar); // No funciona en UNIX (Mac y linux)
  fgets(nombre_a_encontrar, 50, stdin);
  // Pasamos todo a mayusculas para hacer mas facil buscar
  // strupr(nombre_a_encontrar); // strupr sólo funciona en windows, por eso la
  // cambié :/

  nombre_a_encontrar[strlen(nombre_a_encontrar) - 1] = '\0';
  allCaps(nombre_a_encontrar);

  for (i = 0; i < nRecords; i++) {
    // strstr nos ayuda a buscar una cadena dentro de otra, ponemos los
    // nombres concatenados y luego el nombre que buscamos

    if (strstr(nombres_concatenados[0][i], nombre_a_encontrar) != NULL) {
      // Mostramos las personas o la persona con ese nombre en el registro asi
      // como su clave y salario
      printf("\n[%i] %s", i + 1, nombres_concatenados[0][i]);
      foundRecords[cont] = i;
      cont++;
      if (cont == 1) {
        low = i;
      }
    }
  }
  high = low + cont;

  if (cont > 0) {
    printf("\nNº de resultados: %i\n", cont);
    if (cont == 1) {
      printf("\n[%i] %s | % i | $ % .2f \n ", low + 1,
             nombres_concatenados[0][low], matriz_claves[low],
             matriz_salarios[low]);
      return low;
    }
    if (cont >= 2) {
      int foundRecordsLen = sizeof(foundRecords) / sizeof(foundRecords[0]);

      printf("\nSeleccione el registro que busca:\n");

      valid_record_choice = false;
      while (valid_record_choice == false) {
        if (scanf("%i", &record_choice),
            isdigit(record_choice) != 0 || getchar() != '\n') {
          while (getchar() != '\n')
            ;

        } else {
          for (i = 0; i < foundRecordsLen; i++) {
            if (record_choice == (foundRecords[i] + 1)) {
              valid_record_choice = true;
            }
          }

          if (valid_record_choice == false) {
            printf("\n*Opción inválida1*\n");
          }
        }
      }

      printf("\n[%i] %s | % i | $ % .2f \n ", record_choice,
             nombres_concatenados[0][record_choice - 1],
             matriz_claves[record_choice - 1],
             matriz_salarios[record_choice - 1]);

      return (record_choice - 1);
    }
  } else {
    // Si no se encontro ninguna persona mostramos que no hay nadie con ese
    // nombre
    printf("No se encontro ninguna coincidencia");
    return -1;
  }

  return 0;
}

int buscarClave() {
  int i = 0, cont = 0;        // Variables que usaremos para buscar
  int clave_a_encontrar = 0;  // Numero de clave a buscar

  printf("\nIngrese la clave de la persona que busca (Ej. '1566', '1908')\n");
  scanf("%d", &clave_a_encontrar);  // El usuario ingresa el numero a buscar

  for (i = 0; i < nRecords; i++) {
    if (clave_a_encontrar == matriz_claves[i]) {
      cont++;
      if (cont == 1) {
        printf("\nLa persona con esta clave es:\n");
      }
      // Si se encuentra alguien con esa clave mostramos su registro (nombre,
      // clave y salario)
      printf("\n[%i] %s | %4i | $%.2f\n", i + 1, nombres_concatenados[0][i],
             matriz_claves[i], matriz_salarios[i]);

      return i;
    }
    if (cont == 0 && i == nRecords - 1) {
      // Si no se encuentra a nadie con esa clave, lo mostramos
      printf("\nNo se encontro ninguna coincidencia\n\n");
      return -1;
    }
  }

  return 0;
}

int buscarSalario() {
  int i = 0, cont = 0;            // Variables que usaremos para buscar
  float salario_a_encontrar = 0;  // Número de clave a buscar

  printf(
      "\nIngrese el salario de la persona que busca (Ej. '419.00', "
      "'55.80'):\n$");
  scanf("%f", &salario_a_encontrar);  // El usuario ingresa el numero a buscar

  for (i = 0; i < nRecords; i++) {
    if (salario_a_encontrar == matriz_salarios[i]) {
      cont++;
      if (cont == 1) {
        printf("\nLa persona con este salario es:\n");
      }
      // Si se encuentra alguien con ese salario mostramos su registro (nombre,
      // clave y salario)
      printf("\n[%i] %s | %4i | $%.2f\n", i + 1, nombres_concatenados[0][i],
             matriz_claves[i], matriz_salarios[i]);

      return i;
    }
    if (cont == 0 && i == nRecords - 1) {
      // Si no se encuentra a nadie con ese salario, lo mostramos
      printf("\nNo se encontro ninguna coincidencia\n\n");
      return -1;
    }
  }

  return 0;
}

void borrarRegistro(int num) {
  int i = 0;
  if (num <= nRecords && num >= 0) {
    for (i = 0; i <= (nRecords - 1); i++) {
      if (i >= num) {
        strcpy(nombres_concatenados[0][i], nombres_concatenados[0][i + 1]);
        matriz_claves[i] = matriz_claves[i + 1];
        matriz_salarios[i] = matriz_salarios[i + 1];
      } else if (i == nRecords) {
        strcpy(nombres_concatenados[0][i], "");
        matriz_claves[i] = 0;
        matriz_salarios[i] = 0;
      }
    }
    printf("\nRegistro eliminado\n");
    nRecords--;
    printDataBase();
  } else {
    // printf("\nNo existe el registro solicitado\n");
  }
}

void nuevoRegistro() {
  bool valid_user_input = false;

  char newName[256];
  int newID = 0;
  float newSalary = 0;

  printf("%i", nRecords);

  if (nRecords < 10) {
    printf("\n| Nuevo Registro |\n");
    printf("Nombre: ");
    scanf("%s", newName);
    allCaps(newName);

    bool v_num_input;
    int num1, i;
    int opciones[3] = {4, 8, 9};
    int idsLen = sizeof(matriz_claves) / sizeof(matriz_claves[0]);

    v_num_input = false;
    while (v_num_input == false) {
      printf("Clave: ");
      if (scanf("%i", &newID),
          newID < 1000 || 9999 < newID || getchar() != '\n') {
        while (getchar() != '\n')
          ;
        printf("*Clave inválida*\n\n");

      } else {
        for (i = 0; i < idsLen; i++) {
          if (newID == matriz_claves[i]) {
            printf("*Este registro ya existe*\n\n");
            v_num_input = false;
          } else {
            v_num_input = true;
          }
        }
      }
    }

    valid_user_input = false;
    while (valid_user_input == false) {
      printf("Salario: $");

      if (scanf("%f", &newSalary), newSalary < 0 || getchar() != '\n') {
        printf("\nSalario inválido\n");
        while (getchar() != '\n')
          ;

      } else {
        valid_user_input = true;
      }
    }

    strcpy(nombres_concatenados[0][nRecords], newName);
    matriz_claves[nRecords] = newID;
    matriz_salarios[nRecords] = newSalary;

    nRecords++;

    printDataBase();
  } else {
    printf(
        "\n[!] Almacenamiento lleno\nAdministre los registros para agregar "
        "nuevos datos");
  }
}

void modificarClave() {
  int id_edit = -1, newID;

  while (id_edit == -1) {
    id_edit = buscarClave();
  }

  bool v_num_input;
  int num1, i;
  int opciones[3] = {4, 8, 9};
  int idsLen = sizeof(matriz_claves) / sizeof(matriz_claves[0]);

  v_num_input = false;
  while (v_num_input == false) {
    printf("Nueva clave: ");
    if (scanf("%i", &newID),
        newID < 1000 || 9999 < newID || getchar() != '\n') {
      while (getchar() != '\n')
        ;
      printf("*Clave inválida*\n\n");

    } else {
      for (i = 0; i < idsLen; i++) {
        if (newID == matriz_claves[i]) {
          printf("*Este registro ya existe*\n\n");
          v_num_input = false;
        } else {
          v_num_input = true;
        }
      }
    }
  }

  matriz_claves[id_edit] = newID;

  printDataBase();
}

void modificarNombre() {
  int name_edit = -1;
  char newName[256];

  while (name_edit == -1) {
    name_edit = buscarNombre();
  }

  printf("Nuevo nombre: ");
  scanf("%s", newName);
  allCaps(newName);

  strcpy(nombres_concatenados[0][name_edit], newName);

  printDataBase();
}

void modificarSalario() {
  bool valid_user_input = false;
  int salary_edit = -1;
  float newSalary;

  while (salary_edit == -1) {
    salary_edit = buscarSalario();
  }

  valid_user_input = false;
  while (valid_user_input == false) {
    printf("Nuevo salario: $");

    if (scanf("%f", &newSalary), newSalary < 0 || getchar() != '\n') {
      printf("\nSalario inválido\n");
      while (getchar() != '\n')
        ;

    } else {
      valid_user_input = true;
    }
  }

  matriz_salarios[salary_edit] = newSalary;

  printDataBase();
}

void ordenarClave(){
	//Haremos una funcion sort para ordenar las claves
	int i=0, j=0, l=0, s=0;
	int clave_mover[10]; 		//Variable para guardar la clave que moveremos
	float salario_mover=0; //Variable para guardar el salario que moveremos
	char nombre_mover[35]; // Variable para guardar el nombre que moveremos
	
	
	for (i=0; i<nRecords-1; i++){
		for (j=0; j<nRecords-2; j++){
			if (matriz_claves_ordenadas[j]>matriz_claves_ordenadas[j+1]){
				clave_mover[j] = matriz_claves_ordenadas[j];					//Movemos las claves
				matriz_claves_ordenadas[j]=matriz_claves_ordenadas[j+1];
				matriz_claves_ordenadas[j+1]=clave_mover[j];
				
				salario_mover=matriz_salarios_ordenados[j];
				matriz_salarios_ordenados[j] = matriz_salarios_ordenados[j+1]; 	//Movemos los salarios
				matriz_salarios_ordenados[j+1] = salario_mover;
				
				nombre_mover[strlen(nombre_mover) - 1] = '\0';
				strcpy(nombre_mover, nombres_concatenados_ordenados[j][1]);		//Movemos los nombres
				nombres_concatenados_ordenados[j][1][strlen(nombres_concatenados_ordenados[j][1]) - 1] = '\0';
				strcpy(nombres_concatenados_ordenados[j][1], nombres_concatenados_ordenados[j+1][1]);
				nombres_concatenados_ordenados[j+1][1][strlen(nombres_concatenados_ordenados[j+1][1]) - 1] = '\0';
				strcpy(nombres_concatenados_ordenados[j+1][1], nombre_mover);
				 
			}
		}	
	
	}
	
	printf("\n Contactos ordenados por clave\n");
	printDataBase_Sorted();
}

void ordenarNombre(){
	//Haremos una funcion sort para ordenar las claves
	int i=0, j=0, l=0, s=0;
	int clave_mover[10]; 		//Variable para guardar la clave que moveremos
	float salario_mover=0; //Variable para guardar el salario que moveremos
	char nombre_mover[35]; // Variable para guardar el nombre que moveremos
	int matriz_claves_ordenadas1[10];                 // Arreglo para claves ordenadas
  	float matriz_salarios_ordenados1[10];             // Arreglo para salarios ordenados
  	char nombres_concatenados_ordenados1[10][1][35];  // Arreglo para nombres concatenados ordenados
  
  for (j=0; j<nRecords; j++){
		matriz_claves_ordenadas1[j]=matriz_claves_ordenadas[j];
		matriz_salarios_ordenados1[j] = matriz_salarios_ordenados[j];
		strcpy(nombres_concatenados_ordenados1[0][j], nombres_concatenados_ordenados[0][j]);
	}
	
	for (i=0; i<nRecords-1; i++){
		for (j=0; j<nRecords-2; j++){
			if (strcmp(nombres_concatenados_ordenados1[j+1][1],nombres_concatenados_ordenados1[j][1])>0){
				clave_mover[j] = matriz_claves_ordenadas1[j];					//Movemos las claves
				matriz_claves_ordenadas1[j]=matriz_claves_ordenadas1[j+1];
				matriz_claves_ordenadas1[j+1]=clave_mover[j];
				
				salario_mover=matriz_salarios_ordenados1[j];
				matriz_salarios_ordenados1[j] = matriz_salarios_ordenados1[j+1]; 	//Movemos los salarios
				matriz_salarios_ordenados1[j+1] = salario_mover;
				
				nombre_mover[strlen(nombre_mover) - 1] = '\0';
				strcpy(nombre_mover, nombres_concatenados_ordenados1[j][1]);		//Movemos los nombres
				nombres_concatenados_ordenados1[j][1][strlen(nombres_concatenados_ordenados1[j][1]) - 1] = '\0';
				strcpy(nombres_concatenados_ordenados1[j][1], nombres_concatenados_ordenados1[j+1][1]);
				nombres_concatenados_ordenados1[j+1][1][strlen(nombres_concatenados_ordenados1[j+1][1]) - 1] = '\0';
				strcpy(nombres_concatenados_ordenados1[j+1][1], nombre_mover);
				printf("\n%s\n"), nombres_concatenados_ordenados1	[j][1];
			}
		}

	}
	
	printf("\n Contactos ordenados por clave\n");
	printDataBase_Sorted();
}

void ordenarSalario(){
	//Haremos una funcion sort para ordenar las claves
	int i=0, j=0, l=0, s=0;
	int clave_mover[10]; 		//Variable para guardar la clave que moveremos
	float salario_mover=0; //Variable para guardar el salario que moveremos
	char nombre_mover[35]; // Variable para guardar el nombre que moveremos
	
	
	for (i=0; i<nRecords-1; i++){
		for (j=0; j<nRecords-2; j++){
			if (matriz_salarios_ordenados[j]>matriz_salarios_ordenados[j+1]){
				clave_mover[j] = matriz_claves_ordenadas[j];					//Movemos las claves
				matriz_claves_ordenadas[j]=matriz_claves_ordenadas[j+1];
				matriz_claves_ordenadas[j+1]=clave_mover[j];
				
				salario_mover=matriz_salarios_ordenados[j];
				matriz_salarios_ordenados[j] = matriz_salarios_ordenados[j+1]; 	//Movemos los salarios
				matriz_salarios_ordenados[j+1] = salario_mover;
				
				nombre_mover[strlen(nombre_mover) - 1] = '\0';
				strcpy(nombre_mover, nombres_concatenados_ordenados[j][1]);		//Movemos los nombres
				nombres_concatenados_ordenados[j][1][strlen(nombres_concatenados_ordenados[j][1]) - 1] = '\0';
				strcpy(nombres_concatenados_ordenados[j][1], nombres_concatenados_ordenados[j+1][1]);
				nombres_concatenados_ordenados[j+1][1][strlen(nombres_concatenados_ordenados[j+1][1]) - 1] = '\0';
				strcpy(nombres_concatenados_ordenados[j+1][1], nombre_mover);
				 
			}
		}	
	
	}
	
	printf("\n Contactos ordenados por clave\n");
	printDataBase_Sorted();
}


int main() {
  int i = 0;

  bool run = true;  // var Correr programa
  int choice = 0;   // var Selección del usuario
  int cDB = 0;
  do {
    createDataBase();
    cDB++;
  } while (cDB == 0);
  printArt(1);
  while (run == true) {
    printArt(2);
    choice = 0;
    choice = menuChoice();
    switch (choice) {
      case 1:
        printf("\n[1] Mostrar todos los registros\n");
        printDataBase();
        break;
      case 2:
        printf("\n[2] Agregar un registro nuevo\n");
        nuevoRegistro();
        break;
      case 3:
        printf("\n[3] Eliminar un registro buscando por: Clave\n");
        borrarRegistro(buscarClave());
        break;
      case 4:
        printf("\n[4] Eliminar un registro buscando por: Nombre\n");
        borrarRegistro(buscarNombre());
        break;
      case 5:
        printf("\n[5] Modificar un registro por: Clave\n");
        modificarClave();
        break;
      case 6:
        printf("\n[6] Modificar un registro por: Nombre\n");
        modificarNombre();
        break;
      case 7:
        printf("\n[7] Modificar un registro por: Salario\n");
        modificarSalario();
        break;
      case 8:
        printf("\n[8] Buscar un registro: Nombre\n");
        buscarNombre();
        break;
      case 9:
        printf("\n[9] Buscar un registro: Clave\n");
        buscarClave();
        break;
      case 10:
        printf("\n[10] Ordenar alfabéticamente por: Clave\n");
        ordenarClave();
        break;
      case 11:
        printf("\n[11] Ordenar alfabéticamente por: Nombre\n");
        ordenarNombre();
        break;
      case 12:
        printf("\n[12] Ordenar alfabéticamente por: Salario\n");
        ordenarSalario();
        break;
      case 13:
        printArt(3);
        run = false;
        break;
    }
  }

  return 0;
}