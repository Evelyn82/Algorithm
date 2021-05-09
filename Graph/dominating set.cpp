#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int UNWATCHED=0;
const int WATCHED=1;
const int INSTALLED=2;

vector<vector<int>> adj;
vector<bool> vst;
int G, H, answer;
int dfs(int n){
    vst[n]=true;
    
    int childState[3]={0,0,0};
    for(int i=0;i<adj[n].size();++i){
        int nxt=adj[n][i];
        if(vst[nxt]) continue;
        ++childState[dfs(nxt)];
    }
    
    if(childState[UNWATCHED]){
        ++answer;
        return INSTALLED;
    }
    if(childState[INSTALLED]) return WATCHED;
    return UNWATCHED;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N; cin>>N;
    adj.resize(N+1);
    
    int u, v;
    for(int i=0;i<N-1;++i){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vst.resize(N+1, false);
    dfs(1);
    cout<<answer<<'\n';
}
