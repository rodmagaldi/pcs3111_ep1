#include "RedeSocial.h"
#include "Perfil.h"
#include "Publicacao.h"
#include "Professor.h"
#include "Disciplina.h"
#include "Aluno.h"

#include <iostream>
#include <string>

#define MAXIMO_PUBLICACOES 20
#define MAXIMO_SEGUIDORES 20

using namespace std;

void visualizarPerfis(RedeSocial* redeSocial) {
    for (int i = 0; i < redeSocial->getQuantidadeDePerfis(); i++) {
        cout << std::to_string(i+1) << ") " << redeSocial->getPerfis()[i]->getNome() << endl;
    }
}

void terminar(RedeSocial* redeSocial);
void cadastrarPerfil(RedeSocial* redeSocial);
void cadastrarDisciplina(RedeSocial* redeSocial);
void logar(RedeSocial* redeSocial);
void escolherAcao(RedeSocial* redeSocial, Perfil* perfil);
void verPublicacoesFeitas(RedeSocial* redeSocial, Perfil* perfil);
void verPublicacoesRecebidas(RedeSocial* redeSocial, Perfil* perfil);

void escolherOpcao(RedeSocial* redeSocial) {
    int input;
    cout << "Escolha uma opcao: " << endl;
    cout << endl;

    cout << "1) Cadastrar perfil" << endl;
    cout << "2) Cadastrar disciplina" << endl;
    cout << "3) Logar" << endl;
    cout << "0) Terminar" << endl;
    cout << endl;

    cin >> input;
    cout << endl;

    if (input == 1) {
        cout << "=== Cadastrar perfil ===" << endl;

        //chama a funcao para cadastrar um perfil
        cadastrarPerfil(redeSocial);

    } else if (input == 2) {
        cout << "=== Cadastrar disciplina ===" << endl;

        //chama a funcao para cadastrar uma disciplina
        cadastrarDisciplina(redeSocial);

    } else if (input == 3) {
        cout << "=== Logar ===" << endl;

        //chama a funcao para fazer login
        logar(redeSocial);

    } else if (input == 0) {
        cout << "=== Terminar ===" << endl;

        //chama a funcao para terminar
        terminar(redeSocial);

    } else {
        cout << "Escolha umas das alternativas: 1, 2, 3 ou 0." << endl;
        cout << endl;
        escolherOpcao(redeSocial);

    }
}

void cadastrarPerfil(RedeSocial* redeSocial) {
    int nusp;
    string nome;
    string email;
    string prof;
    string dept;

    cout << "Informe os dados do perfil: " << endl;
    cout << endl;

    cout << "Numero USP: ";
    cin >> nusp;
    cout << endl;

    cout << "Nome: ";
    cin.ignore(100, '\n');
    getline(cin, nome);
    cout << endl;

    cout << "E-mail: ";
    getline(cin, email);
    cout << endl;

    cout << "Professor (s/n): ";
    cin >> prof;
    cout << endl;

    if (prof == "n") {
        Perfil* perfilNovo = new Perfil(nusp, nome, email);
        redeSocial->adicionar(perfilNovo);
    }

    else if (prof == "s") {
        cout << "Departamento: ";
        cin >> dept;
        cout << endl;
        Professor* perfilNovo = new Professor(nusp, nome, email, dept);
        redeSocial->adicionar(perfilNovo);
    }

    escolherOpcao(redeSocial);
}

