#include<bits/stdc++.h>

using namespace std;
int a[100][100], n, u, vs[100],e[100],d[100];


void DIJKSTRA(int u){
    for(int v = 1;v<=n;++v){
        d[v] = a[u][v] ;
        e[v] = u;
    }
    d[u] = 0; e[u]= 0; vs[u] =1;
    while(1){
        int s = 0 , min = INT_MAX;
        for(int v = 1;v<=n;++v){
            if(vs[v] == 0 && d[v]<min){
                s = v ; min =d[v];
            }
        }
        if(s == 0) break;
        vs[s] = 1;
        for(int v= 1;v<=n;++v){
            if(vs[v] == 0 && d[v] > d[s] + a[s][v]){
                d[v] = d[s] + a[s][v] ;
                e[v] = s;
            }
        }
    }
    for(int v = 1;v<=n;++v){
        if(v!=u){
            cout<<"Duong di tu "<<u<<"->"<<v<<" co d["<<v<<"]="<<d[v]<<": ";
            int s = v;
            cout<<s<<"<-";
            while(e[s] != 0){
                cout<<e[s];
                s = e[s];
                if(e[s] != 0) cout<<"<-";
            }
            cout<<endl;
        }
    }
}

int main(){
    cin>>n>>u;
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j){
            cin>>a[i][j];
        }
    }
    DIJKSTRA(u);
    return 0;
}