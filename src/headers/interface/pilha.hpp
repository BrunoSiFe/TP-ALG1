#ifndef TP_PILHA
#define TP_PILHA

#include "postoSaude.hpp"

namespace TP
{

    class Pilha
    {

    private:
        PostoSaude *primeiroNo;
        PostoSaude *ultimoNo;

    public:
        Pilha();
        Pilha(PostoSaude *primeiroNo, PostoSaude *ultimoNo);

        PostoSaude *getPrimeiroNo();
        PostoSaude *getUltimoNo();

        void setPrimeiroNo(PostoSaude *primeiroNo);
        void setUltimoNo(PostoSaude *ultimoNo);

        PostoSaude *retirarPilha();

        void empilha(PostoSaude *no);
    };
} 

#endif