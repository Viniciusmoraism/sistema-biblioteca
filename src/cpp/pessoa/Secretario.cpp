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

void Secretario::cadastrarAluno(const std::string& nome, const std::string& dataIngresso, const std::string& matricula, std::string& curso, std::vector<Cliente*>& usuarios) {
    Aluno* aluno = new Aluno(nome, dataIngresso, matricula, curso);
    usuarios.push_back(aluno);
    std::cout << "Aluno cadastrado: " << aluno->getNome() << "\nID: " << aluno->getIdUser() << "\nSenha: " << aluno->getSenha() << std::endl;
}

void Secretario::cadastrarProfessor(const std::string& nome, const std::string& dataIngresso, const std::string& departamento, std::vector<Cliente*>& usuarios) {
    Professor* professor = new Professor(nome, dataIngresso, departamento);
    usuarios.push_back(professor);
    std::cout << "Professor cadastrado: " << professor->getNome() <<  "\nID: " << professor->getIdUser() << "\nSenha: " << professor->getSenha() << std::endl;
}

int Secretario::encontrarCliente(const int idUser, std::vector<Cliente*>& usuarios) const {

    for (size_t i = 0; i < usuarios.size(); ++i) {
        if (usuarios[i]->getIdUser() == idUser) {
            return i;
        }
    }
    return -1;
}

void Secretario::emprestarLivro(int idUser, int idLivro, int idCopia, std::vector<Livro>& acervo, std::vector<Cliente*>& usuarios) {
    int posicaoLivro = encontrarLivro(idLivro, acervo);
    int posicaoPessoa = encontrarCliente(idUser, usuarios);
    if (posicaoLivro == -1) {
        std::cout << "Livro não encontrado no acervo." << std::endl;
        return;
    }
    if(acervo[posicaoLivro].emprestarCopia(idUser, idCopia, 7)) {
        usuarios[posicaoPessoa]->liberarAluguel(idLivro);
        std::cout << "Empréstimo realizado com sucesso." << std::endl;;
    } /*
    Livro& livro = acervo[posicaoLivro];
    if (livro.getDisponiveis() <= 0) {
        std::cout << "Não há cópias disponíveis do livro." << std::endl;
        return;
    }

    if (!livro.emprestarCopia(idCopia)) {
        std::cout << "A cópia selecionada não está disponível para empréstimo." << std::endl;
        return;
    }*/

    
}


void Secretario::receberDevolucao(int idUser, int idLivro, int idCopia, std::vector<Livro>& acervo) {
    int posicaoLivro = encontrarLivro(idLivro, acervo);
    if (posicaoLivro == -1) {
        std::cout << "Livro não encontrado no acervo." << std::endl;
        return;
    } else {
        acervo[posicaoLivro].liberarCopia(idCopia);
        if(idUser == 0) {

        }
    }
    /*

    Livro& livro = acervo[posicaoLivro];
    if (!livro.devolverCopia(idCopia)) {
        std::cout << "A cópia não está emprestada." << std::endl;
        return;
    }*/

    std::cout << "Devolução realizada com sucesso." << std::endl;
}

void Secretario::visualizarDataEntrega(int idLivro, int idCopia, std::vector<Livro>& acervo) {
    int posicao = encontrarLivro(idLivro, acervo);
    if(posicao == -1) {
        std::cout << "Livro não encontrado\n";
    } else {
        std::string resposta = acervo[posicao].getDataDevolucao(idCopia);
        if(resposta.empty()) {
            std::cout << "Cópia não encontrada." << std::endl;
        } else if(resposta == "LIVRE") {
            std::cout << "Ainda não há uma data de devolução definida para essa cópia." << std::endl;
        } else {
            std::cout << "Data de entrega prevista: " << resposta << std::endl;
        }
    }
    
        }

void Secretario::visualizarUsuarios(std::vector<Cliente*>& usuarios) {
    for(size_t i = 0; i < usuarios.size(); i++) {
        std::cout << "ID: " << usuarios[i]->getIdUser() << "\tNome: " << usuarios[i]->getNome() << "\tTipo: " << usuarios[i]->getTipoUsuario() << std::endl;
    }
}