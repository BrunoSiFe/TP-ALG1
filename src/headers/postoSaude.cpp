#include "interface/postoSaude.hpp"

using namespace TP;

PostoSaude::PostoSaude() : PostoSaude(0, 0)
{
}

PostoSaude::PostoSaude(int id, int visitado)
{
    this->id = id;
    this->visitado = visitado;
}

int PostoSaude::getVisitado()
{
    return this->visitado;
}

int PostoSaude::getId()
{
    return this->id;
}

std::vector<PostoSaude*> PostoSaude::getPostosAdjacentes()
{
    return this->postosAdjacentes;
}

void PostoSaude::setId(int id)
{
    this->id = id;
}

void PostoSaude::setVisitado(int visitado)
{
    this->visitado = visitado;
}

void PostoSaude::setPostosAdjacentes(std::vector<PostoSaude*> postosAdjacentes)
{
    this->postosAdjacentes = postosAdjacentes;
}