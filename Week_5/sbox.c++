#include<bits/stdc++.h>
using namespace std;
map<string,string>bhmap;
#define RTL(x,shift) ((uint8_t) ((x) << (shift)) | ((x) >> (8 - (shift))))

void SBOX(uint8_t sbox[256]) {
	uint8_t p = 1, q = 1;
	do {
		p = p ^ (p << 1) ^ (p & 0x80 ? 0x1B : 0);
		q ^= q << 1;
		q ^= q << 2;
		q ^= q << 4;
		q ^= q & 0x80 ? 0x09 : 0;
		sbox[p] = 0x63 ^ q ^ RTL(q, 1) ^ RTL(q, 2) ^ RTL(q, 3) ^ RTL(q, 4);
	} while (p != 1);
	sbox[0] = 0x63;
}
void init(){
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
string bintoHexHelper(string s){
     string res = "";
     int i = 0;
     while(i<s.size()){
          string temp = "";
          temp += s[i];
          temp += s[i+1];
          temp += s[i+2];
          temp += s[i+3];
          i = i+4;
          res+=bhmap[temp];
     }
     return res;
}

int main(){
     init();
     uint8_t sbox[256];
     SBOX(sbox);
     int count = 0;
     while(count<256){
          int t = sbox[count];
          bitset<8>b(t);
          cout<<bintoHexHelper(b.to_string())<<" ";
          count ++;
          if(count%16 == 0)cout<<endl;
     }
}