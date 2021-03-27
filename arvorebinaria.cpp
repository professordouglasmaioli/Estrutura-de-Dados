#include <iostream>
#include <cstddef>
#include "arvorebinaria.h"

using namespace std;

    ArvoreBinariadeBusca::ArvoreBinariadeBusca() // construtor
    {
        raiz = NULL;
    }

    ArvoreBinariadeBusca::~ArvoreBinariadeBusca() // destrutor
    {
        deletarArvore(raiz);
    }

    void ArvoreBinariadeBusca::deletarArvore(No* Noatual)
    {
        if (Noatual != NULL){
            deletarArvore(Noatual->filhoesquerda);

            deletarArvore(Noatual->filhodireita);

            delete Noatual;
        }
    }

    No* ArvoreBinariadeBusca::obterRaiz()
    {
        return raiz;
    }

    bool ArvoreBinariadeBusca::estavazio()
    {
        return (raiz == NULL);
    }

    bool ArvoreBinariadeBusca::estacheio()
    {
        try{
            No* temp = new No;
            delete temp;
            return false;
        } catch(bad_alloc exception){
            return true;
        }
    }

    void ArvoreBinariadeBusca::inserir(Aluno aluno)
    {
        if (estacheio()){
            cout << "A Arvore esta cheia!\n";
            cout << "Nao foi possivel inserir este elemento!\n";
        } else{
            No* NoNovo = new No;
            NoNovo->aluno = aluno;
            NoNovo->filhodireita = NULL;
            NoNovo->filhoesquerda = NULL;
            if (raiz == NULL){
                raiz = NoNovo;
            } else{
                No* temp = raiz;
                while (temp != NULL){
                    if (aluno.obterRa() < temp->aluno.obterRa()){
                        if (temp->filhoesquerda == NULL){
                            temp->filhoesquerda = NoNovo;
                            break;
                        } else{
                            temp = temp->filhoesquerda;
                        }
                    } else{
                        if (temp->filhodireita == NULL){
                            temp->filhodireita = NoNovo;
                            break;
                        } else{
                            temp = temp->filhodireita;
                        }
                    }
                }
            }
        }
    }

    void ArvoreBinariadeBusca::remover(Aluno aluno)
    {
        removerbusca(aluno, raiz);
    }

    void ArvoreBinariadeBusca::removerbusca(Aluno aluno, No*& noatual)
    {
        if (aluno.obterRa() < noatual->aluno.obterRa()){
            removerbusca(aluno, noatual->filhoesquerda);
        } else if (aluno.obterRa() > noatual->aluno.obterRa()){
            removerbusca(aluno, noatual->filhodireita);
        } else{
            deletarNo(noatual);
        }
    }

    void ArvoreBinariadeBusca::deletarNo(No*& noatual)
    {
        No* temp = noatual;
        if (noatual->filhoesquerda == NULL){
            noatual = noatual->filhodireita;
            delete temp;
        } else if (noatual->filhodireita == NULL){
            noatual = noatual->filhoesquerda;
            delete temp;
        } else{
            Aluno AlunoSucessor;
            obterSucessor(AlunoSucessor, noatual);
            noatual->aluno = AlunoSucessor;
            removerbusca(AlunoSucessor, noatual->filhodireita);
        }
    }

    void ArvoreBinariadeBusca::obterSucessor(Aluno& AlunoSucessor, No* temp)
    {
        temp = temp->filhodireita;
        while (temp->filhoesquerda != NULL){
            temp = temp->filhoesquerda;
        }
        AlunoSucessor = temp->aluno;
    }

    void ArvoreBinariadeBusca::buscar(Aluno& aluno, bool& busca)
    {
        busca = false;
        No* noatual = raiz;
        while (noatual != NULL){
            if (aluno.obterRa() < noatual->aluno.obterRa()){
                noatual = noatual->filhoesquerda;
            } else if (aluno.obterRa() > noatual->aluno.obterRa()){
                noatual = noatual->filhodireita;
            } else{
                busca = true;
                aluno = noatual->aluno;
                break;
            }
        }
    }

    void ArvoreBinariadeBusca::imprimirpreordem(No* Noatual)
    {
        if (Noatual != NULL){
            cout << Noatual->aluno.obterNome() << ": ";
            cout << Noatual->aluno.obterRa() << endl;

            imprimirpreordem(Noatual->filhoesquerda);

            imprimirpreordem(Noatual->filhodireita);
        }
    }

    void ArvoreBinariadeBusca::imprimiremordem(No* Noatual)
    {
        if (Noatual != NULL){
            imprimiremordem(Noatual->filhoesquerda);

            cout << Noatual->aluno.obterNome() << ": ";
            cout << Noatual->aluno.obterRa() << endl;

            imprimiremordem(Noatual->filhodireita);            
        }
    }

    void ArvoreBinariadeBusca::imprimirposordem(No* Noatual)
    {
        if (Noatual != NULL){
            imprimirposordem(Noatual->filhoesquerda);

            imprimirposordem(Noatual->filhodireita);

            cout << Noatual->aluno.obterNome() << ": ";
            cout << Noatual->aluno.obterRa() << endl;            
        }
    }
