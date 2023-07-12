#include<iostream>
using namespace std;

void solve(){
    int n,m,sx,sy,d;
    cin>>n>>m>>sx>>sy>>d;
    bool st[4] = {false};
    if(sx - d <= 1) st[0] = 1;
    if(sx + d >= n) st[1] = 1;
    if(sy - d <= 1) st[2] = 1;
    if(sy + d >= m) st[3] = 1;
    
    if(st[0] && st[1]) cout<<-1<<"\n";
    else if(st[2] && st[3]) cout<<-1<<"\n";
    else if(st[0] && st[2]) cout<<-1<<"\n";
    else if(st[1] && st[3]) cout<<-1<<"\n";
    else {
        cout << n + m - 2 << endl;
    }
}


int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("puase");
    return 0;
}