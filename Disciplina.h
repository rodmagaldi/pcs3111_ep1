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
        void imprimir();

        bool receber(Publicacao* p);
        bool adicionarSeguidor(Perfil* seguidor);

    protected:
        Professor* responsavel;
        Disciplina* preRequisito = NULL;



    private:
};

#endif // DISCIPLINA_H
