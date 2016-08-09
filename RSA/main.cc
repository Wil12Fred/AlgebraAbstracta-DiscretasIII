#include <iostream>
#include <ctime>
#include <map>
#include <math.h>
#include <chrono>//tiempo de demora de un programa
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <sys/time.h>//da el tiempo en milisegundos
#include <stdint.h>//maneja numeros de 64 bits
#include <NTL/ZZ.h>//maneja numeros muy grandes
using namespace std;
using namespace NTL;
typedef long long ll;
typedef std::chrono::high_resolution_clock Time;  
typedef std::chrono::milliseconds ms;             
typedef std::chrono::duration<float> fsec;        
typedef pair <ZZ,ZZ> pii;

#include "funciones.h"//algoritmos elementales
#include "xorshift.h"//numeros pseudoaleatorios
#include "mersenne_twister.h"//numeros pseudoaleatorios casi perfectos
#include "miller_rabin.h"//algoritmo de primalidad de numeros impares!
#include "bbs.h"//numeros aleatorios
#include "lfcr.h"

int tam=128;

#include "criba.h"//numeros primos O(n*lg(n))
#include "fermat.h"//test de primalidad
#include "lucas.h"//verifica los numeros de mersenne lucas-lehmer

#include "gordon.h"//numeros primos fuertes
#include "pollar.h"//factorizacion
#include "rsa.h"//algoritmo de encriptacion


string diccionario;//="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 1234567890,;:-_<>@*+().?!";

int main(){
  diccionario=leer("diccionario.txt");
  int encriptar;
  SeedXorShift();
  SeedBBS();
  RSA A(diccionario);
  //cout << lfcr(32) << endl;
  //vector<int> Criba;eratotenes(&Criba);
  A.dar_datos();
  cout << "Encriptar-Desencriptar" << endl;
  cin >> encriptar;
  while (encriptar){
    if (encriptar==1){
      ifstream leer ("encriptar.txt",ios::in);
      ZZ n;
      ZZ e;
      string mns;
      cin >> n >> e;
      cin >> mns;
      cout << A.encriptar(mns,n,e) << endl;
      leer.close();
    }
    if (encriptar==2){
      string mns;
      cin >> mns;//mns=leer("desencriptar.txt");
      cout << A.desencriptar(mns) << endl;
    }
    cout << "Encriptar-Desencriptar" << endl;
    cin >> encriptar;
  }
  return 0;
}
