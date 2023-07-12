#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
// �����ַ����Ĺ�ϣֵ
size_t hash_string(const std::string& str) {
    size_t hash = 0;
    for (char c : str) {
        hash = hash * 31 + c;
    }
    return hash;
}

// �����ļ��Ĺ�ϣֵ
size_t hash_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        return 0;
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    return hash_string(content);
}

// ���������ļ������ƶ�
double similarity(const std::string& file1, const std::string& file2) {
    std::unordered_set<size_t> hash_set;
    size_t count = 0;
    size_t same_count = 0;

    // �����һ���ļ��Ĺ�ϣֵ
    size_t hash1 = hash_file(file1);
    if (hash1 != 0) {
        hash_set.insert(hash1);
        count++;
    }

    // ����ڶ����ļ��Ĺ�ϣֵ
    size_t hash2 = hash_file(file2);
    if (hash2 != 0) {
        count++;
        if (hash_set.count(hash2) > 0) {
            same_count++;
        } else {
            hash_set.insert(hash2);
        }
    }

    // �������ƶ�
    if (count == 0) {
        return 0;
    } else {
        return static_cast<double>(same_count) / count;
    }
}

int main() {
    std::ifstream filename_file("a.txt");
    if (!filename_file) {
        std::cerr << "Failed to open filenames.txt" << std::endl;
        return 1;
    }

    std::vector<std::string> filenames;
    std::string filename;
    while (std::getline(filename_file, filename)) {
        filenames.push_back(filename);
    }

    size_t num_files = filenames.size();
    std::vector<std::vector<double>> similarity_matrix(num_files, std::vector<double>(num_files, 0.0));

    for (size_t i = 0; i < num_files; i++) {
        for (size_t j = i + 1; j < num_files; j++) {
            double sim = similarity(filenames[i], filenames[j]);
            similarity_matrix[i][j] = sim;
            similarity_matrix[j][i] = sim;
        }
    }

    // ������ƶȾ���
    for (size_t i = 0; i < num_files; i++) {
        for (size_t j = 0; j < num_files; j++) {
            std::cout << similarity_matrix[i][j] << " ";
            if(similarity_matrix[i][j] != 0)cout << i << endl << j << endl << endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
