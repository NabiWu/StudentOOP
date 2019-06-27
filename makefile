CXXFLAGS=-g -std=c++14 -Wall -pedantic
CC=$(CXX)

STUDENT_DIR=my_code
TEST_DIR=tests



test_stl: $(TEST_DIR)/test_stl

$(TEST_DIR)/test_stl: $(TEST_DIR)/test_stl.cpp


tests: test_stl
	tests/test_stl


prod: tests
	- git commit -a -m "new assignment done"
	git push origin master