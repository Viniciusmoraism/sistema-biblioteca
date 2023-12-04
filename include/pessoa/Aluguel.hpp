#ifndef ALUGUEL_HPP
#define ALUGUEL_HPP

/**
 * @brief Classe que representa um aluguel de um livro.
 * 
 * Um aluguel é associado a um livro e uma cópia específica do livro, e mantém o número de renovações
 * que foram feitas para o aluguel.
 */
class Aluguel {
private:
    int _idLivro; /**< O ID do livro associado ao aluguel. */
    int _idCopia; /**< O ID da cópia do livro associada ao aluguel. */
    int _renovacoes; /**< O número de renovações realizadas para o aluguel. */

public:
    /**
     * @brief Construtor da classe Aluguel.
     */
    Aluguel();

    /**
     * @brief Obtém o ID do livro associado ao aluguel.
     * @return O ID do livro.
     */
    int getIdLivro() const;

    /**
     * @brief Obtém o ID da cópia do livro associada ao aluguel.
     * @return O ID da cópia do livro.
     */
    int getIdCopia() const;

    /**
     * @brief Obtém o número de renovações realizadas para o aluguel.
     * @return O número de renovações.
     */
    int getRenovacoes() const;

    /**
     * @brief Define o ID do livro associado ao aluguel.
     * @param id O ID do livro.
     */
    void setIdLivro(int id);

    /**
     * @brief Define o ID da cópia do livro associada ao aluguel.
     * @param id O ID da cópia do livro.
     */
    void setIdCopia(int id);

    /**
     * @brief Define o número de renovações realizadas para o aluguel.
     * @param numRenovacoes O número de renovações.
     */
    void setRenovacoes(int numRenovacoes);

    /**
     * @brief Sobrecarga do operador de igualdade para comparar dois aluguéis.
     * @param outro O outro aluguel a ser comparado.
     * @return true se os aluguéis forem iguais, false caso contrário.
     */
    bool operator==(const Aluguel& outro) const;
};

#endif  // ALUGUEL_HPP