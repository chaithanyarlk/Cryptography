#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long int
map<char,string>m;
void init(){
     m['0'] = "0000";
     m['1'] = "0001";
     m['2'] = "0010";
     m['3'] = "0011";
     m['4'] = "0100";
     m['5'] = "0101";
     m['6'] = "0110";
     m['7'] = "0111";
     m['8'] = "1000";
     m['9'] = "1001";
     m['A'] = "1010";
     m['B'] = "1011";
     m['C'] = "1100";
     m['D'] = "1101";
     m['E'] = "1110";
     m['F'] = "1111";
}
vector<ll> galoisMulitplication (string a, string b){
     string aBin ="";
     string bBin = "";
     aBin += m[a[0]];aBin += m[a[1]];
     bBin += m[b[0]];bBin += m[b[1]];
     cout<<aBin<<" "<<bBin<<endl;
     vector<ll>arr(15,0);
     for(int i = 0;i<bBin.size();i++){
          for(int j = 0;j<aBin.size();j++){
               if(aBin[j] == '1' && bBin[i] == '1'){
                    if(arr[(bBin.size()-1-i)+(aBin.size()-1-j)] == 0)
                    arr[(bBin.size()-1-i)+(aBin.size()-1-j)] = 1;
                    else
                    arr[(bBin.size()-1-i)+(aBin.size()-1-j)] = 0;
               }
          }
     }
     
     reverse(arr.begin(),arr.end());
     for(int i = 0;i<arr.size();i++)
     cout<<arr[i]<<" ";
     cout<<endl;
     return arr;
}
vector<ll> galoisDivision(vector<ll> polynomial){
     for(int i = 0;i<polynomial.size();i++)
     cout<<polynomial[i]<<" ";
     cout<<endl;
     vector<ll>aes {1,0,0,0,1,1,0,1,1};
     for(int i = 0;i<9;i++){
          cout<<"Current i "<<i<<endl;
          if(polynomial[i] == 1){
               for(int j = 0;j<aes.size();j++)
               {if(polynomial[i+j] == 1 && aes[j] == 1) polynomial[i+j] = 0;
               else if(polynomial[i+j] == 0 && aes[j] == 1) polynomial[i+j] = 1;
               }
          }
          for(int k = 0;k<polynomial.size();k++)
          cout<<polynomial[k]<<" ";
          cout<<endl;
     }
     for(int i = 0;i<polynomial.size();i++)
     cout<<polynomial[i]<<" ";
     cout<<endl;
     return polynomial;
}

int main(){
     init();
     vector<ll> arr = galoisMulitplication("FF","03");
     arr = galoisDivision(arr);
}