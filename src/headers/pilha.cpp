#include "interface/pilha.hpp"

using namespace TP;

Pilha::Pilha() : Pilha(new PostoSaude(),new PostoSaude()){

}

Pilha::Pilha(PostoSaude* primeiroNo,PostoSaude* ultimoNo){
    this->primeiroNo = primeiroNo;
    this->ultimoNo = ultimoNo;
}

PostoSaude* Pilha::getUltimoNo(){
    return this->ultimoNo;
}

PostoSaude* Pilha::getPrimeiroNo(){
    return this->primeiroNo;
}

void Pilha::setPrimeiroNo(PostoSaude* primeiroNo){
    this->primeiroNo = primeiroNo;
}

void Pilha::setUltimoNo(PostoSaude* ultimoNo){
    this->ultimoNo = ultimoNo;
}
