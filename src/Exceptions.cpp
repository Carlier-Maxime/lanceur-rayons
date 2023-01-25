//
// Created by Reynald on 25/01/2023.
//

#include "Exceptions.h"

#include <utility>

const char *ExceptionWithMsg::what() const noexcept {
    return msg.c_str();
}

ExceptionWithMsg::ExceptionWithMsg(std::string msg) : msg(std::move(msg)) {}

ImageException::ImageException(const std::string &msg) : ExceptionWithMsg(msg) {}
