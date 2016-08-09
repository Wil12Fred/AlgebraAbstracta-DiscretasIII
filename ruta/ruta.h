using namespace std;

class ruta{
  private:
    int clave;
  public:
    string dic;
    ruta(string dic,int clave){this->dic=dic;this->clave=clave;};
    int pos(int ,int);
    string encriptar(string );
    string desencriptar(string );
};

int ruta::pos(int x,int y){
  return x*clave+y;
}

/*
 * 0 4 8
 * 1 5 9
 * 2 6 x
 * 3 7 x 
 */

string ruta::encriptar(string mns){
  int tam=mns.size()+(clave-mns.size()%clave)%clave;
  int anc=tam/clave;
  for (int i=mns.size();i<tam;i++) mns.push_back('x');
  string enc;
  for (int y=0,x=anc-1;y<(clave+1)/2 && x>=anc/2;y++,x--){
    for (int y1=y,x1=x;y1<clave-y ;y1++){
        enc.push_back(mns[this->pos(x1,y1)]);
    }
    for (int y1=clave-y-1,x1=x-1;x1>y;x1--){
        enc.push_back(mns[this->pos(x1,y1)]);
    }
    for (int y1=clave-y-1,x1=y;y1>y-1 && x1<anc/2;y1--){
        enc.push_back(mns[this->pos(x1,y1)]);
    }
    for (int y1=y,x1=y+1;x1<x && y1<clave/2;x1++){
        enc.push_back(mns[this->pos(x1,y1)]);
    }
  }
  return enc;
}

string ruta::desencriptar(string mns){
  int anc=mns.size()/clave;
  string enc(mns.size(),'x');
  int c=0;
  for (int y=0,x=anc-1;y<(clave+1)/2 && x>=anc/2;y++,x--){
    for (int y1=y,x1=x;y1<clave-y ;y1++){
      enc[this->pos(x1,y1)]=mns[c];
      c++;
    }
    for (int y1=clave-y-1,x1=x-1;x1>y;x1--){
      enc[this->pos(x1,y1)]=mns[c];
      c++;
    }
    for (int y1=clave-y-1,x1=y;y1>y-1 && x1<anc/2;y1--){
      enc[this->pos(x1,y1)]=mns[c];
      c++;
    }
    for (int y1=y,x1=y+1;x1<x && y1<clave/2;x1++){
      enc[this->pos(x1,y1)]=mns[c];
      c++;
    }
  }
  return enc;
}
