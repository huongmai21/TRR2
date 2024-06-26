#include<bits/stdc++.h>
using namespace std;

int n, m, d[10000], c[10000], ts[10000];
int a[100][100];
int vs[100], t[100];

void Kruskal(){
	for(int i = 1; i <= m - 1; i++)
		for(int j = i + 1; j <= m; j++)
			if(ts[i] > ts[j]){
				int tg = ts[i]; ts[i] = ts[j]; ts[j] = tg;
				tg = d[i]; d[i] = d[j]; d[j] = tg;
				tg = c[i]; c[i] = c[j]; c[j] = tg;
			}
	int wt = 0, k = 0;
	for(int i = 1 ; i <= n; i++) vs[i] = 0;
	for(int i = 1 ; i <= m; i++)
		if(!(vs[d[i]] != 0 && vs[d[i]] == vs[c[i]])){
			k++;
			t[k] = i;
			wt = wt + ts[i];
			if(k == n - 1){
				cout << wt << endl;
				for(int j = 1; j <= k; j++) cout << d[t[j]] << " " << c[t[j]] << endl;
				return;
			}
			int u = d[i], v = c[i];
			if(vs[u] == 0 && vs[v] == 0){
				vs[u] = k; vs[v] = k;
			}
			else
				if(vs[u] == 0 && vs[v] != 0) vs[u] = vs[v];
				else
					if(vs[u] != 0 && vs[v] == 0) vs[v] = vs[u];
					else
						if(vs[u] < vs[v]){
							int tg = vs[v];
							for(int j = 1; j <= n; j++)
								if(vs[j] == tg) vs[j] = vs[u];
						}
						else if(vs[v] < vs[u]){
							int tg = vs[u];
							for(int j = 1; j <= n ;j++)
								if(vs[j] == tg) vs[j] = vs[v];
						}
		}
}
int vocung = 100000;
void nap(){
	int dem = 1;
	for(int i = 1 ; i <= n ; i++){
		for(int j = i + 1; j <= n; j++){
			if(a[i][j] < vocung){
				ts[dem] = a[i][j];
				d[dem] = i;
				c[dem] = j;
				dem++;
			}
		}
	}
	m = dem - 1;
}

int main(){
	cin >> n;
	for(int i = 1; i <= n ; i++){
		for(int j = 1 ; j <= n; j++)
			cin >> a[i][j];
	}
	nap();	
	Kruskal();
}
