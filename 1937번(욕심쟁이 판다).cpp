#include <iostream>
#include <algorithm>

using namespace std;

int dp[501][501];
bool visited[501][501];
int arr[501][501];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int n;

int Func(int i, int j) {
	if (visited[i][j]) {
		return dp[i][j];
	}

	int nearMax = 0;
	for (int k = 0; k < 4; k++) {
		if (i + dir[k][0] < 0 || i + dir[k][0] >= n || j + dir[k][1] < 0 || j + dir[k][1] >= n) continue;
		if (arr[i][j] < arr[i + dir[k][0]][j + dir[k][1]]) {  //주변에 현재위치보다 더 많은 먹이가 있는 경우
			nearMax = max(nearMax, Func(i + dir[k][0], j + dir[k][1]));
		}
	}
	dp[i][j] = nearMax + 1;
	visited[i][j] = true;
	return dp[i][j];
}

int main(void) {
	int max = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			dp[i][j] = 1;
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == 1) {
				Func(i, j);
			}
			max = max > dp[i][j] ? max : dp[i][j];
		}
	}

	cout << max << endl;
	return 0;
}