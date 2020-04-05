#include <bits/stdc++.h>
using namespace std;

bool k,ar1[60][60],ar2[60][60];
int x,y,z,tmp[60][60];

void result(int p,int q,int r){
    if(r==x && q==x+1 && p==y && !k){
        k=true;
        cout<<"Case #"<<z<<": "<<"POSSIBLE\n";
        for(int i=1;i<=x;++i){
            for(int j=1;j<=x;++j){
                cout<<tmp[i][j]<<" ";
            }
            cout<<"\n";
        }
        return;
    }else if (x<r){
        return;
    }else if (x<q){
        result(p,1,r+1);
    }for(int i=1;i<=x && !k;++i){
        if (!ar1[r][i] && !ar2[q][i]){
            ar1[r][i]=ar2[q][i]=true;
            if(r==q){
                p+=i;
            }
            tmp[r][q]=i;
            result(p,q+1,r);
            ar1[r][i]=ar2[q][i]=false;
            if(r==q){
                p-=i;
            }
            tmp[r][q]=0;
        }
    }
}

int main(){
    int n;
    scanf(" %d", &n);
    for(z=1;z<=n;++z){
        scanf(" %d %d",&x,&y);
        result(0,1,1);
        if(!k){
            cout<<"Case #"<<z<<": "<<"IMPOSSIBLE\n";
        }
        k=false;
    }
    return 0;
}
