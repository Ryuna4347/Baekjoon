// pda_pro12
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;

int a, b, ans; ll lft, rgt;

int main() {
    cin >> a >> b;

    lft = 1;  rgt = b;

    while (lft <= rgt) {
        int mid = (lft + rgt) >> 1;   // 가정된 K번째 
        ll Sum = 0;
        for (int i = 1; i <= a; i++)    // 행마다 mid보다 작은수의 갯수를 측정
            Sum += min(a, mid / i);
        if (Sum >= b)
            rgt = mid - 1, ans = mid;
        else
            lft = mid + 1;
    }
    cout << ans;
    return 0;
}﻿