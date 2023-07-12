#include <iostream>
using namespace std;
#define int long long
#define endl '\n'

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<(x2 - x1) * (y2 - y1) + 1<<endl;
    }   
    return 0;
}