#include <iostream>
#include <string.h>

using namespace std;

int n;
int arr[13];
bool dp[2600001];

void Dynamic(int i, int sum) { //n : n��° ��, sum : ��������� ������ ��(���� ����, ������ �ߴ� sum���� ���Ը� ���� ����)
	if (i == n - 1) { //������ �߱��� �� ��� ���� ���
		//������� �� �� �ִ� �����ΰ�(�� ���԰� ������ ���� �� �����Ƿ�) üũ�� ���� �ʾ����Ƿ� ���� ������ �� ��� �� �����Ѵ�.
		if (sum + arr[i] > 0) { //������ �߸� �� ���
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
	Dynamic(i + 1, sum - arr[i]); //������ �߸� �� ���
	Dynamic(i + 1, sum); //�߸� ��� ���� ���
	Dynamic(i + 1, sum + arr[i]); //�߸� ����� ���
}

int main(void) {
	int sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	memset(dp, false, dp[0] + sum);

	Dynamic(0, 0); //0��° �ߺ���, ���� �ƹ��͵� �����Ƿ� ���Դ� 0

	int count = 0;
	for (int i = 1; i <= sum; i++) {
		if (dp[i] == true) {
			count++;
		}
	}
	cout << sum - count << endl;
	return 0;
}