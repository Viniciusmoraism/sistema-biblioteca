#include "Cliente.hpp"

Cliente::Cliente(const std::string& nome, const std::string& dataIngresso, int senha)
    : Pessoa(nome, dataIngresso, senha) {}

Cliente::~Cliente() {}

void Cliente::consultarLivrosAlugados(std::vector<Livro>& acervo) {
    std::cout << "Livros alugados pelo " << getTipoUsuario() << " " << getNome() << " (ID: " << getIdUser() << "):" << std::endl;
    bool encontrado = false;
    for (int i = 0; i < _limite; i++) {
        int posicao = encontrarLivro(_alugueis[i].getIdLivro(), acervo);
        if (posicao != -1 && _alugueis[i].getRenovacoes() > 0) {
            acervo[posicao].verAluguel(_alugueis[i].getIdCopia());
            encontrado = true;
        }
    }

    if (!encontrado) {
        std::cout << "Nenhum livro alugado pelo usuário " << getIdUser() << std::endl;
    }
}

void Cliente::consultarLivrosReservados(std::vector<Livro>& acervo) {
    std::cout << "Livros reservados pelo " << getTipoUsuario() << " " << getNome() << " (ID: " << getIdUser() << "):" << std::endl;
    bool encontrado = false;
    for (int i = 0; i < _limite; i++) {
        bool expirado = false;
        int posicao = encontrarLivro(_alugueis[i].getIdLivro(), acervo);
        if (posicao != -1 && _alugueis[i].getRenovacoes() == 0) {
            expirado = acervo[posicao].verReserva(_alugueis[i].getIdCopia(), getIdUser());
            encontrado = true;
            if(expirado) {
                _alugueis[i].setIdLivro(-1);
            }
        }
    }
    if (!encontrado) {
        std::cout << "Nenhum livro reservado pelo usuário " << getIdUser() << std::endl;
    }
}

int Cliente::checarAlugueis(const int idLivro) {
    for(int i = 0; i < _limite; i++) {
        if(_alugueis[i].getIdLivro() == idLivro) {
            std::cout << "Reserva não permitida devido ao usuário já ter um aluguel ou reserva deste Livro.\n";
            return -1;
        }
    }

    for(int i = 0; i < _limite; i++) {
        if(_alugueis[i].getIdLivro() == -1) {
            return i;
        }
    }
    std::cout << "Reserva não permitida devio ao limite de reservas e alugueis já ter sido atingido.\n";
    return -1;
}


void Cliente::reservarLivro(const int idLivro, int idCopia, std::vector<Livro>& acervo) {
    int posicaoAluguel = checarAlugueis(idLivro);
    if(posicaoAluguel == - 1) {
        return;
    }    

    int posicao = encontrarLivro(idLivro, acervo);
    if (posicao != -1) {
        if( acervo[posicao].reservarCopia(getIdUser(), idCopia)) {
            std::cout << "Livro reservado com sucesso." << std::endl;
            _alugueis[posicaoAluguel].setIdLivro(idLivro);
            _alugueis[posicaoAluguel].setIdCopia(idCopia);
            _alugueis[posicaoAluguel].setRenovacoes(0);
            return;
        } else {
            std::cout << "Não foi possível reservar o livro." << std::endl;
            return;
        }
    }
    std::cout << "Livro não encontrado." << std::endl;
    return;
}

void Cliente::renovarEmprestimo(const int idLivro, std::vector<Livro>& acervo) {

    int limiteRenovacao = 2;
    int posicaoAluguel = -1;
        for(int i = 0; i < _limite; i++) {
            if(_alugueis[i].getIdLivro() == idLivro) {
                if(_alugueis[i].getRenovacoes() == limiteRenovacao) {
                    std::cout << "Não é possível renovar novamente. É necessário realizar outro empréstimo na Biblioteca.\n";
                    return;
                } else {
                    posicaoAluguel = i;
                }
            }  
        }
    int posicao = encontrarLivro(idLivro, acervo);
    if (posicao != -1) {
        if(acervo[posicao].renovarCopia(getIdUser(), _alugueis[posicaoAluguel].getIdCopia(), _diasEmprestimo)) {
            _alugueis[posicaoAluguel].setRenovacoes(_alugueis[posicaoAluguel].getRenovacoes() +1);
            std::cout << "Empréstimo renovado com sucesso." << std::endl;
            return;
        } else {
            std::cout << "Não foi possível renovar o empréstimo." << std::endl;
            return;
        }
    } 
    std::cout << "Livro não encontrado." << std::endl;
}

void Cliente::liberarAluguel(int idLivro) {
    int posicao = -1;
    for(int i = 0; i < _limite; i++) {
        if(idLivro == _alugueis[i].getIdLivro()) {
            posicao = i;
        }
    }
    if(posicao == -1) {
        return;
    } else { return;
        /*_alugueis[posicao].setIdCopia() = -1;
        _alugueis[posicao].setIdLivro() = -1;
        _alugueis[posicao].setRenovacoes() = 0;*/
    }
    
}

void Cliente::setAlugueis(const Aluguel* alugueis, int tamanho) {
    // Certifique-se de que o tamanho fornecido seja menor ou igual ao limite
    if (tamanho <= _limite) {
        // Copie os alugueis para o vetor _alugueis
        for (int i = 0; i < tamanho; i++) {
            _alugueis[i] = alugueis[i];
        }
    } else {
        // Caso o tamanho fornecido seja maior que o limite, exiba uma mensagem de erro
        std::cout << "Erro: O tamanho fornecido excede o limite de alugueis." << std::endl;
    }
}