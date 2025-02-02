#include "ComponentNotFoundException.hpp"

const char *ComponentNotFoundException::what() {
    return "The Component type was not found, so no operation could be performed.";
}
