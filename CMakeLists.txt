cmake_minimum_required(VERSION 3.15.3)
project(stm32f103c8t6-template)
enable_language(C ASM)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(SOURCE
	src/startup.c
	src/vectors.c
	src/main.c
)

set(EXECUTABLE out.elf)
add_executable(${EXECUTABLE} ${SOURCE})

#target_compile_definitions(${EXECUTABLE} PRIVATE)

target_include_directories(${EXECUTABLE} PRIVATE
	include
)

target_compile_options(${EXECUTABLE} PRIVATE
	-mcpu=cortex-m3
	-mthumb
	--specs=nano.specs

	-fdata-sections
	-ffunction-sections

	-Wall
	-Werror
	-Wfatal-errors

	$<$<CONFIG:Debug>:-O0 -g>
)

target_link_options(${EXECUTABLE} PRIVATE
	-T${CMAKE_SOURCE_DIR}/linker.ld
	-mcpu=cortex-m3
	-mthumb
	--specs=nano.specs
	-lc -lm -lnosys
	-Wl,--gc-sections
)
