//
// Created by Михаил Баклыков on 22.04.2022.
//

#pragma once
#include <cstdio>
#include <cstring>
#include <exception>

class SysCallException : public std::exception {
public:
    int sys_errno;
    const char *file;
    explicit SysCallException(int n, const char * file = nullptr) : sys_errno(n), file(file) {

    }

    void print() const {
        if(file != nullptr){
            fprintf(stderr, "Error: %s [%s]", strerror(sys_errno), file);
        } else {
            fprintf(stderr, "Error: %s", strerror(sys_errno));
        }
    }
};
