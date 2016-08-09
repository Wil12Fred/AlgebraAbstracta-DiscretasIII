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

#include "criba.h"//numeros primos O(n*lg(n))
#include "fermat.h"//test de primalidad
#include "lucas.h"//verifica los numeros de mersenne lucas-lehmer

#include "gordon.h"//numeros primos fuertes
#include "pollar.h"//factorizacion
#include "rsa.h"//algoritmo de encriptacion
#include "fdigital.h"


string diccionario;//="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 1234567890,;:-_<>@*+().?!";

int main(){
  SeedXorShift();
  SeedBBS();
  diccionario=leer("diccionario.txt");
  FirmaDigital A(diccionario),B(diccionario);
  for (int i=0;i<diccionario.size();i++){
    string firma=A.darFD(diccionario[i],B.n,B.e);
    cout << B.verFD(firma,A.n,A.e);
  }
  cout << endl;
  return 0;
}
