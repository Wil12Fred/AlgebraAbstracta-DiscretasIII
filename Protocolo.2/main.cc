#include <iostream>
#include "vaya"
#include "ruta"

using namespace std;

int main (){
  int clave;
  cin >> clave;
  vaya A(clave);
  ruta B(clave);
  string mns;
  cin >> mns;
  cout << B.encriptar(A.encriptar(mns)) << endl;
  return 0;
}
