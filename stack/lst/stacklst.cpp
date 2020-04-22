
#include <stdexcept>

/* ************************************************************************** */

/* ************************************************************************** */

// ...
/** COSTRUTTORI DI STACKLST **/

//COPY CONSTRUCTOR DI STACKLST
template <typename Data>
 StackLst<Data>::StackLst(const StackLst& stack):List<Data>(stack){}  //initializer list serve per fare operazioni prima di chiamare una funzione
                                                                      //ma solo con i costruttori


//MOVE CONSTRUCTOR DI STACKLST
template <typename Data>
StackLst<Data>::StackLst(StackLst&& stack):List<Data>(std::move(stack)){}  //initializer list serve per fare operazioni prima di chiamare una funzione
                                                                           //ma solo con i costruttori


/** ASSIGNMENT DI STACKLST **/

//COPY ASSIGNMENT DI STACKLST
template <typename Data>
StackLst <Data> & StackLst<Data>:: operator=(const StackLst& stack){
     List<Data>::operator=(stack);
     return *this;
}

//MOVE ASSIGNMENT DI STACKLST
template <typename Data>
StackLst<Data>& StackLst<Data>:: operator=(StackLst&& stack){
    List<Data>::operator=(std::move(stack));
    return *this;
}



//FUNZIONE DI PUSH NELLO STACK (COPY)
template  <typename Data>
void StackLst<Data>::Push(Data& item) noexcept {
    this->InsertAtFront(item);
}



//FUNZIONE DI PUSH NELLO STACK (MOVE)
template  <typename Data>
void StackLst<Data>::Push(Data&& item) noexcept {
    this->InsertAtFront(std::move(item));
}



//FUNZIONE DI POP DALLO STACK
template  <typename Data>
void StackLst<Data>::Pop(){
    this->RemoveFromFront();
}


//FUNZIONE DI TOP DALLO STACK
template  <typename Data>
Data StackLst<Data>::Top()const{
    return this->Front();
}

//FUNZIONE DI TOPNPOP DALLO STACK
template  <typename Data>
Data StackLst<Data>::TopNPop(){
    return this->FrontNRemove();
}

//OPERATOR DI UGUAGLIANZA TRA STACK
template <typename Data>
bool StackLst<Data>::operator==(StackLst& stack){
    return List<Data>::operator==(stack);
}

//OPERATOR DI DISUGUAGLIANZA TRA STACK
template <typename Data>
bool StackLst<Data>::operator!=(StackLst& stack){
    return List<Data>::operator!=(stack);
}

// ...
