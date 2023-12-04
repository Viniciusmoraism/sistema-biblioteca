#include "Professor.hpp"
#include <iostream>

Professor::Professor(const std::string& nome, const std::string& dataIngresso, const std::string& departamento, int senha)
    : Cliente(nome, dataIngresso, senha), _departamento(departamento) {
        _tipoUsuario = "Professor";
        _diasEmprestimo = 14;
    }

Professor::~Professor() {}

std::string Professor::getDepartamento() const {
    return _departamento;
}

std::string Professor::getTipoUsuario() const {
    return _tipoUsuario;
}

void Professor::pagarMulta() {
    /*if (!_livrosAlugados.empty()) {
        for (Livro& livro : _livrosAlugados) {
            bool multaPaga = livro.pagarMulta(getId());  // Chama o método pagarMulta() do livro com o ID do professor
            if (multaPaga) {
                std::cout << "Multa paga para o livro: " << livro.getTitulo() << std::endl;
            }
        }
    } else {*/
        std::cout << "Não há multas para pagar." << std::endl;
   // }
}

//bool Professor::pagarMulta(Livro& livro,) {
  //  return livro.pagarMulta(idUsuario);
//}

 