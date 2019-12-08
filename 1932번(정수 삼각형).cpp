#include <iostream>
#include <algorithm>

using namespace std;


int main(void) {
	int n;
	cin >> n;

	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[i + 1];
		for (int j = 0; j < i + 1; j++) {
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			int temp;
			cin >> temp;

			arr[i][j] = temp;
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) { //좌측 사이드
				arr[i][j] += arr[i - 1][j];
			}
			else if (j == i) { //우측 사이드
				arr[i][j] += arr[i - 1][j - 1];
			}
			else {
				arr[i][j] += max(arr[i - 1][j - 1], arr[i - 1][j]);
			}
		}
	}

	int maxVal = arr[n - 1][0];
	for (int i = 1; i < n; i++) {
		if (arr[n - 1][i] > maxVal) {
			maxVal = arr[n - 1][i];
		}
	}
	cout << maxVal << "\n";

	return 0;
}