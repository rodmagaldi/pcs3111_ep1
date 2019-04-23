#ifndef ALUNO_H
#define ALUNO_H

#include "Perfil.h"
#include <string>

class Aluno : public Perfil
{
    public:
        Aluno(string nome);
        virtual ~Aluno();

    protected:

    private:
};

#endif // ALUNO_H
