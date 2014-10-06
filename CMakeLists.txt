project(chess)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(chess_SRCS chess.cpp main.cpp)
qt4_automoc(${chess_SRCS})
add_executable(chess ${chess_SRCS})
target_link_libraries(chess ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
install(TARGETS chess RUNTIME DESTINATION bin)
