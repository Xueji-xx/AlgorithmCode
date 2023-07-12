#include <iostream>
using namespace std;

string st[]={"-F","-Cl","-Br","-I","-CH3","-CH2CH3","-CH2CH2CH3","-H"};

int main(){
    string s1,s2,s3,s4;
    int n;
    cin>>n;
    for(int i = 0;i < n;i ++){
        cin>>s1>>s2>>s3>>s4;
        if(s1 == s3 || s2 == s4){
            cout<<"None"<<endl;
            continue;
        }
        else if(s2 == s1 || s3 == s4){
            cout<<"Cis"<<endl;
            continue;
        }
        else if(s1 == s4 || s2 == s3){
            cout<<"Trans"<<endl;
            continue;
        }
        else{
            int a1,a2,a3,a4;
            a1 = a2 = a3 = a4 = 0;
            for(int i = 0;i <= 7;i ++){
                if (s1==st[i]) a1=i;
				if (s2==st[i]) a2=i;
				if (s3==st[i]) a3=i;
				if (s4==st[i]) a4=i;
            }
            if(a1 < a3){
                if(a2 < a4){
                    cout<<"Zasamman"<<endl;
                }
                else cout<<"Entgegen"<<endl;
            }
            else{
                if(a2 > a4){
                    cout<<"Zasamman"<<endl;
                }
                else cout<<"Entgegen"<<endl;
            }
        }
    }
    return 0;
}