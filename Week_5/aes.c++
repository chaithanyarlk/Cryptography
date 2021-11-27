#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define PB push_back
map<char,string>hbmap;
map<string,string>bhmap;
vector<string>W0,W1,W2,W3;
string SBOX [16][16] = {
        {"63", "7C", "77", "7B", "F2", "6B", "6F", "C5", "30", "01", "67", "2B", "FE", "D7", "AB", "76"},
        {"CA", "82", "C9", "7D", "FA", "59", "47", "F0", "AD", "D4", "A2", "AF", "9C", "A4", "72", "C0"},
        {"B7", "FD", "93", "26", "36", "3F", "F7", "CC", "34", "A5", "E5", "F1", "71", "D8", "31", "15"},
        {"04", "C7", "23", "C3", "18", "96", "05", "9A", "07", "12", "80", "E2", "EB", "27", "B2", "75"},
        {"09", "83", "2C", "1A", "1B", "6E", "5A", "A0", "52", "3B", "D6", "B3", "29", "E3", "2F", "84"},
        {"53", "D1", "00", "ED", "20", "FC", "B1", "5B", "6A", "CB", "BE", "39", "4A", "4C", "58", "CF"},
        {"D0", "EF", "AA", "FB", "43", "4D", "33", "85", "45", "F9", "02", "7F", "50", "3C", "9F", "A8"},
        {"51", "A3", "40", "8F", "92", "9D", "38", "F5", "BC", "B6", "DA", "21", "10", "FF", "F3", "D2"},
        {"CD", "0C", "13", "EC", "5F", "97", "44", "17", "C4", "A7", "7E", "3D", "64", "5D", "19", "73"},
        {"60", "81", "4F", "DC", "22", "2A", "90", "88", "46", "EE", "B8", "14", "DE", "5E", "0B", "DB"},
        {"E0", "32", "3A", "0A", "49", "06", "24", "5C", "C2", "D3", "AC", "62", "91", "95", "E4", "79"},
        {"E7", "C8", "37", "6D", "8D", "D5", "4E", "A9", "6C", "56", "F4", "EA", "65", "7A", "AE", "08"},
        {"BA", "78", "25", "2E", "1C", "A6", "B4", "C6", "E8", "DD", "74", "1F", "4B", "BD", "8B", "8A"},
        {"70", "3E", "B5", "66", "48", "03", "F6", "0E", "61", "35", "57", "B9", "86", "C1", "1D", "9E"},
        {"E1", "F8", "98", "11", "69", "D9", "8E", "94", "9B", "1E", "87", "E9", "CE", "55", "28", "DF"},
        {"8C", "A1", "89", "0D", "BF", "E6", "42", "68", "41", "99", "2D", "0F", "B0", "54", "BB", "16"},
};
string INSBOX [16][16] = {
        {"52", "09", "6A", "D5", "30", "36", "A5", "38", "BF", "40", "A3", "9E", "81", "F3", "D7", "FB"},
        {"7C", "E3", "39", "82", "9B", "2F", "FF", "87", "34", "8E", "43", "44", "C4", "DE", "E9", "CB"},
        {"54", "7B", "94", "32", "A6", "C2", "23", "3D", "EE", "4C", "95", "0B", "42", "FA", "C3", "4E"},
        {"08", "2E", "A1", "66", "28", "D9", "24", "B2", "76", "5B", "A2", "49", "6D", "8B", "D1", "25"},
        {"72", "F8", "F6", "64", "86", "68", "98", "16", "D4", "A4", "5C", "CC", "5D", "65", "B6", "92"},
        {"6C", "70", "48", "50", "FD", "ED", "B9", "DA", "5E", "15", "46", "57", "A7", "8D", "9D", "84"},
        {"90", "D8", "AB", "00", "8C", "BC", "D3", "0A", "F7", "E4", "58", "05", "B8", "B3", "45", "06"},
        {"D0", "2C", "1E", "8F", "CA", "3F", "0F", "02", "C1", "AF", "BD", "03", "01", "13", "8A", "6B"},
        {"3A", "91", "11", "41", "4F", "67", "DC", "EA", "97", "F2", "CF", "CE", "F0", "B4", "E6", "73"},
        {"96", "AC", "74", "22", "E7", "AD", "35", "85", "E2", "F9", "37", "E8", "1C", "75", "DF", "6E"},
        {"47", "F1", "1A", "71", "1D", "29", "C5", "89", "6F", "B7", "62", "0E", "AA", "18", "BE", "1B"},
        {"FC", "56", "3E", "4B", "C6", "D2", "79", "20", "9A", "DB", "C0", "FE", "78", "CD", "5A", "F4"},
        {"1F", "DD", "A8", "33", "88", "07", "C7", "31", "B1", "12", "10", "59", "27", "80", "EC", "5F"},
        {"60", "51", "7F", "A9", "19", "B5", "4A", "0D", "2D", "E5", "7A", "9F", "93", "C9", "9C", "EF"},
        {"A0", "E0", "3B", "4D", "AE", "2A", "F5", "B0", "C8", "EB", "BB", "3C", "83", "53", "99", "61"},
        {"17", "2B", "04", "7E", "BA", "77", "D6", "26", "E1", "69", "14", "63", "55", "21", "0C", "7D"}
    };
