cmake_minimum_required(VERSION 3.22)
project(FRC2026 CXX)

if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(frc REQUIRED)
find_package(wpi REQUIRED)
find_package(wpilibNewCommands REQUIRED)
find_package(pathplannerlib-cpp REQUIRED)
find_package(photonlib-cpp REQUIRED)
find_package(URCL REQUIRED)
find_package(REVLib REQUIRED)
find_package(CTRE_Phoenix6_WPI REQUIRED)

file(GLOB_RECURSE FRC_CPP_SRCS src/*.cpp)

add_executable(frcUserProgram ${FRC_CPP_SRCS})
target_link_libraries(frcUserProgram
    frc::frc
    wpi::wpi
    wpilibNewCommands::wpilibNewCommands
    pathplannerlib-cpp::pathplannerlib-cpp
    photonlib-cpp::photonlib-cpp
    URCL::URCL
    REVLib::REVLib
    CTRE_Phoenix6_WPI::CTRE_Phoenix6_WPI
)
