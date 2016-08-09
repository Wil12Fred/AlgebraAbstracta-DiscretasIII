ZZ SeedLfcr(){
  ZZ tmp;
  tmp=xorshift_x ^(xorshift_x << 11);
  xorshift_x=xorshift_y ;                                                        
  xorshift_y=xorshift_z ;                                                        
  xorshift_z=xorshift_w ;                                                        
  xorshift_w=xorshift_w ^ ( xorshift_w >>19)^(tmp^(tmp>>8)) ;//xor y shiftrigth  
  return xorshift_w;//modulo                                           
}

inline ZZ FS(ZZ x,ZZ i){
  return (ExpMod(x,i+4,to_ZZ("2"))+ExpMod(x,i+5,to_ZZ("2"))+1)%to_ZZ("2");
}

string trans(string aux,int it){
  ZZ sum=to_ZZ(it);
  for (int i=0;i<3;i++){
    int r=rand()%aux.size();
    sum+=to_ZZ(aux[r]);
  }
  int change=rand()%aux.size();
  if (ToString(sum%to_ZZ("2"))=="1"){
    aux[change]=1;
  } else {
    aux[change]=0;
  }
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
  string bin;
  int i=0;
  while (i<tam){
    ZZ x=SeedLfcr();
    bin+=(ToString(FS(x,to_ZZ(i))));
    i++;
  }
  int bloque=0;
  cout << bloque << endl;
  while (!m_r(BinZZ(bin),5)){
    string ans;
    for (int i=0;i<tam;i+=((tam*3)/100)){
      string aux(bin,i,(tam*3)/100);
      aux=trans(aux,bloque);
      ans+=aux;
      bloque++;
    }
    bin=ans;
  }
  return BinZZ(bin);
}
