#include <iostream>
using namespace std;
const int N = 33000;
int n;
int tr[N],w[N];

int lowbit(int x){
    return x & -x;
}

void add(int x){
    for(int i = x;i < N;i += lowbit(i)){
        tr[i]++;
    }
}

int query(int x){
    int res = 0;
    for(int i = x;i;i -= lowbit(x)){
        res += tr[i];
    }
    return res;
}

int main(){
    cin >> n;
    for(int i = 0;i < n;i ++){
        int x,y;
        cin>>x>>y;
        x ++;
        ++w[query(x)];
        add(x);
    }
    for(int i = 0;i < n;i ++)cout<<w[i]<<endl;
    return 0;
}