void cadastrarDisciplina(RedeSocial* redeSocial) {
    string nome;
    int nresponsavel;
    Professor* responsavel = NULL;
    int npreRequisito;
    Disciplina* preRequisito = NULL;

    cout << "Informe os dados da disciplina: " << endl;
    cout << endl;

    cout << "Nome: ";
    cin.ignore(100, '\n');
    getline(cin, nome);
    cout << endl;

    cout << "Responsavel: " << endl;
    visualizarPerfis(redeSocial);

    cout << "Digite o numero ou 0 para cancelar: ";
    cin >> nresponsavel;
    cout << endl;


    if (nresponsavel == 0) {
        //cancelamento da acao

        cout << "===== Criacao de disciplina cancelada! =====" << endl;
        cout << endl;
    } else {
        //escolha de um responsavel
        nresponsavel--;

        if (dynamic_cast<Professor*>(redeSocial->getPerfis()[nresponsavel]) != NULL) {
            //caso seja professor

            responsavel = dynamic_cast<Professor*>(redeSocial->getPerfis()[nresponsavel]);

            cout << "Pre-Requisito: " << endl;
            visualizarPerfis(redeSocial);

            cout << "Digite o numero ou 0 para nenhum: ";
            cin >> npreRequisito;
            cout << endl;

            if (npreRequisito == 0) {
                //caso nao haja pre-requisito

                Disciplina* perfilNovo = new Disciplina(nome, responsavel);
                redeSocial->adicionar(perfilNovo);
            } else {
                //caso haja pre-requsito
                npreRequisito--;

                if (dynamic_cast<Disciplina*>(redeSocial->getPerfis()[npreRequisito])!= NULL) {
                    //caso seja valido

                    preRequisito = dynamic_cast<Disciplina*>(redeSocial->getPerfis()[npreRequisito]);
                    Disciplina* perfilNovo = new Disciplina(nome, responsavel, preRequisito);
                    redeSocial->adicionar(perfilNovo);
                } else {
                    //caso seja invalido

                    cout << "O Pre-Requisito deve ser uma disciplina!" << endl;
                    cout << endl;

                }
            }

        } else {
            //caso nao seja professor

            cout << "Somente professores podem ser responsaveis por disciplinas!" << endl;
            cout << endl;
        }
    }
    escolherOpcao(redeSocial);
}

void logar(RedeSocial* redeSocial) {
    int nlogin;
    Perfil* usuarioLogado;

    cout << "Escolha um perfil:" << endl;
    visualizarPerfis(redeSocial);

    cout << "Digite o numero ou 0 para cancelar: ";
    cin >> nlogin;
    cout << endl;

    if (nlogin == 0) {
        cout << "===== Login cancelado =====" << endl;
        cout << endl;

        escolherOpcao(redeSocial);
    } else {
        nlogin--;
        usuarioLogado = redeSocial->getPerfis()[nlogin];
        escolherAcao(redeSocial, usuarioLogado);
    }
}

void escolherAcao(RedeSocial* redeSocial, Perfil* perfil) {
    int nopcao;

    cout << perfil->getNumeroUSP() << " - " << perfil->getNome() << endl;

    if (dynamic_cast<Professor*>(perfil)!= NULL) {
        Professor* prof = dynamic_cast<Professor*>(perfil);
        cout << "Departamento: " << prof->getDepartamento() << endl;
    }

    if (dynamic_cast<Disciplina*>(perfil)!= NULL) {
        Disciplina* disc = dynamic_cast<Disciplina*>(perfil);
        if (disc->getPreRequisito()!= NULL) {
            cout << "Pre-Requisito: " << disc->getPreRequisito()->getNome() << endl;
        } else {
            cout << "Pre-Requisito: -" << endl;
        }
    }

    cout << "Seguidores: " << perfil->getQuantidadeDeSeguidores() << endl;
    cout << "---" << endl;
    cout << "Escolha uma opcao:" << endl;
    cout << "1) Ver publicacoes feitas" << endl;
    cout << "2) Ver publicacoes recebidas" << endl;
    cout << "3) Fazer publicacao" << endl;

    if (dynamic_cast<Disciplina*>(perfil) == NULL) {
        cout << "4) Seguir perfil" << endl;
    }

    cout << "0) Deslogar" << endl;
    cout << endl;

    cin >> nopcao;
    cout << endl;

    if (nopcao == 0) {
        cout << "===== Usuario " << perfil->getNome() << " deslogado! =====" << endl;
        cout << endl;
        logar(redeSocial);
    } else if (nopcao == 1) {
        verPublicacoesFeitas(redeSocial, perfil);
        escolherAcao(redeSocial, perfil);
    } else if (nopcao == 2) {
        verPublicacoesRecebidas(redeSocial, perfil);
    }

}

