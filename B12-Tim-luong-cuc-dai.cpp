#include<bits/stdc++.h>

using namespace std;

int n,s,t, c[100][100], gf[100][100];
int q1[100],vs[100],e[100];

int BFS(int gf[][100]){
    int v, dq = 1, cq = 0;
    cq++; q1[cq] = s ; vs[s] =1 ,e[s] = 0;
    while(dq<=cq){
        v = q1[dq] ; ++dq;
        for(int i=1;i<=n;++i){
            if(vs[i] == 0 && gf[v][i] > 0){
                cq++; q1[cq] = i;
                vs[i] = 1; e[i] = v;
                if(i == t) return 1;
            }
        }
    }
    return 0;
}

int FordFulkerson(int c[][100]){
    int u,v;
    for(u=1;u<=n;++u)
        for(v=1;v<=n;++v)
            gf[u][v] = c[u][v];
    
    int max_flow = 0;

    while(BFS(gf)){
        for(int u=1;u<=n;++u) vs[u]=0;

        int path_flow = INT_MAX;
        for(v = t ;v != s; v = e[v]){
            u = e[v];
            path_flow = min(path_flow, gf[u][v]);
        }

        for(v = t ;v != s; v = e[v]){
            u = e[v];
            gf[u][v] -= path_flow;
            gf[v][u] += path_flow;
        }

        max_flow += path_flow;

        // cq=1; dq=1 ; q2[cq]=s; vs[s]=1;e[s]=0; d[s]=10000;
        // while(dq<=cq){
        //     u=q2[dq]; dq++;
        //     for(int v = 1;v<=n;++v)
        //         if(vs[v] == 0){
        //             if(c[u][v] > 0 && fl[u][v] <c[u][v]){
        //                 e[v] = u; d[v] = (d[u]<c[u][v]-fl[u][v]) ? d[u] : c[u][v] - fl[u][v];
        //                 cq++ ; q2[cq]=v; vs[v] = 1;
        //                 if(v==t) return;
        //             }
        //             if(c[u][v] > 0 && fl[u][v] >0){
        //                 e[v] = -u; d[v] = (d[u]<fl[u][v]) ? d[u] :fl[v][u];
        //                 cq++ ; q2[cq]=v; vs[v] = 1;
        //                 if(v==t) return;
        //             }

        //         }
        // }
    }
    return max_flow;
 
}


int main(){
    // ifstream fin;
    // ofstream fout;
    // fin.open("DT.INP");
    // fout.open("DT.OUT");
    // fin>>n;
    // for(int i=1;i<=n;++i){
    //     for(int j=1;j<=n;++j){
    //         fin>>c[i][j];
    //     }
    // }
    // s=1, t=n;

    // fin.close();
    // fout.close();

    cin>>n;
    s=1; t=n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>c[i][j];
        }
    }
    cout<<FordFulkerson(c);
    // for(int i=1;i<=n;++i){
    //     cout<<
    // }
}