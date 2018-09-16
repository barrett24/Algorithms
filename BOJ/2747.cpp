#include <iostream>
using namespace std;
int arr[46];
int fibo(int n) {
	arr[0] = 0;
	arr[1] = 1;
	if (n == 0) {
		return arr[0];
	}
	else if (n == 1) {
		return arr[1];
	}
	else if (n > 1) {
		for (int i = 2; i <= n; i++) {
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		return arr[n];
	}
}
int main() {
	int n;
	cin >> n;
	cout << fibo(n) << endl;
	return 0;
}