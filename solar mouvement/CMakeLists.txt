cmake_minimum_required(VERSION 3.21)
project(SOLARIS VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick QuickControls2 Test)

qt_add_executable(SOLARIS
    src/main.cpp
    src/core/SolarCalculator.cpp src/core/SolarCalculator.h
    src/core/SimulationClock.cpp src/core/SimulationClock.h
    src/core/Sun.cpp src/core/Sun.h
    src/core/SolarSystemController.cpp src/core/SolarSystemController.h
    src/services/SettingsManager.cpp src/services/SettingsManager.h)
qt_wrap_cpp(SOLARIS_MOC
    src/core/SimulationClock.h src/core/Sun.h src/core/SolarSystemController.h)
target_sources(SOLARIS PRIVATE ${SOLARIS_MOC})
qt_add_qml_module(SOLARIS URI Solaris VERSION 1.0 QML_FILES qml/Main.qml)
target_include_directories(SOLARIS PRIVATE src)
target_link_libraries(SOLARIS PRIVATE Qt6::Core Qt6::Gui Qt6::Quick Qt6::QuickControls2)

enable_testing()
add_subdirectory(tests)
