add_test( EnglishToRussian.HardStrings /mnt/g/my_programs/DockerC/translit/build/tests/hello_test [==[--gtest_filter=EnglishToRussian.HardStrings]==] --gtest_also_run_disabled_tests)
set_tests_properties( EnglishToRussian.HardStrings PROPERTIES WORKING_DIRECTORY /mnt/g/my_programs/DockerC/translit/build/tests SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set( hello_test_TESTS EnglishToRussian.HardStrings)
