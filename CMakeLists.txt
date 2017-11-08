cmake_minimum_required(VERSION 2.8)

project(LearnOpengl)


	
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(SOURCE_DIR src)

set(MERGELIST_SOURCE_LIST 
	${SOURCE_DIR}/mergeSortedList/merge.cpp)
	
set(LEASTKNUMS_SOURCE_LIST 
	${SOURCE_DIR}/leastKNumbers/findLeastKNums.cpp)
	
set(FIRSTREPEATCHAR_SOURCE_LIST 
	${SOURCE_DIR}/firstNotRepeatChar/solution.cpp)
	
add_executable(MergeList ${MERGELIST_SOURCE_LIST})

add_executable(LeastKNums ${LEASTKNUMS_SOURCE_LIST})

add_executable(FirstRepeatChar ${FIRSTREPEATCHAR_SOURCE_LIST})

