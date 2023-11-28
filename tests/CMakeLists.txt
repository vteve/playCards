add_compile_options(-fprofile-arcs -ftest-coverage)
link_libraries(gcov)

add_executable(testPlayCards testPlayCards.cpp catch.hpp)
add_executable(testPlayDeckDynamic testPlayDeckDynamic.cpp catch.hpp)
add_executable(testPlayDeckStatic testPlayDeckStatic.cpp catch.hpp)

target_link_libraries(testPlayDeckDynamic playCards)
target_link_libraries(testPlayDeckStatic playCards)

