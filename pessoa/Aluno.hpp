#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "Cliente.hpp"
#include <vector>

/**
 * @brief Classe que representa um aluno, derivada da classe Cliente.
 * 
 * Um aluno é uma pessoa que possui informações pessoais, como nome, data de ingresso,
 * matrícula e curso. Além disso, um aluno também herda as funcionalidades de um cliente,
 * podendo buscar livros, alugar e reservar.
 */
class Aluno : public Cliente {
public:

    /**
     * @brief Construtor da classe Aluno.
     * @param nome O nome do aluno.
     * @param dataIngresso A data de ingresso do aluno.
     * @param matricula A matrícula do aluno.
     * @param curso O curso do aluno.
     * @param senha A senha do aluno (opcional, aleatorizada caso padrão).
     */
    Aluno(const std::string& nome, const std::string& dataIngresso, const std::string& matricula, const std::string& curso, int senha = -1);
    
    /**
     * @brief Destrutor da classe Aluno.
     */
    ~Aluno();

    /**
     * @brief Obtém a matrícula do aluno.
     * @return A matrícula do aluno.
     */
    std::string getMatricula() const;

     /**
     * @brief Obtém o curso do aluno.
     * @return O curso do aluno.
     */
    std::string getCurso() const;

     /**
     * @brief Realiza o pagamento de uma multa do aluno.
     */
    void pagarMulta();

     /**
     * @brief Obtém o tipo de usuário da pessoa.
     * @return O tipo de usuário da pessoa.
     * 
     * @note Torna a classe concreta.
     */
    std::string getTipoUsuario() const override;

    /*void reservarLivro(const Livro& livro, Acervo& acervo);
    void renovarEmprestimo(const Livro& livro, Acervo& acervo);
    void consultarListaLivros(Acervo& acervo) const;
    void consultarLivrosAlugados(Acervo& acervo) const; std::vector<Livro>& acervo std::vector<Livro>& acervo*/

private:
    std::string _matricula; /**< A matrícula do aluno. */
    std::string _curso; /**< O curso do aluno. */
    std::vector<Livro> _livrosAlugados; /**< Os livros alugados pelo aluno. */
};

#endif  // ALUNO_HPP