ZZ Gordon(int tam){
  ZZ p=GPrime(tam);
  ZZ q=GPrime(tam),e,a,b,p1,mod,P,ans;
  a=4;
  p1=p*a+1;
  while (!m_r(p1,5)){
    a+=2;
    p1=a*p+1;
  }
  mod=q*p1;
  P=ExpMod(q,p1-1,mod)-ExpMod(p1,q-1,mod);
  e=P&1;
  if (e==0) P+=mod;
  a=2;
  ans=P+a*mod;
  while (!m_r(ans,5)){
    a+=2;
    ans=P+a*mod;
  }
  return ans;
}
