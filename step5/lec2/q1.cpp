#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<char> sortCharactersByFrequency(const string& s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    vector<pair<char, int>> vec(freq.begin(), freq.end());
    sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second > b.second;
    });
    vector<char> result;
    for (const auto& p : vec) result.push_back(p.first);
    return result;
}
