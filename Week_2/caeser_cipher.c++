#include<bits/stdc++.h>
using namespace std;

string ceaserEncryption(string plain,int shift){
    string cipher_text = "";
    int temp;
    for(int i = 0;i<plain.size();i++){
        if(plain[i]>='A' && plain[i]<='Z'){
            temp = (plain[i]-int('A')+shift)%26;
            cipher_text += char(temp+int('A'));
        }
        else{
            temp = (plain[i]-int('a')+shift)%26;
            cipher_text += char(temp+int('a'));
        }
    }
    return cipher_text;
}
string ceaserDecryption(string plain,int shift){
    string cipher_text = "";
    int temp;
    for(int i = 0;i<plain.size();i++){
        if(plain[i]>='A' && plain[i]<='Z'){
            temp = (plain[i]-int('A')-shift);
            if(temp<0)temp = temp+26;
            temp = temp%26;
            cipher_text += char(temp+int('A'));
        }
        else{
            temp = (plain[i]-int('a')-shift)%26;
            if(temp<0)temp = temp+26;
            temp = temp%26;
            cipher_text += char(temp+int('a'));
        }
    }
    return cipher_text;
}

void bruteForce(string s){
    cout<<"Brute Force Approach ..."<<endl;
    for(int i = 0;i<26;i++){
        cout<<"When shift is "<<i<< " Then word is "<<ceaserDecryption(s,i)<<endl;
    }
}

int main(){
    int shift = 3;
    string plain = "ABCD";
    string enc = ceaserEncryption(plain,shift);
    cout<<"Encrypted Message : "<<enc<<endl;
    cout<<"DeCrypted Message : "<<ceaserDecryption(enc,shift)<<endl;
    bruteForce(enc);
}