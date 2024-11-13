struct BIT{
    #define lowbit(x) (x&-x)
    int n;
    vector<int>bit;
    void init(int _n){
        n=_n+1;
        bit=vector<int>(n,0);
    }
    int query(int x){
        x++;
        int res=0;
        for(;x>0;x-=lowbit(x))res+=bit[x];
        return res;
    }
    int range_q(int l,int r)return query(r)-query(l-1);
    int upd(int x,int v){
        x++;
        for(;x<n;x+=lowbit(x))bit[x]+=v;
    }
};