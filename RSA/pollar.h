ZZ c_brent;

ZZ f(ZZ x){
  return x*x+c_brent;
}

ZZ pollar(ZZ n){
  ZZ x,y,d;
  c_brent=1;
  x=2;//rand();
  y=2;
  d=1;
  while (d==1){
    x=f(x)%n;
    y=f(f(y))%n;
    d=gcd(x-y,n);
  }
  return d;
}

inline bool isPowerOf2(ZZ i){
  ZZ aux=(i-1)&i;
  return aux==0?1:0;
}

ZZ brent(ZZ n){
  ZZ x,y,d,r,q,k,ys,m;
  y=XorShift(n-2)+1;
  c_brent=XorShift(n-2)+1;
  m=XorShift(n-2)+1;
  d=1;
  r=1;
  q=1;
  while (d==1){
    x=y;
    for (ZZ i=to_ZZ("0");i<r;i++){
      y=f(y)%n;
    }
    k=0;
    while (k<r && d==1){
      ys=y;
      for (ZZ i=to_ZZ("0");i<min(m,r-k);i++){
        y=f(y)%n;
        q=(q*(abs(x-y)))%n;
      }
      d=gcd(q,n);
      k+=m;
    }
    r=r*2;
  }
  if (d==n){
    while (d<2){
      ys=f(ys)%n;
      d=gcd(x-ys,n);
    }
  }
  return d;
}

void factorization_pollar(ZZ N,map<ZZ,int>&M){
  if (N==1)
    return;
  if (m_r(N,5)){
    M[N]++;
    return;
  }
  ZZ factor=pollar(N);
  factorization_pollar(factor,M);
  factorization_pollar(N/factor,M);
  return;
}

void factorization_brent(ZZ N,map<ZZ,ZZ>&M){
  if (N==1)
    return;
  if (m_r(N,5)){
    M[N]++;
    return;
  }
  ZZ factor=brent(N);
  factorization_brent(factor,M);
  factorization_brent(N/factor,M);
  return;
}

ZZ phiEuler(ZZ N){
  ZZ ans;
  ans=1;//e^p-e^p-1
  map<ZZ,ZZ> M;
  while((N&1)==0){
    M[to_ZZ("2")]++;
    N>>=1;
  }
  factorization_brent(N,M);
  for (auto it=M.begin();it!=M.end();it++){
    ZZ aux=ExpMod(it->first,it->second)-ExpMod(it->first,it->second-1);
    ans*=aux;
  }
  return ans;
}
