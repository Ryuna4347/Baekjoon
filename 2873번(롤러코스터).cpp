#include <iostream> 
#include <algorithm> 
using namespace std; int happy[1000][1000];

void append(string& ans, char c, int end) { 
	for (int i = 0; i < end; i++) {
		ans += c;
	}
} 
int main() {
	int R, C; 
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> happy[i][j]; 
	
	if (R % 2 == 1) {  //���� Ȧ���� ���
		string ans = ""; 
		bool r = true; //������� ����ġ(�ึ�� �¿�� �Դٰ��� �ϸ鼭 �����ϱ� ������)
		for (int i = 0; i < R; i++) {
			if (r) { 
				append(ans, 'R', C - 1);
				r = !r; 
			} 
			else {
				append(ans, 'L', C - 1);
				r = !r; 
			} 
			if (i + 1 < R) //�� �پ� �����ϹǷ� ��->�Ʒ�->�·� �����ϴ� ��
				ans += 'D'; 
		} cout << ans << '\n'; 
	}
	else if (C % 2 == 1) { //���� ¦��, ���� Ȧ���� ���
		string ans = "";
		bool d = true;  //������� ����ġ(��/��)
		for (int i = 0; i < C; i++) {
			if (d) {
				append(ans, 'D', R - 1);
				d = !d;
			}
			else {
				append(ans, 'U', R - 1);
				d = !d;
			}
			if (i + 1 < C) //�� �پ� �����ϹǷ� �Ʒ�->������->���� �����ϴ� ��
				ans += 'R';
		}
		cout << ans << '\n';
	}
	else { //���� Ȧ�� ��� ¦���� ���
		int x = 0, y = 1; //������ ������ ��ǥ�� �������� üũ���̰� �׷����� ��ġ �߿��� ���� �������� ���� ��ġ�� �ϳ� �ɷ��� ������(���ϴ�)�� ������ �� �ִ�. ��ó�� �ϸ� ���ϴ����� �������� ��
		int minVal = happy[0][1];  //�ּ� �������� ������ ��ǥ�� ã�´�.(�ش� ��ǥ�� �������� �ʱ� ���ؼ�)
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if ((i + j) % 2 == 1 && minVal > happy[i][j]) {
					minVal = happy[i][j]; 
					x = i; y = j; 
				} 
			} 
		}
		string ans = "", revAns = ""; //���ۺκп��� ����, �����κп��� ����
		int sr = 0, sc = 0, er = R - 1, ec = C - 1; //���� �� ����/���� ������ ��
		while (er - sr > 1) { //���� 2�ຸ�� ���� ���������� ��� ����(�ּ� ������ ��ǥ�� ������ ���Ե��� �ʴ� ������ ����)
			if (sr + 1 < x) { //���ۺκп��� ������ϴ� ������ο� �ּҸ����� ��ǥ�� ���Ե��� �ʴ� ��� ����
				append(ans, 'R', C - 1); //���� ������->��->���� ������->�ϰ�
				append(ans, 'D', 1);
				append(ans, 'L', C - 1);
				append(ans, 'D', 1);
				sr += 2;
			} 
			if (er - 1 > x) { //���κп��� ������ϴ� ������ο� �ּҸ����� ��ǥ�� ���Ե��� �ʴ� ��� ����
				append(revAns, 'R', C - 1); //��->��->��->��(���߿� �����Ǹ�)
				append(revAns, 'D', 1);
				append(revAns, 'L', C - 1);
				append(revAns, 'D', 1);
				er -= 2; 
			} 
		} 
		while (ec - sc > 1) { //���� 2�ุ ������ ��� ������ �������� �����Ѵ�.(�ּ� ������ ��ǥ�� �ִ� 2x2�迭�� �ɶ����� ����)
			if (sc + 1 < y) { //���ۺκп��� �����
				append(ans, 'D', 1);  //��->��->��->��
				append(ans, 'R', 1); 
				append(ans, 'U', 1); 
				append(ans, 'R', 1); 
				sc += 2; 
			} 
			if (ec - 1 > y) {  //���κп��� �����
				append(revAns, 'D', 1); //��->��->��->��(���߿� �����Ǹ�)
				append(revAns, 'R', 1); 
				append(revAns, 'U', 1);
				append(revAns, 'R', 1); 
				ec -= 2;
			} 
		} 
		//2x2���� �ּҸ����� ��ǥ�� ���ü� �ִ� �κ��� ���/���� �� �� �ϳ��ε� �׿� ���� ��������� �����Ѵ�.
		if (x == sr + 1) { 
			append(ans, 'R', 1);
			append(ans, 'D', 1);
		} 
		else if (x == er - 1) {
			append(ans, 'D', 1);
			append(ans, 'R', 1);
		}
		reverse(revAns.begin(), revAns.end()); //���������� ���� ��δ� ��ġ�� ���ؼ� ����������� �Ѵ�.
		ans += revAns; 
		cout << ans << '\n'; 
	} 
	return 0;
}
