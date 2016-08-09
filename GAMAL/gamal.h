bool esRP(ZZ g,ZZ n){//puedo optimizar
  ZZ m=phiEuler(n);
  map<ZZ,ZZ>M;
  factorization_brent(m,M);
  for (auto it=M.begin();it!=M.end();it++){
    ZZ mi=m/it->first;
    if(ExpMod(g,mi,n)==1){
      return false;
    }
  }
  return true;
}

ZZ RaizPrimitiva(ZZ p){
  ZZ rand=BlumBlumShub(p-1)+1;
  ZZ phi=phiEuler(p);
  while (!esRP(rand,p)){
    rand=BlumBlumShub(p-1)+1;
  }
  return rand;
}

class Gamal{
  private:
    ZZ d;
  public: 
    string diccionario;
    ZZ p;
    ZZ e1,e2;
    ZZ c1,km,c2;
    ZZ r;
    Gamal(string diccionario){
      this->diccionario=diccionario;
      p=GPrime(tam/2);
      e1=RaizPrimitiva(p);
      d=BlumBlumShub(p-1)+1;
      e2=ExpMod(e1,d,p);
    }
    Gamal(string diccionario,ZZ e1, ZZ e2, ZZ p,ZZ d){
      this->diccionario=diccionario;
      this->e1=e1;
      this->e2=e2;
      this->p=p;
      this->d=d;
    }
    void darDatos(){
      ifstream darDatos("Recuperacion",ios::in);
      darDatos >> e1;
      darDatos >> e2;
      darDatos >> p;
      darDatos >> d;
    }
    string encriptar(string mns,ZZ E1,ZZ E2,ZZ P){
      r=BlumBlumShub(P-2)+1;
      c1=ExpMod(E1,r,P);
      km=ExpMod(E2,r,P);
      string encriptar;
      for (int i=0;i<mns.size();i++){
        encriptar+=ToString(to_ZZ(diccionario.find(mns[i])),2);
      }
      int tam=ele(P)-1;
      while (encriptar.size()%tam){
        encriptar.push_back('0');
      }
      string C2;
      for (int i=0;i<encriptar.size();i+=tam){
        string aux(encriptar,i,tam);
        ZZ pos(INIT_VAL,aux.c_str());
        pos=(pos*km)%P;
        C2+=(ToString(pos,tam+1));
      }
      return ToString(c1,tam+1)+C2;
    }
    string desencriptar(string mns){
      string C1(mns,0,ele(p));
      c1=to_ZZ(C1.c_str());
      km=ExpMod(c1,d,p);
      km=inv(km,p);
      string aux;
      for (int i=ele(p);i<mns.size();i+=ele(p)){
        string pos(mns,i,ele(p));
        ZZ c(INIT_VAL,pos.c_str());
        aux+=ToString((c*km)%p,ele(p)-1);
      }
      string ans;
      for (int i=0;i<aux.size();i+=2){
        string pos(aux,i,2);
        ans.push_back(diccionario[stoi(pos)]);
      }
      return ans;
    }
};
