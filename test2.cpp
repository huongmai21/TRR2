#include<bits/stdc++.h>

using namespace std;
int a[100][100], n, u, vs[100],e[100],s[10000], ce[10000];

// void DFSDQ(int u){
//     vs[u] = 1;
//     for(int v = 1;v<=n;++v){
//         if(vs[v] == 0 && a[u][v] == 1){
//             e[v] = u;
//             DFSDQ(v);
//         }
//     }
// }

// int kt(int a[][100], int n){
//     for(int v= 1;v<=n;++v){
//         vs[v] = 0; e[v] = 0;
//     }
//     DFSDQ(1);
//     int ok = 1;
//     for(int v=1;v<=n;++v){
//         if(vs[v] = 0){
//             ok = 0;
//             break;
//         }
//     }
//     if(ok == 0) return 0;
//     int bl = 0;
//     for(int v= 1;v<=n;++v){
//         int deg = 0;
//         for(int i = 1;i<=n;++i){
//             if(a[v][i] = 1) deg++;
//         }
//         if(deg %2 == 1){
//             bl++;
//             if(bl > 2) return 0;
//         }
//         if(bl == 1){
//             u = v; // gan u la dinh bac le co so hieu min
//             ok=2;
//         }
//     }
//     return ok;
// }

void EULER(int a[][100]){
    int top = 0, k;
    top++; s[top]=u;  k=0;
    while(top>0){
        int v=s[top];
        int ok= 1;
        for(int i = 1;i<=n;++i){
            if(a[v][i] == 1){
                top++;
                s[top] = i ;
                ok = 0;
                a[v][i]= 0; a[i][v] = 0;
                break;
            }
        }
        if(ok == 1){
            k++;
            ce[k] = v;
            top--;
        }
    }
    for(int v= k;v>0;v--) cout<<ce[v]<<" ";
}

void EULER2(int a[][100]){
    int top = 0, k;
    top++; s[top]=u;  k=0;
    while(top>0){
        int v=s[top];
        int ok= 1;
        for(int i = 1;i<=n;++i){
            if(a[v][i] == 1){
                top++;
                s[top] = i ;
                ok = 0;
                a[v][i]= 0;
                break;
            }
        }
        if(ok == 1){
            k++;
            ce[k] = v;
            top--;
        }
    }
    for(int v= k;v>0;v--) cout<<ce[v]<<" ";
}


int main(){
    cin>>n>>u;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>a[i][j];
        }
    }
    EULER(a);
    return 0;
}