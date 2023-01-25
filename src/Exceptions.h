#ifndef LANCEUR_RAYONS_EXCEPTIONS_H
#define LANCEUR_RAYONS_EXCEPTIONS_H

#include <exception>
#include <string>

class ExceptionWithMsg : public std::exception {
public:
    explicit ExceptionWithMsg(std::string msg);

private:
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
private :
    std::string msg;
};

class ImageException : public ExceptionWithMsg {
public:
    explicit ImageException(const std::string &msg);
};

#endif //LANCEUR_RAYONS_EXCEPTIONS_H
