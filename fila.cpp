#include <iostream>
#include "fila.h"

using namespace std;

    fila::fila() // construtor
    {
        primeiro = 0;
        ultimo = 0;
        estrutura = new TipoItem[max_itens];
    }

    fila::~fila() // destrutor
    {
        delete [] estrutura;
    }

    bool fila::estavazio() //isempty
    {
        return (primeiro == ultimo);
    }

    bool fila::estacheio() //isfull
    {
        return (ultimo-primeiro == max_itens);
    }

    void fila::inserir(TipoItem item) //push //enqueue
    {
        if (estacheio()){
            cout << "A fila esta cheia\n";
            cout << "Esse elemento nao pode ser inserido\n";
        } else{
            estrutura[ultimo % max_itens] = item;
            ultimo++;
        }
    }

    TipoItem fila::remover() //pop //dequeue
    {
        if (estavazio()){
            cout << "A fila esta vazia!\n";
            cout << "Nenhum elemento foi removido!\n";
            return 0;
        } else{
            primeiro++;            
            return estrutura[(primeiro-1) % max_itens];
        }
    }

    void fila::imprimir() //print
    {
        cout << "Fila: [ ";
        for (int i=primeiro ; i<ultimo ; i++){
            cout << estrutura[i % max_itens] << " ";
        }
        cout << "]\n";
    }