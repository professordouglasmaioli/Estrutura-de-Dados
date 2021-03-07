// pilha = stack
typedef int TipoItem;
const int max_itens = 100;

class pilha{
    private:
    int tamanho;
    TipoItem* estrutura;

    public:
    pilha(); //construtora //stack
    ~pilha(); //destrutora //~stack
    bool estacheia(); //verifica se a pilha esta cheia //isfull
    bool estavazia(); //verifica se a pilha esta vazia //isempty
    void inserir(TipoItem item); //push
    TipoItem remover(); //pop
    void imprimir(); //print
    int qualtamanho(); //lenght

};