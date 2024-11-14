while(Q.size()){
    auto [dx,x] = Q.top();Q.pop();
    if(dis[x].size() >= k) continue;
    dis[x].PB(dx);
    for(auto [v,w]:E[x]) Q.emplace(w+dx,v);
}