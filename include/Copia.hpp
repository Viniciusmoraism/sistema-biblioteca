#ifndef COPIA_HPP
#define COPIA_HPP

#include <iostream>
#include <string>

/**
 * @class Copia
 * Classe que representa uma cópia específica de um livro. É responsável por armazenar as informações dos empréstimos, renovações e etc. Copia deve ser utilizada primariamente dentro da classe Livro.
 */
class Copia {
public:
    /**
     * Construtor da classe Copia.
     * @param idCopia O ID da cópia.
     */
    Copia(int idCopia);

    /**
     * Destrutor da classe Copia.
     */
    ~Copia();

    /**
     * Obtém o ID da cópia.
     * @return O ID da cópia.
     */
    int getIdCopia() const;

    /**
     * Verifica se a cópia está disponível para empréstimo.
     * @return Verdadeiro se a cópia estiver disponível, falso caso contrário.
     */
    bool isDisponivel() const;

    /**
     * Verifica se a cópia está reservada.
     * @return Verdadeiro se a cópia estiver reservada, falso caso contrário.
     */
    bool isReservado() const;

    /**
     * Obtém a data de empréstimo da cópia.
     * @return A data de empréstimo da cópia.
     */
    std::string getDataEmprestimo() const;

    /**
     * Obtém a data de devolução da cópia.
     * @return A data de devolução da cópia.
     */
    std::string getDataDevolucao() const;

    /**
     * Obtém a data limite de duração da reserva para o usuário que reservou a cópia aluga-la.
     * @return A data limite de duração da reserva para o usuário que reservou a cópia aluga-la.
     */
    std::string getDataLimiteReserva() const;

    /**
     * Obtém o ID do usuário que realizou o empréstimo da cópia.
     * @return O ID do usuário que realizou o empréstimo.
     */
    int getEmprestimo() const;

    /**
     * Obtém o ID do usuário que realizou a reserva da cópia.
     * @return O ID do usuário que realizou a reserva.
     */
    int getReserva() const;

    /**
     * Define o ID do usuário que realizou o empréstimo da cópia.
     * @param emprestimo O ID do usuário que realizou o empréstimo.
     */
    void setEmprestimo(int emprestimo);

    /**
     * Define o ID do usuário que realizou a reserva da cópia.
     * @param reserva O ID do usuário que realizou a reserva.
     */
    void setReserva(int reserva);

    /**
     * Define a data de empréstimo da cópia.
     * @param dataEmprestimo A data de empréstimo da cópia.
     */
    void setDataEmprestimo(const std::string& dataEmprestimo);

    /**
     * Define a data de devolução da cópia.
     * @param dataDevolucao A data de devolução da cópia.
     */
    void setDataDevolucao(const std::string& dataDevolucao);

    /**
     * Define A data limite de duração da reserva para o usuário que reservou a cópia aluga-la.
     * @param dataLimiteReserva A data limite de duração da reserva para o usuário que reservou a cópia aluga-la.
     */
    void setDataLimiteReserva(const std::string& dataLimiteReserva);

    /**
     * Mostra informações sobre a cópia.
     */
    void informacoes() const;

    double getMulta() const;
    void setMulta(double multa);



private:

    
    int _idCopia;                   /**< O ID da cópia. */
    int _emprestimo;                /**< O ID do usuário que realizou o empréstimo. */
    int _reserva;                   /**< O ID do usuário que realizou a reserva. */
    std::string _dataEmprestimo;    /**< A data de empréstimo da cópia. */
    std::string _dataDevolucao;     /**< A data de devolução da cópia. */
    std::string _dataLimiteReserva; /**< A data limite de duração da reserva para o usuário que reservou a cópia aluga-la. */
    double _multa;                  /**< Armazena valor da multa */
};

#endif  // COPIA_HPP