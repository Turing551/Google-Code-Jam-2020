#include <bits/stdc++.h>
using namespace std;

void solve(){
    int k,arr[101][101];
    long long x=0,y=0,z=0;
    cin>>k;
    for(int i=0;i<k;i++){
        int tmp=0,arr1[101]={0};
        for(int j=0;j<k;j++){
            cin>>arr[i][j];
            if(i==j){
                x+=arr[i][j];
            }if(arr1[arr[i][j]]!=0){
                tmp=1;
            }
            arr1[arr[i][j]]=-1;
        }if(tmp==1){
            y++;
        }
    }
    for(int j=0;j<k;j++){
        int arr1[101]={0};
        int tmp=0;
        for(int i=0;i<k;i++){
            if(arr1[arr[i][j]]!=0){
                tmp=1;
            }
            arr1[arr[i][j]]=-1;
        }if(tmp==1){
            z++;
        }
    }
    cout<<x<<" "<<y<<" "<<z;
    cout<<endl;
}
int main(){
    int n,i=1;
    cin>>n;
    while(n--){
        cout<<"Case #"<<i<<": ";
        solve();
        i++;
    }
    return 0;
}
