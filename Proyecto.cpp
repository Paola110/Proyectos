#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

/*
AZ Recommendations :D
---
1. Usen el comando "using namespace std" para que no
tengan que escribirlo una y otra vez

2. No usen \n al terminar una línea, a menos que quieran
el búfer al mil por ciento, mejor usen endl

3. Hagan funciones para cada cosa, así el código es más
fácil de manipular
*/

string ord_combin() {
  int quant, taken, i, i2, i3, fact1 = 1, fact2 = 1, fact3 = 1;

  // Factorial del Conjunto Total
  cout << "\nIngrese la cantidad de elementos totales" << endl;
  cin >> quant;

  for (i = 1; i <= quant; i++) {
    fact1 = fact1 * i;
  }

  // Factorial de elementos tomados del conjunto
  cout << "Ingrese la cantidad de elementos a usar" << endl;
  cin >> taken;

  for (i2 = 1; i2 <= taken; i2++) {
    fact2 = fact2 * i2;
  }

  // Factorial de la resta de elementos totales menos tomados
  int remain = quant - taken;

  for (i3 = 1; i3 <= remain; i3++) {
    fact3 = fact3 * i3;
  }

  // Fórmula de la combinatoria
  int combin = (fact1) / (fact2 * fact3);

  string result = "La combinatoria es: " + to_string(combin);

  return result;
}

string ord_permut() {
  int quant;
  int taken;
  int i;
  int fact1 = 1;
  int fact2 = 1;

  // Factorial del Conjunto Total
  cout << "\nIngrese la cantidad de elementos totales" << endl;
  cin >> quant;

  for (i = 1; i <= quant; i++) {
    fact1 = fact1 * i;
  }

  // Factorial de elementos tomados del conjunto
  cout << "Ingrese la cantidad de elementos a usar" << endl;
  cin >> taken;

  // Factorial de la resta de elementos totales menos tomados
  int remain = quant - taken;

  for (i = 1; i <= remain; i++) {
    fact2 = fact2 * i;
  }

  // Fórmula de la permutación
  int permut = (fact1) / (fact2);

  string result = "La permutación es: " + to_string(permut);

  return result;
}

string pri_palomar() {
  int palomas, palomares;
  float resultPal = (palomas / palomares);
  cout << "Bienvenid@ al menú del principio del palomar" << endl;
  cout << "Ingrese la cantidad de \"palomas\":" << endl;
  cin >> palomas;
  cout << "Ingrese la cantidad de \"palomares\"" << endl;
  cin >> palomares;
  string printRes = "Caben " + to_string(resultPal) + " palomas en " +
                    to_string(palomares) + " palomares.";
  return printRes;
}

int dec_bin() {
  int numero = 0, bin, t = -1, binario[20];
  do {
    if (numero < 0) {
      cout << "\nError: El numero no puede ser negativo\n";
    }
    cout << "\nDame un entero base 10: ";
    cin >> numero;
  } while (numero < 0);
  int residuo = numero;
  while (residuo >= 2) {
    t++;
    bin = residuo % 2;
    binario[t] = bin;
    residuo = residuo / 2;
  }
  cout << "\nEl numero " << numero << " en binario es ";
  t++;
  binario[t] = 1;
  bin = binario[0];
  for (int i = t; i > 0; i--) {
    cout << binario[i];
  }
  if (numero == 0) {
    bin = 0;
  }
  return bin;
  cout << "\n";
}

int dec_oct() {
  int divi, numero = 0, oct, t = -1, octal[20];
  do {
    if (numero < 0) {
      cout << "\nError: El numero no puede ser negativo\n";
    }
    cout << "\nDame un entero base 10: ";
    cin >> numero;
  } while (numero < 0);
  int residuo = numero;
  while (residuo >= 1) {
    t++;
    divi = (residuo / 8);
    oct = residuo - ((divi)*8);
    octal[t] = oct;
    residuo = (residuo / 8);
  }
  oct = octal[0];
  cout << "\nEl numero " << numero << " en octal es ";
  t++;
  for (int i = t - 1; i > 0 && numero != 0; i--) {
    cout << octal[i];
  }
  if (numero == 0) {
    oct = 0;
  }
  return oct;
  cout << "\n";
}

int dec_hex() {
  int num, cociente = 1, divisor, mod;
  list<int> hex_num;

  cout << "Ingrese un número decimal entero: ";
  cin >> num;

  divisor = num;

  while (cociente != 0) {
    cociente = floor(divisor / 16);

    mod = divisor % 16;
    hex_num.push_front(mod);

    divisor = cociente;
  }

  for (auto i : hex_num) {
    i >= 10 ? cout << char(55 + i) : cout << i;
  }
  return 0;
}

