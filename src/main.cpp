#include <iostream>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <stack>

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

bool avaliarApenasFalsos(std::vector<bool> avaliarNecessidadeDiminuirAuxiliar)
{
    bool aux = false;

    for (long unsigned int i = 0; i < avaliarNecessidadeDiminuirAuxiliar.size(); i++)
    {
        if (avaliarNecessidadeDiminuirAuxiliar[i] == true)
        {
            aux = true;
        }
    }

    return aux;
}

bool dfs(std::vector<CentroDistribuicao *> vetorCentroDistribuicao,
         std::vector<std::vector<int>> listaAdjacencia, std::vector<int> elementosVisitados)
{

    
    for (long unsigned int j = 0; j < vetorCentroDistribuicao.size(); j++)
    {

        std::stack<int> elementos;

        for (long unsigned int k = 0; k < vetorCentroDistribuicao[j]->getPostosAdjacentes().size(); k++)
        {

            elementos.push(vetorCentroDistribuicao[j]->getPostosAdjacentes()[k]);
        }

        long unsigned int tamanhoOriginal = elementos.size();

        while (!elementos.empty())
        {

            int posicao = elementos.top();
            elementos.pop();

            std::vector<bool> avaliarNecessidadeDiminuirAuxiliar;
            if (elementosVisitados[posicao] == 0)
            {
                elementosVisitados[posicao] = 1;
                for (long unsigned int i = 0; i < listaAdjacencia[posicao].size(); i++)
                {
                    if (listaAdjacencia[posicao][i] != 0)
                    {

                        elementos.push(listaAdjacencia[posicao][i]);
                        avaliarNecessidadeDiminuirAuxiliar.push_back(true);
                    }
                    else if (listaAdjacencia[posicao][i] == 0)
                    {
                        avaliarNecessidadeDiminuirAuxiliar.push_back(false);
                    }
                }
            }
            else if (elementosVisitados[posicao] == 1 && posicao != 0)
            {
                return true;
            }

            if (!avaliarApenasFalsos(avaliarNecessidadeDiminuirAuxiliar) && elementos.size() < tamanhoOriginal)
            {
                elementosVisitados = gerarVectorVazio(elementosVisitados.size());
                tamanhoOriginal--;
            }
        };
    }

    return false;
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

    if (numeroMaximoPostosAlcancaveis == 1)
    {
        vetorPostosAlcancaveis = postosAlcancaveisCentroDistribuicao(vetorPostosAlcancaveis, vetorPostoSaude, vetorCentroDistribuicao);
    }
    else if (numeroMaximoPostosAlcancaveis > 1)
    {

        vetorPostosAlcancaveis = postosAlcancaveisCentroDistribuicao(vetorPostosAlcancaveis, vetorPostoSaude, vetorCentroDistribuicao);

        for (long unsigned int i = 0; i < vetorPostosAlcancaveis.size(); i++)
        {

            elementosVisitados[vetorPostosAlcancaveis[i]] = 2;
        }

        vetorPostosAlcancaveis = gerarPostosAlcancaveis(vetorPostosAlcancaveis, elementosVisitados, listaAdjacencia, numeroMaximoPostosAlcancaveis);
    }

    resposta(vetorPostosAlcancaveis);

    elementosVisitados = gerarVectorVazio(listaAdjacencia.size());

    if (dfs(vetorCentroDistribuicao, listaAdjacencia, elementosVisitados))
    {
        std::cout << "1";
    }
    else
    {
        std::cout << "0";
    }

    return 0;
}