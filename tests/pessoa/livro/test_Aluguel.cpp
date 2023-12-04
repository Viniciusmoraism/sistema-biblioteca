#include "doctest.h"
#include "Aluguel.hpp"

TEST_CASE("Teste Construtor e Getters") {
    Aluguel aluguel;

    CHECK_EQ(aluguel.getIdLivro(), -1);
    CHECK_EQ(aluguel.getIdCopia(), -1);
    CHECK_EQ(aluguel.getRenovacoes(), 0);
}

TEST_CASE("Teste Setters e Getters") {
    Aluguel aluguel;

    aluguel.setIdLivro(123);
    aluguel.setIdCopia(456);
    aluguel.setRenovacoes(2);

    CHECK_EQ(aluguel.getIdLivro(), 123);
    CHECK_EQ(aluguel.getIdCopia(), 456);
    CHECK_EQ(aluguel.getRenovacoes(), 2);
}

TEST_CASE("Teste Operador de Igualdade") {
    Aluguel aluguel1;
    aluguel1.setIdLivro(123);

    Aluguel aluguel2;
    aluguel2.setIdLivro(123);

    Aluguel aluguel3;
    aluguel3.setIdLivro(456);

    CHECK_EQ(aluguel1 == aluguel2, true);
    CHECK_EQ(aluguel1 == aluguel3, false);
}