
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
StackVec<Data>::StackVec(const StackVec& stack):Vector<Data>(stack){}

template <typename Data>
StackVec<Data>::StackVec(StackVec&& stack) noexcept:Vector<Data>(std::move(stack)){}


template <typename Data>
StackVec<Data>::StackVec(unsigned int newsize):Vector<Data>(newsize){
}


template <typename Data>
void StackVec<Data>::Push(Data& item) noexcept{

if (this->index - 1 >= 0){
this->elem[this->index] = item;
this->index++;
}

if(this->index = this->size){
    Expand();
} else if(this->index=this->size/4) Reduce();

}


template <typename Data>
void StackVec<Data>::Push(Data&& item) noexcept{

    if (this->elem!= nullptr){
        this->elem[this->index] = std::move(item);
        this->index++;
    }

    if(this->index = this->size){
        Expand();
    } else if(this->index=this->size/4) Reduce();
}


template <typename Data>
void StackVec<Data>::Pop() {
this->elem[index -1] = Data();
    this->index--;

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



