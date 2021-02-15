int vstOrder, SCC;
int vst[MXV], sccID[MXV];
vector<vector<int>> adj;
vector<pair<int,int>> ret;

int findCutEdge(int n, int prev){
    int ans=vst[n]=vstOrder++;
    
    for(int& next : adj[n]){
        if(next==prev) continue;
        if(!vst[next]) {
            int subTree=findCutEdge(next, n);
            if(subTree>vst[n]){
                if(next>n) ret.push_back(make_pair(n, next));
                else ret.push_back(make_pair(next, n));
            }ans=min(ans, subTree);
        }
        else ans=min(ans, vst[next]);
    }
    return ans;
}

int main(){
    vstOrder=SCC=1;
    findCutEdge(1, 1);
}
