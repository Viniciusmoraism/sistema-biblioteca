#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "Pessoa.hpp"

/**
 * @brief Classe derivada de Pessoa que representa um cliente da biblioteca.
 * 
 * Um cliente é uma pessoa que possui informações pessoais e tem a capacidade de buscar livros,
 * alugar e reservar.
 */

class Cliente : public Pessoa {
public:
    
    /**
     * @brief Construtor da classe Cliente.
     * @param nome O nome do cliente.
     * @param dataIngresso A data de ingresso do cliente na biblioteca.
     * @param senha A senha do cliente (opcional, padrão = -1:). É aleatorizada na instanciação se for mantida com o valor padrão.
     */

    Cliente(const std::string& nome, const std::string& dataIngresso, int senha = -1);
    
    /**
     * @brief Destrutor da classe Cliente.
     */
    ~Cliente();

    /**
     * @brief Consulta os livros alugados pela pessoa.
     * @param acervo O vetor de livros do acervo.
     */
    virtual void consultarLivrosAlugados(std::vector<Livro>& acervo);

    /**
     * @brief Consulta os livros reservados pela pessoa.
     * @param acervo O vetor de livros do acervo.
     */
    virtual void consultarLivrosReservados(std::vector<Livro>& acervo);

    /**
     * @brief Reserva um livro.
     * @param idLivro O ID do livro a ser reservado.
     * @param idCopia O ID da cópia do livro a ser reservado.
     * @param acervo O vetor de livros do acervo.
     */
    virtual void reservarLivro(const int idLivro, int idCopia, std::vector<Livro>& acervo);

    /**
     * @brief Renova o empréstimo de um livro.
     * @param idLivro O ID do livro a ter o empréstimo renovado.
     * @param acervo O vetor de livros do acervo.
     */
    virtual void renovarEmprestimo(const int idLivro, std::vector<Livro>& acervo);


    /**
     * @brief Libera um aluguel, removendo-o da lista de alugueis do cliente.
     * @param idLivro O ID do livro a ter o aluguel liberado.
     */

    void liberarAluguel(int idLivro);

    /**
     * @brief Define os aluguéis do cliente.
     * @param alugueis Um ponteiro para o array de aluguéis.
     * @param tamanho O tamanho do array de aluguéis.
     */

    void setAlugueis(const Aluguel* alugueis, int tamanho); 

protected:
    /**
     * @brief Verifica se o usuário já possui o limite de aluguéis e reservas da Biblioteca atingido e retorna a posição do atributo _alugueis que serão armazenadas as informações do próximo Empréstimo ou Reserva de um livro especifico.
     * @param idLivro O ID do livro a ser verificado.
     * @return A posição do atributo _alugueis que será usada para armazenar informações sobre o empréstimo ou reserva.
     */
    virtual int checarAlugueis(const int idLivro);
    
    int _diasEmprestimo = 7; /**< Número de dias de empréstimo padrão. */
    static const int _limite = 3; /**< Limite de livros reservados/alugados por usuário. */
    Aluguel _alugueis[_limite]; /**< Vetor de alugueis do usuário. */

};

#endif  // CLIENTE_HPP