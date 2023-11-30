#include "Pessoa.hpp"
#include <cstdlib> // Para a função rand()
#include <ctime>   // Para a função time()
#include <typeinfo> // Para typeid
#include <string>
#include <cctype>

int Pessoa::_id = 0;

Pessoa::Pessoa(const std::string& nome, const std::string& dataIngresso, int senha)
    : _idUser(++_id), _nome(nome), _dataIngresso(dataIngresso), _tipoUsuario("Pessoa") {
    if (senha != -1) {
        _senha = senha;
    } else {
        _senha = gerarSenhaAleatoria();
    }
}

Pessoa::~Pessoa() {}

int Pessoa::getId() {
    return _id;
}

int Pessoa::getIdUser() const {
    return _idUser;
}

std::string Pessoa::getNome() const {
    return _nome;
}

std::string Pessoa::getDataIngresso() const {
    return _dataIngresso;
}

int Pessoa::getSenha() const {
    return _senha;
}

void Pessoa::setNome(const std::string& novoNome) {
    _nome = novoNome;
}

void Pessoa::setSenha(int novaSenha) {
    _senha = novaSenha;
}

int Pessoa::gerarSenhaAleatoria() {
    srand(time(nullptr));
    return rand() % 900000 + 100000;
}

int Pessoa::encontrarInfoLivro(const InfoLivro& infoLivro, std::vector<Livro>& acervo) const {
    for (size_t i = 0; i < acervo.size(); ++i) {
        if (acervo[i].getInfoLivro() == infoLivro) {
            return i;
        }
    }
    return -1;
}

int Pessoa::encontrarLivro(const int idLivro, std::vector<Livro>& acervo) const {

    for (size_t i = 0; i < acervo.size(); ++i) {
        if (acervo[i].getIdLivro() == idLivro) {
            return i;
        }
    }
    return -1;
}

void Pessoa::consultarListaLivros(std::vector<Livro>& acervo) {
    std::cout << "Lista de Livros no Acervo:" << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << std::setw(4) << "ID" << " | "
              << std::setw(20) << "Nome" << " | "
              << std::setw(15) << "Autor" << " | "
              << std::setw(12) << "Gênero" << " | "
              << std::setw(7) << "Edição" << " | "
              << std::setw(12) << "Disponíveis" << " | "
              << std::setw(12) << "Reservados" << " | "
              << std::setw(6) << "Total" << std::endl;
    std::cout << "==================================" << std::endl;
    for (Livro& livro : acervo) {
        //livro.getLivro().informacoes();
        std::cout << std::setw(4) << livro.getIdLivro() << " | "
              << std::setw(20) << livro.getInfoLivro().getNome().substr(0, 20) << " | "
              << std::setw(15) << livro.getInfoLivro().getAutor().substr(0, 15)  << " | "
              << std::setw(12) << livro.getInfoLivro().getGenero() << " | "
              << std::setw(7) << livro.getInfoLivro().getEdicao() << " | "
              << std::setw(12) << livro.getTotalDisponiveis() << " | "
              << std::setw(12) << livro.getTotalReservados() << " | "
              << std::setw(6) << livro.getTotalCopias() << std::endl;
         //std::cout << livro.getIdLivro() << " | " << livro.getInfoLivro().getNome().substr(0, 30) << " | " << livro.getInfoLivro().getAutor().substr(0, 20) << " | " << livro.getInfoLivro().getGenero() << " | " << livro.getInfoLivro().getEdicao() << " | " << livro.getTotalDisponiveis() << " | " << livro.getTotalReservados() << " | " << livro.getTotalCopias() << std::endl;
    }
    std::cout << "==================================" << std::endl;
}


void Pessoa::buscarLivro(const std::string& trecho, const std::string& campo, std::vector<Livro>& acervo) {
    bool encontrado = false;
    std::string trechoLowerCase = trecho;
    for (size_t z = 0; z < trechoLowerCase.size(); z++) {
        trechoLowerCase[z] = std::tolower(trechoLowerCase[z]);
        }

    std::cout << "==================================" << std::endl;
    std::cout << std::setw(4) << "ID" << " | "
              << std::setw(20) << "Nome" << " | "
              << std::setw(15) << "Autor" << " | "
              << std::setw(12) << "Gênero" << " | "
              << std::setw(7) << "Edição" << " | "
              << std::setw(12) << "Disponíveis" << " | "
              << std::setw(12) << "Reservados" << " | "
              << std::setw(6) << "Total" << std::endl;
    std::cout << "==================================" << std::endl;
    for (size_t w = 0; w < acervo.size(); w++) {
        const InfoLivro& livro = acervo[w].getInfoLivro();

        std::string atributoLowerCase;
        if (campo == "nome") {
            atributoLowerCase =  livro.getNome();
        } else if (campo == "autor") {
            atributoLowerCase = livro.getAutor();
        } else if (campo == "genero") {
            atributoLowerCase = livro.getGenero();
        } else {
            // Campo inválido, ignorar elemento
            continue;
        }

        for (size_t j = 0; j < atributoLowerCase.size(); j++) {
        atributoLowerCase[j] = std::tolower(atributoLowerCase[j]);
        }


        if (atributoLowerCase.find(trechoLowerCase) != std::string::npos) {
            encontrado = true;
            std::cout << std::setw(4) << acervo[w].getIdLivro() << " | "
              << std::setw(20) << acervo[w].getInfoLivro().getNome().substr(0, 20) << " | "
              << std::setw(15) << acervo[w].getInfoLivro().getAutor().substr(0, 15)  << " | "
              << std::setw(12) << acervo[w].getInfoLivro().getGenero() << " | "
              << std::setw(7) << acervo[w].getInfoLivro().getEdicao() << " | "
              << std::setw(12) << acervo[w].getTotalDisponiveis() << " | "
              << std::setw(12) << acervo[w].getTotalReservados() << " | "
              << std::setw(6) << acervo[w].getTotalCopias() << std::endl;
        }
    }
    
    if(!encontrado) {
        std::cout << "Nenhum livro encontrado\n";
    }
}

void Pessoa::exibirLivro(const int idLivro,  std::vector<Livro>& acervo) {
    int posicao = encontrarLivro(idLivro, acervo);
    if(posicao == -1) {
        std::cout << "Livro não encontrado \n";
    } else {
        acervo[posicao].informacoes();
    }
}