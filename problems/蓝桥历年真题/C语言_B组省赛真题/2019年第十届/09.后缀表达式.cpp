// ���� N ���Ӻš�M �������Լ� N + M + 1 ������ A 1 ,A 2 ,������ ,A N+M+1 ��С
// ����֪������������ N ���Ӻš�M �������Լ� N + M +1 �������ճ��ĺϷ���
// ��׺���ʽ�У������������һ����
// �������������Ľ����
// ����ʹ��1 2 3 + -���� ��2 3 + 1 -�� �����׺���ʽ����� 4�������ġ�
// �����ʽ:
// ��һ�а����������� N �� M��
// �ڶ��а��� N + M + 1 ������ A 1 ,A 2 ,������ ,A N+M+1 ��
// �����ʽ:
// ���һ������������𰸡�

#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n + m + 1);
	int sum = 0; 
	for (int i = 0; i < arr.size(); i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int minPos = -1;
	int maxNeg = -1;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] < 0) {
			maxNeg = i;
		} 
		else if (arr[i] > 0) {
			minPos = i;
			break;
		}
	}
	if (maxNeg == arr.size() - 1) {  // ȫ�� 
		for (int i = 0; i < maxNeg; i++) {
			sum -= arr[i];
		} 
		sum += maxNeg;
	} 
	else if (minPos == 0) {  // ȫ��
		sum -= arr[minPos];
		for (int i = 1; i < arr.size(); i++) {
			sum += arr[i];
		} 
	}
	else {  // �����и�
		int minAbs = INT_MAX;
		for (int i = 0; i < arr.size(); i++) {
			arr[i] = abs(arr[i]);
			sum += arr[i];
			if (arr[i] < minAbs) minAbs = arr[i];
		} 
		sum -= 2 * minAbs;
	}
	cout << sum;
	return 0;
}
// 2 2
// -2 -1 0 2 3
// 0 -2 - -1 - 2 3 + +