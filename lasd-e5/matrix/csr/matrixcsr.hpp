
#ifndef MATRIXCSR_HPP
#define MATRIXCSR_HPP

/* ************************************************************************** */

#include "../matrix.hpp"

#include "../../list/list.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */
// Must extend Matrix<Data>
template <typename Data>
class MatrixCSR : virtual public Matrix<Data>, virtual protected List<std::pair<Data,ulong>>{

private:

  // ...

protected:

  using Matrix<Data>::rownum;
  using Matrix<Data>::colnum;
  using Matrix<Data>::size;

  using typename List<std::pair<Data,ulong>>::Node;
  using List<std::pair<Data,ulong>>::head;
  using List<std::pair<Data,ulong>>::tail;

  Vector<Node**>vectorRows{1};

public:

  // Default constructor
  MatrixCSR();

  /* ************************************************************************ */

  // Specific constructors
  MatrixCSR(ulong, ulong); // A matrix of some specified dimension

  /* ************************************************************************ */

  // Copy constructor
  MatrixCSR(const MatrixCSR&);

  // Move constructor
  MatrixCSR(MatrixCSR&&)noexcept;

  /* ************************************************************************ */

  // Destructor
  ~MatrixCSR();

  /* ************************************************************************ */

  // Copy assignment
  MatrixCSR& operator=(const MatrixCSR&);

  // Move assignment
  MatrixCSR& operator=(MatrixCSR&&)noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MatrixCSR&)const noexcept;
  inline bool operator!=(const MatrixCSR&)const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Matrix)

  void RowResize(ulong) override; // Override Matrix member
  void ColumnResize(ulong) override; // Override Matrix member

  bool ExistsCell(ulong, ulong) const noexcept override; // Override Matrix member (should not throw exceptions)

  Data& operator()(ulong,ulong) override; // Override Matrix member (mutable access to the element; throw out_of_range when out of range)
  const Data& operator()(ulong, ulong) const override; // Override Matrix member (immutable access to the element; throw out_of_range when out of range and length_error when not present)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFunctor;
  void MapPreOrder(const MapFunctor, void*)override; // Override MappableContainer member
  void MapPostOrder(const MapFunctor, void*)override; // Override MappableContainer member


  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;
  void FoldPreOrder(const FoldFunctor, const void*, void*) const override; // Override FoldableContainer member
  void FoldPostOrder(const FoldFunctor, const void*, void*)const override; // Override FoldableContainer member

};

/* ************************************************************************** */

}

#include "matrixcsr.cpp"

#endif
