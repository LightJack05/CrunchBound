CC=gcc
CXX=g++
RM=rm -f
PROFILER=heaptrack
CPPFLAGS=-g -O0 $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)
LDLIBS=$(shell root-config --libs)
SDL3FLAGS=$(shell pkg-config sdl3 --cflags --libs)

PROJ=cpp-project

SRCS=$(shell find . -name '*.cpp')
OBJDIR=./obj
BINDIR=./bin
OBJS=$(patsubst ./%.cpp, $(OBJDIR)/%.o, $(SRCS))

.PHONY: docs

all: $(BINDIR)/$(PROJ)

$(BINDIR)/$(PROJ): $(OBJS)
	@echo ""
	@echo "Linking... "
	@mkdir -p $(BINDIR)
	$(CXX) -Wall $(LDFLAGS) -o $(BINDIR)/$(PROJ) $(OBJS) $(LDLIBS) $(SDL3FLAGS)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CPPFLAGS) -c $< -o $@
	@echo "    CXX $<"

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^ | sed 's,\(\w\+\)\.o,$(OBJDIR)/\1.o,g' >> ./.depend
	@echo ""

clean:
	@echo "RM $(OBJS)"
	@$(RM) $(OBJS)
	@echo "RM $(BINDIR)/$(PROJ)"
	@$(RM) $(BINDIR)/$(PROJ)

distclean: clean
	@echo "RM .depend"
	@$(RM) *~ .depend

include .depend

run: all
	$(BINDIR)/$(PROJ)

profile: all
	$(PROFILER) $(BINDIR)/$(PROJ)

rebuild: distclean all

docs:
	doxygen doxygen.conf
