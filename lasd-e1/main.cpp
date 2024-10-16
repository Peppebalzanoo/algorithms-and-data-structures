#include "zlasdtest/test.hpp"
#include "zmytest/test.hpp"
#include <iostream>

int main() {
    int select = -1;
    do{
    std::cout << "***************************** Lasd Libraries 2021 *****************************" << std::endl;
    std::cout << "    [1] CHIAMA LASDTEST" << std::endl;
    std::cout << "    [2] CHIAMA IL MIO TEST" << std::endl;
    std::cout << "    [0] PER USCIRE" << std::endl;
    std::cout<<"@"; std::cin>>select;
        switch (select) {
            case 1:
                lasdtest(); //Call to LasdTest
                break;
            case 2:
                start(); //Call to MyTest
                break;
            case 0:
                std::cout<<"*********************************** Good Bye **********************************"<<std::endl;
                break;
        }
    }while(select != 0);
    return 0;
}
