# Sistema de Biblioteca Avançado
Esse é um programa de gerenciamento de biblioteca desenvolvido na discplina PDS2 da UFMG. Nesse programa é possivel realizar um gerenciamento de livros a partir de um acervo.O sistema divide os usuários a partir de uma classe base, e cada um possui diferentes opções de gerenciamento, como realizar cadastro, consultar disponibilidade de livros, alugar, reservar, etc.

# Ferramentas

* Linguagem: [C++11](https://cplusplus.com/doc/)
* Compilação: [Make](https://www.gnu.org/software/make/)
* Documentação: [Doxygen](https://doxygen.nl/)
* Testes Unitários: [Doctest](https://github.com/doctest/doctest)

# User Story - Sistema de Biblioteca
Cada usuario possui diferentes atribuições.

-> Como um aluno, quero poder buscar livros na biblioteca para encontrar materiais relevantes para os meus estudos.

-> Como um professor, desejo alugar livros da biblioteca para enriquecer meu conhecimento e ensinar meus alunos.

-> Como um secretário, quero ser capaz de cadastrar novos alunos e professores no sistema da biblioteca para manter registros precisos dos usuários.

-> Como um secretário, quero poder realizar empréstimos e receber devoluções de livros dos clientes para manter o controle de quem tem quais livros.

-> Como um gestor, quero ser capaz de adicionar novos livros ao acervo da biblioteca e remover livros antigos para manter o catálogo atualizado.

-> Como um cliente, desejo poder reservar livros específicos na biblioteca para garantir que eu possa acessá-los quando precisar



# CRC´s
# Class:livro
** Responsabilitys**

Manter informações do livro (título, autor, etc.).
Controlar o status de reserva do livro.
Rastrear as datas de empréstimo e devolução para fins de multa.

**Colaborators**

Colabora com a classe Cliente para gerenciar empréstimos e reservas.
Colabora com a classe Bibliotecário para atualizar informações do livro.

# Class:Pessoa
** Responsabilitys**

Servir como uma classe abstrata base para classes derivadas.

**Colaborators**

Colabora com as classes Cliente, Aluno, Professor, Secretário e Bibliotecário como uma superclasse com informações pessoais comuns.

# Class:Cliente
** Responsabilitys**

Manter informações pessoais do cliente.

Buscar livros na biblioteca.

Alugar e reservar livros.

**Colaborators**

Colabora com a classe Livro para gerenciar empréstimos e reservas.

# Class:Aluno
** Responsabilitys**

Estender as funcionalidades de um cliente.

Manter informações específicas do aluno (data de ingresso, matrícula, curso).

**Colaborators**

Colabora com a classe Cliente para buscar e alugar livros.

# Class:Professor
** Responsabilitys**

Estender as funcionalidades de um cliente.

Manter informações específicas do professor (data de ingresso, departamento).

**Colaborators**

Colabora com a classe Cliente para buscar e alugar livros.

# Class:Secretario
** Responsabilitys**

Manter informações pessoais do secretário.

Realizar tarefas administrativas, como cadastro de alunos e professores, empréstimos, visualização de informações, etc.

**Colaborators**

Colabora com as classes Cliente, Aluno, Professor, Bibliotecário, etc., para executar tarefas administrativas.

# Class:Secretario
** Responsabilitys**

Estender as funcionalidades de um secretário.

Gerenciar o acervo de livros, incluindo adição e remoção de livros.

**Colaborators**

Colabora com a classe Livro para atualizar o acervo de livros.










## **Compilação**

```bash
$ make
```
**Atenção: Criar antes um diretório _./build/_**

## **Execução**

```bash
$ ./sistema_bibliotecas
```

## **Compilação Testes**

```bash
$ make test
```

## **Documentação**

É necessário ter na raiz do projeto um arquivo _Doxyfile_. Um arquivo padrão pode ser gerado pelo comando:
```bash
$ doxygen -g
```

Para gerar a documentação, utilizar:

```bash
$ doxygen Doxyfile
```
ou
```bash
$ make docs
```

**Atenção: Criar antes um diretório _./doc/_**

## **Remover arquivos auxiliares**
```bash
$ make clean
```
