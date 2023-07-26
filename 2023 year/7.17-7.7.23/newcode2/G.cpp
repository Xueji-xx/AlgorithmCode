#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

const int N = 1e6+50;
#define endl "\n"

char s[N*2];
char rev[256];
char _s[N];

bool check(char a,char b){
    return b == rev[a];
}

void init(){
    for(int i=0;i<256;i++){ 
		rev[i] = '1';
	}
	rev['b'] = 'q';
	rev['d'] = 'p';
	rev['p'] = 'd';
	rev['q'] = 'b';
	rev['n'] = 'u';
	rev['u'] = 'n';
	rev['o'] = 'o';
	rev['s'] = 's';
	rev['x'] = 'x';
	rev['z'] = 'z';
	rev['#'] = '#';
}

void solve(){
    scanf("%s",_s);
    int n = strlen(_s);
    s[0] = '$';
    for(int i = 0;i < n;i ++){
        s[i*2+1] = '#';
        s[i*2+2] = _s[i];
    }
    n *= 2;
    s[++n] = '#';   
    s[n + 1] = '\0';
    int rc = 0;
    vector<int> r(n+1);
    int sta = 1;
    for(int i = 1;i <= n;i ++){
        if(rc + r[rc] >= i){
            r[i] = min(r[rc - (i - rc)],r[rc] - (i - rc));//找到当前的回文半径
        }
        else{
            r[i] = -1;
        }    
        while(check(s[i - r[i] - 1],s[i + r[i] + 1])){//判断是否符合回文
            r[i] ++;
        }
        if(i + r[i] > rc + r[rc]){
            rc = i;
        }
        if(r[i] && i - r[i] <= sta){
            s[i + r[i] - 1] = '$';
            sta = i + r[i];
            i = i + r[i] - 1;//记录到下一个回文串的起始位置
        }   
    }
    cout << (sta == n ? "YES" : "NO") << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}