cmake_minimum_required(VERSION 2.8)

project(LearnOpengl)


	
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(SOURCE_DIR src)

set(MERGELIST_SOURCE_LIST 
	${SOURCE_DIR}/mergeSortedList/merge.cpp)
	
add_executable(MergeList ${MERGELIST_SOURCE_LIST})

