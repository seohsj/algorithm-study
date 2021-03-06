#include <iostream>
#include <string>
using namespace std;
long long two[51];
//사분면 문자열 - > 좌표
pair<long long, long long> go(string& a, int index, long long r, long long c, long long size) {
    if (size == 1) {
        return make_pair(r, c);
    }
    else {
        if (a[index] == '1') {
            return go(a, index + 1, r, c + size / 2, size / 2);
        }
        else if (a[index] == '2') {
            return go(a, index + 1, r, c, size / 2);
        }
        else if (a[index] == '3') {
            return go(a, index + 1, r + size / 2, c, size / 2);
        }
        else if (a[index] == '4') {
            return go(a, index + 1, r + size / 2, c + size / 2, size / 2);
        }
    }
    return make_pair(0, 0);
}
string gogo(long long r, long long c, long long size, long long x, long long y) {
    if (size == 1) {
        return "";
    }
    if (x < r + size / 2 && y < c + size / 2) {
        return "2" + gogo(r, c, size / 2, x, y);
    }
    else if (x < r + size / 2 && y >= c + size / 2) {
        return "1" + gogo(r, c + size / 2, size / 2, x, y);
    }
    else if (x >= r + size / 2 && y < c + size / 2) {
        return "3" + gogo(r + size / 2, c, size / 2, x, y);
    }
    else {
        return "4" + gogo(r + size / 2, c + size / 2, size / 2, x, y);
    }
}
int main() {
    two[0] = 1;
    for (int i = 1; i <= 50; i++) {
        two[i] = two[i - 1] * 2LL;
    }
    int n;
    string a;
    cin >> n >> a;
    long long size = two[n];
    auto p = go(a, 0, 0, 0, size);
    long long dr, dc;
    cin >> dc >> dr;
    dr = -dr;
    p.first += dr;
    p.second += dc;
    //좌표 p는 몇사분면 인가?
    if (0 <= p.first && p.first < size && 0 <= p.second && p.second < size) {
        cout << gogo(0, 0, size, p.first, p.second) << '\n';
    }
    else {
        cout << -1 << '\n';
    }
    return 0;
}