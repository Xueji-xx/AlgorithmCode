#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    iota(a.begin(),a.end(),1);

    int left = 0,right = n - 3;
    if(n & 1)left++;

    while(left < right){
        swap(a[left++],a[right--]);
    }

    for(int i = 0;i < n;i ++)cout<<a[i]<<' ';
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}