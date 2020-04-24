
#include <stdexcept>

/* ************************************************************************** */

template <typename Data>
void QueueVec<Data>::Print() {
    Vector<Data>::print();
}
// ...
/** FUNZIONI ACCESSORIE **/

template <typename Data>
Data QueueVec<Data>:: Capacity() const noexcept {
    return Vector<Data>::Size();
}

template <typename Data>
void QueueVec<Data>:: Ordinate(){
    if(this->tail < this ->head){
        QueueVec<Data> vectemp = *this;
        int i = this->head;
        int j=0;
        while( (i +1)%this->size != this->tail){
            vectemp.elem[j] = this->elem[i];
            i = (i+1)%this->size;
            j++;
        }
        *this = std::move(vectemp);

        std::cout<<"STRUTTURA ORDINATA";
    }
}


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
    Vector<Data>::Resize(this->size*2);
}

template <typename Data>
void QueueVec<Data>::Reduce() {
    Vector<Data>::Resize(this->size/2);
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

    if(this->tail !=  0) {
        if (abs(this->tail - this->head) == this->size / 2) Expand();
        else if (abs(this->tail - this->head) == this->size / 4) Reduce();
    }
    this->elem[tail] = item;
    tail = (tail + 1)%(this->size);

    Ordinate();
}

//FUNZIONE DI ENQUEUE (MOVE)
template <typename Data>
void  QueueVec<Data>::Enqueue(Data&& item){
    if(this->tail != 0) {
        if (abs(this->tail - this->head) == this->size / 4) Reduce();
        else if (abs(this->tail - this->head) == this->size / 2) Expand();
    }
    this->elem[tail] = std::move(item);
    tail = (tail + 1)%(this->size);

    Ordinate();
}

//FUNZIONE DI DEQUEUE
template <typename Data>
void  QueueVec<Data>::Dequeue(){

    this->elem[this->head] = Data();
    this->head = (this->head+1)%this->size;

    if (abs(this->tail - this->head) == this->size / 4) Reduce();
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