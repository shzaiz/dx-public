int qpow(int a, int b){
    int ans = 1;
    while(b){
        if(b&1){
            ans *= a;
        }
        a *= a;
        b>>=1;
    }
    return ans;
}