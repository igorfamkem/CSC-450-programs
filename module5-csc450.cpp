#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Function to reverse the contents of a file
void reverseFileContent(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (!inFile || !outFile) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    std::reverse(content.begin(), content.end());

    outFile << content;
    inFile.close();
    outFile.close();
}

int main() {
    std::string userInput;
    std::string fileName = "CSC450_CT5_mod5.txt";
    std::ofstream outFile;

    // Open file in append mode
    outFile.open(fileName, std::ios::app);
    if (!outFile) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    // Get user input
    std::cout << "Enter text to append to the file: ";
    std::getline(std::cin, userInput);

    // Write user input to the file
    outFile << userInput << std::endl;
    outFile.close();

    // Reverse the content of the file and store it in CSC450-mod5-reverse.txt
    reverseFileContent(fileName, "CSC450-mod5-reverse.txt");

    std::cout << "Data appended and reversed file created successfully." << std::endl;

    return 0;
}

