#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "InfoLivro.hpp"
#include "Copia.hpp"

/**
 * @class Livro
 * Classe que representa todas cópias de um livro no acervo da Biblioteca. A classe é uma  composição das informações do livro como nome e autor e a lista das cópias, cada cópia possui os atributos necessários para gerenciar os empréstimos, renovações e reesrvas no que tange os livros, sendo que os atributos dos usuários são alterados dentro da Classe Pessoa.
 */
class Livro {
public:
    /**
     * Construtor da classe Livro.
     * @param infoLivro As informações do livro.
     */
    Livro(const InfoLivro& infoLivro);

    /**
     * Destrutor da classe Livro.
     */
    ~Livro();

    /**
     * Obtém o número total de cópias disponíveis do livro.
     * @return O número total de cópias disponíveis.
     */
    int getTotalDisponiveis() const;

    /**
     * Obtém o número total de cópias reservadas do livro.
     * @return O número total de cópias reservadas.
     */
    int getTotalReservados();

    /**
     * Obtém o número total de cópias do livro.
     * @return O número total de cópias.
     */
    int getTotalCopias() const;

    /**
     * Obtém o ID do livro.
     * @return O ID do livro.
     */
    int getIdLivro() const;

    /**
     * Obtém as informações do livro.
     * @return As informações do livro.
     */
    InfoLivro getInfoLivro() const;

    /**
     * Obtém as cópias do livro.
     * @return Um vetor contendo as cópias do livro.
     */
    std::vector<Copia> getCopias();


    /**
     * Adiciona uma nova cópia ao livro.
     * @param print indica se o método deve printar os ids da cópia adicionada.
     */
    void adicionarCopia(bool print = false);

    /**
     * Atualiza as reservas das cópias do livro.
     */
    void atualizarReservas();

    /**
     * Mostra informações sobre o livro e suas cópias.
     */
    void informacoes();

    /**
     * Remove uma cópia do livro com base no seu ID.
     * @param idCopia O ID da cópia a ser removida.
     */
    void removerCopia(int idCopia);

    /**
     * Realiza o empréstimo de uma cópia do livro para um usuário.
     * @param userId O ID do usuário que está fazendo o empréstimo.
     * @param idCopia O ID da cópia a ser emprestada.
     * @param dias O número de dias de empréstimo.
     * @return Verdadeiro se o empréstimo for realizado com sucesso, falso caso contrário.
     */
    bool emprestarCopia(int userId, int idCopia, int dias);

    /**
     * Realiza a reserva de uma cópia do livro para um usuário.
     * @param userId O ID do usuário que está fazendo a reserva.
     * @param idCopia O ID da cópia a ser reservada.
     * @return Verdadeiro se a reserva for realizada com sucesso, falso caso contrário.
     */
    bool reservarCopia(int userId, int idCopia);

    /**
     * Renova o empréstimo de uma cópia do livro para um usuário.
     * @param userId O ID do usuário que está renovando o empréstimo.
     * @param idCopia O ID da cópia a ser renovada.
     * @param dias O número de dias de renovação.
     * @return Verdadeiro se a renovação for realizada com sucesso, falso caso contrário.
     */
    bool renovarCopia(int userId, int idCopia, int dias);

    /**
     * Libera uma cópia do livro após a devolução.
     * @param idCopia O ID da cópia a ser liberada.
     * @return Verdadeiro se a liberação for realizada com sucesso, falso caso contrário.
     */
    bool liberarCopia(int idCopia);

    /**
     * Exibe as informações de aluguel de uma cópia do livro.
     * @param idCopia O ID da cópia.
     */
    void verAluguel(int idCopia);

    /**
     * Verifica se uma cópia do livro está reservada por um usuário e exibe as informações de reserva da cópia do livro.
     * @param idCopia O ID da cópia.
     * @param idUsuario O ID do usuário.
     * @return Verdadeiro se a cópia estiver reservada pelo usuário, falso caso contrário.
     */
    bool verReserva(int idCopia, int idUsuario);

    double calcularMultaTotal(int IdUser);
    bool quitarMulta(int idCopia);
    bool pagarMulta(int idCopia, double valor);
    std::string getDataDevolucao(int idCopia);

protected:
    /**
     * Encontra a posição de uma cópia no vetor de cópias do livro com base no seu ID.
     * @param idCopia O ID da cópia a ser encontrada.
     * @return A posição da cópia no vetor, ou -1 se a cópia não for encontrada.
     */
    int encontrarCopia(int idCopia) const;

    /**
     * Obtém a data atual.
     * @return A data atual.
     */
    std::tm dataAtual();

    /**
     * Converte uma string de data em uma estrutura tm.
     * @param dataString A string de data a ser convertida.
     * @return A estrutura tm correspondente à data.
     */
    std::tm StrParaTm(const std::string& dataString);

    /**
     * Converte uma estrutura tm em uma string de data.
     * @param tmData A estrutura tm contendo a data.
     * @return A string de data correspondente.
     */
    std::string TmParaString(const std::tm& tmData);

    /**
     * Calcula a diferença em dias entre duas datas.
     * @param tmData1 A primeira data.
     * @param tmData2 A segunda data.
     * @return A diferença em dias entre as duas datas.
     */
    int calcularDifDias(const std::tm& tmData1, const std::tm& tmData2);

    /**
     * Adiciona um número de dias a uma data.
     * @param data A data.
     * @param nDias O número de dias a serem adicionados.
     * @return A nova data resultante da adição dos dias.
     */
    std::tm adicionarDias(const std::tm& data, int nDias);

private:
    InfoLivro _infoLivro;   /**< As informações do livro. */
    std::vector<Copia> _copias; /**< O vetor de cópias do livro. */
    static int _id; /**< ID global dos livros. Garante unicidade dos livros distintos cadastrados, permitindo que todas cópias possam utilizar um mesmo ID principal.*/
    int _idLivro; /**< ID do livro.*/
    int _idCopia; /**< ID global das cópias de um livro específico. Garante unicidade das cópias.*/
    double _multaDiaria = 5.5;
};



#endif  // LIVRO_HPP