if (STUDY)
    add_subdirectory(study)
else ()
    add_library(ch1_s1 STATIC
        ex_9.cc
        ex_11.cc ex_13.cc ex_14.cc
    )
endif()

foreach(ex
    9
    11 13 14)
    set(test "ut_ex_${ex}")
    add_executable(${test} ex_${ex}_test.cc)
    target_link_libraries(${test} gtest ch1_s1)
    add_test(ut_ex_1_1_${ex} ${test})
endforeach(ex)
