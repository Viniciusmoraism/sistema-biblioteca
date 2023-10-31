# Sistema de Biblioteca Avançado
Esse é um programa de gerenciamento de biblioteca desenvolvido na discplina PDS2 da UFMG. Nesse programa é possivel realizar um gerenciamento de livros a partir de um acervo.O sistema divide os usuários a partir de uma classe base, e cada um possui diferentes opções de gerenciamento, como realizar cadastro, consultar disponibilidade de livros, alugar, reservar, etc.

# Ferramentas

* Linguagem: [C++11](https://cplusplus.com/doc/)
* Compilação: [Make](https://www.gnu.org/software/make/)
* Documentação: [Doxygen](https://doxygen.nl/)
* Testes Unitários: [Doctest](https://github.com/doctest/doctest)

# User Story - Sistema de Biblioteca
Cada usuario possui diferentes atribuições.

#Como aluno e professor:

-> Reservar um livro.

-> Renovar um Livro.

-> Ver livros alugados e data de entrega.

-> Consultar livros no acervo.

-> Pagar multa.

#Como Gestor:

-> Cadastar novo usuario.

-> Iniciar proceso de multa/ Quitar uma multa.

-> Iniciar empresimo de livro/Receber devolução.

-> Consultar livros no acervo.

#Como Bibliotecario:

-> Cadastrar novos livros (inlcui autor, id e categoria).

-> Remover livros.

-> Consultar livros no acervo.

# CRC´s




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
