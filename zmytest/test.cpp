
#include <iostream>
#include <algorithm>
#include <cmath>
#include "../vector/vector.hpp"
#include "../list/list.hpp"
#include "../RandomValues.hpp"
//#include "stack/lst/stacklst.hpp"
//#include "queue/lst/queuelst.hpp"
//#include "stack/vec/stackvec.hpp"
//#include "queue/vec/queuevec.hpp"


/* ************************************************************************** */

/**FUNZIONI MAP BY ME**/

//FUNZIONE DI DUPLICAZIONE PER VETTORI E LISTE
template <typename Data>
void DuplicateInt(Data& elem, void*){
    elem = elem*2;
}
template <typename Data>
void DuplicateIntVectorPreOrder(lasd::Vector<Data> &vettore){
    vettore.MapPreOrder(DuplicateInt<Data>, nullptr);
}
template <typename Data>
void DuplicateIntListPreOrder(lasd::List<Data> &list){
    list.MapPreOrder(DuplicateInt<Data>, nullptr);
}




//FUNZIONE QUADRATO PER VETTORI E LISTE
template <typename Data>
void SquaredFloat(Data& elem, void* par){
    elem *= elem;
    elem = round(elem*1000)/1000;
}
template <typename Data>
void SquareFloatVectorPreOrder(lasd::Vector<Data> &vettore){
    vettore.MapPreOrder(&SquaredFloat<Data>, nullptr);
}
template <typename Data>
void SquareFloatListPreOrder(lasd::List<Data> &list){
    list.MapPreOrder(&SquaredFloat<Data>, nullptr);
}




//FUNZIONE DI UPPER CASE PER VETTORI E LISTE
template <typename Data>
void UpperCase(Data& elem, void* par){
    std::transform(elem.begin(), elem.end(),elem.begin(), ::toupper);
}
template <typename Data>
void UppercaseVectorPreOrder(lasd::Vector<Data> &vettore){
    vettore.MapPreOrder(&UpperCase<Data>, nullptr);
}
template <typename Data>
void UppercaseListPreOrder(lasd::List<Data> &list){
    list.MapPreOrder(&UpperCase<Data>, nullptr);
}





/**FUNZIONI DI FOLD BY ME**/

//FOLD PER INTERI
template <typename Data>
void Sum(const Data & dat, const void* par, void *acc) {
    if (dat < *(int*)par){
        *(int*)acc += dat;
    }
}
template <typename Data>
Data FoldIntVectorSumLowerThan(const Data par, lasd::Vector<Data> &vettore) {
    Data acc = 0;
    vettore.FoldPreOrder(&Sum<Data>,&par,&acc);
    return acc;
}
template <typename Data>
Data FoldIntListSumLowerThan(const Data par, lasd::List<Data> &list) {
    Data acc = 0;
    list.FoldPreOrder(&Sum<Data>,&par,&acc);
    return acc;
}



//FOLD PER FLOAT
template <typename Data>
void MoltiplicateFloat(const Data & dat, const void* par, void *acc) {
    if (dat > *(Data*)par){
        *(Data*)acc *= dat;
    }
}
template <typename Data>
Data FoldFloatVectorMoltiplicateBiggerThan(const Data par, lasd::Vector<Data> &vettore) {
    Data acc = 1;
    vettore.FoldPreOrder(&MoltiplicateFloat<Data>,&par,&acc);
    return acc;
}
template <typename Data>
Data FoldFloatListMoltiplicateBiggerThan(const Data par, lasd::List<Data> &list) {
    float acc = 1.0f;
    list.FoldPreOrder(&MoltiplicateFloat<Data>,&par,&acc);
    return acc;
}




//FOLD PER STRINGHE
template <typename Data>
void StringConcat(const Data & dat, const void* par, void *acc) {
    if (dat.length() <= *(int*)par){
        *(Data*)acc += dat;
    }
}

template <typename Data>
Data FoldStringVectorConcatLowerEquals(const int par, lasd::Vector<Data> &vettore) {
    std::string acc = "";
    vettore.FoldPreOrder(&StringConcat<Data>,&par,&acc);
    return acc;
}

template <typename Data>
Data FoldStringListConcatLowerEquals(const int par, lasd::List<Data> &list) {
    std::string acc = "";
    list.FoldPreOrder(&StringConcat<Data>,&par,&acc);
    return acc;
}











void GeneralTestStackAndQueueList(){
/*
    lasd::QueueLst<int> queuelist;
    queuelist.Enqueue(1);
    queuelist.Enqueue(2);
    queuelist.Enqueue(3);
    queuelist.Enqueue(4);

    std::cout<<"\n\nTOP stacklist1: "<<queuelist.HeadNDequeue();

    lasd::QueueLst<int> queuelist2;

    queuelist2 = queuelist;
    std::cout<<"\n\nTOP queuelist2: "<<queuelist2.Head();
    //stacklist2.Push(45);

    //std::cout<<"\n\nTOP stacklist2: "<<stacklist2.Top();


    //if(stacklist == stacklist2) std::cout<<" SONO UGUALI ! ";
*/
}

void GeneralTestStackAndQueueVector(){


}

void GeneralTestListe(){

    int n=1;
    int m = 0;
    lasd::List<int> lista1;
    std::cout<<"Quanti nodi vuoi inserire all' interno della lista1 : ";
    std::cin>>m;

    for(int i=0;i<m;i++) {
        lista1.InsertAtFront(n++);
    }
    lista1.PrintList();

    lasd::List<int> lista2;
    std::cout<<"\nQuanti nodi vuoi inserire all' interno della lista2 : ";
    std::cin>>m;

    for(int i=0;i<m;i++) {
        lista2.InsertAtFront(n++);
    }
    lista2.PrintList();
    /**LIST TEST**/

    //COPY CONSTRUCTOR
    std::cout<<"\n\n ** TEST COPY CONSTRUCTOR ** \n\n";
    lasd::List<int> lista3(lista2);
    lista3.PrintPreOrder();

    //MOVE CONSTRUCTOR
    std::cout<<"\n\n ** TEST MOVE CONSTRUCTOR ** \n\n";
    lasd::List<int> lista4(std::move(lista2));
    lista4.PrintPreOrder();
    std::cout<<"Print della lista passata con move : \n";
    lista2.PrintPreOrder();


    //COPY ASSIGNMENT
    std::cout<<" ** TEST COPY ASSIGNMENT ** \n\n";
    lista1 = lista4;
    lista1.PrintPreOrder();

    //MOVE ASSIGMENT
    std::cout<<" ** TEST MOVE ASSIGNMENT ** \n\n";
    lista1 = std::move(lista4);
    lista1.PrintPreOrder();
    std::cout<<"Print della lista passata con move : \n";
    lista4.PrintPreOrder();

    //OPERATOR ==
    std::cout<<" ** TEST OPERATOR ==  ** \n\n";
    lasd::List<int> listauguale(lista1);
    if (lista1 == listauguale) std::cout<<" SONO UGUALI \n";
    else std::cout<<" SONO DIVERSI \n";


    //OPERATOR !=
    std::cout<<" ** TEST OPERATOR !=** \n\n";
    if (lista1 != lista4) std::cout<<" SONO DIVERSI \n";


    /** NODE TEST **/

    //COPY CONSTRUCTOR
    //lasd::List<int>::Node node1 = new Node();

    //MOVE CONSTRUCTOR


    //OPERATOR ==

    //OPERATOR !=

}

