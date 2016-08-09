class Pr{
  private:
    ZZ d;
    ZZ r,cm,ca;
    ZZ a,k,m;
  public:
    string diccionario;
    RSA R;
    Gamal G;
    ZZ n,e,g,q;
    ZZ inversa(ZZ &A){
      return ExpMod(A,q-2,q);
    }
    Pr(string diccionario){
      this->diccionario=diccionario;
      R=RSA(diccionario);
      G=Gamal(diccionario);
      n=R.n;
      e=R.e;
      d=R.darD();
      g=G.e1;
      q=G.p;
    }
    string encriptar(string mns,ZZ n2,ZZ e2,ZZ g2,ZZ q2){
      string mensaje;
      for (int i=0;i<mns.size();i++){
        mensaje+=(ToString(conv<ZZ>(diccionario.find(mns[i])),2));
      }
      int tam=(ele(q2)-1);
      while (mensaje.size()%tam){
        mensaje.push_back('0');
      }
      string ans;
      r=BlumBlumShub(q2-2)+1;
      k=ExpMod(g2,r,q2);
      ca=ExpMod(r,e2,n2);
      for (int i=0;i<mensaje.size();i+=tam){
        string auxiliar1(mensaje,i,tam);
        ZZ mn(INIT_VAL,auxiliar1.c_str());
        cm=(mn*k)%q2;
        ans+=ToString(cm,ele(q2));
      }
      return ToString(ca,ele(n2))+ans;
    }
    string desencriptar(string mns){
      string aux(mns,0,ele(n));
      ca=to_ZZ(aux);
      a=ExpMod(ca,d,n);
      k=ExpMod(g,a,q);
      string aux_1;
      string ans;
      for (int i=ele(n);i<mns.size();i+=ele(q)){
        string aux1(mns,i,ele(q));
        cm=to_ZZ(aux1);
        aux_1+=ToString((cm*inversa(k))%q,ele(q)-1);
      }
      for (int i=0;i<aux_1.size();i+=2){
        string aux(aux_1,i,2);
        ans.push_back(diccionario[conv<int>(stoi(aux))]);
      }
      return ans;
    }
};
