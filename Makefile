# Makefile para o projeto Sistema de bibliotecas

# Comando de compilação
CXX = g++

# Flags de compilação
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude -Iinclude/livro -Iinclude/pessoa -Ithird_party

# Diretórios do projeto
SRCDIR = src
TESTDIR = tests
INCDIR = include
BUILDDIR = build
DOCDIR = doc

# Nome do executável
EXECUTABLE = sistema_bibliotecas
TEST_EXECUTABLE = test_sistema_bibliotecas

# Arquivos fonte
SOURCES = $(wildcard $(SRCDIR)/*.cpp $(SRCDIR)/livro/*.cpp $(SRCDIR)/pessoa/*.cpp) #$(filter-out $(SRCDIR)/Secretario.cpp $(SRCDIR)/Bibliotecario.cpp,$(wildcard $(SRCDIR)/*.cpp $(SRCDIR)/livro/*.cpp $(SRCDIR)/pessoa/*.cpp))#
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
TEST_SOURCES = $(wildcard $(TESTDIR)/*.cpp $(TESTDIR)/livro/*.cpp $(TESTDIR)/pessoa/*.cpp)
TEST_OBJECTS = $(patsubst $(TESTDIR)/%.cpp,$(BUILDDIR)/%.o,$(TEST_SOURCES))


# Excluindo Secretario.cpp e Bibliotecario.cpp
#SOURCES := $(filter-out $(SRCDIR)/pessoa/Secretario.cpp,$(SOURCES))
#SOURCES := $(filter-out $(SRCDIR)/pessoa/Bibliotecario.cpp,$(SOURCES))
#OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
# Excluindo Secretario.cpp e Bibliotecario.cpp
#TEST_SOURCES := $(filter-out $(TESTDIR)/pessoa/Secretario.cpp,$(TEST_SOURCES))
#TEST_SOURCES := $(filter-out $(TESTDIR)/pessoa/Bibliotecario.cpp,$(TEST_SOURCES))
#TEST_OBJECTS = $(patsubst $(TESTDIR)/%.cpp,$(BUILDDIR)/%.o,$(TEST_SOURCES))

# Inclusões
INCLUDES = -I$(INCDIR)

# Linkagem
LDFLAGS =

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $(EXECUTABLE)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(TEST_EXECUTABLE): $(OBJECTS) $(TEST_OBJECTS)
	$(CXX) $(OBJECTS) $(TEST_OBJECTS) $(LDFLAGS) -o $(TEST_EXECUTABLE)

$(BUILDDIR)/%.o: $(TESTDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

docs:
	$(DOXYGEN) $(DOCDIR)/Doxyfile

clean:
	rm -rf $(BUILDDIR)/*.o $(EXECUTABLE) $(TEST_EXECUTABLE) $(DOCDIR)/html
	

.PHONY: all clean docs test
# MAKE
