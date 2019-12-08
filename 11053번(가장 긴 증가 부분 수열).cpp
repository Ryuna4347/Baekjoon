#include <iostream>
using namespace std;

int arr[1000];
int dp[1000];

int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		int biggestPartial = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				biggestPartial = biggestPartial > dp[j] ? biggestPartial : dp[j];
			}
		}
		dp[i] = biggestPartial + 1;
		max = max > dp[i] ? max : dp[i];
	}
	cout << max << endl;
	return 0;
}