#include<iostream>
using namespace std;
const int N = 1e6+50;
int ne[N];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a,b;
    int n,m;
    cin>>n>>a>>m>>b;
    a = '1' + a;
    b = '1' + b;
    for(int i = 2,j = 0;i <= n;i ++){
        while(j && a[i] != a[j+1])j = ne[j];
        if(a[i] == a[j+1])j++;
        ne[i] = j;
    }
    for(int i = 1,j = 0;i <= m;i ++){
        while(j && b[i] != a[j+1])j = ne[j];
        if(b[i] == a[j+1])j++;
        if(j == n){
            cout<<i-j<<' ';
            j = ne[j];
        }
    }
    system("pause");
    return 0;
}