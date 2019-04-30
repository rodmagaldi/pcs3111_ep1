#include "RedeSocial.h"
#include "Perfil.h"
#include "Disciplina.h"
#include "Professor.h"

RedeSocial::RedeSocial(int numeroMaximoDePerfis) {
    this->numeroMaximoDePerfis = numeroMaximoDePerfis;
    perfis = new Perfil*[numeroMaximoDePerfis];
}

RedeSocial::~RedeSocial() {
  cout << "Destrutor de RedeSocial: " << quantidadeDePerfis << " perfis" << endl;

  for (int i = 0; i < this->quantidadeDePerfis; i++) {
        delete this->perfis[i];
    }
  delete[] this->perfis;

  cout << "RedeSocial deletada " << endl;
}

Perfil** RedeSocial::getPerfis() {
    return this->perfis;
}

int RedeSocial::getQuantidadeDePerfis() {
    return this->quantidadeDePerfis;
}

bool RedeSocial::adicionar(Perfil* p) {
    if (this->quantidadeDePerfis < this->numeroMaximoDePerfis && !checaPerfil(p)) {
        this->perfis[this->quantidadeDePerfis] = p;
        this->quantidadeDePerfis++;
        return true;
    } else {
        return false;
    }
}

void RedeSocial::imprimir () {
  cout << endl << "------------------------------ " << endl;
  cout << "RedeSocial: " << quantidadeDePerfis << " perfis" << endl;
  cout << "------------------------------ " << endl;
  if (quantidadeDePerfis == 0){
    cout << "Sem perfis" << endl;
    cout << "------------------------------ " << endl;
  } else {
    for (int i = 0; i < quantidadeDePerfis; i++){
      perfis[i]->imprimir();
      cout << "------------------------------ " << endl;
    }
  }
  cout << endl;
}

bool RedeSocial::checaPerfil(Perfil* perfil) {
    for (int i = 0; i < this->quantidadeDePerfis; i++){
        if (this->perfis[i]==perfil) {
            return true;
        }
    }
    return false;
}
