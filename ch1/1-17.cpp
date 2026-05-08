#include <iostream>
#include <vector>
#include <string>

int main() {
    const int LINE_SIZE = 80;
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(std::cin, line)) {
        if (line.length() > LINE_SIZE) {
            lines.push_back(line);
        }
    }

    std::cout << "-------------------\n";
    for (const auto& line : lines) {
        std::cout << line << std::endl;
    }
    return 0;
}
