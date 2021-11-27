#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
string generateKey(string key,int n){
    string gen ="";
    int i = 0;
    int count = 0;
    int len = key.size();
    while(count<n){
        if(i == len)i=0;
        gen += key[i];
        i++;
        count++;
    }
    return gen;
}
string vigEncryption(string text,string key){
    string res ="";
    for(int i = 0;i<text.size();i++){
        char temp = (text[i]+key[i])%26;
        temp+='A';
        res+=temp;
    }
    return res;
}
string vigDecryption(string cipher,string key){
    string res = "";
    for(int i = 0;i<cipher.size();i++){
        char temp = (cipher[i]-key[i]+26)%26;
        temp+='A';
        res+=temp;
    }
    return res;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string key ;
    string text ;
    cout<<"Enter Text to Encrpty ..."<<endl;
    cin>>text;
    cout<<"Key ..."<<endl;
    cin>>key;
    string Vig_Key = generateKey(key,text.size());
    string enc = vigEncryption(text,Vig_Key);
    cout<<"Encrypted Message "<<enc<<endl;
    cout<<"Decrypted Message "<<vigDecryption(enc,Vig_Key)<<endl;
}