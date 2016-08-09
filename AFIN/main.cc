#include <iostream>
#include <ctime>
#include "mate.h"
#include "afin.h"

using namespace std;

int main(){
  string dic="abcdefghijklmnopqrstuvwxyz";
  afin A(dic);
  cout << A.desencriptar((A.encriptar(dic))) << endl;
  return 0;
}
