#include <iostream>
#include <vector>
#include "mate.h"
#include "vaya.h"

int main (){
  string dic="abcdefghijklmnopqrstuvwxyz";
  int clave;
  cin >> clave;
  vaya A(dic,clave);
  string mns="Wilber Cutire Sivincha Wilber";
  cin >> mns;
  cout << mns << endl;
  cout << A.encriptar(mns) << endl;
  cout << A.desencriptar(A.encriptar(mns));
  return 0;
}
