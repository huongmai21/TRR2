#include<bits/stdc++.h>
using namespace std;

int n, s,t, a[100][100], d[100], e[100], vs[100];

void Dijstra(int s){
	int u, v;
	for(v = 1; v <= n ; v++){
		d[v] = a[s][v];
		e[v] = s;
	}
	d[s] = 0; e[s] = 0; vs[s] = 1;
	while(1){
		int u = 0, min = 10000;
		for(v = 1; v <= n ; v++) 
			if(vs[v] == 0 && d[v] < min){
				u = v; min = d[v];
			}
		if(u == 0) return;
		vs[u] = 1;
		for(v = 1; v <= n; v++)
			if(vs[v] == 0 && d[v] > d[u] + a[u][v]){
				d[v] = d[u] + a[u][v];
				e[v] = u;
			}
	}
}

int main(){
	freopen("DN.INP","r",stdin);
	freopen("DN.OUT","w",stdout);

	cin >> n >> s >> t;
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= n ; j++) cin >> a[i][j];
	}
	Dijstra(s);

	vector<int> res;
	int x = t ;
	res.push_back(t);
	while(x != s){//u
		res.push_back(e[x]);
		x = e[x];
	}
	if(res.size() <= 2 || res[res.size() -1] != s) cout<<0<<endl;
	else{
		cout << res.size() << endl;
		for(int i= res.size()-1;i>=0;--i) cout<<res[i]<<" ";
	}
	
	return 0;
}
