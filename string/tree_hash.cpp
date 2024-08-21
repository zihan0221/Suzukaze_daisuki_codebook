map<vector<int>,int>id;
ll dfs(int u){
    vector<ll> h;
    for(ll child : edge[u]){
        h.push_back(dfs(child));
    }
    sort(h.begin(), h.end());
    if(id.count(h))return id[h];
    else return id[h]=id.size();
}