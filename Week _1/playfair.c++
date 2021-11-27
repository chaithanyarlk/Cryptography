#include<bits/stdc++.h>
using namespace std;
char mat[5][5];
map<char,int>m;
// bogus helper
char bogusFinder(){
    for(int i = 0;i<26;i++){
        if(m[char(i+'A')] == 0){
            m[char(i+'A')] = -1;
            return char(i+'A');
        } 
    }
}
// generation of table
void generateTable(string key){
    int x =0,y=0;
    if(key.size()>25)cout<<"Error"<<endl;
    for(int i = 0;i<key.size();i++){
        m[key[i]] = 1;
        mat[x][y]=key[i];
        if(y == 4){
            x++;
            y =0 ;
        }
        else y++;
    }
    int a  = 0;
    while(x<5){
        if(char(a+'A') !='J'&&m[char(a+'A')] == 0){
            mat[x][y] = char(a+'A');
            if(y == 4){
                x++;
                y=0;
            }
            else y++;
        }
        a++;
    }
    // Uncomment to see the Table
    // for(int i = 0;i<5;i++){
    //     for(int j = 0;j<5;j++){
    //         cout<<mat[i][j]<< " ";
    //     }
    //     cout<<endl;
    // }
    
}
pair<int,int>search(char a){
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            if(mat[i][j] == a){
                return make_pair(i,j);
            }
        }
    }
}
// encryption code
string encryption(string text){
    string res ="";
    string filter= "";
    char prev = text[0];
    filter = prev;
    char bogus1 = bogusFinder();
    char bogus2 = bogusFinder();
    for(int i = 1;i<text.size();i++){
        if(prev == text[i]){
            filter += bogus1+text[i];
        }
        else{
            filter += text[i];
        }
    }
    if(text.size()%2)filter += bogus2;
    // cout<<filter<<endl;
    for(int i = 0;i<filter.size();i = i+2){
        if(filter[i] == 'J')filter[i] ='I';
        if(filter[i+1] == 'J')filter[i+1] ='I';
        pair<int,int>x1 = search(filter[i]);
        pair<int,int>x2 = search(filter[i+1]);
        // cout<<x1.first<< " "<<x1.second<<endl;
        // cout<<x2.first<< " "<<x2.second<<endl;
        if(x1.second == x2.second){
            // // same column
            // cout<<"Same col"<<endl;
            res += mat[(x1.first+1)%5][x1.second];
            res+= mat[(x2.first+1)%5][x2.second];
        }
        else if(x1.first == x2.first){
            // // same row
            // cout<<"Same row"<<endl;
            res += mat[x1.first][(x1.second+1)%5];
            res+= mat[x2.first][(x2.second+1)%5];
        }
        else{
           // cout<<"Totally Different"<<endl;
            res += mat[x1.first][x2.second];
            res += mat[x2.first][x1.second];
        }
    }
    return res;
    
    
}
// decryption code
string decryption(string text){
    string res ="";
    for(int i = 0;i<text.size();i = i+2){
        if(text[i] == 'J')text[i] ='I';
        if(text[i+1] == 'J')text[i+1] ='I';
        pair<int,int>x1 = search(text[i]);
        pair<int,int>x2 = search(text[i+1]);
        // cout<<x1.first<< " "<<x1.second<<endl;
        // cout<<x2.first<< " "<<x2.second<<endl;
        if(x1.second == x2.second){
            // // same column
            // cout<<"Same col"<<endl;
            int t1 = x1.first-1;
            int t2 = x2.first - 1;
            if(t1<0)t1 += 5;
            if(t2<0)t2+=5;
            res += mat[(t1)%5][x1.second];
            res+= mat[(t2)%5][x2.second];
        }
        else if(x1.first == x2.first){
            // // same row
            // cout<<"Same row"<<endl;
            int t1= x1.second-1;
            int t2 = x2.second -1;
            if(t1<0)t1+=5;
            if(t2<0)t2+=5;
            res += mat[x1.first][(t1)%5];
            res+= mat[x2.first][(t2)%5];
        }
        else{
           // cout<<"Totally Different"<<endl;
            res += mat[x1.first][x2.second];
            res += mat[x2.first][x1.second];
        }
    }
    string org ="";
    for(int i = 0;i<res.size();i++){
        if(m[res[i]] != -1)org += res[i];
    }
    return org;
    
    
}
int main(){
    string key ;
    string text ;
    cout<<"Enter Key ..."<<endl;
    cin>>key;
    cout<<"Enter text ..."<<endl;
    cin>>text;
    generateTable(key);
    string enc = encryption(text);
    cout<<"Encrypted Message : "<<enc<<endl;
    cout<<"Decrypted Message : "<<decryption(enc)<<endl;
}