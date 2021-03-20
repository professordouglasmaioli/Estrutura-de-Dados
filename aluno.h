#include <iostream>
using namespace std;

class Aluno{
    private:
    int ra;
    string nome;

    public:
    Aluno();
    Aluno(int r, string n);
    int obterRa();
    string obterNome();
};