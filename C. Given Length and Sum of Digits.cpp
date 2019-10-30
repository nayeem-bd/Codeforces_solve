#include<bits/stdc++.h>
using namespace std;

bool possible(int m, int s)
{
    return s >= 0 && s <= 9 * m;
}
int main()
{
    int m,s,i,j,k,l,sum;
    cin>>m>>s;
    string mn,mx;
    if(m==1 && s==0){
        cout<<"0 0"<<endl;
        return 0;
    }
    if(s>9*m || s==0){
        cout<<"-1 -1"<<endl;
        return 0;
    }

    sum = s;
    for(i=1;i<=m;i++){
        for(l=0;l<10;l++){
            if((i>1||l>0||(m==1 && l==0)) && possible(m-i,sum-l)){
                mn += '0'+l;
                sum -= l;
                break;
            }
        }
    }
    sum = s;
    for(i=1;i<=m;i++){
        for(l=9;l>-1;l--){
            if((i>1||l>0||(m==1 && l==0)) && possible(m-i,sum-l)){
                mx += '0'+l;
               // cout<<l<<endl;
                sum -= l;
                break;
            }
        }
    }


    cout<<mn<<" "<<mx<<endl;
    return 0;
}
