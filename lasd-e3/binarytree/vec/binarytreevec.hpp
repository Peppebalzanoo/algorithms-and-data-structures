
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public BinaryTree<Data> { // Must extend BinaryTree<Data>

private:

  // ...

protected:

  using BinaryTree<Data>::size;

  // ...

  struct NodeVec : virtual public BinaryTree<Data>::Node{ // Must extend Node

  private:

    // ...

  protected:

      // ...

  public:

      Data info;
      long index = -1;
      Vector<NodeVec*>* puntvec = nullptr;


      /* ********************************************************************** */

      NodeVec() = default;

      // Specific constructor
      NodeVec(const Data&, long ind, Vector<NodeVec*>*);

    /* ********************************************************************** */

      // Copy constructor
      NodeVec(const NodeVec&);

      // Move constructor
      NodeVec(NodeVec&&)noexcept;

    /* ********************************************************************** */

      // Destructor
      ~NodeVec() = default;

    /* ********************************************************************** */

      // Copy assignment
      NodeVec& operator=(const NodeVec&); // Copy assignment of abstract types should not be possible.

      // Move assignment
      NodeVec& operator=(NodeVec&&)noexcept; // Move assignment of abstract types should not be possible.

    /* ********************************************************************** */

      // Comparison operators
      // bool operator==(const NodeLnk&)const noexcept;
      // inline bool operator!=(const NodeLnk&)const noexcept;

    /* ********************************************************************** */

      // Specific member functions

      Data& Element() noexcept override; // Mutable access to the element (concrete function should not throw exceptions)
      const Data& Element() const noexcept override; // Immutable access to the element (concrete function should not throw exceptions)

      //bool IsLeaf() const noexcept override;

      bool HasLeftChild() const noexcept override; // (concrete function should not throw exceptions)
      bool HasRightChild() const noexcept override; // (concrete function should not throw exceptions)

      typename BinaryTree<Data>::Node& LeftChild() const override; // (concrete function must throw std::out_of_range when not existent)
      typename BinaryTree<Data>::Node& RightChild() const override; // (concrete function must throw std::out_of_range when not existent)



     /* ********************************************************************** */
  };

    Vector<NodeVec*>*vec = nullptr;

public:

  // Default constructor
  BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeVec(const LinearContainer<Data>&); // A binary tree obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeVec(const BinaryTreeVec&);

  // Move constructor
  BinaryTreeVec(BinaryTreeVec&&)noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeVec& operator=(const BinaryTreeVec&);

  // Move assignment
  BinaryTreeVec& operator=(BinaryTreeVec&&)noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeVec&)const noexcept;
  inline bool operator!=(const BinaryTreeVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  NodeVec& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthMappableContainer)
  using typename BreadthMappableContainer<Data>::MapFunctor;
  void MapBreadth(const MapFunctor, void*)override;


  // Specific member functions (inherited from BreadthFoldableContainer)
  using typename BreadthFoldableContainer<Data>::FoldFunctor;
  void FoldBreadth(const FoldFunctor, const void*, void*) const override;

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
