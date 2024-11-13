template<class T> struct Point {
  static constexpr T eps = 1e-8;
  static int dcmp(T x) {
    if(abs(x) <= eps) return 0;
    else return x < 0 ? -1 : 1;
  }
  struct Self {
    T x, y;
    Self(T _x=0, T _y=0):x(_x), y(_y) {}
    Self operator+(const Self &a) const {
      return Self(x+a.x, y+a.y);  }
    Self operator-(const Self &a) const {
      return Self(x-a.x, y-a.y);  }
    Self operator*(const T &a) const {
      return Self(x*a, y*a);  }
    Self operator/(const T &a) const {
      return Self(x/a, y/a);  }
    T operator*(const Self &a) const {
      return x*a.x + y*a.y;  }
    T operator^(const Self &a) const {
      return x*a.y - y*a.x;  }
    auto operator<=>(const Self &a) const {
      return (x != a.x) ? x <=> a.x : y <=> a.y; }
      //return dcmp(x-a.x) < 0 || (dcmp(x-a.x) == 0 && dcmp(y-a.y) < 0); }
    bool operator==(const Self &a) const {
      return dcmp(x-a.x) == 0 && dcmp(y-a.y) == 0;  }
  };
  static T norm2(const Self &a) {
    return a*a; }
  static T norm(const Self &a) {
    return sqrt(norm2(a)); }
  static Self perp(const Self &a) {
    return Self(-a.y, a.x); }
  static Self rotate(const Self &a, T ang) {
    return Self(a.x*cos(ang)-a.y*sin(ang), a.x*sin(ang)+a.y*cos(ang)); }
  struct Line {
    Self s, e, v; // start, end, end-start
    T ang;
    Line(Self _s=Self(0, 0), Self _e=Self(0, 0)):s(_s), e(_e) { v = e-s; ang = atan2(v.y, v.x); }
    bool operator<(const Line &L) const {
      return ang < L.ang;
  } };
  struct Circle {
    Self o; T r;
    Circle(Self _o=Self(0, 0), T _r=0):o(_o), r(_r) {}
  };
};