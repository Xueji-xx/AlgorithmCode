#include <iostream>
#include <set>
using namespace std;
#define int long long
#define endl '\n'

set<int> solve(int x){
    set<int> num;
    for(int i = 1;i <= x / i;i ++){
        if(x % i == 0){
            num.insert(i);
            num.insert(x / i);
        }
    }
    return num;
}

void solve1(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    set<int> num1 = solve(a);
    set<int> num2 = solve(b);
    for(auto i : num1){
        for(auto j : num2){
            int x = i * j;
            int y = a * b / x;
            x = (a / x + 1) * x;
            y = (b / y + 1) * y;
            if(a < x && x <= c && b < y && y <= d){
                cout<<x<< ' '<<y<<endl;
                return;
            }
        }
    }
    cout<<-1<<' '<<-1<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve1();
    }
    return 0;
}