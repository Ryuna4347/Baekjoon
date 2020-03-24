#include <iostream>
#include <algorithm>

using namespace std;

int dp[101][10001]; //앱 갯수, 최대 재시작 비용(100*100)
int memory[101], restart[101];

int main(void) {
	int n, M; //앱 갯수, 요구 메모리
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
		dp[i][0] = 0; //아무것도 빼지 않았을 경우 메모리도 0만큼 얻을 수 있다.
		for (int j = 1; j <= n * 100; j++) { //재실행 값은 각 앱마다 100이 최대이므로 굳이 10000개 칸의 초기값을 다 채워줄 필요가 없다. 
			dp[i][j] = -1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n * 100; j++) { //재실행 값은 각 앱마다 100이 최대이므로 굳이 10000개 칸의 초기값을 다 채워줄 필요가 없다. 
			if (dp[i - 1][j] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j]); //사용 안했을 때
				dp[i][j + restart[i]] = max(dp[i][j + restart[i]], dp[i - 1][j] + memory[i]); //사용 했을 때 (재시작 비용이 겹치는 경우도 있으므로 최대값을 저장)
			}
		}
	}

	//마지막 어플 dp에서 메모리 값이 M이상이 나오는 j 값 중 제일 작은 값을 구한다.
	int minVal = 10000000;
	for (int j = 1; j <= 10000; j++) { //M이 1 이상이므로 0은 안써도 된다.
		if (dp[n][j] >= M) {
			minVal = min(minVal, j);
		}
	}
	cout << minVal << endl;
	return 0;
}