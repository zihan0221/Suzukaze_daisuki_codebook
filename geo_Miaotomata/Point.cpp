using ld = long double;
template<class T>
struct pt{
	T x,y;
	pt(T _x,T _y):x(_x),y(_y){}
	pt():x(0),y(0){}
	
	pt operator * (T  c){ return pt(x*c,y*c);}
	pt operator / (T  c){ return pt(x/c,y/c);}
	pt operator + (pt a){ return pt(x+a.x,y+a.y);}
	pt operator - (pt a){ return pt(x-a.x,y-a.y);}
	T  operator * (pt a){ return x*a.x + y*a.y;}
	T  operator ^ (pt a){ return x*a.y - y*a.x;}

	auto operator<=>(pt o) const { return (x != o.x) ? x <=> o.x : y <=> o.y; } // c++20
	bool operator < (pt a) const { return x < a.x || (x == a.x && y < a.y);};
	bool operator== (pt a) const { return x == a.x and y == a.y;};
	friend T ori(pt a, pt b, pt c) { return (b - a) ^ (c - a); }
	friend T abs2(pt a) { return a * a; }
};
using numbers::pi; // c++20
const ld pi = acos(-1);
const ld eps = 1e-8L;
using Pt = pt<ld>;
int sgn(ld x) { return (x > -eps) - (x < eps); } // dcmp == sgn
ld abs(Pt a) { return sqrt(abs2(a)); }
ld arg(Pt x) { return atan2(x.y, x.x); }
bool argcmp(Pt a, Pt b) { // arg(a) < arg(b)
    int f = (Pt{a.y, -a.x} > Pt{} ? 1 : -1) * (a != Pt{});
    int g = (Pt{b.y, -b.x} > Pt{} ? 1 : -1) * (b != Pt{});
    return f == g ? (a ^ b) > 0 : f < g;
}
Pt unit(Pt x) { return x / abs(x); }
Pt rotate(Pt u) { // pi / 2
    return {-u.y, u.x};
}
Pt rotate(Pt u, ld a) {
    Pt v{sin(a), cos(a)};
    return {u ^ v, u * v};
}


istream &operator>>(istream &s, Pt &a) { return s >> a.x >> a.y; }
ostream &operator<<(ostream &s, Pt &a) { return s << "(" << a.x << ", " << a.y << ")";} 

bool collinearity(Pt a, Pt b, Pt c) {  // 三點共線
    return ((b - a) ^ (c - a)) == 0;
}


