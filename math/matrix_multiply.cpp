template<class T> using Matrix = std::vector<std::vector<T>>;
template<class T> void set_matrix(Matrix<T>& m, int x, int y, T v) {
  m = Matrix<T>(x, std::vector<T>(y, v));
}
template<class T> Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>& b) {
  assert(a[0].size() == b.size());
  int sa = a.size(), sb = b[0].size(), sc = a[0].size();
  Matrix<T> ret; set_matrix(ret, sa, sb, 0);
  for(int i = 0; i < sa; ++i) {
    for(int j = 0; j < sb; ++j) {
      for(int k = 0; k < sc; ++k) {
        ret[i][j] += a[i][k] * b[k][j];
        // add ret[i][j] %= MOD if needed
      }
    }
  }
  return ret;
}