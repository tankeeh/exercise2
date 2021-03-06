#ifndef STACK_HPP
#define STACK_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */
//La classe stack funge da interfaccia per il tipo di struttura che invece la estenderà
//e ne implementerà i metodi

    template <typename Data>
    class Stack: virtual public Container {

    private:

        // ...

    protected:

        // ...

    public:

        // Destructor
        ~Stack() = default;

        /* ************************************************************************ */

        // Copy assignment
        Stack &operator=(Stack& ) = delete;
        // type operator=(argument); // Copy assignment of abstract types should not be possible.

        // Move assignment
        Stack &operator=(Stack&& ) = delete;
        // type operator=(argument); // Move assignment of abstract types should not be possible.

        /* ************************************************************************ */

        // Comparison operators
        // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
        bool operator==(Stack&) = delete;
        // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.
        bool operator!=(Stack&) = delete;

        /* ************************************************************************ */

        // Specific member functions

        virtual Data Top() const = 0; // (might throw std::length_error)
        virtual void Pop() = 0; // (might throw std::length_error)
        virtual Data TopNPop() = 0; // (might throw std::length_error)

        virtual void Push(Data&) = 0 ; // Copy of the value
        virtual void Push(Data&&) = 0 ;// Move of the value

    };

/* ************************************************************************** */

}

#endif
