
#ifndef QUEUE_HPP
#define QUEUE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Queue : virtual public Container {

private:

  // ...

protected:

  // ...

public:

  // Destructor
   ~Queue() = default;

  /* ************************************************************************ */

  // Copy assignment
  Queue &operator=(Queue& ) = delete;
    // Copy assignment of abstract types should not be possible.

  // Move assignment
  Queue &operator=(Queue&& ) = delete;
// Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(Queue&) = delete; // Comparison of abstract types might not be possible.
  bool operator!=(Queue&) = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual Data Head() const = 0; // (might throw std::length_error)
  virtual void Dequeue() = 0; // (might throw std::length_error)
  virtual Data HeadNDequeue() = 0; // (might throw std::length_error)
  virtual void Enqueue(Data&) = 0 ; // Copy of the value
  virtual void Enqueue(Data&&) = 0 ;// Move of the value


};

/* ************************************************************************** */

}

#endif
