[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7116656&assignment_repo_type=AssignmentRepo)
# LAB04 - Introduction to Dynamic Programming

In today's lab we explore two dynamic programming solutions to finding the nth Fibonacci number in _O(n)_.

## Background

As we will see in lecture, **dynamic programming** offers us a solution to finding the nth Fibonacci number in O(n). We will also find that there are two approaches to dynamic programming: (1) bottom-up and (2) top-down. In this lab we'll explore both approaches to finding the nth Fibonacci number.

### Top-Down Approach

The top-down approach is a technique of saving values that have already been calculated, a technique that is referred to as _memoization_. With this technique we first break the problem up into sub-problems and then calculate and store values. To facilitate this approach we can use a map structure. A map is also known as an "**associative array**" in which "keys" are associated with "values." The arrays you have worked with thus far could be thought of as an associative map wherein the "key" is an integer (i.e., the index into the array), and of course, the "value" is the contents of the array at that index (key). Fortunately for us, the standard template library includes such a structure. The program `demo.cpp` in this repo demonstrates the use of a map, and is shown below:

```c++
#include "csc232.h"

int main()
{
    std::map<std::string, char> grade_list;
    // Assign "John" a grade of 'C'
    grade_list["John"] = 'C';
    std::cout << "John's grade = " << grade_list["John"] << std::endl;

    // Raise his grade
    grade_list["John"] = 'B';
    std::cout << "After raising his grade, " << std::endl;

    // Find an entry in the map. The member function find(key) returns an
    // iterator; end() is an iterator that points to the "end" of the map.
    // If we haven't "reached" the end of the map, the key is in the map.
    if (grade_list.find("John") != grade_list.end()) {
        std::cout << "John's grade = " << grade_list["John"] << std::endl;
    }

    // On the other hand, if we have reached the "end" of the map using find(key)
    // then the key isn't in the map.
    if (grade_list.find("Jim") == grade_list.end()) {
        std::cout << "Jim wasn't found in the map" << std::endl;
    } else {
        std::cout << "Jim's grade = " << grade_list["Jim"] << std::endl;
    }

    // Let's associate another key/value pair in the map:
    grade_list["Sue"] = 'A';

    // Iterators "point" to elements in the map. Each element in the map has
    // a key/value pair named "first" (the key) and "second" (the value). Two
    // common iterators are begin() and end(). NOTE: end() doesn't point to
    // anything
    // "John" <- 'A'           <- grade_list.begin() points here
    // "Sue"  <- 'A'
    //                         <- grade_list.end() points here, i.e. just after
    //                            the last item in the map. Trying to access items
    //                            pointed to by end() will result in a Segmentation
    //                            fault and will dump the core.
    std::cout << "grade_list.begin()->first = " << grade_list.begin()->first
              << std::endl;
    std::cout << "grade_list.begin()->second = " << grade_list.begin()->second
              << std::endl;

    // We can use these pointers to iterator through the map
    std::cout << "Mappings in grade_list:" << std::endl;
    for (std::map<std::string, char>::iterator it = grade_list.begin(); it != grade_list.end(); ++it) {
        std::cout << std::setw(4) << it->first << " <-- " << it->second << std::endl;
    }

    // A map that maps integers to integers
    std::map<int, int> m;
    m[0] = 1;
    m[1] = 1;
    for (std::map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
        std::cout << it->first << " <-- " << it->second << std::endl;
    }

    return EXIT_SUCCESS;
}
```

You should build and execute the `lab04-demo` target and examine the output to ensure you understand the use of this data structure. When run, the output should match the following:

```text
John's grade = C
After raising his grade, 
John's grade = B
Jim wasn't found in the map
grade_list.begin()->first = John
grade_list.begin()->second = B
Mappings in grade_list:
John <-- B
 Sue <-- A
0 <-- 1
1 <-- 1
```

