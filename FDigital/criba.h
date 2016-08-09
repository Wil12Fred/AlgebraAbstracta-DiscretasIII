#define MAXI 200000002
int Criba[MAXI];

void eratotenes( vector<int>* Primes){
  Criba[4]=Criba[6]=2;
  Primes->push_back(2);
  Primes->push_back(3);
  Primes->push_back(5);
  int R[]={4,2,4,2,4,6,2,6};
  for (int i=7,cur=0;i<MAXI;i+=R[cur++&7]){
    if(!Criba[i]){
      Primes->push_back(i);
      for (int j=i*i;j<=MAXI;j+=2*i)
        Criba[j]=i;
      }
  }
  return;
}

void facEratostenes(int N,map<int,int> * primeFactors){
  while (Criba[N]!=0){
    N/=Criba[N];
    (*primeFactors)[Criba[N]]++;
  }
  (*primeFactors)[N]++;
  return;
}

void FactorOut(ZZ &N,int &p){
  while (N % p==0){
    N/=p;
  }
}

bool isSmooth(ZZ N,vector<int>*P){
  for (int i=0;i<P->size();i++){
    FactorOut(N,(*P)[i]);
  }
  if (N==1){
    return true;
  }
  return false;
}
