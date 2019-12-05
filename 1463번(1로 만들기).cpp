#include <iostream>
#include <algorithm>

using namespace std;

//�׳� ���� ���� ���� ����(1 ���� �����ϴ� �ͺ��� �����°� �翬�� �� ���� ������ �� �ֱ� ����)
//�׸��� ������ 2�� ������ 1�� ������ ����� �����ϱ� ������ ���⸦ ��� �� �ϴ� �� �ƴϴ�.
//���� : (5->4->2)->1     5->2�� ���� n%2 �̺κ��� 5->4�� ��
int FindFastest(int n) {
	if (n <= 1) {
		return 0;
	}
	int val1 = FindFastest(n / 3) + n % 3 + 1; //�켱 3���� ������ �� 1ȸ, ���� 3���� ����������� �ʴ� ��� ���⸦ ���� 3���� ������ �������� ������ �̵��ϴ� Ƚ������ ���Ѵ�.
	int val2 = FindFastest(n / 2) + n % 2 + 1;
	return min(val1, val2);
}

int main(void) {
	int n;
	cin >> n;

	cout << FindFastest(n) << endl;
	return 0;
}


/*2�� ���

#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

int main(void) {
	clock_t start, end;
	start = clock();
	int n;
	cin >> n;
	int* dp = new int[n + 1];

	for (int i = 1; i < n + 1; i++) {
		dp[i] = 0;
	}

	for (int i = 2; i < n + 1; i++) {
		if ((i % 2 == 0) && (i % 3 == 0)) {
			dp[i] = min(min(dp[i / 2], dp[i / 3]), dp[i - 1]) + 1;
		}
		else if (i % 2 == 0) {
			dp[i] = min(dp[i / 2], dp[i - 1]) + 1;

		}
		else if (i % 3 == 0) {
			dp[i] = min(dp[i / 3], dp[i - 1]) + 1;

		}
		else {
			dp[i] = dp[i - 1] + 1;
		}
	}

	cout << dp[n] << "\n";
	end = clock();
	cout << (double)(end - start) << "ms" << endl;
	return 0;
}
*/