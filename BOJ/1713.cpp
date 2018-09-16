#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, Chu, Total_Chu;
vector<pair<int, int>> v;
queue<pair<int, int>> q;


int main() {
	int temp;
	vector<pair<int, int>>::iterator iter;
	scanf("%d\n%d", &N, &Total_Chu);
	while (Total_Chu--) {
		bool check = false;
		scanf("%d", &temp);
		if (v.size() < N | v.empty()) {
			for (iter = v.begin(); iter != v.end(); iter++) {
				if (iter->first == temp) {
					check = true;//이미 있다면
					break;
				}
			}
			if (check == true) iter->second++;
			else v.push_back(make_pair(temp, 1));
		}
		if (v.size >= N) {

		}

	}
	return 0;
}