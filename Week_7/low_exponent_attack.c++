#include<bits/stdc++.h>
#include <chrono>
using namespace std;
#define ll long long int
using namespace std::chrono;

int main(){
     ll p,q,e,d,n,phin;
     p = 103;q = 101;n=p*q;
     phin = (p-1)*(q-1);
     vector<ll>arr;
     // to store the values of e
     for(ll i  = 2;i<phin;i++){
          if(__gcd(phin,i) == 1)arr.push_back(i);
     }
     ll msg = 12;
     auto start = high_resolution_clock::now();
     for(int j = 0;j<arr.size();j++){
          e = arr[j];
          cout<<"This is e "<<e<<endl;
          ll cipher = pow(msg,e);
          cipher = cipher % n;
          ll decrypt = -1;
          for(ll i = 0;i<n &&decrypt != msg;i++){
               d = i;
               decrypt = pow(cipher,d);
               decrypt = decrypt%n;
          }
          if(d != n)
          cout<<d<<endl;
     }
     auto stop = high_resolution_clock::now();
     auto duration = duration_cast<microseconds>(stop - start);
     cout<<"Time taken for breaking 3 digit RSA where if we use low exponent d is "<<duration.count()<<" microseconds"<<endl;    
}