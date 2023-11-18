#include <iostream>
#include <string>

int main()
{
  std::string str{ "I saw a red car yesterday." };
  size_t startPos = str.find("red");

    // Check if the substring was found
  if (startPos != std::string::npos) {
      str.replace(startPos, 3, "blue");
  }

  std::cout << str << '\n'; // I saw a blue car yesterday.

  return 0;
}
