#include "Copia.hpp"
#include <string>
#include <iostream>
#include <iomanip>

Copia::Copia(int idCopia)
    : _idCopia(idCopia), _emprestimo(-1), _reserva(-1), _dataEmprestimo(""), _dataDevolucao(""),_dataLimiteReserva(""),_multa(0.0) {}

Copia::~Copia() {}

int Copia::getIdCopia() const {
    return _idCopia;
}
int Copia::getReserva() const {
    return _reserva;
}

int Copia::getEmprestimo() const {
    return _emprestimo;
}

bool Copia::isDisponivel() const {
    return _emprestimo == -1;
}

bool Copia::isReservado() const {
    return _reserva != -1;
}

std::string Copia::getDataEmprestimo() const {
    return _dataEmprestimo;
}

std::string Copia::getDataDevolucao() const {
    return _dataDevolucao;
}

std::string Copia::getDataLimiteReserva() const {
    return _dataLimiteReserva;
}

void Copia::setEmprestimo(int emprestimo) {
    _emprestimo = emprestimo;
}

void Copia::setReserva(int reserva) {
    _reserva = reserva;
}

void Copia::setDataEmprestimo(const std::string& dataEmprestimo) {
    _dataEmprestimo = dataEmprestimo;
}

void Copia::setDataDevolucao(const std::string& dataDevolucao) {
    _dataDevolucao = dataDevolucao;
}

void Copia::setDataLimiteReserva(const std::string& dataLimiteReserva) {
    _dataLimiteReserva = dataLimiteReserva;
}

void Copia::informacoes() const {
    std::string temp;
    std::string temp2;
    if (_dataEmprestimo.empty()) {
        temp =  "LIVRE";
    } else {
        temp = _dataEmprestimo;
    }
    if (_dataDevolucao.empty()) {
        temp2 = "LIVRE";
    } else {
        temp2 =  _dataDevolucao;
    }
    std::cout << std::setw(4) << _idCopia << "\t"
              << std::setw(10) << (isDisponivel() ? "SIM" : "NAO") << "\t"
              << std::setw(10) << (isReservado() ? "SIM" : "NAO") << "\t"
              << std::setw(15) << temp << "\t"
              << std::setw(15) << temp2 << std::endl;
    //std::cout << _idCopia << "\t" << (isDisponivel() ? "SIM" : "NAO") << "\t" << (isReservado() ? "SIM" : "NAO") << "\t";

    std::cout << std::endl;
}

double Copia::getMulta() const {
    return _multa;
}
void Copia::setMulta(double multa) {
    _multa = multa;
}