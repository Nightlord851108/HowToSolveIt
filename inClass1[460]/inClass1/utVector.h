#ifndef UTVECTOR_H_INCLUDED
#define UTVECTOR_H_INCLUDED

#include "Vector.h"
#include <string>
#include <vector>
#include <algorithm>

const double epsilon = 0.00001;

TEST (Array, twoD_first) {
    int a[][2] = {{1,2},{3,4}};
    ASSERT_EQ(1, a[0][0]);
    ASSERT_EQ(2, a[0][1]);
    ASSERT_EQ(3, a[1][0]);
    ASSERT_EQ(4, a[1][1]);
}

TEST (Array, twoD_second) {
    int a[][3] = {{2,-1,3},{1,1,3}};
    ASSERT_EQ(2, a[0][0]);
    ASSERT_EQ(-1, a[0][1]);
    ASSERT_EQ(3, a[0][2]);
    ASSERT_EQ(1, a[1][0]);
    ASSERT_EQ(1, a[1][1]);
    ASSERT_EQ(3, a[1][2]);
}

TEST (Vector, first) {
    double a[] = {1,0};
    Vector v(a,2);
    ASSERT_EQ(1,v[1]);
    ASSERT_EQ(0,v[2]);
}

TEST (Vector, innerProduct) {
    double a[] = {1,0};
    Vector u(a,2);
    double b[] = {1,1};
    Vector v(b,2);

    ASSERT_EQ(1, innerProduct(u,v));
}

TEST (Vector, innerProductDimError) {
    double a[] = {1,0};
    Vector u(a,2);
    double b[] = {1,1,1};
    Vector v(b,3);
    //ASSERT_THROW(innerProduct(u,v),std::string);
    try {
        innerProduct(u,v);
        FAIL();
    } catch (std::string s) {
        ASSERT_EQ(std::string("Dim error"), s);
    }
}

TEST (Vector, scalarProduct) {
    double a[] = {1,0};
    Vector u(a,2);
    Vector v = 3*u;

    ASSERT_EQ(3, v[1]);
    ASSERT_EQ(0, v[2]);
}

TEST (Vector, addition) {
    double a[] = {1,0};
    Vector u(a,2);
    double b[] = {1,1};
    Vector v(b,2);

    Vector w = u + v;
    ASSERT_EQ(2, w[1]);
    ASSERT_EQ(1, w[2]);
}

TEST (Vector, subtraction) {
    double a[] = {1,0};
    Vector u(a,2);
    double b[] = {1,1};
    Vector v(b,2);

    Vector w = u - v;
    ASSERT_EQ(0, w[1]);
    ASSERT_EQ(-1, w[2]);
}

TEST (Vector, length) {
    double b[] = {1,1};
    Vector v(b,2);

    EXPECT_NEAR(sqrt(2), v.length(),epsilon);
}

TEST (Vector, angle) {
    double a[] = {1,0};
    Vector u(a,2);
    double b[] = {1,1};
    Vector v(b,2);
    EXPECT_NEAR (45, angle(u, v), epsilon);
    EXPECT_NEAR (360-45, angle(v, u), epsilon);
}

TEST (Vector, crossProduct) {
  double a[] = {1,0,0};
  Vector u(a,3);
  double b[] = {1,1,0};
  Vector v(b,3);

  Vector w= crossProduct(u,v);
  EXPECT_NEAR(0, w[1], epsilon);
  EXPECT_NEAR(0, w[2], epsilon);
  EXPECT_NEAR(1, w[3], epsilon);

  Vector x= crossProduct(v,u);
  EXPECT_NEAR(0, x[1], epsilon);
  EXPECT_NEAR(0, x[2], epsilon);
  EXPECT_NEAR(-1, x[3], epsilon);
}

TEST (Vector, pointingOut) {
  double a[] = {1,0,0};
  Vector u(a,3);
  double b[] = {1,1,0};
  Vector v(b,3);

  EXPECT_TRUE(pointingOut(u,v));
  EXPECT_TRUE(!pointingOut(v,u));
}
TEST (Vector, linearCombination) {
    double a[] = {1,0};
    Vector u(a,2);
    double b[] = {1,1};
    Vector v(b,2);

    Vector w = 3*u + 2*v;
    ASSERT_EQ(5, w[1]);
    ASSERT_EQ(2, w[2]);
}

