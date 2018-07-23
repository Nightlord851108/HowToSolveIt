#ifndef UTEXP_H_INCLUDED
#define UTEXP_H_INCLUDED

#include <cmath>

const double epsilon = 0.00001;
void swap(int &a, int & b) {
  int t = a;
  a = b;
  b = t;
}

TEST (sawp, first) {
  int i=0, j=1;
  swap(i,j);
  EXPECT_EQ(1,i);
  EXPECT_EQ(0,j);
}

void bubble(int a[], int n) {
  for (int j=n-1; j>0; --j)
    for (int i=0; i<j; ++i)
      if (a[i]>a[i+1])
        swap(a[i],a[i+1]);
}

bool isGreaterThan(int i, int j) {return i > j;}
bool isLessThan(int i, int j) {return i < j;}

class isGreaterThanByDistanceToN {
public:
  isGreaterThanByDistanceToN(int N) :n(N) {}
  bool operator() (int i, int j) const {return abs(i-n) > abs(j-n);}
private:
  const int n;
};

#include <iostream>
using namespace std;

void bubble(int a[], int n, bool (*func) (int,int)) {
  for (int j=n-1; j>0; --j)
    for (int i=0; i<j; ++i)
      if (func(a[i],a[i+1]))
        swap(a[i],a[i+1]);
      cout << "ptr version called" << endl;
}

void bubble(int a[], int n, isGreaterThanByDistanceToN  const & func) {
  for (int j=n-1; j>0; --j)
    for (int i=0; i<j; ++i)
      if (func(a[i],a[i+1]))
        swap(a[i],a[i+1]);
      cout << "obj version called" << endl;
}

/*
template <class Compare>
void bubble(int a[], int n, Compare func) {
  for (int j=n-1; j>0; --j)
    for (int i=0; i<j; ++i)
      if (func(a[i],a[i+1]))
        swap(a[i],a[i+1]);
}
*/
TEST (bubble, first) {
  int  a[] = {6,3,9};
  bubble(a,3);
  EXPECT_EQ(3, a[0]);
  EXPECT_EQ(6, a[1]);
  EXPECT_EQ(9, a[2]);
}

TEST (bubble, second) {
  int  a[] = {9,8,7,6,5,4,3,2,1};
  bubble(a,9);
  EXPECT_EQ(1, a[0]);
  EXPECT_EQ(2, a[1]);
  EXPECT_EQ(3, a[2]);
  EXPECT_EQ(4, a[3]);
  EXPECT_EQ(5, a[4]);
  EXPECT_EQ(6, a[5]);
  EXPECT_EQ(7, a[6]);
  EXPECT_EQ(8, a[7]);
  EXPECT_EQ(9, a[8]);
}

TEST (bubble, third) {
  int  a[] = {6,3,9};
  bubble(a,3,isGreaterThan);
  EXPECT_EQ(3, a[0]);
  EXPECT_EQ(6, a[1]);
  EXPECT_EQ(9, a[2]);
}

TEST (bubble, isGreaterThan) {
  int  a[] = {6,3,9};
  bubble(a,3,isGreaterThan);
  EXPECT_EQ(3, a[0]);
  EXPECT_EQ(6, a[1]);
  EXPECT_EQ(9, a[2]);
}

TEST (bubble, isLessThan) {
  int  a[] = {6,3,9};
  bubble(a,3,isLessThan);
  EXPECT_EQ(9, a[0]);
  EXPECT_EQ(6, a[1]);
  EXPECT_EQ(3, a[2]);
}

TEST (bubble, isGreaterThanByDistanceToN) {
  int  a[] = {6,3,9};
  bubble(a,3,isGreaterThanByDistanceToN(7));
  EXPECT_EQ(6, a[0]);
  EXPECT_EQ(9, a[1]);
  EXPECT_EQ(3, a[2]);
}

#endif //UTEXP_H_INCLUDED
