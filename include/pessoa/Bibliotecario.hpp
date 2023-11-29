#ifndef BIBLIOTECARIO_HPP
#define BIBLIOTECARIO_HPP

#include "Secretario.hpp"
#include "Livro.hpp"

/**
 * @brief Classe que representa um bibliotecário, derivada da classe Secretario.
 *
 * Um bibliotecário é um funcionário da biblioteca que possui as mesmas responsabilidades
 * de um secretário, mas também possui tarefas adicionais relacionadas à administração
 * do acervo de livros da biblioteca. Ele pode cadastrar novos livros no acervo e remover
 * livros existentes do acervo.
 */
class Bibliotecario : public Secretario {
public:
    /**
     * @brief Construtor da classe Bibliotecario.
     * @param nome O nome do bibliotecário.
     * @param dataIngresso A data de ingresso do bibliotecário.
     * @param senha A senha do bibliotecário (opcional).
     */
    Bibliotecario(const std::string& nome, const std::string& dataIngresso, int senha = -1);

    /**
     * @brief Destrutor da classe Bibliotecario.
     */
    ~Bibliotecario();

    /**
     * @brief Cadastra um livro no acervo da biblioteca.
     * @param livro As informações do livro a ser cadastrado.
     * @param acervo O vetor de livros onde o livro será cadastrado.
     */
    void cadastrarLivro(const InfoLivro& livro, std::vector<Livro>& acervo);

    /**
     * @brief Remove um livro do acervo da biblioteca.
     * @param idLivro O ID do livro a ser removido.
     * @param idCopia O ID da cópia do livro a ser removida.
     * @param acervo O vetor de livros onde o livro será removido.
     */
    void removerLivro(int idLivro, int idCopia, std::vector<Livro>& acervo);
};

#endif  // BIBLIOTECARIO_HPP