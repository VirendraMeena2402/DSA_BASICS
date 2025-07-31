#include <string>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = "";
        int count = 0;
        while ((int)repeated.size() < (int)b.size()) {
            repeated += a;
            count++;
        }
        if (repeated.find(b) != string::npos) return count;
        repeated += a;
        count++;
        if (repeated.find(b) != string::npos) return count;
        return -1;
    }
};
