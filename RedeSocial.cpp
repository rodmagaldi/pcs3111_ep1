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

//void RedeSocial::imprimirEstatisticas() {
//    int nalunos = 0 ;
//    int nprofessores = 0;
//    int ndisciplinas = 0;
//    int nperfis = 0;
//    for (int i = 0; i < quantidadeDePerfis; i++) {
//        if (dynamic_cast<Aluno*>(perfis[i])!= NULL) {
//            nalunos++;
//        } else if (dynamic_cast<Professor*>(perfis[i])!= NULL) {
//            nprofessores++;
//        } else if (dynamic_cast<Disciplina*>(perfis[i])!= NULL) {
//            ndisciplinas++;
//        } else {
//            nperfis++;
//        }
//    }
//    cout << endl;
//    cout << "Numero de alunos: " << nalunos <<endl;
//    cout << "Numero de professores: " << nprofessores << endl;
//    cout << "Numero de disciplinas: " << ndisciplinas << endl;
//    cout << "Numero de perfis: " << nperfis << endl;
//}
