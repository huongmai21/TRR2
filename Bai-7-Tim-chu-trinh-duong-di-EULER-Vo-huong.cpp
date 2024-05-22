#include<bits/stdc++.h>
using namespace std;

int a[100][100], n, vs[100], e[100], s[10000], ce[10000];
int u;

void DfsDequy(int u){
	int v;
	vs[u] = 1;
	for(v = 1; v <= n; v++){
		if(vs[v] == 0 && a[u][v] == 1){
			e[v] = u;
			DfsDequy(v);
		}
	}
}

int kt(){
	int v;
	for(v = 1 ; v <= n ; v++){
		vs[v] = 0;
		e[v] = 0;
	}
	DfsDequy(1); 
	int ok = 1;
	for(v = 1 ; v <= n ; v++){
		if(vs[v] == 0){
			ok = 0;
			break;
		}
	}
	if(ok == 0) return 0;
	int bl = 0;
	for(v = 1 ; v <= n ; v++){
		int deg = 0;
		for(int i = 1 ; i <= n ; i++){
			if(a[v][i] == 1) deg++;
		}
		if(deg % 2 == 1){
			bl++;
			if(bl > 2) return 0;
			if(bl == 1){
				u = v; ok = 2;
			}
		}
	}
	return ok;
}

void EULER(){
	int check = kt();
	if(check == 0){
		cout << "Khong co chu trinh hoac duong di Euler!";
		return;
	}
	if(check == 1) u = 1; 
	int top = 0;
	int v;
	top++;
	s[top] = u; int k = 0;
	while(top > 0){
		int v = s[top];
		int ok = 1;
		for(int x = 1 ; x <= n ; x++){
			if(a[v][x] == 1){
				top++;
				s[top] = x;
				ok = 0;
				a[v][x] = 0; a[x][v] = 0;
				break;
			}
		}
		if(ok == 1){
			k++;
			ce[k] = v;
			top--;
		}
	}
	for(v = k; v > 0; v--) cout << ce[v] << " ";
}

int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++)
			cin >> a[i][j];
	}
	EULER();
}
