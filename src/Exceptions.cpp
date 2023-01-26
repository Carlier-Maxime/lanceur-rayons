#include "Exceptions.h"

#include <utility>
#include <sstream>

const char *ExceptionWithMsg::what() const noexcept {
    return msg.c_str();
}

ExceptionWithMsg::ExceptionWithMsg(std::string msg) : msg(std::move(msg)) {}

ImageException::ImageException(const std::string &msg) : ExceptionWithMsg(msg) {}

FileException::FileException(const std::string &msg) : ExceptionWithMsg(msg) {}

SyntaxException::SyntaxException(const std::string &msg) : ExceptionWithMsg(msg) {}

void SyntaxException::setLine(unsigned long long int newLine) {
    SyntaxException::line = newLine;
    std::stringstream ss;
    ss << msg << " in line : " << line;
    result = ss.str();
}

const char *SyntaxException::what() const noexcept {
    return result.c_str();
}

BuilderException::BuilderException(const std::string &msg) : ExceptionWithMsg(msg) {}
