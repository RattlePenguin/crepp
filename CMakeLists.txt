cmake_minimum_required(VERSION 3.22)

project(Crepp)

add_executable(Program)

target_sources(Program
	PRIVATE
		main.cpp
		src/CreppClass.cpp
		src/print.cpp
)
