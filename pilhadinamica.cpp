#include <iostream>
#include "pilhadinamica.h"
#include <new>
#include <cstddef> //NULL

using namespace std;

    pilhadinamica::pilhadinamica() //construtor //dynamic stack
    {
        NoTopo = NULL;
    }

    pilhadinamica::~pilhadinamica() //destrutor
    {
        No* NoTemp;
        while (NoTopo != NULL){
            NoTemp = NoTopo;
            NoTopo = NoTopo->proximo;
            delete NoTemp;
        }
    }

    bool pilhadinamica::estavazio() //isempty
    {
        return (NoTopo == NULL);
    }

    bool pilhadinamica::estacheio() //tem memória //isfull
    {
        No* NoNovo;
        try{
            NoNovo = new No;
            delete NoNovo;
            return false;
        } catch(std::bad_alloc exception){
            return true;
        }
    }

    void pilhadinamica::inserir(TipoItem item) //push
    {
        if (estacheio()){
            cout << "A Pilha esta cheia!\n";
            cout << "Nao foi possivel inserir este elemento!\n";
        } else{
            No* NoNovo = new No;
            NoNovo->valor = item;
            NoNovo->proximo = NoTopo;
            NoTopo = NoNovo;
        }
    }

    TipoItem pilhadinamica::remover() //pop
    {
        if (estavazio()){
            cout << "A Pilha esta vazia!\n";
            cout << "Nao foi possivel remover nenhum elemento!\n";
            return 0;
        } else{
            No* NoTemp;
            NoTemp = NoTopo;
            TipoItem item = NoTopo->valor;
            NoTopo = NoTopo->proximo;
            delete NoTemp;
            return item;
        }
    }

    void pilhadinamica::imprimir() //print
    {
        No* NoTemp = NoTopo;
        cout << "Pilha: [ ";
        while (NoTemp != NULL){
            cout << NoTemp->valor << " ";
            NoTemp = NoTemp->proximo;
        }
        cout << "]\n";
    }
