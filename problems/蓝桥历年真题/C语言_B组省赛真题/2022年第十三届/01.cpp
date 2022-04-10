 #include <bits/stdc++.h>
 using namespace std;
 
 int main(void) {
 	int num;
 	cin >> num;
 	vector<int> c;
 	while(num) {
 		c.push_back(num % 9);
 		num /= 9;
 	}
 	for (int i = 0; i < c.size(); i++)
 	cout << c[i];
 	return 0;
 } 
