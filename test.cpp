#include<bits/stdc++.h>
using namespace std;

int a[100][100] , n,u, vs[100],e[100], s[100] ,q[100], lt[100];

void DFS(int u){
    int top = 1; s[top] = u; vs[u]=1; e[u] = 0;
    cout<<u<<"(0) ";
    while(top>0){
        int v = s[top] ;
        int ok=1;
        for(int i=1;i<=n;++i){
            if(vs[i] == 0 && a[v][i] == 1){
                top++;
                s[top] = i;
                vs[i] = 1; e[i]=v;
                cout<<s[top]<<"("<<e[s[top]]<<") ";
                ok = 0; break;
            }
        }
        if(ok == 1) top--;
    }
}


void BFS(int u){
    int v, dq = 1, cq = 0;
    cq++; q[cq] = u ; vs[u] =1 ,e[u] = 0;
    while(dq<=cq){
        v = q[dq] ; ++dq;
        cout<<v<<"("<<e[v]<<") ";
        for(int i=1;i<=n;++i){
            if(vs[i] == 0 && a[v][i] == 1){
                cq++; q[cq] = i;
                vs[i] = 1; e[i] = v;
            }
        }
    }
}


void DFSDQ(int u){
    vs[u] = 1;
    for(int v = 1;v<=n;++v){
        if(vs[v] == 0 && a[u][v] == 1){
            e[v] = u;
            DFSDQ(v);
        }
    }
}

int TPLT_DFS(int a[][100]){
    int k = 0;
    for(int u = 1;u<=n;++u) lt[u] = 0;
    for(int u = 1;u<=n;++u){
        if(lt[u] == 0){
            k++;
            DFSDQ(u);
        }
    } 
    return k;
}

void T_DFS(int a[][100]){
    int ok = 0 ;
    for(int u=1;u<=n;++u){
        for(int v=1;v<=n;++v) vs[v] = 0;
        DFSDQ(u);
        int dem = 0;
        for(int v=1;v<=n;++v){
            if(vs[v] == 1) ++dem;
        }
        if(dem == n){
            ok = 1;
            for(int v=1;v<=n;++v){
                if(e[v] != 0) cout<<v<<" "<<e[v]<<endl;
            }
            break;
        }
    }
    if(ok == 0) cout<<" Khong co cay khung"<<endl;
}

void T_BFS(int a[][100]){
    int ok = 0 ;
    for(int u=1;u<=n;++u){
        for(int v=1;v<=n;++v) vs[v] = 0;
        BFS(u);
        int dem = 0;
        for(int v=1;v<=n;++v){
            if(vs[v] == 1) ++dem;
        }
        if(dem == n){
            ok = 1;
            for(int v=1;v<=n;++v){
                if(e[v] != 0) cout<<v<<" "<<e[v]<<endl;
            }
            break;
        }
    }
    if(ok == 0) cout<<" Khong co cay khung"<<endl;
}

int main(){
    cin>>n;
    for(int i = 1 ;i<=n;++i){
        for(int j = 1 ;j<=n;++j){
            cin>>a[i][j];
        }
    }
    T_DFS(a);
    return 0;
}