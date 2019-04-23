#include "Perfil.h"
#include "Evento.h"
#include <iostream>
#include <string>

#define MAXIMO_PUBLICACOES 20
#define MAXIMO_SEGUIDORES 20

using namespace std;

class Publicacao;

//metodos publicos

Perfil::Perfil(int numeroUSP, string nome, string email): numeroUSP (numeroUSP) , nome (nome), email (email) {
}

Perfil::~Perfil(){
    cout << "Destrutor de perfil: " << this->nome << " - Quantidade de publicacoes feitas: " << this->quantidadeDePublicacoesFeitas << endl;

    for (int i = 0; i < this->quantidadeDePublicacoesFeitas; i++) {
        delete this->publicacoesFeitas[i];
    }

    cout << "Perfil deletado" << endl;
};

int Perfil::getNumeroUSP() {
    return this->numeroUSP;
}

string Perfil::getNome() {
    return this->nome;
}

string Perfil::getEmail() {
    return this->email;
}

bool Perfil::adicionarSeguidor(Perfil* seguidor) {
    //caso seja possivel adicionar seguidores
    if (this->quantidadeDeSeguidores < MAXIMO_SEGUIDORES && !conferirSeguidor(seguidor) && seguidor!=this) {
        this->seguidores[quantidadeDeSeguidores] = seguidor;
        this->quantidadeDeSeguidores++;

        //adiciona publicacao a lista de recebidas
        Publicacao* p = new Publicacao(this, "Novo seguidor: " + seguidor->nome);
        this->receber(p);

        return true;
    //caso nao o seja
    } else {
        return false;
    }
}

bool Perfil::publicar(string texto) {

    //caso nao seja possivel publicar
    if (this->quantidadeDePublicacoesFeitas >= MAXIMO_PUBLICACOES) {
        return false;
    //caso seja possivel publicar
    } else {
        //adiciona o texto a lista de publicacoes feitas
        this->publicacoesFeitas[this->quantidadeDePublicacoesFeitas] = new Publicacao(this, texto);
        //adiciona o texto aos seguidores
        if (this->quantidadeDeSeguidores > 0) {
            for (int i = 0; i < quantidadeDeSeguidores; i++) {
                this->seguidores[i]->receber(this->publicacoesFeitas[this->quantidadeDePublicacoesFeitas]);
            }
        }
        //aumenta o contador de publicacoes feitas
        this->quantidadeDePublicacoesFeitas += 1;
        return true;
    }
}

bool Perfil::publicar(string texto, string data) {
    //caso nao seja possivel publicar
    if (this->quantidadeDePublicacoesFeitas >= MAXIMO_PUBLICACOES) {
        return false;
    //caso seja possivel publicar
    } else {
        //adiciona o texto a lista de publicacoes feitas
        this->publicacoesFeitas[this->quantidadeDePublicacoesFeitas] = new Evento(this, data, texto);
        //adiciona o texto aos seguidores
        if (this->quantidadeDeSeguidores > 0) {
            for (int i = 0; i < quantidadeDeSeguidores; i++) {
                this->seguidores[i]->receber(this->publicacoesFeitas[this->quantidadeDePublicacoesFeitas]);
            }
        }
        //aumenta o contador de publicacoes feitas
        this->quantidadeDePublicacoesFeitas += 1;
        return true;
    }
}

bool Perfil::receber(Publicacao* p) {
    if (this->quantidadeDePublicacoesRecebidas >= MAXIMO_PUBLICACOES) {
        return false;
    } else {
        this->publicacoesRecebidas[this->quantidadeDePublicacoesRecebidas] = p;
        this->quantidadeDePublicacoesRecebidas ++;
        return true;
    }
}

Publicacao** Perfil::getPublicacoesFeitas() {
    return this->publicacoesFeitas;
}

int Perfil::getQuantidadeDePublicacoesFeitas() {
    return this->quantidadeDePublicacoesFeitas;
}

Publicacao** Perfil::getPublicacoesRecebidas() {
    return this->publicacoesRecebidas;
}

int Perfil::getQuantidadeDePublicacoesRecebidas() {
    return this->quantidadeDePublicacoesRecebidas;
}

Perfil** Perfil::getSeguidores() {
    return this->seguidores;
}

int Perfil::getQuantidadeDeSeguidores() {
    return this->quantidadeDeSeguidores;
}

void Perfil::imprimir() {
	cout << endl << "Nome: " << nome << endl;
	if (quantidadeDeSeguidores == 0)
		cout << "Sem seguidor"<< endl;
	else {
        for (int j = 0; j<quantidadeDeSeguidores; j++) {
            cout << "Seguidor " << j << " - Nome: " << this->seguidores[j]->nome << endl;
        }
	}
	cout << "Numero de publicacoes feitas: " << quantidadeDePublicacoesFeitas << endl;
	for (int i = 0; i < quantidadeDePublicacoesFeitas; i++)
		cout << "Publicacao " << i << " - Autor: " << publicacoesFeitas[i]->getAutor()->getNome() << " - Texto: " << publicacoesFeitas[i]->getTexto() <<endl;

  cout << "Numero de publicacoes recebidas: " << quantidadeDePublicacoesRecebidas << endl;
  for (int i = 0; i < quantidadeDePublicacoesRecebidas; i++)
		cout << "Publicacao " << i << " - Autor: " << publicacoesRecebidas[i]->getAutor()->getNome() << " - Texto: " << publicacoesRecebidas[i]->getTexto() <<endl;
    cout << endl;

}

//metodos privados ou protegidos

bool Perfil::conferirSeguidor(Perfil* seguidorTeorico) {
    for (int i = 0; i < quantidadeDeSeguidores; i++){
        if (this->seguidores[i]==seguidorTeorico) {
            return true;
        }
    }
    return false;
}
