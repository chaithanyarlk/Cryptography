#include<bits/stdc++.h>
using namespace std;
#define PB push_back
map<char,string>hbmap;
map<string,char>bhmap;
const int N = 64;
vector<int> pbox  {32, 1, 2, 3, 4, 5, 4, 5,6, 7, 8, 9, 8, 9, 10, 11,12, 13, 12,13, 14, 15, 16, 17,16, 17, 18, 19, 20, 21, 20, 21,22, 23, 24, 25, 24, 25, 26, 27,28, 29, 28, 29, 30, 31, 32, 1};
vector<int> init_perm { 58, 50, 42, 34, 26, 18, 10, 2,60, 52, 44, 36, 28, 20, 12, 4,62, 54, 46, 38, 30, 22, 14, 6,64, 56, 48, 40, 32, 24, 16, 8,57, 49, 41, 33, 25, 17, 9, 1,59, 51, 43, 35, 27, 19, 11, 3,61, 53, 45, 37, 29, 21, 13, 5,63, 55, 47, 39, 31, 23, 15, 7 };
vector<int>final_perm { 40, 8, 48, 16, 56, 24, 64, 32,39, 7, 47, 15, 55, 23, 63, 31,38, 6, 46, 14, 54, 22, 62, 30,37, 5, 45, 13, 53, 21, 61, 29,36, 4, 44, 12, 52, 20, 60, 28,35, 3, 43, 11, 51, 19, 59, 27,34, 2, 42, 10, 50, 18, 58, 26,33, 1, 41, 9, 49, 17, 57, 25 };
vector<int>keycompress { 14, 17, 11, 24, 1, 5,3, 28, 15, 6, 21, 10,23, 19, 12, 4, 26, 8,16, 7, 27, 20, 13, 2,41, 52, 31, 37, 47, 55,30, 40, 51, 45, 33, 48,44, 49, 39, 56, 34, 53,46, 42, 50, 36, 29, 32 };
vector<int>keyparity {57, 49, 41, 33, 25, 17, 9,1, 58, 50, 42, 34, 26, 18,10, 2, 59, 51, 43, 35, 27,19, 11, 3, 60, 52, 44, 36,63, 55, 47, 39, 31, 23, 15,7, 62, 54, 46, 38, 30, 22,14, 6, 61, 53, 45, 37, 29,21, 13, 5, 28, 20, 12, 4};
vector<int>straight { 16, 7, 20, 21,29, 12, 28, 17,1, 15, 23, 26,5, 18, 31, 10,2, 8, 24, 14,32, 27, 3, 9,19, 13, 30, 6,22, 11, 4, 25 };
const int S[8][4][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
                    0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
                    4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
                    15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 },
                    { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
                    3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
                    0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
                    13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 },
                    { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
                    13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
                    13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
                    1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 },
                    { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
                    13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
                    10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
                    3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 },
                    { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
                    14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
                    4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
                    11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 },
                    { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
                    10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
                    9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
                    4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 },
                    { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
                    13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
                    1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
                    6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 },
                    { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
                    1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
                    7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
                    2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };
