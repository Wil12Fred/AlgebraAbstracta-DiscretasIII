ZZ k_q(ZZ q){
  ZZ k;
  q--;
  k=0;
  while ((q&1)==0){
    q=q >> 1;
    k++;
  }
  return q;
}

bool m_r(ZZ n,int max){
  ZZ e,a,temp,r;
  ZZ q=k_q(n);
  for (int i = 0; i < max; i++){
    a = XorShift(n - 1) + 1;
    temp = q;
    r = ExpMod(a, temp, n);
    while (temp != n - 1 && r != 1 && r != n - 1){
        r = MultMod(r, r, n);
        temp = temp << 1;
    }
    e=temp & 1;
    if (r != n - 1 && e == 0)
      return false;
  }
  return true;
}

/*bool m_r(ZZ n){
  ZZ i,b,r,aux;
  //int j=0,int B[5]={2,3,5,7,11};b= conv<ZZ> (B[j]);
  pii kq=k_q(n);
  b=XorShift(n-3)+2;
  //while (b<n){
    r=ExpMod(b,kq.second,n);
    cout  << "1 " <<   b << " " << kq.second << " " << n << endl;
    if (r==1){
      return true;
    }
    for (i=1;i<kq.first;i++){
      r=MultMod(r,r,n);
      cout << "2 " <<  r << " " << r  << " " << n << endl;
      if(r==(n-1)){
        return true;
      }
    }
    //j++;b= conv<ZZ> (B[j]);}
  return false;
}*/


