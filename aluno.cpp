#include "aluno.h"
using namespace std;

    Aluno::Aluno()
    {
        ra = -1;
        nome = " ";
    }

    Aluno::Aluno(int r, std::string n)
    {
        ra = r;
        nome = n;
    }

    string Aluno::obterNome()
    {
        return nome;
    }

    int Aluno::obterRa()
    {
        return ra;
    }