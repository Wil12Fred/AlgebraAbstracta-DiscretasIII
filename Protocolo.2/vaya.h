using namespace std;

class vaya{
  private:
    int clave;
  public:
    string dic;
    vaya(string ,int );
    string encriptar(string );
    string desencriptar(string );
};

vaya::vaya(string dic,int clave){
  this->dic=dic;
  this->clave=clave;
}

/*
 * m    i    g
 *  u  c  e a  o
 *   r     l    x
 */

string vaya::encriptar(string mns){
  int comp=mns.size()%(2*clave-2);
  comp=2*clave-2-comp;
  if (comp==2*clave-1) comp=1;
  else comp++;
  for (int i=0;i<comp;i++){
    mns.push_back('x');
  }
  int tot=2*(clave-1);
  int salto=tot;
  int falta=tot-salto;
  string encriptado;
  for (int i=0;i<clave;i++){
    vector<int> A;
    if(salto!=0)A.push_back(salto);
    if (falta!=0)A.push_back(falta);
    for (int j=i,c=0;j<mns.size();j+=A[c%A.size()],c++){
      encriptado.push_back(mns[j]);
    }
    salto-=2;
    falta+=2;
  }
  return encriptado;
}

string vaya::desencriptar(string enc){
  string des(enc.size(),'x');
  int tot=2*(clave-1);
  int salto=tot;
  int falta=tot-salto;
  int pos=0;
  for (int i=0;i<clave;i++){
    vector<int> A;
    if(salto!=0) A.push_back(salto);
    if (falta!=0) A.push_back(falta);
    for (int j=i,c=0;j<enc.size();j+=A[c%A.size()],c++){
      des[j]=enc[pos];
      pos++;
    }
    salto-=2;
    falta+=2;
  }
  return des;
}

