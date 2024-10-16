
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : virtual public BinaryTree<Data>{ // Must extend BinaryTree<Data>

private:

  // ...

protected:

  using BinaryTree<Data>::size;

  // ...

struct NodeLnk : virtual public BinaryTree<Data>::Node{ // Must extend Node

  private:

    // ...

  protected:

    // ...

  public:

    Data info;
    NodeLnk* left = nullptr;
    NodeLnk* right = nullptr;

    // ...

    /* ********************************************************************** */

    NodeLnk() = default;

    // Specific constructor
    NodeLnk(const Data&);

    /* ********************************************************************** */

    // Copy constructor
    NodeLnk(const NodeLnk&);

    // Move constructor
    NodeLnk(NodeLnk&&)noexcept;

    /* ********************************************************************** */

    // Destructor
    ~NodeLnk();

    /* ********************************************************************** */

    // Copy assignment
    NodeLnk& operator=(const NodeLnk&); // Copy assignment of abstract types should not be possible.

    // Move assignment
    NodeLnk& operator=(NodeLnk&&)noexcept; // Move assignment of abstract types should not be possible.

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

};

NodeLnk* root = nullptr;

public:

  // Default constructor
  BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeLnk(const LinearContainer<Data>&); // A binary tree obtained from a LinearContainer

  NodeLnk* recursiveCopyContainer(const LinearContainer<Data>& con, ulong i);

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeLnk(const BinaryTreeLnk&);

  NodeLnk* recursiveCopyConstructor(const NodeLnk* node_tocopy);



  // Move constructor
  BinaryTreeLnk(BinaryTreeLnk&&)noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BinaryTreeLnk();


  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeLnk& operator=(const BinaryTreeLnk&);

  // Move assignment
  BinaryTreeLnk& operator=(BinaryTreeLnk&&)noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeLnk&) const noexcept;
  inline bool operator!=(const BinaryTreeLnk&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  NodeLnk& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
