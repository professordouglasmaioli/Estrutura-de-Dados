#include <iostream>
using namespace std;

class Aluno{
    private:
    int ra;
    std::string nome;

    public:
    Aluno();
    Aluno(int r, std::string n);
    string obterNome();
    int obterRa();
};