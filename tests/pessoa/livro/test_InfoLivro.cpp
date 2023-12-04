#include "doctest.h"
#include "InfoLivro.hpp"

TEST_CASE("Teste da classe InfoLivro") {
    InfoLivro livro1("Harry Potter", "J.K. Rowling", 1, "Fantasia");
    InfoLivro livro2("Dom Casmurro", "Machado de Assis", 5, "Romance");

    CHECK_EQ(livro1.getNome(), "Harry Potter");
    CHECK_EQ(livro1.getAutor(), "J.K. Rowling");
    CHECK_EQ(livro1.getGenero(), "Fantasia");
    CHECK_EQ(livro1.getEdicao(), 1);

    CHECK_EQ(livro2.getNome(), "Dom Casmurro");
    CHECK_EQ(livro2.getAutor(), "Machado de Assis");
    CHECK_EQ(livro2.getGenero(), "Romance");
    CHECK_EQ(livro2.getEdicao(), 5);

    CHECK(livro1 == livro1);
    CHECK(livro2 == livro2);
    CHECK_FALSE(livro1 == livro2);
    CHECK_FALSE(livro2 == livro1);
}