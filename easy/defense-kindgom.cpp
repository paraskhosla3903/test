// Problem: Defense of a Kingdom - (Udemy DSA Essentials using C++ - Basic Sorting Algorithms)

#include <bits/stdc++.h>
using namespace std;

/* 
Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is 
represented by a rectangular grid of cells. The player builds crossbow towers in some cells of the grid. The tower 
defends all the cells in the same row and the same column. No two towers share a row or a column.

The penalty of the position is the number of cells in the largest undefended rectangle. For example, the position shown 
on the picture has penalty 12.
*/

int defkin(int W, int H, vector<pair<int, int> > position){
    int n = position.size();

    vector<int> x;
    vector<int> y;

    for(int i=0;i<n;i++){
    	x.push_back(position[i].first);
    	y.push_back(position[i].second);
    }

    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    int xmax = 0, ymax = 0;

    for(int i=0;i<n-1;i++){
    	xmax = max(xmax,x[i+1]-x[i]-1);
    	ymax = max(ymax,y[i+1]-y[i]-1);
    }

    return xmax * ymax;
}

int main() {
	int t;cin>>t;
	while(t--){
		int w,h,n;
		cin>>w>>h>>n;
		int v1,v2;
		vector<pair<int,int>> position;
		for(int i=0;i<n;i++){
			cin>>v1>>v2;
			position.push_back(make_pair(v1,v2));
		}
		cout<<defkin(w,h,position);
	}
	return 0;
}
