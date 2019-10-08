#include "findOp.h"

// Funcao que retorna o numero de operacoes necessarias
// Recebe como parametro o tamanho desejado e a lista de beckers disponiveis
int numOp(int ml, LinkedList & sizes) {
    if (ml == 0){
        return 0;
    }

    //Cria-se uma nova lista que vai armazenar as operacoes
    LinkedList newSizes;
    
    //Essa lista é inicializada com os elementos da lista de recipientes
    for (int i=0; i < sizes.size(); i++) {
        newSizes.insertElement(sizes.getElement(i));
    }

    int op = 1;

    //Fica nesse loop ate existir um valor na lista de operacoes igual ao tamanho desejado
    while (1) {
        if (checkWin(ml, newSizes)) {
            return op;

        } else {
            int sizeB = newSizes.size();

            addItems(sizes, newSizes);
            op += 1;

            for (int i = 0; i < sizeB; i++){
                newSizes.removeFirst();                
            }        
        }
    }
}



//Funcao que chega se o tamanho desejado na esta na lista de operacoes
//Recebe como parametro o tamanho e a lista de operacoes
bool checkWin(int ml, LinkedList  & newSizes) {
    for (int i = 0; i < newSizes.size(); i++){
        if (newSizes.getElement(i) == ml) {
            return true;
        }
    }   
    return false;
}



//Funcao que adiciona itens na lista de operacoes somando e subtraindo
void addItems(LinkedList & sizes, LinkedList & newSizes) {

    int nSize = newSizes.size();
    
    for(int i = 0; i < sizes.size(); i++) {

        for (int j= 0; j < nSize; j++) {
            int add = newSizes.getElement(j) + sizes.getElement(i);
            int sub = newSizes.getElement(j) - sizes.getElement(i);

            //Checa se o novo valor calculado com soma e inedito na lista de operacoes
            if (isDifferent(add, newSizes)) {
                newSizes.insertElement(add);  
            }

            //Checa se o novo valor calculado com subtracao e inedito na lista de operacoes
            //Tambem chega se o valor e maior que zero
            if (sub > 0 && sub && isDifferent(sub, newSizes)){
                newSizes.insertElement(sub);
            } 
        }
    } 
}


//Funcao que chega se um determinado valor ja esta na lista
bool isDifferent(int element, LinkedList & newSizes) {
    for (int i = 0; i < newSizes.size(); i++) {
        if (element == newSizes.getElement(i)) {
            return false;
        } 
    }
    return true;
}
