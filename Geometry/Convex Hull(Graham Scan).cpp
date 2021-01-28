// 52ms

typedef long long ll;
struct ConvexHull{
    ll x, y;
    ll p, q;
    //ConvexHull(){} 기본 생성자 작성시
    //ConvexHull(ll x1, ll y1) : ... 작성가능
    ConvexHull(ll x1=0, ll y1=0):x(x1), y(y1), p(1), q(0){}
}c[MX];
bool cmp(const ConvexHull& a, const ConvexHull& b){
    if(a.q*b.p != a.p*b.q) return a.q*b.p < a.p*b.q;
    
    if(a.y!=b.y) return a.y<b.y;
    return a.x<b.x;
}
ll ccw(const ConvexHull& a, const ConvexHull& b, const ConvexHull& c){
    return (a.x*b.y + b.x*c.y + c.x*a.y - b.x*a.y - c.x*b.y - a.x*c.y);
}

int main(){
    int n; scanf("%d",&n);
    ll x,y;
    for(int i=0;i<n;++i){
        scanf("%lld%lld", &x,&y);
        c[i]=ConvexHull(x,y);
    }
    sort(c, c+n, cmp);
    
    for(int i=1;i<n;++i){
        c[i].p=c[i].x-c[0].x;
        c[i].q=c[i].y-c[0].y;
    }
    sort(c+1, c+n, cmp);
    
    stack<int> s;
    s.push(0);
    s.push(1);
    int next=2;
    while(next<n){
        while(s.size()>=2){
            int first, second;
            second=s.top(); s.pop();
            first=s.top();
            
            if(ccw(c[first], c[second], c[next])>0){
                s.push(second);
                break;
            }
        }
        s.push(next++);
    }
    printf("%d\n", (int)s.size()); 
}


// 12ms boj 1708 
/*
//#include <bits/stdc++.h>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <unistd.h>
#include <sys/mman.h>
#define SZ(v) ((int)(v).size())
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
pii p[100003];
vector<int> v, w;

inline bool concave(int i, int j, int k){
    return (ll)(p[j].y-p[i].y)*(p[k].x-p[j].x)
        > (ll)(p[j].x-p[i].x)*(p[k].y-p[j].y);
}

inline bool convex(int i, int j, int k){
    return (ll)(p[j].y-p[i].y)*(p[k].x-p[j].x)
        < (ll)(p[j].x-p[i].x)*(p[k].y-p[j].y);
}

namespace fio {
    size_t sz = 2097152, cur = 2097152;
    off_t ofs;
    char *buf;

    inline void init(size_t n) {
        int pgsize = getpagesize();
        sz = ((n - 1) / pgsize + 1) * pgsize;
        cur = sz;
    }

    inline int next_char() {
        if (sz == cur) {
            if (buf) munmap(buf, sz);
            buf = (char *)mmap(NULL, sz, PROT_READ, MAP_PRIVATE, 0, ofs);
            if (buf == MAP_FAILED) return EOF;
            ofs += sz;
            cur = 0;
        }
        return buf[cur] ? buf[cur++] : EOF;
    }

    inline unsigned next_unsigned() {
        int fst = 0;
        unsigned ans = 0;
        while (fst != EOF && (fst < 48 || fst > 57)) fst = next_char();
        while (fst >= 48 && fst <= 57) {
            ans = 10 * ans + (fst & 15);
            fst = next_char();
        }
        return ans;
    }

    inline int next_int() {
        int fst = 0, ans = 0, inv = 0;
        while (fst != EOF && (fst < 45 || fst > 57)) fst = next_char();
        if (fst == 45) {
            fst = next_char();
            inv = 1;
        }
        while (fst >= 48 && fst <= 57) {
            ans = 10 * ans + (fst & 15);
            fst = next_char();
        }
        return inv ? -ans : ans;
    }
};

int main(){
    n = fio::next_int();
    for (int i=0; i<n; i++){
        p[i].x = fio::next_int();
        p[i].y = fio::next_int();
    }
    sort(p, p+n);
    for (int i=0; i<n; i++){
        while (SZ(v) > 1 && !concave(v[SZ(v)-2], v.back(), i)){
            v.pop_back();
        }
        v.push_back(i);
    }
    for (int i=n-1; i>=0; i--){
        while (SZ(w) > 1 && !convex(i, w.back(), w[SZ(w)-2])){
            w.pop_back();
        }
        w.push_back(i);
    }
    printf("%d\n", SZ(v)+SZ(w)-2);
    return 0;
}
*/
