#include "test.hpp"


void emptiness(lasd::Container& con){
    if(con.Empty() == true){
        std::cout<<"LA STRUTTURA E' VUOTA"<<std::endl;
    }else{
        std::cout<<"LA STRUTTURA NON E' VUOTA"<<std::endl;
    }
}
/* ****************************************************************************************************************** */
template <typename Type>
void elementImmediatly(lasd::Queue<Type>& que){
    try{
        std::cout << ">>> L'ELEMENTO E':"<<std::fixed<<que.Head()<<" <<<"<<std::endl;
    }catch (std::length_error &exc){
        std::cout<<"\n*** ACCESSO NON VALIDO ALLA STRUTTURA ***"<<std::endl;
    }
}

template <typename Type>
void elementImmediatly(lasd::Stack<Type>& stk){
    try{
        std::cout << ">>> L'ELEMENTO E':"<<std::fixed<<stk.Top()<<" <<<"<<std::endl;
    }catch (std::length_error &exc){
        std::cout<<"\n*** ACCESSO NON VALIDO ALLA STRUTTURA ***"<<std::endl;
    }
}
/* ****************************************************************************************************************** */

template <typename Type>
void removeFromQueueWithoutRead(lasd::Queue<Type>& que){
    try {
        std::cout << ">>> RIMOZIONE SENZA LETTURA EFFETTUATA <<<" << std::endl;
        que.Dequeue();
    }catch(std::length_error &exc){
        std::cout<<"\n*** ACCESSO NON VALIDO ALLA STRUTTURA ***"<<std::endl;
    }
}

template <typename Type>
void removeFromQueueRead(lasd::Queue<Type>& que){
    try {
        std::cout << ">>> L'ELEMENTO CHE HAI RIMOSSO E': "<<std::fixed<<que.HeadNDequeue()<<" <<<"<<std::endl;
    }catch (std::length_error &exc){
        std::cout<<"\n*** ACCESSO NON VALIDO ALLA STRUTTURA ***"<<std::endl;
    }
}

/* ****************************************************************************************************************** */

template <typename Type>
void removeFromStackWithoutRead(lasd::Stack<Type>& stk){
    try {
        std::cout << ">>> RIMOZIONE SENZA LETTURA EFFETTUATA <<<" << std::endl;
        stk.Pop();
    }catch(std::length_error &exc){
        std::cout<<"\n*** ACCESSO NON VALIDO ALLA STRUTTURA ***"<<std::endl;
    }
}

template <typename Type>
void removeFromStackRead(lasd::Stack<Type>& stk){
    try {
        std::cout << ">>> L'ELEMENTO CHE HAI RIMOSSO E': "<<std::fixed<<stk.TopNPop()<<" <<<"<<std::endl;
    }catch (std::length_error &exc){
        std::cout<<"\n*** ACCESSO NON VALIDO ALLA STRUTTURA ***"<<std::endl;
    }
}

/* ****************************************************************************************************************** */

