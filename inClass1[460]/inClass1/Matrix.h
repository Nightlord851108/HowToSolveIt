#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include "Vector.h"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

class IncreasingByAngleToRefAroundGiven {
public:
  IncreasingByAngleToRefAroundGiven(Vector const & given, Vector const & refVec):o(given), ref(refVec-given) {}
  bool operator () (Vector * u, Vector * v) {
    Vector b1=*u-o;
    Vector b2=*v-o;
    return angle(ref,b1) <= angle(ref,b2);
  }
  Vector o;
  Vector ref;
};


class Matrix {
public:
    Matrix(){sys.push_back(0);}
    Matrix(unsigned rows, unsigned cols, double ini=0.0) {
      sys.push_back(0);
      for (unsigned i=1; i <= rows; ++i)
        sys.push_back(new Vector(cols, ini));
    }
    Matrix(Vector * vecs[], unsigned nRows) {
      sys.push_back(0);
      for (unsigned i=0; i < nRows; ++i)
          sys.push_back(new Vector(*vecs[i]));
    }
    ~Matrix() {
      for (unsigned i=0; i <=rows(); ++i)
        delete sys[i];
    }
    void add (Vector * v) {sys.push_back(new Vector(*v));}
    unsigned rows() const {return sys.size()-1;}
    unsigned cols() const {
        return (sys.size()==1)? 0 : sys[1]->dim();
    }
    double at(unsigned i, unsigned j) const {return (*sys[i])[j];}
    void swap (unsigned i, unsigned j) {std::iter_swap(sys.begin()+i, sys.begin()+j);}
    Vector & operator [] (unsigned i) const {return *sys[i];}
    Matrix transpose () const {
        Matrix r(this->cols(), this->rows());
        for (unsigned i=1; i<=r.rows(); ++i)
          for (unsigned j=1; j <=r.cols(); ++j)
              r[i][j] = (*this)[j][i];
        return r;
    }

    std::string strAugmentedMatrix(unsigned partitionPos) {
        std::stringstream ss;
        for (unsigned i=1; i <= rows(); ++i) {
          ss << "[";
          unsigned j=1;
          for (; j <= partitionPos; ++j) {
            ss << std::setw(5) << std::setprecision(3) << at(i,j);
          }
          ss << "|";
          for (; j <= cols(); ++j) {
            ss << std::setw(5) << std::setprecision(3) << at(i,j);
          }
          ss <<"]\n";
        }
        return ss.str();
    }
    void sortVectorsAroundGivenVectorWithRef(Vector const & given, Vector const & ref) {
      std::sort(sys.begin()+1, sys.end(), IncreasingByAngleToRefAroundGiven(given,ref));
    }
private:
    std::vector<Vector *> sys;
};

void eliminate (unsigned i, Matrix &sys) {
    for (unsigned j=i+1; j <=sys.rows(); ++j) {
        sys[j].saxpy(-sys[j][i], sys[i]);
    }
}

bool pivot(unsigned i, Matrix &sys) {
    unsigned j = i;
    for (; j<=sys.rows(); ++j) {
        if (sys.at(j,i) != 0)
            break;
    }
    bool pivoted = j<=sys.rows();
    if (pivoted && j != i)
        sys.swap(i,j);

    return pivoted;
}

void forwardGaussian (Matrix &sys) {
    for (unsigned i=1; i<=sys.rows(); ++i) {
        if (pivot(i, sys)) {
            sys[i].scale(sys[i][i]);
            eliminate(i,sys);
        }
    }
}

void forwardGaussianWithOutput (Matrix &sys, unsigned partitionPos, std::ostream &out) {
    for (unsigned i=1; i<=sys.rows(); ++i) {
        out << sys.strAugmentedMatrix(partitionPos) <<std::endl;
        if (pivot(i, sys)) {
            sys[i].scale(sys[i][i]);
            eliminate(i,sys);
        }
    }
}

void backEliminate (unsigned i, Matrix &sys) {
    for (unsigned j=i-1; j > 0; --j) {
        sys[j].saxpy(-sys[j][i], sys[i]);
    }
}

void backwardGaussian (Matrix &sys) {
    for (unsigned i=sys.rows(); i > 0; --i) {
        if (sys[i][i] != 0) {
            backEliminate(i,sys);
        }
    }
}

void backwardGaussianWithOutput (Matrix &sys, unsigned partitionPos, std::ostream &out) {
    for (unsigned i=sys.rows(); i > 0; --i) {
        if (sys[i][i] != 0) {
            backEliminate(i,sys);
        }
        out << sys.strAugmentedMatrix(partitionPos) <<std::endl;
    }
}

void GaussJordan(Matrix & sys) {
    forwardGaussian(sys);
    backwardGaussian(sys);
}

void GaussJordanWithOutput (Matrix &sys, unsigned partitionPos, std::ostream &out) {
    forwardGaussianWithOutput(sys, partitionPos, out);
    backwardGaussianWithOutput(sys, partitionPos, out);
}

Matrix operator * (Matrix const & m, Matrix const & n) {
    if (m.cols() != n.rows())
      throw std::string("dimension error");
    Matrix r(m.rows(), n.cols());
    for (unsigned i=1; i<=r.rows(); ++i)
      for (unsigned j=1; j <=r.cols(); ++j)
        for (unsigned k=1; k <=m.cols(); ++k)
          r[i][j] += m[i][k]*n[k][j];
    return r;
}

#endif // MATRIX_H_INCLUDED