int bin_dec() {
  int n, i, err=1, dec = 0, bin = 0, x = 0;
  long int numero, tam;
  do {
    cout << "\nDame un numero base 2 (binario): ";
    cin >> numero;
    tam = numero;
    if (numero == 0) {
      cout << "\nEl numero binario " << numero << " en decimal es ";
      return 0;
      break;
    }
    for (i = 0; tam > 0; i++) {
      n = tam % 10;
      tam = trunc(tam / 10);
      if (n != 0 && n != 1) {
        i = 0;
        cout << "\nError: Este numero no es binario\n";
        cout << "\nDame un numero base 2 (binario): ";
        cin>>numero;
        tam=numero;
        break;
      }
    }
    if (numero < 0) {
      i = 0;
      cout << "\nError: Este numero no es binario, es negativo\n";
    }
  } while (n != 0 && n != 1 && numero < 0);

  tam = numero;

  for (i; i > 0; i--) {
    n = tam % 10;
    tam = trunc(tam / 10);
    if (n == 1) {
      bin += n * pow(2, x);
    }
    x++;
  }
  cout << "\nEl numero binario " << numero << " en decimal es ";
  return bin;
  cout << "\n";
}

int dec_maya(){
  int num, cociente=1, divisor, mod, lineas, puntos;
  string maya_line = "";
  list<string> maya_num;
  
  cout<<"Ingrese un número decimal entero: ";
  cin>>num;
  
  divisor = num;

  while(cociente != 0){
    cociente = floor(divisor/20);
    mod = divisor%20;

    lineas = floor(mod/5);
    puntos = mod%5;

    if (mod == 0){
      maya_line = "<@>\n";
    } else {
      
      if (puntos > 0){
        for(int i=0; i<puntos; i++){
          maya_line += "*";
        }
        maya_line += "\n";
      }

      if (lineas > 0){
        for(int i=0; i<lineas; i++){
          maya_line += "----\n";
        }
      }
      
    }
    
    maya_num.push_front(maya_line);

    divisor = cociente;
    maya_line = "";
  }

  for (auto i : maya_num){
    cout<<i<<"\n";
  }
  return 0;
}

int main() {
  
  int opcion1, opcion2;
  do{
    cout << "\n\n¡Bienvenido! elige una opcion del menu: " << endl;
    cout << "1. Conversiones" <<endl;
    cout << "2. Combinatoria" <<endl;
    cout << "3. Salir" <<endl; 
    cin>>opcion1;
    switch(opcion1){
      default:
      while(opcion1<1||opcion1>3){
        cout<<"Debes darme un numero entre 1 y 3"<<endl;
        cin>>opcion1;
      }
      case 1:
        cout<< "\n\nElige el tipo de conversion"<< endl;
        cout<< "1. Convertir de decimal a maya"<<endl;
        cout<< "2. Convertir de decimal a binario"<<endl;
        cout<< "3. Convertir de decimal a octal"<<endl;
        cout<< "4. Convertir de decimal a hexadecimal"<<endl;
        cout<< "5. Convertir de binario a decimal"<<endl;
        cout<< "6. Convertir de binario a octal"<<endl;
        cout<< "7. Convertir de binario a hexadecimal"<<endl;
        cin>>opcion2;
          switch(opcion2){
            default:
            while (opcion2<1|| opcion2>7){
            cout<<"Debes darme un numero entre 1 y 7"<<endl;
              cin>>opcion2;
            }
            case 1:
            cout << dec_maya() << endl;
            break;
            case 2:
            cout << dec_bin() << endl;
            break;
            case 3:
            cout << dec_oct() << endl;    
            break;
            case 4:
            cout << dec_hex() << endl;
            break;
            case 5:
            cout << bin_dec() << endl;    
            break;
            case 6:
            break;
            case 7:
            break;
          }
      break;
      case 2:
        cout<< "\n\nElige el tipo de combinatoria"<< endl;
        cout<< "1. Permutaciones ordinarias"<<endl;
        cout<< "2. Permutaciones con dos aspectos"<<endl;
        cout<< "3. Principio del palomar"<<endl;
        cout<< "4. Combinaciones"<<endl;
        cin>>opcion2;
          switch(opcion2){
            default:
            while (opcion2<1|| opcion2>4){
            cout<<"Debes darme un numero entre 1 y 4"<<endl;
              cin>>opcion2;
            }
            case 1:
            cout << ord_permut() << endl;
            break;
            case 2:
            break;
            case 3:
            cout << pri_palomar() << endl;    
            break;
            case 4:
            cout << ord_combin() << endl;
            break;
          }
      break;
      case 3:
      cout<<"Salir"<<endl;
      break;
    }
  
  } while(opcion1!=3);
  exit(0);
}

