//
// Created by Oleksandra Baukh on 12/13/17.
//

#ifndef MARK1_LOGGER_H
#define MARK1_LOGGER_H


class Logger {
private:
public:
    virtual ~Logger() {}

    virtual Logger *logAppend(const char *c)= 0;

    virtual Logger *logAppend(int number)= 0;

    virtual Logger *logAppend(long number)= 0;

    virtual Logger *newLine()= 0;
};

#endif //MARK1_LOGGER_H
