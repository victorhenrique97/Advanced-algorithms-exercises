#include <iostream>

using namespace std;

bool isValid(int x, int y, int z, int A, int B, int C){

	if(x+y+z == A && x*y*z == B && x*x+y*y+z*z == C)
		return true;

return false;
}

int main(){

	int A, B, C, n;
	bool isvalid;

	cin >> n;
	for(int i=0; i<n; ++i){
		
		cin >> A >> B >> C;
		isvalid = false;

		for(int x=0; !isvalid && x<100; ++x){
			for(int y=0; !isvalid && y<100; ++y)
				for(int z=0; !isvalid && z<100; ++z)
					if(isValid(x, y, z, A, B, C)){
						cout << x << " " << y << " " << z << endl;
						isvalid = true;
					}
		}

		if(!isvalid) cout << "No solution\n";
		
	}

return 0;
}