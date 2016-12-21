EXE = wikigraph

OBJS_DIR = .objs
OBJS_OTHER = main.o

CXX = clang++
LD = clang++
WARNINGS = -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable
CXXFLAGS = -std=c++1y -stdlib=libc++ -g -O0 $(WARNINGS) -MMD -MP -c
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi

all: $(EXE)

$(OBJS_DIR)/%.o: %.cpp | $(OBJS_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(EXE):
	$(LD) $^ $(LDFLAGS) -o $@

$(EXE): $(patsubst %.o, $(OBJS_DIR)/%.o, $(OBJS_OTHER))

-include $(OBJS_DIR)/*.d

clean:
	rm -rf $(EXE) $(OBJS_DIR)

.PHONY: all clean
