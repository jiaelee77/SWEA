//4613. 러시안 국기같은 깃발

#include<iostream>
using namespace std;

int main() {


	int T;
	int ans = 999999;
	char in[51];
	int record[50][3];
	int n, m;
	
	
	cin >> T;
	

	for (int tc = 1; tc <= T; tc++) {
		
		cin >> n >> m;
		ans = 999999;

		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 3; j++) {
				record[i][j] = m;
			}
		}

		for (int i = 0; i < n; i++) {
			cin >> in;
			//cout << in;

			for (int j = 0; j < m; j++) {
				if (in[j]=='W') {
					record[i][0]--;
				}
				if (in[j] == 'B') {
					record[i][1]--;
				}
				if (in[j] == 'R') {
					record[i][2]--;
				}
			}

			
		}
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
			cout<<record[i][j]<<" ";
			}cout << endl;
		}*/
		//make combination
		for (int wc = 1; wc <= (n - 2); wc++) {
			for (int bc = 1; bc <= (n - 1); bc++) {
				int rc = 0;
				rc = n - wc - bc;
				
				if(n == (wc+bc+rc) && rc>0){

					//cout << "comb: " << wc << bc << rc << endl;

					int res = 0;

					for (int i = 0; i < wc; i++) {
						res += record[i][0];
					}
					for (int i = wc; i < (wc+bc); i++) {
						res += record[i][1];
					}
					for (int i = (wc+bc); i < n; i++) {
						res += record[i][2];
					}
					//cout << res << endl;
					if (res < ans)
						ans = res;

				}
			}
		}
		cout << "#" << tc << " " << ans << endl;
	}


	return 0;
}