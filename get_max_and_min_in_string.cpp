#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<int> parseStringToIntVector(const std::string& input) {
    std::vector<int> result;
    std::istringstream iss(input);
    int num;
    while (iss >> num) {
        result.push_back(num);
    }
    return result;
}

std::string highAndLow(const std::string& numbers) {
  std::vector<int> v = parseStringToIntVector(numbers);
  int resmax = v[0], resmin = v[0];
  for (auto el : v) {
    if (el > resmax)
      resmax = el;
    if (el < resmin)
      resmin = el;
  }
  return std::to_string(resmax) + " " + std::to_string(resmin);
}

int main() {
  std::cout << highAndLow("23 32 44 555 -1 0.12") << "\n";
  return 0;
}
