
#include "test.hpp"
#include <iostream>
#include "../stack/vec/stackvec.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../stack/lst/stacklst.hpp"



void TestQueVec(){

    lasd::QueueVec<int> coda;
    std::cout<<"CAPACITA' DEL VETTORE : "<<coda.Capacity()<<std::endl;

    coda.Enqueue(10); // in questo punto il vettore dovrebbe resizarsi a 4
    std::cout<<"CAPACITA' DEL VETTORE : "<<coda.Capacity()<<std::endl;


    coda.Enqueue(11); // in questo punto il vettore dovrebbe resizarsi a 8
    std::cout<<"CAPACITA' DEL VETTORE : "<<coda.Capacity()<<std::endl;
    std::cout<<"\n\n";
    coda.print();

    coda.Enqueue(12);
    std::cout<<"CAPACITA' DEL VETTORE : "<<coda.Capacity()<<std::endl;
    std::cout<<"\n\n";
    coda.print();
    std::cout<<"\n\n";

    coda.Enqueue(13);
    std::cout<<"CAPACITA' DEL VETTORE : "<<coda.Capacity()<<std::endl;
    coda.Enqueue(14);
    std::cout<<"\n\n";
    coda.print();
    std::cout<<"\n\n";

    std::cout<<"CAPACITA' DEL VETTORE : "<<coda.Capacity()<<std::endl;
    coda.Dequeue();
    std::cout<<"\n\n";
    coda.print();
    std::cout<<"\n\n";

    std::cout<<"CAPACITA' DEL VETTORE : "<<coda.Capacity()<<std::endl;
    coda.Dequeue();
    std::cout<<"\n\n";
    coda.print();
    std::cout<<"\n\n";

    coda.Dequeue();
    coda.Enqueue(18);
    coda.Dequeue();
    coda.Enqueue(19);
    coda.Enqueue(20);
    coda.Enqueue(21);

    std::cout<<"\n\n";
    coda.print();

    //std::cout<<coda[2];




}

