#include "Evento.h"

Evento::Evento(Perfil* autor, string data, string texto): Publicacao (autor, texto), data (data) {
}

Evento::~Evento() {
}

string Evento::getData() {
    return this->data;
}
