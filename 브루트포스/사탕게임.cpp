#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string s[51];
int candy() {
	int ans = 1;
	// �翷 ��
	for (int i = 0; i < n; i++) {
		int temp = 1;
		for (int j = 0; j < n - 1; j++) {
			if (s[i][j] == s[i][j + 1]) temp++;
			else {
				ans = max(temp, ans);
				temp = 1;
			}
		}
		ans = max(temp, ans);
	}
	// ���Ʒ� ��
	for (int i = 0; i < n; i++) {
		int temp = 1;
		for (int j = 0; j < n - 1; j++) {
			if (s[j][i] == s[j + 1][i]) temp++;
			else {
				ans = max(temp, ans);
				temp = 1;
			}
		}
		ans = max(temp, ans);
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int answer = 0;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			//�翷 ��
			if (s[i][j] == s[i][j + 1]) answer = max(answer, candy());
			else {
				swap(s[i][j], s[i][j + 1]);
				answer = max(answer, candy());
				swap(s[i][j + 1], s[i][j]); //������� �������ƾ���.
			}

			if (s[j][i] == s[j + 1][i]) answer = max(answer, candy());
			else {
				swap(s[j][i], s[j + 1][i]);
				answer = max(answer, candy());
				swap(s[j + 1][i], s[j][i]);
			}
		}
	}
	cout << answer;
}