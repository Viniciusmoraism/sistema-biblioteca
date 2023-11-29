#ifndef SECRETARIO_HPP
#define SECRETARIO_HPP

#include "Pessoa.hpp"
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Livro.hpp"

/**
 * @brief Classe que representa um secretário, derivada da classe Pessoa.
 * 
 * Um secretário é uma pessoa que possui informações pessoais, como nome e data de ingresso.
 * Ele também tem a responsabilidade de realizar diversas tarefas relacionadas à administração
 * da biblioteca, como cadastrar alunos e professores, emprestar e receber devoluções de livros,
 * visualizar informações sobre empréstimos e usuários, entre outras atividades.
 */
class Secretario : public Pessoa {
public:
    /**
     * @brief Construtor da classe Secretario.
     * @param nome O nome do secretário.
     * @param dataIngresso A data de ingresso do secretário.
     * @param senha A senha do secretário (opcional).
     */
    Secretario(const std::string& nome, const std::string& dataIngresso, int senha = -1);

    /**
     * @brief Destrutor da classe Secretario.
     */
    ~Secretario();

    /**
     * @brief Obtém o tipo de usuário da pessoa.
     * @return O tipo de usuário da pessoa.
     * 
     * @note Sobrescreve o método da classe base.
     */
    std::string getTipoUsuario() const override;

    /**
     * @brief Quita a multa de um usuário por um determinado livro.
     * @param livro O livro que teve a multa quitada.
     * @param idUsuario O ID do usuário que teve a multa quitada.
     * @return true se a multa foi quitada com sucesso, false caso contrário.
     */
    bool quitarMulta(Livro& livro, int idUsuario);

    /**
     * @brief Encontra um cliente pelo seu ID em um vetor de usuários.
     * @param idUser O ID do cliente a ser encontrado.
     * @param usuarios O vetor de clientes onde será feita a busca.
     * @return A posição do cliente no vetor de usuários, ou -1 se não encontrado.
     */
    int encontrarCliente(const int idUser, std::vector<Cliente*>& usuarios) const;

    /**
     * @brief Cadastra um aluno na biblioteca.
     * @param nome O nome do aluno.
     * @param dataIngresso A data de ingresso do aluno.
     * @param matricula A matrícula do aluno.
     * @param curso O curso do aluno.
     * @param usuarios O vetor de usuários onde o aluno será cadastrado.
     */
    void cadastrarAluno(const std::string& nome, const std::string& dataIngresso, const std::string& matricula, std::string& curso, std::vector<Cliente*>& usuarios);

    /**
     * @brief Cadastra um professor na biblioteca.
     * @param nome O nome do professor.
     * @param dataIngresso A data de ingresso do professor.
     * @param departamento O departamento do professor.
     * @param usuarios O vetor de usuários onde o professor será cadastrado.
     */
    void cadastrarProfessor(const std::string& nome, const std::string& dataIngresso,const std::string& departamento, std::vector<Cliente*>& usuarios);

    /**
     * @brief Realiza o empréstimo de um livro para um usuário.
     * @param idUser O ID do usuário que está realizando o empréstimo.
     * @param idLivro O ID do livro a ser emprestado.
     * @param idCopia O ID da cópia do livro a ser emprestada.
     * @param acervo O vetor de livros disponíveis para empréstimo.
     * @param usuarios O vetor de usuários onde o usuário está cadastrado.
     */
    void emprestarLivro(int idUser, int idLivro, int idCopia, std::vector<Livro>& acervo, std::vector<Cliente*>& usuarios);

    /**
     * @brief Recebe a devolução de um livro de um usuário.
     * @param idUser O ID do usuário que está realizando a devolução.
     * @param idLivro O ID do livro a ser devolvido.
     * @param idCopia O ID da cópia do livro a ser devolvida.
     * @param acervo O vetor de livros disponíveis para empréstimo.
     */
    void receberDevolucao(int idUser, int idLivro, int idCopia, std::vector<Livro>& acervo);

    /**
     * @brief Visualiza a data de entrega de um livro.
     * @param idLivro O ID do livro a ser consultado.
     * @param idCopia O ID da cópia do livro a ser consultada.
     * @param acervo O vetor de livros disponíveis para empréstimo.
     */
    void visualizarDataEntrega(int idLivro, int idCopia, std::vector<Livro>& acervo);

    /**
     * @brief Visualiza os usuários cadastrados na biblioteca.
     * @param usuarios O vetor de usuários a ser visualizado.
     */
    void visualizarUsuarios(std::vector<Cliente*>& usuarios);
};

#endif  // SECRETARIO_HPP