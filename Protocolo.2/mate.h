inline int mod(int i,int n){
  int d=i/n;
  if (i<0) d--;
  int m=i-(d*n);
  return m==n ? 0 : m;
}
