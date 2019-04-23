#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include "Perfil.h"
#include "Professor.h"

class Perfil;

class Disciplina : public Perfil
{
    public:
        Disciplina(string nome, Professor* responsavel);
        Disciplina(string nome, Professor* responsavel, Disciplina* preRequisito);
        virtual ~Disciplina();

        Professor* getResponsavel();
        Disciplina* getPreRequisito();
//        void imprimir();

    protected:
        Professor* responsavel;
        Disciplina* preRequisito;

        bool adicionarSeguidor(Perfil* seguidor);
        bool receber(Publicacao* p);

    private:
};

#endif // DISCIPLINA_H
