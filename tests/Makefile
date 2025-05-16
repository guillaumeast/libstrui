# ------------ CONFIG ---------------
CXX       	:= g++
CXXFLAGS  	:= -std=c++17 -Wall -Wextra -pedantic

BREW_PREFIX := $(shell command -v brew >/dev/null 2>&1 && brew --prefix || echo "")
INCLUDES    := -I../include $(if $(BREW_PREFIX),-I$(BREW_PREFIX)/include)
LIBS        := $(if $(BREW_PREFIX),-L$(BREW_PREFIX)/lib) -lunistring

TEST_SRC  	:= test.cpp
TEST_BIN  	:= test

# ------------ RULES ----------------

test: $(TEST_SRC)
	@echo "\n🚧 Compiling test binary...\n"
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(TEST_SRC) -o $(TEST_BIN) $(LIBS)
	@echo "\n🚀 Running tests:"
	@./$(TEST_BIN)
	@echo "🧹 Cleaning up..."
	@rm -f $(TEST_BIN)

clean:
	rm -f $(TEST_BIN)

.PHONY: test clean
