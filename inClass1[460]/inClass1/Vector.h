#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>

const double PI = 3.1415926;

class Vector {
public:
  static Vector VectorFromString(std::string const & s) {
    std::string components = Vector::stripParentheses(s);
    // good to go
    std::stringstream ss(components);
    std::string componentString;

    double a[256], componentValue;
    unsigned dim = 0;
    while (getline(ss, componentString, ' '), !ss.fail())
      if (std::stringstream(componentString) >> componentValue) {
          a[dim] = componentValue;
          dim ++;
      }
    return Vector(a,dim);
  }
  static std::string stripParentheses(std::string const & s) {
    std::stringstream ss(s);
    std::string components;
    char c;
    ss >> c;
    if (c != '[')
      throw std::string("format error");
    getline(ss,components, ']');
    if (!ss.good())
      throw std::string("format error");
    return components;
  }
public:
    Vector (double a[], unsigned dim): d(dim), v(new double[dim]) {
        for (unsigned i=0; i < dim; ++i)
            v[i] = a[i];
    }
    Vector (unsigned dim, double ini=0.0):d(dim), v(new double[dim]) {
      for (unsigned i=0; i < dim; ++i)
          v[i] = ini;
    }
    Vector (Vector const & vec):d(vec.dim()), v(new double[vec.dim()]){
        for (unsigned i=0; i < d; ++i)
            v[i] = vec.v[i];
    }
    ~Vector () {delete [] v;}
    Vector & operator = (Vector const & vec){
        for (unsigned i=0; i < d; ++i)
            v[i] = vec.v[i];
        return *this;
    }
    unsigned dim () const { return d;}
    double & operator [] (unsigned i) const {return v[i-1];}

    // y <- scalar alpha x plus y(self)
    void saxpy(double a, Vector const & x) {
        for (unsigned i = 1; i <= d; ++i)
            (*this)[i] = a*x[i] + (*this)[i] ;
    }

    void scale(double c) {
        for (unsigned i = 0; i < d; ++i)
            v[i] /= c ;
    }

    double length() const {
      double s=0;
      for (int i=1; i<=dim(); ++i)
        s += (*this)[i]*(*this)[i];
      return sqrt(s);
    }
private:
    unsigned d;
    double * v;
};

double innerProduct(Vector const &u, Vector const & v) {
    if (u.dim() != v.dim())
        throw std::string("Dim error");
    double p = 0;
    for (unsigned i=1; i <= u.dim(); ++i)
        p += u[i]*v[i];
    return p;
}

Vector crossProduct(Vector const & u, Vector const & v) {
   if ((u.dim() != v.dim()) || (u.dim() != 3))
      throw std::string("Dim error");
   double a[3] = {u[2]*v[3]-u[3]*v[2],
                 -u[1]*v[3]+u[3]*v[1],
                  u[1]*v[2]-u[2]*v[1]};
   return Vector(a,3);
}
double dist(Vector const & u, Vector const & v) {
  double d2 = 0;
  for (unsigned i=1; i <= u.dim(); ++i )
    d2 += (u[i]-v[i])*(u[i]-v[i]);
  return sqrt(d2);
}

double areaTriangle(Vector const & v1, Vector const & v2, Vector const & v3) {
  double a = dist(v1, v2), b= dist(v2,v3), c = dist(v3,v1);
  double s = (a+b+c)/2;
  return sqrt(s*(s-a)*(s-b)*(s-c));
}

Vector operator * (double s, Vector const & v) {
    Vector w(v);
    for (unsigned i=1; i<= w.dim(); ++i)
        w[i] *= s;
    return w;
}

Vector operator + (Vector const & u, Vector const & v) {
    Vector w(u);
    for (unsigned i=1; i<= w.dim(); ++i)
        w[i] += v[i];
    return w;
}

Vector operator - (Vector const & u, Vector const & v) {
    Vector w(u);
    for (unsigned i=1; i<= w.dim(); ++i)
        w[i] -= v[i];
    return w;
}

bool pointingOut(Vector const & u, Vector const & v) {
    return u[1]*v[2]-u[2]*v[1] >= 0;
}
double angle(Vector const & u, Vector const & v) {
    double ang = acos(innerProduct(u,v)/(u.length()*v.length()));
    if (pointingOut(u,v))
      return ang*180/PI;
    else
      return 360-ang*180/PI;
}

Vector centroid (Vector * vecs[], int nVecs) {
    Vector a(*vecs[0]);
    for (int i=1; i< nVecs; ++i) {
      a = a + *vecs[i];
    }
    a = 1.0/nVecs * a;
    return a;
}

#endif // VECTOR_H_INCLUDED
