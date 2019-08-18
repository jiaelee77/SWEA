#include<iostream>
using namespace std;

int n;
int is_complete;
int mid;
int sum;
int main(){

	cin >> n;
	//mid = n - n / 2;

	for (int i = 1; i*i <=n; i++){
		if (n % i == 0){
			sum = sum + i + (n / i);
		}
	}

	is_complete = (n == (sum-n)) ? 1 : 0;

	if (is_complete) cout << "yes"<<endl;
	else cout << "no" << endl;
	return 0;
}