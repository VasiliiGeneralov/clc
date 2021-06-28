add_executable(tests test.cpp)

target_link_libraries(tests PRIVATE tokenizer parser analyzer)

target_include_directories(tests PRIVATE 
  ${PROJECT_SOURCE_DIR}/src/tokenizer
  ${PROJECT_SOURCE_DIR}/src/parser
  ${PROJECT_SOURCE_DIR}/src/analyzer)
