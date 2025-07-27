#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int maxRow = 0;
            for (int i = 0; i < m; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            bool leftSmaller = (mid == 0) || (mat[maxRow][mid] > mat[maxRow][mid - 1]);
            bool rightSmaller = (mid == n - 1) || (mat[maxRow][mid] > mat[maxRow][mid + 1]);

            if (leftSmaller && rightSmaller) {
                return {maxRow, mid};
            } else if (!leftSmaller) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return {-1, -1};
    }
};
