#include <iostream>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum = 0;
        while(n--){
            int x;
            cin>>x;
            sum += x;
        }
        cout<<(sum > 0 ? sum : -1 * sum)<<endl;
    }
    return 0;
}