struct fenwick{
    #define lowbit(x) (x&-x)
    int n,m;
    vector<vector<int>> v;
    fenwick(int _n,int _m) : n(_n+1),m(_m+1),v(_n+2,vector<int>(_m+2,0)){}
    void add(int x,int y,int u){
        ++x,++y;
        for(;x < n; x += lowbit(x)){
            for(int j = y;j < m; j += lowbit(j)) v[x][j] += u;
        } 
    }
    int qry(int x,int y){
        ++x,++y; 
        int ret = 0;
        for(; x ; x -= lowbit(x)){
            for(int j = y; j; j -= lowbit(j)) ret += v[x][j];
        }
        return ret;
    }
    //(l,u) <= (r,d)
    //d -   +
    //u +   -
    //  l   r
    void add(int l,int u,int r,int d,int x){
        ++r,++d;
        add(l,u,x);
        add(l,d,-x);
        add(r,u,-x);
        add(r,d,x);
    }
    int qry(int l,int u,int r,int d){
        --l,--u;
        return qry(r,d) - qry(r,u) - qry(l,d) + qry(l,u);
    }
};