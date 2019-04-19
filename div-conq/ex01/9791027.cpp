#include <iostream>
#include <vector>

using namespace std;


int conquer(vector<int> &v, int start, int middle, int end){

	vector<int> A, B;
	int swaps = 0;
	int start_A, start_B, end_A, end_B;

	for(int i=start; i<= middle; ++i)
		A.push_back(v[i]);

	for(int i=middle+1; i<=end; ++i)
		B.push_back(v[i]);


	start_A = start_B = 0;
	end_A = A.size()-1;
	end_B = B.size()-1;

	for(int i=0; i<end-start+1; ++i){

		if(start_A > end_A)  // acabou o A
			v[start+i] = B[start_B++];

		else if(start_B > end_B) // acabou o B 
			v[start+i] = A[start_A++];

		else if(A[start_A] > B[start_B]){
			v[start+i] = B[start_B++];
			swaps += end_A - start_A + 1;
		}

		else if(A[start_A] <= B[start_B]){
			v[start+i] = A[start_A++];
		}
	}

	A.clear();
	B.clear();

return swaps;
}


int divisor(vector<int> &v, int start, int end){

	int middle;
	if(start >= end) return 0;
	
	middle = (start+end)/2;
	return divisor(v, start, middle) + divisor(v, middle+1, end) + conquer(v, start, middle, end);
}


int main(){


	int n,m, aux;
	vector<int> v;

	cin >> n;

	for(int i=0; i<n; ++i){
		
		cin >> m;

		for(int j=0; j<m; j++){
			cin >> aux;
			v.push_back(aux);
		}

	cout << divisor(v, 0, m-1) << endl;

	v.clear();

	}


return 0;
}


 