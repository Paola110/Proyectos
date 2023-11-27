#include <cctype>
#include <cstdlib>
#include <iostream>
#include <locale.h>
#include <stdbool.h>
#include <string>
#include <windows.h>
using namespace std;

// { Compilación Condicional }

// -> Limpiar Pantalla

void clearScreen() {        // Limpia la pantalla según el SO
    #ifdef _WIN32           // Para Windows
        system("cls");
    #else                   // Para Linux
        system("clear");
    #endif
}


// { Constantes y Colores }

// -> Colores

const char *const red = "\033[1;31m";           // Rojo
const char *const white = "\033[0m";            // Blanco
const char *const cyan = "\033[1;36m";          // Cyan
const char *const green = "\033[0;32m";         // Verde
const char *const lgreen = "\033[1;32m";        // Verde claro


// -> Constantes

// { Declaración de variables }

int i, j, k;
string opcionCalc[] = {"~","p","q","r","s","^","v","(",")","-->","<->","Ax ","Ex "};
string inputProposicion[25];

// { Declaración de funciones }

bool digit(const string &str);
char *Upper(char *str);
void gotoxy(int x,int y);
int ingresarNumCalc(int minVal, int maxVal);
string crearComplementoLogico(int i, int botonCorrecto, string accion);
void imprimirProposicion();
void asciiArt(int artNum);

// { Funciones }

int main() {
  clearScreen();
  /* Código Dummy
  cout << "¡Hola Muñoz!" << endl;
  cout << "Ingrese un número: ";
  string numero;
  cin >> numero;
  if (digit(numero)) {
    cout << "Es un número" << endl;
  } else {
    cout << "No es un número" << endl;
  }
  char palabra[30];
  cin >> palabra;
  Upper(palabra);
  cout << "La palabra es: " << palabra;
  */

  //Menu calculadora de proposiciones lógicas

  int boton;
  bool usingCalc = true;
  
  setlocale(LC_ALL, "");
  asciiArt(1);

  while(usingCalc){
    boton = ingresarNumCalc(0,15);
    
    switch(boton){
        //Botón de negación
        case 0:
          inputProposicion[i] = crearComplementoLogico(i, boton, "NEGACION (~)");
          i++;
          break;	
        //Predicados, por ahora los ignoramos
        case 11:
          inputProposicion[i] = crearComplementoLogico(i, boton, "PARA TODO x (Ax)");
          i++;
          break;
        case 12:
          inputProposicion[i] = crearComplementoLogico(i, boton, "ALGUNO EN x (Ex)");
          i++;
          break;
        //Botones de eliminar
        case 13:
          if(i>0){
            inputProposicion[i-1] = '\0'; //Elimina el ultimo caracter ingresado por el usuario
            i--;
          }
          break;
        case 14:
          gotoxy(5,11);
          cout << "                            ";
          fill_n(inputProposicion, 25, '\0');
          i=0;
          break;
        //Evaluar funcion, salimos del ciclo
        case 15:
          usingCalc = false;
        break;
        default:
          inputProposicion[i] = opcionCalc[boton];
          i++;
          break;
      }
      imprimirProposicion();
  }
}

bool digit(const string &str) {    // Se recibe un string
  for (char c : str) {             // Ciclo for en cada caracter del string
    if (!isdigit(c) && c != '.') { // Verifica si *no* es dígito
      return false;                // No es numérico
    }
  }
  return true; // Es numérico
}

char *Upper(char *str) {
  int i;
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] = (int)str[i] - 32;
  }
  return (str);
}
//ALAN :)

void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}

int ingresarNumCalc(int minVal, int maxVal){
  string comprobarNum;
  int numCorrecto;
  while(1){
    do{
      gotoxy(72,17);
      cout << "                            ";
      gotoxy(72,17);
    cin >> comprobarNum;
  }while(digit(comprobarNum) == false);
  numCorrecto = stoi(comprobarNum);
    if( numCorrecto > maxVal | numCorrecto < minVal ){
      gotoxy(42,18);
      cout << "OPCION INVALIDA";
    }else{
      gotoxy(42,18);
      cout << "                            ";
      break;
    }
  }
  return numCorrecto;
}

void imprimirProposicion(){
  gotoxy(5,11);
  cout << "                            ";
  gotoxy(5,11);
  int i;
  for(i=0;i<25;i++){
    cout << inputProposicion[i];
  }
}

string crearComplementoLogico(int i, int botonCorrecto, string accion){
  int variableComplemento;
  string predicado;
  gotoxy(42,16);
  cout << "¿Qué variable quieres concatenar con " << accion << "?";
  variableComplemento = ingresarNumCalc(1,4);
  gotoxy(42,16);
  cout << "                                                      ";
  if(botonCorrecto==0){
    return opcionCalc[0]+opcionCalc[variableComplemento];
  }else{
    return opcionCalc[botonCorrecto]+opcionCalc[variableComplemento]+"(x)";
  }
}

void asciiArt(int artNum){
  if (artNum==1){
    cout << "    __             _                                             _      _                   _ \n"
      "   / /  ___   __ _(_) ___ __ _   _ __  _ __ ___  _ __   ___  ___(_) ___(_) ___  _ __   __ _| |\n"
      "  / /  / _ \\ / _` | |/ __/ _` | | '_ \\| '__/ _ \\| '_ \\ / _ \\/ __| |/ __| |/ _ \\| '_ \\ / _` | |\n"
      " / /__| (_) | (_| | | (_| (_| | | |_) | | | (_) | |_) | (_) \\__ \\ | (__| | (_) | | | | (_| | |\n"
      " \\____/\\___/ \\__, |_|\\___\\__,_| | .__/|_|  \\___/| .__/ \\___/|___/_|\\___|_|\\___/|_| |_|\\__,_|_|\n"
      "             |___/              |_|             |_|                                           \n\n"
      "***************************************************************************************************\n"
      "  ___________________________________	* BIENVENIDO A LA CALCULADORA DE PREPOCISIONES LOGICAS! Üü\n"
      " |  _______________________________  |	* \n"
      " | |                               | |	* \n"
      " | |                               | |	* ACERCA DE:\n"
      " | |_______________________________| |	* Este programa interpreta preposiciones lógicas y retorna\n"
      " |  ___________ ___________   _____  |	* su tabla de verdad. Ingresa el caracter con el número\n"
      " | |0    |13   |14         | |15   | |	* correspondiente de la calculadora, uno a la vez.\n"
      " | |  ~  |  C  |    DEL    | |     | |	*\n"
      " | |_____|_____|___________| |     | |	*\n"
      " | |1    |2    |3    |4    | |     | |	* Ingresa el número que desees:\n"
      " | |  p  |  q  |  r  |  s  | |     | |	*\n"
      " | |_____|_____|_____|_____| |  =  | |	*\n"
      " | |5    |6    |7    |8    | |     | |	*\n"
      " | |  ^  |  v  |  (  |  )  | |     | |	*\n"
      " | |_____|_____|_____|_____| |     | |	*\n"
      " | |9    |10   |11   |12   | |     | |	*\n"
      " | | --> | <-> |  A  |  E  | |     | |	*\n"
      " | |_____|_____|_____|_____| |_____| |	*\n"
      " |___________________________________|	*\n";
  }
}
