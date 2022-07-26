#include <iostream>
#include <fstream>
#include <vector>

namespace spec {

std::vector<std::string> get_strings() {
  std::vector<std::string> lines;
  std::ifstream file("../input.txt");
  if (file.is_open()) {
    std::string str;
    while (std::getline(file, str)) {
      lines.push_back(str);
    }
  }
  return lines;
}

std::pair<std::vector<bool>, std::vector<bool>>
get_gamma_and_epsilon(std::vector<std::string>& vec) {
  std::vector<bool> gamma(12);
  std::vector<bool> epsilon(12);
  int count_of_ones{};
  for (int i{}; i < 12; ++i) {
    count_of_ones = 0;
    for (int j{}; j < 1000; ++j) {
      if (vec[j][i] == '1')
        ++count_of_ones;
    }
    if (count_of_ones >= 500) {
      gamma[i] = true;
      epsilon[i] = false;
    }
    else {
      gamma[i] = false;
      epsilon[i] = true;
    }
  }
  return std::make_pair(gamma, epsilon);
}

std::string get_oxygen(std::vector<std::string>& lines) {
  int count{};
  for (int i{}; i < 12; ++i) {
    count = 0;
    for (int j{}; j < lines.size(); ++j)
      count += lines[j][i] - 48;
    if (count >= (lines.size() - count)) {
      for (int j = lines.size() - 1; j >= 0; --j)
        if (lines[j][i] == 48)
          lines.erase(lines.begin() + j);
    }
    else {
      for (int j = lines.size() - 1; j >= 0; --j)
        if (lines[j][i] == 49)
          lines.erase(lines.begin() + j);
    }
  }
  return lines[0];
}

std::string get_carbon_dioxide(std::vector<std::string>& lines) {
  int count;
  for (int i{}; i < 12; ++i) {
    count = 0;
    for (int j{}; j < lines.size(); ++j)
      count += lines[j][i] - 48;
    if (count >= (lines.size() - count)) {
      for (int j = lines.size() - 1; j >= 0; --j)
        if (lines[j][i] == 49)
          lines.erase(lines.begin() + j);
    }
    else {
      for (int j = lines.size() - 1; j >= 0; --j)
        if (lines[j][i] == 48)
          lines.erase(lines.begin() + j);
    }
  }
  return lines[0];
}

} // spec

int main() {
  std::vector<std::string> result = spec::get_strings();
  std::vector<std::string> result2 = result;
  std::cout << spec::get_oxygen(result) << std::endl;
  std::cout << spec::get_carbon_dioxide(result2) << std::endl;

}