void GeneralTestVettori(){



    int n=1;
    int m = 0;
    std::cout<<"Quanti nodi vuoi inserire all' interno del vettore1 : ";
    std::cin>>m;
    lasd::Vector<int> vettore1(m);


    for(int i=0;i<m;i++) {
        vettore1[i] = (n++);
    }
    vettore1.PrintPreorder();

    std::cout<<"Quanti nodi vuoi inserire all' interno del vettore2 : ";
    std::cin>>m;
    lasd::Vector<int> vettore2(m);

    for(int i=0;i<m;i++) {
        vettore2[i] = (n++);
    }
    vettore2.PrintPreorder();


    //COPY CONSTRUCTOR
    std::cout<<"\n\n ** TEST COPY CONSTRUCTOR ** \n\n";
    lasd::Vector<int> vettore3(vettore2);
    vettore3.PrintPreorder();

    //MOVE CONSTRUCTOR
    std::cout<<"\n\n ** TEST MOVE CONSTRUCTOR ** \n\n";
    lasd::Vector<int> vettore4(std::move(vettore2));
    vettore4.PrintPreorder();
    std::cout<<"Print della lista passata con move : \n";
    vettore2.PrintPreorder();


    //COPY ASSIGNMENT
    std::cout<<" ** TEST COPY ASSIGNMENT ** \n\n";
    vettore1 = vettore4;
    vettore1.PrintPreorder();

    //MOVE ASSIGMENT
    std::cout<<" ** TEST MOVE ASSIGNMENT ** \n\n";
    vettore1 = std::move(vettore4);
    vettore1.PrintPreorder();
    std::cout<<"Print della lista passata con move : \n";
    vettore4.PrintPreorder();

    //OPERATOR ==
    std::cout<<" ** TEST OPERATOR ==  ** \n\n";
    lasd::Vector<int> vettoreuguale(vettore1);
    if (vettore1 == vettoreuguale) std::cout<<" SONO UGUALI \n";
    else std::cout<<" SONO DIVERSI \n";


    //OPERATOR !=
    std::cout<<" ** TEST OPERATOR !=** \n\n";
    if (vettore1 != vettore4) std::cout<<" SONO DIVERSI \n";


}





