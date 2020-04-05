#include <bits/stdc++.h>
using namespace std;

void solve(){
	char arr[100];
    int k;
    cin>>arr;
    int res=strlen(arr);
    for(int i=0;i<res;i++){
        int tmp;
        if(i==0){
            tmp=arr[i]-'0';
            for(int j=0;j<tmp;j++){
                cout<<'(';
            }
        }else{
            if(arr[i-1]<arr[i]){
                tmp=arr[i]-arr[i-1];
                for(int j=0;j<tmp;j++){
                    cout<<'(';
                }
            }else if(arr[i-1]>arr[i]){
                tmp=arr[i-1]-arr[i];
                for(int j=0;j<tmp;j++){
                    cout<<')';
                }
            }
        }
        cout<<arr[i];
        if(i==res-1){
            tmp=arr[i]-'0';
            for(int j=0;j<tmp;j++){
                cout<<')';
            }
        }
    }
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
