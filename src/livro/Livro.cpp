#include "Livro.hpp"

int Livro::_id = 0;

Livro::Livro(const InfoLivro& infoLivro)
    : _infoLivro(infoLivro), _idLivro(++_id), _idCopia(1) {}

Livro::~Livro() {}

void Livro::adicionarCopia(bool print) {
    Copia novaCopia(_idCopia);
    _copias.push_back(novaCopia);
    if(print) {
    std::cout << "ID: " << _idLivro << "\tCopia: " << _idCopia << std::endl;
    }
    _idCopia++;
}

int Livro::encontrarCopia(int idCopia) const {
    for (size_t i = 0; i < _copias.size(); i++) {
        if (_copias[i].getIdCopia() == idCopia) {
            return i;
        }
    }
    return -1;
}

void Livro::removerCopia(int idCopia) {
    int posicao = encontrarCopia(idCopia);
    if (posicao == -1) {
        std::cout << "A Cópia " << idCopia << " do livro " << _idLivro << " não existe.\n"; 
    } else {
        _copias.erase(_copias.begin() + posicao);
        //std::cout << "Cópia removida com sucesso.\n";
    }
}

void Livro::atualizarReservas() {
    std::tm dataAtual = this->dataAtual();
    
    for (Copia& copia : _copias) {
        std::tm dataLimiteReserva = StrParaTm(copia.getDataLimiteReserva());
        
        if (copia.getDataLimiteReserva() == "" || calcularDifDias(dataLimiteReserva, dataAtual) < 0) {
            copia.setReserva(-1);
            copia.setDataLimiteReserva("");
            copia.setMulta(0.0);
        }
    }
}

void Livro::verAluguel(int idCopia) {
    int posicao = encontrarCopia(idCopia);
    if (posicao == -1) {
        std::cout << "A Cópia " << idCopia << " do livro " << _idLivro << " não existe.\n"; 
    } else {
        atualizarReservas();
        std::cout << "ID: " << _idLivro << std::endl;
        _infoLivro.informacoes();
        std::cout << "Cópia: " << _copias[posicao].getIdCopia() << "\tData do Aluguel: " << _copias[posicao].getDataEmprestimo() << "\tData de Devolução: " << _copias[posicao].getDataDevolucao() << "\tmulta: R$" << calcularMultaTotal(idCopia) << "\t Reservado? " << (_copias[posicao].isReservado() ? "SIM\n" : "NÃO\n");        
    }
}

bool Livro::verReserva(int idCopia, int idUsuario) {
    int posicao = encontrarCopia(idCopia);
    if (posicao == -1) {
        std::cout << "A Cópia " << idCopia << " do livro " << _idLivro << " não existe.\n"; 
        return false;
    } else {
        std::cout << "ID: " << _idLivro << std::endl;
        _infoLivro.informacoes();
        std::cout << "Cópia: " << _copias[posicao].getIdCopia() << "\tData Prevista de Devolução: " << (_copias[posicao].isDisponivel() ? "\tLIVRE " : _copias[posicao].getDataDevolucao());
        if (idUsuario == _copias[posicao].getReserva()) {
            std::cout << "\tLimite da Reserva: " << _copias[posicao].getDataLimiteReserva() << std::endl; 
            return false;
        } else {
            std::cout << "Reserva Expirada. Reserva por outro usuário: " << (_copias[posicao].isReservado() ? "SIM\n" : "NAO\n");
            return true;
        }       
    }
}

void Livro::informacoes() {
    atualizarReservas();
    _infoLivro.informacoes();
    std::cout << "ID: " << getIdLivro() << std::endl;
    //std::cout << "ID\tDisponivel\tReservao\tData Emprestimo\tData Devolução" <<std::endl;
    std::cout << std::setw(4) << "ID Cópia" << "\t"
              << std::setw(10) << "Disponível" << "\t"
              << std::setw(10) << "Reservado" << "\t"
              << std::setw(15) << "Data Empréstimo" << "\t"
              << std::setw(15) << "Data Devolução" << std::endl;
    std::cout << "==================================" << std::endl;
    for (const Copia& copia : _copias) {
        copia.informacoes();
    }
    std::cout << "==================================" << std::endl;
}

