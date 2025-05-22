#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(std::string content, const std::string& s1, const std::string& s2) {
    std::string result;
    size_t pos = 0;
    size_t found;

    if (s1.empty())
        return content;

    while ((found = content.find(s1, pos)) != std::string::npos) {
        result += content.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result += content.substr(pos);
    return result;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream inputFile(filename.c_str());
    if (!inputFile) {
        std::cerr << "Error: Cannot open input file." << std::endl;
        return 1;
    }

    std::string content((std::istreambuf_iterator<char>(inputFile)),
                         std::istreambuf_iterator<char>());
    inputFile.close();

    std::string replaced = replaceAll(content, s1, s2);

    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile) {
        std::cerr << "Error: Cannot create output file." << std::endl;
        return 1;
    }

    outputFile << replaced;
    outputFile.close();

    return 0;
}
