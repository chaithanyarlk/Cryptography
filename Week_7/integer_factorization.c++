#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// In RSA P Q I need to guess the Phi(n) from the public Key
// Phi(n) = euler totient which is (p-1)*(q-1)
// n = p*q
int main(){
     ll n = 103*101;
     ll a = ceil(sqrt(n));
     ll b = a*a - n;
     ll t = floor(sqrt(b));
     while(t*t != b){
          a++;
          b = a*a - n;
          t = floor(sqrt(b));
     }
     cout<<a-t<<" "<<a+t<<endl;
}