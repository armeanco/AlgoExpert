#include <string>
#include <algorithm>

bool isPalindrome(std::string str) {
  std::string isP = str;
  std::reverse(isP.begin(), isP.end());
  return isP == str;
}
