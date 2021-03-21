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
        while (estrutura[local].obterRa() > 0){
            local = (local+1) % max_posicoes;
        }
        estrutura[local] = aluno;
        quant_itens++;
    }

    void Hash::deletar(Aluno aluno)
    {
        int local = FuncaoHash(aluno);
        bool teste = false;
        while (estrutura[local].obterRa() != -1){
            if (estrutura[local].obterRa() == aluno.obterRa()){
                cout << "Elemento Removido!\n";
                estrutura[local] = Aluno(-2, " ");
                quant_itens--;
                teste = true;
                break;
            }
            local = (local+1) % max_posicoes;
        }
        if (!teste){
            cout << "O elemento nao encontrado!\n";
            cout << "Nenhum elemento foi removido!\n";
        }
    }

    void Hash::buscar(Aluno& aluno, bool& busca)
    {
        int local = FuncaoHash(aluno);
        busca = false;
        while (estrutura[local].obterRa() != -1){
            if (estrutura[local].obterRa() == aluno.obterRa()){
                busca = true;
                aluno = estrutura[local];
                break;
            }
            local = (local+1) % max_posicoes;
        }
    }

    void Hash::imprimir()
    {
        cout << "Tabela Hash:\n";
        for (int i=0 ; i<max_posicoes ; i++){
            if (estrutura[i].obterRa() > 0){
                cout << i << ":" << estrutura[i].obterRa() << " "; 
                cout << estrutura[i].obterNome() << endl;
            }
        }
    }