#include<bits/stdc++.h>
using namespace std;
#define ll long long int

string XOR(string a,string b){
     string res ="";
     for(int i = 0;i<a.size();i++){
          if(a[i] == b[i])
          res+="0";
          else
          res += "1";
     }
     return res;
}
string leftShiftCircular(string a){
     char t = a[0];
     for(int i = 0;i<a.size()-1;i++)a[i]=a[i+1];
     a[a.size()-1] = t;
     return a;
}
string rightShiftCircular(string a){
     char t = a[a.size()-1];
     for(int i = a.size()-1;i>0;i--)a[i]=a[i-1];
     a[0] = t;
     return a;
}
int hashCodeGeneratorEncrypt(int a,int p){
     bitset<64>b(a);
     bitset<64>b1(p);
     string key = b1.to_string();
     string text = b.to_string();
     text = XOR(text,key);
     return stoi(text, 0, 2);
}
int hashCodeGeneratorDecrypt(int a,int p){
     bitset<64>b(a);
     bitset<64>b1(p);
     string key = b1.to_string();
     string text = b.to_string();
     text = XOR(text,key);
     return stoi(text, 0, 2);
}

int main(){
     ll p,g,a,b,x,y,key_a,key_b;
     p = 103;
     g = 9;
     a = 4;
     b = 5;
     x = pow(g,a);x = x%p;
     y = pow(g,b);y = y%p;
     int t1 = hashCodeGeneratorEncrypt(x,p);
     int t2 = hashCodeGeneratorDecrypt(t1,p);
     cout<<"Hash Code sent "<<t1<<" Hash Code Verified "<<t2<<endl;
     cout<<"A sends public key to B "<<x<<endl;
     cout<<"B sends public key to A "<<y<<endl;
     key_a = pow(y,a);key_a = key_a%p;
     key_b = pow(x,b);key_b = key_b%p;
     cout<<"Shared key at A is "<<key_a<<" Shared key at B is "<<key_b<<endl;
     cout<<"Shared key is "<<key_a<<endl;

}