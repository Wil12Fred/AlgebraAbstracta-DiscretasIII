inline char FS(string bin){
  return ((bin[bin.size()-1]-'0')+(bin[bin.size()-2]-'0')+1)%2+'0';
}

string leftbin(string aux){
  string aux3;
  aux3.push_back(aux[0]);
  string aux2(aux,1,aux.size()-1);
  return aux3+aux2;
}

string trans(string aux,int it){
  aux=leftbin(aux);
  for (int i=0;i<3;i++){
    int ran=rand()%aux.size();
    it+=aux[ran]-'0';
  }
  int ran=rand()%aux.size();
  aux[ran]=(it%2)+'0';
  return aux;
}

inline ZZ BinZZ(string aux){
  ZZ ans=to_ZZ("0");
  ZZ pos=to_ZZ("1");
  for (int i=0;i<aux.size();i++){
    if(aux[i]=='1'){
      ans+=pos;
    }
    pos<<=1;
  }
  return ans;
}

ZZ lfcr(int tam){
  string bin=SeedLFCR(4);
  for (int i=0;i<tam-4;i++){
    bin.push_back(FS(bin));
  }
  while (!m_r(BinZZ(bin),5)){
    cout << bin << " " << BinZZ(bin) <<  endl;
    string ans;
    int bloque=0;
    for (int i=0;i<tam;i+=((tam*3)/100)){
      string aux(bin,i,(tam*3)/100);
      aux=trans(aux,bloque);
      ans+=aux;
      bloque++;
    }
    bin=ans;
    cin >> bloque;
  }
  return BinZZ(bin);
}
