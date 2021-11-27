#include<bits/stdc++.h>
using namespace std;
#define PB push_back
map<char,int>m;
const string key = "BCDA";
vector<int>valArr;
#define n 4
char mat[n][n];
void setPermutation(string s){
    sort(s.begin(),s.end());
    for(int i = 0;i<s.size();i++){
        m[s[i]] = i;
    }
}
string transpositionEncryption(string s){
    setPermutation(key);
    int i = 0;
    int x = 0,y=0;
    while(i<s.size()){
        mat[x][y] = s[i];
        i++;
        if(y == 4){
            y = 0;x++;
        }
        else{
            y++;
        }
    }
    if(x == 4 && y== 4){
        
    }
    else{
        while(x <=4){
            mat[x][y] = '_';
            if( y == 4){
                y = 0;x ++;
            }
            else y++;
        }
    }
    // for(int i= 0;i<n;i++){
    //     for(int j = 0;j<n;j++){
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    string res ="";
    for(int i = 0;i<key.size();i++){
        valArr.PB(m[key[i]]);
        for(int j = 0;j<n;j++){
            res += mat[j][m[key[i]]];
        }
    }
    return res;
}
string decrypt(string s,vector<int>keyVal){
    int val = s.size();
    val = (int)sqrt(val);
    char mapper[val][val];
    for(int i = 0;i<val;i++){
        int k = 0;
        for(int j = i*val;j<val+(i*val);j++){
            mapper[k][keyVal[i]] = s[j];
            k++;
        }
    }
    string res ="";
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            res += mapper[i][j];
        }
    }
    return res;
}
void bruteForce(string s){
    vector<int>a;
    for(int i = 0;i<n;i++){
        a.PB(i);
    }
    do{
        cout<<decrypt(s,a)<<endl;
    }while(next_permutation(a.begin(),a.end()));
}
int main(){
    string s = "ABCDEFG";
    cout<<"Message "<<s<<endl;
    string enc = transpositionEncryption(s);
    cout<<"Encrypted Message ... "<<enc<<endl;
    cout<<"Decrypted Message ... "<<decrypt(enc,valArr)<<endl;
    cout<<"Brute Force"<<endl;
    bruteForce(enc);
}
















