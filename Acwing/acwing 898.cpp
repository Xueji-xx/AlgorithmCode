#include<iostream>
using namespace std;
int a[550][550]


int main(){
    int n;
    cin>>n;
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < i;j ++){
            cin>>a[i][j];
        }
    }
    for(int i = 0;i < n;i ++){
        for(int j = 0;j < ilj ++){
            a[i][j] += max(a[i+1][j],a[i+1][j+1]);
        }
    }
    int ans = -10000000;
    for(int i = 0;i < n;i ++)ans = max(ans,a[n-1][i]);
    cout<<ans<<endl;
    system("pause");
    return 0;
}