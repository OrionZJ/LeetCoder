#include <bits/stdc++.h>
using namespace std;

class Apple {
    public:
        int _basketId;
        string _appleId;
        int _weight;
        int _diameter;
        Apple() {}
        Apple(int basketId, string appleId, int weight, int diameter) {
            this->_basketId = basketId;
            this->_appleId = appleId;
            this->_weight = weight;
            this->_diameter = diameter;
        }

        void show() {
            cout << this->_appleId << " " 
                 << this->_weight << " " 
                 << this->_diameter;
        }

};

class Basket {
    public:
        int _basketId;
        vector<Apple> _applesInBasket;
        Apple heaviestApple;
    
        Basket(int basketId, vector<Apple> &apples) {
            this->_basketId = basketId;
            for (int i = 0; i < apples.size(); i++) {
                if (apples[i]._basketId == this->_basketId)
                    this->_applesInBasket.push_back(apples[i]);
            }
        }

        void selectHeaviest() {
            this->heaviestApple = this->_applesInBasket[0];
            for (int i = 0; i < _applesInBasket.size(); i++) {
                if (_applesInBasket[i]._weight > heaviestApple._weight) {
                    this->heaviestApple = this->_applesInBasket[i];
                }
            }
        }

};



int main(void) {
    int appleNum;
    vector<Apple> apples;
    vector<Basket> baskets;
    cin >> appleNum;
    for (int i = 0; i < appleNum; i++) {
        int basketId;
        string appleId;
        int weight;
        int diameter;
        cin >> basketId;
        cin >> appleId;
        cin >> weight;
        cin >> diameter;
        apples.push_back(Apple(basketId,appleId,weight,diameter));
        int cnt = 0;
        for (int i = 0; i < baskets.size(); i++) {
            if (basketId == baskets[cnt]._basketId) break;
            cnt++;
        }
        if (cnt >= baskets.size() )
            baskets.push_back(Basket(basketId, apples));
    }

    for (int i = 0; i < baskets.size(); i++) {
        cout << baskets[i]._basketId << " ";
        baskets[i].selectHeaviest();
        baskets[i].heaviestApple.show();
        if (i < baskets.size() - 1) cout << "\n";        
    }
    
    return 0;
}