
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST : virtual public BinaryTreeLnk<Data>{ // Must extend BinaryTreeLnk<Data>

private:

  // ...

protected:

  using BinaryTreeLnk<Data>::size;
  using BinaryTreeLnk<Data>::root;
  // ...

public:

  // Default constructor
  BST() = default;

  /* ************************************************************************ */

  // Specific constructors
  BST(const LinearContainer<Data>&); // A bst obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  BST(const BST&);

  // Move constructor
  BST(BST&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BST() = default;

  /* ************************************************************************ */

  // Copy assignment
  BST& operator=(const BST&);

  // Move assignment
  BST& operator=(BST&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BST&) const noexcept;
  inline bool operator!=(const BST&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  void Insert(const Data&)noexcept; // Copy of the value
  void Insert(Data&&)noexcept; // Move of the value

  void Remove(const Data&)noexcept;

  const Data& Min()const; // (concrete function must throw std::length_error when empty)
  Data MinNRemove(); // (concrete function must throw std::length_error when empty)
  void RemoveMin(); // (concrete function must throw std::length_error when empty)

  const Data& Max()const; // (concrete function must throw std::length_error when empty)
  Data MaxNRemove(); // (concrete function must throw std::length_error when empty)
  void RemoveMax(); // (concrete function must throw std::length_error when empty)

  const Data& Predecessor(const Data&)const; // (concrete function must throw std::length_error when empty)
  Data PredecessorNRemove(const Data&); // (concrete function must throw std::length_error when empty)
  void RemovePredecessor(const Data&); // (concrete function must throw std::length_error when empty)

  const Data& Successor(const Data&)const; // (concrete function must throw std::length_error when empty)
  Data SuccessorNRemove(const Data&); // (concrete function must throw std::length_error when empty)
  void RemoveSuccessor(const Data&); // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  bool Exists(const Data&)const noexcept override; // Override TestableContainer member

protected:

  // Auxiliary member functions

  Data DataNDelete(typename BST<Data>::NodeLnk*);

  typename BST<Data>::NodeLnk* Detach(typename BST<Data>::NodeLnk*&)noexcept;

  typename BST<Data>::NodeLnk* DetachMin(typename BST<Data>::NodeLnk*&)noexcept;
  typename BST<Data>::NodeLnk* DetachMax(typename BST<Data>::NodeLnk*&)noexcept;

  typename BST<Data>::NodeLnk* SkipOnLeft(typename BST<Data>::NodeLnk*&)noexcept;
  typename BST<Data>::NodeLnk* SkipOnRight(typename BST<Data>::NodeLnk*&)noexcept;



  typename BST<Data>::NodeLnk*& FindPointerToMin(typename BST<Data>::NodeLnk*&)noexcept;
  typename BST<Data>::NodeLnk* const& FindPointerToMin(typename BST<Data>::NodeLnk* const&)const noexcept;

  typename BST<Data>::NodeLnk*& FindPointerToMax(typename BST<Data>::NodeLnk*&) noexcept;
  typename BST<Data>::NodeLnk* const& FindPointerToMax(typename BST<Data>::NodeLnk* const&)const noexcept;

  typename BST<Data>::NodeLnk*& FindPointerTo(typename BST<Data>::NodeLnk*&, const Data&)noexcept;
  typename BST<Data>::NodeLnk* const& FindPointerTo(typename BST<Data>::NodeLnk* const&, const Data&)const noexcept;



  typename BST<Data>::NodeLnk** FindPointerToPredecessor(const Data&)noexcept;
  typename BST<Data>::NodeLnk* const* FindPointerToPredecessor(const Data&) const noexcept;


  typename BST<Data>::NodeLnk** FindPointerToSuccessor(const Data&)noexcept;
  typename BST<Data>::NodeLnk* const* FindPointerToSuccessor(const Data&)const noexcept;


};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
