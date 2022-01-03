// 小明刚刚看完电影《第39级台阶》，离开电影院的时候，
// 他数了数礼堂前的台阶数，恰好是39级！站在台阶前，他突然又想着一个问题：
// 如果我每一步只能迈上1个或2个台阶，先迈左脚，
// 然后左右交替，最后一步是迈右脚，
// 也就是说一共要走偶数步。
// 那么，上完39级台阶，有多少种不同的上法呢？
// 请你利用计算机的优势，帮助小明寻找答案。
// 要求提交的是一个整数。

#include <bits/stdc++.h>
using namespace std;

void move(int stage, int step, int &cnt) {
    if (stage > 0) {
        move(stage - 1, step + 1, cnt);
        move(stage - 2, step + 1, cnt);
    } else if (stage == 0 && step % 2 ==0) {
        cnt++;
        return;
    } else {
        return;
    }
}

int main(void) {
    int stage = 39;
    int step = 0;
    int cnt = 0;
    move(stage, step, cnt);
    cout << cnt;
    return 0; 
}
