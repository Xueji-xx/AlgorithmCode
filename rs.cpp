#include<iostream>
#include<string.h>
using namespace std;


int main(){
    //string s;
    char s[100];
    //cin>>s;
    scanf("%s",s+1);
    cout<<strlen(s+1)<<endl;
    /*s = '1' + s;
    cout<<s.length()<<endl;*/
    system("pause");
    return 0;
}