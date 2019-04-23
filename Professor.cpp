#include "Professor.h"

using namespace std;

class Perfil;

Professor::Professor(int numeroUSP, string nome, string email, string departamento): Perfil (numeroUSP, nome, email), departamento (departamento) {
}

Professor::~Professor() {
}

string Professor::getDepartamento(){
    return this->departamento;
}

void Professor::imprimir() {
    cout << "Departamento: " << this->getDepartamento() << endl;
    Perfil::imprimir();
}
