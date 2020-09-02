/*
将矩阵顺时针打印出来。
核心是边界条件。如果边界可以的话
方法1：递归，
方法2： 一般方法

*/
//逐层打印法
/*
从左向右，碰到数组的尾部或者是已经遍历过的，就变为重上往下
从上往下
从右向左
从下往上
核心是确定上下左右的边界
碰到右边界，就要向下

上边界 int up = 0;
int down = 2;
int left = 0;
int right = 2;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return {};
        }

        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> order;
        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom) {
            for (int column = left; column <= right; column++) {
                order.push_back(matrix[top][column]);
            }
            for (int row = top + 1; row <= bottom; row++) {
                order.push_back(matrix[row][right]);
            }
            if (left < right && top < bottom) {
                for (int column = right - 1; column > left; column--) {
                    order.push_back(matrix[bottom][column]);
                }
                for (int row = bottom; row > top; row--) {
                    order.push_back(matrix[row][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return order;
    }
};


*/