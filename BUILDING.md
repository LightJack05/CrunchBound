# CrunchBound compilation guide

If you would like to build crunchbound from source, please follow the instructions in this file. If you encounter any issues, please do not hesitate to open an issue on GitHub.

> [!NOTE]
> This guide will assume you are using an Arch Linux System. If you are not, please make sure you adapt the steps as needed to set up everything on your distro. The dependencies stay the same, but they may be installed in a different way.
> If your distribution does not provide you with a package for the dependencies, please refer directly to the library documentation for installation instructions.

## Build time dependencies
CrunchBound uses shared libraries and needs them installed at compile- and runtime. 
The required libraries are:
- glibc / glibc++
- sdl3 [[PKGBUILD](https://gitlab.archlinux.org/archlinux/packaging/packages/sdl3/-/blob/main/PKGBUILD?ref_type=heads)]
    - glibc
    - libxext
    - libxrender
    - libx11
    - libgl
    - libxcursor
    - hidapi
    - libusb
- sdl3-image [[PKGBUILD](https://aur.archlinux.org/cgit/aur.git/tree/PKGBUILD?h=sdl3_image)]
    - libpng
    - libtiff
    - libjpeg
    - libwebp
    - libavif
    - libjxl
- sdl3-ttf [[PKGBUILD](https://aur.archlinux.org/cgit/aur.git/tree/PKGBUILD?h=sdl3_ttf-git)]
    - freetype2
    - harfbuzz

In addition to the shared libraries, the following packages are required (these include configuration tools and compilers):
- base-devel
    - This package includes the required tools:
        - gcc
        - g++
        - make
        - pkgconf
        - ldd
        - sed
- findutils
    - This package includes the required tools:
        - xargs
- gawk
    - This package includes the required tools:
        - awk
- tar
- grep
- Fundamental Linux system utilities, such as: 
    - cp
    - mv
    - rm
    - bash
    - chmod
    - mkdir 

> [!IMPORTANT]
> This list does not include makedepends for the libraries, such as cmake or ninja! Please aquire those from the library documentation page. 
> The PKGBUILD has those packages listed for Arch Linux.


To install these dependencies, we will use the yay AUR helper. 
Please install yay according to these instructions and then continue here:
[Yay Installation](https://github.com/Jguer/yay?tab=readme-ov-file#installation)

Install the build- and runtime dependencies using yay (as always, check PKGBUILD before downloading things from the AUR):
```
yay -S sdl3 sdl3_image sdl3_ttf-git base-devel pkgconf findutils gawk tar grep
```

That's it, you're all set up to build CrunchBound now!

## Optional dependencies

The following optional dependencies can be installed to enable full tooling via the makefile and help with development:
- heaptrack (C/C++ memory analysis tool)
- appimagetool-bin (for packaging the application to an appimage for distribution)
- doxygen + graphviz (for building the documentation)

```
yay -S heaptrack appimagetool-bin doxygen graphviz
```


## Cloning the Repository

To get the current version of the CrunchBound source code, clone the git repo to a location of your choice:

```
git clone https://github.com/LightJack05/CrunchBound.git
```

## The Makefile

CrunchBound is shipped with a Makefile that is used to automate several processes during development. Depending on what you want to achieve, you can execute a different target.

The Makefile automatically detects cpp and hpp files in the working directory.

### Building the Project into an ELF binary (with debug info)

This is probably the most common action. It will produce a binary at ./bin/crunchbound which you can then execute.
To build the binary, simply execute the following command:

```
make
```

### Cleaning the project of compiled files

If you want to remove any build files, and have a clean working area, you have multiple options. Some are more thourough that others.

#### Remove any and all files built

If you want to make sure there is nothing left of any builds, run the following command:

```
make distclean
```

This will delete:
- All .o files in ./obj/
- The generated ELF binary in ./bin/
- The entire ./package/ directory
- The .depend file containing make dependencies

#### Remove all build files, leave makedepends intact

To only remove build files but leave makedepends intact, run:

```
make clean
```

This will delete:
- All .o files in ./obj/
- The generated ELF binary in ./bin/
- The entire ./package/ directory


#### Remove only the package files

To only remove the files from the packaging process, execute:

```
make cleanpackages
```

This will delete:
- The entire ./package/ directory

### Quickly rebuild the project

To combine `make distclean` and `make`, run:

```
make rebuild
```

This is useful if you want to make sure the entire project is actually recompiled, as make sometimes does not notice changes in included files.

### Packaging CrunchBound for distribution

#### Arch Linux PKGBUILD

To package the application using PKGBUILD into an Arch Linux package, run the following command:

```
make archpackage
```

An Arch Linux package will be built to ./package/arch/

> [!IMPORTANT]
> Packaging for Arch Linux requires an Arch Linux system, including makepkg!

> [!WARNING]
> Before packaging, the entire ./package directory will be deleted using `make clean`!

#### AppImage

> [!IMPORTANT]
> Packaging to appimage requires the appimage tool installed. To install it with yay, execute: `yay -S appimagetool-bin`.

To package the application into a fully self-contained AppImage file, execute the following command:

```
make appimage
```

This will create an AppImage in ./package/appimage/.

Before the appimage is built, it will be organized into ./package/appimage/crunchbound.AppDir/. Any required libraries, as well as assets will be copied there, and then packaged into the AppImage file.

> [!WARNING]
> Before packaging, the entire ./package directory will be deleted using `make clean`!

> [!NOTE]
> If you wish to modify the directory of the AppImage directory before it is built into the squashfs AppImage, you may use `make prepare-appimage`, and then modify the contents. To then build the appimage, run `make build-appimage`.
> This may be useful for testing purposes.

#### Building all packaging formats at once

To build all available packaging formats at once, run:

```
make package
```

This will build both an AppImage and an Arch package.

> [!WARNING]
> Before packaging, the entire ./package directory will be deleted using `make clean`!


### Release and Debug

By default, `make` builds a debug version of the project using the gcc flags `-g -DDEVELOPMENT`.
If you would like to build a release version, run `make release`.

> [!CAUTION]
> In a release build, assets will be loaded from `/usr/share/crunchbound/assets`, since the DEVELOPMENT macro is not set!

By default, packaging always uses release, and all other profiles use debug.

Release builds are stripped ELF binaries without debug symbols.

### Documentation

The documentation is available on GitHub pages [here](https://lightjack05.github.io/CrunchBound/docs/d0/d30/md_README.html).

To build the Doxygen documentation, you need doxygen and graphviz (dot) installed. To install them:
```
sudo pacman -S graphviz doxygen
```

Then, build the docs:

```
make docs
```

They will be placed into `./docs/html/`. Just open the `index.html` in a browser of your choice.
