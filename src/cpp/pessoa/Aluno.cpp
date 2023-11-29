#include "Aluno.hpp"
#include <iostream>

Aluno::Aluno(const std::string& nome, const std::string& dataIngresso, const std::string& matricula, const std::string& curso, int senha)
    : Cliente(nome, dataIngresso, senha), _matricula(matricula), _curso(curso) {
        _tipoUsuario = "Aluno";
    }

Aluno::~Aluno() {}

std::string Aluno::getTipoUsuario() const {
    return _tipoUsuario;
}

std::string Aluno::getMatricula() const {
    return _matricula;
}

std::string Aluno::getCurso() const {
    return _curso;
}

void Aluno::pagarMulta()