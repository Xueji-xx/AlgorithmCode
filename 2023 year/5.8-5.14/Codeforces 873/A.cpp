#include <iostream>
using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n & 1){
        for(int i = 1;i <= n;i ++)cout <<  i << ' ';
        cout << endl;
    }
    else{
        for(int i = 1;i <= n;i ++){
            if(i == n / 2)cout << i * 2 << ' ';
            else cout << i << ' ';
        }
        cout << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t --)solve();
    return 0;
}