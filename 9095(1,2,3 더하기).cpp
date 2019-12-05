#include <iostream>
#include <cstring>
using namespace std;

int dp[11];

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;

		memset(dp, 0, sizeof(dp));

		dp[1] = 1; //0+1
		dp[2] = 2; //1+1, 0+2
		dp[3] = 4;
		for (int j = 4; j <= t; j++) {
			dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
		}
		cout << dp[t] << endl;
	}
	return 0;
}
