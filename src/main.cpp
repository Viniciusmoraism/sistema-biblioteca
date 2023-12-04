#include "InfoLivro.hpp"
#include "Copia.hpp"
#include "Livro.hpp"
#include "Aluguel.hpp"
#include "Pessoa.hpp"
#include "Cliente.hpp"
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Secretario.hpp"
#include "Bibliotecario.hpp"
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

int main() {

  std::vector<Livro> acervo;
  std::vector<Pessoa *> funcionarios;
  std::vector<Cliente *> usuarios;

  Pessoa *pessoaTemp = new Bibliotecario("Admin", "21/06/2023", 321);
  funcionarios.push_back(pessoaTemp);
  pessoaTemp = new Secretario("Moça da Biblioteca", "21/06/2023", 123);
  funcionarios.push_back(pessoaTemp);

  Cliente* clienteTemp = new  Aluno("João", "21/06/2023", "2023-01001", "Engenharia Elétrica");
  usuarios.push_back(clienteTemp);
  //pessoaTemp = new Aluno("João", "21/06/2023", "2023-01001", "Engenharia Elétrica");
  //usuarios.push_back(pessoaTemp);
  clienteTemp = new Aluno("Maria", "21/06/2023", "2023-01002", "História");
  usuarios.push_back(clienteTemp);
  clienteTemp = new Aluno("Asdrubaldo Pereira", "21/06/2023", "2023-01003", "Administração");
  usuarios.push_back(clienteTemp);
  clienteTemp = new Professor("Ademir", "21/06/2023", "Física");
  usuarios.push_back(clienteTemp);

  InfoLivro infoLivroTemp = InfoLivro("Cálculo Volume 1", "James Stewart", 5, "Matemática");
  Livro livroTemp = Livro(infoLivroTemp);
  acervo.push_back(livroTemp);

  infoLivroTemp = InfoLivro("Cálculo Volume 2", "James Stewart", 5, "Matemática");
  livroTemp = Livro(infoLivroTemp);
  acervo.push_back(livroTemp);

  infoLivroTemp = InfoLivro("Patologia", "Bogliolo", 7, "Saúde");
  livroTemp = Livro(infoLivroTemp);
  acervo.push_back(livroTemp);

  infoLivroTemp = InfoLivro("1984", "George Orwell", 7, "Literatura");
  livroTemp = Livro(infoLivroTemp);
  acervo.push_back(livroTemp);

  infoLivroTemp = InfoLivro("Algoritmos - Teoria e Prática", "Thomas Cormen", 2, "Computação");
  livroTemp = Livro(infoLivroTemp);
  acervo.push_back(livroTemp);

  for (int i = 0; i < 10; i++)
  {
    acervo[0].adicionarCopia();
    acervo[1].adicionarCopia();
    if (i < 4)
    {
      acervo[2].adicionarCopia();
    }
    if (i < 2)
    {
      acervo[3].adicionarCopia();
    }
    if (i < 7)
    {
      acervo[4].adicionarCopia();
    }
  }

  Aluguel alugueis[3];
  alugueis[0].setIdLivro(1);
  alugueis[0].setIdCopia(2);
  alugueis[0].setRenovacoes(2);
  alugueis[1].setIdLivro(2);
  alugueis[1].setIdCopia(1);
  alugueis[1].setRenovacoes(1);
  alugueis[2].setIdLivro(3);
  alugueis[2].setIdCopia(1);
  alugueis[2].setRenovacoes(0);

  if (Cliente *cliente = dynamic_cast<Cliente *>(usuarios[0]))
  {
    cliente->setAlugueis(alugueis, 3);
  }

  int id = usuarios[0]->getIdUser();

  acervo[0].emprestarCopia(id, 2, 7);
  acervo[1].emprestarCopia(id, 1, 7);
  acervo[2].reservarCopia(id, 1);

  std::string nome;
  std::string dataIngresso;
  std::string senha;
  std::string matricula;
  std::string curso;
  std::string departamento;
  int opcao;

  /*std::cout << "Digite o seu nome: ";
  std::getline(std::cin, nome);

  std::cout << "Selecione o tipo de usuário:" << std::endl;
  std::cout << "1. Aluno" << std::endl;
  std::cout << "2. Professor" << std::endl;
  std::cout << "3. Secretário" << std::endl;
  std::cout << "4. Bibliotecário" << std::endl;
  std::cout << "Digite a opção desejada: ";
  std::cin >> opcao;
  std::cin.ignore(); // Limpa o caractere de nova linha pendente*/

  do
  {
    std::cout << "Bem-vindo(a) ao sistema da biblioteca!" << std::endl;

    std::cout << "Selecione o tipo de usuário:" << std::endl;
    std::cout << "1. Aluno - João, um aluno que usa e abusa da biblioteca e já está com seu limite de livros" << std::endl;
    std::cout << "2. Professor - Ademir, um professor que nunca alugou um livro" << std::endl;
    std::cout << "3. Secretário - A moça da bibloteca pode gerenciar os usuários, mas não os livros" << std::endl;
    std::cout << "4. Bibliotecário - Manda e desmanda na biblioteca, escolhe quais livros entram para o acervo e quais saem" << std::endl;
    std::cout << "0. Sair do Programa" << std::endl;
    std::cout << "Digite a opção desejada: ";
    std::cin >> opcao;
    std::cin.ignore(); // Limpa o caractere de nova linha pendente

    switch (opcao)
    {
      case 1:
      {
        Aluno *aluno = dynamic_cast<Aluno *>(usuarios[0]);
        int escolha;
        std::string entrada;
        std::cout << "***\n";
        std::cout << "Olá, "
                  << aluno->getNome() << std::endl;
        do
        {
          std::cout << std::endl;
          std::cout << "Selecione a ação desejada:" << std::endl;
          std::cout << "1. Reservar livro" << std::endl;
          std::cout << "2. Renovar livro" << std::endl;
          std::cout << "3. Ver livros alugados" << std::endl;
          std::cout << "4. Ver livros reservados" << std::endl;
          std::cout << "5. Ver acervo" << std::endl;
          std::cout << "6. buscar livro" << std::endl;
          std::cout << "7. Pagar multa" << std::endl;
          std::cout << "0. Tela inicial" << std::endl;
          std::cout << "Digite a opção desejada: ";
          std::cin >> escolha;
          std::cin.ignore();

          switch (escolha)
          {
            case 1:
            {
                int idLivro, idCopia;
                std::string entrada;

                std::cout << "Qual o ID do livro e da cópia que deseja reservar?" << std::endl;
                std::cout << "Forneça os IDs separados por espaço. Ex: 15 2" << std::endl;
                std::cout << "(Se não souber, volte ao menu anterior e selecione 5)" << std::endl;
                std::cout << "X: voltar" << std::endl;

                std::getline(std::cin, entrada);
                std::cout << std::endl;

                if (entrada == "X" || entrada == "x")
                {
                    std::cout << "Voltando ao menu principal..." << std::endl;
                    break;
                }

                std::istringstream iss(entrada);
                if (!(iss >> idLivro >> idCopia) || idLivro <= 0 || idCopia <= 0)
                {
                    std::cout << "Entrada inválida! Digite IDs válidos separados por espaço." << std::endl;
                    std::cout << "Retornando ao menu principal..." << std::endl;
                    break;
                }

                aluno->reservarLivro(idLivro, idCopia, acervo);
                std::cout << "Pressione enter para continuar" << std::endl;
                std::getline(std::cin, entrada);

                break;
            }

            case 2:
            {
              //std::string entrada;
              int idLivro;
              std::cout << "Qual o ID do livro que deseja renovar?" << std::endl;
              std::cout << "(Se não souber, volte ao menu anterior e selecione 5)" << std::endl;
              std::cout << "X: voltar" << std::endl;
              std::getline(std::cin, entrada);
              std::cout << std::endl;


              if (entrada == "X" || entrada == "x")
              {
                std::cout << "Voltando ao menu principal..." << std::endl;
                break;
              }

              std::istringstream iss(entrada);
              if (!(iss >> idLivro) || idLivro <= 0)
              {
                std::cout << "Entrada inválida!" << std::endl;
                std::cout << "Retornando ao menu principal..." << std::endl;
                break;
              }
              aluno->renovarEmprestimo(idLivro, acervo);
              std::cout << "Pressione enter para continuar" << std::endl;
              std::getline(std::cin, entrada);
              

              break;
            }
            case 3:
            {
              aluno->consultarLivrosAlugados(acervo);
              std::cout << "Pressione enter para continuar" << std::endl;
              //std::string entrada;
              std::getline(std::cin, entrada);

              break;
            }
            case 4:
            {
              aluno->consultarLivrosReservados(acervo);
              std::cout << "Pressione enter para continuar" << std::endl;
              //std::string entrada;
              std::getline(std::cin, entrada);

              break;
            }
            case 5:
            {
              //std::string entrada;
              int idLivro;
              aluno->consultarListaLivros(acervo);
              std::cout << "Qual o ID do livro que você deseja visualizar seus detalhes?" << std::endl;
              std::cout << "X: voltar" << std::endl;
              std::getline(std::cin, entrada);
              std::cout << std::endl;


              if (entrada == "X" || entrada == "x")
              {
                std::cout << "Voltando ao menu principal..." << std::endl;
                break;
              }

              std::istringstream iss(entrada);
              if (!(iss >> idLivro) || idLivro <= 0)
              {
                std::cout << "Entrada inválida!" << std::endl;
                std::cout << "Retornando ao menu principal..." << std::endl;
                break;
              }

              aluno->exibirLivro(idLivro, acervo);
              std::cout << "Pressione enter para continuar" << std::endl;
              std::getline(std::cin, entrada);

              break;
            }

            case 6:
            {
              std::string campo, trecho;

              std::cout << "Por qual campo deseja buscar o livro?" << std::endl;
              std::cout << "1. Nome" << std::endl;
              std::cout << "2. Autor" << std::endl;
              std::cout << "3. Gênero" << std::endl;
              std::cout << "X: Voltar" << std::endl;
              std::getline(std::cin, campo);
              std::cout << std::endl;


              if (campo == "X" || campo == "x")
              {
                std::cout << "Voltando ao menu principal..." << std::endl;
                break;
              }

              int opcaoCampo;
              std::istringstream issCampo(campo);
              if (!(issCampo >> opcaoCampo) || opcaoCampo < 1 || opcaoCampo > 3)
              {
                std::cout << "Opção inválida! Digite um número válido." << std::endl;
                std::cout << "Retornando ao menu principal..." << std::endl;
                break;
              }
              std::string campoConvertido;
              if (campo == "1") {
                  campoConvertido = "nome";
              } else if (campo == "2") {
                  campoConvertido = "autor";
              } else if (campo == "3") {
                  campoConvertido = "genero";
              } else {
                  // Opção inválida, trate o caso de acordo com suas necessidades
              }
              std::cout << "Qual o trecho que deseja buscar?" << std::endl;
              std::getline(std::cin, trecho);
              std::cout << std::endl;


              aluno->buscarLivro(trecho, campoConvertido, acervo);
              std::cout << "Pressione enter para continuar" << std::endl;
              //std::string entrada;
              std::getline(std::cin, entrada);

              break;
            }
            case 7:
            {
              aluno->pagarMulta();
              std::cout << "Pressione enter para continuar" << std::endl;
              //std::string entrada;
              std::getline(std::cin, entrada);
              break;
            }
            case 0:
            {
              std::cout << "Tela inicial..." << std::endl;
              std::cout << "Pressione enter para continuar" << std::endl;
              //std::string entrada;
              std::getline(std::cin, entrada);
              break;
            }
            default:
            {
              std::cout << "Opção inválida!" << std::endl;
              break;
            }
          }
        } while (escolha != 0);
        break;
      }
      case 2:
      {
        Professor *professor = dynamic_cast<Professor *>(usuarios[3]);
        int escolha;
        std::string entrada;
        std::cout << "***\n";
        std::cout << "Olá, "
                  << professor->getNome() << std::endl;
        do
        {
          std::cout << std::endl;
          std::cout << "Selecione a ação desejada:" << std::endl;
          std::cout << "1. Reservar livro" << std::endl;
          std::cout << "2. Renovar livro" << std::endl;
          std::cout << "3. Ver livros alugados" << std::endl;
          std::cout << "4. Ver livros reservados" << std::endl;
          std::cout << "5. Ver acervo" << std::endl;
          std::cout << "6. buscar livro" << std::endl;
          std::cout << "7. Pagar multa" << std::endl;
          std::cout << "0. Tela inicial" << std::endl;
          std::cout << "Digite a opção desejada: ";
          std::cin >> escolha;
          std::cin.ignore();

          switch (escolha)
          {
            case 1:
            {
                int idLivro, idCopia;
                std::string entrada;

                std::cout << "Qual o ID do livro e da cópia que deseja reservar?" << std::endl;
                std::cout << "Forneça os IDs separados por espaço. Ex: 15 2" << std::endl;
                std::cout << "(Se não souber, volte ao menu anterior e selecione 5)" << std::endl;
                std::cout << "X: voltar" << std::endl;

                std::getline(std::cin, entrada);
                std::cout << std::endl;

                if (entrada == "X" || entrada == "x")
                {
                    std::cout << "Voltando ao menu principal..." << std::endl;
                    break;
                }

                std::istringstream iss(entrada);
                if (!(iss >> idLivro >> idCopia) || idLivro <= 0 || idCopia <= 0)
                {
                    std::cout << "Entrada inválida! Digite IDs válidos separados por espaço." << std::endl;
                    std::cout << "Retornando ao menu principal..." << std::endl;
                    break;
                }

                professor->reservarLivro(idLivro, idCopia, acervo);
                std::cout << "Pressione enter para continuar" << std::endl;
                std::getline(std::cin, entrada);

                break;
            }

            case 2:
            {
              //std::string entrada;
              int idLivro;
              std::cout << "Qual o ID do livro que deseja renovar?" << std::endl;
              std::cout << "(Se não souber, volte ao menu anterior e selecione 5)" << std::endl;
              std::cout << "X: voltar" << std::endl;
              std::getline(std::cin, entrada);
              std::cout << std::endl;


              if (entrada == "X" || entrada == "x")
              {
                std::cout << "Voltando ao menu principal..." << std::endl;
                break;
              }

              std::istringstream iss(entrada);
              if (!(iss >> idLivro) || idLivro <= 0)
              {
                std::cout << "Entrada inválida!" << std::endl;
                std::cout << "Retornando ao menu principal..." << std::endl;
                break;
              }
              professor->renovarEmprestimo(idLivro, acervo);
              std::cout << "Pressione enter para continuar" << std::endl;
              std::getline(std::cin, entrada);
              

              break;
            }
            case 3:
            {
              professor->consultarLivrosAlugados(acervo);
              std::cout << "Pressione enter para continuar" << std::endl;
              //std::string entrada;
              std::getline(std::cin, entrada);

              break;
            }
            case 4:
            {
              professor->consultarLivrosReservados(acervo);
              std::cout << "Pressione enter para continuar" << std::endl;
              //std::string entrada;
              std::getline(std::cin, entrada);

              break;
            }
            case 5:
            {
              //std::string entrada;
              int idLivro;
              professor->consultarListaLivros(acervo);
              std::cout << "Qual o ID do livro que você deseja visualizar seus detalhes?" << std::endl;
              std::cout << "X: voltar" << std::endl;
              std::getline(std::cin, entrada);
              std::cout << std::endl;


              if (entrada == "X" || entrada == "x")
              {
                std::cout << "Voltando ao menu principal..." << std::endl;
                break;
              }

              std::istringstream iss(entrada);
              if (!(iss >> idLivro) || idLivro <= 0)
              {
                std::cout << "Entrada inválida!" << std::endl;
                std::cout << "Retornando ao menu principal..." << std::endl;
                break;
              }

              professor->exibirLivro(idLivro, acervo);
              std::cout << "Pressione enter para continuar" << std::endl;
              std::getline(std::cin, entrada);

              break;
            }

            case 6:
            {
              std::string campo, trecho;

              std::cout << "Por qual campo deseja buscar o livro?" << std::endl;
              std::cout << "1. Nome" << std::endl;
              std::cout << "2. Autor" << std::endl;
              std::cout << "3. Gênero" << std::endl;
              std::cout << "X: Voltar" << std::endl;
              std::getline(std::cin, campo);
              std::cout << std::endl;


              if (campo == "X" || campo == "x")
              {
                std::cout << "Voltando ao menu principal..." << std::endl;
                break;
              }

              int opcaoCampo;
              std::istringstream issCampo(campo);
              if (!(issCampo >> opcaoCampo) || opcaoCampo < 1 || opcaoCampo > 3)
              {
                std::cout << "Opção inválida! Digite um número válido." << std::endl;
                std::cout << "Retornando ao menu principal..." << std::endl;
                break;
              }
              std::string campoConvertido;
              if (campo == "1") {
                  campoConvertido = "nome";
              } else if (campo == "2") {
                  campoConvertido = "autor";
              } else if (campo == "3") {
                  campoConvertido = "genero";
              } else {
                  // Opção inválida, trate o caso de acordo com suas necessidades
              }

              std::cout << "Qual o trecho que deseja buscar?" << std::endl;
              std::getline(std::cin, trecho);
              std::cout << std::endl;


              professor->buscarLivro(trecho, campoConvertido, acervo);
              std::cout << "Pressione enter para continuar" << std::endl;
              //std::string entrada;
              std::getline(std::cin, entrada);

              break;
            }
            case 7:
            {
              professor->pagarMulta();
              std::cout << "Pressione enter para continuar" << std::endl;
              //std::string entrada;
              std::getline(std::cin, entrada);
              break;
            }
            case 0:
            {
              std::cout << "Tela inicial..." << std::endl;
              std::cout << "Pressione enter para continuar" << std::endl;
              //std::string entrada;
              std::getline(std::cin, entrada);
              break;
            }
            default:
            {
              std::cout << "Opção inválida!" << std::endl;
              break;
            }
          }
        } while (escolha != 0);
          break;
      } 
    case 3:
      {
        Secretario *secretario = dynamic_cast<Secretario *>(funcionarios[1]);
        int escolha;
        std::string entrada;
        std::cout << "***\n";
        std::cout << "Olá, "
                  << secretario->getNome() << std::endl;
        do
        {
          std::cout << std::endl;
          std::cout << "Selecione a ação desejada:" << std::endl;
          std::cout << "1. Cadastrar aluno" << std::endl;
          std::cout << "2. Cadastrar professor" << std::endl;
          std::cout << "3. Iniciar empréstimo de livro" << std::endl;
          std::cout << "4. Receber devolução de livro" << std::endl;
          std::cout << "5. Ver acervo" << std::endl;
          std::cout << "6. Buscar livro" << std::endl;
          std::cout << "7. Quitar multa" << std::endl;
          std::cout << "0. Tela inicial" << std::endl;
          std::cout << "Digite a opção desejada: ";
          std::cin >> escolha;
          std::cin.ignore();

          switch (escolha)
          {
            case 1:
            {
              std::string nome;
              std::string dataIngresso;
              std::string matricula;
              std::string curso;

              std::cout << "Digite o nome do aluno: ";
              std::getline(std::cin, nome);

              std::cout << "Digite a data de ingresso do aluno (DD/MM/AAAA): ";
              std::getline(std::cin, dataIngresso);

              // Verificação do formato da data de ingresso
              if (dataIngresso.size() != 10 ||
                  dataIngresso[2] != '/' || dataIngresso[5] != '/' ||
                  !isdigit(dataIngresso[0]) || !isdigit(dataIngresso[1]) ||
                  !isdigit(dataIngresso[3]) || !isdigit(dataIngresso[4]) ||
                  !isdigit(dataIngresso[6]) || !isdigit(dataIngresso[7]) ||
                  !isdigit(dataIngresso[8]) || !isdigit(dataIngresso[9]))
              {
                  std::cout << "Data de ingresso inválida! Retornando ao menu principal..." << std::endl;
                  break;
              }

              std::cout << "Digite a matrícula do aluno: ";
              std::getline(std::cin, matricula);

              std::cout << "Digite o curso do aluno: ";
              std::getline(std::cin, curso);

              std::cout << "Confirma o cadastro do aluno?" << std::endl;
              std::cout << "1. Cadastrar" << std::endl;
              std::cout << "2. Cancelar" << std::endl;
              int opcao2;
              std::cin >> opcao2;

              if (opcao2 == 1)
              {
                  secretario->cadastrarAluno(nome, dataIngresso, matricula, curso, usuarios);
                  std::cout << "Aluno cadastrado com sucesso!" << std::endl;
                  std::cout << "Pressione enter para continuar" << std::endl;
                  std::getline(std::cin, entrada);
              }
              else if (opcao2 == 2)
              {
                  std::cout << "Cadastro cancelado. Voltando ao menu principal..." << std::endl;
              }
              else
              {
                  std::cout << "Opção inválida! Retornando ao menu principal..." << std::endl;
              }
              std::cout << "Pressione enter para continuar" << std::endl;
              std::getline(std::cin, entrada);
              break;
            }

            case 2:
            {
              std::string nome;
              std::string dataIngresso;
              std::string departemto;

              std::cout << "Digite o nome do professor: ";
              std::getline(std::cin, nome);

              std::cout << "Digite a data de ingresso do professor (DD/MM/AAAA): ";
              std::getline(std::cin, dataIngresso);

              // Verificação do formato da data de ingresso
              if (dataIngresso.size() != 10 ||
                  dataIngresso[2] != '/' || dataIngresso[5] != '/' ||
                  !isdigit(dataIngresso[0]) || !isdigit(dataIngresso[1]) ||
                  !isdigit(dataIngresso[3]) || !isdigit(dataIngresso[4]) ||
                  !isdigit(dataIngresso[6]) || !isdigit(dataIngresso[7]) ||
                  !isdigit(dataIngresso[8]) || !isdigit(dataIngresso[9]))
              {
                  std::cout << "Data de ingresso inválida! Retornando ao menu principal..." << std::endl;
                  break;
              }

              std::cout << "Digite o departamento do professor: ";
              std::getline(std::cin, departamento);

              std::cout << "Confirma o cadastro do professor?" << std::endl;
              std::cout << "1. Cadastrar" << std::endl;
              std::cout << "2. Cancelar" << std::endl;
              int opcao2;
              std::cin >> opcao2;

              if (opcao2 == 1)
              {
                  secretario->cadastrarProfessor(nome, dataIngresso, departamento, usuarios);
                  std::cout << "Professor cadastrado com sucesso!" << std::endl;
                  std::cout << "Pressione enter para continuar" << std::endl;
                  std::getline(std::cin, entrada);
              }
              else if (opcao2 == 2)
              {
                  std::cout << "Cadastro cancelado. Voltando ao menu principal..." << std::endl;
              }
              else
              {
                  std::cout << "Opção inválida! Retornando ao menu principal..." << std::endl;
              }
              std::cout << "Pressione enter para continuar" << std::endl;
              std::getline(std::cin, entrada);

              break;
            }
            case 3:
            {
              int idUser, idLivro, idCopia;
              std::string entrada;

              std::cout << "Qual o ID do usuário, ID do livro e ID da cópia que deseja iniciar o empréstimo?" << std::endl;
              std::cout << "Forneça os IDs separados por espaço. Ex: 10 15 2" << std::endl;
              std::cout << "X: voltar" << std::endl;

              std::getline(std::cin, entrada);

              if (entrada == "X" || entrada == "x")
              {
                  std::cout << "Voltando ao menu principal..." << std::endl;
                  break;
              }

              std::istringstream iss(entrada);
              if (!(iss >> idUser >> idLivro >> idCopia) || idUser <= 0 || idLivro <= 0 || idCopia <= 0)
              {
                  std::cout << "Entrada inválida! Digite IDs válidos separados por espaço." << std::endl;
                  std::cout << "Retornando ao menu principal..." << std::endl;
                  break;
              }
              secretario->emprestarLivro(idUser, idLivro, idCopia, acervo, usuarios);
              std::cout << "Pressione enter para continuar" << std::endl;
              //std::string entrada;
              std::getline(std::cin, entrada);

              break;
            }
            case 4:
            {
              int idUser, idLivro, idCopia;
              std::string entrada;

              std::cout << "Qual o ID do usuário, ID do livro e ID da cópia que deseja receber a devolução?" << std::endl;
              std::cout << "Forneça os IDs separados por espaço. Ex: 10 15 2" << std::endl;
              std::cout << "X: voltar" << std::endl;

              std::getline(std::cin, entrada);

              if (entrada == "X" || entrada == "x")
              {
                  std::cout << "Voltando ao menu principal..." << std::endl;
                  break;
              }

              std::istringstream iss(entrada);
              if (!(iss >> idUser >> idLivro >> idCopia) || idUser <= 0 || idLivro <= 0 || idCopia <= 0)
              {
                  std::cout << "Entrada inválida! Digite IDs válidos separados por espaço." << std::endl;
                  std::cout << "Retornando ao menu principal..." << std::endl;
                  break;
              }
              secretario->receberDevolucao(idUser, idLivro, idCopia, acervo);
              std::cout << "Pressione enter para continuar" << std::endl;
              //std::string entrada;
              std::getline(std::cin, entrada);

              break;
            }
            case 5:
            {
              //std::string entrada;
              int idLivro;
              secretario->consultarListaLivros(acervo);
              std::cout << "Qual o ID do livro que você deseja visualizar seus detalhes?" << std::endl;
              std::cout << "X: voltar" << std::endl;
              std::getline(std::cin, entrada);
              std::cout << std::endl;


              if (entrada == "X" || entrada == "x")
              {
                std::cout << "Voltando ao menu principal..." << std::endl;
                break;
              }

              std::istringstream iss(entrada);
              if (!(iss >> idLivro) || idLivro <= 0)
              {
                std::cout << "Entrada inválida!" << std::endl;
                std::cout << "Retornando ao menu principal..." << std::endl;
                break;
              }

              secretario->exibirLivro(idLivro, acervo);
              std::cout << "Pressione enter para continuar" << std::endl;
              std::getline(std::cin, entrada);

              break;
            }

            case 6:
            {
              std::string campo, trecho;

              std::cout << "Por qual campo deseja buscar o livro?" << std::endl;
              std::cout << "1. Nome" << std::endl;
              std::cout << "2. Autor" << std::endl;
              std::cout << "3. Gênero" << std::endl;
              std::cout << "X: Voltar" << std::endl;
              std::getline(std::cin, campo);
              std::cout << std::endl;


              if (campo == "X" || campo == "x")
              {
                std::cout << "Voltando ao menu principal..." << std::endl;
                break;
              }

              int opcaoCampo;
              std::istringstream issCampo(campo);
              if (!(issCampo >> opcaoCampo) || opcaoCampo < 1 || opcaoCampo > 3)
              {
                std::cout << "Opção inválida! Digite um número válido." << std::endl;
                std::cout << "Retornando ao menu principal..." << std::endl;
                break;
              }
              std::string campoConvertido;
              if (campo == "1") {
                  campoConvertido = "nome";
              } else if (campo == "2") {
                  campoConvertido = "autor";
              } else if (campo == "3") {
                  campoConvertido = "genero";
              } else {
                  // Opção inválida, trate o caso de acordo com suas necessidades
              }
              std::cout << "Qual o trecho que deseja buscar?" << std::endl;
              std::getline(std::cin, trecho);
              std::cout << std::endl;


              secretario->buscarLivro(trecho, campoConvertido, acervo);
              std::cout << "Pressione enter para continuar" << std::endl;
              //std::string entrada;
              std::getline(std::cin, entrada);

              break;
            }
            case 7:
            {
              std::cout << "Erro.\n";
              std::cout << "Pressione enter para continuar" << std::endl;
              //std::string entrada;
              std::getline(std::cin, entrada);
              break;
            }
            case 0:
            {
              std::cout << "Tela inicial..." << std::endl;
              std::cout << "Pressione enter para continuar" << std::endl;
              //std::string entrada;
              std::getline(std::cin, entrada);
              break;
            }
            default:
            {
              std::cout << "Opção inválida!" << std::endl;
              break;
            }
          }
        } while (escolha != 0);
          break;
      }
    case 4:
      {
        Bibliotecario *bibliotecario = dynamic_cast<Bibliotecario *>(funcionarios[0]);
        int escolha;
        std::string entrada;
        std::cout << "***\n";
        std::cout << "Olá, "
                  << bibliotecario->getNome() << std::endl;
        do
        {
          std::cout << std::endl;
          std::cout << "Selecione a ação desejada:" << std::endl;
          std::cout << "1. Cadastrar aluno" << std::endl;
          std::cout << "2. Cadastrar professor" << std::endl;
          std::cout << "3. Iniciar empréstimo de livro" << std::endl;
          std::cout << "4. Receber devolução de livro" << std::endl;
          std::cout << "5. Ver acervo" << std::endl;
          std::cout << "6. Buscar livro" << std::endl;
          std::cout << "7. Ver usuários" << std::endl;
          std::cout << "8. Adicionar livro" << std::endl;
          std::cout << "9. Remover livro" << std::endl;
          std::cout << "0. Tela inicial" << std::endl;
          std::cout << "Digite a opção desejada: ";
          std::cin >> escolha;
          std::cin.ignore();

          switch (escolha)
          {
            case 1:
            {
              std::string nome;
              std::string dataIngresso;
              std::string matricula;
              std::string curso;

              std::cout << "Digite o nome do aluno: ";
              std::getline(std::cin, nome);

              std::cout << "Digite a data de ingresso do aluno (DD/MM/AAAA): ";
              std::getline(std::cin, dataIngresso);

              // Verificação do formato da data de ingresso
              if (dataIngresso.size() != 10 ||
                  dataIngresso[2] != '/' || dataIngresso[5] != '/' ||
                  !isdigit(dataIngresso[0]) || !isdigit(dataIngresso[1]) ||
                  !isdigit(dataIngresso[3]) || !isdigit(dataIngresso[4]) ||
                  !isdigit(dataIngresso[6]) || !isdigit(dataIngresso[7]) ||
                  !isdigit(dataIngresso[8]) || !isdigit(dataIngresso[9]))
              {
                  std::cout << "Data de ingresso inválida! Retornando ao menu principal..." << std::endl;
                  break;
              }

              std::cout << "Digite a matrícula do aluno: ";
              std::getline(std::cin, matricula);

              std::cout << "Digite o curso do aluno: ";
              std::getline(std::cin, curso);

              std::cout << "Confirma o cadastro do aluno?" << std::endl;
              std::cout << "1. Cadastrar" << std::endl;
              std::cout << "2. Cancelar" << std::endl;
              int opcao2;
              std::cin >> opcao2;

              if (opcao2 == 1)
              {
                  bibliotecario->cadastrarAluno(nome, dataIngresso, matricula, curso, usuarios);
                  std::cout << "Aluno cadastrado com sucesso!" << std::endl;
                  std::cout << "Pressione enter para continuar" << std::endl;
                  std::getline(std::cin, entrada);
              }
              else if (opcao2 == 2)
              {
                  std::cout << "Cadastro cancelado. Voltando ao menu principal..." << std::endl;
              }
              else
              {
                  std::cout << "Opção inválida! Retornando ao menu principal..." << std::endl;
              }
              std::getline(std::cin, entrada);
              break;
            }

            case 2:
            {
              std::string nome;
              std::string dataIngresso;
              std::string departemto;

              std::cout << "Digite o nome do professor: ";
              std::getline(std::cin, nome);

              std::cout << "Digite a data de ingresso do professor (DD/MM/AAAA): ";
              std::getline(std::cin, dataIngresso);

              // Verificação do formato da data de ingresso
              if (dataIngresso.size() != 10 ||
                  dataIngresso[2] != '/' || dataIngresso[5] != '/' ||
                  !isdigit(dataIngresso[0]) || !isdigit(dataIngresso[1]) ||
                  !isdigit(dataIngresso[3]) || !isdigit(dataIngresso[4]) ||
                  !isdigit(dataIngresso[6]) || !isdigit(dataIngresso[7]) ||
                  !isdigit(dataIngresso[8]) || !isdigit(dataIngresso[9]))
              {
                  std::cout << "Data de ingresso inválida! Retornando ao menu principal..." << std::endl;
                  break;
              }

              std::cout << "Digite o departamento do professor: ";
              std::getline(std::cin, departamento);

              std::cout << "Confirma o cadastro do professor?" << std::endl;
              std::cout << "1. Cadastrar" << std::endl;
              std::cout << "2. Cancelar" << std::endl;
              int opcao2;
              std::cin >> opcao2;

              if (opcao2 == 1)
              {
                  bibliotecario->cadastrarProfessor(nome, dataIngresso, departamento, usuarios);
                  std::cout << "Professor cadastrado com sucesso!" << std::endl;
                  std::cout << "Pressione enter para continuar" << std::endl;
                  std::getline(std::cin, entrada);
              }
              else if (opcao2 == 2)
              {
                  std::cout << "Cadastro cancelado. Voltando ao menu principal..." << std::endl;
              }
              else
              {
                  std::cout << "Opção inválida! Retornando ao menu principal..." << std::endl;
              }

              std::getline(std::cin, entrada);

              break;
            }
            case 3:
            {
              int idUser, idLivro, idCopia;
              std::string entrada;

              std::cout << "Qual o ID do usuário, ID do livro e ID da cópia que deseja iniciar o empréstimo?" << std::endl;
              std::cout << "Forneça os IDs separados por espaço. Ex: 10 15 2" << std::endl;
              std::cout << "X: voltar" << std::endl;

              std::getline(std::cin, entrada);

              if (entrada == "X" || entrada == "x")
              {
                  std::cout << "Voltando ao menu principal..." << std::endl;
                  break;
              }

              std::istringstream iss(entrada);
              if (!(iss >> idUser >> idLivro >> idCopia) || idUser <= 0 || idLivro <= 0 || idCopia <= 0)
              {
                  std::cout << "Entrada inválida! Digite IDs válidos separados por espaço." << std::endl;
                  std::cout << "Retornando ao menu principal..." << std::endl;
                  break;
              }
              bibliotecario->emprestarLivro(idUser, idLivro, idCopia, acervo, usuarios);
              std::cout << "Pressione enter para continuar" << std::endl;
              //std::string entrada;
              std::getline(std::cin, entrada);

              break;
            }
            case 4:
            {
              int idUser, idLivro, idCopia;
              std::string entrada;

              std::cout << "Qual o ID do usuário, ID do livro e ID da cópia que deseja receber a devolução?" << std::endl;
              std::cout << "Forneça os IDs separados por espaço. Ex: 10 15 2" << std::endl;
              std::cout << "X: voltar" << std::endl;

              std::getline(std::cin, entrada);

              if (entrada == "X" || entrada == "x")
              {
                  std::cout << "Voltando ao menu principal..." << std::endl;
                  break;
              }

              std::istringstream iss(entrada);
              if (!(iss >> idUser >> idLivro >> idCopia) || idUser <= 0 || idLivro <= 0 || idCopia <= 0)
              {
                  std::cout << "Entrada inválida! Digite IDs válidos separados por espaço." << std::endl;
                  std::cout << "Retornando ao menu principal..." << std::endl;
                  break;
              }
              bibliotecario->receberDevolucao(idUser, idLivro, idCopia, acervo);
              std::cout << "Pressione enter para continuar" << std::endl;
              //std::string entrada;
              std::getline(std::cin, entrada);

              break;
            }
            case 5:
            {
              //std::string entrada;
              int idLivro;
              bibliotecario->consultarListaLivros(acervo);
              std::cout << "Qual o ID do livro que você deseja visualizar seus detalhes?" << std::endl;
              std::cout << "X: voltar" << std::endl;
              std::getline(std::cin, entrada);
              std::cout << std::endl;


              if (entrada == "X" || entrada == "x")
              {
                std::cout << "Voltando ao menu principal..." << std::endl;
                break;
              }

              std::istringstream iss(entrada);
              if (!(iss >> idLivro) || idLivro <= 0)
              {
                std::cout << "Entrada inválida!" << std::endl;
                std::cout << "Retornando ao menu principal..." << std::endl;
                break;
              }

              bibliotecario->exibirLivro(idLivro, acervo);
              std::cout << "Pressione enter para continuar" << std::endl;
              std::getline(std::cin, entrada);

              break;
            }

            case 6:
            {
              std::string campo, trecho;

              std::cout << "Por qual campo deseja buscar o livro?" << std::endl;
              std::cout << "1. Nome" << std::endl;
              std::cout << "2. Autor" << std::endl;
              std::cout << "3. Gênero" << std::endl;
              std::cout << "X: Voltar" << std::endl;
              std::getline(std::cin, campo);
              std::cout << std::endl;


              if (campo == "X" || campo == "x")
              {
                std::cout << "Voltando ao menu principal..." << std::endl;
                break;
              }

              int opcaoCampo;
              std::istringstream issCampo(campo);
              if (!(issCampo >> opcaoCampo) || opcaoCampo < 1 || opcaoCampo > 3)
              {
                std::cout << "Opção inválida! Digite um número válido." << std::endl;
                std::cout << "Retornando ao menu principal..." << std::endl;
                break;
              }
              std::string campoConvertido;
              if (campo == "1") {
                  campoConvertido = "nome";
              } else if (campo == "2") {
                  campoConvertido = "autor";
              } else if (campo == "3") {
                  campoConvertido = "genero";
              } else {
                  // Opção inválida, trate o caso de acordo com suas necessidades
              }

              std::cout << "Qual o trecho que deseja buscar?" << std::endl;
              std::getline(std::cin, trecho);
              std::cout << std::endl;


              bibliotecario->buscarLivro(trecho, campoConvertido, acervo);
              std::cout << "Pressione enter para continuar" << std::endl;
              //std::string entrada;
              std::getline(std::cin, entrada);

              break;
            }
            case 7:
            {
              bibliotecario->visualizarUsuarios(usuarios);
              std::cout << "Pressione enter para continuar" << std::endl;
              //std::string entrada;
              std::getline(std::cin, entrada);
              break;
            }
            case 8:
            {
              std::string nome;
              std::string autor;
              std::string genero;
              int edicao;

              std::cout << "Digite o nome do livro: ";
              std::getline(std::cin, nome);

              std::cout << "Digite o autor do livro: ";
              std::getline(std::cin, autor);

              std::cout << "Digite o gênero do livro: ";
              std::getline(std::cin, genero);

              std::cout << "Digite o número da edição do livro: ";
              std::string edicaoStr;
              std::getline(std::cin, edicaoStr);

              try {
                  edicao = std::stoi(edicaoStr);
              } catch (const std::invalid_argument&) {
                  std::cout << "Número de edição inválido! Retornando ao menu principal..." << std::endl;
                  break;
              }

              InfoLivro infoLivro(nome, autor, edicao, genero);
              bibliotecario->cadastrarLivro(infoLivro, acervo);

              std::cout << "Pressione enter para continuar" << std::endl;
              std::getline(std::cin, entrada);
              break;
            }
            case 9:
            {
              int idLivro, idCopia;
                std::string entrada;

                std::cout << "Qual o ID do livro e da cópia que deseja remover?" << std::endl;
                std::cout << "Forneça os IDs separados por espaço. Ex: 15 2" << std::endl;
                std::cout << "(Se não souber, volte ao menu anterior e selecione 5)" << std::endl;
                std::cout << "X: voltar" << std::endl;

                std::getline(std::cin, entrada);
                std::cout << std::endl;

                if (entrada == "X" || entrada == "x")
                {
                    std::cout << "Voltando ao menu principal..." << std::endl;
                    break;
                }

                std::istringstream iss(entrada);
                if (!(iss >> idLivro >> idCopia) || idLivro <= 0 || idCopia <= 0)
                {
                    std::cout << "Entrada inválida! Digite IDs válidos separados por espaço." << std::endl;
                    std::cout << "Retornando ao menu principal..." << std::endl;
                    break;
                }
                //std::cout<< idLivro << idCopia;
                bibliotecario->removerLivro(idLivro, idCopia, acervo);
                std::cout << "Pressione enter para continuar" << std::endl;
                std::getline(std::cin, entrada);

              break;
            }
            case 0:
            {
              std::cout << "Tela inicial..." << std::endl;
              std::cout << "Pressione enter para continuar" << std::endl;
              //std::string entrada;
              std::getline(std::cin, entrada);
              break;
            }
            default:
            {
              std::cout << "Opção inválida!" << std::endl;
              break;
            }
          }
        } while (escolha != 0);
          break;
      }

    } //FIM DO SWITCH DE ESCOLHER USUARIO


  //FIM DO LOOP DE ESCOLHER USUARIO  
  } while (opcao != 0);

return 0;
}