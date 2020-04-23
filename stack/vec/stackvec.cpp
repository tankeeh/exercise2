
#include <stdexcept>

/* ************************************************************************** */

// ...
/** RIDUZIONE ED ESPANSIONE DEL VETTORE**/

template <typename Data>
void StackVec<Data>:: Expand(){
    Vector<Data>::Resize(this->size*2);
}

template <typename Data>
void StackVec<Data>:: Reduce(){
    Vector<Data>::Resize(this->size/2);
}

/** CONSTRUCTORS DEL VETTORE **/
//COPY CONSTRUCTOR DELLO STACK VETTORE
template <typename Data>
StackVec<Data>::StackVec(const StackVec& stack):Vector<Data>(stack){
    this->index = stack.index;
}

template <typename Data>
StackVec<Data>::StackVec(StackVec&& stack) noexcept:Vector<Data>(std::move(stack)){
    this->index = stack.index;
}


template <typename Data>
StackVec<Data>::StackVec(unsigned int newsize):Vector<Data>(newsize){
}


template <typename Data>
void StackVec<Data>::Push(Data& item){

if (this->index - 1 >= 0){
this->elem[this->index] = item;
this->index++;
}
else throw std::length_error("La Size del vettore e' 0. Allocare memoria al vettore.");

if(this->index == this->size/2) Expand();
 else if(this->index == this->size/4) Reduce();

}


template <typename Data>
void StackVec<Data>::Push(Data&& item){

    if (this->index - 1 >= 0){
        this->elem[this->index] = std::move(item);
        this->index++;
    }
    else throw std::length_error("La Size del vettore e' 0. Allocare memoria al vettore.");

    if(this->index == this->size/2) Expand();
    else if(this->index == this->size/4) Reduce();
}


template <typename Data>
void StackVec<Data>::Pop() {
    if (this->index -1 >= 0) {

        this->elem[index - 1] = Data();
        this->index--;
        if (this->index == this->size / 4) Reduce();
    }
    else throw std::length_error("Non ci sono elementi nello stack.");
}

//FUNZIONE DI TOP DALLO STACK
template  <typename Data>
Data StackVec<Data>::Top()const{
    return this->elem[this->index -1];
}

template  <typename Data>
Data StackVec<Data>::TopNPop(){
    Data temp = Top();
    this->Pop();
    return temp;
}



/**OPERATORI DI ASSIGNMENT**/


template <typename Data>
StackVec<Data>& StackVec<Data>:: operator=(const StackVec& stack){
    Vector<Data>::operator=(stack);
    return *this;
}

template <typename Data>
StackVec<Data>& StackVec<Data>:: operator=(StackVec&& stack){
    Vector<Data>::operator=(std::move(stack));
    return *this;
}








/**OPERATORI DI CONFRONTO**/

template <typename Data>
bool StackVec<Data>:: operator==(StackVec& stack){
    return Vector<Data>::operator==(stack);
}

template <typename Data>
bool StackVec<Data>:: operator!=(StackVec& stack){
    return Vector<Data>::operator!=(stack);
}


/**OPERAZIONI OVERRIDE DA CONTAINER**/


template <typename Data>
bool StackVec<Data>::Empty() const noexcept {
    return ( this->index == 0);
}

template <typename Data>
int StackVec<Data>::Size() const noexcept {
    return this->index;
}

template <typename Data>
void StackVec<Data>::Clear(){
    Vector<Data>::Clear();
    this->index = 0;
}