void StackVecInt() {
    std::cout<<"-- STACKVEC DI INTERI --";
    char scelta = '0';
    int dim;
    std::cout<<"Inserire la grandezza dello stack : ";
    std::cin>>dim;
    lasd::StackVec<int> stack(dim);

    while (scelta != 'e') {
        std::cout << "Che operazione vuoi effettuare sulla seguente coda come vettore : \n";
        std::cout << "1. PUSH  \n";
        std::cout << "2. POP\n";
        std::cout << "3. TOPnPOP\n";
        std::cout << "4. TOP\n";
        std::cout << "5. EMPTY\n";
        std::cout << "6. SIZE\n";
        std::cout << "7. CLEAR\n";

        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** OPERAZIONE DI PUSH ** \n\n";
                int item;
                std::cout<<"Quale elemento vuoi inserire nello stack? : ";
                try {
                    std::cin >> item;
                    stack.Push(item);
                }catch (std::length_error ex){
                    std::cout<<"\n"<<ex.what()<<std::endl;
                }
                break;
            case '2':
                std::cout << " ** OPERAZIONE DI POP ** \n\n";
                stack.Pop();
                std::cout<<"Eliminato l'elemento in testa.";
                break;
            case '3':
                std::cout << " ** OPERAZIONE DI TOPnPOP ** \n\n";
                std::cout<<"La testa dello stack e' "<<stack.TopNPop()<<" ed e' stata eliminata.";
                break;
            case '4':
                std::cout << " ** OPERAZIONE DI TOP ** \n\n";
                std::cout<<"La testa dello stack e' "<<stack.Top();
                break;
            case '5':
                std::cout << " ** TEST EMPTY ** \n\n";
                if(stack.Empty() == 1)std::cout<<" Lo stack e' vuoto.";
                else std::cout<<" Lo stack contiene almeno un elemento.";
                break;
            case '6':
                std::cout << " ** TEST SIZE ** \n\n";
                std::cout<<"La size dello stack e' : "<<stack.Size();
                break;
            case '7':
                std::cout << " ** TEST CLEAR ** \n\n";
                std::cout<<"Pulizia dello stack...";
                stack.Clear();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                exit(0);

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
}
void StackVecFloat() {
    std::cout<<"-- STACKVEC DI FLOAT --";
    char scelta = '0';
    int dim;
    std::cout<<"Inserire la grandezza dello stack : ";
    std::cin>>dim;
    lasd::StackVec<float> stack(dim);

    while (scelta != 'e') {
        std::cout << "Che operazione vuoi effettuare sulla seguente coda come vettore : \n";
        std::cout << "1. PUSH  \n";
        std::cout << "2. POP\n";
        std::cout << "3. TOPnPOP\n";
        std::cout << "4. TOP\n";
        std::cout << "5. EMPTY\n";
        std::cout << "6. SIZE\n";
        std::cout << "7. CLEAR\n";

        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** OPERAZIONE DI PUSH ** \n\n";
                float item;
                std::cout<<"Quale elemento vuoi inserire nello stack? : ";
                try {
                    std::cin >> item;
                    stack.Push(item);
                }catch (std::length_error ex){
                    std::cout<<"\n"<<ex.what()<<std::endl;
                }
                break;
            case '2':
                std::cout << " ** OPERAZIONE DI POP ** \n\n";
                stack.Pop();
                std::cout<<"Eliminato l'elemento in testa.";
                break;
            case '3':
                std::cout << " ** OPERAZIONE DI TOPnPOP ** \n\n";
                std::cout<<"La testa dello stack e' "<<stack.TopNPop()<<" ed e' stata eliminata.";
                break;
            case '4':
                std::cout << " ** OPERAZIONE DI TOP ** \n\n";
                std::cout<<"La testa dello stack e' "<<stack.Top();
                break;
            case '5':
                std::cout << " ** TEST EMPTY ** \n\n";
                if(stack.Empty() == 1)std::cout<<" Lo stack e' vuoto.";
                else std::cout<<" Lo stack contiene almeno un elemento.";
                break;
            case '6':
                std::cout << " ** TEST SIZE ** \n\n";
                std::cout<<"La size dello stack e' : "<<stack.Size();
                break;
            case '7':
                std::cout << " ** TEST CLEAR ** \n\n";
                std::cout<<"Pulizia dello stack...";
                stack.Clear();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                exit(0);

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
}
void StackVecString() {
    std::cout<<"-- STACKVEC DI STRINGHE --";
    char scelta = '0';
    int dim;
    std::cout<<"Inserire la grandezza dello stack : ";
    std::cin>>dim;
    lasd::StackVec<std::string> stack(dim);

    while (scelta != 'e') {
        std::cout << "Che operazione vuoi effettuare sulla seguente coda come vettore : \n";
        std::cout << "1. PUSH  \n";
        std::cout << "2. POP\n";
        std::cout << "3. TOPnPOP\n";
        std::cout << "4. TOP\n";
        std::cout << "5. EMPTY\n";
        std::cout << "6. SIZE\n";
        std::cout << "7. CLEAR\n";

        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1': {
                std::cout << " ** OPERAZIONE DI PUSH ** \n\n";
                std::string item = "";
                std::cout << "Quale elemento vuoi inserire nello stack? : ";
                try {
                    std::cin >> item;
                    stack.Push(item);
                }catch (std::length_error ex){
                    std::cout<<"\n"<<ex.what()<<std::endl;
                }
                break;
            }
            case '2':
                std::cout << " ** OPERAZIONE DI POP ** \n\n";
                stack.Pop();
                std::cout<<"Eliminato l'elemento in testa.";
                break;
            case '3':
                std::cout << " ** OPERAZIONE DI TOPnPOP ** \n\n";
                std::cout<<"La testa dello stack e' "<<stack.TopNPop()<<" ed e' stata eliminata.";
                break;
            case '4':
                std::cout << " ** OPERAZIONE DI TOP ** \n\n";
                std::cout<<"La testa dello stack e' "<<stack.Top();
                break;
            case '5':
                std::cout << " ** TEST EMPTY ** \n\n";
                if(stack.Empty() == 1)std::cout<<" Lo stack e' vuoto.";
                else std::cout<<" Lo stack contiene almeno un elemento.";
                break;
            case '6':
                std::cout << " ** TEST SIZE ** \n\n";
                std::cout<<"La size dello stack e' : "<<stack.Size()<<"\n";
                break;
            case '7':
                std::cout << " ** TEST CLEAR ** \n\n";
                std::cout<<"Pulizia dello stack...";
                stack.Clear();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                exit(0);

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
}
void StackVecDouble() {
    std::cout<<"-- STACKVEC DI DOUBLE --";
    char scelta = '0';
    int dim;
    std::cout<<"Inserire la grandezza dello stack : ";
    std::cin>>dim;
    lasd::StackVec<double> stack(dim);

    while (scelta != 'e') {
        std::cout << "Che operazione vuoi effettuare sulla seguente coda come vettore : \n";
        std::cout << "1. PUSH  \n";
        std::cout << "2. POP\n";
        std::cout << "3. TOPnPOP\n";
        std::cout << "4. TOP\n";
        std::cout << "5. EMPTY\n";
        std::cout << "6. SIZE\n";
        std::cout << "7. CLEAR\n";

        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1': {
                std::cout << " ** OPERAZIONE DI PUSH ** \n\n";
                double item;
                std::cout << "Quale elemento vuoi inserire nello stack? : ";
                try {
                    std::cin >> item;
                    stack.Push(item);
                }catch (std::length_error ex){
                    std::cout<<"\n"<<ex.what()<<std::endl;
                }
                break;
            }
            case '2':
                std::cout << " ** OPERAZIONE DI POP ** \n\n";
                stack.Pop();
                std::cout<<"Eliminato l'elemento in testa.";
                break;
            case '3':
                std::cout << " ** OPERAZIONE DI TOPnPOP ** \n\n";
                std::cout<<"La testa dello stack e' "<<stack.TopNPop()<<" ed e' stata eliminata.";
                break;
            case '4':
                std::cout << " ** OPERAZIONE DI TOP ** \n\n";
                std::cout<<"La testa dello stack e' "<<stack.Top();
                break;
            case '5':
                std::cout << " ** TEST EMPTY ** \n\n";
                if(stack.Empty() == 1)std::cout<<" Lo stack e' vuoto.";
                else std::cout<<" Lo stack contiene almeno un elemento.";
                break;
            case '6':
                std::cout << " ** TEST SIZE ** \n\n";
                std::cout<<"La size dello stack e' : "<<stack.Size();
                break;
            case '7':
                std::cout << " ** TEST CLEAR ** \n\n";
                std::cout<<"Pulizia dello stack...";
                stack.Clear();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                exit(0);

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
}

void StackListInt() {
    std::cout<<"-- STACKLIST DI INTERI --";
    char scelta = '0';

    lasd::StackLst<int> stack;

    while (scelta != 'e') {
        std::cout << "Che operazione vuoi effettuare sulla seguente coda come vettore : \n";
        std::cout << "1. PUSH  \n";
        std::cout << "2. POP\n";
        std::cout << "3. TOPnPOP\n";
        std::cout << "4. TOP\n";
        std::cout << "5. EMPTY\n";
        std::cout << "6. SIZE\n";
        std::cout << "7. CLEAR\n";

        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1': {
                std::cout << " ** OPERAZIONE DI PUSH ** \n\n";
                int item;
                std::cout << "Quale elemento vuoi inserire nello stack? : ";
                std::cin >> item;
                stack.Push(item);
                break;
            }
            case '2':
                std::cout << " ** OPERAZIONE DI POP ** \n\n";
                stack.Pop();
                std::cout<<"Eliminato l'elemento in testa.";
                break;
            case '3':
                std::cout << " ** OPERAZIONE DI TOPnPOP ** \n\n";
                std::cout<<"La testa dello stack e' "<<stack.TopNPop()<<" ed e' stata eliminata.";
                break;
            case '4':
                std::cout << " ** OPERAZIONE DI TOP ** \n\n";
                std::cout<<"La testa dello stack e' "<<stack.Top();
                break;
            case '5':
                std::cout << " ** TEST EMPTY ** \n\n";
                if(stack.Empty() == 1)std::cout<<" Lo stack e' vuoto.";
                else std::cout<<" Lo stack contiene almeno un elemento.";
                break;
            case '6':
                std::cout << " ** TEST SIZE ** \n\n";
                std::cout<<"La size dello stack e' : "<<stack.Size();
                break;
            case '7':
                std::cout << " ** TEST CLEAR ** \n\n";
                std::cout<<"Pulizia dello stack...";
                stack.Clear();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                exit(0);

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
}
void StackListFloat() {
    std::cout<<"-- STACKLIST DI FLOAT --";
    char scelta = '0';

    lasd::StackLst<float> stack;

    while (scelta != 'e') {
        std::cout << "Che operazione vuoi effettuare sulla seguente coda come vettore : \n";
        std::cout << "1. PUSH  \n";
        std::cout << "2. POP\n";
        std::cout << "3. TOPnPOP\n";
        std::cout << "4. TOP\n";
        std::cout << "5. EMPTY\n";
        std::cout << "6. SIZE\n";
        std::cout << "7. CLEAR\n";

        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1': {
                std::cout << " ** OPERAZIONE DI PUSH ** \n\n";
                float item;
                std::cout << "Quale elemento vuoi inserire nello stack? : ";
                std::cin >> item;
                stack.Push(item);
                break;
            }
            case '2':
                std::cout << " ** OPERAZIONE DI POP ** \n\n";
                stack.Pop();
                std::cout<<"Eliminato l'elemento in testa.";
                break;
            case '3':
                std::cout << " ** OPERAZIONE DI TOPnPOP ** \n\n";
                std::cout<<"La testa dello stack e' "<<stack.TopNPop()<<" ed e' stata eliminata.";
                break;
            case '4':
                std::cout << " ** OPERAZIONE DI TOP ** \n\n";
                std::cout<<"La testa dello stack e' "<<stack.Top();
                break;
            case '5':
                std::cout << " ** TEST EMPTY ** \n\n";
                if(stack.Empty() == 1)std::cout<<" Lo stack e' vuoto.";
                else std::cout<<" Lo stack contiene almeno un elemento.";
                break;
            case '6':
                std::cout << " ** TEST SIZE ** \n\n";
                std::cout<<"La size dello stack e' : "<<stack.Size();
                break;
            case '7':
                std::cout << " ** TEST CLEAR ** \n\n";
                std::cout<<"Pulizia dello stack...";
                stack.Clear();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                exit(0);

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
}
void StackListString() {
    std::cout<<"-- STACKLIST DI STRINGHE --";
    char scelta = '0';

    lasd::StackLst<std::string> stack;

    while (scelta != 'e') {
        std::cout << "Che operazione vuoi effettuare sulla seguente coda come vettore : \n";
        std::cout << "1. PUSH  \n";
        std::cout << "2. POP\n";
        std::cout << "3. TOPnPOP\n";
        std::cout << "4. TOP\n";
        std::cout << "5. EMPTY\n";
        std::cout << "6. SIZE\n";
        std::cout << "7. CLEAR\n";

        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1': {
                std::cout << " ** OPERAZIONE DI PUSH ** \n\n";
                std::string item;
                std::cout << "Quale elemento vuoi inserire nello stack? : ";
                std::cin >> item;
                stack.Push(item);
                break;
            }
            case '2':
                std::cout << " ** OPERAZIONE DI POP ** \n\n";
                stack.Pop();
                std::cout<<"Eliminato l'elemento in testa.";
                break;
            case '3':
                std::cout << " ** OPERAZIONE DI TOPnPOP ** \n\n";
                std::cout<<"La testa dello stack e' "<<stack.TopNPop()<<" ed e' stata eliminata.";
                break;
            case '4':
                std::cout << " ** OPERAZIONE DI TOP ** \n\n";
                std::cout<<"La testa dello stack e' "<<stack.Top();
                break;
            case '5':
                std::cout << " ** TEST EMPTY ** \n\n";
                if(stack.Empty() == 1)std::cout<<" Lo stack e' vuoto.";
                else std::cout<<" Lo stack contiene almeno un elemento.";
                break;
            case '6':
                std::cout << " ** TEST SIZE ** \n\n";
                std::cout<<"La size dello stack e' : "<<stack.Size();
                break;
            case '7':
                std::cout << " ** TEST CLEAR ** \n\n";
                std::cout<<"Pulizia dello stack...";
                stack.Clear();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                exit(0);

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
}
void StackListDouble() {
    std::cout<<"-- STACKLIST DI DOUBLE --";
    char scelta = '0';

    lasd::StackLst<double> stack;

    while (scelta != 'e') {
        std::cout << "Che operazione vuoi effettuare sulla seguente coda come vettore : \n";
        std::cout << "1. PUSH  \n";
        std::cout << "2. POP\n";
        std::cout << "3. TOPnPOP\n";
        std::cout << "4. TOP\n";
        std::cout << "5. EMPTY\n";
        std::cout << "6. SIZE\n";
        std::cout << "7. CLEAR\n";

        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1': {
                std::cout << " ** OPERAZIONE DI PUSH ** \n\n";
                double item;
                std::cout << "Quale elemento vuoi inserire nello stack? : ";
                std::cin >> item;
                stack.Push(item);
                break;
            }
            case '2':
                std::cout << " ** OPERAZIONE DI POP ** \n\n";
                stack.Pop();
                std::cout<<"Eliminato l'elemento in testa.";
                break;
            case '3':
                std::cout << " ** OPERAZIONE DI TOPnPOP ** \n\n";
                std::cout<<"La testa dello stack e' "<<stack.TopNPop()<<" ed e' stata eliminata.";
                break;
            case '4':
                std::cout << " ** OPERAZIONE DI TOP ** \n\n";
                std::cout<<"La testa dello stack e' "<<stack.Top();
                break;
            case '5':
                std::cout << " ** TEST EMPTY ** \n\n";
                if(stack.Empty() == 1)std::cout<<" Lo stack e' vuoto.";
                else std::cout<<" Lo stack contiene almeno un elemento.";
                break;
            case '6':
                std::cout << " ** TEST SIZE ** \n\n";
                std::cout<<"La size dello stack e' : "<<stack.Size();
                break;
            case '7':
                std::cout << " ** TEST CLEAR ** \n\n";
                std::cout<<"Pulizia dello stack...";
                stack.Clear();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                exit(0);

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
}


void StackVec() {
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Scegliere il tipo dello stack vettore: \n";
        std::cout << "1.stack di interi. \n";
        std::cout << "2.stack di float. \n";
        std::cout << "3.stack di stringhe. \n";
        std::cout << "4.stack di double. \n";


        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** STACK DI INTERI ** \n\n";
                StackVecInt();
                break;
            case '2':
                std::cout << " ** STACK DI FLOAT ** \n\n";
                StackVecFloat();
                break;
            case '3':
                std::cout << " ** STACK DI STRINGHE ** \n\n";
                StackVecString();
                break;
            case '4':
                std::cout << " ** STACK DI DOUBLE ** \n\n";
                StackVecDouble();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}
void StackList(){
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Scegliere il tipo dello stack lista: \n";
        std::cout << "1.stack di interi. \n";
        std::cout << "2.stack di float. \n";
        std::cout << "3.stack di stringhe. \n";
        std::cout << "4.stack di double. \n";


        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** STACK DI INTERI ** \n\n";
                StackListInt();
                break;
            case '2':
                std::cout << " ** STACK DI FLOAT ** \n\n";
                StackListFloat();
                break;
            case '3':
                std::cout << " ** STACK DI STRINGHE ** \n\n";
                StackListString();
                break;
            case '4':
                std::cout << " ** STACK DI DOUBLE ** \n\n";
                StackListDouble();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }

    }
}





