inline int mod(int i,int n){
  int d=i/n;
  if (i<0) d--;
  int m=i-(d*n);
  return m==n ? 0 : m;
}

inline int mod1(int i, int n){
  if (i<0){
    while (i<0)
      i+=n;
    return i;
  }
  while (n<=i){
    i-=n;
  }
  return i;
}
