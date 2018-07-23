#ifndef UTPOLYGON_H_INCLUDED
#define UTPOLYGON_H_INCLUDED
#include "Vector.h"
#include "Polygon.h"

const double epsilon = 0.00001;

TEST (Polygon, ctor) {
  double a[] = {1,0};
  Vector u(a,2);
  double b[] = {1,1};
  Vector v(b,2);
  double c[] = {0,0};
  Vector w(c,2);

  Vector * vecs[3] = {&u, &v, &w}; // in place
  Polygon t(vecs, 3);
  EXPECT_EQ(1, t.m[1][1]);
  EXPECT_EQ(0, t.m[1][2]);
  EXPECT_EQ(1, t.m[2][1]);
  EXPECT_EQ(1, t.m[2][2]);
  EXPECT_EQ(0, t.m[3][1]);
  EXPECT_EQ(0, t.m[3][2]);
}

TEST (Polygon, PerimeterTriangle) {
  double a[] = {1,0};
  Vector u(a,2);
  double b[] = {1,1};
  Vector v(b,2);
  double c[] = {0,0};
  Vector w(c,2);

  Vector * vecs[3] = {&u, &v, &w}; // in place
  Polygon t(vecs, 3);
  EXPECT_EQ(1+1+sqrt(2), t.perimeter());
}

TEST (Polygon, AreaTriangle) {
  double a[] = {1,0};
  Vector u(a,2);
  double b[] = {1,1};
  Vector v(b,2);
  double c[] = {0,0};
  Vector w(c,2);

  Vector * vecs[3] = {&u, &v, &w}; // in place
  Polygon t(vecs, 3);
  EXPECT_NEAR(0.5, t.area(), epsilon);
}

TEST (Polygon, AreaPerimeterSquare) {
  double a[] = {1,0};
  Vector u(a,2);
  double b[] = {1,1};
  Vector v(b,2);
  double c[] = {0,1};
  Vector w(c,2);
  double d[] = {0,0};
  Vector x(d,2);

  Vector * vecs[4] = {&u, &v, &w, &x}; // in place
  Polygon t(vecs, 4);
  EXPECT_NEAR(1.0, t.area(), epsilon);
  EXPECT_NEAR(4.0, t.perimeter(), epsilon);
}

TEST (Polygon, factory) {
  double a[] = {1,0};
  Vector u(a,2);
  double b[] = {0,1};
  Vector v(b,2);
  double c[] = {1,1};
  Vector w(c,2);
  double d[] = {0,0};
  Vector x(d,2);

  Vector * vecs[4] = {&u, &v, &w, &x}; // in place
  Polygon p=Polygon::createPolygon(vecs,4);
  EXPECT_EQ(1, p.m[1][1]);
  EXPECT_EQ(0, p.m[1][2]);
  EXPECT_EQ(1, p.m[2][1]);
  EXPECT_EQ(1, p.m[2][2]);
  EXPECT_EQ(0, p.m[3][1]);
  EXPECT_EQ(1, p.m[3][2]);
  EXPECT_EQ(0, p.m[4][1]);
  EXPECT_EQ(0, p.m[4][2]);
  EXPECT_NEAR(4.0, p.perimeter(), epsilon);
  EXPECT_NEAR(1.0, p.area(), epsilon);
}

TEST (Polygon, Pentagon)
{
    double a[2] = {0,-9};
    double b[2] = {-9,-3};
    double c[2] = {-5,7};
    double d[2] = {5,7};
    double e[2] = {9,-3};

    Vector A(a,2);
    Vector B(b,2);
    Vector C(c,2);
    Vector D(d,2);
    Vector E(e,2);

    Vector * vs[5] = {&A,&D,&C,&B,&E};

    Polygon p=Polygon::createPolygon(vs,5);
    EXPECT_NEAR(194, p.area(), epsilon);
}

#endif //UTPOLYGON_H_INCLUDED
