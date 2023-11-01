#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Cliente.hpp"
#include <vector>

/**
 * @brief Classe que representa um professor, derivada da classe Cliente.
 * 
 * Um professor é uma pessoa que possui informações pessoais, como nome, data de ingresso
 * e departamento. Além disso, um professor também herda as funcionalidades de um cliente,
 * podendo buscar livros, alugar e reservar.
 */
class Professor : public Cliente {
public:

    /**
     * @brief Construtor da classe Professor.
     * @param nome O nome do professor.
     * @param dataIngresso A data de ingresso do professor.
     * @param departamento O departamento do professor.
     * @param senha A senha do professor (opcional).
     */
    Professor(const std::string& nome, const std::string& dataIngresso, const std::string& departamento, int senha = -1);

    /**
     * @brief Destrutor da classe Professor.
     */
    ~Professor();

    /**
     * @brief Obtém o departamento do professor.
     * @return O departamento do professor.
     */
    std::string getDepartamento() const;

     /**
     * @brief Obtém o tipo de usuário da pessoa.
     * @return O tipo de usuário da pessoa.
     * 
     * @note Torna a classe concreta.
     */
    std::string getTipoUsuario() const override;

    /**
     * @brief Realiza o pagamento de uma multa do professor.
     */
    void pagarMulta();
    /*void reservarLivro(Acervo& acervo, const Livro& livro);
    void renovarEmprestimo(Acervo& acervo, int idCopia, int dias);
    void consultarListaLivros(const Acervo& acervo);
    void consultarLivrosAlugados(const Acervo& acervo); std::vector<Livro>& acervo*/

private:
    std::string _departamento; /**< O departamento do professor. */
};

#endif  // PROFESSOR_HPP