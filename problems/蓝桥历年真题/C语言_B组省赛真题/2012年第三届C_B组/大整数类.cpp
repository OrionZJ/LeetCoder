#include <bits/stdc++.h>
using namespace std;

class HugeInteger {
private:
    vector<int> data;
public:
    HugeInteger();
    HugeInteger(string num);
    HugeInteger operator+(const HugeInteger &t);
    friend ostream &operator<<(ostream &out, HugeInteger &a);
    ~HugeInteger();
};

HugeInteger::HugeInteger(string num) {
    int yu = num.size() % 4;
    for (int i = 0; i < num.size() - yu; i += 4) {
        int temp = num[num.size() - 1 - i] + num[num.size() - 2 - i]*10 + num[num.size() - 3 - i]*100 + num[num.size() - 4 - i]*1000;
        data.push_back(temp);
    }
    switch (yu) {
    case 1:
        data.push_back(num[0]);
        break;

    case 2:
        data.push_back(num[0]*10 + num[1]);
        break;

    case 3:
        data.push_back(num[0]*100 + num[1]*10 + num[2]);
        break;

    default:
        break;
    }    
}

HugeInteger HugeInteger::operator+(const HugeInteger &t) {
    HugeInteger sum;
    bool c = false;
    for (int i = 0; i < (data.size() > t.data.size() ? data.size():t.data.size()); i++) {
        if (i < (data.size() < t.data.size() ? data.size():t.data.size())) {
            int temp = data[i] + t.data[i];
            if (c == true) temp++;
            if (temp > 9999) {
                c = true;
                temp = temp % 10000;
            }
            else c = false;
            sum.data.push_back(temp);
        } else {
            int temp = (data.size() > t.data.size() ? data[i] : t.data[i]);
            if (c == true) temp++;
            if (temp > 9999) {
                c = true;
                temp = temp % 10000;
            }
            else c = false;
            sum.data.push_back(temp);
        }
    }
    return sum;
}

ostream &operator<<(ostream &out, HugeInteger &a) {
    for (int i = 0; i < a.data.size(); i++){
        cout << a.data[i];
    }
    
}

HugeInteger::~HugeInteger() {
}


int main() {
    HugeInteger n1("999999999999999999999999999999999999999999");
    HugeInteger n2("1");
    cout << n1 + n2;
}