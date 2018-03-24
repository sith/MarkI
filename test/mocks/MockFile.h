
//
// Created by Fedorov, Alex on 2/23/18.
//

#ifndef MARKOS_MOCKFILE_H
#define MARKOS_MOCKFILE_H

#include <filesystem/File.h>
#include "gmock/gmock.h"

class MockFile : public File {
public:
    MOCK_METHOD0(readNextInt8,
                 int8());

    MOCK_METHOD0(readNextInt16,
                 int16());

    MOCK_METHOD0(readNextChar,
                 char());

    MOCK_METHOD1(writeInt8,
                 void(
                         const int8 number));

    MOCK_METHOD1(writeInt16,
                 void(
                         const int16 number));

    MOCK_METHOD1(writeChar,
                 void(
                         const char aChar));

    MOCK_METHOD1(writeString,
                 void(
                         const char *aChar));
};


#endif //MARKOS_MOCKFILE_H
