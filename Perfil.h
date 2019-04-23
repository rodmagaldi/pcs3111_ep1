#ifndef PERFIL_H
#define PERFIL_H

#include <iostream>
#include <string>
#include "Publicacao.h"
#include "RedeSocial.h"

#define MAXIMO_PUBLICACOES 20
#define MAXIMO_SEGUIDORES 20

using namespace std;

class Publicacao;

class Perfil {
protected:
  string nome;
  string email;
  int numeroUSP;

  Perfil* seguidores[MAXIMO_SEGUIDORES];
  int quantidadeDeSeguidores = 0;

  Publicacao* publicacoesFeitas[MAXIMO_PUBLICACOES];
  int quantidadeDePublicacoesFeitas = 0;

  Publicacao* publicacoesRecebidas[MAXIMO_PUBLICACOES];
  int quantidadeDePublicacoesRecebidas = 0;

  //Confere se o seguidor ja foi adicionado a lista de seguidores. Se sim, ele nao eh adicionado novamente
  bool conferirSeguidor(Perfil* seguidorTeorico);

public:

  //construtor e destrutor
  Perfil(int numeroUSP, string nome, string email);
  virtual ~Perfil();

  int getNumeroUSP();
  string getNome();
  string getEmail();

  //Adiciona um perfil como seguidor deste perfil
  virtual bool adicionarSeguidor(Perfil* seguidor);

  //Faz uma publicacao
  virtual bool publicar(string texto);
  virtual bool publicar(string texto, string data);

  virtual bool receber(Publicacao* p);

  virtual Publicacao** getPublicacoesFeitas();
  virtual int getQuantidadeDePublicacoesFeitas();

  virtual Publicacao** getPublicacoesRecebidas();
  virtual int getQuantidadeDePublicacoesRecebidas();

  virtual Perfil** getSeguidores();
  virtual int getQuantidadeDeSeguidores();

  //imprime o perfil
  virtual void imprimir();
};

#endif // PERFIL_H
