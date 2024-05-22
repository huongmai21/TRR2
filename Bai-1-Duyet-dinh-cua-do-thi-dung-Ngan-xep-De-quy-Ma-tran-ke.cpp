#include<bits/stdc++.h>
using namespace std;

//Su dung ngan xep
//G cho boi ma tran ke a[i][j]

int a[100][100], n, vs[100], e[100], s[100];

void DfsNx(int u){
	int top = 1; s[top] = u; vs[u] = 1;
	int v = s[top];
	cout << v << " ";
	while(top > 0){
		v = s[top]; 
		int ok = 1;
		for(int i = 1 ; i <= n ; i++){
			if(vs[i] == 0 && a[v][i] == 1){
				top++;
				s[top] = i;
				cout << s[top] << " ";
				vs[i] = 1;
				e[i] = v;
				ok = 0;
				break;
			}
		}
		if(ok == 1) top--;
	}
}

void DuyetDfs(){
	int v;
	for(v = 1 ; v <= n ; v++){
		vs[v] = 0; e[v] = 0;
	}
	for(v = 1 ; v <= n ; v++){
		if(vs[v] == 0) DfsNx(v);
	}
}

int main(){
	cout << "Nhap so dinh cua do thi G: n = ";
	cin >> n;
	cout << "Nhap ma tran ke a[][] cua do thi G:\n";
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cin >> a[i][j];
		}
	}
	cout << "Thu tu duyet cac dinh cua do thi G: ";
	DuyetDfs();
}

