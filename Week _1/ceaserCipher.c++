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

int main(){
    int shift;
    string plain;
    cout<<"Text to be encrypted ..."<<endl;
    cin>>plain;
    cout<<"Shift Key ... "<<endl;
    cin>>shift;
    string enc = ceaserEncryption(plain,shift);
    cout<<"Encrypted Message : "<<enc<<endl;
    cout<<"DeCrypted Message : "<<ceaserDecryption(enc,shift)<<endl;
}