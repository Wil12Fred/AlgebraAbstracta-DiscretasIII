#include <iostream>
#include "ruta.h"

using namespace std;

/* 0 7 e
 * 1 8 f
 * 2 9 g
 * 3 a h
 * 4 b i
 * 5 c x
 * 6 d x
 */
int main(){
  string dic="abcdefghijklmnopqrstuvwxyz ";
  int clave;
  cin >> clave;
  ruta A(dic,clave);
  string mns;
  cin >> mns;
  cout << A.encriptar(mns) << endl; 
  cout << A.desencriptar(A.encriptar(mns)) << endl;
  return 0;
}
