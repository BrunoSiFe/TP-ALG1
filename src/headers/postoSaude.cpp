#include "interface/postoSaude.hpp"

using namespace TP;

PostoSaude::PostoSaude() : PostoSaude(0,false){

}

PostoSaude::PostoSaude(int id,bool visitado){
    this->id = id;
    this->visitado = visitado;
}

bool PostoSaude::getVisitado(){
    return this->visitado;
}

int PostoSaude::getId(){
    return this->id;
}

void PostoSaude::setId(int id){
    this->id = id;
}

void PostoSaude::setVisitado(bool visitado){
    this->visitado = visitado;
}
