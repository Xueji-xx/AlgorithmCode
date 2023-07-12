#include <iostream>
using namespace std;



int main(){
    int n;
    double s = 0;
    cin>>n;
    for(int i = 1;i <= n;i ++){
        double x;
        cin>>x;
        s += x;
    }
    s /= (n+1);
    for(int i = 1;i <= n;i ++){
        if(i == 1){
            printf("%.7f ",2*s);
        }
        else printf("%.7f ",s);
    }
    return 0;
}