#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
struct node{
    int s,a,e,sum;
    int y;
};

bool cmp(node o,node p){
    if(p.sum != o.sum)return o.sum < p.sum;
    else return o.y < p.y;
}


signed main(){
    int t;
    cin >> t;
    node b[t+10];
    for(int i = 1;i <= t;i ++){
        cin >> b[i].s >> b[i].a >> b[i].e;
        b[i].sum = b[i].s + b[i].a + b[i].e;
        b[i].y = b[i].s + b[i].a;
    }
    sort(b+1,b+1+t,cmp);
    int ans = 0;
    int last = 0;
    for(int i = 1;i <= t;i ++){
        last += b[i].y;
        ans += last;
        last += b[i].e;
    }
    cout << ans << endl;
    /*for(int i = 1;i <= t;i ++){
        cout << b[i].s << ' ' << b[i].a << ' ' << b[i].e << endl;
    }*/
    return 0;
}