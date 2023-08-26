#include<bits/stdc++.h>
using namespace std;

//custom class
class Edge{
    public:
    int u;
    int v;
    int w;

    //constructor
    Edge(int u,int v, int w){
        this->u=u;
        this->v=v;
        this->w=w;
    }
};
int main(){
    int n,e;
    cin>>n>>e;
    vector<Edge>v;
    while(e--){
        int a,b,w;
        cin>>a>>b>>w;

        Edge ed(a,b,w);
        //cout<<ed.u<<" "<<ed.v<<" "<<ed.w<<endl;
        v.push_back(ed);

        //distance inifinity
        int dist[n+1];
        for(int i=1; i<=n; i++){
            dist[i]=INT_MAX;
        }

        //initially distance zero
        dist[1]=0;

        //relaxation
        for(int i=1; i<=n-1; i++){
            for(int j=0; j<v.size(); j++){
                Edge ed= v[j];
                int a= ed.u;
                int b= ed.v;
                int w= ed.w;
                if(dist[a]+w<dist[b]){
                    dist[b]=dist[a]+w;
                }
            }
        }

    //print
    for(int i=1; i<=n; i++){
        cout<<"Nodes"<< i<< " "<<dist[i]<<endl;
    }

    }
    
    return 0;
}