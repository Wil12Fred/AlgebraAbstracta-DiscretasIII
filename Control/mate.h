using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

inline ll mod(ll i,ll n){
  ll d=i/n;
  if (i<0) d--;
  ll m=i-(d*n);
  return m==n ? 0 : m;
}

inline ll even(ll a){
  if (a & 1) return false;
  return true;
}

ll men_res(ll a,ll b){
  if (b==0){
    return a;
  }
  ll resto=mod(a,b);
  ll resto2=(resto-b)*-1;
  return men_res(b , min(resto,resto2));
}

inline ll gcd(ll u,ll v){
  ll a,b,t,aux,s;
  a=u;
  b=v;
  if (a<b){
    aux=a;
    a=b;
    b=aux;
  }
  while (b!=0){
    s=1;
    while ((b*s)<=a)
      s=s<<1;
    s=s>>1;
    t = min(a-b*s,b*(s<<1)-a);
    a=b;
    b=t;
    if (a<b){
      aux=a;
      a=b;
      b=aux;
    }
  }
  return a;
}

inline pii ext(ll x,ll y,ll v=0){
  ll u,A,B,C,D,g=1;
  A=1,B=0,C=0,D=1;
  while ((even(x)) && (even(y))){
    x=x >> 1;
    y=y >> 1; 
    g=g<<1;
  }
  u=x ;
  v=y ;//x*(A+C)+y*(B+D)
  while (u!=0){
    while (even(u)){
      u=u >> 1;
      if ((even(A)) && (even(B))){
        A=A >> 1; B=B >> 1;
      }else{
        A=(A+y) >> 1;B=(B-x) >> 1;
      }
    }
    while (even(v)){
      v=v >> 1;
      if ((even(C)) && (even(D))){
        C=C >> 1;
        D=D >> 1;
      }else{
        C=(C+y) >> 1;
        D=(D-x) >> 1; 
      }
    }
    if (u>=v){
      u-=v;
      A-=C;
      B-=D;
    }else{
      v-=u;
      C-=A;
      D-=B;
    }
  }
  v*=g;
  return make_pair(C,D);
}

inline ll inv(ll n, ll m){
  return mod(ext(n,m).first,m); 
}
