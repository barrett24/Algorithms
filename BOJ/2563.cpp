#include <iostream>
using namespace std;

int a[101][101] = { 0 };
int n, x, y;
int cnt=0;

int main() {
	cin >> n;
	while (n--) {
		cin >> x >> y;
		for (int i = x; i < x + 10; i++)
			for (int j = y; j < y + 10; j++)
				a[i][j] = 1;
	}
	for (int i = 1; i < 101; i++)
		for (int j = 1; j < 101; j++)
			if (a[i][j] == 1) cnt++;
	cout << cnt << endl;
	return 0;
}