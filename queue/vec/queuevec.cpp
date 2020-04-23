
#include <stdexcept>

/* ************************************************************************** */

// ...



/** CONSTRUCTOR QUEUEVEC **/
//COSTRUTTORE DI DEFAULT
template <typename Data>
QueueVec<Data>:: QueueVec():Vector<Data>(2){};

template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec& queue):Vector<Data>(queue){
    this->head = queue.head;
    this->tail = queue.head;
}

template <typename Data>
QueueVec<Data>::QueueVec(QueueVec&& queue) noexcept:Vector<Data>(queue){
    std::swap(this->head,queue.head);
    std::swap(this->tail,queue.tail);
}


/**FUNZIONI DI ESPANSIONE/RIDUZIONE DELLA CODA **/

template <typename Data>
void QueueVec<Data>::Expand() {

}

template <typename Data>
void QueueVec<Data>::Reduce() {

}

/** ASSIGNMENT QUEUEVEC **/

template <typename Data>
QueueVec<Data>& QueueVec<Data>:: operator=(const QueueVec& queue){
        this->Clear();
        Vector<Data>::operator=(queue);
        this->head = queue.head;
        this->tail = queue.head;
        return *this;
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>:: operator=(QueueVec&& queue){
    this->Clear();
    Vector<Data>::operator=(std::move(queue));
    std::swap(this->head,queue.head);
    std::swap(this->tail,queue.tail);
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


/**OPERAZIONI DI QUEUEVEC**/

//FUNZIONE DI ENQUEUE (COPY)
template <typename Data>
void  QueueVec<Data>::Enqueue(Data& item){

    this->elem[tail] = item;
    tail = (tail + 1)%(this->size);

}

//FUNZIONE DI ENQUEUE (MOVE)
template <typename Data>
void  QueueVec<Data>::Enqueue(Data&& item){

    this->elem[tail] = std::move(item);
    tail = (tail + 1)%(this->size);

}

//FUNZIONE DI DEQUEUE
template <typename Data>
void  QueueVec<Data>::Dequeue(){
    this->elem[this->head] = Data();
    this->head = (this->head+1)%this->size;
}

//FUNZIONE DI HEAD
template <typename Data>
Data QueueVec<Data>::Head() const {
    return this->elem[this->head];
}

//FUNZIONE DI HEADNDEQUEUE
template <typename Data>
Data QueueVec<Data>::HeadNDequeue(){
return 0;
}


/**OPERAZIONI OVERRIDE DA CONTAINER**/


template <typename Data>
bool QueueVec<Data>::Empty() const noexcept {
return (this->size==0);
}

template <typename Data>
int QueueVec<Data>::Size() const noexcept {
return (this->tail - this->head);
}