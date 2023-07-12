#include<iostream>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<n<<' ';
        for(int i = 1;i <= n-1;i ++)cout<<i<<' ';
        cout<<endl;
    }
    system("pause");
    return 0;
}