#include "test.hpp"

/* ****************************************************************************************************************** */
template <typename Type>
void startPredecessSuccess(lasd::BST<Type>& tree) {
    int select = -1;
    Type data;
    do {
        std::cout << "\n*******************************************************************************" << std::endl;
        std::cout << "*** SELEZIONE IL TIPO DI OPERAZIONE DA EFFETTUARE ***" << std::endl;
        std::cout << "    [1] RIMOZIONE SENZA LETTURA DEL PREDECESSORE" << std::endl;
        std::cout << "    [2] RIMOZIONE CON LETTURA DEL PREDECESSORE" << std::endl;
        std::cout << "    [3] LETTURA NON DISTRUTTIVA DEL PREDECESSORE" << std::endl;
        std::cout << "\n    [4] RIMOZIONE SENZA LETTURA DEL SUCCESSORE" << std::endl;
        std::cout << "    [5] RIMOZIONE CON LETTURA DEL SUCCESSORE" << std::endl;
        std::cout << "    [6] LETTURA NON DISTRUTTIVA DEL SUCCESSORE" << std::endl;
        std::cout << "\n    [0] PER USCIRE E TORNARE AL MENU PRECEDENTE" << std::endl;
        std::cout << "@";
        std::cin >> select;
        if (!std::cin.fail()) {
            switch (select) {
                case 1: {
                    try {
                        std::cout << "@INSERISCI IL DATO: " << std::endl;
                        std::cout << "@";
                        std::cin >> data;
                        if (!std::cin.fail()) {
                            tree.RemovePredecessor(data);
                            std::cout << ">>> PREDECESSORE RIMOSSO CORRETTAMENTE <<<" << std::endl;
                        }
                    } catch (std::length_error e) {

                    }
                }
                break;

                case 2: {
                    try{
                    std::cout << "@INSERISCI IL DATO: " << std::endl;
                    std::cout << "@";
                    std::cin >> data;
                    std::cout << ">>> IL PREDECESSORE E': " << tree.PredecessorNRemove(data)<< " ED E' STATO CORRETTAMENTE RIMOSSO <<<" << std::endl;
                    } catch (std::length_error e) {
                        std::cout << "*** SELEZIONE NON VALIDA ***" << std::endl;
                    }
                }
                break;

                case 3: {
                    try {
                        std::cout << "@INSERISCI IL DATO: " << std::endl;
                        std::cout << "@";
                        std::cin >> data;
                        if (!std::cin.fail()) {
                            std::cout << ">>> IL PREDECESSORE E': " << tree.Predecessor(data) << " <<<" << std::endl;
                        }
                    } catch (std::length_error e) {
                        std::cout << "*** SELEZIONE NON VALIDA ***" << std::endl;
                    }
                }
                    break;

                case 4:
                    try{
                        std::cout << "@INSERISCI IL DATO: " << std::endl;
                        std::cout << "@";
                        std::cin >> data;
                        if (!std::cin.fail()) {
                            tree.RemoveSuccessor(data);
                            std::cout << ">>> SUCCESSORE RIMOSSO CORRETTAMENTE <<<" << std::endl;
                        }
                    }catch (std::length_error e){
                        std::cout << "*** SELEZIONE NON VALIDA ***" << std::endl;
                    }
                    break;

                case 5:
                    try {
                        std::cout << "@INSERISCI IL DATO: " << std::endl;
                        std::cout << "@";
                        std::cin >> data;
                        if (!std::cin.fail()) {
                            std::cout << ">>> IL SUCCESSORE E': " << tree.SuccessorNRemove(data)<< " ED E' STATO CORRETTAMENTE RIMOSSO <<<" << std::endl;
                        }
                    }catch (std::length_error){
                        std::cout << "*** SELEZIONE NON VALIDA ***" << std::endl;
                        }
                    break;

                case 6:
                    try{
                        std::cout << "@INSERISCI IL DATO: " << std::endl;
                        std::cout << "@";
                        std::cin >> data;
                        if (!std::cin.fail()) {
                            std::cout << ">>> IL SUCCESSORE E': " << tree.Successor(data) << " <<<" << std::endl;
                        }
                    }catch (std::length_error e){
                        std::cout << "*** SELEZIONE NON VALIDA ***" << std::endl;
                    }
                    break;

                    case 0:
                        select = 0;
                        return;

                    default :
                        std::cout << "*** SELEZIONE NON VALIDA ***" << std::endl;
                    break;
            }
        }else{
            std::cout<<"*** SELEZIONE NON VALIDA ***"<<std::endl;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }while (std::cin.fail() || select != 0);
}




/* ****************************************************************************************************************** */
template <typename Type>
void startMinimumMaximum(lasd::BST<Type>& tree){
    int select = -1;
    do {
        std::cout << "\n*******************************************************************************" << std::endl;
        std::cout << "*** SELEZIONE IL TIPO DI OPERAZIONE DA EFFETTUARE ***" << std::endl;
        std::cout << "    [1] RIMOZIONE SENZA LETTURA DEL MINIMO" << std::endl;
        std::cout << "    [2] RIMOZIONE CON LETTURA DEL MINIMO" << std::endl;
        std::cout << "    [3] LETTURA NON DISTRUTTIVA DEL MINIMO" << std::endl;
        std::cout << "\n    [4] RIMOZIONE SENZA LETTURA DEL MASSIMO" << std::endl;
        std::cout << "    [5] RIMOZIONE CON LETTURA DEL MASSIMO" << std::endl;
        std::cout << "    [6] LETTURA NON DISTRUTTIVA DEL MASSIMO" << std::endl;
        std::cout << "\n    [0] PER USCIRE E TORNARE AL MENU PRECEDENTE" << std::endl;
        std::cout << "@";
        std::cin >> select;
        if (!std::cin.fail()) {
            switch (select) {
                case 1:
                    try {
                        tree.RemoveMin();
                        std::cout << ">>> MINIMO RIMOSSO CORRETTAMENTE <<<" << std::endl;
                    }catch (std::length_error e){
                        std::cout << "*** SELEZIONE NON VALIDA ***" << std::endl;
                    }
                    break;

                case 2:
                    try{
                        std::cout << ">>> IL MINIMO E': " << tree.MinNRemove() << " ED E' STATO CORRETTAMENTE RIMOSSO <<<"<< std::endl;
                    }catch (std::length_error e){
                        std::cout << "*** SELEZIONE NON VALIDA ***" << std::endl;
                    }
                    break;

                case 3:
                    try{
                        std::cout << ">>> IL MINIMO E': " << tree.Min() << " <<<" << std::endl;
                    }catch (std::length_error e){
                        std::cout << "*** SELEZIONE NON VALIDA ***" << std::endl;
                    }
                    break;

                case 4:
                    try{
                        tree.RemoveMax();
                        std::cout << ">>> MASSIMO RIMOSSO CORRETTAMENTE <<<" << std::endl;
                    }catch (std::length_error e){
                        std::cout << "*** SELEZIONE NON VALIDA ***" << std::endl;
                    }
                    break;

                case 5:
                    try{
                        std::cout << ">>> IL MASSIMO E': " << tree.MaxNRemove() << " ED E' STATO CORRETTAMENTE RIMOSSO <<<"<< std::endl;
                    }catch (std::length_error e){
                        std::cout << "*** SELEZIONE NON VALIDA ***" << std::endl;
                    }
                    break;

                case 6:
                    try{
                        std::cout << ">>> IL MASSIMO E': " << tree.Max() << " <<<" << std::endl;
                    }catch (std::length_error e){
                        std::cout << "*** SELEZIONE NON VALIDA ***" << std::endl;
                    }
                    break;
                case 0:
                    select = 0;
                    return;
            }
        } else {
            std::cout << "*** SELEZIONE NON VALIDA ***" << std::endl;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }while(std::cin.fail() || select != 0);

}




//*** Select the library functions ***//
template <typename Type>
void selectFunctionLibrary(lasd::BST<Type>&tree){
    Type data;
    int enne = -1;
    int type = -1;

    do {
        std::cout<<"\n*******************************************************************************"<<std::endl;
        std::cout<<"*** SELEZIONA UNA DELLE SEGUENTI FUNZIONI DI LIBRERIA ***"<<std::endl;
        std::cout<<"    [1] INSERISCI UN ELEMENTO"<<std::endl;
        std::cout<<"    [2] ELIMINA UN ELEMENTO"<<std::endl;
        std::cout<<"    [3] OPERAZIONI SUL MINIMO/MASSIMO"<<std::endl;
        std::cout<<"    [4] OPERAZIONI SUL PREDECESSORE/SUCCESSORE"<<std::endl;
        std::cout<<"    [0] PER USCIRE E TORNARE AL MENU PRECEDENTE"<<std::endl;
        std::cout<<"@"; std::cin>>enne;

        if(!std::cin.fail()){

            switch (enne) {
                case 1:
                    std::cout<<"@INSERISCI IL DATO DA INSERIRE: "<<std::endl;
                    std::cout<<"@"; std::cin>>data;
                    if (!std::cin.fail()) {
                        tree.Insert(data);
                    }else{
                        std::cout<<"*** INSERIMENTO NON VALIDO ***"<<std::endl;
                    }
                    break;
                case 2:
                    std::cout<<"@INSERISCI IL DATO DA ELIMINARE "<<std::endl;
                    std::cout<<"@"; std::cin>>data;
                    if (!std::cin.fail()) {
                        tree.Remove(data);
                    }else{
                        std::cout<<"*** INSERIMENTO NON VALIDO ***"<<std::endl;
                    }
                    break;
                case 3:
                    startMinimumMaximum(tree);
                    break;
                case 4:
                    startPredecessSuccess(tree);
                    break;
                case 0:
                    enne = 0;
                    break;
                default :
                    std::cout<<"*** SELEZIONE NON VALIDA ***"<<std::endl;
                    break;
            }
        }else{
            std::cout<<"*** SELEZIONE NON VALIDA ***"<<std::endl;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }while(std::cin.fail() || enne != 0);
}
/* ****************************************************************************************************************** */

template <typename Type>
void productIntegers(const Type& elem, const void* dim, void* acc){
    if(elem < (*(int*)dim)){
        (*(int*)acc) = (*(int*)acc)*elem;
    }
}

template <typename Type>
void sumFloats(const Type& elem, const void* dim, void* acc){
    if(elem > (*(int*)dim)){
        (*(float*)acc) = (*(float*)acc)+elem;
    }
}

template <typename Type>
void concatenationStrings(const Type& elem, const void* dim, void* acc){
    if( elem.size() <= (*(int*)dim)){
        (*(std::string*)acc) = ( (*(std::string*)acc)+elem );
    }
}

/* ****************************************************************************************************************** */

//*** Sum of elements less than n of structure (FoldableContainer<int>) using FoldPreOrder function ***//
void operationForStructureTypeFoldInteger(lasd::FoldableContainer<int>& obj, int& n) {
    std::cout << "*** IL PRODOTTO DEGLI INTERI < N ***" << std::endl;
    std::cout << "@INSERISCI N PER LA FUNZIONE FOLD PREVISTA PER LA STRUTTURA" << std::endl;
    std::cout << "@";
    std::cin >> n;
    do {
        const void *dim = &n;
        void *acc = nullptr;
        if (!std::cin.fail() && n > 0) {
            int ac = 1;
            acc = &ac;
            obj.FoldPreOrder(&productIntegers<int>, dim, acc);
            std::cout << ">>> IL PRODOTTO VALE: " << ac << " <<<" << std::endl;

        } else {
            std::cout << "*** VALORE NON VALIDO ***" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    } while (std::cin.fail() || n < 0);
}

//*** Sum of elements greater than n of structure (FoldableContainer<float>) using FoldPreOrder function ***//
void operationForStructureTypeFoldFloat(lasd::FoldableContainer<float>& obj, int& n) {
    std::cout << "*** SOMMA PER I FLOAT > N ***" << std::endl;
    std::cout << "@INSERISCI N PER LA FUNZIONE FOLD PREVISTA PER LA STRUTTURA" << std::endl;
    std::cout << "@";
    std::cin >> n;
    do {
        const void *dim = &n;
        void *acc = nullptr;
        if (!std::cin.fail() && n > 0) {
            float ac = 0;
            acc = &ac;
            obj.FoldPreOrder(&sumFloats<float>, dim, acc);
            std::cout<<">>> LA SOMMA VALE: "<<std::fixed<<ac<<std::endl;
        }else{
            std::cout << "*** VALORE NON VALIDO ***" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }while(std::cin.fail() || n < 0);
}

//*** Concatenation of elements less-equals than n of structure (FoldableContainer<string>) ***//
void operationForStructureTypeFoldString(lasd::FoldableContainer<std::string>& obj, int& n) {
    std::cout << "*** CONCETENAZIONE DELLE STRINGHE CON LUNGHEZZA <= N ***" << std::endl;
    std::cout << "@INSERISCI N PER LA FUNZIONE FOLD PREVISTA PER LA STRUTTURA" << std::endl;
    std::cout << "@";
    std::cin >> n;
    do {
        const void *dim = &n;
        void *acc = nullptr;
        if (!std::cin.fail() && n > 0) {
            std::string ac = "";
            acc = &ac;
            obj.FoldPreOrder(concatenationStrings<std::string>, dim, acc);
            std::cout<<">>> LA CONCATENAZIONE E': "<<ac<<" <<<"<<std::endl;
        }else{
            std::cout<< "*** VALORE NON VALIDO ***" <<std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }while(std::cin.fail() || n < 0);
}

void checkTheExistenceInteger(lasd::TestableContainer<int>& obj){
    int elem;
    do {
        std::cout << "\n@INSERISCI L'ELEMENTO CHE VUOI CERCARE" << std::endl;
        std::cout<<"@"; std::cin>>elem;
        if (!std::cin.fail() && elem > 0) {
            if (obj.Exists(elem)== true) {
                std::cout<<">>> L'ELEMENTO E' PRESENTE <<<"<<std::endl;
            } else {
                std::cout<<">>> L'ELEMENTO NON E' PRESENTE <<<"<<std::endl;
            }
        }else{
            std::cout<<"*** INSERIMENTO NON VALIDO ***"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }while(std::cin.fail() || elem < 0);
}

void checkTheExistenceFloat(lasd::TestableContainer<float>& obj){
    float elem;
    do {
        std::cout << "\n@INSERISCI L'ELEMENTO CHE VUOI CERCARE" << std::endl;
        std::cout<<"@"; std::cin>>elem;
        if (!std::cin.fail() && elem > 0) {
            if (obj.Exists(elem)== true) {
                std::cout<<">>> L'ELEMENTO E' PRESENTE <<<"<<std::endl;
            } else {
                std::cout<<">>> L'ELEMENTO NON E' PRESENTE <<<"<<std::endl;
            }
        }else{
            std::cout<<"*** INSERIMENTO NON VALIDO ***"<<std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }while(std::cin.fail() || elem < 0);
}

void checkTheExistanceString(lasd::TestableContainer<std::string>& obj){
    std::string str ="";
    do {
        std::cout << "\n@INSERISCI L'ELEMENTO CHE VUOI CERCARE" << std::endl;
        std::cout<<"@"; std::cin>>str;
        if (!std::cin.fail() && str != ""){
            if (obj.Exists(str)) {
                std::cout<<">>> L'ELEMENTO E' PRESENTE <<<"<< std::endl;
            } else {
                std::cout<<">>> L'ELEMENTO NON E' PRESENTE <<<"<<std::endl;
            }
        }
    }while(str =="");
}

/* ****************************************************************************************************************** */

//*** Select the operation for the structure ***//
int& selectActionStructure(int& todo){

    std::cout<<"\n*******************************************************************************"<<std::endl;
    std::cout<<"@SELEZIONA L'OPERAZIONE DIGITANDO IL NUMERO DI RIFERIMENTO"<<std::endl;
    std::cout<<"    [1] VISUALIZZAZIONE IN AMPIEZZA (FUNZIONE MAP)"<<std::endl;
    std::cout<<"    [2] VISUALIZZAZIONE IN PRE-ORDINE (FUNZIONE MAP)"<<std::endl;
    std::cout<<"    [3] VISUALIZZAZIONE IN IN-ORDINE (FUNZIONE MAP)"<<std::endl;
    std::cout<<"    [4] VISUALIZZAZIONE IN POST-ORDINE (FUNZIONE MAP)"<<std::endl;
    std::cout<<"    [5] CONTROLLO DI ESISTENZA DI UN VALORE"<<std::endl;
    std::cout<<"    [6] FUNZIONALITA' PREVISTA PER IL TIPO DELLA STRUTTURA (FUNZIONE FOLD)"<<std::endl;
    std::cout<<"    [7] FUNZIONALITA' DI LIBRERIA"<<std::endl;
    std::cout<<"    [0] PER USCIRE E TORNARE AL MENU PRINCIPALE"<<std::endl;
    std::cout<<"@"; std::cin>>todo;
    return todo;
}
/* ****************************************************************************************************************** */

template <typename Type>
void viewInAmpiezzaMap(lasd::BinaryTree<Type>& obj){
    obj.MapBreadth(&printForMap<Type>, nullptr);
}

template <typename Type>
void viewInPreOrdineMap(lasd::BinaryTree<Type>& obj){
    obj.MapPreOrder(&printForMap<Type>, nullptr);
}

template <typename Type>
void viewInInOrdineMap(lasd::BinaryTree<Type>& obj){
    obj.MapInOrder(&printForMap<Type>, nullptr);
}

template <typename Type>
void viewInPostOrdineMap(lasd::BinaryTree<Type>& obj){
    obj.MapPostOrder(&printForMap<Type>, nullptr);
}

/* ****************************************************************************************************************** */

template <typename Type>
void printForMap(Type& elem, void* par){
    std::cout<<std::fixed<<elem<<" ";
}

template <typename Type>
void viewAllElementsMap(lasd::BinaryTree<Type>& obj){
    obj.MapInOrder(&printForMap<Type>, nullptr);
}
/* ****************************************************************************************************************** */

//*** Generator for integers ***//
void generatorBTInteger(const ulong& dimension, lasd::Vector<int>& vector_int){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(7, 100);
    for (ulong i = 0; i < dimension; i++) {
        if(vector_int.Exists(dist(gen)) == false){
            vector_int[i] = dist(gen);
        }else {
            i--;
        }
    }
}

//*** Generator for floats ***//
void generatorBTFloat(const ulong& dimension, lasd::Vector<float>& vector_float){
    std::default_random_engine gen(std::random_device{}());
    std::uniform_real_distribution<float> dist(7, 100);
    for (ulong i = 0; i < dimension; i++) {
        if(vector_float.Exists(dist(gen)) == false){
            vector_float[i] = dist(gen);
        }else {
            i--;
        }
    }
}

//*** Generator for strings ***//
void generatorBTString(const ulong& dimension, lasd::Vector<std::string>& vector_string){
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
        if(vector_string.Exists(s[i]) == false){
            vector_string[i] = s[i];
        }else {
            i--;
        }
    }
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
                return 0;
            default:
                std::cout<<"*** SELEZIONE NON VALIDA DEL TIPO ***"<<std::endl;
                break;
        }
    }while(select_typestructure != 0);
    return select_typestructure;
}

/* ****************************************************************************************************************** */

void start() {
    int type_structure = -1;
    ulong dimension = 0;
    int num = -1;
    int todo = -1;
    do {
        std::cout << "\n***************************** BENVENUTO NEL MENU' *****************************" << std::endl;
                type_structure = selectTypeStructure();
                if (type_structure != 0) {
                    selectSizeStructure(dimension);
                    switch (type_structure) {
                        case 1: {
                            lasd::Vector<int>vector_int(dimension);
                            generatorBTInteger(dimension, vector_int);
                            lasd::BST<int> abr_int(vector_int);

                            viewAllElementsMap(abr_int);

                            do {
                                switch (todo = selectActionStructure(todo)) {
                                    case 1: //MapBreadth
                                        viewInAmpiezzaMap(abr_int);
                                        break;

                                    case 2: //MaPreOrder
                                        viewInPreOrdineMap(abr_int);
                                        break;

                                    case 3: //MapInOrder
                                        viewInInOrdineMap(abr_int);
                                        break;

                                    case 4: //MapPostOrder
                                        viewInPostOrdineMap(abr_int);
                                        break;

                                    case 5: //Exists
                                        checkTheExistenceInteger(abr_int);
                                        break;

                                    case 6: //Funzionalità FOLD
                                        operationForStructureTypeFoldInteger(abr_int, num);
                                        break;


                                    case 7: //Funzionalità di libreria punto 3
                                        selectFunctionLibrary(abr_int);
                                        break;
                                    case 0:
                                        return;
                                }
                            } while (todo != 0);
                        }
                        break;
                        case 2: {
                            lasd::Vector<float> vector_float(dimension);
                            generatorBTFloat(dimension, vector_float);
                            lasd::BST<float> abr_float(vector_float);

                            viewAllElementsMap(abr_float);

                            do {
                                switch (todo = selectActionStructure(todo)) {
                                    case 1: //MapBreadth
                                        viewInAmpiezzaMap(abr_float);
                                        break;

                                    case 2: //MaPreOrder
                                        viewInPreOrdineMap(abr_float);
                                        break;

                                    case 3: //MapInOrder
                                        viewInInOrdineMap(abr_float);
                                        break;

                                    case 4: //MapPostOrder
                                        viewInPostOrdineMap(abr_float);
                                        break;

                                    case 5: //Exists
                                        checkTheExistenceFloat(abr_float);
                                        break;

                                    case 6: //Funzionalità FOLD
                                        operationForStructureTypeFoldFloat(abr_float, num);
                                        break;

                                    case 7: //Funzionalità di libreria punto 3
                                        selectFunctionLibrary(abr_float);
                                        break;
                                    case 0:
                                        return;
                                }
                            } while (todo != 0);
                        }
                            break;
                        case 3: {
                            lasd::Vector <std::string> vector_string(dimension);
                            generatorBTString(dimension, vector_string);
                            lasd::BST<std::string> abr_string(vector_string);

                            viewAllElementsMap(abr_string);

                            do {
                                switch (todo = selectActionStructure(todo)) {
                                    case 1: //MapBreadth
                                        viewInAmpiezzaMap(abr_string);
                                        break;

                                    case 2: //MaPreOrder
                                        viewInPreOrdineMap(abr_string);
                                        break;

                                    case 3: //MapInOrder
                                        viewInInOrdineMap(abr_string);
                                        break;

                                    case 4: //MapPostOrder
                                        viewInPostOrdineMap(abr_string);
                                        break;

                                    case 5: //Exists
                                        checkTheExistanceString(abr_string);
                                        break;

                                    case 6: //Funzionalità FOLD
                                        operationForStructureTypeFoldString(abr_string, num);
                                        break;

                                    case 7: //Funzionalità di libreria punto 3
                                        selectFunctionLibrary(abr_string);
                                        break;
                                    case 0:
                                        return;
                                }
                            } while (todo != 0);
                        }
                            break;

                        case 0:
                            type_structure = 0;
                            break;

                        default :
                            std::cout<<"*** SELEZIONE NON VALIDA ***"<<std::endl;
                            break;
                    }
                }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    } while (std::cin.fail() || type_structure != 0);
}