int Livro::getTotalDisponiveis() const {
    int count = 0;
    for (const Copia& copia : _copias) {
        if (copia.isDisponivel()) {
            count++;
        }
    }
    return count;
}

int Livro::getTotalReservados() {
    atualizarReservas();
    int count = 0;
    for (const Copia& copia : _copias) {
        if (copia.isReservado()) {
            count++;
        }
    }
    return count;
}

int Livro::getTotalCopias() const {
    return _copias.size();
}

int Livro::getIdLivro() const {
    return _idLivro;
}

InfoLivro Livro::getInfoLivro() const {
    return _infoLivro;
}

std::vector<Copia> Livro::getCopias() {
    atualizarReservas();
    return _copias;
}


//============= métodos auxiliares data ===============

std::tm Livro::dataAtual() {
    std::time_t tempoAtual = std::time(nullptr);
    std::tm* dataAtual = std::localtime(&tempoAtual);

    return *dataAtual; 
}

std::tm Livro::StrParaTm(const std::string& dataString) {
    std::tm tmData = {};

    std::istringstream iss(dataString);
    char delimiter;
    iss >> tmData.tm_mday >> delimiter >> tmData.tm_mon >> delimiter >> tmData.tm_year;

    tmData.tm_mon -= 1; // Ajuste do valor do mês (0-11)
    tmData.tm_year -= 1900; // Ajuste do valor do ano

    return tmData;
}

std::string Livro::TmParaString(const std::tm& tmData) {
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << tmData.tm_mday << '/'
        << std::setfill('0') << std::setw(2) << tmData.tm_mon + 1 << '/'
        << std::setw(4) << tmData.tm_year + 1900;

    return oss.str();
}

int Livro::calcularDifDias(const std::tm& tmData1, const std::tm& tmData2) {
    std::time_t time1 = std::mktime(const_cast<std::tm*>(&tmData1));
    std::time_t time2 = std::mktime(const_cast<std::tm*>(&tmData2));

    const double segundosPorDia = 60 * 60 * 24;
    double diferencaSegundos = std::difftime(time1, time2);

    int diferencaDias = static_cast<int>(diferencaSegundos / segundosPorDia);

    return diferencaDias;
}

std::tm Livro::adicionarDias(const std::tm& data, int nDias) {
    std::tm dataResultante = data;
    dataResultante.tm_mday += nDias;
    std::mktime(&dataResultante);
    return dataResultante;
}

//=========== fim métodos auxiliares data==============

bool Livro::emprestarCopia(int IdUser, int idCopia, int dias) {
    int index = encontrarCopia(idCopia);

    if (index == -1) {
        std::cout << "Cópia não encontrada." << std::endl;
        return false;
    }

    Copia& copia = _copias[index];

    if (!copia.isDisponivel()) {
        std::cout << "A cópia não está disponível para empréstimo." << std::endl;
        return false;
    }

    if (copia.isReservado()) {
        if (IdUser != copia.getReserva()) {
            std::cout << "A cópia está reservada por outro usuário." << std::endl;
            return false;
        }
    }

    copia.setEmprestimo(IdUser);
    copia.setReserva(-1);
    std::tm dataEmprestimo = dataAtual();
    std::tm dataDevolucao = adicionarDias(dataEmprestimo, dias);
    copia.setDataEmprestimo(TmParaString(dataEmprestimo));
    copia.setDataDevolucao(TmParaString(dataDevolucao));

    return true;
}

bool Livro::reservarCopia(int IdUser, int idCopia) {
    int limiteDias = 2;
    int index = encontrarCopia(idCopia);

    if (index == -1) {
        std::cout << "Copia não encontrada." << std::endl;
        return false;
    }

    Copia& copia = _copias[index];

    if (copia.isReservado()) {
        std::cout << "A cópia já está reservada por outro usuário." << std::endl;
        return false;
    }

    if (copia.isDisponivel()) {
        std::tm dataReserva = adicionarDias(dataAtual(), limiteDias);
        copia.setReserva(IdUser);
        copia.setDataLimiteReserva(TmParaString(dataReserva));
    } else {
        std::tm dataDevolucao = StrParaTm(copia.getDataDevolucao());
        std::tm dataLimiteReserva = adicionarDias(dataDevolucao, limiteDias);
        copia.setReserva(IdUser);
        copia.setDataLimiteReserva(TmParaString(dataLimiteReserva));
    }

    return true;
}

