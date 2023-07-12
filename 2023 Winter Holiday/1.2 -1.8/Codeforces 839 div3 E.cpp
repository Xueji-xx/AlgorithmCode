//1700
#include <iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int p[n+10];
    int a,b,c;
    a = b = c = 0;
    for(int i = 1;i <= n;i ++){
        cin>>p[i];
        if(p[i] != i && p[i] != n-i+1)c++;
        else if(p[i] != i)a++;
        else if(p[i] != n-i+1)b++;
    }
    if(a + c <= b)cout<<"First"<<endl;
    else if(b + c < a)cout<<"Second"<<endl;
    else cout<<"Tie"<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}