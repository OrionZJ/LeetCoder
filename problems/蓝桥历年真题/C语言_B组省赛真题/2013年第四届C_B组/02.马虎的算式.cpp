// 小明是个急性子，上小学的时候经常把老师写在黑板上的题目抄错了。
// 有一次，老师出的题目是：36 x 495 = ?
// 他却给抄成了：396 x 45 = ?
// 但结果却很戏剧性，他的答案竟然是对的！！
// 因为 36 * 495 = 396 * 45 = 17820
// 类似这样的巧合情况可能还有很多，比如：27 * 594 = 297 * 54
// 假设 a b c d e 代表1~9不同的5个数字（注意是各不相同的数字，且不含0）
// 能满足形如： ab * cde = adb * ce 这样的算式一共有多少种呢？

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int candidate[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num[5] = {0,};
    int left = 0;
    int right = 0;
    int temp = 0;
    int cnt = 0;
    while (next_permutation(candidate, candidate + 9)) {
        left = candidate[0]*10 + candidate[1];
        right = candidate[2]*100 + candidate[3]*10 + candidate[4]; 
        if (left*1000 + right == temp) continue;
        int left1 = candidate[0]*100 + candidate[3]*10+ candidate[1];
        int right1 = candidate[2]*10 + candidate[4];
        if (left*right == left1*right1) cnt++;
        temp = left * 1000 + right;
    }
    cout << cnt;
    return 0;
}
