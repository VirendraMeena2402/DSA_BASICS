#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;
        for (int i = 0; i <= n - m; i++) {
            if (haystack.compare(i, m, needle) == 0)
                return i;
        }
        return -1;
    }
};
