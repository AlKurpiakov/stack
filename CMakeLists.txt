cmake_minimum_required(VERSION 3.14)

project(Stack
        LANGUAGES CXX)


add_executable(stack Stack.cpp main.cpp Formula.cpp ExpressionChecker.cpp)