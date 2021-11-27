#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back

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

ll publicKeyGeneratorElagmal(ll g,ll p, ll x){
     ll temp = pow(g,x);
     return temp%p;
}

vector<ll> signatureGenerator(ll m, ll g,ll p, ll k, ll x){
     ll r = pow(g,k);
     r = r%p;
     ll s = (m - x*r)*extended_eucledian(p-1,k);
     s = s % (p-1);
     if (s<0) 
     s = s + (p-1);
     vector<ll>a;
     a.PB(r);
     a.PB(s);
     return a;
}
ll signatureVerification(ll y, ll r, ll s, ll m, ll g, ll p){
     ll left = pow(g, m);
     left = left%p;
     ll right = pow(y,r);
     right = right* pow(r,s);
     right = right % p ;
     if(right<0)right = right + p;
     if(left == right)return 1;
     return 0;
}

int main(){
     ll p = 19,g = 10,k = 5,m = 14,x = 16;
     cout<<"Enter the prime p"<<endl;
     cin>>p;
     cout<<"Enter the generator g"<<endl;
     cin>>g;
     cout<<"Enter secret key x"<<endl;
     cin>>x;
     cout<<"Enter Message m"<<endl;
     cin>>m;
     cout<<"Enter value of k"<<endl;
     cin>>k;
     cout<<"The prime used is "<<p<<" generator used is "<<g<<" private key is "<<x<<endl;
     ll y = publicKeyGeneratorElagmal(g,p,x);
     cout<<"Public key is {"<<p<<","<<g<<","<<y<<"}"<<endl;
     vector<ll> a = signatureGenerator(m,g,p,k,x);
     ll r = a[0];
     ll s = a[1];
     cout<<"The signature is ("<<r<<","<<s<<")"<<endl;
     if(signatureVerification(y,r,s,m,g,p) == 1)cout<<"Signature is verified!"<<endl;
     else cout<<"Signature is Invalid!"<<endl;
}