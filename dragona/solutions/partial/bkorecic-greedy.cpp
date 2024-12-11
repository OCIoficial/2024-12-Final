#include <iostream>
#include <vector>

using namespace std;

// @ocimatic should-fail=[st3,st4]
int main(){
	int n, h;
	cin >> n >> h;
	
	// tomar todos los ascensores
	
	vector <int> ascensor(h+1, 0);
	for(int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;

		// si hay dos ascensores
		// con igual "a", nos quedamos
		// con el que lleve más lejos (?)
		ascensor[a] = max(ascensor[a], b);
	}

	int ans = 0;
	int cur = 1;
	while(cur != h){
		if(ascensor[cur]){
			cur = ascensor[cur];
		}
		else{
			cur++;
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}
