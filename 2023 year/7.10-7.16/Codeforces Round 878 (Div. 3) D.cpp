//1400
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5+50;
int a[N];
int n;


bool check(int x){
    int num = 1;
    int k = a[1];
    for(int i = 2;i <= n;i ++){
        if(a[i] - k > x){
            num ++;
            k = a[i];
        }
    }
    return num <= 3;
}

void solve(){
    
    cin >> n;
    for(int i = 1;i <= n;i ++)cin >> a[i];
    sort(a+1,a+1+n);
    int l = 0,r = a[n] - a[1];
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid))r = mid-1;
        else l = mid + 1;
    }
    cout << l / 2  + l % 2 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t --)solve();
    return 0;
}