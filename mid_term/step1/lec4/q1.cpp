#include<iostream>
using namespace std;

class Solution {
public:
    int countDigit(int n) {
        int count = 0,rem = 0;
        while(n != 0){
            rem = n%10;
            count++;
            n /=10;
        }
        return count;
    }
};