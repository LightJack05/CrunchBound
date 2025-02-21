CC=gcc
CXX=g++
RM=rm -rf
PROFILER=heaptrack
CPPFLAGS=-g -O0 $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)
LDLIBS=$(shell root-config --libs)
SDL3FLAGS=$(shell pkg-config sdl3 --cflags --libs)

PROJ=CrunchBound

SRCS=$(shell find . -name '*.cpp')
OBJDIR=./obj
BINDIR=./bin
OBJS=$(patsubst ./%.cpp, $(OBJDIR)/%.o, $(SRCS))
APPIMAGEDIR=./package/appimage/$(PROJ).AppDir
APPIMAGE=./package/appimage/$(PROJ).AppImage
ARCHPACKAGEDIR=./package/arch/

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
	@$(RM) $(APPIMAGEDIR)
	@$(RM) $(APPIMAGE)
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

appimage: all
	@echo "Packaging project into AppDir..."
	@mkdir -p $(APPIMAGEDIR)/usr/bin
	@mkdir -p $(APPIMAGEDIR)/usr/lib
	@mkdir -p $(APPIMAGEDIR)/usr/share/icons/hicolor/256x256/apps
	@mkdir -p $(APPIMAGEDIR)/usr/share/applications
	
	@cp $(BINDIR)/$(PROJ) $(APPIMAGEDIR)/usr/bin/
	
	@echo "Creating AppRun..."
	@echo '#!/bin/bash' > $(APPIMAGEDIR)/AppRun
	@echo 'HERE="$$(dirname "$$(readlink -f "$$0")")"' >> $(APPIMAGEDIR)/AppRun
	@echo 'exec "$$HERE/usr/bin/$(PROJ)" "$$@"' >> $(APPIMAGEDIR)/AppRun
	@chmod +x $(APPIMAGEDIR)/AppRun
	
	@echo "Creating .desktop file..."
	@echo '[Desktop Entry]' > $(APPIMAGEDIR)/$(PROJ).desktop
	@echo 'Name=CrunchBound' >> $(APPIMAGEDIR)/$(PROJ).desktop
	@echo 'Exec=CrunchBound' >> $(APPIMAGEDIR)/$(PROJ).desktop
	@echo 'Icon=CrunchBound' >> $(APPIMAGEDIR)/$(PROJ).desktop
	@echo 'Type=Application' >> $(APPIMAGEDIR)/$(PROJ).desktop
	@echo 'Categories=Game;' >> $(APPIMAGEDIR)/$(PROJ).desktop
	@cp -v $(APPIMAGEDIR)/$(PROJ).desktop $(APPIMAGEDIR)/usr/share/applications/

	@echo "Copying icon..."
	@cp -v ./icon.png $(APPIMAGEDIR)/CrunchBound.png || echo "Icon not found, skipping..."
	
	@echo "Copying required libraries..."
	@ldd $(BINDIR)/$(PROJ) | grep "=> /" | awk '{print $$3}' | xargs -I '{}' cp -v '{}' $(APPIMAGEDIR)/usr/lib/ || echo "No libraries to copy."

	@echo "Creating AppImage..."
	@ARCH=x86_64 appimagetool $(APPIMAGEDIR) $(APPIMAGE)

	@echo "AppImage created at: $(APPIMAGE)"
