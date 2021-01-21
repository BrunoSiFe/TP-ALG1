#ifndef TP_POSTOSAUDE
#define TP_POSTOSAUDE

#include <vector>

namespace TP
{
    class PostoSaude
    {

    private:
        int id;
        int visitado;
        std::vector<PostoSaude *> postosAdjacentes;

    public:
        PostoSaude();
        PostoSaude(int id, int visitado);

        int getId();
        int getVisitado();
        std::vector<PostoSaude*> getPostosAdjacentes();

        void setVisitado(int visitado);
        void setId(int id);
        void setPostosAdjacentes(std::vector<PostoSaude*> postosAdjacentes);
    };
}

#endif