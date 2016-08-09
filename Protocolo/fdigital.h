typedef RSA FirmaDigital;
class VayaRuta{
  private:
    int clave;
    FirmaDigital Fd;
  public:
    string diccionario;
    VayaRuta(string dic,int clave){
      Fd=FirmaDigital(diccionario);
      this->clave=clave;
      diccionario=dic;
    }
    string encriptar(string mns){
      vaya V(diccionario,clave);
      ruta R(diccionario,clave);
      while (mns.size()%clave){
        mns.push_back('x');
      }
      string aux1=R.encriptar(V.encriptar(mns));
      string aux2;
      for (int i=0;i<aux1;i++){
        aux2+=ToString(to_ZZ(diccionario.find(aux1[i])),2);
      }
      while (aux2.size()%(ele(n_b)-1)){
        aux2.push_back('0');
      }
      while (aux2.size()%(ele(n_b)-1)){
        aux2.push_back('0');
      }
      ZZ fd=to_ZZ(aux2);
      c=ExpMod(c,e_b,n_b);
      return ToString(c,ele(n_b));
    }
    string desencriptar(string mns){
      ZZ aux;
      aux=to_ZZ(mns);
      ZZ c=Fd.tcr(aux);
      string firma=ToString(c,ele(n)-1);
      string Firma;
      for (int i=0;i<firma.size();i+=2){
        string bloque(firma,i,2);
        ZZ aux=to_ZZ(bloque);
        Firma.push_back(diccionario[conv<int>(aux)];
      }
      vaya V(diccionario,clave);
      ruta R(diccionario,clave);
      return V.desencriptar(R.desencriptar(Firma));
    }
};
