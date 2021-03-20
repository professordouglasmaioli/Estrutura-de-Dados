#include <iostream>
#include "hash.h"

using namespace std;

    int Hash::FuncaoHash(Aluno aluno)
    {
        return (aluno.obterRa() % max_posicoes);
    }

    Hash::Hash(int tam_vetor, int max)
    {
        quant_itens = 0;
        max_itens = max;
        max_posicoes = tam_vetor;
        estrutura = new Aluno[tam_vetor];
    }

    Hash::~Hash()
    {
        delete [] estrutura;
    }

    bool Hash::estacheio()
    {
        return (quant_itens == max_itens);
    }    

    int Hash::obterTamanhoAtual()
    {
        return (quant_itens);
    }

    void Hash::inserir(Aluno aluno)
    {
        int local = FuncaoHash(aluno);
        estrutura[local] = aluno;
        quant_itens++;
    }

    void Hash::deletar(Aluno aluno)
    {
        int local = FuncaoHash(aluno);
        if (estrutura[local].obterRa() != -1){
            estrutura[local] = Aluno(-1, " ");
            quant_itens--;
        }
    }

    void Hash::buscar(Aluno& aluno, bool& busca)
    {
        int local = FuncaoHash(aluno);
        Aluno aux = estrutura[local];
        if (aluno.obterRa() != aux.obterRa()){
            busca = false;
        } else{
            busca = true;
            aluno = aux;
        }

    }

    void Hash::imprimir()
    {
        cout << "Tabela Hash:\n";
        for (int i=0 ; i<max_posicoes ; i++){
            if (estrutura[i].obterRa() != -1){
                cout << i << ":" << estrutura[i].obterRa() << " "; 
                cout << estrutura[i].obterNome() << endl;
            }
        }
    }