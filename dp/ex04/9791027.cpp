#include <iostream>
#include <vector>

#define MAX_VALUE 300000

using namespace std;

vector <int> coins = {1, 5, 10, 25, 50};
vector <int> dp;


void processing(){

	dp.resize(MAX_VALUE);

	dp[0] = 1;

	for(int i=0; i<5; i++){
		for(int j=coins[i]; j<MAX_VALUE; j++)
			dp[j] += dp[j-coins[i]];
	}
}


int main(){

	int value;
	int N;
	vector <int> values;

	while(cin >> value)
		values.push_back(value);
	N = values.size();

	processing();

	for(int i=0; i<N; i++){
		if(dp[values[i]] > 1) cout << "There are " << dp[values[i]] << " ways to produce " << values[i] << " cents change." << endl;
		else cout << "There is only one way to produce " << values[i] << " cents change." << endl;
	}

	cout << endl;
	

return 0;
}