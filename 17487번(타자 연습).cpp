#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> leftKey = { 'q','w','e','r','t','y','a' ,'s','d' ,'f','g','z','x' ,'c','v' ,'b' }; //�޼����� ġ�� Ÿ�ڵ�

int main(void) {
	int len, balChance = 0, leftPress = 0, rightPress = 0; //balChance : ����+shift
	string str;

	getline(cin, str);
	len = str.length();
	for (int i = 0; i < len; i++) {
		if (str[i] == ' ') { //�����ΰ�?
			balChance++;
		}
		else {
			if ('A' <= str[i] && str[i] <= 'Z') { //�빮���ΰ�?
				balChance++;
				str[i] = tolower(str[i]); //shift+�ҹ����̹Ƿ� �ҹ���ȭ ��Ų��.
			}
			if (std::find(leftKey.begin(), leftKey.end(), str[i]) != leftKey.end()) {
				leftPress++;
			}
			else { //���� Ű�鿡 ������ ���� Ű�� ����
				rightPress++;
			}
		}
	}

	int interval = abs(rightPress - leftPress);
	if (interval == balChance) { //�� ���� �� �ִ� Ƚ���� ���̰� �� �´� ��� ���ʿ� �����ش�
		if (rightPress > leftPress) {
			leftPress += balChance;
		}
		else {
			rightPress += balChance;
		}
	}
	else if (interval < balChance) { //�����̳� ����ƮŰ�� �� ���� ��� ������ �����ְ� ������ ������ ��������.
		if (rightPress > leftPress) {
			leftPress += interval;
		}
		else {
			rightPress += interval;
		}
		balChance -= interval;

		int divided = balChance / 2;
		rightPress += divided;
		leftPress += (balChance - divided); //Ȧ���� ��� �޼տ� 1�� �� ���� �� �ִ�.

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