#include <iostream>

using namespace std;

int main(void) {
	int arr[10];
	int n, k, result = 0;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int idx = n - 1;
	while (k > 0 || idx >= 0) {
		int num = k / arr[idx];
		result += num;
		k -= num * arr[idx--];
	}
	cout << result << endl;
	return 0;
}