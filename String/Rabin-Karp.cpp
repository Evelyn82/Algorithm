
using ll=long long;
const int MOD=100003;

inline int mod(ll n){
    if(n>=0) return n%MOD;
    return ((-1*mod(-n))+MOD)%MOD;
    // return ((-n/MOD+1)*MOD+n)%MOD; -> AC
}
int main(){
    int n; char s[200001];
    scanf("%d %s",&n, s);
    
    int low=0, high=n;
    while(low+1<high){
        int mid=(low+high)/2;
        
        int H=0, pwr=1;
        vector<int> pos[MOD];
        bool found=false;
        
        for(int i=0;i<=n-mid;++i){
            if(i==0){
                // Hornor's method
                for(int j=0;j<mid;++j){
                    H=mod(H+1ll*s[mid-1-j]*pwr);
                    if(j<mid-1) pwr=mod(pwr*2);
                }
            }
            // Rolling hash
            else H = mod(2 * (H - 1ll * s[i-1] * pwr) + s[i + mid - 1]);
            
            if(!pos[H].empty()){
                for(int p : pos[H]){
                    bool same=true;
                    for(int j=0;j<mid;++j){
                        if(s[i+j]!=s[p+j]){
                            same=false;
                            break;
                        }
                    }
                    if(same){
                        found=true;
                        break;
                    }
                }
            }
            if(found) break;
            pos[H].push_back(i);
        }
        (found?low:high)=mid;
    }
    printf("%d\n", low);
}
