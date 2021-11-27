#include<bits/stdc++.h>
using namespace std;
#define PB push_back
const int m = 26;


int modularInverseFinder(int a, int n){
    for(int i = 1;i<n;i++){
        if(((a%n)*(i%n))%n == 1)
        return i;
    }
}
string affineEncryption(string s,int a,int b){
    string res = "";
    for(int i = 0;i<s.length();i++){
        if(s[i]>='A'&&s[i]<='Z'){
            int temp = s[i]-'A';
            temp = ((temp*a)+b)%m;
            char c = (temp+'A');
            res += c;
        }
        else{
            res += s[i];
        }
    }
    return res;
}
string affineDecryption(string s,int a,int b){
    int ainv =  modularInverseFinder(a,m);
    string res ="";
    for(int i = 0;i<s.size();i++){
        if(s[i]>='A'&&s[i]<='Z'){
            int temp = (((ainv * ((s[i]+'A' - b)) % 26)) + 'A');
            char c = temp;
            res += c;
        }
        else res+=s[i];
    }
    return res;
}
void bruteForce(string s){
    vector<int>a_pos;
    for(int i = 2 ;i<m;i++){
        if(__gcd(m,i) == 1)a_pos.PB(i);
    }
    cout<<"Brute Force Approach!"<<endl;
    for(auto iter = a_pos.begin();iter!=a_pos.end();iter++){
        for(int i = 0;i<26;i++){
            cout<<"When a = "<<*iter<<" and b = "<<i<<" ";
            cout<<affineDecryption(s,*iter,i)<<endl;
        }
    }
    
}


int main(){
    string s = "ABCD";
    cout<<"Message ... "<<s<<endl;
    string enc = affineEncryption(s,17,15);
    cout<<"Encrypted Text ... "<<enc<<endl;
    cout<<"Decrypted Text ... "<<affineDecryption(enc,17,15)<<endl;
    bruteForce(enc);
}
















