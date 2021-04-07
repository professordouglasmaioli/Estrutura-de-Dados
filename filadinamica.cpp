#include <iostream>
#include "filadinamica.h"
#include <cstddef>
#include <new>

using namespace std;

    filadinamica::filadinamica() // Constructor
    {
        primeiro = NULL;
        ultimo = NULL;
    }

    filadinamica::~filadinamica() // Destrutor
    {
        No* temp;
        while (primeiro != NULL){
            temp = primeiro;
            primeiro = primeiro->proximo;
            delete temp;
        }
        ultimo = NULL;
    }

    bool filadinamica::estavazio() //isEmpty
    {
        return (primeiro == NULL);
    }

    bool filadinamica::estacheio() //isFull
    {
        No* temp;
        try{
            temp = new No;
            delete temp;
            return false;
        } catch(std::bad_alloc exception){
            return true;
        }
    }

    void filadinamica::inserir(TipoItem item) //enqueue //push
    {
        if (estacheio()){
            cout << "A Fila esta cheia!\n";
            cout << "Nao foi possivel inserir este elemento!\n";
        } else{
            No* NoNovo = new No;
            NoNovo->valor = item;
            NoNovo->proximo = NULL;
            if (primeiro == NULL){
                primeiro = NoNovo;
            } else{
                ultimo->proximo = NoNovo;
            }
            ultimo = NoNovo;
        }
    }

    TipoItem filadinamica::remover() //dequeue //pop
    {
        if (estavazio()){
            cout << "A fila esta vazia!\n";
            cout << "Nao tem elemento a ser removido!\n";
            return 0;
        } else{
            No* temp = primeiro;
            TipoItem item = primeiro->valor;
            primeiro = primeiro->proximo;
            if (primeiro == NULL){
                ultimo = NULL;
            }
            delete temp;
            return item;
        }
    }

    void filadinamica::imprimir() //print
    {
        No* temp = primeiro;
        cout << "Fila= [ ";
        while (temp != NULL){
            cout << temp->valor << " ";
            temp = temp->proximo;
        }
        cout << "]\n";
    }