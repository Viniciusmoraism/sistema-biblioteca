#ifndef INFOLIVRO_HPP
#define INFOLIVRO_HPP

#include <string>

/**
 * @class InfoLivro
 * Classe responsável por armazenar informações sobre um livro.
 */
class InfoLivro {
public:
    /**
     * Construtor da classe InfoLivro.
     * @param nome O nome do livro.
     * @param autor O autor do livro.
     * @param edicao O número da edição do livro.
     * @param genero O gênero do livro.
     */
    InfoLivro(const std::string& nome, const std::string& autor, int edicao, const std::string& genero);

    /**
     * Destrutor da classe InfoLivro.
     */
    ~InfoLivro();

    /**
     * Obtém o nome do livro.
     * @return O nome do livro.
     */
    std::string getNome() const;

    /**
     * Obtém o autor do livro.
     * @return O autor do livro.
     */
    std::string getAutor() const;

    /**
     * Obtém o gênero do livro.
     * @return O gênero do livro.
     */
    std::string getGenero() const;

    /**
     * Obtém o número da edição do livro.
     * @return O número da edição do livro.
     */
    int getEdicao() const;

    /**
     * Mostra informações sobre o livro.
     */
    void informacoes() const;

    /**
     * Sobrecarga do operador de igualdade.
     * Verifica se dois objetos InfoLivro são iguais.
     * @param outro O objeto InfoLivro a ser comparado.
     * @return Verdadeiro se os objetos forem iguais, falso caso contrário.
     */
    bool operator==(const InfoLivro& outro) const;

private:
    std::string _nome;   /**< O nome do livro. */
    std::string _autor;  /**< O autor do livro. */
    std::string _genero; /**< O gênero do livro. */
    int _edicao;         /**< O número da edição do livro. */
};

#endif  // INFOLIVRO_HPP