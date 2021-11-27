#include<bits/stdc++.h>
using namespace std;
#define PB push_back
const int N = 256;

vector<int> keySchedulingAlgorithm(vector<int>key,int n){
    vector<int>S (N,0);
    vector<int>K (N,0);
    for(int i = 0;i<N;i++){
        S[i] = i;
        K[i] = key[i%N];
    }
    int j = 0;
    for(int i = 0;i<N;i++){
        j = (j+S[i]+K[i])%N;
        swap(S[i],S[j]);
    }
    int i = 0;j=0;
    vector<int>keyStream (n,0);
    int count = 0;
    while (count<n){
        i = (i+1)%N;
        j = (j+S[i])%N;
        swap(S[i],S[j]);
        int t = (S[i]+S[j])%N;
        keyStream[count] = S[t];
        count++;
    }
    return keyStream;
}
string XOR(string a ,string b){
    string res  = "";
    for(int i = 0;i<a.size();i++){
        if(a[i] == b[i])res+='0';
        else res += '1';
    }
    return res;
}
vector<string> encryptAlgo(string plain,vector<int>keyStream){
    int n =  plain.size();
    vector<string> res;
    cout<<"Encrypted Message ..."<<endl;
    for(int i = 0;i<n;i++){
        int val = plain[i];
        bitset<8> a(val);
        bitset<8> b(keyStream[i]);
        string c = XOR(a.to_string(),b.to_string());
        cout<<c;
        res.PB(c);
    }
    cout<<endl;
    return res;
}

void decryptAlgo(vector<string> cipher,vector<int>keyStream){
    int n =  cipher.size();
    cout<<"Decrypted Message ..."<<endl;
    for(int i = 0;i<n;i++){
        bitset<8> b(keyStream[i]);
        string c = XOR(cipher[i],b.to_string());
        int val = stoi(c,0,2);
        char a = val;
        cout<<a;
    }
}

vector<int> stringHelper(string key){
    int n = key.size();
    vector<int>K (n,0);
    for(int i = 0;i<n;i++){
        if(key[i] == '1')K[i] = 1;
    }
    return K;
}

int main(){
    string plain;
    string key;
    cout<<"Enter Message ..."<<endl;
    cin>>plain;
    cout<<"Enter the key in binary format ..."<<endl;
    cin>>key;
    vector<int>key_vec = stringHelper(key);
    vector<int>keyStream = keySchedulingAlgorithm(key_vec,plain.size());
    vector<string> cipher = encryptAlgo(plain,keyStream);
    decryptAlgo(cipher,keyStream);
}