template <typename Type>
void insertInQueue(lasd::Queue<Type>& que){
    Type val;
    std::cout<<"\n*******************************************************************************"<<std::endl;
    do {
        std::cout << "@DIGITA L'ELEMENTO DA INSERIRE NELLA STRUTTURA" << std::endl;
        std::cout << "@";
        std::cin >> val;
        if(!std::cin.fail()){
            que.Enqueue(val);
        }else{
            std::cout<<"*** SELEZIONE NON VALIDA ***"<<std::endl;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    } while (std::cin.fail());

}

template <typename Type>
void insertInStack(lasd::Stack<Type>& stk){
    Type val;
    std::cout<<"\n*******************************************************************************"<<std::endl;
    do {
        std::cout << "@DIGITA L'ELEMENTO DA INSERIRE NELLA STRUTTURA" << std::endl;
        std::cout << "@";
        std::cin >> val;
        if(!std::cin.fail()){
            stk.Push(val);
        }else{
            std::cout<<"*** SELEZIONE NON VALIDA ***"<<std::endl;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    } while (std::cin.fail());
}

/* ****************************************************************************************************************** */

//*** Generator for Queue of integers ***//
void generatorQueueInteger(const ulong& dimension, lasd::Queue<int>& que){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(7, 100);
    for (ulong i = 0; i < dimension; i++) {
        que.Enqueue(dist(gen));
    }
}

//*** Generator for Queue of floats ***//
void generatorQueueFloat(const ulong& dimension, lasd::Queue<float>& que){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<float> dist(7, 100);
    for (ulong i = 0; i < dimension; i++) {
        que.Enqueue(dist(gen));
    }
}

//*** Generator for Queue of strings ***//
void generatorQueueString(const ulong& dimension, lasd::Queue<std::string>& que){
    static auto& chrs = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    thread_local static std::mt19937 rg{std::random_device{}()};
    thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);
    std::uniform_int_distribution <int> distribution(3,10);
    std::string s[dimension];
    int tmp = distribution(rg);
    for(ulong i =0; i < dimension; i++){
        while(tmp--){
            s[i] += chrs[pick(rg)];
        }
        tmp = distribution(rg);
        que.Enqueue(s[i]);
    }
}

/* ****************************************************************************************************************** */

//*** Generator for Stack of integers ***//
void generatorStackInteger(const ulong& dimension, lasd::Stack<int>& stk){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(7, 100);
    for (ulong i = 0; i < dimension; i++) {
        stk.Push(dist(gen));
    }
}

//*** Generator for Stack of floats ***//
void generatorStackFloat(const ulong& dimension, lasd::Stack<float>& stk){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<float> dist(7, 100);
    for (ulong i = 0; i < dimension; i++) {
        stk.Push(dist(gen));
    }
}

//*** Generator for Stack of strings ***//
void generatorStackString(const ulong& dimension, lasd::Stack<std::string>& stk){
    static auto& chrs = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    thread_local static std::mt19937 rg{std::random_device{}()};
    thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);
    std::uniform_int_distribution <int> distribution(3,10);
    std::string s[dimension];
    int tmp = distribution(rg);
    for(ulong i =0; i < dimension; i++){
        while(tmp--){
            s[i] += chrs[pick(rg)];
        }
        tmp = distribution(rg);
        stk.Push(s[i]);
    }
}

/* ****************************************************************************************************************** */

//*** Select the operation for the structure ***//
int& selectActionStructure(int& todo){

    std::cout<<"\n*******************************************************************************"<<std::endl;
    std::cout<<"@SELEZIONA L'OPERAZIONE DIGITANDO IL NUMERO DI RIFERIMENTO"<<std::endl;
    std::cout<<"    [1] INSERISCI UN ELEMENTO NELLA STRUTTURA"<<std::endl;
    std::cout<<"    [2] RIMOZIONE SENZA LETTURA"<<std::endl;
    std::cout<<"    [3] RIMOZIONE CON LETTURA"<<std::endl;
    std::cout<<"    [4] STAMPA DELL'ELEMENTO IMMEDIATAMENTE ACCESSIBILE"<<std::endl;
    std::cout<<"    [5] TEST DI VUOTEZZA"<<std::endl;
    std::cout<<"    [6] LETTURA DELLA DIMENSIONE DELLA STRUTTURA"<<std::endl;
    std::cout<<"    [7] SVUOTAMENTO DELLA STRUTTURA"<<std::endl;
    std::cout<<"    [0] PER USCIRE E TORNARE AL MENU PRECEDENTE"<<std::endl;
    std::cout<<"@"; std::cin>>todo;
    return todo;
}

/* ****************************************************************************************************************** */

//*** Select the dimension of structure (integer, float, string) ***//
ulong& selectSizeStructure(ulong& dimension){
    std::cout<<"\n*******************************************************************************"<<std::endl;
    do {
        std::cout<<"@INSERISCI LA DIMENSIONE DELLA STRUTTURA N > 0"<<std::endl;
        std::cout<<"@"; std::cin>>dimension;

        if(std::cin.fail()){
            std::cout << "\n*** INSERIMENTO NON VALIDO ***" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }else if(dimension <= 0){
            std::cout << "\n*** INSERIMENTO NON VALIDO ***" << std::endl;
        }
    }while(std::cin.fail() || dimension <= 0);
    std::cout<<">>> LA DIMENSIONE DELLA STRUTTURA E': "<<dimension<<" <<<"<<std::endl;
    return dimension;
}

/* ****************************************************************************************************************** */

