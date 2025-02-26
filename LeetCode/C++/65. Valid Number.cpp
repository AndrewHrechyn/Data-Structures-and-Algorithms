#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenExponent = false;
        bool seenDot = false;
        for (int i = 0; i < s.length(); i++) {
            char curr = s[i];
            if (curr >= '0' && curr <= '9') {
                seenDigit = true;
            } else if (curr == '+' || curr == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else if (curr == 'e' || curr == 'E') {
                if (seenExponent || !seenDigit) {
                    return false;
                }
                seenExponent = true;
                seenDigit = false;
            } else if (curr == '.') {
                if (seenDot || seenExponent) {
                    return false;
                }
                seenDot = true;
            } else {
                return false;
            }
        }
        return seenDigit;
    }
};

int main() {
    Solution solution;
    string s;
    
    cout << "Enter a string: ";
    cin >> s;
    
    bool result = solution.isNumber(s);
    cout << "Is valid number? " << (result ? "Yes" : "No") << endl;
    
    return 0;
}
