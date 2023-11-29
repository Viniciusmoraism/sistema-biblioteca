#include "Cliente.hpp"

Cliente::Cliente(const std::string& nome, const std::string& dataIngresso, int senha)
    : Pessoa(nome, dataIngresso, senha) {}

Cliente::~Cliente() {}