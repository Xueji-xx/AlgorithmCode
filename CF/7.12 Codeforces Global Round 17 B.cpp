#include<iostream>
using namespace std;

bool check(int a[],int n,int x){
    int l = 0,r = n-1;
    while(l < r){
        while(a[l] == a[x])l++;
        while(a[r] == a[x])r--;
        if(l > r)break;
        if(a[l] == a[r])l++,r--;
        else return false;
    }
    return true;
}

void solve(){
    int n;
    cin>>n;
    int a[n+10] = {0};
    for(int i = 0;i < n;i ++){
        cin>>a[i];
    }
    int l = 0,r = n-1;
    int x,y;
    while(l < r){
        if(a[l] == a[r])l++,r--;
        else{
            x = l,y = r;
            break;
        }
    }
    bool flag = false;
    if(x == y){
        cout<<"YES"<<endl;return;
    }
    else{
        if(check(a,n,x))flag = true;
        if(check(a,n,y))flag = true;
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}