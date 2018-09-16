#include <iostream>
#include <string>
using namespace std;
string A;

int main() {
	cin >> A;
	cout << A[0];
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == 45)
			cout << A[i + 1];
	}
	return 0;
}