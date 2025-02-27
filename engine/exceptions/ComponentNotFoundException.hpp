#ifndef COMPONENTNOTFOUNDEXCEPTION_HPP
#define COMPONENTNOTFOUNDEXCEPTION_HPP

#include <exception>
/**
 * @class ComponentNotFoundException
 * @brief An exception indicating that the requested GameObjectComponent has not been found on the GameObject.
 *
 */
class ComponentNotFoundException : public std::exception {
  public:
    const char *what();
};

#endif // COMPONENTNOTFOUNDEXCEPTION_HPP
