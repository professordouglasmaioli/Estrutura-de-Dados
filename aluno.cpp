#include "aluno.h"

    Aluno::Aluno()
    {
        ra = -1;
        nome = " ";
    }

    Aluno::Aluno(int r, string n)
    {
        ra = r;
        nome = n;
    }

    int Aluno::obterRa()
    {
        return ra;
    }

    string Aluno::obterNome()
    {
        return nome;
    }