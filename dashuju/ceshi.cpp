#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;



int main(){
    ifstream ifs;
    ifs.open("us-counties.txt",ios::in);
    if (!ifs.is_open()){
		cout << "文件打开失败！" << endl;
		return 0;
	}
    string s;
    while(getline(ifs,s)){
        string date;
        string country;
        string city;
        int cases;//感染
        int death;//死亡
        int last_pos = 0;
        bool flag = true;
        int cnt = 0;
        string t;
        for(int i = 0;i < s.length();i ++){
            if(s[i] == '	' && flag){
                switch (cnt){
                    case 0:
                        cnt ++;
                        date = s.substr(last_pos,i - last_pos);
                        break;
                    case 1:
                        cnt ++;
                        country = s.substr(last_pos,i - last_pos);
                        break;
                    case 2:
                        cnt ++;
                        city = s.substr(last_pos,i - last_pos);
                        break;
                    case 3:
                        cnt ++;
                        t = s.substr(last_pos,i - last_pos);
                        for(auto x : t){
                            cases *= 10;
                            cases += (x - '0');
                        }
                        break;
                    case 4:
                        t = s.substr(last_pos,i - last_pos);
                        cout << "***" << t << endl;
                        for(auto x : t){
                            death *= 10;
                            death += (x - '0');
                        }
                        break;
                    default:
                        break;
                }
                flag = false;
            }
            else if(s[i] != '	' && s[i-1] == '	'){
                flag = true;
                last_pos = i;
            }
        }
        cout << date << endl;
        cout << country << endl;
        cout << city << endl;
        cout << cases << endl;
        cout << death << endl;
        break;
    }
    return 0;
}