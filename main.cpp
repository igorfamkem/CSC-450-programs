#include <iostream>
#include <string>

using namespace std;

int main() {
    // Variables to hold user inputs
    string string1, string2, result;

    // Loop to get user input three times
    for (int i = 0; i < 3; ++i) {
        cout << "Enter the first string: ";
        getline(cin, string1); // Get first string input

        cout << "Enter the second string: ";
        getline(cin, string2); // Get second string input

        // Concatenate the strings
        result = string1 + string2;

        // Display the result
        cout << "Concatenated result: " << result << endl << endl;
    }

    return 0;
}
