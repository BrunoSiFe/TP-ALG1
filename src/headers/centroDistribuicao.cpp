#include "interface/centroDistribuicao.hpp"

using namespace TP;

CentroDistribuicao::CentroDistribuicao() : CentroDistribuicao(0)
{
}

CentroDistribuicao::CentroDistribuicao(int id)
{
    this->id = id;
}

CentroDistribuicao::CentroDistribuicao(int id, std::vector<int> postosAdjacentes)
{
    this->id = id;
    this->postosAdjacentes = postosAdjacentes;
}

int CentroDistribuicao::getId()
{
    return this->id;
}

std::vector<int> CentroDistribuicao::getPostosAdjacentes()
{
    return this->postosAdjacentes;
}

void CentroDistribuicao::setId(int id)
{
    this->id = id;
}

void CentroDistribuicao::setPostosAdjacentes(std::vector<int> postosAdjacentes)
{
    this->postosAdjacentes = postosAdjacentes;
}