bool Livro::renovarCopia(int IdUser, int idCopia, int dias) {
    int index = encontrarCopia(idCopia);

    if (index == -1) {
        std::cout << "Copia não encontrada." << std::endl;
        return false;
    }

    Copia& copia = _copias[index];

    if (copia.isReservado()) {
        if (IdUser != copia.getReserva()) {
            std::cout << "A cópia está reservada por outro usuário." << std::endl;
            return false;
        }
    }

    copia.setEmprestimo(IdUser);
    copia.setReserva(-1);
    std::tm dataEmprestimo = dataAtual();
    std::tm dataDevolucao = adicionarDias(dataEmprestimo, dias);
    copia.setDataEmprestimo(TmParaString(dataEmprestimo));
    copia.setDataDevolucao(TmParaString(dataDevolucao));

    return true;

}

bool Livro::liberarCopia(int idCopia) {
    int index = encontrarCopia(idCopia);

    if (index == -1) {
        std::cout << "Copia não encontrada." << std::endl;
        return false;
    }

    Copia& copia = _copias[index];
    copia.setEmprestimo(-1);
    copia.setDataEmprestimo("");
    copia.setDataDevolucao("");

    if (copia.getDataLimiteReserva() != "") {
        std::tm dataLimiteReserva = adicionarDias(dataAtual(), 2);
        copia.setDataLimiteReserva(TmParaString(dataLimiteReserva));
    }
    return true;
}

// GERANDO MULTA DO USUARIO
double Livro::calcularMultaTotal(int idCopia) {
    int posicao = encontrarCopia(idCopia);
    std::string devolucao = _copias[posicao].getDataDevolucao();
    if(devolucao.empty()) {
        return 0.0;
    } else {
        int difDias = calcularDifDias(dataAtual(), StrParaTm(devolucao));
        if(difDias <= 0) {
            return 0.0;
        } else {
            return  _multaDiaria* difDias;
        }
    }
    
    
    /*
    for (Copia& copia : _copias) {
        if (copia.getEmprestado() && copia.getIdUsuario() == IdUser) {
            std::tm dataDevolucao = StrParaTm(copia.getDataDevolucao());
            std::tm dataAtual = this->dataAtual();
            if (dataDevolucao < dataAtual) {
                int diasAtraso = calcularDifDias(dataDevolucao, dataAtual);
                double multa = diasAtraso * _infoLivro.getMultaDiaria();
                copia.setMulta(multa);
                multaTotal += multa;
            }
        }
    return multaTotal;*/
}

bool Livro::quitarMulta(int IdUser) {
    bool multaQuitada = false;
    for (Copia& copia : _copias) {
        if (copia.getEmprestimo() == IdUser) {
            if (copia.getMulta() > 0.0) {
                copia.setMulta(0.0);
                multaQuitada = true;
            }
        }
    }

    if (multaQuitada) {
        std::cout << "Multa quitada com sucesso.\n";
    } else {
        std::cout << "Não há multa a ser quitada.\n";
    }

    return multaQuitada;
}

bool Livro::pagarMulta(int idCopia, double valor) {
    /*bool multaPaga = false;
    for (Copia& copia : _copias) {
        if (copia.getEmprestado() && copia.getIdUsuario() == IdUser) {
            double multa = copia.getMulta();
            if (multa > 0.0) {
                copia.setMulta(0.0);
                multaPaga = true;
            }
        }
    }
    if (multaPaga) {
        std::cout << "Multa paga com sucesso.\n";
    } else {
        std::cout << "Não há multa a ser paga.\n";
    }*/

    return true;// multaPaga;
}

std::string Livro::getDataDevolucao(int idCopia) {
    int posicao = encontrarCopia(idCopia); 
    if(posicao == -1) {
        return "";
    } else if (_copias[posicao].getDataDevolucao().empty()) {
        return "LIVRE";
    } else {
        return _copias[posicao].getDataDevolucao();
    }
}