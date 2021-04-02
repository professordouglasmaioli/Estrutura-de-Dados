#include <iostream>
#include "aluno.h"

struct No{
    Aluno aluno;
    No* filhoesquerda;
    No* filhodireita;

    int fatorB; //acrescentada
};

class ArvoreAVL{ //novo nome da classe
    private:
    No* raiz;

    public:
    ArvoreAVL(); //mudounome
    ~ArvoreAVL(); //mudounome
    void deletarArvore(No* Noatual);
    No* obterRaiz();
    bool estavazio();
    bool estacheio();
    void inserir(Aluno aluno); //modificada
    void remover(Aluno aluno); // modificada
    void removerbusca(Aluno aluno, No*& noatual, bool& diminuiu); //modificada
    void deletarNo(No*& noatual, bool& diminuiu); // modificada
    void obterSucessor(Aluno& AlunoSucessor, No* temp);
    void buscar(Aluno& aluno, bool& busca);
    void imprimirpreordem(No* Noatual);
    void imprimiremordem(No* Noatual);
    void imprimirposordem(No* Noatual);

    // novos métodos:

    void rotacaodireita(No*& tree);
    void rotacaoesquerda(No*& tree);  
    void rotacaoesquerdadireita(No*& tree);
    void rotacaodireitaesquerda(No*& tree);
    void realizarotacao(No*& tree);
    void insererecursivo(No*& noatual, Aluno aluno, bool& cresceu);

};