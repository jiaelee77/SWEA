//1961.숫자 배열 회전
#include<iostream>
using namespace std;

#define SIZE 7

int T, n;
int a[SIZE][SIZE] = { 0, };
int a90[SIZE][SIZE] = { 0, };
int a180[SIZE][SIZE] = { 0, };
int a270[SIZE][SIZE] = { 0, };

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j<n; j++) {
			cout << a90[i][j];
		} cout << " ";

		for (int j = 0; j<n; j++) {
			cout << a180[i][j];
		} cout << " ";

		for (int j = 0; j<n; j++) {
			cout << a270[i][j];
		} cout << endl;
	}
}

void rotation(int bf[SIZE][SIZE],int aft[SIZE][SIZE]) {

	for (int i = 0; i < n; i++) {
		for(int j=0;j<n;j++){
			aft[j][n-i-1]= bf[i][j];
		}
	}

}
int main() {
	//1. get input
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
			cin >> n;
	

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
	

		//2. rotation
		rotation(a, a90);
		rotation(a90, a180);
		rotation(a180, a270); 
		




		cout << "#" << tc << endl;
		print();
	}

	return 0;
}