#include <iostream>
using namespace std;

int T, k, n;
int arr[15][15] = { 0, };

int main() {
	cin >> T;
	for (int i = 0; i < 14; i++) {
		arr[0][i] += i+1;
		arr[i+1][0] = 1;
	}

	for (int i = 1; i < 14; i++) {
		for (int j = 1; j < 15; j++) {
			arr[j][i] = arr[j - 1][i] + arr[j][i-1];
		}
	}

	while (T--) {
		cin >> k >> n;
		cout << arr[k][n - 1] << endl;
	}
	return 0;
}