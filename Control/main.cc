#include <iostream>
#include <vector>
#include <cstring>
#include "mate.h"
#include "cesar.h"
#include "vaya.h"
#include "ruta.h"
#include "arv.h"

using namespace std;

int main(){
  arv A("JonathanMollapazaApazaJimmyJonathanMollapazaApazaJimmy",8);
  int i,j=1;
  cout << "1=encriptar\n2=desencriptar\n";
  cin >> i;
  while (j){
    if (i==1){
      string sdic;
      ll sc;
      cout << "a - b\n";
      cin >> sdic >> sc;
      //cesar Cesar(dic,sc);
      //sdic=Cesar.des(sdic);
      //sdic="Wilber Cutire Sivincha Wilber Cutire Sivincha";
      //sc=10;
      int a1=a(sdic,sc);
      int b1=b(sdic,sc);
      cout << a1 << " " << b1 << endl;
      string enc;
      vaya Vaya(dic,sc);
      ruta Ruta(dic,sc);
      enc=Vaya.encriptar("holamundoholamundoholamundoholamundoholamundo");
      cout << enc.size() << endl;
      enc=Ruta.encriptar(enc);
      enc=A.encriptar(enc,a1,b1);
      cout << enc << endl;
    }
    if (i==2){
      int tam;
      string enc;
      cin >> enc >> tam;
      string des;
      vaya Vaya(dic,8);
      ruta Ruta(dic,8);
      des=A.desencriptar(enc);
      des=Ruta.desencriptar(des);
      for (i=des.size();i!=tam;i=des.size()){
        des.erase(des.begin()+i-1);
      }
      des=Vaya.desencriptar(des);
      cout << des << endl;
    }
    cout << "1=encriptar\n2=desencriptar\n";
    cin >> i;
  }
  return 0;
}
