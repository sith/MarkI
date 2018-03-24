cmake_minimum_required(VERSION 3.9)
project(MarkI)


add_library(${PROJECT_NAME}
        src/Random.h
        src/controller/Controller.h
        src/controller/Controller.cpp
        src/environment/Environment.h
        src/environment/Environment.cpp
        src/logger/Logger.h
        src/logger/LoggerFactory.h
        src/modes/Mode.h
        src/modes/Mode.cpp
        src/modes/EmptyModeListener.h
        src/modes/EmptyModeListener.cpp
        src/modes/ModeListener.h
        src/modes/ModeName.h
        src/modes/ModeManager.h
        src/modes/ModeManager.cpp
        src/state/State.h
        src/state/standard/NoopState.h
        src/state/standard/NoopState.cpp
        src/state/DirectTransition.h
        src/state/DirectTransition.cpp
        src/state/standard/PrintState.cpp
        src/state/standard/PrintState.h
        src/state/standard/WaitState.cpp
        src/state/standard/WaitState.h
        src/controller/Command.h
        src/controller/ControllerCommandListener.h
        src/logger/LoggerFactory.cpp
        src/modes/supervised/SupervisedMode.cpp
        src/modes/supervised/SupervisedMode.h
        src/drivers/MotorDriver.h
        src/sensors/ObstacleSensor.h
        src/sensors/ObstacleSensor.cpp
        src/modes/freerun/FreeRunMode.cpp
        src/modes/freerun/FreeRunMode.h
        src/state/standard/ConditionalState.cpp
        src/state/standard/ConditionalState.h
        src/state/State.cpp
        src/memory/MemoryMonitor.h src/types.h
        src/missions/MissionManager.h
        src/missions/InMemoryMissionManager.h
        src/missions/InMemoryMissionManager.cpp
        src/constants.h
        src/modes/missionReplay/ReplayMissionMode.cpp
        src/modes/missionReplay/ReplayMissionMode.h)

target_include_directories(${PROJECT_NAME} PUBLIC src)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_commons)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_communication)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_controller)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_cycle)
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC MarkOS_time)

add_subdirectory(test)

install(DIRECTORY "src/"
        DESTINATION "/Users/oleksandrabaukh/workspace/MarkOS/MarkI")
