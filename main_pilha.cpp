#include <iostream>
#include "pilha.h"

using namespace std;

int main(){
    pilha pilha1;
    TipoItem item;
    int opcao;
    cout << "Programa gerador de pilha:\n";

    do {
        cout << "Digite 0 para parar o programa!\n";
        cout << "Digite 1 para inserir um elemento!\n";
        cout << "Digite 2 para remover um elemento!\n";
        cout << "Digite 3 para imprimir a pilha!\n";
        cout << "Digite 4 para ver a quantidade de elementos da pilha " << endl;
        cin >> opcao;
        if (opcao == 1){
            cout << "Digite o elemento a ser inserido:\n";
            cin >> item;
            pilha1.inserir(item);
        } else if (opcao == 2){
            item = pilha1.remover();
            cout << "Elemento Removido: " << item << endl;
        } else if (opcao == 3){
            pilha1.imprimir();
        } else if (opcao == 4)
        {
            cout << "A pilha tem " << pilha1.tamanho() << " elementos" << endl;
        }

    } while(opcao != 0);

    return 0;
}
