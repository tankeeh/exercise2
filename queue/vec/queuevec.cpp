
#include <stdexcept>

/* ************************************************************************** */

// ...


/** CONSTRUCTOR QUEUEVEC **/

template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec& queue):Vector<Data>(queue){}

template <typename Data>
QueueVec<Data>::QueueVec(QueueVec&& queue) noexcept:Vector<Data>(queue){}


/** ASSIGNMENT QUEUEVEC **/

template <typename Data>
QueueVec<Data>& QueueVec<Data>:: operator=(const QueueVec& queue){
        Vector<Data>::operator=(queue);
        return *this;
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>:: operator=(QueueVec&& queue){
    Vector<Data>::operator=(std::move(queue));
    return *this;
}


/** OPERATORI DI UGUAGLIANZA/DISUGUAGLIANZA QUEUEVEC **/


template <typename Data>
bool QueueVec<Data>:: operator==(QueueVec& queue){
    return Vector<Data>::operator==(queue);
}

template <typename Data>
bool QueueVec<Data>:: operator!=(QueueVec& queue){
    return Vector<Data>::operator!=(queue);
}



template <typename Data>
void  QueueVec<Data>::Enqueue(Data& item){

    this->elem[tail] = item;
    tail = (tail + 1)%(this->size)


}