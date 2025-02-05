#ifndef COMPONENTNOTFOUNDEXCEPTION_HPP
#define COMPONENTNOTFOUNDEXCEPTION_HPP

#include <exception>
class ComponentNotFoundException : public std::exception {
  public:
    const char *what();
};

#endif // COMPONENTNOTFOUNDEXCEPTION_HPP
