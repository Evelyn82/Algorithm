#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MX=1<<19;
char s[MX];
int n,d, sa[MX], pos[MX];

bool cmp(int i, int j){
	if(pos[i]!=pos[j]) return pos[i]<pos[j];
	i+=d;
	j+=d;
	return (i<n && j<n)?(pos[i]<pos[j]):(i>j);
}
void suffixArray(){
	n=strlen(s);
	for(int i=0;i<n;++i){
		sa[i]=i;
		pos[i]=s[i];
	}
	for(d=1;;d*=2){
		sort(sa, sa+n, cmp);
		
		int tmp[MX]={0,};
		for(int i=0;i<n-1;++i)
			tmp[i+1]=tmp[i]+cmp(sa[i], sa[i+1]);
		
		for(int i=0;i<n;++i) pos[sa[i]]=tmp[i];	
		if(tmp[n-1]==n-1) break;		
	}
}
int main(){
	scanf("%s", s);
	suffixArray();
	for(int i=0;i<n;++i) printf("%d\n", sa[i]+1);
}
