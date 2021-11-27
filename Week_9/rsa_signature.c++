#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll extended_eucledian(ll a, ll b){
     ll q, r, t, t1 = 0, t2 = 1, n = a;
     if(__gcd(a,b)!=1)return -1;
     while(b!=0){
          q = floor(a/b);
          r = a - (b*q);
          t = t1 - (q*t2);
          a = b;b= r;t1= t2;t2 = t;
     }
     if (t1<0)t1 = t1+n;
     return t1;
}
ll power(ll a, ll n, ll b){
     ll res = a;
     for(ll i = 2;i<=n;i++){
          res = ((res%b)*(a%b))%b;
     }
     return res;
}

int main(){
     ll p,q,n,e,d,M,totient;
     cout<<"Enter prime p"<<endl;
     cin>>p;
     cout<<"Enter prime q"<<endl;
     cin>>q;
     cout<<"Enter Message M"<<endl;
     cin>>M;
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
     d = extended_eucledian(totient,e);
     cout<<"D "<<d<<endl;
     cout<<"The public Key will be { "<<e<<","<<n<<" }"<<endl;
     cout<<"The private Key will be { "<<d<<","<<n<<" }"<<endl;
     cout<<"Message from Alice is "<<M<<endl;
     ll S = power(M,d,n);
     if(S<0)S += n;
     ll M1 = power(S,e,n);
     if(M1<0)M1 = M1+n;
     cout<<"Signature value after decrypting is  "<<M1<<endl;
     if(M1 == M)cout<<"Digital Signature Verified!"<<endl;
     else cout<<"Digital Signature Invalid!"<<endl;
}