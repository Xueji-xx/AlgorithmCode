#include<iostream>
#include<unordered_map>
using namespace std;
const int mod = 1e9+7;



int main(){
    int n;
    cin>>n;
    unordered_map<int,int> pri;
    while(n--){
        int x;
        cin>>x;
        for(int i = 2;i <= x/i;i ++){
            while(x % i == 0){
                pri[i]++;
                x /= i;
            }
            if(x > 0)pri[x]++;
        }
    }
    long long ans = 0;
    fpr(auto i : pri){
        long long a = i.first,b = i.second;
        long long t = 1;
        while(b--){
            t = (t * a + 1) % mod;
        }
        ans = ans * t % mod;
    }
    cout<<ans<<endl;
    return 0;
}