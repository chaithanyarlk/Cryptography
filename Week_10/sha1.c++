#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long int
// leftRotate operator takes vector and will rotate by n bits
map<string,string> m;
void init(){
     m["0000"] = "0";
     m["0001"] = "1";
     m["0010"] = "2";
     m["0011"] = "3";
     m["0100"] = "4"; 
     m["0101"] = "5";
     m["0110"] = "6";
     m["0111"] = "7";
     m["1000"] = "8";
     m["1001"] = "9";
     m["1010"] = "a";
     m["1011"] = "b";
     m["1100"] = "c";
     m["1101"] = "d";
     m["1110"] = "e";
     m["1111"] = "f";
}
vector<ll> leftRotate(vector<ll> arr, int n){
     for(int i = 0;i<n;i++){
          ll temp = arr[0];
          for(int j = 1;j<arr.size();j++)arr[j-1] = arr[j];
          arr[arr.size()-1] = temp;
     }
     return arr;
}
vector<ll> leftShift(vector<ll> arr,int n){
     vector<ll> res = arr;
     for(ll i =0;i<n;i++)res.PB(0);
     return res;
}

// This will pad 512 bits and return the vector
vector<ll> padding(vector<ll> text){
     vector<ll>padded (512,0);
     for(int i = 0;i<text.size();i++){
          padded[i] = text[i];
     }
     bitset<64> b(text.size());
     string x = b.to_string();
     cout<<x<<endl;
     int k = 0;
     for(int i = 448;i<512;i++){
          if(x[k] == '1')padded[i] = 1;
          else padded[i] = 0;
          k++;
     }
     cout<<endl;
     cout<<"Padded!"<<endl;
     for(ll i =0;i<padded.size();i++)cout<<padded[i];
     cout<<endl;
     return padded;
}
vector<ll> XOR(vector<ll>a,vector<ll>b){
     vector<ll>res;
     for(ll i =0;i<a.size();i++){
          if(a[i] == b[i])res.PB(0);
          else res.PB(1);
     }
     return res;
}
vector<ll> AND (vector<ll>a, vector<ll> b){
     vector<ll> res;
     for(ll i = 0;i<a.size();i++){
          if(a[i] == 1 && b[i] == 1)res.PB(1);
          else res.PB(0);
     }
     return res;
}
vector<ll> OR (vector<ll>a, vector<ll>b){
     vector<ll> res;
     for(ll i= 0 ;i<a.size();i++){
          if(a[i] == 0&& b[i] ==0)res.PB(0);
          else res.PB(1);
     }
     return res;
}
vector<ll> NOT (vector<ll>a){
     vector<ll> res;
     for(ll i = 0;i<a.size();i++){
          if(a[i] == 0)res.PB(1);
          else res.PB(0);
     }
     return res;
}
vector<ll> ADD32(vector<ll>a,vector<ll>b){
     ll c = 0;
     vector<ll> res;
     for(ll i = a.size()-1;i>=0;i--){
          if(c == 1){
               if(a[i] == 1 && b[i] == 1)res.PB(1);
               else if(a[i] == 0 && b[i] == 0){
                    res.PB(1); c = 0;
               }
               else res.PB(0);
          }
          else{
               if(a[i] == 1 && b[i] == 1){
                    res.PB(0);c = 1;
               }
               else if(a[i] == 0 && b [i] == 0)res.PB(0);
               else res.PB(1);
          }
     }
     return res;
}
vector<vector<ll>> generateWords(vector<ll> arr){
     vector<vector<ll>> words;
     // Done with the first 16 words
     for(ll i = 0;i<16;i++){
          vector<ll>temp;
          for(int j = 0;j<32;j++)temp.PB(arr[i*32+j]);
          words.PB(temp);
     }
     // Now doing with the remaining 80 - 16 = 64 words
     for(ll i = 16;i<80;i++){
          vector<ll>temp = XOR(XOR(XOR(words[i-3],words[i-8]),words[i-14]),words[i-16]);
          temp = leftRotate(temp,1);
          words.PB(temp);
     }
     for(ll i =0;i<words.size();i++){
          cout<<"Word "<<i<<endl;
          for(ll j = 0;j<words[i].size();j++)cout<<words[i][j];
          cout<<endl;
     }
     return words;
     // we have now all 80 words each of 32 bits 
}
vector<ll> hashFunction(vector<vector<ll>>words){
     vector<ll> a {0,1,1,0,0,1,1,1,0,1,0,0,0,1,0,1,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,1};
     vector<ll> b {1,1,1,0,1,1,1,1,1,1,0,0,1,1,0,1,1,0,1,0,1,0,1,1,1,0,0,0,1,0,0,1};
     vector<ll> c {1,0,0,1,1,0,0,0,1,0,1,1,1,0,1,0,1,1,0,1,1,1,0,0,1,1,1,1,1,1,1,0};
     vector<ll> d {0,0,0,1,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,1,0,1,0,0,0,1,1,1,0,1,1,0};
     vector<ll> e {1,1,0,0,0,0,1,1,1,1,0,1,0,0,1,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0};
     vector<ll> k,f;
     for(ll i = 0;i<80;i++){
          if(i>=0 && i<= 19){
               f = XOR(d,AND(b,XOR(c,d)));
               vector<ll> t {0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,0,0,1,1,1,1,0,0,1,1,0,0,1,1,0,0,1};
               k = t;
          }
          else if (i>=20 && i<=39){
               f = XOR(XOR(b,c),d);
               vector<ll> t {0,1,1,0,1,1,1,0,1,1,0,1,1,0,0,1,1,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1};
               k = t;
          }
          else if (i>= 40 && i<= 59){
               f = OR(AND(b,c),OR(AND(b,d),AND(c,d)));
               vector<ll> t {1,0,0,0,1,1,1,1,0,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,0,0};
               k = t;
          }
          else{
               f = XOR(XOR(b,c),d);
               vector<ll> t {1,1,0,0,1,0,1,0,0,1,1,0,0,0,1,0,1,1,0,0,0,0,0,1,1,1,0,1,0,1,1,0};
               k = t;
          }
          vector<ll> temp = ADD32(ADD32(ADD32(ADD32(leftRotate(a,5),f),e),k),words[i]);
          e = d;
          d = c;
          c = leftRotate(b,30);
          b = a;
          a = temp;
     }
     // vector<ll> h0 {0,1,1,0,0,1,1,1,0,1,0,0,0,1,0,1,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,1};
     // vector<ll> h1 {1,1,1,0,1,1,1,1,1,1,0,0,1,1,0,1,1,0,1,0,1,0,1,1,1,0,0,0,1,0,0,1};
     // vector<ll> h2 {1,0,0,1,1,0,0,0,1,0,1,1,1,0,1,0,1,1,0,1,1,1,0,0,1,1,1,1,1,1,1,0};
     // vector<ll> h3 {0,0,0,1,0,0,0,0,0,0,1,1,0,0,1,0,0,1,0,1,0,1,0,0,0,1,1,1,0,1,1,0};
     // vector<ll> h4 {1,1,0,0,0,0,1,1,1,1,0,1,0,0,1,0,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0};
     // h0 = ADD32(h0,a);
     // h1 = ADD32(h1,b);
     // h2 = ADD32(h2,c);
     // h3 = ADD32(h3,d);
     // h4 = ADD32(h4,e);
     // vector<ll> hh = OR(OR(OR(leftShift(h0,128),leftShift(h1,96)),OR(leftShift(h2,64),leftShift(h3,32))),h4);
     vector<ll> hh = OR(OR(OR(leftShift(a,128),leftShift(b,96)),OR(leftShift(c,64),leftShift(d,32))),e);

     return hh;
}
string binaryToHex(vector<ll> arr){
     string res= "";
     for(ll i = 0;i<arr.size();i = i+4){
          string temp = "";
          if(arr[i] == 1)temp+="1";
          else temp += "0";
          if(arr[i+1] == 1)temp += "1";
          else temp += "0";
          if(arr[i+2] == 1)temp+="1";
          else temp += "0";
          if(arr[i+3] == 1)temp += "1";
          else temp += "0";
          res += m[temp];
     }
     return res;

}
int main(){
     init();
     vector<ll> text {0,1,0,0,0,0,0,1};
     vector<ll> padded = padding(text);
     vector<vector<ll>> words = generateWords(padded);
     vector<ll> hashed = hashFunction(words);
     for(ll i =0;i<hashed.size();i++)cout<<hashed[i];
     cout<<endl;
     cout<<binaryToHex(hashed)<<endl;
}
