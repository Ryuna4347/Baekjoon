#include <iostream>
#include <algorithm>

using namespace std;

char arr[100001];

bool desc(int a, int b) { return a > b; }

int GetLen(char* str) {
	int idx = 0;
	int length = 0;
	while (str[idx++]!='\0') {
		length++;
	}
	return length;
}

int GetSum(char* str) {
	int sum = 0;
	int idx = 0;
	while (str[idx] != '\0') {
		sum += int(str[idx++]) - '0';
	}
	return sum;
}
int HasZero(char* str) {
	int idx = 0;
	while (str[idx] != '\0') {
		if (str[idx] == '0') {
			return idx;
		}
		idx++;
	}
	return -1;
}
void Swap(int left, int right) {
	int temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}

int main(void) {
	cin >> arr;

	int len = GetLen(arr);
	int sum = GetSum(arr);

	if (sum % 3 != 0) {
		cout << "-1" << endl;
	}
	else {
		int zeroIdx = HasZero(arr);
		if (HasZero(arr) == -1) {
			cout << "-1" << endl;
			return 0;
		}
		if (zeroIdx != len - 1) {
			Swap(zeroIdx, len - 1);
		}
		sort(arr,arr+(len-1),desc);
		cout << arr << endl;
	}

	return 0;
}