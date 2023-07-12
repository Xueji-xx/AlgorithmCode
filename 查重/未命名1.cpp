/*#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// ��ȡ�ļ����ݵ��ַ�����
std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return content;
}

// �����ַ������ƶ�
double similarity(const std::string& str1, const std::string& str2) {
    int len1 = str1.length();
    int len2 = str2.length();
    int len = std::max(len1, len2);
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (i < len1 && i < len2 && str1[i] == str2[i]) {
            count++;
        }
    }
    return static_cast<double>(count) / len;
}

int main() {
	freopen("a.txt","r+",stdin);
    std::string filename1, filename2;
    std::string content1, content2;
    for(int i = 1;i <= 295;i ++){
        std::getline(std::cin, filename1);
        content1 = readFile(filename1);
        for(int j = 1;j <= 295;j ++){
            std::getline(std::cin, filename2);
            content2 = readFile(filename2);
            double sim = similarity(content1, content2);
            std::cout << "The similarity of " << filename1 << " and " << filename2 << " is " << sim << std::endl;
        }
    }
    return 0;
}*/


/*#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    // �򿪰��������ļ����Ƶ� txt �ļ�
    std::ifstream fileList("a.txt");
    std::string filename;

    // ѭ����ȡÿ���ļ�����
    while (std::getline(fileList, filename)) {
        std::fstream file(filename, std::ios::in | std::ios::out);
        std::string inputStr, outputStr;

        // ��ȡ�ļ�����
        if (file.is_open()) {
            while (std::getline(file, inputStr)) {
                outputStr += inputStr;
            }
            file.clear(); // ����ļ�״̬
            file.seekp(0, std::ios::beg); // ���ļ�ָ���Ƶ��ļ���ͷ
        }

        // �����ַ���
        for (char c : outputStr) {
            if (c == ' ' || c == '\n' || c == '	') {
                continue;
            }
            outputStr += c;
        }

        // ������������д��ԭ�ļ�
        file << outputStr;

        // ����������ַ���
        std::cout << outputStr << std::endl;
    }

    return 0;
}*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

int main() {
    // ���ļ������б��txt�ļ�
    ifstream infile("a.txt");
    if (!infile) {
        cerr << "�޷����ļ�" << endl;
        return 1;
    }

    // ��ȡ�ļ������б�
    vector<string> filenames;
    string filename;
    while (getline(infile, filename)) {
        filenames.push_back(filename);
    }

    // ѭ������ÿ���ļ��������ļ������в���
    for (string filename : filenames) {
        // ���ļ�
        ifstream infile(filename);
        if (!infile) {
            cerr << "�޷����ļ� " << filename << endl;
            continue;
        }

        // �����ļ�����
        // ...
		 // ��ȡ�ļ�����
	    string content((istreambuf_iterator<char>(infile)), (istreambuf_iterator<char>()));
	
	    // ɾ��ע��
	    content = regex_replace(content, regex("/\\*.*?\\*/|//.*\n"), "");
	
	    // ɾ���ո񡢿հ��ַ�������
	    content = regex_replace(content, regex("[\\s\n]+"), "");
	
	    // �������������
	    cout << content << endl;
	        // �ر��ļ�
	        infile.close();
	    }

    // �ر��ļ������б��txt�ļ�
    infile.close();

    return 0;
}

