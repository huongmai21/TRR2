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
	int v, top = 0, dem = 0;
	top++; s[top] = 1; dem++;
	while(top > 0){
		int v = s[top], ok = 1;
		for(int i = 1; i <= n ; i++)
			if((a[v][i] == 1 || a[i][v] == 1) && vs[i] == 0){
				top++; s[top] = i; vs[i] = 1; dem++; ok = 0;
				break;
			}
		if(ok == 1) top--;
	}
	if(dem < n) return 0;
	int x = 0, y = 0;
	for(v == 1 ; v <= n ; v++){
		int d1 = 0, d2 = 0;
		for(int i = 1 ; i <= n ; i++){
			if(a[i][v] == 1) d1++;
			if(a[v][i] == 1) d2++;
		}
		if(d1 != d2){
			if(abs(d1 - d2) > 1) return 0;
			else{
				if(x > 0 && y > 0) return 0;
				else{
					if(d2 > d1) x = v;
					else y = v;
				}
				if(x == 0 && y == 0) return 1;
				else{
					u = x;
					return 2;
				}
			}
		}
	}
}

void EULER(){
	int check = kt();
	if(check == 0){
		cout << "Khong co chu trinh hoac duong di Euler!";
		return;
	}
	if(check == 1) u = 5; 
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
				a[v][x] = 0;
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
