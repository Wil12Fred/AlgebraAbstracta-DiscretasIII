ZZ mersenne_state[624];

int m_index;

void MT(ZZ MAX_XOR){
  ZZ seed=XorShift(MAX_XOR);
  ZZ x,tmp,ans;
  string mult="18124332531873678163";
  ZZ aux(INIT_VAL,mult.c_str());
  m_index=0;
  mersenne_state[0] = seed*seed;
  for (int i=1;i<624;++i){
    x=mersenne_state[i-1]<<30;
    x=x % conv<ZZ>(MAX_XOR);
    tmp = mersenne_state[i-1];
    ans=aux;
    ans= x ^ tmp;
    mersenne_state[i] = abs(ans);
  }
}

void mt_regenerar(){
  ZZ e;
  for (int i=0;i<624;++i){
    ZZ y=(mersenne_state[i] & 0x80000000) +
      (mersenne_state[(i+1)%624] & 0x7fffffff);
    mersenne_state[i]=mersenne_state[(i+397)%624]^(y>>1);
    e=y & 1;
    if (e != 0){
      mersenne_state[i]=mersenne_state[i]^(2567483615);
    }
  }
}

ZZ mt_rand(){
  if (m_index==0) mt_regenerar();
  ZZ y=mersenne_state[m_index];
  y=y^(y>>1);
  y=y^(y<<7 & (conv<ZZ>(2646928640)));
  y=y^(y<<15 & (conv<ZZ>(4022730752)));
  m_index++;
  m_index = m_index%624;
  return y;
}
