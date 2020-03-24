#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> leftKey = { 'q','w','e','r','t','y','a' ,'s','d' ,'f','g','z','x' ,'c','v' ,'b' }; //왼손으로 치는 타자들

int main(void) {
	int len, balChance = 0, leftPress = 0, rightPress = 0; //balChance : 공백+shift
	string str;

	getline(cin, str);
	len = str.length();
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ') { //공백인가?
			balChance++;
		}
		else {
			if ('A' <= str[i] && str[i] <= 'Z') { //대문자인가?
				balChance++;
				str[i] = tolower(str[i]); //shift+소문자이므로 소문자화 시킨다.
			}
			if (std::find(leftKey.begin(), leftKey.end(), str[i]) != leftKey.end()) {
				leftPress++;
			}
			else { //좌측 키들에 없으면 우측 키에 있음
				rightPress++;
			}
		}
	}

	int interval = abs(rightPress - leftPress);
	if (interval == balChance) { //더 누를 수 있는 횟수와 차이가 딱 맞는 경우 한쪽에 몰아준다
		if (rightPress > leftPress) {
			leftPress += balChance;
		}
		else {
			rightPress += balChance;
		}
	}
	else if (interval < balChance) { //공백이나 쉬프트키가 더 많은 경우 균형을 맞춰주고 반으로 나눠서 가져간다.
		if (rightPress > leftPress) {
			leftPress += interval;
		}
		else {
			rightPress += interval;
		}
		balChance -= interval;

		int divided = balChance / 2;
		rightPress += divided;
		leftPress += (balChance - divided); //홀수일 경우 왼손에 1을 더 넣을 수 있다.

	}
	else {
		if (rightPress > leftPress) {
			leftPress += balChance;
		}
		else {
			rightPress += balChance;
		}
	}

	cout << leftPress << " " << rightPress << endl;
	return 0;
}