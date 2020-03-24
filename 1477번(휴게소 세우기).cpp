#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n, m, l, max = 0;
	int arr[100];

	cin >> n >> m >> l;

	arr[0] = 0; //고속도로 시작 지점
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	arr[n + 1] = l;

	sort(arr, arr + (n + 1));

	for (int i = 1; i <= n + 1; i++) {//휴게소 간 최대 거리 갱신
		max = (arr[i] - arr[i - 1]) > max ? (arr[i] - arr[i - 1]) : max;
	}

	int left = 1, right = max; //최소, 최대 휴게소 간 거리

	while (left <= right) {
		int mid = (left + right) / 2;

		int rest = 0; //휴게소 갯수
		for (int i = 1; i <= n + 1; i++) {
			rest += (arr[i] - arr[i - 1]) / mid;
			if ((arr[i] - arr[i - 1]) % mid == 0) {//-1은 처음과 마지막(고속도로 끝 or 기존 ) 모두 포함시키지 않기 때문에 하나를 빼줘야 한다.
				rest--;
			}
		}

		if (rest > m) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << left << endl;
	return 0;
}