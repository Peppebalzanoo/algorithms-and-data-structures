
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

// Must extend Stack<Data> and Vector<Data>
template <typename Data>
class StackVec : virtual public Stack<Data>,
                 virtual protected Vector<Data> {

private:

  // ...

protected:

  using Vector<Data>::size;
  using Vector<Data>::Elements;
  long currentTop = -1; //Index pointing to the Top element of the stack

public:

  // Default constructor
  StackVec();

  /* ************************************************************************ */

  // Specific constructor
  StackVec(const LinearContainer<Data>&); // A stack obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  StackVec(const StackVec&);

  // Move constructor
  StackVec(StackVec&&)noexcept;

  /* ************************************************************************ */

  // Destructor
  ~StackVec();

  /* ************************************************************************ */

  // Copy assignment
  StackVec& operator=(const StackVec&);

  // Move assignment
  StackVec& operator=(StackVec&&)noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackVec&) const noexcept;
  bool inline operator!=(const StackVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  void Push(const Data&) override; // Override Stack member (copy of the value)
  void Push(Data&&) noexcept override; // Override Stack member (move of the value)
  Data& Top() const override; // Override Stack member (must throw std::length_error when empty)
  void Pop() override; // Override Stack member (must throw std::length_error when empty)
  Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  bool Empty() const noexcept override; // Override Container member

  ulong Size() const noexcept override; // Override Container member

  void Clear() override; // Override Container member

  /* ************************************************************************** */

protected:

  // Auxiliary member functions

  void Expand();
  void Reduce();

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
