#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
#include "Livro.hpp"
#include "Aluguel.hpp"

/**
 * @brief Classe abstrata que representa uma Pessoa.
 *
 * A classe Pessoa é uma classe abstrata que serve como base para as classes
 * derivadas que representam diferentes tipos de usuários do sistema.
 */
class Pessoa {
public:
    /**
     * @brief Construtor da classe Pessoa.
     * @param nome O nome da pessoa.
     * @param dataIngresso A data de ingresso da pessoa.
     * @param senha A senha da pessoa.
     */

    Pessoa(const std::string& nome, const std::string& dataIngresso, int senha = -1);
    /**
     * @brief Destrutor.
     */
    ~Pessoa();

    /**
     * @brief Obtém o ID global da pessoa.
     * @return O ID global da pessoa.
     */
    static int getId();

    /**
     * @brief Obtém o ID do usuário.
     * @return O ID do usuário.
     */
    int getIdUser() const;

    /**
     * @brief Obtém o nome da pessoa.
     * @return O nome da pessoa.
     */
    std::string getNome() const;

    /**
     * @brief Obtém a data de ingresso da pessoa.
     * @return A data de ingresso da pessoa.
     */
    std::string getDataIngresso() const;

    /**
     * @brief Obtém a senha da pessoa.
     * @return A senha da pessoa.
     */
    int getSenha() const;

    /**
     * @brief Obtém o tipo de usuário da pessoa.
     * @return O tipo de usuário da pessoa.
     * 
     * @note Este é um método virtual puro que precisa ser implementado pelas classes derivadas.
     */
    virtual std::string getTipoUsuario() const = 0;

    /**
     * @brief Define o nome da pessoa.
     * @param novoNome O novo nome da pessoa.
     */
    void setNome(const std::string& novoNome);

    /**
     * @brief Define a senha da pessoa.
     * @param novaSenha A nova senha da pessoa.
     */
    void setSenha(int novaSenha);

    /**
     * @brief Consulta a lista de todos os livros do acervo.
     * @param acervo O vetor de livros representando o acervo.
     */
    void consultarListaLivros(std::vector<Livro>& acervo);

    /**
     * @brief Busca livros no acervo com base em um trecho e campo específicos e os exibe na tela.
     * @param trecho O trecho a ser buscado.
     * @param campo O campo em que o trecho será buscado.
     * @param acervo O vetor de livros do acervo.
     */
    void buscarLivro(const std::string& trecho, const std::string& campo, std::vector<Livro>& acervo);

    /**
     * @brief Exibe detalhes de um livro e o status de suas cópias.
     * @param idLivro O ID do livro a ser exibido.
     * @param acervo O vetor de livros do acervo.
     */
    void exibirLivro(const int idLivro,  std::vector<Livro>& acervo);



   
protected:
    /**
     * @brief Encontra um livro no acervo com base nas informações do livro.
     * @param livro As informações do livro a ser encontrado.
     * @param acervo O vetor de livros do acervo.
     * @return O índice do livro encontrado no acervo, ou -1 caso não seja encontrado.
     */
    int encontrarInfoLivro(const InfoLivro& livro, std::vector<Livro>& acervo) const;

    /**
     * @brief Encontra um livro no acervo com base no ID do livro.
     * @param idLivro O ID do livro a ser encontrado.
     * @param acervo O vetor de livros do acervo.
     * @return O índice do livro encontrado no acervo, ou -1 caso não seja encontrado.
     */
    int encontrarLivro(const int idLivro, std::vector<Livro>& acervo) const;

    
    std::string _tipoUsuario; /** O tipo de usuário que a Pessoa é no sistema.*/

private:
    static int _id; /**< ID global da pessoa para garantir a unicidade dos usuários. */
    int _idUser; /**< ID do usuário. */
    std::string _nome; /**< Nome da pessoa. */
    std::string _dataIngresso; /**< Data de ingresso da pessoa. */
    int _senha; /**< Senha da pessoa. */
    
    /**
     * @brief Gera uma senha aleatória.
     * @return A senha aleatória gerada.
     */
    int gerarSenhaAleatoria();
};

#endif  // PESSOA_HPP