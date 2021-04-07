#include <iostream>
#include "grafo.h"

using namespace std;

int main(){
    int max, valorarestanula;
    cout << "Digite a quantidade maxima de vertices:\n";
    cin >> max;
    cout << "Digite o valor para representar a ausencia de aresta:\n";
    cin >> valorarestanula;
    Grafo grafo1(max, valorarestanula);
    TipoItem item1, item2;
    int opcao, valor, peso;

    do{
        cout << "Digite 0 para parar o algoritmo!\n";
        cout << "Digite 1 para inserir um vertice!\n";
        cout << "Digite 2 para inserir uma aresta!\n";
        cout << "Digite 3 para imprimir o grau de um vertice!\n";
        cout << "Digite 4 para imprimir o peso de uma aresta!\n";
        cout << "Digite 5 para imprimir a matriz de adjacencias!\n";
        cout << "Digite 6 para imprimir a lista de vertices!\n";
        cout << "Digite 7 para realizar uma busca em largura!\n";
        cout << "Digite 8 para realizar uma busca em profundidade!\n";
        cin >> opcao;

        if (opcao == 1){
            cout << "Digite o elemento do vertice que sera inserido:\n";
            cin >> item1;
            grafo1.inserevertice(item1);
        } else if (opcao == 2){
            cout << "Digite o vertice de saida:\n";
            cin >> item1;
            cout << "Digite o vertice de entrada:\n";
            cin >> item2;
            cout << "Digite o peso desta aresta:\n";
            cin >> peso;
            grafo1.inserearesta(item1, item2, peso);
        } else if (opcao == 3){
            cout << "Digite o vertice que sera calculado o grau:\n";
            cin >> item1;
            valor = grafo1.obtergrau(item1);
            cout << "O grau desse vertice e: " << valor << endl;
        } else if (opcao == 4){
            cout << "Digite o vertice de saida:\n";
            cin >> item1;
            cout << "Digite o vertice de entrada:\n";
            cin >> item2;
            valor = grafo1.obterpeso(item1, item2);
            cout << "O peso dessa aresta e: " << valor << endl;
        } else if (opcao == 5){
            grafo1.imprimirmatriz();
        } else if (opcao == 6){
            grafo1.imprimirvertices();
        } else if (opcao == 7){
            cout << "Digite o vertice de origem:\n";
            cin >> item1;
            cout << "Digite o vertice de destino:\n";
            cin >> item2;
            grafo1.buscaemlargura(item1, item2);           
        } else if (opcao == 8){
            cout << "Digite o vertice de origem:\n";
            cin >> item1;
            cout << "Digite o vertice de destino:\n";
            cin >> item2;
            grafo1.buscaemprofundidade(item1, item2);            
        }
    } while (opcao != 0);


    return 0;
}