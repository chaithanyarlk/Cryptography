#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
     ll p,g,a,b,x,y,key_a,key_b;
     p = 103;
     g = 9;
     a = 4;
     b = 5;
     x = pow(g,a);x = x%p;
     y = pow(g,b);y = y%p;
     cout<<"A sends public key to B "<<x<<endl;
     cout<<"B sends public key to A "<<y<<endl;
     key_a = pow(y,a);key_a = key_a%p;
     key_b = pow(x,b);key_b = key_b%p;
     cout<<"Shared key at A is "<<key_a<<" Shared key at B is "<<key_b<<endl;
     cout<<"Shared key is "<<key_a<<endl;

}