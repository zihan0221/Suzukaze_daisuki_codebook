// Need Line && norm()
double ori(Pt a, Pt b, Pt c) { return (b - a) ^ (c - a); }
int PtSide(Pt p, Line L) {
  return dcmp(ori(L.s, L.e, p) / norm(L.s - L.e));
}
bool argcmp(const Pt &a, const Pt &b) { // arg(a) < arg(b)
  int f = (Pt{a.y, -a.x} > Pt{} ? 1 : -1) * (a != Pt{});
  int g = (Pt{b.y, -b.x} > Pt{} ? 1 : -1) * (b != Pt{});
  return f == g ? (a ^ b) > 0 : f < g;
}
Pt LineInter(Line l, Line m) {
  double s = ori(m.s, m.e, l.s), t = ori(m.s, m.e, l.e);
  return (l.e * s - l.s * t) / (s - t);
}
#ifndef all
  #define all(x) (x).begin(), (x).end()
#endif
vector < double > PolyUnion(const vector < vector < Pt >> & P) {
  const int n = P.size();
  vector < double > Area(n + 1);
  vector < Line > Ls;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < P[i].size(); j++)
      Ls.push_back({
        P[i][j],
        P[i][(j + 1) % P[i].size()]
      });
  auto cmp = [ & ](Line & l, Line & r) {
    Pt u = l.e - l.s, v = r.e - r.s;
    if (argcmp(u, v)) return true;
    if (argcmp(v, u)) return false;
    return PtSide(l.s, r) < 0;
  };
  sort(all(Ls), cmp);
  for (int l = 0, r = 0; l < Ls.size(); l = r) {
    while (r < Ls.size() and!cmp(Ls[l], Ls[r])) r++;
    Line L = Ls[l];
    vector < pair < Pt, int >> event;
    for (auto& ls : Ls) {
      auto c = ls.s, d = ls.e;
      if (dcmp((L.s - L.e) ^ (c - d)) != 0) {
        int s1 = PtSide(c, L) == 1;
        int s2 = PtSide(d, L) == 1;
        if (s1 ^ s2) event.emplace_back(LineInter(L, {
          c,
          d
        }), s1 ? 1 : -1);
      } else if (PtSide(c, L) == 0 and dcmp((L.s - L.e) * (c - d)) > 0) {
        event.emplace_back(c, 2);
        event.emplace_back(d, -2);
      }
    }
    sort(all(event), [ & ](auto i, auto j) {
      return (L.s - i.first) * (L.s - L.e) < (L.s - j.first) * (L.s - L.e);
    });
    int cov = 0, tag = 0;
    Pt lst {
      0,
      0
    };
    for (auto[p, s]: event) {
      if (cov >= tag) {
        Area[cov] += lst ^ p;
        Area[cov - tag] -= lst ^ p;
      }
      if (abs(s) == 1) cov += s;
      else tag += s / 2;
      lst = p;
    }
  }
  for (int i = n - 1; i >= 0; i--) Area[i] += Area[i + 1];
  for (int i = 1; i <= n; i++) Area[i] /= 2;
  return Area;
};
#undef all