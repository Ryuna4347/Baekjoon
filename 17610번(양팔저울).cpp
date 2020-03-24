#include <iostream>
#include <string.h>

using namespace std;

int n;
int arr[13];
bool dp[2600001];

void Dynamic(int i, int sum) { //n : n번째 추, sum : 현재까지의 무게추 합(우측 기준, 좌측의 추는 sum에서 무게를 빼서 진행)
	if (i == n - 1) { //마지막 추까지 온 경우 최종 계산
		//현재까지 달 수 있는 무게인가(추 무게가 음수가 나올 수 없으므로) 체크를 하지 않았으므로 지금 마지막 추 계산 시 진행한다.
		if (sum + arr[i] > 0) { //우측에 추를 달 경우
			dp[sum + arr[i]] = true;
		}
		if (sum > 0) {
			dp[sum] = true;
		}
		if (sum - arr[i] > 0) {
			dp[sum - arr[i]] = true;
		}
		return;
	}
	Dynamic(i + 1, sum - arr[i]); //좌측에 추를 달 경우
	Dynamic(i + 1, sum); //추를 사용 안할 경우
	Dynamic(i + 1, sum + arr[i]); //추를 사용할 경우
}

int main(void) {
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	memset(dp, false, dp[0] + sum);

	Dynamic(0, 0); //0번째 추부터, 현재 아무것도 없으므로 무게는 0

	int count = 0;
	for (int i = 1; i <= sum; i++) {
		if (dp[i] == true) {
			count++;
		}
	}
	cout << sum - count << endl;
	return 0;
}