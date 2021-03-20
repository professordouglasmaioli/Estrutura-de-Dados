#include "aluno.h"

class Hash{
    private:
    int FuncaoHash(Aluno aluno);
    int max_itens;
    int max_posicoes;
    int quant_itens;
    Aluno* estrutura;

    public:
    Hash(int tam_vetor, int max);
    ~Hash();
    bool estacheio();
    int obterTamanhoAtual();
    void inserir(Aluno aluno);
    void deletar(Aluno aluno);
    void buscar(Aluno& aluno, bool& busca);
    void imprimir();
};
