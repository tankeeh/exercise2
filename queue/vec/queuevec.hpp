
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec: virtual public Queue<Data>, virtual protected Vector<Data> { // Should extend Queue<Data> and Vector<Data>

private:

  // ...

protected:

  // using Vector<Data>::???;
  using Vector<Data>::size;
  using Vector<Data>::elem;

  // ...

public:

  // Default constructor
  QueueVec() = default;

  // Copy constructor
  // QueueVec(argument);

  // Move constructor
  // QueueVec(argument);

  /* ************************************************************************ */

  // Destructor
  // ~QueueVec() specifier;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);

  // Move assignment
  // type operator=(argument);

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  // type Head() specifiers; // Override Queue member (might throw std::length_error)
  // type Dequeue() specifiers; // Override Queue member (might throw std::length_error)
  // type HeadNDequeue() specifiers; // Override Queue member (might throw std::length_error)
  // type Enqueue(argument) specifiers; // Override Queue member
  // type Enqueue(argument) specifiers; // Override Queue member

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Empty() specifiers; // Override Container member

  // type Size() specifiers; // Override Container member

  // type Clear() specifiers; // Override Container member

protected:

  // type Expand() specifiers; // Accessory function
  // type Reduce() specifiers; // Accessory function

};

/* ************************************************************************** */

#include "queuevec.cpp"

}

#endif
