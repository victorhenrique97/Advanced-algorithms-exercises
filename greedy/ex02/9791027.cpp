#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

bool compare(int a, int b){
	return b<a;
}

/////////////////////////////////////////////////
int main(){

	int c, s, aux;
	double am, cm, im;
	vector<int> v;
	vector<vector<int>> m;

	while(scanf("%d %d", &c, &s) != EOF){
	   for(int i=0; i<s; ++i){
		
        scanf("%d", &aux);
		  v.push_back(aux);
	   }

	   sort(v.begin(), v.end(), compare);

       m.resize(c);
	   for(int i=0; i<c; ++i)
		  m[i].resize(2);
	
	   aux = 0;
	   for(int i=0; i<c; ++i){
		  if(aux == s) break;
		  m[i][0] = v[aux++]; 
        
	   }

	   for(int j=c-1; j>=0; --j){
		  if(aux == s) break;
		  m[j][1] = v[aux++];
	   }

	   am = 0;
	   for(int i=0; i<s; i++)
		  am+= v[i];
	   am /= c;

	   im = 0;
	   for(int i=0; i<c; i++){
		  cm = 0;
		  cm = m[i][0] + m[i][1];
		  im += abs(cm - am);
	   }

        cout << setprecision(5) << fixed;
        cout << "IMBALANCE = "<<im << endl;

       v.clear();
       m.clear();
    }

return 0;
}
