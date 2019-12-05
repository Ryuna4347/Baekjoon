#include <iostream>
#include <algorithm>

using namespace std;

//그냥 빼는 경우는 없는 이유(1 빼서 접근하는 것보다 나누는게 당연히 더 빨리 접근할 수 있기 때문)
//그리고 어차피 2로 나눌때 1이 남으면 빼기로 접근하기 때문에 빼기를 사용 안 하는 건 아니다.
//예시 : (5->4->2)->1     5->2로 갈때 n%2 이부분이 5->4인 것
int FindFastest(int n) {
	if (n <= 1) {
		return 0;
	}
	int val1 = FindFastest(n / 3) + n % 3 + 1; //우선 3으로 나누는 데 1회, 만약 3으로 나누어떨어지지 않는 경우 빼기를 통해 3으로 나누어 떨어지는 곳까지 이동하는 횟수까지 더한다.
	int val2 = FindFastest(n / 2) + n % 2 + 1;
	return min(val1, val2);
}

int main(void) {
	int n;
	cin >> n;

	cout << FindFastest(n) << endl;
	return 0;
}


/*2번 방법

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