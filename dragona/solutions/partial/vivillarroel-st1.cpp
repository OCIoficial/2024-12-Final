// @ocimatic should-fail=[st2,st3,st4]
#include <iostream>

using namespace std;

int main() {
	int n, h;
	cin >> n >> h;
	if (n == 0) {
		cout << h-1 << endl;
	}
	else {
		int a, b;
		cin >> a >> b;
		cout << h-1-(b-a) << endl;
	}
	return 0;
}
