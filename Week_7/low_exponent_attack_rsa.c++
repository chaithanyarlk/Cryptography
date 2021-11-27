#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll modinverse(ll a,ll b){
     for(ll i = 1;i<b;i++){
          if(((a%b)*(i%b))%b == 1)return i;
     }
     return 0;
} 
int main(){
     ll e,cb,cd,cc,nb,nc,nd,inb,inc,ind,X,m;
     e = 3;m = 102;nb= 377;nc=391;nd=589;
     cout<<"e "<<e<<endl;
     cout<<"m "<<m<<endl;
     cout<<"nb "<<nb<<endl; 
     cout<<"nc "<<nc<<endl;
     cout<<"nd "<<nd<<endl;
     cb = pow(m,e);cb = cb%nb;
     cc = pow(m,e);cc = cc%nc;
     cd = pow(m,e);cd = cd%nd;
     cout<<cb<<" "<<cc<<" "<<cd<<endl;
     inb = modinverse(nc*nd,nb);
     inc = modinverse(nb*nd,nc);
     ind = modinverse(nb*nc,nd);
     cout<<inb<<" "<<inc<<" "<<ind<<endl;
     ll tb = cb*(nc*nd)*inb;
     ll tc = cc*(nb*nd)*inc;
     ll td = cd*(nb*nc)*ind;
     cout<<tb<<" "<<tc<<" "<<td<<endl;
     X = tb+tc+td;
     X = X%(nb*nc*nd);
     X = cbrt(X);
     cout<<"X value "<<X<<endl;

}
