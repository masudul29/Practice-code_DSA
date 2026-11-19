#include <iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int const MaxN=100005;
vector<vector<int>>graph(MaxN);
bool visit[MaxN];
int parent[MaxN];

void printAdj(int V){
    for(int i=0;i<V;i++){
        cout<<i<<": ";
        for(int j=0;j<graph[i].size();j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

}
void init(int V){
     for(int i=0;i<V;i++){
        visit[i]=false;
        parent[i]=-1;
     }
}

bool  isCycle(int src){
    visit[src]=true;
    
    //cout<<src<<" ";
    int v;
    for(int i=0;i<graph[src].size();i++){
        v=graph[src][i];
        
        if(visit[v]==false){
            parent[v]=src;
           if(isCycle(v) ){
            return true;
           }
        }
        else { 
            if(parent[src]!=v) return true;
        }
        
    }
    return false;
}
bool isCycleHelper(int V){
    init(V);
    for(int i=0;i<V;i++){
        if(visit[i]==false){
            //cout<<"DFS: ";
           if(isCycle(i))
           return true;
        }
    }
    return false;
}

void printParent(int V){
    cout<<"Parent: ";
    for(int i=0;i<V;i++){
        cout<<parent[i]<<" ";
    }
}

int main(){
    int V,E;
    cin>>V>>E;
    int p,q;
    for(int i=0;i<E;i++){
        cin>>p>>q;
        graph[p].push_back(q);
        graph[q].push_back(p);
    }
   // printAdj(V);
   cout<<isCycleHelper(V);
    //printParent(V);
    return 0;
}

