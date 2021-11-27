#include<bits/stdc++.h>
using namespace std;

string modifiedCeaserEncryption(string plain,int shift,int h){
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
        if(shift>=25)shift = 0;
        else shift += h;
    }
    return cipher_text;
}
string modifiedCeaserDecryption(string plain,int shift,int h){
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
        if(shift>=25)shift = 0;
        else shift += h;
    }
    return cipher_text;
}

int main(){
    int shift =3;
    string plain = "ABCD";
    int h = 3;
    string enc = modifiedCeaserEncryption(plain,shift,h);
    cout<<"Encrypted Message : "<<enc<<endl;
    cout<<"DeCrypted Message : "<<modifiedCeaserDecryption(enc,shift,h)<<endl;
}