class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int topBorder = 1;
        int bottomBorder = n - 1;
        int leftBorder = 0;
        int rightBorder = n - 1;
        int i = 0; int j = 0;
        int val = 1;
        do {
            while (j <= rightBorder) {      //往右赋值直到右边界
                matrix[i][j++] = val++;
            }
            j--; val--;     //把加多的值减回来
            rightBorder--;      //右边界左缩一格

            while (i <= bottomBorder) {     //往下赋值直到下边界
                matrix[i++][j] = val++;
            }
            i--; val--;     //把加多的值减回来
            bottomBorder--;     //下边界上缩一格

            while (j >= leftBorder) {       //往左赋值直到左边界
                matrix[i][j--] = val++;
            }
            j++; val--;     //把加多的值减回来
            leftBorder++;       //左边界右缩一格

            while (i >= topBorder) {        //往上赋值直到上边界
                matrix[i--][j] = val++;
            }
            i++; val--;     //把加多的值减回来
            topBorder++;        //上边界下缩一格
        } while ( val < n * n);
        return matrix;
    }
};

int main(void) {
    Solution sol;
    sol.generateMatrix(4);
    return 0;
}