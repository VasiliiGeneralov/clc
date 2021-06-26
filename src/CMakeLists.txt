add_subdirectory(tokenizer)
add_subdirectory(parser)
add_subdirectory(analyzer)

set(EXTRA_INCLUDES
	${PRJECT_SOURCE_DIR}/tokenizer
	${PRJECT_SOURCE_DIR}/parser
	${PRJECT_SOURCE_DIR}/analyzer
	)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE tokenizer parser analyzer)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_BINARY_DIR} ${EXTRA_INCLUDES})
