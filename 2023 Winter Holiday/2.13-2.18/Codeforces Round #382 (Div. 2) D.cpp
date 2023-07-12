#include <iostream>
using namespace std;

bool check(int x){
    for(int i = 2;i <= x / i;i ++){
        if(x % i == 0)return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    if(n < 4){
        cout<<1<<endl;
        return 0;
    }
    if(!(n & 1)){
        cout<<2<<endl;
        return 0;
    }
    else{
        if(check(n)){
            cout<<1<<endl;
            return 0;
        }
        int x = n - 2;
        if(check(x)){
            cout<<2<<endl;
            return 0;
        }
        x = n - 3;
        int sum = 1;
        if(x < 4)sum += 1;
        else sum += 2;
        cout<<sum<<endl;
    }
    return 0;
}