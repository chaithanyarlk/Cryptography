#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll modinverse(ll a,ll b){
     for(ll i = 1;i<b;i++){
          if(((a%b)*(i%b))%b == 1)return i;
     }
     return 0;
}

int main(){
     ll p,q,n,e,d,msg,totient;
     cout<<"Enter the value of P which must be prime!"<<endl;
     cin>>p;
     cout<<"Enter the value of Q which must be prime!"<<endl;
     cin>>q;
     cout<<"Enter the integer message!"<<endl;
     cin>>msg;
     n = p*q;
     totient = (p-1)*(q-1);
     int stop = 0;
     for(ll i = 2;i<totient&&stop == 0;i++){
          if(__gcd(totient,i) == 1){
               e = i;
               stop = 1;
          }
     }
     cout<<"E "<<e<<endl;
     d = modinverse(e,totient);
     cout<<"D "<<d<<endl;
     ll cipher,decrypt;
     cipher = pow((float)msg,(float)e);
     cipher = cipher%n;
     decrypt = pow((float)cipher,(float)d);
     decrypt = decrypt%n;
     cout<<"The public Key will be { "<<e<<","<<n<<" }"<<endl;
     cout<<"The private Key will be { "<<d<<","<<n<<" }"<<endl;
     cout<<"Encrypted Message is "<<cipher<<endl;
     cout<<"Decrypted Message is "<<decrypt<<endl;
}