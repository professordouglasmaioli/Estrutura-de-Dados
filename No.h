#ifndef NO_H 
#define NO_H 

#include <iostream>

using namespace std;

typedef string TipoItem;

struct No
{
  TipoItem valor;
  No* proximo;
};

#endif