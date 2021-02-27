// O(N+M)

int* getPi(string p){
    int sz=(int)p.size();
    int *pi=new int[sz];
    pi[0]=0;
    
    for(int i=1, j=0;i<sz;++i){
        while(p[i]!=p[j]){
            if(j==0){
                pi[i]=j; break;
            }
            j=pi[j-1];
        }
        if(p[i]==p[j]) pi[i]=++j;
    }
    return pi;
}

vector<int> kmp(string t, string p, int *pi){
    vector<int> v;
    int szT=(int)t.size(), szP=(int)p.size();
    for(int i=0, j=0;i<szT;++i){
        while(t[i]!=p[j]){
            if(j==0) break;
            j=pi[j-1];
        }
        if(t[i]==p[j]){
            j++;
            if(j==szP){
                v.push_back(i-szP+2);
                j=pi[j-1];
            }
        }
    }
    return v;
}
