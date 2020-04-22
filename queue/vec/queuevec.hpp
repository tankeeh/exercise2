
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
  int head = 0;
  int tail = 0;
  // ...

public:

  // Default constructor
  QueueVec() = default;

  // Copy constructor
  QueueVec(const QueueVec& queue);

  // Move constructor
  QueueVec(QueueVec&& queue)noexcept ;


    /* ************************************************************************ */

  // Destructor
  ~QueueVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  QueueVec& operator=(const QueueVec&);

  // Move assignment
  QueueVec& operator=(QueueVec&&);


    /* ************************************************************************ */

  // Comparison operators
  bool operator==(QueueVec&) ;
  bool operator!=(QueueVec&) ;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  Data Head() const override; // Override Queue member (might throw std::length_error)
  void Dequeue() override; // Override Queue member (might throw std::length_error)
  Data HeadNDequeue() override; // Override Queue member (might throw std::length_error)
  void Enqueue(Data& item); // Override Queue member
  void Enqueue(Data&& item); // Override Queue member

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  using Container::Empty; // Override Container member

  using Container::Size; // Override Container member

  using Container::Clear;  // Override Container member

protected:

  void Expand(); // Accessory function
  void Reduce(); // Accessory function

};

/* ************************************************************************** */

#include "queuevec.cpp"

}

#endif
