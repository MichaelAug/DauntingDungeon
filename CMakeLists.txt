project(DauntingDungeonGame)

cmake_minimum_required(VERSION 3.9)

if (${CMAKE_VERSION} VERSION_LESS 3.12)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

message(STATUS "Current source dir is ${CMAKE_CURRENT_SOURCE_DIR}")
#list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

set(DD_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/DauntingDungeon/*.cpp")
set(DD_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/DauntingDungeon/*.h")
file(GLOB SOURCES ${DD_SOURCES} ${DD_HEADERS})

add_executable(${PROJECT_NAME} ${SOURCES})

target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wextra)
target_link_libraries(
	${PROJECT_NAME}
		PUBLIC
			SDL2
			SDL2_image
			SDL2_ttf
			SDL2_mixer
)

set_target_properties(
	${PROJECT_NAME}
		PROPERTIES
			CXX_STANDARD 17
			CXX_STANDARD_REQUIRED YES
			CXX_EXTENSIONS NO
			INTERPROCEDURAL_OPTIMIZATION true
)