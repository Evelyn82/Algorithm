inline int notN(int n) {return n^1;}
inline int trueN(int n) {return n<<1;}
inline int falseN(int n) {return n<<1|1;}
vector<vector<int>> adj;
stack<int> st;
int sccOrder, vstOrder;
int sccID[MXN], vst[MXN];
int makeSCC(int n){
    int ret=vst[n]=vstOrder++;
    st.push(n);
    for(int& next : adj[n]){
        if(!vst[next]) ret=min(ret, makeSCC(next));
        if(!sccID[next]) ret=min(ret, vst[next]);
    }
    if(ret==vst[n]){
        while(1){
            int t=st.top(); st.pop();
            sccID[t]=sccOrder;
            if(t==n) break;
        }++sccOrder;
    }return ret;
}

int main(){
    int n,m; scanf("%d %d", &n, &m);
    int sz=n*2+1;
    adj.resize(sz+1);
    
    int a,b;
    for(int i=0;i<m;++i){
        scanf("%d %d", &a, &b);
        a=(a>0)?trueN(a):falseN(-a);
        b=(b>0)?trueN(b):falseN(-b);
        
        adj[notN(a)].push_back(b);
        adj[notN(b)].push_back(a);
    }
    
    sccOrder=vstOrder=1;
    for(int i=2;i<=sz;++i) if(!vst[i]) makeSCC(i);
    
    for(int i=1;i<=n;++i){
        if(sccID[trueN(i)]==sccID[falseN(i)]) {
            return unsatisfied;
        }
    }return satisfied;
}
