```Cpp
#include <regex>
#include <iostream>
#include <unordered_map>
static std::unordered_map<std::string, std::vector<std::string>> tests = {
    {"a == b", {}},
    {"a!=b", {}},
    {"a>=b", {}},
    {"a<=b", {}},
    {"!a", {}},
    {"a||b", {}},
    {"a&&b", {}},
    {"a&b", {}},
    {"^a", {}}
};
std::vector<std::string> remove_spaces_from_tokens(std::vector<std::string> in) {
    std::vector<std::string> s;
    for (auto str : in) {
        std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
        str.erase(end_pos, str.end());
        if (!str.empty()) s.push_back(str);
    }
    return s;
}
void do_tests() {
    for (auto& kv : tests) {
        std::string input{kv.first};
        std::regex re("==|!=|>=|<=|!|\\|\\||&&|&|\\^");
        //std::regex re("==");
        std::sregex_token_iterator first{input.begin(), input.end(), re, -1}, last;//the '-1' is what makes the regex split (-1 := what was not matched)
        std::vector<std::string> tokens{first, last};
        kv.second = remove_spaces_from_tokens(tokens);
    }
}
void print_tests() {
    for (const auto& kv : tests) {
        std::cout << "Input: " << kv.first << " ";
        std::cout << "TokenCount: " << kv.second.size() << " ";
        std::cout << "Tokens: ";
        for (auto it = kv.second.begin(); it != kv.second.end(); ++it) {
            char e = std::next(it) == kv.second.end() ? '\n': ' ';
            std::cout << *it << e;
        }
    }
}
int main() {
    do_tests();
    print_tests();

}
```
