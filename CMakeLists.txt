cmake_minimum_required(VERSION 3.21.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# add_compile_options(-Wno-c++98-compat -Wno-c++98-compat-pedantic) not needed with GLM 1.0.1

project(Eon VERSION 0.1.0.4 LANGUAGES C CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(SOURCE_DIR   src)
set(INCLUDE_DIR  include)
set(LIBRARIES_DIR   external)

# include(CTest)
include(FetchContent)

#########
# GTest #
#########
enable_testing()
add_subdirectory(external/googletest-1.14.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include(GoogleTest)

##########
# OpenGL #
##########
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

########
# SDL2 #
########
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(SDL2_IMAGE REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

#######
# GLM #
#######
FetchContent_Declare(
	glm
	GIT_REPOSITORY	https://github.com/g-truc/glm.git
	GIT_TAG 	0af55ccecd98d4e5a8d1fad7de25ba429d60e863 #refs/tags/1.0.1.0 33b0eb9fa336ffd8551024b1d2690e418014553b refs/tags/1.0.0.0
)
FetchContent_MakeAvailable(glm)
set(GLM_LIBRARIES   glm::glm)

#########
# IMGUI #
#########
#[[
add_library(imgui STATIC
        # Main Imgui files
        external/imgui/imgui.cpp
        external/imgui/imgui.h
        external/imgui/imgui_draw.cpp
        external/imgui/imgui_tables.cpp
        external/imgui/imgui_widgets.cpp
        external/imgui/imgui_demo.cpp
        # SDL2+OpenGL-specific files
        external/imgui/imgui_impl_sdl2.cpp
        external/imgui/imgui_impl_sdl2.h
        external/imgui/imgui_impl_sdlrenderer2.cpp
        external/imgui/imgui_impl_sdlrenderer2.h
        external/imgui/imgui_impl_opengl3.cpp
        external/imgui/imgui_impl_opengl3_loader.h
        external/imgui/imgui_impl_opengl3.h)
add_library(imgui::imgui ALIAS imgui)
target_link_libraries(imgui
    PUBLIC
    OpenGL::GL
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)
target_include_directories(imgui PUBLIC external/imgui)]]

###########
# Project #
###########
file(GLOB SOURCES "${SOURCE_DIR}/*.cpp" "${SOURCE_DIR}/*/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARY})
target_link_libraries(${PROJECT_NAME} ${GLM_LIBRARIES})#PRIVATE glm::glm)
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})

########
# Test #
########
add_executable(
  hello_test
  tests/hello_test.cc
)
target_link_libraries(
  hello_test
  GTest::gtest_main
)
gtest_discover_tests(hello_test)
# add_test(hello_test hello_test)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
