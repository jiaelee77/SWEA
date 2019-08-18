//1974. 스도쿠 검증

#include<iostream>
using namespace std;
#define MAX 9

int board[MAX][MAX] = { 0, };
int ans;
int v[MAX + 1] = { 0, };
void init() {

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			board[i][j] = 0;
	ans = 1;
}

int main() {

	int T;
	cin >> T;
	
	for (int tc = 1; tc <= T; tc++) {

		init();
		//1.scan.
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++)
				cin >> board[i][j];
		}
			

		//2.col
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX + 1; j++) v[j] = 0;
			
			for (int j = 0; j < MAX; j++) {
				if (v[board[i][j]] == 1) {//이미 체크된수라면
					ans = 0;
					break;
				}
				v[board[i][j]] = 1;
			}
		}

		//3.row
		if (ans==1) {
			for (int i = 0; i < MAX; i++) {
				for (int j = 0; j < MAX + 1; j++) v[j] = 0;

				for (int j = 0; j < MAX; j++) {
					if (v[board[j][i]] == 1) {//이미 체크된수라면
						ans = 0;
						break;
					}
					v[board[j][i]] = 1;
				}
			}
		}

		//4. check grid
		if (ans == 1) {
			int start = 0;
			int end = 0;

			int arr[3] = { 0,3,6 };
			//int end[3] = { 2,5,8 };

			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {

					int rstart = arr[i];
					//int rend = arr[i] + 3;

					int cstart = arr[j];
					//int cend = arr[j] + 3;

					for (int x = 0; x < MAX + 1; x++) v[x] = 0;


					//cout << rstart << " " << cstart << endl;
					for (int k = rstart; k < rstart+3; k++) {
						for (int l = cstart; l < cstart+3; l++) {

							

							if (v[board[k][l]] == 1) {//이미 체크된수라면
								ans = 0;
								break;
							}
							v[board[k][l]] = 1;
						}
						if (ans == 0) break;
					}
				}
			}
		}

		//out:sdoku? 1 else?0
		cout << "#" << tc << " " << ans << endl;
	}

	return 0;
}