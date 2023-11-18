
#include <iostream>
#include <string>

int main() {
    // Sample string
    std::string myString = "The quick brown fox jumps over the lazy dog.";

    // Find the starting position of the substring
    size_t startPos = myString.find("brown");

    // Check if the substring was found
    if (startPos != std::string::npos) {
        // Replace the substring
        myString.replace(startPos, 5, "red");

        // Output the modified string
        std::cout << "Modified string: " << myString << std::endl;
    } else {
        std::cout << "Substring not found." << std::endl;
    }

    return 0;
}
