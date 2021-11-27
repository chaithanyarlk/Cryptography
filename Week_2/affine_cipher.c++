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

void plainTextAttack(string s,char p1,char p2,char c1, char c2){
    int a1 = p1-'A',a2 = p2-'A',b1 = c1-'A',b2= c2 - 'A';
    int res1,res2;
    if(a1>a2){
        res2 = b1-b2;
        res1 = a1-a2;
    }
    else{ 
        res2 = b2-b1;
        res1 = a2-a1;
    }
    if(res2<0)res2+=m;
    res1 = res1%m;
    res2 = res2%m;
    int p = modularInverseFinder(res1,m);
    int a = (res2*p)%m;
    p = a*a1;
    p = b1-p;
    int b;
    if(p<0){
        p = -p;
        b = p%m;
    }
    else{
        b = p%m;
    }
    cout<<a<<" "<<b<<endl;;
    cout<<affineDecryption(s,a,b);
    
    
}

int main(){
    string s = "ABCD";
    cout<<"Message ... "<<s<<endl;
    string enc = affineEncryption(s,17,15);
    cout<<"Encrypted Text ... "<<enc<<endl;
    cout<<"Decrypted Text ... "<<affineDecryption(enc,17,15)<<endl;
    plainTextAttack(enc,s[0],s[1],enc[0],enc[1]);
}
















