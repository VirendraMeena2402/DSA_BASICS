#include<iostream>
using namespace std;

class Solution {
public:
    int reverseNumber(int n) {
        int new_dig = 0,rem = 0;
        while(n != 0){
            rem = n%10;
            new_dig = new_dig*10 + rem;
            n /=10;
        }
        cout<<new_dig;
    }
};