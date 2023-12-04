#include "doctest.h"
#include "Copia.hpp"
#include <sstream>


TEST_CASE("Teste Construtor e Getters") {
    Copia copia(123);

    CHECK_EQ(copia.getIdCopia(), 123);
    CHECK_EQ(copia.isDisponivel(), true);
    CHECK_EQ(copia.isReservado(), false);
    CHECK_EQ(copia.getDataEmprestimo(), "");
    CHECK_EQ(copia.getDataDevolucao(), "");
    CHECK_EQ(copia.getDataLimiteReserva(), "");
}

TEST_CASE("Teste Setters e Getters") {
    Copia copia(123);

    copia.setEmprestimo(456);
    copia.setReserva(789);
    copia.setDataEmprestimo("2023-01-01");
    copia.setDataDevolucao("2023-01-15");
    copia.setDataLimiteReserva("2023-01-31");

    CHECK_EQ(copia.getIdCopia(), 123);
    CHECK_EQ(copia.isDisponivel(), false);
    CHECK_EQ(copia.isReservado(), true);
    CHECK_EQ(copia.getDataEmprestimo(), "2023-01-01");
    CHECK_EQ(copia.getDataDevolucao(), "2023-01-15");
    CHECK_EQ(copia.getDataLimiteReserva(), "2023-01-31");
}

TEST_CASE("Teste Informacoes") {
    Copia copia(123);

    copia.setEmprestimo(456);
    copia.setReserva(789);
    copia.setDataEmprestimo("2023-01-01");
    copia.setDataDevolucao("2023-01-15");

    std::stringstream output;
    std::streambuf* oldOutput = std::cout.rdbuf(output.rdbuf());

    copia.informacoes();

    std::string expectedOutput = "123\tNAO\tSIM\t2023-01-01\t2023-01-15\n";
    CHECK_EQ(output.str(), expectedOutput);

    std::cout.rdbuf(oldOutput);
}