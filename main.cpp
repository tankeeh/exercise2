
#include <iostream>
#include "zlasdtest/test.hpp"
#include "zmytest/test.hpp"

#include "stack/lst/stacklst.hpp"
#include "queue/lst/queuelst.hpp"
#include "stack/vec/stackvec.hpp"
#include "queue/vec/queuevec.hpp"


using namespace lasd;

int main(){

StackVec<int> stackvec(5);
stackvec.Push(1);


std::cout<<"Size del vettore : "<<stackvec.Size()<<"\n\n";

std::cout<<"\n\nTopNPop dello stack : "<<stackvec.TopNPop()<<"\n\n";
std::cout<<"\n\nTop dello stack : "<<stackvec.Top()<<"\n\n";

stackvec.Push(3);
std::cout<<"\n\nTop dello stack : "<<stackvec.Top()<<"\n\n";

std::cout<<"Size del vettore : "<<stackvec.Size()<<"\n\n";






/**MENU' FINALE**/
/*
    char scelta = '0';

    while (scelta != 'e') {
        std::cout << "\nPrego, inserire : \n";
        std::cout << "1. Per utilizzare il Test ''ZLASDTEST'' . \n";
        std::cout << "2. Per utilizzare il Test dello studente (ZMYTEST). \n";
        std::cout << "\n e. per uscire \n\n\n";

        std::cin >> scelta;

        switch (scelta) {

            case '1':
                std::cout << " ** ZLASDTEST ** \n\n";
                test();
                break;
            case '2':
                std::cout << " ** ZMYTEST ** \n\n";
                mytest();
                break;
            case 'e':
                std::cout << " Program is gonna stop... \n";
                exit(0);
                break;

            default:
                std::cout << " Hai inserito un codice non valido! riprovare : ";
        }
    }
    */

  return 0;

}

// ...