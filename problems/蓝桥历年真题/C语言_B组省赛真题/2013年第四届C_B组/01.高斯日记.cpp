// 大数学家高斯有个好习惯：无论如何都要记日记。
// 他的日记有个与众不同的地方，他从不注明年月日，
// 而是用一个整数代替，比如：4210。
// 后来人们知道，那个整数就是日期，它表示那一天是高斯出生后的第几天。
// 这或许也是个好习惯，它时时刻刻提醒着主人：
// 日子又过去一天，还有多少时光可以用于浪费呢？
// 高斯出生于1777年4月30日，在高斯发现的一个重要定理的日记上标注着5343，
// 因此可算出那天是1791年12月15日。
// 高斯获得博士学位的那天日记上标着8113，请你算出高斯获得博士学位的年月日。
// 提交答案的格式是：yyyy-mm-dd，例如：1980-03-21

#include <bits/stdc++.h>
using namespace std;

bool judgeYear(int year) {
    if (year % 4 == 0) return true;
    else return false;
}

int main(void) {
    int mark = 0;
    cin >> mark;
    int sumDay = mark + 31 + 28 + 31 + 30 - 1;    //设为1月1日出生
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int birthYear = 1777;

    int year = birthYear;
    int month = 1;
    int day = 0;

    while (sumDay >= 365) {    //小心mark = -1
        if (judgeYear(year)) {
            sumDay -= 366;
        } else {
            sumDay -= 365;
        }
        year++;
    }

    if (sumDay != -1) {
        for (int i = 1; i < 13; i++) {
            if (sumDay > days[i]) {
                month++;
                sumDay -= days[i];
            } else {
                break;
            }
        }
        day = sumDay;
    } else {
        year--;
        month = 12;
        day = 31;
    }
    
    cout << year << '-' ;
    if (month < 10) cout << '0' << month;
    else cout << month;
    if (day < 10) cout << '-'<< '0' << day;
    else cout << '-' << day;
    return 0;
}