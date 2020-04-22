
#include <stdexcept>

/* ************************************************************************** */
/** COSTRUTTORI DI QUEUELST **/

//COPY CONSTRUCTOR DI QUEUELST
template <typename Data>
QueueLst<Data>::QueueLst(const QueueLst& queue):List<Data>(queue){}  //initializer list serve per fare operazioni prima di chiamare una funzione
//ma solo con i costruttori


//MOVE CONSTRUCTOR DI QUEUELST
template <typename Data>
QueueLst<Data>::QueueLst(QueueLst&& queue):List<Data>(std::move(queue)){}  //initializer list serve per fare operazioni prima di chiamare una funzione
//ma solo con i costruttori


/** ASSIGNMENT DI QUEUELST **/

//COPY ASSIGNMENT DI QUEUELST
template <typename Data>
QueueLst <Data> & QueueLst<Data>:: operator=(const QueueLst& queue){
    List<Data>::operator=(queue);
    return *this;
}

//MOVE ASSIGNMENT DI QUEUELST
template <typename Data>
QueueLst<Data>& QueueLst<Data>:: operator=(QueueLst&& queue){
    List<Data>::operator=(std::move(queue));
    return *this;
}



//FUNZIONE DI ENQUEUE NELLA QUEUE (COPY)
template  <typename Data>
void QueueLst<Data>::Enqueue(Data& item) noexcept {
    this->InsertAtBack(item);
}



//FUNZIONE DI ENQUEUE NELLA QUEUE (MOVE)
template  <typename Data>
void QueueLst<Data>::Enqueue(Data&& item) noexcept {
    this->InsertAtBack(std::move(item));
}



//FUNZIONE DI DEQUEUE DALLA QUEUE
template  <typename Data>
void QueueLst<Data>::Dequeue(){
    this->RemoveFromFront();
}


//FUNZIONE DI HEAD DELLA QUEUE
template  <typename Data>
Data QueueLst<Data>::Head()const{
    return this->Front();
}

//FUNZIONE DI HEADNDEQUEUE DELLA QUEUE
template  <typename Data>
Data QueueLst<Data>::HeadNDequeue(){
    return this->FrontNRemove();
}

//OPERATOR DI UGUAGLIANZA TRA QUEUE
template <typename Data>
bool QueueLst<Data>::operator==(QueueLst& queue){
    return List<Data>::operator==(queue);
}

//OPERATOR DI DISUGUAGLIANZA TRA QUEUE
template <typename Data>
bool QueueLst<Data>::operator!=(QueueLst& queue){
    return List<Data>::operator!=(queue);
}

// ...
// ...
