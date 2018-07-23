#ifndef UTMATRIX_H_INCLUDED
#define UTMATRIX_H_INCLUDED

#include "Matrix.h"
#include "Vector.h"

TEST (Matrix, creation) {
    double a[] = {1, 1, 0, 3, 4};
    Vector u(a,5);
    double b[] = {2, 1, -1, 1, 1};
    Vector v(b,5);
    double c[] = {3, -1, -1, 2, -3};
    Vector w(c,5);
    double d[] = {-1, 2, 3, -1, 4};
    Vector x(d,5);

    Matrix m;
    m.add(&u);
    m.add(&v);
    m.add(&w);
    m.add(&x);

    ASSERT_EQ(4, (int) m.rows());
    ASSERT_EQ(5, (int) m.cols());
}

TEST (Matrix, constructor) {
    double a[] = {1, 0, 3};
    Vector u(a,3);
    double b[] = {0, 1, 2};
    Vector v(b,3);
    Vector * vecs[] = {&u, &v};

    Matrix m(vecs, 2);

    ASSERT_TRUE(pivot(1, m));

    ASSERT_EQ(1, m.at(1,1));
    ASSERT_EQ(0, m.at(1,2));
    ASSERT_EQ(3, m.at(1,3));

    ASSERT_EQ(0, m.at(2,1));
    ASSERT_EQ(1, m.at(2,2));
    ASSERT_EQ(2, m.at(2,3));
}

TEST (Matrix, pivotSwap) {
    double a[] = {0, 1, 2};
    Vector u(a,3);
    double b[] = {1, 0, 3};
    Vector v(b,3);

    Matrix m;
    m.add(&u);
    m.add(&v);

    ASSERT_TRUE(pivot(1, m));

    ASSERT_EQ(1, m.at(1,1));
    ASSERT_EQ(0, m.at(1,2));
    ASSERT_EQ(3, m.at(1,3));

    ASSERT_EQ(0, m.at(2,1));
    ASSERT_EQ(1, m.at(2,2));
    ASSERT_EQ(2, m.at(2,3));
}

TEST (Matrix, pivotNoSwap) {
    double a[] = {1, 0, 3};
    Vector u(a,3);
    double b[] = {0, 1, 2};
    Vector v(b,3);

    Matrix m;
    m.add(&u);
    m.add(&v);

    ASSERT_TRUE(pivot(1, m));

    ASSERT_EQ(1, m.at(1,1));
    ASSERT_EQ(0, m.at(1,2));
    ASSERT_EQ(3, m.at(1,3));

    ASSERT_EQ(0, m.at(2,1));
    ASSERT_EQ(1, m.at(2,2));
    ASSERT_EQ(2, m.at(2,3));
}

TEST (Matrix, pivotImpossible) {
    double a[] = {0, 1, 2};
    Vector u(a,3);
    double b[] = {0, 0, 3};
    Vector v(b,3);
    Matrix m;
    m.add(&u);
    m.add(&v);
    ASSERT_FALSE(pivot(1, m));
}

TEST (Matrix, eliminate) {
    double a[] = {1, 0, 3};
    Vector u(a,3);
    double b[] = {2, 1, 2};
    Vector v(b,3);
    Matrix m;
    m.add(&u);
    m.add(&v);

    eliminate(1,m);

    ASSERT_EQ(1, m.at(1,1));
    ASSERT_EQ(0, m.at(1,2));
    ASSERT_EQ(3, m.at(1,3));

    ASSERT_EQ(0, m.at(2,1));
    ASSERT_EQ(1, m.at(2,2));
    ASSERT_EQ(-4, m.at(2,3));
}

TEST (Matrix, forwardGaussian) {
    double a[] = {1, 0, 3};
    Vector u(a,3);
    double b[] = {2, 1, 2};
    Vector v(b,3);
    Matrix m;
    m.add(&u);
    m.add(&v);

    forwardGaussian(m);

    ASSERT_EQ(1, m.at(1,1));
    ASSERT_EQ(0, m.at(1,2));
    ASSERT_EQ(3, m.at(1,3));

    ASSERT_EQ(0, m.at(2,1));
    ASSERT_EQ(1, m.at(2,2));
    ASSERT_EQ(-4, m.at(2,3));
}

TEST (Matrix, GaussJordan) {
    double a[] = {1, 1, 0, 3, 4};
    Vector u(a,5);
    double b[] = {2, 1, -1, 1, 1};
    Vector v(b,5);
    double c[] = {3, -1, -1, 2, -3};
    Vector w(c,5);
    double d[] = {-1, 2, 3, -1, 4};
    Vector x(d,5);

    Matrix m;
    m.add(&u);
    m.add(&v);
    m.add(&w);
    m.add(&x);

    GaussJordan(m);

    ASSERT_EQ(1, m.at(1,1));
    ASSERT_EQ(0, m.at(1,2));
    ASSERT_EQ(0, m.at(1,3));
    ASSERT_EQ(0, m.at(1,4));
    ASSERT_EQ(-1, m.at(1,5));

    ASSERT_EQ(0, m.at(2,1));
    ASSERT_EQ(1, m.at(2,2));
    ASSERT_EQ(0, m.at(2,3));
    ASSERT_EQ(0, m.at(2,4));
    ASSERT_EQ(2, m.at(2,5));

    ASSERT_EQ(0, m.at(3,1));
    ASSERT_EQ(0, m.at(3,2));
    ASSERT_EQ(1, m.at(3,3));
    ASSERT_EQ(0, m.at(3,4));
    ASSERT_EQ(0, m.at(3,5));

    ASSERT_EQ(0, m.at(4,1));
    ASSERT_EQ(0, m.at(4,2));
    ASSERT_EQ(0, m.at(4,3));
    ASSERT_EQ(1, m.at(4,4));
    ASSERT_EQ(1, m.at(4,5));
}

