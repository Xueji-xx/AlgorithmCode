#include<iostream>
#include<cmath>
using namespace std;
typedef pair<int,int> PII;
#define x first
#define y second

int main(){
    int n;
    cin>>n;
    PII a[n+50];
    for(int i = 1;i <= n;i ++){
        cin>>a[i].x>>a[i].y;
    }
    double sum = 0;
    for(int i = 1;i < n;i ++){
        sum += abs((double)((a[i].x*a[i+1].y)-(a[i+1].x*a[i].y)));
    }
    sum += abs((double)((a[1].x * a[n].y) - (a[n].x * a[1].y)));
    sum /= 2.0;
    printf("%.3lf",sum);
    system("pause");
    return 0;
}