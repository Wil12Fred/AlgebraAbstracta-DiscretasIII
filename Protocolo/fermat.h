bool fermat(ZZ n,int k){//tiene problemas con los numeros de mersenne
  ZZ aux,a,e;
  if (n==2) return true;
  e=n&1;
  if (e==0) return false;
  for (int i=0;i<k;i++){
    a=XorShift(n-2)+1;
    aux=ExpMod(a,n-1,n);
    if (aux!=1){
      return false;
    }
  }
  return true;
}
