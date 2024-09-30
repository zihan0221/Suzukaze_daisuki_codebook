double cross(Pt o, Pt a, Pt b){
  return (a-o) ^ (b-o);
}
void convex_hull(vector<Pt> pt, vector<Pt>& hull){
  sort(pt.begin(),pt.end());
  int top=0;
  hull = vector<Pt>(2*pt.size());
  for (int i=0; i<(int)pt.size(); i++){
    while (top >= 2 && cross(hull[top-2],hull[top-1],pt[i]) <= 0)
      top--;
    hull[top++] = pt[i];
  }
  for (int i=pt.size()-2, t=top+1; i>=0; i--){
    while (top >= t && cross(hull[top-2],hull[top-1],pt[i]) <= 0)
      top--;
    hull[top++] = pt[i];
  }
  hull.resize(top-1);
}