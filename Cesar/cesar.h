using namespace std;

class cesar{
  private:
    int clave;
  public:
    string dic;
    cesar(string ,int);
    string enc(string);
    string des(string);
};

cesar::cesar(string dic,int clave){
  this->dic=dic;
  this->clave=clave;
}

string cesar::enc(string mns){
  string enc;
  for (int i=0;i<mns.size();i++){
    int pos=dic.find(mns[i])+clave;
    enc.push_back(dic[mod(pos,dic.size())]);
  }
  return enc;
}

string cesar::des(string enc){
  string des;
  for (int i=0;i<enc.size();i++){
    int pos=dic.find(enc[i])-clave;
    des.push_back(dic[mod(pos,dic.size())]);
  }
  return des;
}
