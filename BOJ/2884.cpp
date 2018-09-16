#include <iostream>
using namespace std;
int H, M;
int main() {
	cin >> H >> M;
	if (M - 45 >= 0) {
		cout << H << ' ' << M - 45 << endl;
	}
	else if (M - 45 < 0) {
		if (H == 0)
			cout << H+23 << ' ' << M + 15 << endl;
		else {
			cout << H - 1 << ' ' << M + 15 << endl;
		}
	}
	return 0;
}