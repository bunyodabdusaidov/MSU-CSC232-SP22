# Command-line build and execution

Navigate to your `Labn` directory where you'll execute the following commands to build and execute the Google Tests. 

- `cmake -S . -B build`
- `cmake --build build`
- `cd build && ctest && cd ..`

## Sample Session

Your output should resemble:

```bash
cmake -S . -B build
-- The C compiler identification is GNU 9.3.0
-- The CXX compiler identification is GNU 9.3.0
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Detecting C compile features
-- Detecting C compile features - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found Python: /usr/bin/python3.8 (found version "3.8.10") found components: Interpreter
-- Looking for pthread.h
-- Looking for pthread.h - found
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD
-- Performing Test CMAKE_HAVE_LIBC_PTHREAD - Failed
-- Looking for pthread_create in pthreads
-- Looking for pthread_create in pthreads - not found
-- Looking for pthread_create in pthread
-- Looking for pthread_create in pthread - found
-- Found Threads: TRUE
-- Configuring done
-- Generating done
-- Build files have been written to: <path to your repo>/build
```

Next, build the labs targets:

```bash
cmake --build build
Scanning dependencies of target gtest
[  7%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
[ 14%] Linking CXX static library ../../../lib/libgtest.a
[ 14%] Built target gtest
Scanning dependencies of target gtest_main
[ 21%] Building CXX object _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
[ 28%] Linking CXX static library ../../../lib/libgtest_main.a
[ 28%] Built target gtest_main
Scanning dependencies of target lab01-tests
[ 35%] Building CXX object CMakeFiles/lab01-tests.dir/test/test.cpp.o
[ 42%] Linking CXX executable lab01-tests
[ 42%] Built target lab01-tests
Scanning dependencies of target lab01-demo
[ 50%] Building CXX object CMakeFiles/lab01-demo.dir/src/demo.cpp.o
[ 57%] Linking CXX executable lab01-demo
[ 57%] Built target lab01-demo
Scanning dependencies of target lab01
[ 64%] Building CXX object CMakeFiles/lab01.dir/src/main.cpp.o
[ 71%] Linking CXX executable lab01
[ 71%] Built target lab01
Scanning dependencies of target gmock
[ 78%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
[ 85%] Linking CXX static library ../../../lib/libgmock.a
[ 85%] Built target gmock
Scanning dependencies of target gmock_main
[ 92%] Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
[100%] Linking CXX static library ../../../lib/libgmock_main.a
[100%] Built target gmock_main
```

Now descend into your `build` directory and run `ctest` (and then come back from whence you came):

```bash
cd build && ctest && cd ..
Test project <path to your repo>/build
    Start 1: HelloTest.BasicAssertions
1/1 Test #1: HelloTest.BasicAssertions ........   Passed    0.49 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.51 sec
```