/**TEST DEI VETTORI**/
void TestVectorString(){
    char scelta = '0';
    int n;

    std::cout << "\n\n-- VETTORE DI STRINGHE -- \n\n";

    std::cout << "Quanti elementi si vogliono inserire all' interno del vettore? : ";
    std::cin >> n;
    lasd::Vector<std::string> vettore1(n);


    for (int i = 0; i < n; i++) vettore1[i] = CharValueGenerator();


    while (scelta != 'e') {

        std::cout << "\n\nCosa intendi fare con il seguente vettore? \n\n";

        std::cout << "0. MAP PRINT PREORDER. \n";
        std::cout << "1. MAP PRINT POSTORDER. \n";
        std::cout << "2. FRONT. \n";
        std::cout << "3. BACK. \n";
        std::cout << "4. ACCESSO AD UN ELEMENTO. \n";
        std::cout << "5. CLEAR. \n";
        std::cout << "6. RESIZE. \n";
        std::cout << "7. FOLD EXISTS. \n";
        std::cout << "8. FOLD ConcatString. \n";
        std::cout << "9. MAP UpperCase. \n";

        std::cout<<"b (back). tornare al menu' di scelta dei vettori.\n";
        std::cout << "e (exit). per uscire \n\n\n";

        std::cin >> scelta;
        switch (scelta) {
            case '0':
                std::cout << " -- PRINT DEL VETTORE IN PREORDER -- \n";
                vettore1.PrintPreorder();
                break;
            case '1':
                std::cout << " -- PRINT DEL VETTORE IN POSTORDER -- \n";
                vettore1.PrintPostorder();
                break;
            case '2':
                std::cout << " -- FRONT -- \n";
                try {
                    std::cout << "Il primo elemento del vettore e' : " << vettore1.Front();
                }catch(std::length_error err) {
                    std::clog<<err.what();
                }
                break;
            case '3':
                std::cout << " -- BACK -- \n";
                try {
                    std::cout << "L' ultimo elemento del vettore e' : " << vettore1.Back();
                }catch(std::length_error err){
                    std::clog<<err.what();
                }
                break;
            case '4':
                int elem;
                std::cout << " -- ACCESSO ALL ELEMENTO -- \n";
                std::cout << " A quale elemento vuoi accedere ? : ";
                std::cin >> elem;
                try {
                    std::cout << "L'elemento selezionato e' : " << vettore1[elem];
                }catch( std::length_error ex){
                    std::clog<<ex.what();
                }

                break;
            case '5':
                std::cout << " -- CLEAR --  \n";
                std::cout << "IL VETTORE E' STATO PULITO.\n";

                vettore1.Clear();
                break;
            case '6':
                int nsize;
                std::cout << " -- RESIZE -- \n";
                std::cout << "Quale vuoi che sia la nuova size del vettore? : ";
                std::cin >> nsize;
                vettore1.Resize(nsize);
                break;
            case '7': {
                std::string exp;
                std::cout << " -- FOLD EXISTS -- \n";
                std::cout << "Di quale elemento si vuole verificare l'esistenza all' interno del vettore? : ";
                std::cin >> exp;
                if (vettore1.Exists(exp) == 1) std::cout << "L' ELEMENTO E' PRESENTE NEL VETTORE. ";
                else std::cout << "L' ELEMENTO NON E' PRESENTE NEL VETTORE. ";
                break;
            }
            case '8':
                int par;
                std::cout << " -- FOLD StringConcatLowerEquals --  \n";
                std::cout<< "Verra' mostrata di seguito la concatenazione di tutte le stringhe del vettore aventi lunghezza minore di un certo parametro; \n";
                std::cout << "Inserire tale parametro : ";
                std::cin >> par;
                std::cout<<"la somma e' : "<<FoldStringVectorConcatLowerEquals(par, vettore1);
                break;
            case '9':

                std::cout << " -- MAP UpperCase. --  \n";
                std::cout << "Verra' effettuato l'UPPERCASE (Lettere maiuscole) di tutte le stringhe all' interno dell' array seguente : \n";

                UppercaseVectorPreOrder(vettore1);
                break;
            case 'b':
                std::cout << " Torno al menù di scelta dei vettori.\n";
                return;
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                exit(0);
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
}
void TestVectorInt(){
    char scelta = '0';
    int n;

    std::cout << "\n\n-- VETTORE DI INTERI -- \n\n";

    std::cout << "Quanti elementi si vogliono inserire all' interno del vettore? : ";
    std::cin >> n;
    lasd::Vector<int> vettore1(n);


    for (int i = 0; i < n; i++) vettore1[i] = IntValueGenerator();


    while (scelta != 'e') {

        std::cout << "\n\nCosa intendi fare con il seguente vettore? \n\n";

        std::cout << "0. MAP PRINT PREORDER. \n";
        std::cout << "1. MAP PRINT POSTORDER. \n";
        std::cout << "2. FRONT. \n";
        std::cout << "3. BACK. \n";
        std::cout << "4. ACCESSO AD UN ELEMENTO. \n";
        std::cout << "5. CLEAR. \n";
        std::cout << "6. RESIZE. \n";
        std::cout << "7. FOLD EXISTS. \n";
        std::cout << "8. FOLD SumIntLowerThan. \n";
        std::cout << "9. MAP DuplicateInt. \n";

        std::cout<<"b (back). tornare al menu' di scelta dei vettori.\n";
        std::cout << "e (exit). per uscire \n\n\n";

        std::cin >> scelta;
        switch (scelta) {
            case '0':
                std::cout << " -- PRINT DEL VETTORE IN PREORDER -- \n";
                vettore1.PrintPreorder();
                break;
            case '1':
                std::cout << " -- PRINT DEL VETTORE IN POSTORDER -- \n";
                vettore1.PrintPostorder();
                break;
            case '2':
                std::cout << " -- FRONT -- \n";
                try {
                    std::cout << "Il primo elemento del vettore e' : " << vettore1.Front();
                }catch(std::length_error err) {
                    std::clog<<err.what();
                }
                break;
            case '3':
                std::cout << " -- BACK -- \n";
                try {
                    std::cout << "L' ultimo elemento del vettore e' : " << vettore1.Back();
                }catch(std::length_error err){
                    std::clog<<err.what();
                }
                break;
            case '4':
                int elem;
                std::cout << " -- ACCESSO ALL ELEMENTO -- \n";
                std::cout << " A quale elemento vuoi accedere ? : ";
                std::cin >> elem;
                try {
                    std::cout << "L'elemento selezionato e' : " << vettore1[elem];
                }catch( std::length_error ex){
                    std::clog<<ex.what();
                }

                break;
            case '5':
                std::cout << " -- CLEAR --  \n";
                std::cout << "IL VETTORE E' STATO PULITO.\n";

                vettore1.Clear();
                break;
            case '6':
                int nsize;
                std::cout << " -- RESIZE -- \n";
                std::cout << "Quale vuoi che sia la nuova size del vettore? : ";
                std::cin >> nsize;
                vettore1.Resize(nsize);
                break;
            case '7':
                int ex;
                std::cout << " -- FOLD EXISTS -- \n";
                std::cout << "Di quale elemento si vuole verificare l'esistenza all' interno del vettore? : ";
                std::cin >> ex;
                if ( vettore1.Exists(ex)==1 ) std::cout<<"L' ELEMENTO E' PRESENTE NEL VETTORE. ";
                else std::cout<<"L' ELEMENTO NON E' PRESENTE NEL VETTORE. ";
                break;
            case '8':
                int par;
                std::cout << " -- FOLD SumIntLowerThan --  \n";
                std::cout
                        << "Verra' mostrata di seguito la somma degli interi del vettore minori di un certo parametro; \n";
                std::cout << "Inserire tale parametro : ";
                std::cin >> par;
                std::cout<<"la somma e' : "<<FoldIntVectorSumLowerThan(par, vettore1);
                break;
            case '9':

                std::cout << " -- MAP DuplicateInt. --  \n";
                std::cout << "Verranno duplicati tutti i valori all' interno dell' array seguente : \n";

                DuplicateIntVectorPreOrder(vettore1);
                break;
            case 'b':
                std::cout << " Torno al menù di scelta dei vettori.\n";
                return ;
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                exit(0);
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
}
void TestVectorFloat(){
    char scelta = '0';
    int n;

    std::cout << "\n\n-- VETTORE DI FLOAT -- \n\n";

    std::cout << "Quanti elementi si vogliono inserire all' interno del vettore? : ";
    std::cin >> n;
    lasd::Vector<float> vettore1(n);


    for (int i = 0; i < n; i++) vettore1[i] = FloatValueGenerator();


    while (scelta != 'e') {

        std::cout << "\n\nCosa intendi fare con il seguente vettore? \n\n";

        std::cout << "0. MAP PRINT PREORDER. \n";
        std::cout << "1. MAP PRINT POSTORDER. \n";
        std::cout << "2. FRONT. \n";
        std::cout << "3. BACK. \n";
        std::cout << "4. ACCESSO AD UN ELEMENTO. \n";
        std::cout << "5. CLEAR. \n";
        std::cout << "6. RESIZE. \n";
        std::cout << "7. FOLD EXISTS. \n";
        std::cout << "8. FOLD FoldFloatMoltiplicateBiggerThan. \n";
        std::cout << "9. MAP SquaredFloat. \n";

        std::cout<<"b (back). tornare al menu' di scelta dei vettori.\n";
        std::cout << "e (exit). per uscire \n\n\n";

        std::cin >> scelta;
        switch (scelta) {
            case '0':
                std::cout << " -- PRINT DEL VETTORE IN PREORDER -- \n";
                vettore1.PrintPreorder();
                break;
            case '1':
                std::cout << " -- PRINT DEL VETTORE IN POSTORDER -- \n";
                vettore1.PrintPostorder();
                break;
            case '2':
                std::cout << " -- FRONT -- \n";
                try {
                    std::cout << "Il primo elemento del vettore e' : " << vettore1.Front();
                }catch(std::length_error err) {
                    std::clog<<err.what();
                }
                break;
            case '3':
                std::cout << " -- BACK -- \n";
                try {
                    std::cout << "L' ultimo elemento del vettore e' : " << vettore1.Back();
                }catch(std::length_error err){
                    std::clog<<err.what();
                }
                break;
            case '4':
                int elem;
                std::cout << " -- ACCESSO ALL ELEMENTO -- \n";
                std::cout << " A quale elemento vuoi accedere ? : ";
                std::cin >> elem;
                try {
                    std::cout << "L'elemento selezionato e' : " << vettore1[elem];
                }catch( std::length_error ex){
                    std::clog<<ex.what();
                }

                break;
            case '5':
                std::cout << " -- CLEAR --  \n";
                std::cout << "IL VETTORE E' STATO PULITO.\n";

                vettore1.Clear();
                break;
            case '6':
                int nsize;
                std::cout << " -- RESIZE -- \n";
                std::cout << "Quale vuoi che sia la nuova size del vettore? : ";
                std::cin >> nsize;
                vettore1.Resize(nsize);
                break;
            case '7':
                float ex;
                std::cout << " -- FOLD EXISTS -- \n";
                std::cout << "Di quale elemento si vuole verificare l'esistenza all' interno del vettore? : ";
                std::cin >> ex;
                if ( vettore1.Exists(ex)==1 ) std::cout<<"L' ELEMENTO E' PRESENTE NEL VETTORE. ";
                else std::cout<<"L' ELEMENTO NON E' PRESENTE NEL VETTORE. ";
                break;
            case '8':
                float par;
                std::cout << " -- FOLD FoldFloatMoltiplicateBiggerThan --  \n";
                std::cout
                        << "Verra' mostrato di seguito il prodotto degli elementi del vettore maggiori di un certo parametro; \n";
                std::cout << "Inserire tale parametro : ";
                std::cin >> par;
                std::cout<<"la somma e' : "<<FoldFloatVectorMoltiplicateBiggerThan(par,vettore1);
                break;
            case '9':

                std::cout << " -- MAP SquaredFloat. --  \n";
                std::cout << "Verra' effettuato il quadrato di ciascun elemento all' interno dell' array seguente : \n";

                SquareFloatVectorPreOrder(vettore1);
                break;
            case 'b':
                std::cout << " Torno al menù di scelta dei vettori.\n";
                return ;
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                exit(0);
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
}
void TestVectorDouble(){
    char scelta = '0';
    int n;

    std::cout << "\n\n-- VETTORE DI DOUBLE -- \n\n";
    std::cout << "NOTA: Essendo anche il tipo double a virgola Mobile e compatibile al float in quanto ad operazioni,"
                 " saranno messe a disposizione nel menu' le Map e Fold sviluppate per gli stessi. \n\n";


    std::cout << "Quanti elementi si vogliono inserire all' interno del vettore? : ";
    std::cin >> n;
    lasd::Vector<double> vettore1(n);


    for (int i = 0; i < n; i++) vettore1[i] = FloatValueGenerator();


    while (scelta != 'e') {

        std::cout << "\n\nCosa intendi fare con il seguente vettore? \n\n";

        std::cout << "0. MAP PRINT PREORDER. \n";
        std::cout << "1. MAP PRINT POSTORDER. \n";
        std::cout << "2. FRONT. \n";
        std::cout << "3. BACK. \n";
        std::cout << "4. ACCESSO AD UN ELEMENTO. \n";
        std::cout << "5. CLEAR. \n";
        std::cout << "6. RESIZE. \n";
        std::cout << "7. FOLD EXISTS. \n";
        std::cout << "8. FOLD FoldDoubleMoltiplicateBiggerThan. \n";
        std::cout << "9. MAP SquaredDouble. \n";

        std::cout<<"b (back). tornare al menu' di scelta dei vettori.\n";
        std::cout << "e (exit). per uscire \n\n\n";

        std::cin >> scelta;
        switch (scelta) {
            case '0':
                std::cout << " -- PRINT DEL VETTORE IN PREORDER -- \n";
                vettore1.PrintPreorder();
                break;
            case '1':
                std::cout << " -- PRINT DEL VETTORE IN POSTORDER -- \n";
                vettore1.PrintPostorder();
                break;
            case '2':
                std::cout << " -- FRONT -- \n";
                try {
                    std::cout << "Il primo elemento del vettore e' : " << vettore1.Front();
                }catch(std::length_error err) {
                    std::clog<<err.what();
                }
                break;
            case '3':
                std::cout << " -- BACK -- \n";
                try {
                    std::cout << "L' ultimo elemento del vettore e' : " << vettore1.Back();
                }catch(std::length_error err){
                    std::clog<<err.what();
                }
                break;
            case '4':
                int elem;
                std::cout << " -- ACCESSO ALL ELEMENTO -- \n";
                std::cout << " A quale elemento vuoi accedere ? : ";
                std::cin >> elem;
                try {
                    std::cout << "L'elemento selezionato e' : " << vettore1[elem];
                }catch( std::length_error ex){
                    std::clog<<ex.what();
                }

                break;
            case '5':
                std::cout << " -- CLEAR --  \n";
                std::cout << "IL VETTORE E' STATO PULITO.\n";

                vettore1.Clear();
                break;
            case '6':
                int nsize;
                std::cout << " -- RESIZE -- \n";
                std::cout << "Quale vuoi che sia la nuova size del vettore? : ";
                std::cin >> nsize;
                vettore1.Resize(nsize);
                break;
            case '7':
                double ex;
                std::cout << " -- FOLD EXISTS -- \n";
                std::cout << "Di quale elemento si vuole verificare l'esistenza all' interno del vettore? : ";
                std::cin >> ex;
                if ( vettore1.Exists(ex)==1 ) std::cout<<"L' ELEMENTO E' PRESENTE NEL VETTORE. ";
                else std::cout<<"L' ELEMENTO NON E' PRESENTE NEL VETTORE. ";
                break;
            case '8':
                double par;
                std::cout << " -- FOLD FoldDoubleMoltiplicateBiggerThan --  \n";
                std::cout
                        << "Verra' mostrato di seguito il prodotto degli elementi del vettore maggiori di un certo parametro; \n";
                std::cout << "Inserire tale parametro : ";
                std::cin >> par;
                std::cout<<"Il prodotto e' : "<<FoldFloatVectorMoltiplicateBiggerThan(par, vettore1);
                break;
            case '9':

                std::cout << " -- MAP SquaredDouble. --  \n";
                std::cout << "Verra' effettuato il quadrato di ciascun elemento all' interno dell' array seguente : \n";

                SquareFloatVectorPreOrder(vettore1);
                break;
            case 'b':
                std::cout << " Torno al menù di scelta dei vettori.\n";
                return ;
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                exit(0);
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
}

void TestVettori(){

    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Prego, inserire : \n";
        std::cout << "1. per creare un vettore di interi. \n";
        std::cout << "2. per creare un vettore di stringhe. \n";
        std::cout << "3. per creare un vettore di float. \n";
        std::cout << "4. per creare un vettore di double. \n";

        std::cout << "\n\nb (back). per tornare al menu' di scelta della struttura. \n";
        std::cout << "e (exit). per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " * TEST INTERI * \n";
                TestVectorInt();
                break;
            case '2':
                std::cout << " * TEST STRINGHE * \n";
                TestVectorString();
                break;
            case '3':
                std::cout << " * TEST FLOAT * \n";
                TestVectorFloat();
                break;
            case '4':
                std::cout << " * TEST DOUBLE * \n";
                TestVectorDouble();
                break;
            case 'b':
                std::cout << " Torno al menu' di scelta della struttura...\n";
                return;
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                exit(0);
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
        std::cin.clear();
        std::cin.ignore(100, '\n');
        if (scelta != 'e') {
            std::cout << "\n\n Premi un tasto per continuare ...";
            std::cin.get();
        }

    }
}



/**TEST DELLE LISTE**/
void TestListInt(){
    int scelta = -1;
    int n;

    std::cout << "\n\n-- LISTA DI INTERI -- \n\n";

    std::cout << "Quanti elementi si vogliono inserire all' interno della lista? : ";
    std::cin >> n;
    lasd::List<int> lista1;


    for (int i = 0; i < n; i++) lista1.InsertAtFront(IntValueGenerator());


    while (scelta != 0) {

        std::cout << "\n\nCosa intendi fare con la seguente lista ? \n\n";

        std::cout << "1. MAP PRINT PREORDER. \n";
        std::cout << "2. MAP PRINT POSTORDER. \n";
        std::cout << "3. FRONT. \n";
        std::cout << "4. FRONT & REMOVE. \n";
        std::cout << "5. BACK. \n";
        std::cout << "6. INSERT AT FRONT. \n";
        std::cout << "7. INSERT AT BACK. \n";
        std::cout << "8. REMOVE FROM FRONT \n";
        std::cout << "9. ACCESSO AD UN ELEMENTO. \n";
        std::cout << "10. CLEAR. \n";
        std::cout << "11. FOLD EXISTS. \n";
        std::cout << "12. FOLD SumIntLowerThan. \n";
        std::cout << "13. MAP DuplicateInt. \n\n";

        std::cout << "14. tornare al menu' di scelta delle liste. \n";
        std::cout << "0. per uscire \n\n\n";

        std::cin >> scelta;
        switch (scelta) {
            case 1:
                std::cout << " -- PRINT DELLA LISTA IN PREORDER -- \n";
                lista1.PrintPreOrder();
                break;
            case 2:
                std::cout << " -- PRINT DELLA LISTA IN POSTORDER -- \n";
                lista1.PrintPostOrder();
                break;
            case 3:
                std::cout << " -- FRONT -- \n";
                try {
                    std::cout << "Il primo elemento della lista e' : " << lista1.Front();
                }catch(std::length_error err){
                    std::clog<<err.what();
                }
                break;
            case 4:
                std::cout << " -- FRONT & REMOVE -- \n";
                try {
                    std::cout << "Il primo elemento della lista e' : " << lista1.FrontNRemove();
                    std::cout << "\nElemento eliminato. \n";
                }catch(std::length_error err){
                    std::clog<<err.what();
                }
                break;
            case 5:
                std::cout << " -- BACK -- \n";
                try {
                    std::cout << "L' ultimo elemento della lista e' : " << lista1.Back()<<"\n";
                } catch (std::length_error err) {
                    std::clog<<err.what();
                }
                break;
            case 6:
                int addedElemFront;
                std::cout << " -- INSERT AT FRONT -- \n";
                std::cout << "Che elemento vuoi inserire in testa? : ";
                std::cin>>addedElemFront;

                lista1.InsertAtFront(addedElemFront);
                break;
            case 7:
                int addedElemBack;
                std::cout << " -- INSERT AT BACK -- \n";
                std::cout << "Che elemento vuoi inserire in coda? : ";
                std::cin>>addedElemBack;
                lista1.InsertAtBack(addedElemBack);
                break;
            case 8:

                std::cout << " -- REMOVE FROM FRONT -- \n";
                try {
                    lista1.RemoveFromFront();
                    std::cout << "Elemento in testa eliminato. \n";
                }catch(std::length_error err){
                    std::clog<<err.what();
                }
                break;
            case 9:
                int elem;
                std::cout << " -- ACCESSO ALL ELEMENTO -- \n";
                std::cout << " A quale elemento vuoi accedere ? : ";
                std::cin >> elem;
                try {
                    std::cout << "L'elemento selezionato e' : " << lista1[elem];
                }catch( std::length_error ex){
                    std::clog<<ex.what();
                }
                break;
            case 10:
                std::cout << " -- CLEAR --  \n";
                lista1.Clear();
                std::cout << "LA LISTA E' STATA PULITA.\n";
                break;

            case 11:
                int ex;
                std::cout << " -- FOLD EXISTS -- \n";
                std::cout << "Di quale elemento si vuole verificare l'esistenza all' interno della lista? : ";
                std::cin >> ex;
                if ( lista1.Exists(ex)==1 ) std::cout<<"L' ELEMENTO E' PRESENTE NELLA LISTA. ";
                else std::cout<<"L' ELEMENTO NON E' PRESENTE NELLA LISTA. ";
                break;
            case 12:
                int par;
                std::cout << " -- FOLD SumIntLowerThan --  \n";
                std::cout
                        << "Verra' mostrata di seguito la somma degli interi della lista, minori di un certo parametro; \n";
                std::cout << "Inserire tale parametro : ";
                std::cin >> par;
                std::cout<<"la somma e' : "<<FoldIntListSumLowerThan(par, lista1);
                break;
            case 13:

                std::cout << " -- MAP DuplicateInt. --  \n";
                std::cout << "Verranno duplicati tutti i valori all' interno della lista seguente : \n";

                DuplicateIntListPreOrder(lista1);
                break;
            case 14:
                std::cout << " Torno al menù di scelta delle liste.\n";
                return;
                break;
            case 0:
                std::cout << " Program is gonna stop... \n";
                exit(0);
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
}
void TestListString(){
    int scelta = -1;
    int n;

    std::cout << "\n\n-- LISTA DI STRINGHE -- \n\n";

    std::cout << "Quanti elementi si vogliono inserire all' interno della lista? : ";
    std::cin >> n;
    lasd::List<std::string> lista1;


    for (int i = 0; i < n; i++) lista1.InsertAtFront(CharValueGenerator());


    while (scelta != 0) {

        std::cout << "\n\nCosa intendi fare con la seguente lista ? \n\n";

        std::cout << "1. MAP PRINT PREORDER. \n";
        std::cout << "2. MAP PRINT POSTORDER. \n";
        std::cout << "3. FRONT. \n";
        std::cout << "4. FRONT & REMOVE. \n";
        std::cout << "5. BACK. \n";
        std::cout << "6. INSERT AT FRONT. \n";
        std::cout << "7. INSERT AT BACK. \n";
        std::cout << "8. REMOVE FROM FRONT \n";
        std::cout << "9. ACCESSO AD UN ELEMENTO. \n";
        std::cout << "10. CLEAR. \n";
        std::cout << "11. FOLD EXISTS. \n";
        std::cout << "12. FOLD FoldStringListConcatLowerEquals. \n";
        std::cout << "13. MAP Uppercase. \n\n";

        std::cout << "14. tornare al menu' di scelta delle liste. \n";
        std::cout << "0. per uscire \n\n\n";

        std::cin >> scelta;
        switch (scelta) {
            case 1:
                std::cout << " -- PRINT DELLA LISTA IN PREORDER -- \n";
                lista1.PrintPreOrder();
                break;
            case 2:
                std::cout << " -- PRINT DELLA LISTA IN POSTORDER -- \n";
                lista1.PrintPostOrder();
                break;
            case 3:
                std::cout << " -- FRONT -- \n";
                try {
                    std::cout << "Il primo elemento della lista e' : " << lista1.Front();
                }catch(std::length_error err){
                    std::clog<<err.what();
                }
                break;
            case 4:
                std::cout << " -- FRONT & REMOVE -- \n";
                try {
                    std::cout << "Il primo elemento della lista e' : " << lista1.FrontNRemove();
                    std::cout << "\nElemento eliminato. \n";
                }catch(std::length_error err){
                    std::clog<<err.what();
                }
                break;
            case 5:
                std::cout << " -- BACK -- \n";
                try {
                    std::cout << "L' ultimo elemento della lista e' : " << lista1.Back();
                } catch (std::length_error err) {
                    std::clog<<err.what();
                }
                break;
            case 6: {
                std::string addedElemFront;
                std::cout << " -- INSERT AT FRONT -- \n";
                std::cout << "Che elemento vuoi inserire in testa? : ";
                std::cin >> addedElemFront;
                lista1.InsertAtFront(addedElemFront);
                break;
            }
            case 7: {
                std::string addedElemBack;
                std::cout << " -- INSERT AT BACK -- \n";
                std::cout << "Che elemento vuoi inserire in coda? : ";
                std::cin >> addedElemBack;
                lista1.InsertAtBack(addedElemBack);
                break;
            }
            case 8:

                std::cout << " -- REMOVE FROM FRONT -- \n";
                try {
                    lista1.RemoveFromFront();
                    std::cout << "\nElemento eliminato. \n";
                }
                catch(std::length_error err){
                    std::clog<<err.what();
                }
                break;

            case 9:
                int elem;
                std::cout << " -- ACCESSO ALL ELEMENTO -- \n";
                std::cout << " A quale elemento vuoi accedere ? : ";
                std::cin >> elem;
                try {
                    std::cout << "L'elemento selezionato e' : " << lista1[elem];
                }catch( std::length_error ex){
                    std::clog<<ex.what();
                }
                break;
            case 10: {
                std::cout << " -- CLEAR --  \n";
                lista1.Clear();
                std::cout << "LA LISTA E' STATA PULITA.\n";
                break;
            }
            case 11: {
                std::string ex;
                std::cout << " -- FOLD EXISTS -- \n";
                std::cout << "Di quale elemento si vuole verificare l'esistenza all' interno della lista? : ";
                std::cin >> ex;
                if (lista1.Exists(ex) == 1) std::cout << "L' ELEMENTO E' PRESENTE NELLA LISTA. ";
                else std::cout << "L' ELEMENTO NON E' PRESENTE NELLA LISTA. ";
                break;
            }
            case 12: {
                int par;

                std::cout << " -- FOLD FoldStringConcatLowerEquals --  \n";
                std::cout
                        << "Verra' mostrata di seguito la somma degli interi della lista, minori di un certo parametro; \n";
                std::cout << "Inserire tale parametro : ";
                std::cin >> par;
                std::string temp = "";

                //lista1.FoldPreOrder(StringConcat<std::string>,&par,&temp); //aggiungi temp nel cout sottostante
                std::cout << "la concatenazione e' : "<<FoldStringListConcatLowerEquals(par,lista1);
                break;
            }
            case 13:

                std::cout << " -- MAP UpperCase. --  \n";
                std::cout << "Verra' effettuato l' UPPERCASE ditutti i valori all' interno della lista seguente : \n";

                UppercaseListPreOrder(lista1);
                break;
            case 14:
                std::cout << " Torno al menù di scelta delle liste.\n";
                return;
                break;
            case 0:
                std::cout << " Program is gonna stop... \n";
                exit(0);
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
}
void TestListFloat(){
    int scelta = -1;
    int n;

    std::cout << "\n\n-- LISTA DI FLOAT -- \n\n";

    std::cout << "Quanti elementi si vogliono inserire all' interno della lista? : ";
    std::cin >> n;
    lasd::List<float> lista1;


    for (int i = 0; i < n; i++) lista1.InsertAtFront(FloatValueGenerator());


    while (scelta != 0) {

        std::cout << "\n\nCosa intendi fare con la seguente lista ? \n\n";

        std::cout << "1. MAP PRINT PREORDER. \n";
        std::cout << "2. MAP PRINT POSTORDER. \n";
        std::cout << "3. FRONT. \n";
        std::cout << "4. FRONT & REMOVE. \n";
        std::cout << "5. BACK. \n";
        std::cout << "6. INSERT AT FRONT. \n";
        std::cout << "7. INSERT AT BACK. \n";
        std::cout << "8. REMOVE FROM FRONT \n";
        std::cout << "9. ACCESSO AD UN ELEMENTO. \n";
        std::cout << "10. CLEAR. \n";
        std::cout << "11. FOLD EXISTS. \n";
        std::cout << "12. FOLD FoldFloatMoltiplicateBiggerThan. \n";
        std::cout << "13. MAP SquaredFloat. \n\n";

        std::cout << "14. tornare al menu' di scelta delle liste. \n";
        std::cout << "0. per uscire \n\n\n";

        std::cin >> scelta;
        switch (scelta) {
            case 1:
                std::cout << " -- PRINT DELLA LISTA IN PREORDER -- \n";
                lista1.PrintPreOrder();
                break;
            case 2:
                std::cout << " -- PRINT DELLA LISTA IN POSTORDER -- \n";
                lista1.PrintPostOrder();
                break;
            case 3:
                std::cout << " -- FRONT -- \n";
                try {
                    std::cout << "Il primo elemento della lista e' : " << lista1.Front();
                }catch(std::length_error err){
                    std::clog<<err.what();
                }
                break;
            case 4:
                std::cout << " -- FRONT & REMOVE -- \n";
                try {
                    std::cout << "Il primo elemento della lista e' : " << lista1.FrontNRemove();
                    std::cout << "\nElemento eliminato. \n";
                }catch(std::length_error err){
                    std::clog<<err.what();
                }
                break;
            case 5:
                std::cout << " -- BACK -- \n";
                try {
                    std::cout << "L' ultimo elemento della lista e' : " << lista1.Back();
                } catch (std::length_error err) {
                    std::clog<<err.what();
                }
                break;
            case 6:
                float addedElemFront;
                std::cout << " -- INSERT AT FRONT -- \n";
                std::cout << "Che elemento vuoi inserire in testa? : ";
                std::cin >> addedElemFront;
                lista1.InsertAtFront(addedElemFront);
                break;

            case 7:
                float addedElemBack;
                std::cout << " -- INSERT AT BACK -- \n";
                std::cout << "Che elemento vuoi inserire in coda? : ";
                std::cin >> addedElemBack;
                lista1.InsertAtBack(addedElemBack);
                break;

            case 8:

                std::cout << " -- REMOVE FROM FRONT -- \n";
                try {
                    lista1.RemoveFromFront();
                    std::cout << "\nElemento eliminato. \n";
                }
                catch(std::length_error err){
                    std::clog<<err.what();
                }
                break;

            case 9:
                int elem;
                std::cout << " -- ACCESSO ALL' ELEMENTO -- \n";
                std::cout << " A quale elemento vuoi accedere ? : ";
                std::cin >> elem;
                try {
                    std::cout << "L'elemento selezionato e' : " << lista1[elem];
                }catch( std::length_error ex){
                    std::clog<<ex.what();
                }
                break;
            case 10: {
                std::cout << " -- CLEAR --  \n";
                lista1.Clear();
                std::cout << "LA LISTA E' STATA PULITA.\n";
                break;
            }
            case 11: {
                float ex;
                std::cout << " -- FOLD EXISTS -- \n";
                std::cout << "Di quale elemento si vuole verificare l'esistenza all' interno della lista? : ";
                std::cin >> ex;
                if (lista1.Exists(ex) == 1) std::cout << "L' ELEMENTO E' PRESENTE NELLA LISTA. ";
                else std::cout << "L' ELEMENTO NON E' PRESENTE NELLA LISTA. ";
                break;
            }
            case 12: {
                float par;

                std::cout << " -- FOLD FoldFloatMoltiplicateBiggerThan. --  \n";
                std::cout<< "Verra' mostrato di seguito il prodotto degli elementi della lista maggiori di un certo parametro; \n";
                std::cout << "Inserire tale parametro : ";
                std::cin >> par;


                //lista1.FoldPreOrder(StringConcat<std::string>,&par,&temp); //aggiungi temp nel cout sottostante
                std::cout << "il prodotto e' : "<<FoldFloatListMoltiplicateBiggerThan(par,lista1);
                break;
            }
            case 13:

                std::cout << " -- MAP SquaredFloat. --  \n";
                std::cout << "Verra' fatto il quadrato di tutti i valori all' interno della lista seguente : \n";
                SquareFloatListPreOrder(lista1);
                break;
            case 14:
                std::cout << " Torno al menù di scelta delle liste.\n";
                return;
                break;
            case 0:
                std::cout << " Program is gonna stop... \n";
                exit(0);
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
}
void TestListDouble(){
    int scelta = -1;
    int n;

    std::cout << "\n\n-- LISTA DI DOUBLE -- \n\n";
    std::cout << "NOTA: Essendo anche il tipo double a virgola Mobile e compatibile al float in quanto ad operazioni,"
                 " saranno messe a disposizione nel menu' le Map e Fold sviluppate per gli stessi. \n\n";

    std::cout << "Quanti elementi si vogliono inserire all' interno della lista? : ";
    std::cin >> n;
    lasd::List<double> lista1;


    for (int i = 0; i < n; i++) lista1.InsertAtFront(FloatValueGenerator());


    while (scelta != 0) {

        std::cout << "\n\nCosa intendi fare con la seguente lista ? \n\n";

        std::cout << "1. MAP PRINT PREORDER. \n";
        std::cout << "2. MAP PRINT POSTORDER. \n";
        std::cout << "3. FRONT. \n";
        std::cout << "4. FRONT & REMOVE. \n";
        std::cout << "5. BACK. \n";
        std::cout << "6. INSERT AT FRONT. \n";
        std::cout << "7. INSERT AT BACK. \n";
        std::cout << "8. REMOVE FROM FRONT \n";
        std::cout << "9. ACCESSO AD UN ELEMENTO. \n";
        std::cout << "10. CLEAR. \n";
        std::cout << "11. FOLD EXISTS. \n";
        std::cout << "12. FOLD FoldFloatMoltiplicateBiggerThan. \n";
        std::cout << "13. MAP SquaredDouble. \n\n";

        std::cout << "14. tornare al menu' di scelta delle liste. \n";
        std::cout << "0. per uscire \n\n\n";

        std::cin >> scelta;
        switch (scelta) {
            case 1:
                std::cout << " -- PRINT DELLA LISTA IN PREORDER -- \n";
                lista1.PrintPreOrder();
                break;
            case 2:
                std::cout << " -- PRINT DELLA LISTA IN POSTORDER -- \n";
                lista1.PrintPostOrder();
                break;
            case 3:
                std::cout << " -- FRONT -- \n";
                try {
                    std::cout << "Il primo elemento della lista e' : " << lista1.Front();
                }catch(std::length_error err){
                    std::clog<<err.what();
                }
                break;
            case 4:
                std::cout << " -- FRONT & REMOVE -- \n";
                try {
                    std::cout << "Il primo elemento della lista e' : " << lista1.FrontNRemove();
                    std::cout << "\nElemento eliminato. \n";
                }catch(std::length_error err){
                    std::clog<<err.what();
                }

                break;
            case 5:
                std::cout << " -- BACK -- \n";
                try {
                    std::cout << "L' ultimo elemento della lista e' : " << lista1.Back();
                } catch (std::length_error err) {
                    std::clog<<err.what();
                }
                break;
            case 6: {
                double addedElemFront;
                std::cout << " -- INSERT AT FRONT -- \n";
                std::cout << "Che elemento vuoi inserire in testa? : ";
                std::cin >> addedElemFront;
                lista1.InsertAtFront(addedElemFront);
                break;
            }
            case 7: {
                double addedElemBack;
                std::cout << " -- INSERT AT BACK -- \n";
                std::cout << "Che elemento vuoi inserire in coda? : ";
                std::cin >> addedElemBack;
                lista1.InsertAtBack(addedElemBack);
                break;
            }
            case 8:

                std::cout << " -- REMOVE FROM FRONT -- \n";
                try {
                    lista1.RemoveFromFront();
                    std::cout << "\nElemento eliminato. \n";
                }
                catch(std::length_error err){
                    std::clog<<err.what();
                }
                break;

            case 9:
                int elem;
                std::cout << " -- ACCESSO ALL' ELEMENTO -- \n";
                std::cout << " A quale elemento vuoi accedere ? : ";
                std::cin >> elem;
                try {
                    std::cout << "L'elemento selezionato e' : " << lista1[elem];
                }catch( std::length_error ex){
                    std::clog<<ex.what();
                }
                break;
            case 10: {
                std::cout << " -- CLEAR --  \n";
                lista1.Clear();
                std::cout << "LA LISTA E' STATA PULITA.\n";
                break;
            }
            case 11: {
                double ex;
                std::cout << " -- FOLD EXISTS -- \n";
                std::cout << "Di quale elemento si vuole verificare l'esistenza all' interno della lista? : ";
                std::cin >> ex;
                if (lista1.Exists(ex) == 1) std::cout << "L' ELEMENTO E' PRESENTE NELLA LISTA. ";
                else std::cout << "L' ELEMENTO NON E' PRESENTE NELLA LISTA. ";
                break;
            }
            case 12: {
                double par;

                std::cout << " -- FOLD FoldDoubleMoltiplicateBiggerThan. --  \n";
                std::cout<< "Verra' mostrato di seguito il prodotto degli elementi della lista maggiori di un certo parametro; \n";
                std::cout << "Inserire tale parametro : ";
                std::cin >> par;

                std::cout << "il prodotto e' : "<<FoldFloatListMoltiplicateBiggerThan(par,lista1);
                break;
            }
            case 13:

                std::cout << " -- MAP SquaredFloat. --  \n";
                std::cout << "Verra' fatto il quadrato di tutti i valori all' interno della lista seguente : \n";
                SquareFloatListPreOrder(lista1);
                break;
            case 14:
                std::cout << " Torno al menù di scelta delle liste.\n";
                return;
                break;
            case 0:
                std::cout << " Program is gonna stop... \n";
                exit(0);
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";

        }
    }
}

void TestListe(){
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Prego, inserire : \n";
        std::cout << "1. per creare una lista di interi. \n";
        std::cout << "2. per creare una lista di stringhe. \n";
        std::cout << "3. per creare una lista di float. \n";
        std::cout << "4. per creare una lista di double. \n";
        std::cout << "\n\nb (back). per tornare al menu' di scelta della struttura. \n";
        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " * TEST LISTA INTERI * \n";
                TestListInt();
                break;
            case '2':
                std::cout << " * TEST LISTA STRINGHE * \n";
                TestListString();
                break;
            case '3':
                std::cout << " * TEST LISTA FLOAT * \n";
                TestListFloat();
                break;
            case '4':
                std::cout << " * TEST LISTA DOUBLE * \n";
                TestListDouble();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                exit(0);
                break;
            case 'b':
                std::cout << " Torno al menu' di scelta della struttura...\n";
                return;
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



void mytest() {

    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "Prego, inserire : \n";
        std::cout << "1. per testare un vettore. \n";
        std::cout << "2. per testare una lista. \n";

        std::cout << "e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** TEST VETTORI ** \n\n";
                TestVettori();
                break;
            case '2':
                std::cout << " ** TEST LISTE ** \n\n";
                TestListe();
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








