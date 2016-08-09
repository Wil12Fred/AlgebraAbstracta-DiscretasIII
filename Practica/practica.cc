#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void p1(){
  string s1="problema1";
  string s2(10,'x');
  string s3(s1);
  string s31(s1,0,8);
  string s32(s1.begin(),s1.begin()+3);
  string s33(s1,3);
  string s4("problema1");
  cout << s1 << endl
    << s2 << endl
    << s31 << endl
    << s32 << endl;
}

void p2(){
  string aux("problema2");
  cout << aux.size() << endl;
}

void p3(){
  string st="problema3";
  for(int i=0;i<st.size();i++){
    cout << st[i] << endl;
  }
}

void p4(){
  string st="Mi curso favorito es estructuras discretas 3";
  int aux=st.find('e');
  while (aux>-1 && aux<st.size()){
    st[aux]='x';
    aux=st.find('e');
  }
  cout << st << endl;
}

void p5(){
  string st="12";
  int ist=atoi(st.c_str());
  ist=ist*ist;
  string st2=to_string(ist);
  cout << st2 << endl;
}

void p6(){
  string st="Mi curso favorito es estructuras discretas 3";
  string st2(st,9,8);
  cout << st2 << endl;
}

void p7(){
  string st1="Buenos dias";
  string st2="Adios";
  string st3(st2);
  st2=st1;
  st1=st3;
  cout << st1 << endl;
  cout << st2 << endl;
}

void p8(){
  string mns;
  cout << "Introdusca mensaje con espacios en blanco\n";
  getline(cin,mns);
  cout << mns << endl;
}

void p9(){
  string linea,palabra;
  int cont=0;
  ifstream leer;
  leer.open("Texto.h",ios::in);
  while (getline(leer,linea)) cout << linea << endl;
  leer.close();
  leer.open("Texto.h",ios::in);
  while (leer >> palabra){
    cout << palabra << " ";
    if (palabra=="universo") cont++;
  }
  cout << endl;
  leer.close();
  cout << "Aparecen " << cont << " veces la palabra universo\n";
}

void p10(){
  string st1="Anita vende pan",st2;
  for(int i=0;i<st1.size();i++)
    st2.push_back(st1[i]);
  cout << st2 << endl;
}

void p11(){
  string st="problema11";
  for (int i=0;i<st.size();i++)
    cout << st[i];
  cout << endl;
  for (int i=st.size()-1;i>-1;i--)
    cout << st[i];
  cout << endl;
}

void p12(){
  string st;
  cout << "instrodusca mensaje" << endl;
  getline(cin,st);
  if (st.empty()) cout << "'"<< st <<  "'" << " esta vacio" << endl;
  else cout << "'"<< st <<  "'" << " no esta vacio" << endl;
}

void p13(){
  string st="esternocleidomastoideo";
  int aux=st.find('e');
  while (aux>-1 && aux < st.size()){
    st.erase(st.begin()+aux);
    aux=st.find('e');
  }
  cout << st << endl;
}

void p14(){
  string st1,st2;
  cout << "introdusca dos palabras" << endl;
  cin >> st1 >> st2;
  if (st1==st2) cout << "son iguales" << endl;
  else cout << "son diferentes" << endl;
}

void p15(){
  string st1,st2;
  cout << "introdusca dos palabras" << endl;
  cin >> st1 >> st2;
  st1+=st2;
  cout << st1 << endl;
}

void p16(){
  string st,st2;
  cout << "Introdusca una palabra" << endl;
  cin >> st;
  st2=st;
  reverse(st.begin(),st.end());
  if (st==st2) cout << "es palindromo" << endl;
  else cout << "no es palindromo" << endl;
}

int main (){
  return 0;
}
