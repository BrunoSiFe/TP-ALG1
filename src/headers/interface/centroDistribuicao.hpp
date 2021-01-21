#ifndef TP_CENTRODISTRIBUICAO
#define TP_CENTRODISTRIBUICAO

#include <vector>

namespace TP
{
    class CentroDistribuicao
    {

    private:
        int id;
        std::vector<int> postosAdjacentes;

    public:
        CentroDistribuicao();
        CentroDistribuicao(int id);
        CentroDistribuicao(int id, std::vector<int> postosAdjacentes);

        int getId();
        std::vector<int> getPostosAdjacentes();

        void setId(int id);
        void setPostosAdjacentes(std::vector<int> postosAdjacentes);
    };
} 

#endif