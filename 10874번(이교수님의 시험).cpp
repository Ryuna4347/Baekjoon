#include <iostream>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int isPerfect = true;
		for (int j = 0; j < 10; j++) {
			int answer;
			cin >> answer;
			if (j % 5 + 1 != answer) {
				isPerfect = false;
			}
		}
		if (isPerfect) { cout << (i + 1) << "\n"; }
	}
	return 0;
}