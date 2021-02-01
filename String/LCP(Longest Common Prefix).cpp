void LCP(){
    for(int i=0, k=0;i<n;++i, k=max(k-1, 0)){
        if(pos[i]==0) continue;
        // if(pos[i]==n-1) continue; 뒤와 비교할 경우
        
        for(int j=sa[pos[i]-1];s[i+k]==s[j+k];++k);
        //for(int j=sa[pos[i]+1]...) 뒤와 비교할 경우
        
        lcp[pos[i]]=k;
    }
    printf("x ");
    for(int i=1;i<n;++i) printf("%d ", lcp[i]);
    printf("\n");
}
