cmake_minimum_required(VERSION 3.17)
project(FundementalADT)

set(CMAKE_CXX_STANDARD 14)

add_executable(FundementalADT main.cpp Bubblesort/BubbleSort.h Bubblesort/BubbleSort2.h MyVector/Vector.h MyVector/Vector_copyFrom.h MyVector/Vector_expand.h MyVector/Vector_Shrink.h MyVector/Vector_Bracket.h MyVector/Vector_Unsort.h MyVector/Vector_Comparator.h MyVector/Vector_find.h MyVector/Vector_Insert.h MyVector/Vector_Remove.h MyVector/Vector_Deduplicate.h MyVector/Vector_Traverse.h)