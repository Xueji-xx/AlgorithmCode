#include<iostream>
#include<algorithm>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int a[4];
        for(int i=1; i<=3; i++)cin >>a[i];
        sort(a+1,a+4);
        if(a[1] + a[2] == a[3] || (a[2] == a[3] && a[1] % 2 == 0) || (a[1] == a[2] && a[3] % 2 == 0))
            cout <<"YES"<<endl;
        else
            cout <<"NO"<<endl;
    }
    system("pause");
    return 0;
}