#include <iostream>

using namespace std;


int main(void) {
	int digit_list[4];
	int n;
	cin >> n;

	while (n-- > 0) {
		int digit_index = 0;
		int a, b;

		cin >> a >> b;
		digit_list[digit_index++] = (a%10==0)?10:a%10; //10번 컴퓨터에 대한 예외처리

		int tempA = a;
		for (int i = 2; i <= b; i++) {
			tempA *= a;
			tempA %= 10;

			if (tempA == 0) { //10번 컴퓨터에 대한 예외처리
				tempA = 10;
			}

			if (tempA == digit_list[0]) {
				break;
			}
			else {
				digit_list[digit_index++] = tempA;
			}
		}

		int result = (b - 1) % digit_index;
		cout << digit_list[result] << endl;
	}
	return 0;
}