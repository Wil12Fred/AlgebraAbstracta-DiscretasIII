using namespace std;

class cesar{
  private:
    int clave;
  public:
    string dic;
    cesar(string,int);
    string enc(string);
    string des(string);
};

cesar::cesar(string dic,int clave){
  this->clave=clave;
  this->dic=dic;
}

string cesar::enc(string mns){
  string enc;
  for (int i=0;i<mns.size();i++){
    int aux=dic.find(mns[i]);
    aux=mod1(dic.size()-aux-1+clave,dic.size());
    enc.push_back(dic[aux]);
  }
  return enc;
}

string cesar::des(string enc){
  string mns;
  for (int i=0;i<enc.size();i++){
    int aux=dic.find(enc[i]);
    aux=mod1(dic.size()-aux-1+clave,dic.size());
    mns.push_back(dic[aux]);
  }
  return mns;
}
