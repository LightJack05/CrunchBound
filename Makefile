CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)
LDLIBS=$(shell root-config --libs)
SDL3FLAGS=$(shell pkg-config sdl3 --cflags --libs)

PROJ=proj

SRCS=$(shell find . -name '*.cpp')
OBJDIR=./obj
BINDIR=./bin
OBJS=$(patsubst ./%.cpp, $(OBJDIR)/%.o, $(SRCS))

all: $(BINDIR)/$(PROJ)

$(BINDIR)/$(PROJ): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CXX) -Wall $(LDFLAGS) -o $(BINDIR)/$(PROJ) $(OBJS) $(LDLIBS) $(SDL3FLAGS)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -c $< -o $@

depend: .depend

.depend: $(SRCS)
	$(RM) ./.depend
	$(CXX) $(CPPFLAGS) -MM $^ | sed 's,\(\w\+\)\.o,$(OBJDIR)/\1.o,g' >> ./.depend

clean:
	$(RM) $(OBJS)
	$(RM) $(BINDIR)/$(PROJ)

distclean: clean
	$(RM) *~ .depend

include .depend
