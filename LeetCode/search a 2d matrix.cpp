#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int hi = matrix.size();
        int low = 0;
        int mid;

        while (low < hi) {
            mid = (low + hi) / 2;
         

            if (matrix[mid][0] <= target && matrix[mid][n - 1] >= target) {
              //  cout << "dukse" << endl;
                int hi2 = n;
                int low2 = 0;
                int mid2;

                while (low2 < hi2) {
                    
                    mid2 = (hi2 + low2) / 2;

                //    cout << matrix[mid][mid2] << "  " << mid2 << endl;


                    if (matrix[mid][mid2] == target) {
                        return true;
                    } else if (matrix[mid][mid2] < target) {
                        low2 = mid2 + 1;
                    } else if (matrix[mid][mid2] > target) {
                        hi2 = mid2;
                    }
                }
                return false;
            } else if (matrix[mid][0] > target) {
             //   cout << " hi " << endl;
                hi = mid ;
            } else if (matrix[mid][n - 1] < target) {
            //    cout << "low " << endl;
                low = mid + 1;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 35;
 //   cout << "Enter target value: ";
 //   cin >> target;
    
    bool found = sol.searchMatrix(matrix, target);
    if (found) {
        cout << "Target found in the matrix." << endl;
    } else {
        cout << "Target not found in the matrix." << endl;
    }
    return 0;
}
