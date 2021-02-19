int sccID[MXN*2], vst[MXN*2];
inline int findN(int n){return n>>1;}
inline int notN(int n){return n^1;}
inline int trueN(int n){return n<<1;}
inline int falseN(int n){return n<<1|1;}

int makeSCC(int n){
    ;
}
vector<pair<int,int>> topoPath(int sz){
    vector<pair<int,int>> v;
    for(int i=2;i<sz;++i){
        v.push_back(make_pair(sccID[i], i));
    }
    sort(v.begin(), v.end(), [&](const pair<int,int>& a, const pair<int,int>& b){
        return a.first<b.first;
    });
    return v;
}

int main(){
    for(int i=0;i<m;++i){
        scanf("%d %d", &u, &v);
        u=(u>0?trueN(u):falseN(-u));
        v=(v>0?trueN(v):falseN(-v));
        adj[notN(u)].push_back(v);
        adj[notN(v)].push_back(u);
    }
    sccOrder=vstOrder=1;
    for(int i=2;i<sz;++i) if(!vst[i]) makeSCC(i);
    
    for(int i=1;i<=n;++i){
        if(sccID[trueN(i)]==sccID[falseN(i)]){
            puts("0");
            return unsatisfied;
        }
    }
    
    // satisfied -> discriminate true or false
    vector<pair<int,int>> v=topoPath(sz);
    vector<int> ret(sz,-1);
    for(pair<int,int>& i : v){
        int var=i.second;
        if(ret[findN(var)]==-1) ret[findN(var)]=!(var%2);
    }
    for(int i=1;i<=n;++i) printf("%d ", ret[i]);
}