void TestStack(){
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Vuoi testare : \n";
        std::cout << "1.stack tramite vettore. \n";
        std::cout << "2.stack tramite lista. \n";



        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** STACK DI INTERI ** \n\n";
                StackVec();
                break;
            case '2':
                std::cout << " ** STACK DI FLOAT ** \n\n";
                StackList();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        if (scelta != 'e') {
            std::cout << "\n\n Premi un tasto per continuare ...";
            std::cin.get();
        }

    }
}





/**CODE**/
/*
void QueueVecInt() {
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Che operazione vuoi effettuare sulla seguente coda come vettore : \n";
        std::cout << "1. \n";
        std::cout << "2. \n";
        std::cout << "3. \n";
        std::cout << "4. \n";

        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** CODA DI INTERI ** \n\n";
                //QueueInt();
                break;
            case '2':
                std::cout << " ** CODA DI FLOAT ** \n\n";
                //QueueFloat();
                break;
            case '3':
                std::cout << " ** CODA DI STRINGHE ** \n\n";
                //QueueString();
                break;
            case '4':
                std::cout << " ** CODA DI DOUBLE ** \n\n";
                //QueueDouble();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
    void TestCode() {
        char scelta = '0';

        while (scelta != 'e') {
            std::cout << "Vuoi testare : \n";
            std::cout << "1.coda di interi. \n";
            std::cout << "2.coda di float. \n";
            std::cout << "3.coda di stringhe. \n";
            std::cout << "4.coda di double. \n";


            std::cout << "e. per uscire \n\n\n";

            std::cin >> scelta;

            switch (scelta) {

                case '1':
                    std::cout << " ** CODA DI INTERI ** \n\n";
                    //QueueInt();
                    break;
                case '2':
                    std::cout << " ** CODA DI FLOAT ** \n\n";
                    //QueueFloat();
                    break;
                case '3':
                    std::cout << " ** CODA DI STRINGHE ** \n\n";
                    //QueueString();
                    break;
                case '4':
                    std::cout << " ** CODA DI DOUBLE ** \n\n";
                    //QueueDouble();
                    break;
                case 'e':
                    std::cout << " Program is gonna stop... \n";
                    break;

                default:
                    std::cout << " Hai inserito un codice non valido! riprovare : ";

            }
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            if (scelta != 'e') {
                std::cout << "\n\n Premi un tasto per continuare ...";
                std::cin.get();
            }

        }
    }
}
void QueueVecFloat() {
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Che operazione vuoi effettuare sulla seguente coda come vettore : \n";
        std::cout << "1. \n";
        std::cout << "2. \n";
        std::cout << "3. \n";
        std::cout << "4. \n";

        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** CODA DI INTERI ** \n\n";
                //QueueInt();
                break;
            case '2':
                std::cout << " ** CODA DI FLOAT ** \n\n";
                //QueueFloat();
                break;
            case '3':
                std::cout << " ** CODA DI STRINGHE ** \n\n";
                //QueueString();
                break;
            case '4':
                std::cout << " ** CODA DI DOUBLE ** \n\n";
                //QueueDouble();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
    void TestCode() {
        char scelta = '0';

        while (scelta != 'e') {
            std::cout << "Vuoi testare : \n";
            std::cout << "1.coda di interi. \n";
            std::cout << "2.coda di float. \n";
            std::cout << "3.coda di stringhe. \n";
            std::cout << "4.coda di double. \n";


            std::cout << "e. per uscire \n\n\n";

            std::cin >> scelta;

            switch (scelta) {

                case '1':
                    std::cout << " ** CODA DI INTERI ** \n\n";
                    //QueueInt();
                    break;
                case '2':
                    std::cout << " ** CODA DI FLOAT ** \n\n";
                    //QueueFloat();
                    break;
                case '3':
                    std::cout << " ** CODA DI STRINGHE ** \n\n";
                    //QueueString();
                    break;
                case '4':
                    std::cout << " ** CODA DI DOUBLE ** \n\n";
                    //QueueDouble();
                    break;
                case 'e':
                    std::cout << " Program is gonna stop... \n";
                    break;

                default:
                    std::cout << " Hai inserito un codice non valido! riprovare : ";

            }
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            if (scelta != 'e') {
                std::cout << "\n\n Premi un tasto per continuare ...";
                std::cin.get();
            }

        }
    }
}
void QueueVecString() {
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Che operazione vuoi effettuare sulla seguente coda come vettore : \n";
        std::cout << "1. \n";
        std::cout << "2. \n";
        std::cout << "3. \n";
        std::cout << "4. \n";

        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** CODA DI INTERI ** \n\n";
                //QueueInt();
                break;
            case '2':
                std::cout << " ** CODA DI FLOAT ** \n\n";
                //QueueFloat();
                break;
            case '3':
                std::cout << " ** CODA DI STRINGHE ** \n\n";
                //QueueString();
                break;
            case '4':
                std::cout << " ** CODA DI DOUBLE ** \n\n";
                //QueueDouble();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
    void TestCode() {
        char scelta = '0';

        while (scelta != 'e') {
            std::cout << "Vuoi testare : \n";
            std::cout << "1.coda di interi. \n";
            std::cout << "2.coda di float. \n";
            std::cout << "3.coda di stringhe. \n";
            std::cout << "4.coda di double. \n";


            std::cout << "e. per uscire \n\n\n";

            std::cin >> scelta;

            switch (scelta) {

                case '1':
                    std::cout << " ** CODA DI INTERI ** \n\n";
                    //QueueInt();
                    break;
                case '2':
                    std::cout << " ** CODA DI FLOAT ** \n\n";
                    //QueueFloat();
                    break;
                case '3':
                    std::cout << " ** CODA DI STRINGHE ** \n\n";
                    //QueueString();
                    break;
                case '4':
                    std::cout << " ** CODA DI DOUBLE ** \n\n";
                    //QueueDouble();
                    break;
                case 'e':
                    std::cout << " Program is gonna stop... \n";
                    break;

                default:
                    std::cout << " Hai inserito un codice non valido! riprovare : ";

            }
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            if (scelta != 'e') {
                std::cout << "\n\n Premi un tasto per continuare ...";
                std::cin.get();
            }

        }
    }
}
void QueueVecDouble() {
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Che operazione vuoi effettuare sulla seguente coda come vettore : \n";
        std::cout << "1. \n";
        std::cout << "2. \n";
        std::cout << "3. \n";
        std::cout << "4. \n";

        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** CODA DI INTERI ** \n\n";
                //QueueInt();
                break;
            case '2':
                std::cout << " ** CODA DI FLOAT ** \n\n";
                //QueueFloat();
                break;
            case '3':
                std::cout << " ** CODA DI STRINGHE ** \n\n";
                //QueueString();
                break;
            case '4':
                std::cout << " ** CODA DI DOUBLE ** \n\n";
                //QueueDouble();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
    void TestCode() {
        char scelta = '0';

        while (scelta != 'e') {
            std::cout << "Vuoi testare : \n";
            std::cout << "1.coda di interi. \n";
            std::cout << "2.coda di float. \n";
            std::cout << "3.coda di stringhe. \n";
            std::cout << "4.coda di double. \n";


            std::cout << "e. per uscire \n\n\n";

            std::cin >> scelta;

            switch (scelta) {

                case '1':
                    std::cout << " ** CODA DI INTERI ** \n\n";
                    //QueueInt();
                    break;
                case '2':
                    std::cout << " ** CODA DI FLOAT ** \n\n";
                    //QueueFloat();
                    break;
                case '3':
                    std::cout << " ** CODA DI STRINGHE ** \n\n";
                    //QueueString();
                    break;
                case '4':
                    std::cout << " ** CODA DI DOUBLE ** \n\n";
                    //QueueDouble();
                    break;
                case 'e':
                    std::cout << " Program is gonna stop... \n";
                    break;

                default:
                    std::cout << " Hai inserito un codice non valido! riprovare : ";

            }
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            if (scelta != 'e') {
                std::cout << "\n\n Premi un tasto per continuare ...";
                std::cin.get();
            }

        }
    }
}

void QueueListInt() {
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Che operazione vuoi effettuare sulla seguente coda come vettore : \n";
        std::cout << "1. \n";
        std::cout << "2. \n";
        std::cout << "3. \n";
        std::cout << "4. \n";

        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** CODA DI INTERI ** \n\n";
                //QueueInt();
                break;
            case '2':
                std::cout << " ** CODA DI FLOAT ** \n\n";
                //QueueFloat();
                break;
            case '3':
                std::cout << " ** CODA DI STRINGHE ** \n\n";
                //QueueString();
                break;
            case '4':
                std::cout << " ** CODA DI DOUBLE ** \n\n";
                //QueueDouble();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
    void TestCode() {
        char scelta = '0';

        while (scelta != 'e') {
            std::cout << "Vuoi testare : \n";
            std::cout << "1.coda di interi. \n";
            std::cout << "2.coda di float. \n";
            std::cout << "3.coda di stringhe. \n";
            std::cout << "4.coda di double. \n";


            std::cout << "e. per uscire \n\n\n";

            std::cin >> scelta;

            switch (scelta) {

                case '1':
                    std::cout << " ** CODA DI INTERI ** \n\n";
                    //QueueInt();
                    break;
                case '2':
                    std::cout << " ** CODA DI FLOAT ** \n\n";
                    //QueueFloat();
                    break;
                case '3':
                    std::cout << " ** CODA DI STRINGHE ** \n\n";
                    //QueueString();
                    break;
                case '4':
                    std::cout << " ** CODA DI DOUBLE ** \n\n";
                    //QueueDouble();
                    break;
                case 'e':
                    std::cout << " Program is gonna stop... \n";
                    break;

                default:
                    std::cout << " Hai inserito un codice non valido! riprovare : ";

            }
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            if (scelta != 'e') {
                std::cout << "\n\n Premi un tasto per continuare ...";
                std::cin.get();
            }

        }
    }
}
void QueueListFloat() {
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Che operazione vuoi effettuare sulla seguente coda come vettore : \n";
        std::cout << "1. \n";
        std::cout << "2. \n";
        std::cout << "3. \n";
        std::cout << "4. \n";

        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** CODA DI INTERI ** \n\n";
                //QueueInt();
                break;
            case '2':
                std::cout << " ** CODA DI FLOAT ** \n\n";
                //QueueFloat();
                break;
            case '3':
                std::cout << " ** CODA DI STRINGHE ** \n\n";
                //QueueString();
                break;
            case '4':
                std::cout << " ** CODA DI DOUBLE ** \n\n";
                //QueueDouble();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
    void TestCode() {
        char scelta = '0';

        while (scelta != 'e') {
            std::cout << "Vuoi testare : \n";
            std::cout << "1.coda di interi. \n";
            std::cout << "2.coda di float. \n";
            std::cout << "3.coda di stringhe. \n";
            std::cout << "4.coda di double. \n";


            std::cout << "e. per uscire \n\n\n";

            std::cin >> scelta;

            switch (scelta) {

                case '1':
                    std::cout << " ** CODA DI INTERI ** \n\n";
                    //QueueInt();
                    break;
                case '2':
                    std::cout << " ** CODA DI FLOAT ** \n\n";
                    //QueueFloat();
                    break;
                case '3':
                    std::cout << " ** CODA DI STRINGHE ** \n\n";
                    //QueueString();
                    break;
                case '4':
                    std::cout << " ** CODA DI DOUBLE ** \n\n";
                    //QueueDouble();
                    break;
                case 'e':
                    std::cout << " Program is gonna stop... \n";
                    break;

                default:
                    std::cout << " Hai inserito un codice non valido! riprovare : ";

            }
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            if (scelta != 'e') {
                std::cout << "\n\n Premi un tasto per continuare ...";
                std::cin.get();
            }

        }
    }
}
void QueueListString() {
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Che operazione vuoi effettuare sulla seguente coda come vettore : \n";
        std::cout << "1. \n";
        std::cout << "2. \n";
        std::cout << "3. \n";
        std::cout << "4. \n";

        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** CODA DI INTERI ** \n\n";
                //QueueInt();
                break;
            case '2':
                std::cout << " ** CODA DI FLOAT ** \n\n";
                //QueueFloat();
                break;
            case '3':
                std::cout << " ** CODA DI STRINGHE ** \n\n";
                //QueueString();
                break;
            case '4':
                std::cout << " ** CODA DI DOUBLE ** \n\n";
                //QueueDouble();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
    void TestCode() {
        char scelta = '0';

        while (scelta != 'e') {
            std::cout << "Vuoi testare : \n";
            std::cout << "1.coda di interi. \n";
            std::cout << "2.coda di float. \n";
            std::cout << "3.coda di stringhe. \n";
            std::cout << "4.coda di double. \n";


            std::cout << "e. per uscire \n\n\n";

            std::cin >> scelta;

            switch (scelta) {

                case '1':
                    std::cout << " ** CODA DI INTERI ** \n\n";
                    //QueueInt();
                    break;
                case '2':
                    std::cout << " ** CODA DI FLOAT ** \n\n";
                    //QueueFloat();
                    break;
                case '3':
                    std::cout << " ** CODA DI STRINGHE ** \n\n";
                    //QueueString();
                    break;
                case '4':
                    std::cout << " ** CODA DI DOUBLE ** \n\n";
                    //QueueDouble();
                    break;
                case 'e':
                    std::cout << " Program is gonna stop... \n";
                    break;

                default:
                    std::cout << " Hai inserito un codice non valido! riprovare : ";

            }
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            if (scelta != 'e') {
                std::cout << "\n\n Premi un tasto per continuare ...";
                std::cin.get();
            }

        }
    }
}
void QueueListDouble() {
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Che operazione vuoi effettuare sulla seguente coda come vettore : \n";
        std::cout << "1. \n";
        std::cout << "2. \n";
        std::cout << "3. \n";
        std::cout << "4. \n";

        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** CODA DI INTERI ** \n\n";
                //QueueInt();
                break;
            case '2':
                std::cout << " ** CODA DI FLOAT ** \n\n";
                //QueueFloat();
                break;
            case '3':
                std::cout << " ** CODA DI STRINGHE ** \n\n";
                //QueueString();
                break;
            case '4':
                std::cout << " ** CODA DI DOUBLE ** \n\n";
                //QueueDouble();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
    void TestCode() {
        char scelta = '0';

        while (scelta != 'e') {
            std::cout << "Vuoi testare : \n";
            std::cout << "1.coda di interi. \n";
            std::cout << "2.coda di float. \n";
            std::cout << "3.coda di stringhe. \n";
            std::cout << "4.coda di double. \n";


            std::cout << "e. per uscire \n\n\n";

            std::cin >> scelta;

            switch (scelta) {

                case '1':
                    std::cout << " ** CODA DI INTERI ** \n\n";
                    //QueueInt();
                    break;
                case '2':
                    std::cout << " ** CODA DI FLOAT ** \n\n";
                    //QueueFloat();
                    break;
                case '3':
                    std::cout << " ** CODA DI STRINGHE ** \n\n";
                    //QueueString();
                    break;
                case '4':
                    std::cout << " ** CODA DI DOUBLE ** \n\n";
                    //QueueDouble();
                    break;
                case 'e':
                    std::cout << " Program is gonna stop... \n";
                    break;

                default:
                    std::cout << " Hai inserito un codice non valido! riprovare : ";

            }
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            if (scelta != 'e') {
                std::cout << "\n\n Premi un tasto per continuare ...";
                std::cin.get();
            }

        }
    }
}


void QueueVec(){

}
void QueueList(){

}

void TestQueue(){
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Vuoi testare : \n";
        std::cout << "1.stack tramite vettore. \n";
        std::cout << "2.stack tramite lista. \n";



        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** STACK DI INTERI ** \n\n";
                //StackVec();
                break;
            case '2':
                std::cout << " ** STACK DI FLOAT ** \n\n";
                //StackList();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        if (scelta != 'e') {
            std::cout << "\n\n Premi un tasto per continuare ...";
            std::cin.get();
        }

    }
}
*/
void mytest() {

    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Prego, inserire : \n";
        std::cout << "1. per testare uno stack. \n";
        std::cout << "2. per testare una coda. \n";

        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** TEST STACK ** \n\n";
                TestStack();
                break;
            case '2':
                std::cout << " ** TEST CODE ** \n\n";
                //TestCode();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        if (scelta != 'e') {
            std::cout << "\n\n Premi un tasto per continuare ...";
            std::cin.get();
        }

    }
}








