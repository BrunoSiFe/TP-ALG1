#ifndef TP_POSTOSAUDE
#define TP_POSTOSAUDE

namespace TP{
    class PostoSaude{

        private:

            int id;
            bool visitado;

        public:

            PostoSaude();
            PostoSaude(int id, bool visitado);

            int getId();
            bool getVisitado();

            void setVisitado(bool visitado);
            void setId(int id);

    };
}

#endif