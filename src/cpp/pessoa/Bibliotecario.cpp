#include "Bibliotecario.hpp"
#include <iostream>

Bibliotecario::Bibliotecario(const std::string& nome, const std::string& dataIngresso, int senha)
    : Secretario(nome, dataIngresso, senha) {
    _tipoUsuario = "Bibliotecario";
}

void Bibliotecario::cadastrarLivro(const InfoLivro& infoLivro, std::vector<Livro>& acervo) {
    int posicao = encontrarInfoLivro(infoLivro, acervo);
    std::cout << "Livro cadastrado com Sucesso. \n";
    if (posicao != -1) {
        acervo[posicao].adicionarCopia(true);
    } else {
        Livro novoLivro(infoLivro);
        acervo.push_back(novoLivro);
        acervo[acervo.size()-1].adicionarCopia(true);
    }
}

void Bibliotecario::removerLivro(int idLivro,int idCopia, std::vector<Livro>& acervo) {
    int posicao = encontrarLivro(idLivro, acervo);
    if (posicao == -1) {
        std::cout << "Livro informado não existe no acervo.\n";
    } else {
        acervo[posicao].removerCopia(idCopia);
        //std::cout << "Cópia removida com Sucesso.\n";
        if(acervo[posicao].getCopias().empty()) {
            std::cout << "A última cópia do livro foi removida. Livro removido do acervo.\n";
        }
    }
}