For more details and a quick tutorial on using the map found in the STL, see [STL Maps -- Associative Arrays](https://www.cprogramming.com/tutorial/stl/stlmap.html).

With your understanding of the map object from the Background section, let us turn to the top-down approach to finding the nth Fibonacci number using a map.

Suppose we have a simple map object, `m`, which maps each Fibonacci number calculated that has already been calculated to its result, and we modify our function to use it and update it. The resulting function requires only _O(n)_ time instead of exponential time (but requires _O(n)_ space):

```text
// This, of course, is just pseudo-code
function fib(n)
    map<int, int> m
    m[0] = 1
    m[1] = 1
    return fib(n, m)

function fib(n, m)
   if key n is not in map m
      m[n] = fib(n - 1, m) + fib(n - 2, m)
   return m[n]
```

### Bottom-up Approach

In the bottom-up approach, we calculate the smaller values of the Fibonacci sequence first, then build larger values from them. This method also uses _O(n)_ time since it contains a loop that repeats _n_ − 1 times, but it only takes constant (_O(1)_) space, in contrast to the top-down approach which requires _O(n)_ space to store the map.

```text
// again, using pseudo-code
function fib(n)
    if n = 0
        return 1
    else
        var previousFib = 0, currentFib = 1
        repeat n − 1 times // loop is skipped if n = 1
            var newFib = previousFib + currentFib
            previousFib = currentFib
            currentFib  = newFib
    return currentFib
```

Before proceeding with this lab, the student should take the time to read

* [Chapter 2 - Recursion: The Mirrors](https://online.vitalsource.com/reader/books/9780134477473/epubcfi/6/62%5B%3Bvnd.vst.idref%3DP7001011925000000000000000000BEE%5D!/4/2%5BP7001011925000000000000000000BEE%5D/2/2%5BP70010119250000000000000000095A9%5D/7:13%5B:%20T%2Che%20%5D)
* [Fibonacci Number](https://en.wikipedia.org/wiki/Fibonacci_number)
* [A naive, recursive solution](https://online.vitalsource.com/reader/books/9780134477473/epubcfi/6/74%5B%3Bvnd.vst.idref%3DP7001011925000000000000000000FF4%5D!/4/2%5BP7001011925000000000000000000FF4%5D/6%5BP7001011925000000000000000000FF7%5D/2/2%5BP7001011925000000000000000009906%5D/5:30%5Blti%2Cply%5D) to finding the nth Fibonacci number
* [Dynamic Programming algorithms](https://en.wikipedia.org/wiki/Dynamic_programming#Fibonacci_sequence) for finding the nth Fibonacci number

## Objective

Upon successful completion of this lab, the student has learned how to

* implement a bottom-up, dynamic programming, solution to finding the nth Fibonacci number
* implement a top-down, dynamic programming, solution to finding the nth Fibonacci number
* declare, process and manipulate an associative array (i.e., the `std::map`)

## Getting Started

After accepting this assignment with the provided [GitHub Classroom Assignment link](https://classroom.github.com/a/uYMV-8YZ), clone this repository. If you have cloned the repository from the command line prompt, navigate into the newly created directory

```bash
cd lab04-github-username
```

Next, create a branch named `develop`. Please note: The name of this branch **must** be as specified and will be, to the grading scripts, case-sensitive.

```bash
git checkout -b develop
```

Make sure you are on the `develop` branch before you get started. Make all your commits on the `develop` branch.

```bash
git branch
```

_You may have to type the `q` character to get back to the command line prompt after viewing the branch(es)._

## Tasks

This lab consists of three tasks:

1. Create a set of interfaces used to find the nth Fibonacci number.
2. Implement another one of these interfaces using a bottom-up, dynamic programming approach.
3. Implement one of these interfaces using a top-down, dynamic programming approach.

### Task 1: Creating the interfaces

1. Create `fib.h` in the `include` folder with the following contents. This is an _abstract_ class as it contains a **pure virtual** function declaration. As such, you cannot create objects of this type. Instead, we **extend** this class into a concrete class that can be used to create objects. Fill in as many of the doxygen comments as needed with the appropriate text.

    ```c++
    /**
    * @file fib.h
    * @author your name (you@domain.com)
    * @brief 
    * @version 0.1
    * @date 2022-02-21
    * 
    * @copyright Copyright (c) 2022
    * 
    */

    #ifndef LAB04_FIB_CALCULATOR_H__
    #define LAB04_FIB_CALCULATOR_H__

    /**
    * @brief A calculator that computes values using Dynamic Programming.
    */
    class DynamicCalculator
    {
    public:
        /**
        * @brief Calculates the nth Fibonacci number.
        * 
        * Note: It is assumed that the "first" Fibonacci number is associated with n = 0, i.e.,
        *
        * fib(n) = 1 if n == 0 or n == 1
        *        = fib(n - 1) + fib(n - 2) for n > 1
        *
        * In other words,
        *
        * n:      0   1   2   3   4   5 ...
        * fib(n): 1   1   2   3   5   8 ...
        * 
        * @param n an index into the Fibonacci sequence, beginning with 0
        * @return the nth Fibonacci number, where the first number in the sequence is index 0.
        * @pre n >= 0
        */
        virtual int fib(int n) const = 0;
    };
    #endif // LAB04_FIB_CALCULATOR_H__
    ```

2. Now create `topfib.h` (also in the `include` folder) which **extends** the abstract `DynamicCalculator` class. This class will implement the top-down solution discussed above. You'll provide the implementation details in Task 2.

    ```c++
    /**
    * @file topfib.h
    * @author your name (you@domain.com)
    * @brief 
    * @version 0.1
    * @date 2022-02-21
    * 
    * @copyright Copyright (c) 2022
    * 
    */

    #ifndef LAB04_TOP_DOWN_CALCULATOR_H__
    #define LAB04_TOP_DOWN_CALCULATOR_H__

    #include <map>
    #include "fib.h"

    /**
    * An implementation of the <code>DynamicCalculator</code> that uses a top-down,
    * dynamic programming approaches where appropriate.
    */
    class TopDownDynamicCalculator : public DynamicCalculator
    {
    public:
        /**
        * Calculates the nth Fibonacci number using a top-down, dynamic programming approach.
        *
        * @pre n >= 0
        * @param n an index into the Fibonacci sequence beginning at 0.
        * @return The nth number in the Fibonacci sequence is returned.
        */
        int fib(int n) const override;
    private:
        int fib(int n, std::map<int, int>& map) const;
    };
    #endif // LAB04_TOP_DOWN_CALCULATOR_H__
    ```

3. Now create `bottomfib.h` (also in the `include` folder) which **extends** the abstract `DynamicCalculator` class. This class will implement the top-down solution discussed above. You'll provide the implementation details in Task 3.

    ```c++
    /**
    * @file bottomfib.h
    * @author your name (you@domain.com)
    * @brief 
    * @version 0.1
    * @date 2022-02-21
    * 
    * @copyright Copyright (c) 2022
    * 
    */

    #ifndef LAB04_BOTTOM_UP_CALCULATOR_H__
    #define LAB04_BOTTOM_UP_CALCULATOR_H__

    #include "fib.h"

    /**
    * @brief An implementation of the <code>DynamicCalculator</code> that uses a bottom-up 
    * dynamic programming approaches where appropriate.
    */
    class BottomUpDynamicCalculator : public DynamicCalculator
    {
    public:
        /**
        * Calculates the nth Fibonacci number using a bottom-up, dynamic programming approach.
        *
        * @pre n >= 0
        * @param n an index into the Fibonacci sequence beginning at 0.
        * @return The nth number in the Fibonacci sequence is returned.
        */
        int fib(int n) const override;
    };
    #endif // LAB04_BOTTOM_UP_CALCULATOR_H__
    ```

4. Update the `lab04-tests` target in `CMakeLists.txt` by adding references to these three header files:

    ```cmake
    set(SRC_TEST_FILES test/test.cpp
                       include/fib.h
                       include/topfib.h
                       include/bottomfib.h)
    ```

5. Update progress macro defintions (toggle `TEST_TASK1` to `TRUE`)
6. Build the `lab04-tests` target. Here you just want to verify that the target still builds without issue.
7. Once your target builds, stage, commit and push your changes to GitHub.

### Task 2: Top-down Solution

In this second task, you'll implement the top-down solution in an implementation file for the `TopDownDynamicCalculator` using the pseudo-code presented in the Background section as your guide.

1. Create `topfib.cpp` in the `src` folder and implement the methods.
2. Update the `lab04-tests` target in `CMakeLists.txt`

    ```cmake
    set(SRC_TEST_FILES test/test.cpp
                       include/fib.h
                       include/topfib.h
                       src/topfib.cpp
                       include/bottomfib.h)
    ```

3. Update progress macro definitions (toggle `TEST_TASK2` to `TRUE`)
4. Build and execute the `lab04-tests` target to validate the correctness of your solution.
5. Once your target builds, stage, commit, and push your changes to GitHub.

### Task 3: Bottom-up Solution

In this third task, you'll implement the bottom-up solution in an implementation file for the `BottomUpDynamicCalculator` using the pseudo-code presented in the Background section as your guide.

1. Create `bottomfib.cpp` in the `src` folder and implement the methods.
2. Update the `lab04-tests` target in `CMakeLists.txt`

    ```cmake
    set(SRC_TEST_FILES test/test.cpp
                       include/fib.h
                       include/topfib.h
                       src/topfib.cpp
                       include/bottomfib.h
                       src/bottomfib.cpp)
    ```

3. Update progress macro definitions (toggle `TEST_TASK3` to `TRUE`)
4. Build and execute the `lab04-tests` target to validate the correctness of your solution.
5. Once your target builds, stage, commit, and push your changes to GitHub.

## Submission Details

Before submitting your assignment, be sure you have pushed all your changes to GitHub. If this is the first time you're pushing your changes, the push command will look like:

```bash
git push -u origin develop
```

If you've already set up remote tracking (using the `-u origin develop` switch), then all you need to do is type

```bash
git push
```

As usual, prior to submitting your assignment on Blackboard, be sure that you have committed and pushed your final changes to GitHub. Once your final changes have been pushed, create a pull request that seeks to merge the changes in your `develop` branch into your `trunk` branch. Once your pull request has been created, submit the URL of your assignment _repository_ (i.e., _not_ the URL of the pull request) Blackboard using a Text Submission. Please note: the timestamp of the submission on Blackboard is used to assess any late penalties if and when warranted, _not_ the date/time you create your pull request. **No exceptions will be granted for this oversight**.

### Due Date

Your assignment submission is due by 11:59 PM, Saturday, February 26, 2022.

### Grading Rubric

This assignment is worth **3 points**.

Criteria          | Exceeds Expectations        | Meets Expectations             | Below Expectations | Failure                                                 |
------------------|-----------------------------|--------------------------------|--------------------|---------------------------------------------------------|
Pull Request (20%)| Submitted early, correct url| Submitted on-time; correct url | Incorrect URL            | No pull request was created or submitted          |
Code Style (20%)  | Exemplary code style        | Consistent, modern coding style    | Inconsistent coding style| No style whatsoever or no code changes present|
Correctness^ (60%)| All unit tests pass         | At least 80% of the unit tests pass| At least 60% of the unit tests pass| Less than 50% of the unit tests pass|

^ _The Google Test unit runner will calculate the correctness points based purely on the fraction of tests passed_.

### Late Penalty

* In the first 24 hour period following the due date, this lab will be penalized 0.6 point meaning the grading starts at 2.4 (out of 3 total possible) points.
* In the second 24 hour period following the due date, this lab will be penalized 1.2 points meaning the grading starts at 1.8 (out of 3 total possible) points.
* After 48 hours, the assignment will not be graded and thus earns no points, i.e., 0 out of 3 possible points.
