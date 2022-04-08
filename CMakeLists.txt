cmake_minimum_required(VERSION 3.21)
project(AVLTree)

set(CMAKE_CXX_STANDARD 23)

add_executable(AVLTree avltree/main.cpp avltree/Holder.cpp avltree/Holder.hpp avltree/Node.cpp avltree/Node.hpp avltree/AVLManager.cpp avltree/AVLManager.hpp avltree/Display.cpp avltree/Display.hpp Binary-Tree-RecursiveFun.cpp)
