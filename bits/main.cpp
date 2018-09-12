#include <iostream>
#include <bitset>

using namespace std;

template  <std::size_t N>
bitset<2*N> multi(bitset<N> m, bitset<N> q){
  bitset<N>a(0); //acumulador
  int c=0;//acarreo
  bitset<N>qr(q);
  bitset<2*N>res(0); //resultado
  int cont=N;
  int j=0;

  while(cont!=0){
    if(q[j]==1){
      bitset<N> suma;
      for(int i=0; i<N; i++){
        suma[i]=((a[i] ^ m[i]) ^ c);
        c=((a[i] & m[i]) | ((a[i] ^ m[i]) & c));
      }
      a=suma;
    }
    int tmp=a[0];
    a>>=1;
    qr>>=1;
    qr[N-1]=tmp;
    a[N-1]=c;
    cont--;
    j++;
  }

  for(int i=0;i<2*N;i++){
    if(i<N)
      res[i]=qr[i];
    else
      res[i]=a[i-N];
  }
  return res;
}


int main(){
  bitset<4> mndo;
  bitset<4> mdor;
  cout<<"multiplicando: ";
  cin>>mndo;
  cout<<"multiplicador: ";
  cin>>mdor;

  cout<<multi(mndo,mdor);

  return 0;
}
