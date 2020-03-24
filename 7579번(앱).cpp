#include <iostream>
#include <algorithm>

using namespace std;

int dp[101][10001]; //�� ����, �ִ� ����� ���(100*100)
int memory[101], restart[101];

int main(void) {
	int n, M; //�� ����, �䱸 �޸�
	cin >> n >> M;

	for (int i = 1; i <= n; i++) {
		int m;
		cin >> m;
		memory[i] = m;
	}
	for (int i = 1; i <= n; i++) {
		int c;
		cin >> c;
		restart[i] = c;

	}
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0; //�ƹ��͵� ���� �ʾ��� ��� �޸𸮵� 0��ŭ ���� �� �ִ�.
		for (int j = 1; j <= n * 100; j++) { //����� ���� �� �۸��� 100�� �ִ��̹Ƿ� ���� 10000�� ĭ�� �ʱⰪ�� �� ä���� �ʿ䰡 ����. 
			dp[i][j] = -1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n * 100; j++) { //����� ���� �� �۸��� 100�� �ִ��̹Ƿ� ���� 10000�� ĭ�� �ʱⰪ�� �� ä���� �ʿ䰡 ����. 
			if (dp[i - 1][j] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j]); //��� ������ ��
				dp[i][j + restart[i]] = max(dp[i][j + restart[i]], dp[i - 1][j] + memory[i]); //��� ���� �� (����� ����� ��ġ�� ��쵵 �����Ƿ� �ִ밪�� ����)
			}
		}
	}

	//������ ���� dp���� �޸� ���� M�̻��� ������ j �� �� ���� ���� ���� ���Ѵ�.
	int minVal = 10000000;
	for (int j = 1; j <= 10000; j++) { //M�� 1 �̻��̹Ƿ� 0�� �Ƚᵵ �ȴ�.
		if (dp[n][j] >= M) {
			minVal = min(minVal, j);
		}
	}
	cout << minVal << endl;
	return 0;
}