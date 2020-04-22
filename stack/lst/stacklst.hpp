
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

    template <typename Data>
    class StackLst : virtual public Stack<Data>, virtual protected List<Data>{

    private:

        // ...

    protected:

        // using List<Data>::???;
        using List<Data>::size;
        using List<Data>::node;
        // ...

    public:

        // Default constructor
        StackLst() = default;

        // Copy constructor
        StackLst( const StackLst& stack);

        // Move constructor
        StackLst(StackLst&& stack);

        // StackLst(argument);

        /* ************************************************************************ */

        // Destructor
        ~StackLst() = default;

        /* ************************************************************************ */

        // Copy assignment
        StackLst &operator=(const StackLst& stack);


        // Move assignment
        StackLst &operator=(StackLst&& stack);

        /* ************************************************************************ */

        // Comparison operators
        bool operator==(StackLst& stack);
        // type operator!=(argument) specifiers;
        bool operator!=(StackLst& stack);


        /* ************************************************************************ */

        // Specific member functions (inherited from Stack)

        Data Top() const override ; // Override Stack member (might throw std::length_error)
        void Pop() override ; // Override Stack member (might throw std::length_error)
        Data TopNPop() override ; // Override Stack member (might throw std::length_error)
        void Push(Data& item) noexcept override; // Override Stack member
        void Push(Data&& item) noexcept override;

        /* ************************************************************************ */

        // Specific member functions (inherited from Container)

        using List<Data>::Clear;  // Override Container member

    };

/* ************************************************************************** */

#include "stacklst.cpp"

}

#endif