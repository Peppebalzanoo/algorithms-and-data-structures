
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

#include "../iterator/iterator.hpp"

#include "../queue/lst/queuelst.hpp"
#include "../stack/lst/stacklst.hpp"


/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

// Must extend InOrder/BreadthMappableContainer<Data> and InOrder/BreadthFoldableContainer<Data>
template <typename Data>
class BinaryTree :  virtual public InOrderMappableContainer<Data>,
                    virtual public BreadthMappableContainer<Data>,
                    virtual public InOrderFoldableContainer<Data>,
                    virtual public BreadthFoldableContainer<Data> {

private:

  // ...

protected:

  using BreadthMappableContainer<Data>::size;

  // ...

public:

  struct Node {

  private:

    // ...

  protected:

    // ...
    // Comparison operators
    bool operator==(const Node&) const noexcept; // Comparison of abstract types is possible, but should not be visible.
    inline bool operator!=(const Node&) const noexcept; // Comparison of abstract types is possible, but should not be visible.

  public:

    friend class BinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    virtual ~Node() = default;

    /* ********************************************************************** */

    // Copy assignment
    Node& operator=(const Node&) = delete; // Copy assignment of abstract types should not be possible.

    // Move assignment
    Node& operator=(Node&&)noexcept = delete; // Move assignment of abstract types should not be possible.

    /* ********************************************************************** */

    // Comparison operators

    /* ********************************************************************** */

    // Specific member functions

    virtual Data& Element() noexcept = 0; // Mutable access to the element (concrete function should not throw exceptions)

    virtual const Data& Element() const noexcept = 0; // Immutable access to the element (concrete function should not throw exceptions)

    bool IsLeaf() const noexcept; // (concrete function should not throw exceptions)

    virtual bool HasLeftChild() const noexcept = 0; // (concrete function should not throw exceptions)
    virtual bool HasRightChild() const noexcept = 0; // (concrete function should not throw exceptions)


    virtual Node& LeftChild() const  = 0; // (concrete function must throw std::out_of_range when not existent)
    virtual Node& RightChild() const = 0; // (concrete function must throw std::out_of_range when not existent)

  };

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTree() = default;

  /* ************************************************************************ */

  // Copy assignment
  BinaryTree& operator=(const BinaryTree&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  BinaryTree& operator=(BinaryTree&&)noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.
  inline bool operator!=(const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual Node& Root() const = 0; // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  void MapPreOrder(const MapFunctor, void*) override; // Override MappableContainer member
  void MapPostOrder(const MapFunctor, void*) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  void FoldPreOrder(const FoldFunctor, const void*, void*) const override; // Override FoldableContainer member
  void FoldPostOrder(const FoldFunctor, const void*, void*) const override; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from InOrderMappableContainer)

  void MapInOrder(const MapFunctor, void*) override; // Override InOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from InOrderFoldableContainer)

  void FoldInOrder(const FoldFunctor, const void*, void*) const override; // Override InOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthMappableContainer)

  void MapBreadth(const MapFunctor, void*)override; // Override BreadthMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthFoldableContainer)

  void FoldBreadth(const FoldFunctor, const void*, void*) const override; // Override BreadthFoldableContainer member

protected:

  // Auxiliary member functions (for MappableContainer)

  void MapPreOrder(const MapFunctor, void*, Node*); // Accessory function executing from one node of the tree
  void MapPostOrder(const MapFunctor, void*, Node*); // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for FoldableContainer)

  void FoldPreOrder(const FoldFunctor, const void*, void*, Node*) const; // Accessory function executing from one node of the tree
  void FoldPostOrder(const FoldFunctor, const void*, void*, Node*) const; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for InOrderMappableContainer)

  void MapInOrder(const MapFunctor, void*, Node*); // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for InOrderFoldableContainer)

  void FoldInOrder(const FoldFunctor, const void*, void*, Node*) const; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for BreadthMappableContainer)

  void MapBreadth(const MapFunctor, void*, Node*); // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for BreadthFoldableContainer)

  void FoldBreadth(const FoldFunctor, const void*, void*, Node*) const; // Accessory function executing from one node of the tree

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator : virtual public ForwardIterator<Data> { // Must extend ForwardIterator<Data>

private:

  // ...

protected:

  typename BinaryTree<Data>::Node* curr = nullptr;
  StackLst<typename BinaryTree<Data>::Node*> stack;

public:

  // Specific constructors
  BTPreOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPreOrderIterator(const BTPreOrderIterator&);

  // Move constructor
  BTPreOrderIterator(BTPreOrderIterator&&)noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BTPreOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPreOrderIterator& operator=(const BTPreOrderIterator&);

  // Move assignment
  BTPreOrderIterator& operator=(BTPreOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPreOrderIterator&)const noexcept;
  inline bool operator!=(const BTPreOrderIterator&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  Data& operator*() const; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTPreOrderIterator& operator++(); // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator : virtual public ForwardIterator<Data> { // Must extend ForwardIterator<Data>

private:

  // ...

protected:

  // ...
  typename BinaryTree<Data>::Node* curr = nullptr;
  StackLst<typename BinaryTree<Data>::Node*> stack;

  // Auxiliary member functions

 typename BinaryTree<Data>::Node& mostLeafSx(typename BinaryTree<Data>::Node&);



public:

  // Specific constructors
  BTPostOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPostOrderIterator(const BTPostOrderIterator&);

  // Move constructor
  BTPostOrderIterator(BTPostOrderIterator&&)noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BTPostOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTPostOrderIterator& operator=(const BTPostOrderIterator&);

  // Move assignment
  BTPostOrderIterator& operator=(BTPostOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPostOrderIterator&) const noexcept;
  inline bool operator!=(const BTPostOrderIterator&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  Data& operator*()const; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTPostOrderIterator& operator++(); // (throw std::out_of_range when terminated)


};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator : virtual public ForwardIterator<Data> { // Must extend ForwardIterator<Data>

private:

  // ...

protected:

  // ...
  typename BinaryTree<Data>::Node* curr = nullptr;
  StackLst<typename BinaryTree<Data>::Node*> stack;

  // Auxiliary member functions
  typename BinaryTree<Data>::Node& mostLeftNode(typename BinaryTree<Data>::Node&);



public:

  // Specific constructors
  BTInOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTInOrderIterator(const BTInOrderIterator&);

  // Move constructor
  BTInOrderIterator(BTInOrderIterator&&)noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BTInOrderIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTInOrderIterator& operator=(const BTInOrderIterator&);

  // Move assignment
  BTInOrderIterator& operator=(BTInOrderIterator&&)noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTInOrderIterator<Data>&) const noexcept;
  inline bool operator!=(const BTInOrderIterator<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  Data& operator*()const; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTInOrderIterator<Data>& operator++(); // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator : virtual public ForwardIterator<Data>{ // Must extend ForwardIterator<Data>

private:

  // ...

protected:

  // ...
  typename BinaryTree<Data>::Node* curr = nullptr;
  QueueLst<typename BinaryTree<Data>::Node*> queue;

public:

  // Specific constructors
  BTBreadthIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTBreadthIterator(const BTBreadthIterator&);

  // Move constructor
  BTBreadthIterator(BTBreadthIterator&&)noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BTBreadthIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  BTBreadthIterator& operator=(const BTBreadthIterator<Data>&);

  // Move assignment
  BTBreadthIterator& operator=(BTBreadthIterator<Data>&&)noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTBreadthIterator<Data>&) const noexcept;
  inline bool operator!=(const BTBreadthIterator<Data>&)const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  Data& operator*()const; // (throw std::out_of_range when terminated)

  bool Terminated() const noexcept; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  BTBreadthIterator& operator++(); // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
