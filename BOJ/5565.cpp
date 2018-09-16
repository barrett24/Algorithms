#include <iostream>
using namespace std;

int main() {
	int N, temp, sum = 0;
	cin >> N;
	for (int i = 1; i <= 9; i++) {
		cin >> temp;
		sum += temp;
	}
	cout << N - sum << endl;
	return 0;
}