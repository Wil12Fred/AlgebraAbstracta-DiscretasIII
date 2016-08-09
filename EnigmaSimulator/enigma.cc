#include <iostream>
#include <cstring>

using namespace std;

string dic = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string rotors[3] = 
{
  "EJDKSIRUXBLHWTMCQGZNPYFVOA",
  "BDFHJLCPRTXVZNYEIWGAKMUSQO",
  "EKMFLGDQVZNTOWYHXUSPAIBRCJ"
};

char reflector[] = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
//char reflector[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char key[] = "BCD";

int mod(int a){
  a=a%26;
  return a%26 < 0 ? a+26 :a;//;
}

string encriptar (string ct){
  // Sets initial permutation
  int R = dic.find(key[2]);
  int M = dic.find(key[1]);
  int L = dic.find(key[0]);

  string encriptado;

  for ( int x = 0; x < ct.size() ; x++ ) {
    int ct_letter = dic.find(ct[x]);

    // Step right rotor on every iteration
    R = mod(R + 1);

    // Pass through rotors
    char a = rotors[2][mod(ct_letter + R)];//R->clave key[2]
    char b = rotors[1][mod(dic.find(a)+ M - R)];//M->clave key[1]
    char c = rotors[0][mod(dic.find(b)+ L - M)];//L->clave key[0]
    // Pass through reflector
    char ref = reflector[mod(dic.find(c))-L];
    int pos=dic.find(ref);
    // Inverse rotor pass
    int d = mod(rotors[0].find(dic[mod(pos + L)]) - L);
    int e = mod(rotors[1].find(dic[mod(d + M)]) - M);
    int f = mod(rotors[2].find(dic[mod(e + R)]) - R);

    encriptado.push_back(dic[f]);
  }
  return encriptado;
}

int main ()
{
  string MNS="HOLAMUNDO";//="PZUFWDSASJGQGNRMAEODZJXQQKHSYGVUSGSU";
  cout << encriptar(dic+dic) << endl;
  cout << encriptar(encriptar(dic+dic)) << endl;
  return 0;
}
