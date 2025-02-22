#include "GameObjectNotFoundException.hpp"

const char *GameObjectNotFoundException::what() {
    return "The GameObject was not found, so no operation could be "
           "performed.";
}
