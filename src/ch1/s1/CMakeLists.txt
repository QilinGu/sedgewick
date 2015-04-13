if (STUDY)
    add_subdirectory(study)
else ()
    add_library(ch1_s1 STATIC
        ex_9.cc
    )
endif()

foreach(ex 9)
    set(test "ut_ex_${ex}")
    add_executable(${test} ex_9_test.cc)
    target_link_libraries(${test} gtest ch1_s1)
    add_test(ut_ex_1_1_${ex} ${test})
endforeach(ex)
