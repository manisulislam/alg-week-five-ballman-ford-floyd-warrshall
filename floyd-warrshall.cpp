#include<bits/stdc++.h>
using namespace std;

//range
const int INF= 1e7+5;
int main(){
    int n, e;
    cin>>n>>e;
    int dist[n+1][n+1];

    //firstly all node distance infinity and i==j then distance 0
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dist[i][j]=INF;
            if(i==j) dist[i][j]=0;

        }
    }

    //input
    while(e--){
        int a, b, w;
        cin>>a>>b>>w;
        dist[a][b]=w;
    }

    //print
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dist[i][j]==INF) cout<<"INF"<<" ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }

    //floyd warshall implementation
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][k]+dist[j][k]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[j][k];
                }
            }
        }
    }

    cout<<"Updated"<<endl;
    //print
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dist[i][j]==INF) cout<<"INF"<<" ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}