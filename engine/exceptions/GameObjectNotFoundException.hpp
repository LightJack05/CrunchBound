#ifndef GAMEOBJECTNOTFOUNDEXCEPTION_HPP
#define GAMEOBJECTNOTFOUNDEXCEPTION_HPP

#include <exception>
/**
 * @class ComponentNotFoundException
 * @brief An exception indicating that the requested gameobject has not been found.
 *
 */
class GameObjectNotFoundException : public std::exception {
  public:
    const char *what();
};

#endif // GAMEOBJECTNOTFOUNDEXCEPTION_HPP