void verPublicacoesFeitas(RedeSocial* redeSocial, Perfil* perfil) {
    cout << "Publicacoes feitas: " << endl;
    for (int i = 0; i < perfil->getQuantidadeDePublicacoesFeitas(); i++) {
        cout << std::to_string(i+1) << ") " << perfil->getPublicacoesFeitas()[i]->getTexto() << " (" << perfil->getNome() << ") [" << perfil->getPublicacoesFeitas()[i]->getCurtidas() << " curtidas]" << endl;
    }
    cout << endl;
}

void verPublicacoesRecebidas(RedeSocial* redeSocial, Perfil* perfil) {
    int npub;

    cout << "Publicacoes recebidas: " << endl;
    for (int i = 0; i < perfil->getQuantidadeDePublicacoesRecebidas(); i++) {
        cout << std::to_string(i+1) << ") " << perfil->getPublicacoesRecebidas()[i]->getTexto() << " (" << perfil->getPublicacoesRecebidas()[i]->getAutor()->getNome() << ") [" << perfil->getPublicacoesRecebidas()[i]->getCurtidas() << " curtidas]" << endl;
    }

    cout << endl;
    cout << "Digite o numero da mensagem para curtir ou 0 para voltar: ";
    cin >> npub;
    cout << endl;

    if (npub == 0) {
        escolherAcao(redeSocial, perfil);
    } else {
        npub--;
        perfil->getPublicacoesRecebidas()[npub]->curtir(perfil);
        verPublicacoesRecebidas(redeSocial, perfil);
    }
}

void terminar(RedeSocial* redeSocial) {
    delete redeSocial;
}

int main() {

    cout << "Bem vindo ao inicializador de Rede Social." << endl;
    cout << "Qual a capacidade desejada?" << endl;
    cout << endl;

    int capacidade;
    cin >> capacidade;
    cout << endl;

    cout << "===== Rede Social iniciada com capacidade de " + std::to_string(capacidade) +" perfis =====" << endl;
    cout << endl;

    RedeSocial* redeSocial = new RedeSocial(capacidade);

    escolherOpcao(redeSocial);

//  cout << endl << " ===== Cria Moodle" << endl;
//  RedeSocial* moodle = new RedeSocial(100);
//
//  cout << endl << " ===== Cria perfil 1 - Prof. Marcelo" << endl;
//  Professor* profMarcelo = new Professor(1, "Prof. Marcelo", "profmarcelo@pcs.usp.br", "PCS");
//  profMarcelo->imprimir();
//
//  cout << " ===== Cria perfil 2 - Maria Santos" << endl;
//  Perfil* mariaSantos = new Perfil(2, "Maria Santos", "maria.santos@usp.br");
//  mariaSantos->imprimir();
//
//  cout << " ===== Cria perfil 3 - Carlos Costa" << endl;
//  Perfil* carlosCosta = new Perfil(3, "Carlos Costa", "carlos.costa@usp.br");
//  carlosCosta->imprimir();
//
//  cout << " ===== Cria perfil 4 - PCS3111" << endl;
//  Disciplina* pcs3111 = new Disciplina("PCS3111", profMarcelo);
//  pcs3111->imprimir();
//
//  moodle->adicionar(profMarcelo);
//  moodle->adicionar(mariaSantos);
//  moodle->adicionar(carlosCosta);
//  moodle->adicionar(pcs3111);
//
//  cout << " ===== Maria Segue Prof. Marcelo" << endl;
//  profMarcelo->adicionarSeguidor(mariaSantos);
//
//  cout << " ===== Carlos Segue Prof. Marcelo" << endl;
//  profMarcelo->adicionarSeguidor(carlosCosta);
////
////  cout << " ===== Maria Segue PCS3110" << endl;
////  pcs3110->adicionarSeguidor(mariaSantos);
////
////  cout << " ===== Maria Segue PCS3111" << endl;
////  pcs3111->adicionarSeguidor(mariaSantos);
//
//  cout << " ===== Mensagens publicadas" << endl;
//  profMarcelo->publicar("Mensagem 1");
//  mariaSantos->publicar("Mensagem 2");
//  carlosCosta->publicar("Mensagem 3");
//  pcs3111->publicar("Mensagem 4");
//
////  moodle->imprimirEstatisticas();
//
//  moodle->imprimir();
//
//  delete moodle;

  return 0;
}
