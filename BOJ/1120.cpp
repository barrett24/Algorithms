//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//string A;
//string B;
//int diff = 0, ans = 99999;
//
//int main() {
//	cin >> A >> B;
//
//	for (int i = 0; i <= B.length() - A.length(); i++) {
//		for (int j = 0; j < A.length(); j++) {
//			if (A[j] != B[j+i])
//				++diff;
//		}
//		ans = min(diff, ans);
//	}
//	cout << ans << endl;
//	return 0;
//}
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string a, b;
int cnt = 0, ans = 987654321;
int main() {
	cin >> a >> b;
	for (int i = 0; i <= b.length() - a.length(); i++) {
		cnt = 0;
		for (int j = 0; j < a.length(); j++)
			if (a[j] != b[j + i]) ++cnt;
		ans = min(cnt, ans);
	}
	cout << ans << endl;
	return 0;
}