string rounds [10][4] = {
        {"01", "00", "00", "00"},
        {"02", "00", "00", "00"},
        {"04", "00", "00", "00"},
        {"08", "00", "00", "00"},
        {"10", "00", "00", "00"},
        {"20", "00", "00", "00"},
        {"40", "00", "00", "00"},
        {"80", "00", "00", "00"},
        {"1B", "00", "00", "00"},
        {"36", "00", "00", "00"}
};

/*
     First generate all the round keys of 4 bytes total 10 will be generated and top
     of them will be original key

     Except last round remaining rounds are same

     Now each block of plain text will be broken into a 4*4 matrix

     Xor with round key first then

     Substitute with values from the S Box table by matching first four as row and next four as column
     For all 16 values in plain text represented as 4*4 matrix

     Left Shift rows in the new state matrix by row number begining from 0 to 3

     Then do mixColumns for which each of the column of the State will be multiplied with 
     standard matrix for which we have a shortcut and replace them with the corresponding values

     Then XOR the values in the State 
*/
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
string hextoBinHelper(string s){
     string res = "";
     for (int i = 0;i<s.size();i++)
     res+=hbmap[s[i]];
     return res;
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

void matrixStringHelpher(vector<vector<string>>s){
     vector<string>temp;
     W0 = temp;
     W1 = temp;
     W2 = temp;
     W3 = temp;
     for(int i = 0;i<4;i++){
          W0.PB(s[0][i]);
          W1.PB(s[1][i]);
          W2.PB(s[2][i]);
          W3.PB(s[3][i]);
          // This will simply make matrix into words string
     }
}
string XOR(string a,string b){
     string res = "";
     for(int i = 0;i<a.size();i++){
          if(a[i] == b[i])res += '0';
          else res += '1';
     }
     return res;
}
int strtodec(string s){
     int val = 0;
     if(s[0] == '1')val += 8;
     if(s[1] == '1') val+=4;
     if(s[2] == '1')val += 2;
     if(s[3] == '1') val+=1;
     return val;
}
void keyGenerator(vector<vector<vector<string>>>&keys){
     vector<vector<string>>key(4);
     for(int i = 0;i<4;i++){
          key[i].PB(W0[i]);
          key[i].PB(W1[i]);
          key[i].PB(W2[i]);
          key[i].PB(W3[i]);
     }
     keys.PB(key);
     // initial key is given to it
     for(int t = 0;t<10;t++){
          vector<vector<string>>key(4);
          // Now we  need to left shift w3 then we need to take S box value and then XOR
          vector<string>temp {W3[1],W3[2],W3[3],W3[0]};
          // left shift is done
          for(int i =0;i<4;i++){
               temp[i] = hextoBinHelper(SBOX[strtodec(temp[i].substr(0,4))][strtodec(temp[i].substr(4,8))]);
          }
          // This will return the value S Box value of W3
          vector<string>g(4);
          for(int i = 0;i<4;i++){
               g[i] = XOR(temp[i],hextoBinHelper(rounds[t][i]));
          }
          for(int i = 0;i<4;i++){
               W0[i] = XOR(W0[i],g[i]);
          }
          for(int i = 0;i<4;i++){
               W1[i] = XOR(W1[i],W0[i]);
          }
          for(int i = 0;i<4;i++){
               W2[i] = XOR(W2[i],W1[i]);
          }
          for(int i = 0;i<4;i++){
               W3[i] = XOR(W3[i],W2[i]);
          }
          for(int i = 0;i<4;i++){
               key[i].PB(W0[i]);
               key[i].PB(W1[i]);
               key[i].PB(W2[i]);
               key[i].PB(W3[i]);
          }
          keys.PB(key);
     }
}
void printMatrix(vector<vector<string>>s){
     for(int i = 0;i<4;i++){
          for(int j = 0;j<4;j++){
               cout<<bintoHexHelper(s[i][j])<<" ";
          }
          cout<<endl;
     }
}
void matriceString(vector<vector<string>>s){
     cout<<"The Cipher text is "<<endl;
     for(int i = 0;i<4;i++){
          for(int j = 0;j<4;j++){
               cout<<bintoHexHelper(s[j][i])<<" ";
          }
     }
     cout<<endl;
}
string multiplier(int n,string s);
vector<vector<string>> encrypt(string plain,vector<vector<vector<string>>>&keys){
     vector<vector<string>> state (4,vector<string>(4));
     int x = 0,y = 0;
     for(int i = 0;i<plain.size();i++){
          int temp = 32;
          if(plain[i] != ' '){
               temp = (int)plain[i];
               
          }
          bitset<8>b(temp);
          state[x][y] = b.to_string();
          x++;
          if(x == 4){
               x = 0;
               y++;
          }
     
     }
     cout<<"Initial plain Text Matrix"<<endl;
     printMatrix(state);
     cout<<"Round 0"<<endl;
     cout<<"Initial XOR State"<<endl;
     for(int i = 0;i<4;i++){
          for(int j = 0;j<4;j++){
               state[i][j] = XOR(keys[0][i][j],state[i][j]);
          }
     }
     printMatrix(state);
     for(int t = 1;t<10;t++){
          cout<<"Round "<<t<<endl;
          cout<<"Key is "<<endl;
          printMatrix(keys[t]);
          // S Box substitute
          for(int i =0;i<4;i++ ){
               for(int j = 0;j<4;j++){
                    int col  = strtodec(state[i][j].substr(4,4));
                    int row =  strtodec(state[i][j].substr(0,4));
                    state[i][j] = hextoBinHelper(SBOX[row][col]);
               }
          }
          cout<<"After S Box"<<endl;
          printMatrix(state);
          // Left shift is done
          for(int i = 0;i<4;i++){
               for(int j = 0;j<i;j++){
                    string temp = state[i][0];
                    state[i][0] = state[i][1];
                    state[i][1] = state[i][2];
                    state[i][2] = state[i][3];
                    state[i][3] = temp;
               }
          }
          cout<<"After Shift "<<endl;
          printMatrix(state);
          // Mix Columns
          const int matrix [4][4] = {{2,3,1,1},{1,2,3,1},{1,1,2,3},{3,1,1,2}};
          vector<vector<string>> new_state (4,vector<string>(4));
          for(int k = 0;k<4;k++){
               for(int i = 0;i<4;i++){
                  new_state [i][k] = XOR(multiplier(matrix[i][0],state[0][k]),XOR(multiplier(matrix[i][1],state[1][k]),XOR(multiplier(matrix[i][2],state[2][k]),multiplier(matrix[i][3],state[3][k]))));
               }
          }
          // Now new state is ready and need to XOR with key 
          cout<<"After Mix col"<<endl;
          printMatrix(new_state);
          for(int i = 0;i<4;i++){
               for(int j = 0;j<4;j++){
                    new_state[i][j] = XOR(new_state[i][j],keys[t][i][j]);
               }
          }
          // XOR is done now result need to be set to state back
          cout<<"After XOR"<<endl;
          printMatrix(new_state);
          state = new_state;
          matriceString(state);
     }
     
     
    //////////////////////////////////////////////////////////////////////////////////////////////////////// // 
     
     
     // Final value need to be XOR 
     cout<<"Final State "<<endl;
          for(int i =0;i<4;i++ ){
               for(int j = 0;j<4;j++){
                    state[i][j] = hextoBinHelper(SBOX[strtodec(state[i][j].substr(0,4))][strtodec(state[i][j].substr(4,8))]);
               }
          }
          // Left shift is done
          for(int i = 0;i<4;i++){
               for(int j = 0;j<i;j++){
                    string temp = state[i][0];
                    state[i][0] = state[i][1];
                    state[i][1] = state[i][2];
                    state[i][2] = state[i][3];
                    state[i][3] = temp;
               }
          }
          vector<vector<string>> new_state (4,vector<string>(4));
          new_state = state;
          for(int i = 0;i<4;i++){
               for(int j = 0;j<4;j++){
                    new_state[i][j] = XOR(new_state[i][j],keys[10][i][j]);
               }
          }
          // XOR is done now result need to be set to state back
          state = new_state;
     printMatrix(state);
     matriceString(state);
     return state;
}
string multiplier(int n,string s){
     if(n == 1)return s;
     if(n == 2){
          int temp = s[0];
          for(int i = 1;i<s.size();i++)s[i-1] = s[i];
          s[s.size()-1] = '0';
          // left shift by 1
          if(temp == '0')return s;
          if(temp == '1')
          return XOR(s,"00011011");
     }
     
     return XOR(s,multiplier(2,s));
}




int main(){
     init();
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string key = "Thats my Kung Fu";
    string plain = "Two One Nine Two";
    string res = "";
    cout<<"This is plain text "<<endl;
    cout<<plain<<endl;
    cout<<"This is key "<<endl;
    cout<<key<<endl;
    // Converting to ascii and then to binary of 8 bits each character
    vector<vector<string>>key_matrix_bin(4);
    vector<vector<char>> key_matrix(4);
    int x = 0,y=0;
    for(int i = 0;i<key.size();i++){
         int temp ;
         if(key[i]==' ')temp = 32;
         else temp = (int)key[i];
         bitset<8>b(temp);
         res += b.to_string();
         key_matrix_bin[x].PB(b.to_string());
         key_matrix[x].PB(key[i]);
         y++;
         if(y == 4){
              y = 0;
              x++;
         }
    }
    for(int i =0;i<4;i++){
         for(int j = 0;j<4;j++){
              cout<<bintoHexHelper(key_matrix_bin[i][j])<<" ";
         }
         cout<<endl;
    }
    matrixStringHelpher(key_matrix_bin);
    // Generates the inital keys required 
    vector<vector<vector<string>>>keys;
    keyGenerator(keys);
    encrypt(plain,keys);
}