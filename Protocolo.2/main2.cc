#include <iostream>
#include <vector>
#include "vaya.h"
#include "ruta.h"

using namespace std;

int main (){
  int clave;
  string dic;
  cin >> clave;
  vaya A(dic,clave);
  ruta B(dic,clave);
  string mns="zp_ljaopnaanopp naama aanp tjl laozhlaatozzamaaa hat amzoaalh  lajaanopnaaz";
  cout << A.desencriptar(B.desencriptar(mns)) << endl;
  return 0;
}
