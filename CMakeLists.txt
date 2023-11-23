cmake_minimum_required (VERSION 3.12)
project (workshop)

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp" "src/*.hpp" "src/*.inl")

add_executable(puzzle ${SOURCE_FILES})
set_target_properties(puzzle PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED YES
)