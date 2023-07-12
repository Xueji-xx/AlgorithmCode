#include <iostream>
using namespace std;

const int N = 110000;
int p[N];
string str,s;

void add(){
    str += '^';
    for(int i = 0;i < s.size();i ++){
        str += '#';
        str += s[i];
    }
    str += '#';
    str += '@';
}

void manacher(){
    int r = 0,mid = 0;
    for(int i = 1;i < str.size() - 1;i ++){
        p[i] = r > i ? min(p[2*mid - i],r-i) : 1;
        while(str[i + p[i]] == str[i - p[i]])p[i] ++;
        if(i + p[i] > r){
            r = i + p[i];
            mid = i;
        }
    }
}

int main(){
    while(cin >> s){
        int maxm = 0;
        add();
        manacher();
        for(int i = 1;i <= str.size() - 1;i ++){
            maxm = max(maxm,p[i]-1);
        }
        cout << maxm << endl;
    }
    return 0;
}