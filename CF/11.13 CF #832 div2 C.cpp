#include <iostream>
#include <climits>
using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int minn = INT_MAX;
        int a[n+10];
        for(int i = 1;i <= n;i ++){
            cin>>a[i];
            minn = min(minn,a[i]);
        }
        cout<<((a[1] > minn)?"Alice" : "Bob")<<endl;
    }
    return 0;
}