#include<bits/stdc++.h>
using namespace std;
#define ll long long int

string Encryption(string plain,int shift){
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
string Decryption(string plain,int shift){
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
     ll p,g,a,b,x,y,key_a,key_b,e,key_eve_a,key_eve_b,eve;
     p = 103;
     g = 9;
     a = 4;
     b = 5;
     e = 6;
     x = pow(g,a);x = x%p;
     y = pow(g,b);y = y%p;
     eve = pow(g,e);eve = eve%p;
     key_a = pow(eve,a);key_a = key_a%p;
     key_eve_a = pow(x,e);key_eve_a = key_eve_a%p;
     key_b = pow(eve,b);key_b = key_b%p;
     key_eve_b = pow(y,e);key_eve_b = key_eve_b%p;
     string messageA = "hello";
     cout<<"A has shared private key as "<<key_a<<endl;
     cout<<"B has shared private key as "<<key_b<<endl;
     cout<<"Eve has shared private key with A as "<<key_eve_a<<endl;
     cout<<"Eve has shared private key with B as "<<key_eve_b<<endl;
     cout<<"A sends message to B : "<<messageA<<" Encrypted form is "<<Encryption(messageA,key_a)<<endl;
     cout<<"Eve can decrypt the message from A to B. Decrypted message is "<<Decryption(Encryption(messageA,key_a),key_eve_a)<<endl;
     cout<<"Eve can modify or replay with B with same message Eve sends hellob. Encrypted Form is "<<Encryption("hellob",key_eve_b)<<endl;
     cout<<"B recieves message from Eve and assumes it from A. Decrypted message is "<<Decryption(Encryption("hellob",key_eve_b),key_b)<<endl;
     cout<<"A sends message encrypted to B which will be recieved by Eve"<<endl;
     cout<<"Eve can decrypt it as the shared private key between A and Eve matches and can manipulate and send to B"<<endl;
     cout<<"Similar is the case with B and Eve"<<endl;
}