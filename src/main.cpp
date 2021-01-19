#include <iostream>
#include <stdlib.h>
#include <vector>
#include "headers/interface/centroDistribuicao.hpp"
#include "headers/interface/postoSaude.hpp"
#include "headers/interface/pilha.hpp"

#define clear system('CLS')

using namespace TP;

int main()
{

    int temperatura = 0, quantidadePostosSaude = 0, quantidadeCentrosDistribuicao = 0;

    std::cin >> quantidadeCentrosDistribuicao;
    std::cin >> quantidadePostosSaude;
    std::cin >> temperatura;

    std::vector<CentroDistribuicao *> vetorCentroDistribuicao;

    for (int i = quantidadeCentrosDistribuicao; i > 0; i--)
    {

        CentroDistribuicao *centro = new CentroDistribuicao(i);

        std::vector<int> postosAdjacentes;

        while ()
        {

            int aux = 0;

            std::cin >> aux;

            postosAdjacentes.push_back(aux);
        }

        centro->setPostosAdjacentes(postosAdjacentes);

        vetorCentroDistribuicao.push_back(centro);
    }

    int **matrizAdjacenciaPostosSaude[quantidadePostosSaude][quantidadePostosSaude];

    int iteracoesMaximas = 0;

    iteracoesMaximas = (-60) - (-90) / temperatura;

    for (int i = 0; i <= vetorCentroDistribuicao.size(); i++)
    {

        vetorPostoAdjacente = vetorCentroDistribuicao[i]->getPostosAdjacentes();

        for (int j = 0; i <= vetorPostoAdjacente.size(); j++)
        {

            

        }
    }

    iteracoesMaximas--;
}

return 0;
}