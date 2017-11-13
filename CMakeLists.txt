cmake_minimum_required(VERSION 2.8)

project(LearnAlgorithm)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(SOURCE_DIR src)

set(MERGELIST_SOURCE_LIST 
	${SOURCE_DIR}/mergeSortedList/merge.cpp)
	
set(LEASTKNUMS_SOURCE_LIST 
	${SOURCE_DIR}/leastKNumbers/findLeastKNums.cpp)
	
set(FIRSTREPEATCHAR_SOURCE_LIST 
	${SOURCE_DIR}/firstNotRepeatChar/solution.cpp)
	
set(MINVALUESTACK_SOURCE_LIST 
	${SOURCE_DIR}/minStack/minValueOfStack.cpp)

set(IMPDEQUE_SOURCE_LIST 
	${SOURCE_DIR}/useTwoStackImpDeque/main.cpp)	

set(FINDKTHTOTAIL_SOURCE_LIST 
	${SOURCE_DIR}/findKthToTail/main.cpp)

set(DELETCHAR_SOURCE_LIST 
	${SOURCE_DIR}/deletChar/main.cpp)

set(GETLONGESTSYSMMERICAL_SOURCE_LIST 
	${SOURCE_DIR}/getLongestSymmericalLen/main.cpp)	
	
	
add_executable(MergeList ${MERGELIST_SOURCE_LIST})

add_executable(LeastKNums ${LEASTKNUMS_SOURCE_LIST})

add_executable(FirstRepeatChar ${FIRSTREPEATCHAR_SOURCE_LIST})

add_executable(MinValueOfStack ${MINVALUESTACK_SOURCE_LIST})

add_executable(TwoStackImpQueue ${IMPDEQUE_SOURCE_LIST})

add_executable(FindKthToTail ${FINDKTHTOTAIL_SOURCE_LIST})

add_executable(DeletChar ${DELETCHAR_SOURCE_LIST})

add_executable(GetLongestSymmercial ${GETLONGESTSYSMMERICAL_SOURCE_LIST})
