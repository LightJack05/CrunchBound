# CrunchBound

CrunchBound is a game made with SDL3 in C++. The game can be run on x86_64 Linux Systems, provided that the GLIBC version is compatible with the build (see **Installation** for more information).

## How to play
You have to handle the crunch! Collect coffee to prevent your Coffee Meter from dropping to 0 and avoid bugs at the same time!
If you hit a bug, it's game over, nobody has time to fix them!

## Controls
A and D to move left and right

SPACE to jump (you have a double jump)

R to restart

## Installation

Depending on your preferences, the game can be built from source or you can use either the Arch Linux Package or the AppImage file provided.

### AppImage
The easiest one is the x86_64 appimage. Just download the file from the releases page and run the file:

```
./crunchbound.AppImage
```

> [!IMPORTANT]
> Appimages require fuse to run. Install fuse on the system before executing it. On Ubuntu run `sudo apt install libfuse2` and on Arch `sudo pacman -S fuse2`. On other distributions, please consult their instructions.

> [!WARNING]
> If your GLIBC version is very old (such as on a Debian 11 system) you may not be able to run the image compiled against a newer version. Currently, all AppImages on the releases page are built on Ubuntu 20.04 LTS. Anything that uses an older glibc version may be incompatible, although the interface is generally pretty stable. If you encounter issues, try updating to a newer glibc version.

All other dependencies are packaged directly into the AppImage file, so there is no need to install anything, aside from a GUI to render the window and a basic Linux system.

### Arch Linux Package

If you use a built Arch Linux Package, you will need to install the dependencies onto your system.
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

## License information
The license can be found under LICENSE under the Repo root folder.

During the development process, generative AI (including, but not limited to ChatGPT), has been used to create or partially create external tooling such as the Makefile, PKGBUILD and GH Actions. If generative AI was used in the Code itself, it has been made clear using comments around the generated part.

I am not responsible for any external libraries used.

## Architecture

Crunchbound uses a component model. That means the engine attaches certain components to GameObjects, which then provide certain interfaces or perform certain actions. The hierarchy of the components may be found on the documentation page of the GameObjectComponent, in the class diagram.