using namespace std;

TEST (setw, first) {
  stringstream ss;
  ss << "[" << setw(5) << 1 << setw(5) << 1 << setw(5) << 0 << setw(5) << 3
     << "|" << setw(5) << 4 <<"]" << "\n";
  ss << "[" << setw(5) << 2 << setw(5) << 1 << setw(5) << -1 << setw(5) << 1
     << "|" << setw(5) << 1 <<"]" << "\n";
  ss << "[" << setw(5) << 3 << setw(5) << -1 << setw(5) << -1 << setw(5) << 2
     << "|" << setw(5) << -3 <<"]" << "\n";
  ss << "[" << setw(5) << -1 << setw(5) << 2 << setw(5) << 3 << setw(5) << -1
     << "|" << setw(5) << 4 <<"]" << "\n";

  string ans = "[    1    1    0    3|    4]\n"
               "[    2    1   -1    1|    1]\n"
               "[    3   -1   -1    2|   -3]\n"
               "[   -1    2    3   -1|    4]\n";
  ASSERT_EQ(ans,ss.str());
}

TEST (Matrix, outputMatrixForm) {
    double a[] = {1, 1, 0, 3, 4};
    Vector u(a,5);
    double b[] = {2, 1, -1, 1, 1};
    Vector v(b,5);
    double c[] = {3, -1, -1, 2, -3};
    Vector w(c,5);
    double d[] = {-1, 2, 3, -1, 4};
    Vector x(d,5);

    Matrix m;
    m.add(&u);
    m.add(&v);
    m.add(&w);
    m.add(&x);

    string org = "[    1    1    0    3|    4]\n"
                 "[    2    1   -1    1|    1]\n"
                 "[    3   -1   -1    2|   -3]\n"
                 "[   -1    2    3   -1|    4]\n";
    ASSERT_EQ(org,m.strAugmentedMatrix(4));

    GaussJordan(m);

    string ans = "[    1    0    0    0|   -1]\n"
                 "[    0    1    0    0|    2]\n"
                 "[    0    0    1    0|    0]\n"
                 "[   -0   -0   -0    1|    1]\n";
    ASSERT_EQ(ans,m.strAugmentedMatrix(4));
}

TEST (Matrix, zero) {
    Matrix n(2,2);
    ASSERT_EQ(0, n[1][1]);
    ASSERT_EQ(0, n[1][2]);
    ASSERT_EQ(0, n[2][1]);
    ASSERT_EQ(0, n[2][2]);
}

TEST (Matrix, multiply) {
    double a[] = {1, 0};
    Vector u(a,2);
    double b[] = {2, 1};
    Vector v(b,2);
    Matrix m;
    m.add(&u);
    m.add(&v);

    double a1[] = {1, 0};
    Vector u1(a1,2);
    double b1[] = {0, 1};
    Vector v1(b1,2);
    Matrix m1;
    m1.add(&u1);
    m1.add(&v1);

    Matrix n = m * m1;
    ASSERT_EQ(1, n[1][1]);
    ASSERT_EQ(0, n[1][2]);
    ASSERT_EQ(2, n[2][1]);
    ASSERT_EQ(1, n[2][2]);
}

TEST (Matrix, multiply2) {
    Matrix m(2,2,1);

    Matrix n = m * m;
    ASSERT_EQ(2, n[1][1]);
    ASSERT_EQ(2, n[1][2]);
    ASSERT_EQ(2, n[2][1]);
    ASSERT_EQ(2, n[2][2]);
}

TEST (Matrix, multiplyException) {
    Matrix m(2,2,1);
    Matrix n(3,3);

    try {
      m * n;
      FAIL() << "We shouldn't get here.";
    }
    catch (string s) {
      ASSERT_EQ(string("dimension error"), s);
    }
}

TEST (Matrix, transpose) {
    Matrix m(2,3,1);
    Matrix n(m.transpose());
    ASSERT_EQ(3,n.rows());
    ASSERT_EQ(2,n.cols());
}

TEST (Matrix, forwardGaussianWithOutput) {
  double a[] = {1, 1, 0, 3, 4};
  Vector u(a,5);
  double b[] = {2, 1, -1, 1, 1};
  Vector v(b,5);
  double c[] = {3, -1, -1, 2, -3};
  Vector w(c,5);
  double d[] = {-1, 2, 3, -1, 4};
  Vector x(d,5);

  Matrix m;
  m.add(&u);
  m.add(&v);
  m.add(&w);
  m.add(&x);

  GaussJordanWithOutput (m, 4, std::cout);
}

#endif // UTMATRIX_H_INCLUDED
