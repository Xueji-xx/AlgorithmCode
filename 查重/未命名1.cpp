/*#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// 读取文件内容到字符串中
std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return content;
}

// 计算字符串相似度
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
    // 打开包含所有文件名称的 txt 文件
    std::ifstream fileList("a.txt");
    std::string filename;

    // 循环读取每个文件名称
    while (std::getline(fileList, filename)) {
        std::fstream file(filename, std::ios::in | std::ios::out);
        std::string inputStr, outputStr;

        // 读取文件内容
        if (file.is_open()) {
            while (std::getline(file, inputStr)) {
                outputStr += inputStr;
            }
            file.clear(); // 清除文件状态
            file.seekp(0, std::ios::beg); // 将文件指针移到文件开头
        }

        // 处理字符串
        for (char c : outputStr) {
            if (c == ' ' || c == '\n' || c == '	') {
                continue;
            }
            outputStr += c;
        }

        // 将处理后的内容写入原文件
        file << outputStr;

        // 输出处理后的字符串
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
    // 打开文件名称列表的txt文件
    ifstream infile("a.txt");
    if (!infile) {
        cerr << "无法打开文件" << endl;
        return 1;
    }

    // 读取文件名称列表
    vector<string> filenames;
    string filename;
    while (getline(infile, filename)) {
        filenames.push_back(filename);
    }

    // 循环遍历每个文件名，打开文件并进行操作
    for (string filename : filenames) {
        // 打开文件
        ifstream infile(filename);
        if (!infile) {
            cerr << "无法打开文件 " << filename << endl;
            continue;
        }

        // 进行文件操作
        // ...
		 // 读取文件内容
	    string content((istreambuf_iterator<char>(infile)), (istreambuf_iterator<char>()));
	
	    // 删除注释
	    content = regex_replace(content, regex("/\\*.*?\\*/|//.*\n"), "");
	
	    // 删除空格、空白字符、换行
	    content = regex_replace(content, regex("[\\s\n]+"), "");
	
	    // 输出处理后的内容
	    cout << content << endl;
	        // 关闭文件
	        infile.close();
	    }

    // 关闭文件名称列表的txt文件
    infile.close();

    return 0;
}

