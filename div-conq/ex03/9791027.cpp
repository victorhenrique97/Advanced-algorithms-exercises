#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <utility>
#include <limits.h>

using namespace std;

int dist_g = INT_MAX, ax_g = -1, ay_g = -1, bx_g = -1, by_g = -1;

bool compare_x(pair<int, int>A, pair<int, int>B){ // funcao de comparação dos valores em x

	if(A.first < B.first) return true;
return false;
}

bool compare_y(pair<int, int> A, pair<int, int>B){ // função de comparação dos valores em y
	
	if(A.second < B.second) return true;
return false;
}

float dist_2points(pair<int, int>A, pair<int, int>B){ // função que calcula a distancia entre 2 pontos
	return sqrt(pow((A.first - B.first), 2) + pow((A.second - B.second),2));	
}

float min(float A, float B){ // função que retorna o minimo entre 2 pontos
	return (A < B)? A : B;
}


float dist_2(vector<pair<int, int>> v, int begin, int end){

	float dist = INT_MAX;
	sort(v.begin(), v.end(), compare_y);
	float dist_aux = INT_MAX;
	int k = -1, l = -1;

	for(int i=begin; i<=end; ++i){
		for(int j= i+1; j<=end; ++j){
			dist_aux = dist_2points(v[i], v[j]);
			if(dist_aux < dist){
				dist = dist_aux;
				k = i;
				l = j;
			}
		}
	}

	if(dist<dist_g){
		dist_g = dist;
		ax_g = v[k].first;
		ay_g = v[k].second;
		bx_g = v[l].first;
		by_g = v[l].second;
	}

return dist;
}


float closest_pair(vector<pair<int, int>> v, int begin, int end){ // função que retorna o menor par

	int n = (end-begin)+1;
	if(n <= 3) return dist_2(v, begin, end);
		
	
	vector <pair<int, int>> v_center;
	float delta1, delta2, delta;
	pair<int, float> middle_point;
	int middle;

	middle = (begin+end)/2;
	middle_point = v[middle];

	delta1 = closest_pair(v, begin, middle);
	delta2 = closest_pair(v, middle+1, end);
	delta = min(delta1, delta2);

	for(int i=begin; i<=end; ++i)
		if(abs(v[i].first - middle_point.first) < delta){
			v_center.push_back(make_pair(v[i].first, v[i].second));
		}

	return min(delta, dist_2(v_center, 0,  v_center.size()-1));

}
int main(){

	vector<pair<int, int>> points;
	vector<pair<int, int>> points2;
	int n, x, y;

	cin >> n;

	for(int i=0; i<n; ++i){
		cin >> x >> y;
		points.push_back(make_pair(x, y));
		points2.push_back(make_pair(x, y));
	}

	sort(points.begin(), points.end(), compare_x);

	float dist = closest_pair(points, 0, n-1);
	int a = -1, b = -1;
	int i=0;
	
	for(i=0; i<n; ++i){
		if(points2[i].first == ax_g && points2[i].second == ay_g){
			a = i;
			break;
		}
	}
	for(i=0; i<n; i++){
		if(points2[i].first == bx_g && points2[i].second == by_g){
			b = i;
			break;
		}
	}

	if(a>b) printf("%d %d %.6f\n", b, a, dist);
	else printf("%d %d %.6f\n", a, b, dist);



return 0;
}

