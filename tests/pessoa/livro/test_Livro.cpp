#include "doctest.h"
#include "Livro.hpp"

TEST_CASE("Teste Construtor e Getters") {
    InfoLivro infoLivro("Título", "Autor", 1, "Gênero");
    Livro livro(infoLivro);

    CHECK_EQ(livro.getIdLivro(), 1);
    CHECK_EQ(livro.getInfoLivro().getNome(), "Título");
    CHECK_EQ(livro.getInfoLivro().getAutor(), "Autor");
    CHECK_EQ(livro.getInfoLivro().getGenero(), "Gênero");
    CHECK_EQ(livro.getInfoLivro().getEdicao(), 1);
    CHECK_EQ(livro.getTotalCopias(), 0);
}

TEST_CASE("Teste Adicionar e Encontrar Cópia") {
    InfoLivro infoLivro("Título", "Autor", 1, "Gênero");
    Livro livro(infoLivro);

    CHECK_EQ(livro.getTotalCopias(), 0);

    livro.adicionarCopia();
    livro.adicionarCopia();

    CHECK_EQ(livro.getTotalCopias(), 2);

    std::vector<Copia> copias = livro.getCopias();
}

TEST_CASE("Teste Remover Cópia") {
    InfoLivro infoLivro("Título", "Autor", 1, "Gênero");
    Livro livro(infoLivro);

    livro.adicionarCopia();
    livro.adicionarCopia();

    CHECK_EQ(livro.getTotalCopias(), 2);

    std::vector<Copia> copias = livro.getCopias();

    livro.removerCopia(copias[0].getIdCopia());

    CHECK_EQ(livro.getTotalCopias(), 1);

    livro.removerCopia(3); // Tentativa de remover cópia inexistente

    CHECK_EQ(livro.getTotalCopias(), 1);
}