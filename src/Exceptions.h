#ifndef LANCEUR_RAYONS_EXCEPTIONS_H
#define LANCEUR_RAYONS_EXCEPTIONS_H

#include <exception>
#include <string>

class ExceptionWithMsg : public std::exception {
public:
    explicit ExceptionWithMsg(std::string msg);

private:
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;

protected:
    std::string msg;
};

class ImageException : public ExceptionWithMsg {
public:
    explicit ImageException(const std::string &msg);
};

class FileException : public ExceptionWithMsg {
public:
    explicit FileException(const std::string &msg);
};

class SyntaxException : public ExceptionWithMsg {
private:
    unsigned long long line=-1;
    std::string result;
    const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
public:
    explicit SyntaxException(const std::string &msg);
    void setLine(unsigned long long int newLine);
};

#endif //LANCEUR_RAYONS_EXCEPTIONS_H
