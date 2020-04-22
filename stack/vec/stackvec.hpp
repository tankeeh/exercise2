
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec: virtual public Stack<Data>, virtual protected Vector<Data> { // Should extend Stack<Data> and Vector<Data>

private:

  // ...

protected:

  // using Vector<Data>::???;
  using Vector<Data>::size;
  using Vector<Data>::elem;
  int index = 0;
  // ...

public:

  // Default constructor
  StackVec() = default;

  StackVec(unsigned int newsize);

  // Copy constructor
  StackVec( const StackVec& stack);


  // Move constructor
  StackVec(StackVec&& stack) noexcept;


    /* ************************************************************************ */

  // Destructor
  ~StackVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackVec &operator=(const StackVec& stack);


    // Move assignment
  StackVec &operator=(StackVec&& stack);


    /* ************************************************************************ */

  // Comparison operators
  bool operator==(StackVec& stack);
  bool operator!=(StackVec& stack);

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

    Data Top() const override ; // Override Stack member (might throw std::length_error)
    void Pop() override ; // Override Stack member (might throw std::length_error)
    Data TopNPop() override ; // Override Stack member (might throw std::length_error)
    void Push(Data& item) noexcept override; // Override Stack member
    void Push(Data&& item) noexcept override;

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  using Container::Empty; // Override Container member

  using Container::Size; // Override Container member

  using Container::Clear; // Override Container member

protected:

  void Expand(); // Accessory function
  void Reduce(); // Accessory function

};

/* ************************************************************************** */

#include "stackvec.cpp"

}

#endif
