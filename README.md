# CrunchBound

CrunchBound is a game made with SDL3 in C++.

> [!NOTE]
> The game is currently in development and not anywhere near finished.

## Installation

Depending on your preferences, the game can be built from source, or you can use either the Arch Linux Package, or the AppImage file provided.

### AppImage
The easiest one is the appimage, just download the file from the releases page and run the file:

```
./crunchbound.AppImage
```

> [!IMPORTANT]
> Appimages require fuse to run. Install fuse on the system before executing it. On Ubuntu run `sudo apt install libfuse2` and on Arch `sudo pacman -S fuse2`. On other distributions, please consult their instructions.

All dependencies are packaged directly into the AppImage file, so there is no need to install anything, aside from a GUI to render the window and a basic Linux system.

### Arch Linux Package

If you use the built Arch Linux Package, you will need to install the dependencies onto your system.
CrunchBound uses some libraries currently only available on the AUR. I will be using yay as an AUR helper. 
Installation instructions for yay can be found here: [Yay Installation](https://github.com/Jguer/yay?tab=readme-ov-file#installation)

Install the packages using yay (as always, check PKGBUILD before downloading things from the AUR):
```
yay -S sdl3 sdl3_image sdl3_ttf-git
```

Then install the downloaded Arch Package:
```
sudo pacman -U crunchbound-{version}-{arch}.pkg.tar.zst
```
(Replace {version} and {arch} with appropriate values)

### Building from source

To build from source, please check out the [compilation guide](https://lightjack05.github.io/CrunchBound/docs/d6/dd0/md_BUILDING.html).
