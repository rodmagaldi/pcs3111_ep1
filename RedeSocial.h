#ifndef REDESOCIAL_H
#define REDESOCIAL_H
#include "Perfil.h"

class Perfil;

class RedeSocial {
public:
  RedeSocial(int numeroMaximoDePerfis);
  virtual ~RedeSocial();

  int getQuantidadeDePerfis();
  Perfil** getPerfis();

  bool adicionar(Perfil* p);
  void imprimir ();

//  void imprimirEstatisticas();
private:
  Perfil** perfis;
  int quantidadeDePerfis = 0;
  int numeroMaximoDePerfis;

  bool checaPerfil(Perfil* perfil);
};

#endif // REDESOCIAL_H
