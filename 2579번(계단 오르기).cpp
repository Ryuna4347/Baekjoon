#include <iostream>
#include <algorithm>

using namespace std;

long long arr[301];
long long dp[301];

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2]; //��ĭ������ �������� �� �� �ֱ� ������ 2�� ��� 1,2 ��� ��°� ������ �̵��̴�.

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + arr[i - 1], dp[i - 2])+arr[i];
	}
	cout << dp[n] << endl;
	return 0;
}

