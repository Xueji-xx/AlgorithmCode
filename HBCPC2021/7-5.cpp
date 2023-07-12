#include<iostream>
#include<math.h>
using namespace std;
string s;

int main(){
    cin>>s;
    int cnt = 0;
    bool flag = true;
    bool flagx = false;
    if(s == "f(x)=0"){
        cout<<"f'(x)=0";
        return 0;
    }
    cout<<"f'(x)=";
    for(int i = 5;i <= s.length();i ++){
        int a = 0,b = 0;
        bool flag0 = false;
        if(s[i] == 'x'){// ax^b   a = suma
            flagx = true;
            int cnta = 1;
            int suma = 0;
            while(s[i-cnta] >= '0' && s[i-cnta] <= '9'){
                int x = s[i-cnta] - '0';
                int y = x * pow(10,cnta-1);
                suma += y;
                cnta++;
                flag0 = true;
            }
            if(suma == 0 && flag0 == true)continue;
            if(suma == 0){
                suma = 1;
            }
            if(s[i-cnta] == '-')suma = -suma;
            a = suma;
            int sumb = 0;
            if(s[i+1] == '^'){
                int cntb = 2;
                while(s[i+cntb] >= '0' && s[i+cntb] <= '9'){
                    int x = s[i+cntb] - '0';
                    sumb *= 10;
                    sumb += x;
                    cntb++;
                }
                b = sumb;
            }
            else b = 1;
            //Êä³ö
            if(a < 0)cout<<a*b;
            else{
                if(!flag){
                    cout<<'+';
                    cout<<a*b;
                }
                else{
                    cout<<a*b;
                    flag = false;
                }
            }
            if(b == 1)continue;
            if(b != 2){
                cout<<"x^";
                cout<<b-1;
            }
            else if(b == 2)cout<<'x';
        }
    }
    if(!flagx){
        cout<<0;
    }
    return 0;
}