//*** Select the type of structure (integer, float, string) ***//
int selectTypeStructure(){
    int select_typestructure = -1;
    do {
        std::cout<<"\n*******************************************************************************"<<std::endl;
        std::cout<<"@SELEZIONA IL TIPO DELLA STRUTTURA DIGITANDO IL NUMERO DI RIFERIMENTO"<<std::endl;
        std::cout<<"    [1] INTERO"<<std::endl;
        std::cout<<"    [2] FLOAT"<<std::endl;
        std::cout<<"    [3] STRINGA"<<std::endl;
        std::cout<<"    [0] PER USCIRE"<<std::endl;
        std::cout<<"@"; std::cin>>select_typestructure;

        switch (select_typestructure) {
            case 1 : //Integer
                std::cout<<">>> HAI SELEZIONATO IL TIPO INTERO <<<"<<std::endl;
                return 1;
            case 2 : //Float
                std::cout<<">>> HAI SELEZIONATO IL TIPO FLOAT <<<"<<std::endl;
                return 2;
            case 3 : //String
                std::cout<<">>> HAI SELEZIONATO IL TIPO STRINGA <<<"<<std::endl;
                return 3;
            case 0 : //Exit
                select_typestructure = 0;
                break;
            default:
                std::cout<<"*** SELEZIONE NON VALIDA DEL TIPO ***"<<std::endl;
                break;
        }
    }while(select_typestructure != 0);
    return select_typestructure;
}

/* ****************************************************************************************************************** */

