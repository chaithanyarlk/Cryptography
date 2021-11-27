#include<bits/stdc++.h>
using namespace std;
#define PB push_back

vector<char> streamMaker(int n,int m1,int m2,int p1,int p2){
    vector<int>s1(m1,1);
    s1[0] = 0;s1[p1] = 0;s1[m1-1-p1]=0;s1[p1+1] = 0;
    vector<int>s2(m2,1);
    s2[0] = 0;s2[p2] = 0;s2[m2-1-p2] = 0;s2[p2+1] = 0;
    
    vector<char>stream;
    for(int i = 0;i<n;i++){
        if(s1[m1-1] == s2[m2-1])stream.PB('0');
        else stream.PB('1');
        int val = (s1[m1-1] == s1[p1]&& s1[m1-1] == s1[m1-1-p1])?1:0;
        s1[p1] = s1[p1] == 0?1:0;
        for(int j = 1;j<m1;j++){
            s1[j] = s1[j-1];
        }
        s1[0] = val;
        if(p1 == m1-1)p1=0;
        else p1++;
        val = (s2[m2-1] == s2[p2])?0:1;
        s2[p2] = s2[p2] == 0?1:0;
        for(int j = 1;j<m2;j++){
            s2[j] = s2[j-1];
        }
        s2[0] = val;
        if(p2 == m2-1)p2=0;
        else p2++;
        
    }
    return stream;
    
}
char XOR(int a,char b){
    if((a == 1&& b =='1')||(a == 0&& b =='0'))return '0';
    else return '1';
}
string encrypt(string plain,vector<char>stream){
    string res = "";
    int n = plain.size();
    for(int i = 0;i<n;i++){
        res += (stream[i]^plain[i])+'0';
    }
    return res;
}
string decrypt(string cipher,vector<char>stream){
    string res = "";
    int n = cipher.size();
    for(int i = 0;i<n;i++){
        res += ((stream[i]-'0')^(cipher[i]-'0'))+'0';
    }
    return res;
}

int main(){
    string plain ;
    cout<<"Enter Message ..."<<endl;
    cin>>plain;
    int m1 = 5,m2 =8,p1= 3,p2 = 4;
    vector<char> stream = streamMaker(plain.size(),m1,m2,p1,p2);
    string cipher = encrypt(plain,stream);
    cout<<"Encrypted Message ..."<<cipher<<endl;
    cout<<"Decrypted Message ..."<<decrypt(cipher,stream)<<endl;
    stream = streamMaker(32,m1,m2,p1,p2);
    cout<<"Stream Verification and Analysis!"<<endl;
    for(int i = 0;i<stream.size();i++)
    cout<<stream[i];
    cout<<endl;
    cout<<"This is for 32 iterations and stream did not repeat itself yet";
}










