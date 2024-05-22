#include<bits/stdc++.h>

using namespace std;
int a[100][100], n, e[100][100],d[100][100];


void FLOYD(int a[][100]){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            d[i][j] = a[i][j];
            e[i][j] = i;
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    e[i][j] = k;
                }
            }
        }
    }
    for(int i=1;i<=n;++i){
        if(d[i][i]<0){
            cout<<"G chua chu trinh am"<<endl;
            return;
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(j!=i){
                cout<<"Duong di tu "<<i<<"->"<<j<<" co d["<<i<<"]["<<j<<"]="<<d[i][j]<<" : ";
				cout << j;
				int x = j;
				while(e[i][x] != i){
					cout << "<-" << e[i][x];
					x = e[i][x];
				}
				cout << "<-" << i << endl;
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j){
            cin>>a[i][j];
        }
    }
    FLOYD(a);
    return 0;
}