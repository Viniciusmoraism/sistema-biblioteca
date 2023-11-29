#include "InfoLivro.hpp"
#include <iostream>

InfoLivro::InfoLivro(const std::string& nome, const std::string& autor, int edicao, const std::string& genero)
    : _nome(nome), _autor(autor), _genero(genero), _edicao(edicao) {}

InfoLivro::~InfoLivro() {}

std::string InfoLivro::getNome() const {
    return _nome;
}

std::string InfoLivro::getAutor() const {
    return _autor;
}

std::string InfoLivro::getGenero() const {
    return _genero;
}

int InfoLivro::getEdicao() const {
    return _edicao;
}

void InfoLivro::informacoes() const {
    std::cout << "==================================" << std::endl;
    std::cout << "Nome: " << _nome << std::endl;
    std::cout << "Autor: " << _autor << std::endl;
    std::cout << "Edicao: " << _edicao << std::endl;
    std::cout << "Genero: " << _genero << std::endl;
    std::cout << "==================================" << std::endl;
}

bool InfoLivro::operator==(const InfoLivro& outro) const {
    return (_nome == outro._nome && _autor == outro._autor && _genero == outro._genero && _edicao == outro._edicao);
}