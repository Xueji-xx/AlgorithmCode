#include<iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    double sum = 0,cnt = 0;
    for(int i = 0;i < n;i ++){
        double x;
        cin>>x;
        sum += x;
        if(cnt >= 200)cnt += x*0.5;
        else if(cnt >= 100 && cnt < 200)cnt += x*0.8;
        else cnt += x;
    }
    if(sum >= 225)printf("%.3lf ",(sum-225)*0.5+200);
    else if(sum >= 100 && sum < 225)printf("%.3lf ",(sum-100)*0.8+100);
    else printf("%.3lf ",sum);
    printf("%.3lf\n",cnt);
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}