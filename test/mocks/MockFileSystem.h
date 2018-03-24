//
// Created by Fedorov, Alex on 2/23/18.
//

#ifndef MARKOS_MOCKFILESYSTEM_H
#define MARKOS_MOCKFILESYSTEM_H

#include <filesystem/FileSystem.h>
#include "gmock/gmock.h"
class MockFileSystem : public FileSystem {
public:
    MOCK_METHOD1(openFile,
                 Pointer<File>(const char *path));
    MOCK_METHOD1(deleteFile,
                 void(const char *path));
    MOCK_METHOD1(createDirectory,
                 void(const char *path));
};

#endif //MARKOS_MOCKFILESYSTEM_H
