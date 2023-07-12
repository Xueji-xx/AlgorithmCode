#include <iostream>
using namespace std;

double p[150];//¸ÅÂÊ

void init(){
    p[90] = 1;
    for(int i = 1;i < 74;i ++)p[i] = 0.006;
    for(int i = 74;i <= 89;i ++)p[i] = p[i-1] + 0.06;
}

int main(){
    int x;
    cin>>x;
    init();
    double ans = 0,t = 1;
    for(int i = x+1;i <= 90;i ++){
        ans += (i - x) * (t * p[i]);
        t = t * (1 - p[i]);
    }
    printf("%.3f",ans);
    return 0;
}
