CMAKE_MINIMUM_REQUIRED(VERSION 3.11)

project(bomberman)

include(CMake/Findraylib.cmake)

include_directories(sources/include)

file(GLOB SOURCES "sources/src/*.cpp")

add_executable(bomberman ${SOURCES})

target_link_libraries(bomberman raylib)

if(UNIX)
  ##set(CMAKE_SKIP_BUILD_RPATH_FALSE)
  ##set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
  ##set(CMAKE_INSTALL_RPATH "$ENV{HOME}/indie_studio")
  ##set(CMAKE_INSTALL_RPATH_USE_LINK_PATH FALSE)
  ##set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/")
  install(TARGETS bomberman DESTINATION "$ENV{HOME}/indie_studio")
elseif(WIN32)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/")
endif()
