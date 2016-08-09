#include <iostream>
#include <string>
#include <vector>
#include "mate.h"
#include "cesar.h"

using namespace std;

int main (){
  string dic="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWZYZ\n";
  cout << "introduzca clave" << endl;
  int clave;
  cin >> clave;
  cesar A(dic,clave),B(dic,clave);
  int opc;
  cout << "1=encriptar \n2=desencriptar" << endl;
  cin >> opc;
  while (opc){
    if (opc==1){
      string mns;
      cout << "introduzca el mensaje" << endl;
      cin >> mns;
      string enc=A.enc(mns);
      cout << enc << endl;
    }
    if (opc==2){
      string enc;
      cout << "introduzca mensaje encriptado" << endl;
      cin >> enc;
      string des=A.des(enc);
      cout << des << endl;
    }
    cout << "1=encriptar \n2=desencriptar" << endl;
    cin >> opc;
  }
  return 0;
}
