#include "Secretario.hpp"
#include <iostream>

Secretario::Secretario(const std::string& nome, const std::string& dataIngresso, int senha)
    : Pessoa(nome, dataIngresso,senha) {
        _tipoUsuario = "Secretario";
    }

Secretario::~Secretario() {}

std::string Secretario::getTipoUsuario() const {
    return _tipoUsuario;
}

bool Secretario::quitarMulta(Livro& livro, int idUsuario) {
    return livro.quitarMulta(idUsuario);
}