void start() {
    int select_structure = -1;
    int type_structure = -1;
    ulong dimension = -1;
    int todo = -1;
    do {
        std::cout << "\n***************************** BENVENUTO NEL MENU' *****************************" << std::endl;
        std::cout << "@SELEZIONA LA STRUTTURA DIGITANDO IL NUMERO DI RIFERIMENTO" << std::endl;
        std::cout << "    [1] STACK LIST" << std::endl;
        std::cout << "    [2] STACK VECTOR" << std::endl;
        std::cout << "    [3] QUEUE LIST " << std::endl;
        std::cout << "    [4] QUEUE VECTOR " << std::endl;
        std::cout << "    [0] PER USCIRE" << std::endl;
        std::cout << "@";
        std::cin >> select_structure;
        switch (select_structure) {
            case 1 : //Stack List
                std::cout<<">>> HAI SELEZIONATO STACK LIST <<<"<<std::endl;
                type_structure = selectTypeStructure();
                selectSizeStructure(dimension);
                if(type_structure == 1){ //Stack List of integers
                    lasd::StackLst<int>stklis_int;
                    generatorStackInteger(dimension, stklis_int);
                    do {
                        switch(todo = selectActionStructure(todo)){
                            case 1: //Insert an element in the structure
                                insertInStack(stklis_int);
                                break;
                            case 2: //Remove an element from structure without read
                                removeFromStackWithoutRead(stklis_int);
                                break;
                            case 3: //Remove an element from structure with read
                                removeFromStackRead(stklis_int);
                                break;
                            case 4: //Print the element immediatly accessibile
                                elementImmediatly(stklis_int);
                                break;
                            case 5: //Test if the structure is empty
                                emptiness(stklis_int);
                                break;
                            case 6: //Read size of the structure
                                std::cout << ">>> LA SIZE DELLA STRUTTURA E':"<<stklis_int.Size()<<" <<<"<<std::endl;
                                break;
                            case 7: //Clear the structure
                                stklis_int.Clear();
                                std::cout << ">>> STRUTTURA SVUOTATA CORRETTAMENTE <<<"<<std::endl;
                                break;
                            case 0: //Exit
                                break;
                        }
                    }while(todo != 0);

                }else if(type_structure == 2){ //Stack List of floats
                    lasd::StackLst<float>stklis_float;
                    generatorStackFloat(dimension, stklis_float);
                    do {
                        switch(todo = selectActionStructure(todo)){
                            case 1: //Insert an element in the structure
                                insertInStack(stklis_float);
                                break;
                            case 2: //Remove an element from structure without read
                                removeFromStackWithoutRead(stklis_float);
                                break;
                            case 3: //Remove an element from structure with read
                                removeFromStackRead(stklis_float);
                                break;
                            case 4: //Print the element immediatly accessibile
                                elementImmediatly(stklis_float);
                                break;
                            case 5: //Test if the structure is empty
                                emptiness(stklis_float);
                                break;
                            case 6: //Read size of the structure
                                std::cout << ">>> LA SIZE DELLA STRUTTURA E':"<<stklis_float.Size()<<" <<<"<<std::endl;
                                break;
                            case 7: //Clear the structure
                                stklis_float.Clear();
                                std::cout << ">>> STRUTTURA SVUOTATA CORRETTAMENTE <<<"<<std::endl;
                                break;
                            case 0: //Exit
                                break;
                        }
                    }while(todo != 0);

                }else if(type_structure == 3){ //Stack List of strings
                    lasd::StackLst<std::string>stklis_string;
                    generatorStackString(dimension, stklis_string);
                    do {
                        switch(todo = selectActionStructure(todo)){
                            case 1: //Insert an element in the structure
                                insertInStack(stklis_string);
                                break;
                            case 2: //Remove an element from structure without read
                                removeFromStackWithoutRead(stklis_string);
                                break;
                            case 3: //Remove an element from structure with read
                                removeFromStackRead(stklis_string);
                                break;
                            case 4: //Print the element immediatly accessibile
                                elementImmediatly(stklis_string);
                                break;
                            case 5: //Test if the structure is empty
                                emptiness(stklis_string);
                                break;
                            case 6: //Read size of the structure
                                std::cout << ">>> LA SIZE DELLA STRUTTURA E':"<<stklis_string.Size()<<" <<<"<<std::endl;
                                break;
                            case 7: //Clear the structure
                                stklis_string.Clear();
                                std::cout << ">>> STRUTTURA SVUOTATA CORRETTAMENTE <<<"<<std::endl;
                                break;
                            case 0: //Exit
                                break;
                        }
                    }while(todo != 0);
                }
                select_structure = 0;
                break;

            case 2: //Stack Vector
                std::cout<<">>> HAI SELEZIONATO STACK VECTOR <<<"<<std::endl;
                type_structure = selectTypeStructure();
                selectSizeStructure(dimension);
                if(type_structure == 1){ //Stack Vec of integers
                    lasd::StackVec<int>stkvec_int;
                    generatorStackInteger(dimension, stkvec_int);
                    do {
                        switch(todo = selectActionStructure(todo)){
                            case 1: //Insert an element in the structure
                                insertInStack(stkvec_int);
                                break;
                            case 2: //Remove an element from structure without read
                                removeFromStackWithoutRead(stkvec_int);
                                break;
                            case 3: //Remove an element from structure with read
                                removeFromStackRead(stkvec_int);
                                break;
                            case 4: //Print the element immediatly accessibile
                                elementImmediatly(stkvec_int);
                                break;
                            case 5: //Test if the structure is empty
                                emptiness(stkvec_int);
                                break;
                            case 6: //Read size of the structure
                                std::cout << ">>> LA SIZE DELLA STRUTTURA E':"<<stkvec_int.Size()<<" <<<"<<std::endl;
                                break;
                            case 7: //Clear the structure
                                stkvec_int.Clear();
                                std::cout << ">>> STRUTTURA SVUOTATA CORRETTAMENTE <<<"<<std::endl;
                                break;
                            case 0: //Exit
                                break;
                        }
                    }while(todo != 0);


                }else if(type_structure == 2){ //Stack Vec of floats
                    lasd::StackVec<float>stkvec_float;
                    generatorStackFloat(dimension, stkvec_float);
                    do {
                        switch(todo = selectActionStructure(todo)){
                            case 1: //Insert an element in the structure
                                insertInStack(stkvec_float);
                                break;
                            case 2: //Remove an element from structure without read
                                removeFromStackWithoutRead(stkvec_float);
                                break;
                            case 3: //Remove an element from structure with read
                                removeFromStackRead(stkvec_float);
                                break;
                            case 4: //Print the element immediatly accessibile
                                elementImmediatly(stkvec_float);
                                break;
                            case 5: //Test if the structure is empty
                                emptiness(stkvec_float);
                                break;
                            case 6: //Read size of the structure
                                std::cout << ">>> LA SIZE DELLA STRUTTURA E':"<<stkvec_float.Size()<<" <<<"<<std::endl;
                                break;
                            case 7: //Clear the structure
                                stkvec_float.Clear();
                                std::cout << ">>> STRUTTURA SVUOTATA CORRETTAMENTE <<<"<<std::endl;
                                break;
                            case 0: //Exit
                                break;
                        }
                    }while(todo != 0);


                }else if(type_structure == 3){ //Stack Vec of strings
                    lasd::StackVec<std::string>stkvec_string;
                    generatorStackString(dimension, stkvec_string);
                    do {
                        switch(todo = selectActionStructure(todo)){
                            case 1: //Insert an element in the structure
                                insertInStack(stkvec_string);
                                break;
                            case 2: //Remove an element from structure without read
                                removeFromStackWithoutRead(stkvec_string);
                                break;
                            case 3: //Remove an element from structure with read
                                removeFromStackRead(stkvec_string);
                                break;
                            case 4: //Print the element immediatly accessibile
                                elementImmediatly(stkvec_string);
                                break;
                            case 5: //Test if the structure is empty
                                emptiness(stkvec_string);
                                break;
                            case 6: //Read size of the structure
                                std::cout << ">>> LA SIZE DELLA STRUTTURA E':"<<stkvec_string.Size()<<" <<<"<<std::endl;
                                break;
                            case 7: //Clear the structure
                                stkvec_string.Clear();
                                std::cout << ">>> STRUTTURA SVUOTATA CORRETTAMENTE <<<"<<std::endl;
                                break;
                            case 0: //Exit
                                break;
                        }
                    }while(todo != 0);

                }
                select_structure = 0;
                break;

            case 3: //Queue List
                std::cout<<">>> HAI SELEZIONATO QUEUE LIST <<<"<<std::endl;
                type_structure = selectTypeStructure();
                selectSizeStructure(dimension);
                if(type_structure == 1){ //Queue List of integers
                    lasd::QueueLst<int>quelis_int;
                    generatorQueueInteger(dimension, quelis_int);
                    do {
                        switch(todo = selectActionStructure(todo)){
                            case 1: //Insert an element in the structure
                                insertInQueue(quelis_int);
                                break;
                            case 2: //Remove an element from structure without read
                                removeFromQueueWithoutRead(quelis_int);
                                break;
                            case 3: //Remove an element from structure with read
                                removeFromQueueRead(quelis_int);
                                break;
                            case 4: //Print the element immediatly accessibile
                                elementImmediatly(quelis_int);
                                break;
                            case 5: //Test if the structure is empty
                                emptiness(quelis_int);
                                break;
                            case 6: //Read size of the structure
                                std::cout << ">>> LA SIZE DELLA STRUTTURA E':"<<quelis_int.Size()<<" <<<"<<std::endl;
                                break;
                            case 7: //Clear the structure
                                quelis_int.Clear();
                                std::cout << ">>> STRUTTURA SVUOTATA CORRETTAMENTE <<<"<<std::endl;
                                break;
                            case 0: //Exit
                                break;
                        }
                    }while(todo != 0);


                }else if(type_structure == 2){ //Queue List of floats
                    lasd::QueueLst<float>quelis_float;
                    generatorQueueFloat(dimension, quelis_float);
                    do {
                        switch(todo = selectActionStructure(todo)){
                            case 1: //Insert an element in the structure
                                insertInQueue(quelis_float);
                                break;
                            case 2: //Remove an element from structure without read
                                removeFromQueueWithoutRead(quelis_float);
                                break;
                            case 3: //Remove an element from structure with read
                                removeFromQueueRead(quelis_float);
                                break;
                            case 4: //Print the element immediatly accessibile
                                elementImmediatly(quelis_float);
                                break;
                            case 5: //Test if the structure is empty
                                emptiness(quelis_float);
                                break;
                            case 6: //Read size of the structure
                                std::cout << ">>> LA SIZE DELLA STRUTTURA E':"<<quelis_float.Size()<<" <<<"<<std::endl;
                                break;
                            case 7: //Clear the structure
                                quelis_float.Clear();
                                std::cout << ">>> STRUTTURA SVUOTATA CORRETTAMENTE <<<"<<std::endl;
                                break;
                            case 0: //Exit
                                break;
                        }
                    }while(todo != 0);


                }else if(type_structure == 3){ //Queue List of strings
                    lasd::QueueLst<std::string>quelis_string;
                    generatorQueueString(dimension, quelis_string);
                    do {
                        switch(todo = selectActionStructure(todo)){
                            case 1: //Insert an element in the structure
                                insertInQueue(quelis_string);
                                break;
                            case 2: //Remove an element from structure without read
                                removeFromQueueWithoutRead(quelis_string);
                                break;
                            case 3: //Remove an element from structure with read
                                removeFromQueueRead(quelis_string);
                                break;
                            case 4: //Print the element immediatly accessibile
                                elementImmediatly(quelis_string);
                                break;
                            case 5: //Test if the structure is empty
                                emptiness(quelis_string);
                                break;
                            case 6: //Read size of the structure
                                std::cout << ">>> LA SIZE DELLA STRUTTURA E':"<<quelis_string.Size()<<" <<<"<<std::endl;
                                break;
                            case 7: //Clear the structure
                                quelis_string.Clear();
                                std::cout << ">>> STRUTTURA SVUOTATA CORRETTAMENTE <<<"<<std::endl;
                                break;
                            case 0: //Exit
                                break;
                        }
                    }while(todo != 0);

                }
                select_structure = 0;
                break;

            case 4: //Queue Vector
                std::cout<<">>> HAI SELEZIONATO QUEUE VECTOR <<<"<<std::endl;
                type_structure = selectTypeStructure();
                selectSizeStructure(dimension);
                if(type_structure == 1){ //Queue Vector of integers
                    lasd::QueueVec<int>quevec_int;
                    generatorQueueInteger(dimension, quevec_int);
                    do {
                        switch(todo = selectActionStructure(todo)){
                            case 1: //Insert an element in the structure
                                insertInQueue(quevec_int);
                                break;
                            case 2: //Remove an element from structure without read
                                removeFromQueueWithoutRead(quevec_int);
                                break;
                            case 3: //Remove an element from structure with read
                                removeFromQueueRead(quevec_int);
                                break;
                            case 4: //Print the element immediatly accessibile
                                elementImmediatly(quevec_int);
                                break;
                            case 5: //Test if the structure is empty
                                emptiness(quevec_int);
                                break;
                            case 6: //Read size of the structure
                                std::cout << ">>> LA SIZE DELLA STRUTTURA E':"<<quevec_int.Size()<<" <<<"<<std::endl;
                                break;
                            case 7: //Clear the structure
                                quevec_int.Clear();
                                std::cout << ">>> STRUTTURA SVUOTATA CORRETTAMENTE <<<"<<std::endl;
                                break;
                            case 0: //Exit
                                break;
                        }
                    }while(todo != 0);

                }else if(type_structure == 2){ //Queue Vector of floats
                    lasd::QueueVec<float>quevec_float;
                    generatorQueueFloat(dimension, quevec_float);
                    do {
                        switch(todo = selectActionStructure(todo)){
                            case 1: //Insert an element in the structure
                                insertInQueue(quevec_float);
                                break;
                            case 2: //Remove an element from structure without read
                                removeFromQueueWithoutRead(quevec_float);
                                break;
                            case 3: //Remove an element from structure with read
                                removeFromQueueRead(quevec_float);
                                break;
                            case 4: //Print the element immediatly accessibile
                                elementImmediatly(quevec_float);
                                break;
                            case 5: //Test if the structure is empty
                                emptiness(quevec_float);
                                break;
                            case 6: //Read size of the structure
                                std::cout << ">>> LA SIZE DELLA STRUTTURA E':"<<quevec_float.Size()<<" <<<"<<std::endl;
                                break;
                            case 7: //Clear the structure
                                quevec_float.Clear();
                                std::cout << ">>> STRUTTURA SVUOTATA CORRETTAMENTE <<<"<<std::endl;
                                break;
                            case 0: //Exit
                                break;
                        }
                    }while(todo != 0);

                }else if(type_structure == 3){ //Queue Vector of strings
                    lasd::QueueVec<std::string>quevec_string;
                    generatorQueueString(dimension, quevec_string);
                    do {
                        switch(todo = selectActionStructure(todo)){
                            case 1: //Insert an element in the structure
                                insertInQueue(quevec_string);
                                break;
                            case 2: //Remove an element from structure without read
                                removeFromQueueWithoutRead(quevec_string);
                                break;
                            case 3: //Remove an element from structure with read
                                removeFromQueueRead(quevec_string);
                                break;
                            case 4: //Print the element immediatly accessibile
                                elementImmediatly(quevec_string);
                                break;
                            case 5: //Test if the structure is empty
                                emptiness(quevec_string);
                                break;
                            case 6: //Read size of the structure
                                std::cout << ">>> LA SIZE DELLA STRUTTURA E':"<<quevec_string.Size()<<" <<<"<<std::endl;
                                break;
                            case 7: //Clear the structure
                                quevec_string.Clear();
                                std::cout << ">>> STRUTTURA SVUOTATA CORRETTAMENTE <<<"<<std::endl;
                                break;
                            case 0: //Exit
                                break;
                        }
                    }while(todo != 0);
                }
                select_structure = 0;
                break;

            case 0: //Exit
                select_structure = 0;
                break;
            default:
                std::cout << "*** SELEZIONE NON VALIDA DELLA STRUTTURA ***" << std::endl;
                break;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    } while (std::cin.fail() || select_structure != 0);
}
