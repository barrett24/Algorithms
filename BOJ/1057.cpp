#include <iostream>
#include <algorithm>
using namespace std;
int M, X, Y;
int arr[4] = {0,1,0,0 };

int main() {
	cin >> M;
	while (M--) {
		cin >> X >> Y;
		swap(arr[X], arr[Y]);
	}
	for (int i = 1; i <= 3; i++) {
		if (arr[i] == 1) cout << i << endl;
	}
	return 0;
}