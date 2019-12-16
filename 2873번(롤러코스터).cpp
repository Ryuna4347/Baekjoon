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
	
	if (R % 2 == 1) {  //행이 홀수일 경우
		string ans = ""; 
		bool r = true; //진행방향 스위치(행마다 좌우로 왔다갔다 하면서 진행하기 때문에)
		for (int i = 0; i < R; i++) {
			if (r) { 
				append(ans, 'R', C - 1);
				r = !r; 
			} 
			else {
				append(ans, 'L', C - 1);
				r = !r; 
			} 
			if (i + 1 < R) //두 줄씩 진행하므로 우->아래->좌로 진행하는 듯
				ans += 'D'; 
		} cout << ans << '\n'; 
	}
	else if (C % 2 == 1) { //행이 짝수, 열이 홀수일 경우
		string ans = "";
		bool d = true;  //진행방향 스위치(상/하)
		for (int i = 0; i < C; i++) {
			if (d) {
				append(ans, 'D', R - 1);
				d = !d;
			}
			else {
				append(ans, 'U', R - 1);
				d = !d;
			}
			if (i + 1 < C) //두 줄씩 진행하므로 아래->옆으로->위로 진행하는 듯
				ans += 'R';
		}
		cout << ans << '\n';
	}
	else { //열과 홀이 모두 짝수인 경우
		int x = 0, y = 1; //시작점 주위의 좌표를 기준으로 체크무늬가 그려지는 위치 중에서 제일 만족도가 낮은 위치는 하나 걸러야 도착점(우하단)에 도달할 수 있다. 위처럼 하면 좌하단으로 내려가게 됨
		int minVal = happy[0][1];  //최소 만족도를 가지는 좌표를 찾는다.(해당 좌표는 지나가지 않기 위해서)
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if ((i + j) % 2 == 1 && minVal > happy[i][j]) {
					minVal = happy[i][j]; 
					x = i; y = j; 
				} 
			} 
		}
		string ans = "", revAns = ""; //시작부분에서 진행, 도착부분에서 진행
		int sr = 0, sc = 0, er = R - 1, ec = C - 1; //열과 행 시작/종료 변수인 듯
		while (er - sr > 1) { //행이 2행보다 많이 남아있으면 계속 진행(최소 만족도 좌표가 영역에 포함되지 않는 선에서 진행)
			if (sr + 1 < x) { //시작부분에서 뻗어야하는 진행라인에 최소만족도 좌표가 포함되지 않는 경우 진행
				append(ans, 'R', C - 1); //우측 끝까지->하->좌측 끝까지->하강
				append(ans, 'D', 1);
				append(ans, 'L', C - 1);
				append(ans, 'D', 1);
				sr += 2;
			} 
			if (er - 1 > x) { //끝부분에서 뻗어야하는 진행라인에 최소만족도 좌표가 포함되지 않는 경우 진행
				append(revAns, 'R', C - 1); //하->왼->하->우(나중에 반전되면)
				append(revAns, 'D', 1);
				append(revAns, 'L', C - 1);
				append(revAns, 'D', 1);
				er -= 2; 
			} 
		} 
		while (ec - sc > 1) { //행이 2행만 남았을 경우 이제는 열단위로 진행한다.(최소 만족도 좌표가 있는 2x2배열이 될때까지 진행)
			if (sc + 1 < y) { //시작부분에서 뻗어나감
				append(ans, 'D', 1);  //하->우->위->우
				append(ans, 'R', 1); 
				append(ans, 'U', 1); 
				append(ans, 'R', 1); 
				sc += 2; 
			} 
			if (ec - 1 > y) {  //끝부분에서 뻗어나감
				append(revAns, 'D', 1); //우->위->우->하(나중에 반전되면)
				append(revAns, 'R', 1); 
				append(revAns, 'U', 1);
				append(revAns, 'R', 1); 
				ec -= 2;
			} 
		} 
		//2x2에서 최소만족도 좌표가 나올수 있는 부분은 우상/좌하 둘 중 하나인데 그에 따라 진행방향을 결정한다.
		if (x == sr + 1) { 
			append(ans, 'R', 1);
			append(ans, 'D', 1);
		} 
		else if (x == er - 1) {
			append(ans, 'D', 1);
			append(ans, 'R', 1);
		}
		reverse(revAns.begin(), revAns.end()); //끝에서부터 뻗은 경로는 합치기 위해서 반전시켜줘야 한다.
		ans += revAns; 
		cout << ans << '\n'; 
	} 
	return 0;
}
