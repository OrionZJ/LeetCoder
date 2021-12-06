// 假设有两种微生物X和Y，X出生后每隔3分钟分裂一次（数目加倍），Y出生后每隔2分钟分裂一次（数目加倍）。
// 一个新出生的X，半分钟之后吃掉1个Y，且从此开始每隔1分钟吃掉1个Y。已知新出生的X=10，Y=89，求60分钟后Y的数目。若X=10，Y=90呢？
// 本题的要求就是写出这两种初始条件下，60分钟后Y的数目。题目的结果令你震惊吗？
// 这不是简单的数字游戏！真实的生物圈有着同样脆弱的性质！也许因为你消灭的那只Y就是最终导致Y种群灭绝的最后一根稻草！

#include <bits/stdc++.h>
using namespace std;


int main(void) {
    long long x = 10, y = 89;
    
    for (int halfMin = 0; halfMin <= 120; halfMin++) {
        
        if (halfMin % 2 == 1) {
            y -= x;
        }
        
        if (halfMin % 6 == 0) {
            x *= 2;
        }
        if (halfMin % 4 == 0) {
            y *= 2;
        }

    }

    cout << x << endl << y;
}

