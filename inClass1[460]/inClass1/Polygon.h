#ifndef POLYGON_H_INCLUDED
#define POLYGON_H_INCLUDED

#include "Vector.h"
#include "Matrix.h"

class Polygon {
public:
  static Polygon createPolygon(Vector * vecs[], unsigned nVertices) {
    Polygon p(vecs, nVertices);
    Vector o = centroid(vecs, nVertices);
    p.m.sortVectorsAroundGivenVectorWithRef(o, p.m[1]);
    return p;
  }
public:
  Polygon (Vector * vecs[], unsigned nVertices):m() {
    for (unsigned i=0; i < nVertices; ++i)
      m.add(vecs[i]);
  }
  unsigned nVertices() const {return m.rows();}
  double perimeter () const {
    double p = 0;
    for (unsigned i=1; i <= nVertices()-1; ++i)
      p += dist(m[i], m[i+1]);
    p += dist(m[nVertices()],m[1]);
    return p;
  }
  double area() const {
    double a = 0;
    for (unsigned i=3; i<= nVertices(); ++i)
      a += areaTriangle(m[1], m[i-1], m[i]);
    return a;
  }
  Matrix m;
};

#endif //POLYGON_H_INCLUDED
