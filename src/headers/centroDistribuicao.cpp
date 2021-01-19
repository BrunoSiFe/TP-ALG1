#include "interface/centroDistribuicao.hpp"

using namespace TP;

CentroDistribuicao::CentroDistribuicao() : CentroDistribuicao(0){

}

CentroDistribuicao::CentroDistribuicao(int id){
    this->id = id;
}

CentroDistribuicao::CentroDistribuicao(int id,std::vector<int> postosAdjacentes){
    this->id = id;
    this->postosAdjacentes = postosAdjacentes;
}

int CentroDistribuicao::getId(){
    return this->id;
}

void CentroDistribuicao::setId(int id){
    this->id = id;
}
