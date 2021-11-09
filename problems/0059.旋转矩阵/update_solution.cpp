#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int topBorder = 0;
        int bottomBorder = n - 1;
        int leftBorder = 0;
        int rightBorder = n - 1;
        int val = 1;
        while ( val <= n * n) {
            for (int j = leftBorder; j <= rightBorder; j++) {      //往右赋值直到右边界
                matrix[topBorder][j] = val++;
            }
            topBorder++;        //上边界下缩一格

            for (int i = topBorder; i <= bottomBorder; i++) {     //往下赋值直到下边界
                matrix[i][rightBorder] = val++;
            }
            rightBorder--;     //右边界左缩一格

            for (int j = rightBorder; j >= leftBorder; j--) {       //往左赋值直到左边界
                matrix[bottomBorder][j] = val++;
            }
            bottomBorder--;       //下边界上缩一格

            for (int i = bottomBorder; i >= topBorder; i--) {        //往上赋值直到上边界
                matrix[i][leftBorder] = val++;
            }
            leftBorder++;        //左边界右缩一格
        } 
        return matrix;
    }
};

int main(void) {
    Solution sol;
    sol.generateMatrix(4);
    return 0;
}