TEST (array, swap) {
    int myints[]={10,20,30,40,50 };
    std::iter_swap(myints, myints+4);
    ASSERT_EQ(50,myints[0]);
    ASSERT_EQ(10,myints[4]);
}

TEST (vector, swap) {
    int myints[]={10,20,30,40,50 };
    std::vector<int> myvector(myints, myints+5);
    std::iter_swap(myvector.begin(), myvector.begin()+4);
    ASSERT_EQ(50,myvector[0]);
    ASSERT_EQ(10,myvector[4]);
}

TEST (Vector, scale) {
    double b[] = {2, 4, 2};
    Vector v(b,3);
    v.scale(v[1]);
    ASSERT_EQ (1, v[1]);
    ASSERT_EQ (2, v[2]);
    ASSERT_EQ (1, v[3]);
}

TEST (Vector, centroid) {
  double a[] = {1,0};
  Vector u(a,2);
  double b[] = {0,1};
  Vector v(b,2);
  double c[] = {1,1};
  Vector w(c,2);
  double d[] = {0,0};
  Vector x(d,2);

  Vector * vecs[4] = {&u, &v, &w, &x};
  Vector o = centroid(vecs,4);
  EXPECT_NEAR(0.5, o[1], epsilon);
  EXPECT_NEAR(0.5, o[2], epsilon);

}

TEST (Vector, zero) {
    Vector v(2);
    ASSERT_EQ(0, v[1]);
    ASSERT_EQ(0, v[2]);
}

TEST (Vector, one) {
    Vector v(2, 1);
    ASSERT_EQ(1, v[1]);
    ASSERT_EQ(1, v[2]);
}

TEST (Vector, saxpy) {
  double a[] = {1, 0, 3};
  Vector u(a,3);
  double b[] = {2, 1, 2};
  Vector v(b,3);

  v.saxpy(-2, u);
  ASSERT_EQ(0, v[1]);
  ASSERT_EQ(1, v[2]);
  ASSERT_EQ(-4,v[3]);
}

TEST (Vector, stripParentheses) {
  std::string s("[ 1 0 3 ]");

  ASSERT_EQ(" 1 0 3 ", Vector::stripParentheses(s));
}

TEST (Vector, VectorFromString) {
  std::string s("[1 0 3]");
  Vector v=Vector::VectorFromString(s);

  ASSERT_EQ(1, v[1]);
  ASSERT_EQ(0, v[2]);
  ASSERT_EQ(3, v[3]);
}

#include <algorithm>
TEST (stdsort, defaultIncreasing) {
  int a[] = {3,1,5,7,4};
  std::vector<int> v(a,a+5);
  std::sort(v.begin(),v.end());
  EXPECT_EQ(1,v[0]);
  EXPECT_EQ(3,v[1]);
  EXPECT_EQ(4,v[2]);
  EXPECT_EQ(5,v[3]);
  EXPECT_EQ(7,v[4]);
}

bool geq(int a, int b) {return a>= b;}

TEST (stdsort, decreasing) {
  int a[] = {3,1,5,7,4};
  std::vector<int> v(a,a+5);
  std::sort(v.begin(),v.end(), geq);
  EXPECT_EQ(7,v[0]);
  EXPECT_EQ(5,v[1]);
  EXPECT_EQ(4,v[2]);
  EXPECT_EQ(3,v[3]);
  EXPECT_EQ(1,v[4]);
}

class DistanceToN {
public:
  DistanceToN(int N):n(N){}
  bool operator ()(int a, int b) {return abs(a-n) <= abs(b-n);}
  int n;
};

TEST (stdsort, increasingByDistanceToN ) {
  int a[] = {3,1,5,7,4};
  std::vector<int> v(a,a+5);

  std::sort(v.begin(),v.end(), DistanceToN(7));
  EXPECT_EQ(7,v[0]);
  EXPECT_EQ(5,v[1]);
  EXPECT_EQ(4,v[2]);
  EXPECT_EQ(3,v[3]);
  EXPECT_EQ(1,v[4]);
}


#endif // UTVECTOR_H_INCLUDED
