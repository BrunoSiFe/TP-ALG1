#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>

#include "headers/interface/centroDistribuicao.hpp"
#include "headers/interface/postoSaude.hpp"
#include "headers/interface/pilha.hpp"

#define clear system('CLS')

using namespace TP;

std::vector<CentroDistribuicao *> receberDadosCentroDistribuicao(std::vector<CentroDistribuicao *> vetorCentroDistribuicao, int quantidadeCentrosDistribuicao)
{

    for (int i = 0; i < quantidadeCentrosDistribuicao; i++)
    {

        CentroDistribuicao *novoCentro = new CentroDistribuicao();

        std::string linha = "";
        getline(std::cin, linha);
        std::istringstream iteracaoStringStream(linha);

        std::vector<int> vetorAuxiliarPostosAdjacentesCentros;

        for (std::string linha; iteracaoStringStream >> linha;)
        {
            vetorAuxiliarPostosAdjacentesCentros.push_back(std::stoi(linha));
        }

        novoCentro->setId(i + 1);
        novoCentro->setPostosAdjacentes(vetorAuxiliarPostosAdjacentesCentros);

        vetorCentroDistribuicao.push_back(novoCentro);
    }

    return vetorCentroDistribuicao;
}

std::vector<PostoSaude *> receberDadosPostosSaude(std::vector<PostoSaude *> vetorPostoSaude, int quantidadePostosSaude)
{

    PostoSaude *novoPosto = new PostoSaude();
    for (int i = 0; i < quantidadePostosSaude; i++)
    {

        novoPosto->setId(i + 1);

        vetorPostoSaude.push_back(novoPosto);
    }
    for (int i = 0; i <= quantidadePostosSaude; i++)
    {

        std::string linha = "";
        getline(std::cin, linha);
        std::istringstream iteracaoStringStream(linha);

        std::vector<PostoSaude *> vetorAuxiliarPostosAdjacentesPostos;

        for (std::string linha; iteracaoStringStream >> linha;)
        {
            vetorAuxiliarPostosAdjacentesPostos.push_back(vetorPostoSaude[std::stoi(linha)]);
        }

        novoPosto->setPostosAdjacentes(vetorAuxiliarPostosAdjacentesPostos);
    }

    return vetorPostoSaude;
}

std::vector<PostoSaude *> postosAlcancaveisCentroDistribuicao(std::vector<PostoSaude *> vetorPostosAlcancaveis,
                                                              std::vector<PostoSaude *> vetorPostosSaude, std::vector<CentroDistribuicao *> vetorCentroDistribuicao)
{
    for (long unsigned int i = 0; i < vetorCentroDistribuicao.size(); i++)
    {

        std::vector<int> vetorPostoSaudeAuxiliar;

        vetorPostoSaudeAuxiliar = vetorCentroDistribuicao[i]->getPostosAdjacentes();

        for (long unsigned int j = 0; j < vetorPostoSaudeAuxiliar.size(); j++)
        {
            vetorPostosAlcancaveis.push_back(vetorPostosSaude[vetorPostoSaudeAuxiliar[j]]);
        }
    }

    return vetorPostosAlcancaveis;
}

int main()
{

    int temperatura = 0, quantidadePostosSaude = 0, quantidadeCentrosDistribuicao = 0;

    std::cin >> quantidadeCentrosDistribuicao;
    std::cin >> quantidadePostosSaude;
    std::cin >> temperatura;

    std::vector<CentroDistribuicao *> vetorCentroDistribuicao;

    std::cin.ignore(INT64_MAX, '\n');

    vetorCentroDistribuicao = receberDadosCentroDistribuicao(vetorCentroDistribuicao, quantidadeCentrosDistribuicao);

    std::vector<PostoSaude *> vetorPostoSaude;

    vetorPostoSaude = receberDadosPostosSaude(vetorPostoSaude, quantidadePostosSaude);

    int numeroMaximoPostosAlcancaveis = ((-60) - (-90)) / temperatura;

    std::vector<PostoSaude *> vetorPostosAlcancaveis;

    vetorPostosAlcancaveis = postosAlcancaveisCentroDistribuicao()

    int a = 1 + 1;

    return 0;
}