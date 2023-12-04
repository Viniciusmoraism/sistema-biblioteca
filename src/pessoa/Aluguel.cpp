#include "Aluguel.hpp"

Aluguel::Aluguel()
    : _idLivro(-1), _idCopia(-1), _renovacoes(0) {}

int Aluguel::getIdLivro() const {
    return _idLivro;
}

int Aluguel::getIdCopia() const {
    return _idCopia;
}

int Aluguel::getRenovacoes() const {
    return _renovacoes;
}

void Aluguel::setIdLivro(int id) {
    _idLivro = id;
}

void Aluguel::setIdCopia(int id) {
    _idCopia = id;
}

void Aluguel::setRenovacoes(int numRenovacoes) {
    _renovacoes = numRenovacoes;
}

bool Aluguel::operator==(const Aluguel& outro) const {
    return _idLivro == outro._idLivro; // && _idCopia == outro._idCopia;
}