#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>

#include "headers/interface/centroDistribuicao.hpp"
#include "headers/interface/postoSaude.hpp"

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

std::vector<int> postosAlcancaveisCentroDistribuicao(std::vector<int> vetorPostosAlcancaveis,
                                                     std::vector<PostoSaude *> vetorPostoSaude, std::vector<CentroDistribuicao *> vetorCentroDistribuicao)
{
    for (long unsigned int i = 0; i < vetorCentroDistribuicao.size(); i++)
    {

        std::vector<int> vetorPostoSaudeAuxiliar;

        vetorPostoSaudeAuxiliar = vetorCentroDistribuicao[i]->getPostosAdjacentes();

        for (long unsigned int j = 0; j < vetorPostoSaudeAuxiliar.size(); j++)
        {
            vetorPostosAlcancaveis.push_back(vetorPostoSaude[vetorPostoSaudeAuxiliar[j] - 1]->getId());
        }
    }

    return vetorPostosAlcancaveis;
}

std::vector<std::vector<int>> gerarListaAdjacencia(std::vector<std::vector<int>> listaAdjacencia)
{
    std::string linha = "";
    getline(std::cin, linha);
    std::istringstream iteracaoStringStream(linha);

    std::vector<int> vetorAuxiliar;

    for (std::string linha; iteracaoStringStream >> linha;)
    {
        vetorAuxiliar.push_back(std::stoi(linha));
    }

    listaAdjacencia.push_back(vetorAuxiliar);

    return listaAdjacencia;
}

std::vector<int> gerarVectorVazio(int tamanho)
{

    std::vector<int> listaZeros;

    for (int i = 0; i <= tamanho; i++)
    {
        listaZeros.push_back(0);
    }

    return listaZeros;
}

std::vector<int> gerarPostosAlcancaveisPosPrimeiraProfundidade(std::vector<int> vetorPostosAlcancaveis, std::vector<int> elementosVisitados,
                                                               std::vector<std::vector<int>> listaAdjacencia, int iteracoesMaximasTemperatura)
{
    std::queue<int> filaPrincipal;
    std::queue<int> filaAuxiliar;

    for (long unsigned int i = 0; i < vetorPostosAlcancaveis.size(); i++)
    {

        filaPrincipal.push(vetorPostosAlcancaveis[i]);
    }

    for (int k = iteracoesMaximasTemperatura; k > 0; k--)
    {
        while (!filaPrincipal.empty())
        {

            int postoAuxiliar = filaPrincipal.front();
            filaPrincipal.pop();

            if (postoAuxiliar != 0)
            {

                if (!elementosVisitados[postoAuxiliar] || elementosVisitados[postoAuxiliar] == 2)
                {
                    if (elementosVisitados[postoAuxiliar] != 2)
                    {

                        vetorPostosAlcancaveis.push_back(postoAuxiliar);
                    }
                    elementosVisitados[postoAuxiliar] = 1;

                    for (long unsigned int j = 0; j < listaAdjacencia[postoAuxiliar].size(); j++)
                    {

                        filaAuxiliar.push(listaAdjacencia[postoAuxiliar][j]);
                    }
                }
            }
        }
        filaPrincipal.swap(filaAuxiliar);
    }

    return vetorPostosAlcancaveis;
}

std::vector<int> gerarPostosAlcancaveis(std::vector<int> vetorPostosAlcancaveis, std::vector<int> elementosVisitados,
                                        std::vector<std::vector<int>> listaAdjacencia, int iteracoesMaximasTemperatura)
{

    vetorPostosAlcancaveis = gerarPostosAlcancaveisPosPrimeiraProfundidade(vetorPostosAlcancaveis, elementosVisitados, listaAdjacencia, iteracoesMaximasTemperatura);

    return vetorPostosAlcancaveis;
}

void resposta(std::vector<int> vetorPostosAlcancaveis)
{
    std::cout << vetorPostosAlcancaveis.size() << std::endl;

    std::sort(vetorPostosAlcancaveis.begin(), vetorPostosAlcancaveis.end());

    if (vetorPostosAlcancaveis.size() != 0)
    {

        for (long unsigned int i = 0; i < vetorPostosAlcancaveis.size(); i++)
        {

            std::cout << vetorPostosAlcancaveis[i] << " ";
        }

        std::cout << std::endl;
    }
    else
    {
        std::cout << "*" << std::endl;
    }
}

bool isCyclicUtil(int posicao, bool postosVisitados[], bool *recStack, std::vector<std::vector<int>> listaAdjacencia)
{

    if (posicao == 0)
    {
        return false;
    }
    if (postosVisitados[posicao] == false)
    {
        postosVisitados[posicao] = true;
        recStack[posicao] = true;

        std::vector<int>::iterator i;
        for (i = listaAdjacencia[posicao].begin(); i != listaAdjacencia[posicao].end(); ++i)
        {
            if (!postosVisitados[*i] && isCyclicUtil(*i, postosVisitados, recStack, listaAdjacencia))
                return true;
            else if (recStack[*i])
                return true;
        }
    }
    recStack[posicao] = false;
    return false;
}

bool isCyclic(int quantidadePostosSaude, std::vector<std::vector<int>> listaAdjacencia)
{
    bool *visited = new bool[quantidadePostosSaude];
    bool *recStack = new bool[quantidadePostosSaude];

    for (int i = 0; i < quantidadePostosSaude; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < quantidadePostosSaude; i++)
        if (isCyclicUtil(i, visited, recStack, listaAdjacencia))
            return true;

    return false;
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

    std::vector<std::vector<int>> listaAdjacencia;

    for (int i = 0; i < quantidadePostosSaude; i++)
    {

        PostoSaude *novoPosto = new PostoSaude();
        novoPosto->setId(i + 1);
        novoPosto->setVisitado(0);

        vetorPostoSaude.push_back(novoPosto);
    }

    std::vector<int> vetorAuxiliar;
    listaAdjacencia.push_back(vetorAuxiliar);

    for (long unsigned int i = 0; i < vetorPostoSaude.size(); i++)
    {

        listaAdjacencia = gerarListaAdjacencia(listaAdjacencia);
    }

    int numeroMaximoPostosAlcancaveis = ((-60) - (-90)) / temperatura;

    std::vector<int> vetorPostosAlcancaveis;

    std::vector<int> elementosVisitados = gerarVectorVazio(listaAdjacencia.size());

    if (numeroMaximoPostosAlcancaveis>1)
    {
        vetorPostosAlcancaveis = postosAlcancaveisCentroDistribuicao(vetorPostosAlcancaveis, vetorPostoSaude, vetorCentroDistribuicao);

        for (long unsigned int i = 0; i < vetorPostosAlcancaveis.size(); i++)
        {

            elementosVisitados[vetorPostosAlcancaveis[i]] = 2;
        }

        vetorPostosAlcancaveis = gerarPostosAlcancaveis(vetorPostosAlcancaveis, elementosVisitados, listaAdjacencia, numeroMaximoPostosAlcancaveis);
    }

    resposta(vetorPostosAlcancaveis);
    std::cout << isCyclic(quantidadePostosSaude, listaAdjacencia) << std::endl;

    return 0;
}