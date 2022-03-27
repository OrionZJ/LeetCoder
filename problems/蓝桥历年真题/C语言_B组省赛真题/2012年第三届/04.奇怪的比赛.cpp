// 某电视台举办了低碳生活大奖赛。
// 题目的计分规则相当奇怪：每位选手需要回答10个问题（其编号为1到10），越后面越有难度。
// 答对的，当前分数翻倍；
// 答错了则扣掉与题号相同的分数（选手必须回答问题，不回答按错误处理）。
// 每位选手的起步分都是10分，某获胜选手最终得分刚好是100分，
// 如果不让你看比赛过程，你能推断出他（她）哪个题目答对了，哪个题目答错了吗？
// 如果把答对的记为1，答错的记为0，则10个题目的回答情况可用仅含1和0的串来表示，
// 如0010110011就是可能的情况。
// 你的任务是算出所有可能情况，每个答案占一行。

#include <bits/stdc++.h>
using namespace std;

void solve(int grade, int index, int num[]) {
    if (index > 11) return;
    if (grade == 100 && index == 11) {
        for (int i = 1; i < 11; i++) {
            cout << num[i];
        }
        cout << endl;
        return;
    }

    num[index] = 1;
    solve(grade*2, index + 1, num);

    num[index] = 0;
    solve(grade - index, index + 1, num);
}

int main(void) {
    int num[11] = {0,};
    solve(10, 1, num); 
    return 0;
}
