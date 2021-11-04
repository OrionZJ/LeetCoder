#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int slowPointer = 0;
        int fastPointer = 0;
        int minSize = 0;
        while (fastPointer < nums.size() ) {        //尾指针不超出数组范围就一直循环
            int sum = 0;
            for (int i = slowPointer; i <= fastPointer; i++) {      //求窗口内数字和
                sum += nums[i];
            }
            int size = fastPointer - slowPointer + 1;       //求窗口长度
            if (sum >= target) {        //若得到子区间
                if (minSize == 0) minSize = size;       //第一次获得子区间，则取当前区间
                if (minSize > size) minSize = size;     //小于上一子区间,则取当前区间
                slowPointer++;      
            } 
            else fastPointer++;
        }
        return minSize;
    }
};
