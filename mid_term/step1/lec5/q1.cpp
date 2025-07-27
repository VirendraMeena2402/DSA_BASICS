#include<iostream>
using namespace std;

class Solution{	
	public:
		int NnumbersSum(int N){
			if(N == 0){
                return 0;
            }
            int sum = 0;
            sum = N + NnumbersSum(N-1);
            return sum;
		}
};