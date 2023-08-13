#include <cstring>
#include <string>

#include <cmath>
#include <iostream>
#include <regex>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> numbers;
    string subject = s;
    smatch match;
    regex r("\\d+");
    int i = 1;
    for (auto i = sregex_iterator{s.begin(), s.end(), r}; i != sregex_iterator{}; ++i) {
        numbers.push_back(stoi(i->str()));
    }
    int maxNumber = *max_element(numbers.begin(), numbers.end());
    cout << maxNumber << "\n";
}