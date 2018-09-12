#include <iostream>
#include <bitset>

using namespace std;

template  <std::size_t N>
bitset<2*N> multi(bitset<N> m, bitset<N> q){
    bitset<N>a(0);
    int c;
    bitset<2*N>res(0);
    int cont=N;

    while(cont!=0){
        if(q[0]==1){
            bitset<N> suma;
            for(int i=0; i<N; i++){
                suma[i]=((a[i] ^ m[i]) ^ c);
                c=((a[i] & m[i]) | ((a[i] ^ m[i]) & c));
            }
            a=suma;
        }
    int tmp=a[0];

    a>>=1;
    q>>=1;
    q[N-1]=tmp;
    a[N-1]=c;

    c=0;
    cont--;
    }

    for(int i=0;i<2*N;i++){
        if(i<N)
            res[i]=q[i];
        else
            res[i]=a[i-N];
    }
    return res;
}

template  <std::size_t N>
bitset<2*N> booth(bitset<N> m, bitset<N> q){
    bitset<N>a(0);
    int q1=q[0];
    bitset<2*N> res(0);
    int cont=N;

    while(cont!=0){
        if(q==1 && q1==0){
            int c=0;
            bitset<4> resta;
            bitset<4> suma;
            bitset<4> u(1);
            m1=~m;

            for(int i=0; i<4; i++){
                suma[i]=((m1[i] ^ u[i]) ^ c);
                c=((m1[i] & u[i]) | ((m1[i] ^ u[i]) & c));
            }

            bitset<4>res=suma;
            for(int i=0; i<4; i++){
                resta[i]=((suma[i] ^ a[i]) ^ c);
                c=((suma[i] & a[i]) | ((suma[i] ^ a[i]) & c));
            }
            suma=resta;

        }
        else if(q==0 && q1==1){
            bitset<N> suma;
            int c=0;
            for(int i=0; i<N; i++){
                suma[i]=((a[i] ^ m[i]) ^ c);
                c=((a[i] & m[i]) | ((a[i] ^ m[i]) & c));
            }
            a=suma;
        }
    }

}


int main(){
    bitset<4> mndo;
    bitset<4> mdor;
    cout<<"multiplicando: ";
    cin>>mndo;
    cout<<"multiplicador: ";
    cin>>mdor;

  //cout<<multi(mndo,mdor);
  cout<<suma;

  return 0;
}
