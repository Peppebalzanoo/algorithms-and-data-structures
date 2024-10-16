
#ifndef ITERATOR_HPP
#define ITERATOR_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Iterator {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~Iterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  Iterator& operator=(const Iterator&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  Iterator& operator=(Iterator&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Iterator&) const noexcept = delete; // Comparison of abstract types might not be possible.
  inline bool operator!=(const Iterator&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual Data& operator*() const = 0; // (concrete function must throw std::out_of_range when terminated)

  virtual bool Terminated() const noexcept = 0; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class ForwardIterator : virtual public Iterator<Data> { // Must extend Iterator

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~ForwardIterator() = default;

  /* ************************************************************************ */

  // Copy assignment
  ForwardIterator& operator=(const ForwardIterator&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  ForwardIterator& operator=(ForwardIterator&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const ForwardIterator&)const noexcept = delete; // Comparison of abstract types might not be possible.
  inline bool operator!=(const ForwardIterator&)const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual ForwardIterator& operator++() = 0; // (concrete function must throw std::out_of_range when terminated) //*** CHECK THIS DIFFERENCE ***

};

/* ************************************************************************** */

template <typename Data>
class BackwardIterator { // Must extend Iterator

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BackwardIterator() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // type operator--() specifiers; // (concrete function must throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BidirectionalIterator { // Must extend ForwardIterator and BackwardIterator

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BidirectionalIterator() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // type Terminated() specifiers; // Override Iterator member

  // type ForwardTerminated() specifiers; // (concrete function should not throw exceptions)

  // type BackwardTerminated() specifiers; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

}

#endif
