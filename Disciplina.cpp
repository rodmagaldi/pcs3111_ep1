#include "Disciplina.h"
#include <string>

using namespace std;

class Perfil;
class Professor;

Disciplina::Disciplina(string nome, Professor* responsavel, Disciplina* preRequisito): Perfil (0, nome, ""), responsavel (responsavel), preRequisito (preRequisito) {
    this->adicionarSeguidor(responsavel);
}

Disciplina::Disciplina(string nome, Professor* responsavel): Perfil (0, nome, ""), responsavel (responsavel) {
    this->adicionarSeguidor(responsavel);
}

Disciplina::~Disciplina() {
}

Professor* Disciplina::getResponsavel() {
    return this->responsavel;
}

Disciplina* Disciplina::getPreRequisito() {
    if (this->preRequisito != NULL) {
        return this->preRequisito;
    } else {
        return NULL;
    }
}

//void Disciplina::imprimir() {
// cout << "Nome: " << nome << " - Responsavel: " << responsavel->getNome() << endl;
//}

bool Disciplina::adicionarSeguidor(Perfil* seguidor) {
    //caso seja possivel adicionar seguidores
    if (this->quantidadeDeSeguidores < MAXIMO_SEGUIDORES && !conferirSeguidor(seguidor) && seguidor!=this) {
        this->seguidores[quantidadeDeSeguidores] = seguidor;
        this->quantidadeDeSeguidores++;

        return true;
    //caso nao o seja
    } else {
        return false;
    }
}

bool Disciplina::receber(Publicacao* p) {
    return false;
}
