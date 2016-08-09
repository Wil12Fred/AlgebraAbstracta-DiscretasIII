typedef long long ll;
using namespace std;

string dic="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int pos(int x,int y,int clave){
  return x*clave+y;
}

int a(string st, int clave){
  bool ex[st.size()];
  memset(ex,0,sizeof(ex));
  for(int i=clave;i<=st.size();i+=(clave-1)*2){//va por los picos
    ex[i-1]=1;//marco como visitado
    ll aleatorio=dic.find(st[mod(pos(i-1,clave-1,clave),st.size())])+dic.find(st[i-1]);//asigno su valor
    if (gcd(aleatorio,ll (dic.size()))==1){//verifico si puede ser aleatorio
      return aleatorio;
    }
  }
  int i=clave;
  for(;i<=st.size();i+=(clave-1)*2){//voy por los oblicuas
    int x=i-1;
    int y=clave-1;
    while (y>0 && ex[x-1]==0){//derecha
      ex[x-1]=1;
      ll aleatorio=dic.find(st[mod(pos(x-1,y-1,clave),st.size())])+dic.find(st[x-1]);
      if (gcd(aleatorio,ll (dic.size()))==1){
        return aleatorio;
      }
      x--;
      y--;
    }
    x=i+1;
    y=clave-1;
    while (y>0 && x<=st.size() && ex[x-1]==0){//izquierda
      ex[x-1]=1;
      ll aleatorio=dic.find(st[mod(pos(x-1,y-1,clave),st.size())])+dic.find(st[x-1]);
      if (gcd(aleatorio,ll (dic.size()))==1){
        return aleatorio;
      }
      x++;
      y--;
    }
  }
  int f=clave-st.size()%(clave+clave-2);//si palabra no completa la ultima oblicua
  if (f>0){
    int x=i-f;
    int y=clave-f;
    while (y>0 && ex[x-1]==0){
      ex[x-1]=1;
      ll aleatorio=dic.find(st[mod(pos(x-1,y-1,clave),st.size())])+dic.find(st[x-1]);
      if (gcd(aleatorio,ll (dic.size()))==1){
        return aleatorio;
      }
      x--;
      y--;
    }
  }
  return st.size()-1;
}

int b(string st,int clave){
  int ans=0;
  int ini=0;
  char ant;
  for(int i=clave;i<=st.size();i+=(clave-1)*2){//va por los rectangulos formados
    int anc=i-ini;
    int n=anc-1;
    for (int y=0,x=anc-1;y<(clave+1)/2 && x>=anc/2;y++,x--){
      for (int y1=y,x1=x;y1<clave-y ;y1++){
        int sum=mod(pos(x1+ini,y1,clave),st.size());
        if (n-x1==y1 && y1!=0){//verifico si pertenece a la oblicua
          ans+=dic.find(ant);
        }
        ant=st[sum];//lo marco como el anterior
      }
      for (int y1=clave-y-1,x1=x-1;x1>y;x1--){
        int sum=mod(pos(x1+ini,y1,clave),st.size());
        if (n-x1==y1){
          ans+=dic.find(ant);
        }
        ant=st[sum];
      }
      for (int y1=clave-y-1,x1=y;y1>y-1 && x1<anc/2;y1--){
        int sum=mod(pos(x1+ini,y1,clave),st.size());
        if (n-x1==y1){
          ans+=dic.find(ant);
        }
        ant=st[sum];
      }
      for (int y1=y,x1=y+1;x1<x && y1<clave/2;x1++){
        int sum=mod(pos(x1+ini,y1,clave),st.size());
        if (n-x1==y1){
          ans+=dic.find(ant);
        }
        ant=st[sum];
      }
    }
    ini=i;
    ans+=dic.find(ant);//el ultimo elemento siempre se añade
  }
  int i=st.size();
  int anc=i-ini;
  int n=anc-1;
  for (int y=0,x=anc-1;y<(clave+1)/2 && x>=anc/2;y++,x--){//va por el ultimo rectangulo
    for (int y1=y,x1=x;y1<clave-y ;y1++){
      int sum=mod(pos(x1+ini,y1,clave),st.size());
      if (n-x1==y1 && y1!=0){
        ans+=dic.find(ant);
      }
      ant=st[sum];
    }
    for (int y1=clave-y-1,x1=x-1;x1>y;x1--){
      int sum=mod(pos(x1+ini,y1,clave),st.size());
      if (n-x1==y1){
        ans+=dic.find(ant);
      }
      ant=st[sum];
    }
    for (int y1=clave-y-1,x1=y;y1>y-1 && x1<anc/2;y1--){
      int sum=mod(pos(x1+ini,y1,clave),st.size());
      if (n-x1==y1){
        ans+=dic.find(ant);
      }
      ant=st[sum];
    }
    for (int y1=y,x1=y+1;x1<x && y1<clave/2;x1++){
      int sum=mod(pos(x1+ini,y1,clave),st.size());
      if (n-x1==y1){
        ans+=dic.find(ant);
      }
      ant=st[sum];
    }
  }
  return ans;
}

class arv{
  private:
    ll m_a;
    ll m_b;
  public:
    ll MOD;
    arv(string st,int clave){
      MOD=dic.size();
      m_a=a(st,clave);
      m_b=b(st,clave);
      cout << m_a << " " << m_b << endl;
    }
    string encriptar(string mns,int a,int b){
      string enc;
      for (int i=0;i<mns.size();i++){
        int aux=dic.find(mns[i]);
        enc.push_back(dic[mod(mod(aux*a,MOD)+b,MOD)]);
      }
      return enc;
    }
    string desencriptar(string enc){
      string mns;
      for (int i=0;i<enc.size();i++){
        int aux=dic.find(enc[i]);
        int d=mod(mod(aux-m_b,MOD)*inv(m_a,MOD),MOD);
        mns.push_back(dic[d]);
      }
      return mns;
    }
};
