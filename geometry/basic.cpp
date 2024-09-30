// Calculate the area of a polygon
ld poly_area(const vector<Pt>& pt) {
  int sz = pt.size();
  ld ret = 0;
  for(int i = 1; i <= sz; ++i) {
    ret += pt[i - 1] ^ pt[i % sz];
  }
  return abs(ret) / 2;
}
// Polar Compare
template<class T> struct CmpByAngle {
  bool operator()(const T& lhs, const T& rhs) {
    using eps_compare::ge;
    T zero = T();
    if((lhs < zero) ^ (rhs < zero))
      return (lhs < zero) < (rhs < zero);
    return (lhs ^ rhs) > 0;
    // return ge(lhs ^ rhs, typename T::value_type());
  }
};
// Pick's Theorm
// A = i + b/2 - 1
// A: Area of polygon
// i: Grid number in the inner
// b: Grid number on the side
constexpr ld pi = 3.14159265359;
// Float compare
bool eq(ld l, ld r) { return abs(l - r) < EPS; }
bool ne(ld l, ld r) { return abs(l - r) > EPS; }
bool le(ld l, ld r) { return (l - r) < -EPS; }
bool ge(ld l, ld r) { return (l - r) > EPS; }
bool leq(ld l, ld r) { return (l - r) < EPS; }
bool geq(ld l, ld r) { return (l - r) > -EPS; }