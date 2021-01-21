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

    public:
        PostoSaude();
        PostoSaude(int id, int visitado);

        int getId();
        int getVisitado();

        void setVisitado(int visitado);
        void setId(int id);
    };
}

#endif