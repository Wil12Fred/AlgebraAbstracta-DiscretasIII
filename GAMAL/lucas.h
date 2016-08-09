//si p=compuesto entonces M(p) es compuesto
bool lucas(ZZ p){
	ZZ i;
	if (!m_r(p,5)) return false;
  cout << "pase" << endl;
  ZZ r ,Mp;
	Mp=ExpMod(conv<ZZ>(2),p)-1;
  cout << "Mp=" << Mp << endl;
  r=4;
  cout << r << endl;
	for (i=2; i<p; i++) {
    r=(MultMod(r,r,Mp)-2) % Mp;
    cout << r << endl;
	}
	if (r==0) return true;
  return false;
}
