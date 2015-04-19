if (STUDY)
    add_subdirectory(study)
else ()
    add_library(ch1_s1 STATIC
        ex_9.cc
        ex_11.cc ex_13.cc ex_14.cc ex_15.cc
        ex_20.cc ex_21.cc ex_22.cc ex_23.cc ex_24.cc ex_27.cc ex_28.cc ex_29.cc
    )
endif()

foreach(ex
    9
    11 13 14 15
    20 21 22 23 24 27 28 29)
    set(test "ut_ex_${ex}")
    add_executable(${test} ex_${ex}_test.cc)
    target_link_libraries(${test} gtest ch1_s1)
    add_test(ut_ex_1_1_${ex} ${test})
endforeach(ex)

foreach(ex
    21 22 23 24 27 28)
    set(bin "ex_${ex}")
    add_executable(${bin} ${bin}_main.cc)
    target_link_libraries(${bin} gtest ch1_s1)
endforeach(ex)