void init(){
    hbmap['0'] = "0000";
    hbmap['1'] = "0001";
    hbmap['2'] = "0010";
    hbmap['3'] = "0011";
    hbmap['4'] = "0100";
    hbmap['5'] = "0101";
    hbmap['6'] = "0110";
    hbmap['7'] = "0111";
    hbmap['8'] = "1000";
    hbmap['9'] = "1001";
    hbmap['A'] = "1010";
    hbmap['B'] = "1011";
    hbmap['C'] = "1100";
    hbmap['D'] = "1101";
    hbmap['E'] = "1110";
    hbmap['F'] = "1111";
    bhmap["0000"] = '0';
    bhmap["0001"] = '1';
    bhmap["0010"] = '2';
    bhmap["0011"] = '3';
    bhmap["0100"] = '4';
    bhmap["0101"] = '5';
    bhmap["0110"] = '6';
    bhmap["0111"] = '7';
    bhmap["1000"] = '8';
    bhmap["1001"] = '9';
    bhmap["1010"] = 'A';
    bhmap["1011"] = 'B';
    bhmap["1100"] = 'C';
    bhmap["1101"] = 'D';
    bhmap["1110"] = 'E';
    bhmap["1111"] = 'F';
}
string hextoBin(string s){
    string res = "";
    for(int i = 0;i<s.size();i++){
        res+=hbmap[s[i]];
    }
    return res;
}
string bintoHex(string s){
    string res = "";
    int i = 0;
    while(i<s.size()){
        string r = "";
        r += s[i];
        r += s[i+1];
        r += s[i+2];
        r += s[i+3];
        i+=4;
        res+=bhmap[r];
    }
    return res;
}
string permutationAlgo(string s,vector<int>arr,int n){
    string res= "";
    for(int i= 0;i<n;i++){
        res+=s[arr[i]-1];
    }
    return res;
}
string XOR(string a ,string b){
    string res = "";
    for(int i = 0;i<a.size();i++){
        if(a[i] == b[i])res+='0';
        else res += '1';
    }
    return res;
}
string leftShift (string s, int shift){
    for(int i = 0;i<shift;i++){
        string temp = "";
        for(int i = 1;i<s.size();i++){
            temp += s[i];
        }
        temp+=s[0];
        s = temp;
    }
    return s;
}
void roundKeysGenerator(string key,vector<string>&roundkeysBin,vector<string>&roundkeysHex){
    string left = key.substr(0,28);
    string right = key.substr(28,56);
    for(int i = 1;i<=16;i++){
        if(i == 1||i==2|| i==9 || i==16){
            left = leftShift(left,1);
            right = leftShift(right,1);
        }
        else{
            left = leftShift(left,2);
            right = leftShift(right,2);
        }
        string org = left+right;
        string keygen = permutationAlgo(org,keycompress,48);
        roundkeysBin.PB(keygen);
        roundkeysHex.PB(bintoHex(keygen));
    }
}
string sBoxHelper(string s,int n){
    int row = 2*(int(s[n*6]-'0'))+int(s[n*6+5]-'0');
    int col = 8*(int(s[n*6+1]-'0'))+4*(int(s[n*6+2]-'0'))+2*(int(s[n*6+3]-'0'))+(int(s[n*6+4]-'0'));
    int temp = S[n][row][col];
    bitset<4>b(temp);
    return b.to_string();
}
string encryptionAlgo(string plain,vector<string>&roundkeysBin,vector<string>&roundkeysHex){
    string plainBin = hextoBin(plain);
    cout<<"Message in binary ..."<<plainBin<<endl;
    string plainInitPer = permutationAlgo(plainBin,init_perm,N);
    string left = plainInitPer.substr(0,32);
    string right = plainInitPer.substr(32,64);
    //cout<<"Left "<<left<<" Right "<<right<<endl;
    for(int i = 0;i<16;i++){
        string right_exp = permutationAlgo(right,pbox,pbox.size());
        string rightres = XOR(right_exp,roundkeysBin[i]);
        //cout<<"Right after XOR key "<<rightres<<endl;
        string res ="";
        for(int i = 0;i<8;i++){
            res += sBoxHelper(rightres,i);
        }
        //cout<<"result after SBOX "<<res<<endl;
        res = permutationAlgo(res,straight,32);
        //cout<<"Result after permuation "<<res<<endl;
        left = XOR(res,left);
        //cout<<"XOR final result "<<left<<endl;
        if(i!=15){
            swap(left,right);
        }
        //cout<<"Swap result "<<left<<right<<endl;
        cout<<"Round "<<i+1<<endl;
        cout<<"\t"<<"Key used is "<<roundkeysHex[i]<<endl;
        cout<<"\t"<<"Left Part in binary "<<left<<" in Hex "<<bintoHex(left)<<endl;
        cout<<"\t"<<"Right Part in binary "<<right<<" in Hex "<<bintoHex(right)<<endl;
    }
    string final_str = left+right;
    final_str = permutationAlgo(final_str,final_perm,64);
    return bintoHex(final_str);
}
string decryptHelper(string cipher,vector<string>&roundkeysBin,vector<string>&roundkeysHex){
    reverse(roundkeysBin.begin(),roundkeysBin.end());
    reverse(roundkeysHex.begin(),roundkeysHex.end());
    return encryptionAlgo(cipher,roundkeysBin,roundkeysHex);
}
void bruteForce(string cipher){
     cout<<"BruteForce begins ..."<<endl;
     int t = int(pow(2,56));
     for(int i = 0;i<t;i++){
          bitset<56>b(i);
          vector<string>roundkeysBin,roundkeysHex;
          roundKeysGenerator(b.to_string(),roundkeysBin,roundkeysHex);
          string d = decryptHelper(cipher,roundkeysBin,roundkeysHex);
          cout<<"Decryption due to 56 bit key "<<b.to_string()<<" "<<d<<endl;
     }
}

int main(){
    init();
    string plain, key;
    plain = "9955ABCD11228855";
    key = "1023ACDBCA2525";
    cout<<"Message ... "<<plain<<endl;
    cout<<"Key ... "<<key<<endl;
    string keyBin = hextoBin(key);
    cout<<"Key in binary ..."<<keyBin<<endl;
    string key_56 = permutationAlgo(keyBin,keyparity,56);
    cout<<"Permuatated key 56 bit ..."<<key_56<<endl;
    vector<string>roundkeysBin,roundkeysHex;
    roundKeysGenerator(key_56,roundkeysBin,roundkeysHex);
    cout<<"Encryption Begins ..."<<endl;
    string cipher = encryptionAlgo(plain,roundkeysBin,roundkeysHex);
    cout<<"Encrypted String ... "<<cipher<<endl;
    cout<<"Decryption Begins ..."<<endl;
    string decrypt = decryptHelper(cipher,roundkeysBin,roundkeysHex);
    cout<<"Decrypted Message ... "<<decrypt<<endl;
    bruteForce(cipher);
}

















