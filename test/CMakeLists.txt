cmake_minimum_required(VERSION 3.10)
project(MarkI_tests)

add_executable(${PROJECT_NAME}
        main.cpp
        mocks/MockClock.h
        mocks/MockFileSystem.h
        modes/ModeManagerTest.h
        modes/ModeManagerTest.cpp
        controller/ControllerTest.cpp
        controller/ControllerTest.h
        controller/TestController.cpp
        controller/TestController.h
        mocks/MockModeListener.h
        mocks/MockControllerCommandListener.h
        mocks/MockController.h
        mocks/MockRandom.h
        modes/supervised/SupervisedModeTest.cpp
        modes/supervised/SupervisedModeTest.h
        mocks/MockMotorDriver.h mocks/MockObstacleSensor.h
        mocks/MockEnvironment.h
        mocks/MockFile.h
        mocks/MockMissionIdGenerator.h
        missions/InMemoryMissionManagerTest.cpp
        missions/InMemoryMissionManagerTest.h
        mocks/MockLogger.h
        mocks/PassThroughLoggerFactory.h
        mocks/MockMissionManager.h
        controller/RemoteControllerTest.cpp
        controller/RemoteControllerTest.h)

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_commons)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_communication)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_controller)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_controller_test)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_cycle)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_time)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkI)

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC gtest gtest_main)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC gmock gmock_main)
