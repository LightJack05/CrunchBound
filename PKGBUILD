pkgname=crunchbound
pkgver=0.0.1
pkgrel=1
pkgdesc="Endless runner build with SDL3"
arch=('x86_64')
license=('MIT')
depends=('gcc' 'sdl3' 'root' 'sdl3_image')
makedepends=('make' 'pkgconf')
source=("source.tar.gz")
sha256sums=('SKIP')

build() {
    cd "$srcdir"
    
    # Ensure any environment-specific flags are loaded for root and SDL3
    export CPPFLAGS="$(root-config --cflags)"
    export LDFLAGS="$(root-config --ldflags)"
    export LDLIBS="$(root-config --libs)"
    export SDL3FLAGS="$(pkg-config sdl3 --cflags --libs)"

    # Build the project using the Makefile
    make release -j32
}

package() {
    cd "$srcdir"
    
    # Install binary
    install -Dm755 "bin/$pkgname" "$pkgdir/usr/bin/$pkgname"
    
    # Install assets from the assets directory
    install -d "$pkgdir/usr/share/$pkgname/assets"
    cp -r assets/* "$pkgdir/usr/share/$pkgname/assets/"
    
    # Optionally include the license
    #install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

# Optional checksums can be replaced with the actual ones if required
# sha256sums=('actualchecksumvalue')
