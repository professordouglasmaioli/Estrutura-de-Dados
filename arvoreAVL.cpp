#include <iostream>
#include <cstddef>
#include "arvoreAVL.h" //modificado

using namespace std;

    ArvoreAVL::ArvoreAVL() // construtor  //mudounome
    {
        raiz = NULL;
    }

    ArvoreAVL::~ArvoreAVL() // destrutor //mudounome
    {
        deletarArvore(raiz);
    }

    void ArvoreAVL::deletarArvore(No* Noatual)
    {
        if (Noatual != NULL){
            deletarArvore(Noatual->filhoesquerda);

            deletarArvore(Noatual->filhodireita);

            delete Noatual;
        }
    }

    No* ArvoreAVL::obterRaiz()
    {
        return raiz;
    }

    bool ArvoreAVL::estavazio()
    {
        return (raiz == NULL);
    }

    bool ArvoreAVL::estacheio()
    {
        try{
            No* temp = new No;
            delete temp;
            return false;
        } catch(bad_alloc exception){
            return true;
        }
    }

    void ArvoreAVL::inserir(Aluno aluno) //modificada
    {
        bool cresceu;
        insererecursivo(raiz, aluno, cresceu);
    }

    void ArvoreAVL::insererecursivo(No*& noatual, Aluno aluno, bool& cresceu)
    { // novo
        if (noatual == NULL) {
            noatual = new No;
            noatual->filhodireita = NULL;
            noatual->filhoesquerda = NULL;
            noatual->aluno = aluno;
            noatual->fatorB = 0;
            cresceu = true;
            return;
        }  
        if (aluno.obterRa() < noatual->aluno.obterRa()) {
            insererecursivo(noatual->filhoesquerda, aluno, cresceu);
            if (cresceu){
                noatual->fatorB-=1;   
            } 
        } else {
            insererecursivo(noatual->filhodireita, aluno, cresceu);
            if (cresceu){
                noatual->fatorB+=1;
            }    
        } 
        realizarotacao(noatual);

        if (cresceu && noatual->fatorB == 0){
            cresceu = false;
        }
    }

    void ArvoreAVL::remover(Aluno aluno) //modificada
    {
        bool diminuiu;
        removerbusca(aluno, raiz, diminuiu);
    }

    void ArvoreAVL::removerbusca(Aluno aluno, No*& noatual, bool& diminuiu)
    { //modificada
        if (aluno.obterRa() < noatual->aluno.obterRa()){
            removerbusca(aluno, noatual->filhoesquerda, diminuiu);
            if (diminuiu){
                noatual->fatorB+=1;
            }
        } else if (aluno.obterRa() > noatual->aluno.obterRa()){
            removerbusca(aluno, noatual->filhodireita, diminuiu);
            if (diminuiu){
                noatual->fatorB-=1;
            }
        } else{
            deletarNo(noatual, diminuiu);
        }
        if (noatual != NULL){
            realizarotacao(noatual);
            if (diminuiu && noatual->fatorB != 0){
                diminuiu = false;
            }
        }
    }

    void ArvoreAVL::deletarNo(No*& noatual, bool& diminuiu)
    {
        No* temp = noatual;
        if (noatual->filhoesquerda == NULL){
            noatual = noatual->filhodireita;
            diminuiu = true;
            delete temp;
        } else if (noatual->filhodireita == NULL){
            noatual = noatual->filhoesquerda;
            diminuiu = true;
            delete temp;
        } else{
            Aluno AlunoSucessor;
            obterSucessor(AlunoSucessor, noatual);
            noatual->aluno = AlunoSucessor;
            removerbusca(AlunoSucessor, noatual->filhodireita, diminuiu);
            if (diminuiu){
                noatual->fatorB-=1;
            }
        }
    }

    void ArvoreAVL::obterSucessor(Aluno& AlunoSucessor, No* temp)
    {
        temp = temp->filhodireita;
        while (temp->filhoesquerda != NULL){
            temp = temp->filhoesquerda;
        }
        AlunoSucessor = temp->aluno;
    }

    void ArvoreAVL::buscar(Aluno& aluno, bool& busca)
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

    void ArvoreAVL::imprimirpreordem(No* Noatual)
    {
        if (Noatual != NULL){
            cout << Noatual->aluno.obterNome() << ": ";
            cout << Noatual->aluno.obterRa() << endl;

            imprimirpreordem(Noatual->filhoesquerda);

            imprimirpreordem(Noatual->filhodireita);
        }
    }

    void ArvoreAVL::imprimiremordem(No* Noatual)
    {
        if (Noatual != NULL){
            imprimiremordem(Noatual->filhoesquerda);

            cout << Noatual->aluno.obterNome() << ": ";
            cout << Noatual->aluno.obterRa() << endl;

            imprimiremordem(Noatual->filhodireita);            
        }
    }

    void ArvoreAVL::imprimirposordem(No* Noatual)
    {
        if (Noatual != NULL){
            imprimirposordem(Noatual->filhoesquerda);

            imprimirposordem(Noatual->filhodireita);

            cout << Noatual->aluno.obterNome() << ": ";
            cout << Noatual->aluno.obterRa() << endl;            
        }
    }





    void ArvoreAVL::rotacaodireita(No*& pai) //novo
    {
        No* novopai = pai->filhoesquerda;
        pai->filhoesquerda = novopai->filhodireita;
        novopai->filhodireita = pai;
        pai = novopai;
    }

    void ArvoreAVL::rotacaoesquerda(No*& pai) //novo
    {
        No* novopai = pai->filhodireita;
        pai->filhodireita = novopai->filhoesquerda;
        novopai->filhoesquerda = pai;
        pai = novopai;
    }

    void ArvoreAVL::rotacaoesquerdadireita(No*& pai)
    {
        No* filho = pai->filhoesquerda;
        rotacaoesquerda(filho);
        pai->filhoesquerda = filho;
        rotacaodireita(pai);
    }


    void ArvoreAVL::rotacaodireitaesquerda(No*& pai)
    {
        No* filho = pai->filhodireita;
        rotacaodireita(filho);
        pai->filhodireita = filho;
        rotacaoesquerda(pai);
    }


    void ArvoreAVL::realizarotacao(No*& pai)
    {
        No* filho;
        No* neto; // Caso precise da rotação dupla

        if (pai->fatorB == -2){ //rotaciona para a direita

        filho = pai->filhoesquerda;

        if (filho->fatorB == -1){ // Simples para a direita
            pai->fatorB = 0;
            filho->fatorB = 0;
            rotacaodireita(pai);
        } else if (filho->fatorB == 0){ // Simples para a direita
            pai->fatorB = -1;
            filho->fatorB = 1;
            rotacaodireita(pai);
        } else if (filho->fatorB == 1){ // Rotação dupla
            neto = filho->filhodireita;
            if (neto->fatorB == -1){
                pai->fatorB = 1;
                filho->fatorB = 0;
            } else if (neto->fatorB == 0){
                pai->fatorB = 0;
                filho->fatorB = 0;                
            } else if (neto->fatorB == 1){
                pai->fatorB = 0;
                filho->fatorB = -1;                
            }
            neto->fatorB = 0; 
            rotacaodireitaesquerda(pai);            
        }



        } else if(pai->fatorB == 2){ //rotaciona para a esquerda
            filho = pai->filhodireita;
            if (filho->fatorB == 1) { // Simples para a esquerda
                pai->fatorB = 0;
                filho->fatorB = 0;
                rotacaoesquerda(pai);
            } else if (filho->fatorB == 0){ // Simples para a esquerda         
                pai->fatorB = 1;
                filho->fatorB = -1;
                rotacaoesquerda(pai);
            } else if (filho->fatorB == -1){ // Rotacao dupla
                neto = filho->filhoesquerda;
                if (neto->fatorB == -1){
                    pai->fatorB =  0;
                    filho->fatorB = 1; 
                } else if (neto->fatorB == 0){
                    pai->fatorB =  0;
                    filho->fatorB = 0; 
                } else if (neto->fatorB == 1){
                    pai->fatorB =  -1;
                    filho->fatorB = 0; 
                }
                neto->fatorB = 0;
                rotacaodireitaesquerda(pai);
            }
        }
    }                  