//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstdio>
//#include <string>
//using namespace std;
//int N, M;
//string temp;
//
//int main() {
//	cin >> N >> M;
//	vector<string> v1;
//	vector<string> v2;
//	v1.resize(N);
//	for (int i = 1; i <= N; i++) {
//		getline(cin,temp);
//		v1.push_back(temp);
//	}
//	sort(v1.begin(), v1.end());
//
//	for (int i = 1; i <= M; i++) {
//		getline(cin, temp);
//		if (binary_search(v1.begin(), v1.end(), temp))
//			v2.push_back(temp);
//	}
//	sort(v2.begin(), v2.end());
//
//	cout << (int)v2.size() << endl;
//	for (int i = 1; i <= v2.size(); i++)
//		cout << v2[i] << endl;
//	return 0;
//}
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include <string>
using namespace std;

int main(void) {
	int n, m;
	string temp;
	scanf_s("%d %d", &n, &m);

	vector<string> v;
	vector<string> v_result;
	cin.ignore();
	v.resize(n);

	for (int i = 0; i<n; i++) {
		getline(cin, temp);
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	for (int j = 0; j<m; j++) {
		getline(cin, temp);

		if (binary_search(v.begin(), v.end(), temp)) { 
			v_result.push_back(temp);
		}
	}

	sort(v_result.begin(), v_result.end());

	printf("%d\n", (int)v_result.size());
	for (int i = 0; i<(int)v_result.size(); i++) {
		printf("%s\n", v_result[i].c_str());
	}

	return 0;
}