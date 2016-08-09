#include <iostream>
#include <string>
#include "mate.h"
#include "cesar.h"

using namespace std;

int main (){
  //int i,n;cin >> i >> n;cout << mod1(i,n) << endl;
  string dic="abcdefghijklmnopqrstuvwxyz .;-",mns;//="cesar en diii";
  int clave;
  cin >> clave >> mns;
  cesar A(dic,clave);
  cout << A.enc(mns) << endl;
  cout << A.des(A.enc(mns)) << endl;
  return 0;
}
