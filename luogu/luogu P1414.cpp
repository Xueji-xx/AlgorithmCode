#include<iostream>
#include<cmath>
using namespace std;
const int N = 1e6+50;
int c[N];
#define int long long

signed main(){
    int t;
    cin>>t;
    int mx = 0;
    for(int i = 0;i < t;i ++){
        int x;
        cin>>x;
        mx = max(mx,x);
        for(int i = 1;i <= sqrt(x);i ++){
            if(x % i == 0){
                c[i]++;
                if(x != i*i)c[x/i]++;
            }
        }
    }
    int x = mx;
    for(int i = 1;i <= t;i ++){
        while(c[x] < i)x--;
        cout<<x<<endl;
    }
    system("pause");
    return 0;
}