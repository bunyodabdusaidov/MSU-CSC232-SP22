[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=6953740&assignment_repo_type=AssignmentRepo)
# LAB02 - Array Processing

We continue our exploration of arrays in C++ by writing code used to process the elements of an array. We explore the processing of both one-dimensional and two-dimensional arrays.

## Background

Before proceeding with this lab, the student should take the time to read and/or review

* [Appendix A.6: Arrays](https://online.vitalsource.com/reader/books/9780134477473/epubcfi/6/446%5B%3Bvnd.vst.idref%3DP7001011925000000000000000006803%5D!/4/2%5BP7001011925000000000000000006803%5D/10%5BP70010119250000000000000000068CC%5D/2/2%5BP700101192500000000000000000E285%5D/3:5%5Brra%2Cys%5D)
* [LAB01 - Arrays and Addresses](https://msu-csc232-sp22.github.io/lab01/)

## Objective

Upon successful completion of this lab, the student has learned how to

* create an alias for a type with the `using` keyword
* pass one-dimensional arrays to functions for processing
* pass two-dimensional arrays to functions for processing

## Getting Started

After accepting this assignment with the provided [GitHub Classroom Assignment link](https://classroom.github.com/a/ZxBPduUc), clone this repository. If you have cloned the repository from the command line prompt, navigate into the newly created directory

```bash
cd labn-github-username
```

Next, create a branch named `develop`. Please note: The name of this branch **must** be as specified and will be, to the grading scripts, case-sensitive.

```bash
git checkout -b develop
```

Make sure you are on the `develop` branch before you get started. Make all your commits on the `develop` branch.

```bash
git branch
```

_You may have to type the `q` character to get back to the command line prompt after viewing the branches._

## Tasks

There are three tasks in this lab:

1. Find the largest element of one or more elements in a one-dimensional array.
2. Find the sum of one or more elements in a one-dimensional array.
3. Print the elements of a two-dimensional array in a tabular fashion.

For this lab, all your coding will take place in the [csc232.h](include/csc232.h) header file.

### Task 1 - Finding the largest element of a one-dimensional array

In our last lab, we found a convenient way of creating an alias for some type using the `typedef` statement. For example, we declared a new type named `IntegerArray` to be an alias for a one-dimensional array of 16 integers as follows:

```c++
static const int SIZE{16};
typedef int IntegerArray[SIZE];
```

There is another way to do this in C++ with the `using` keyword:

```c++
static const int SIZE{16};
using IntegerArray = int[NUM_ELEMENTS];
```

Notice the slightly different syntax. See the accepted answer in this [Stack Overflow link](https://stackoverflow.com/questions/10747810/what-is-the-difference-between-typedef-and-using-in-c11) for a nice discussion on the difference between the two techniques.

**Before you start this task**, toggle the `WORKING_ON_TASK1` macro declared in [csc232.h](include/csc232.h) from `FALSE` to `TRUE`.

**Step 1**: Declare a static constant integer named `NUM_ELEMENTS` initialized to 16; look for the `// TODO: Task 1.1`.

**Step 2**: Declare a new type named `IntArray` to be an array of integers to hold NUM_ELEMENTS; look for the `// TODO: Task 1.2`. Be sure to do this with the `using` keyword as discussed above.

**Step 3**: Replace the stub implementation of the `find_max` function with a correct implementation. Use the Doxygen comments as a guide for how the parameters should be used in your implementation. Recall that array indexes begin with the value of 0. Also, keep in mind as to why these parameters are needed: arrays are a primitive type in C++ and can't "tell" us anything about themselves (i.e., their size, for example). As such, we pass this information to the functions that process arrays.

The parameters shown here are typical of array processing functions. Consider the parameters `lower_index` and `num_to_search`. These parameters define a half-open interval of array indexes. Consider the following array:

```text
       +----+----+----+----+----+----+
data = | 10 | 20 | 30 | 40 | 50 | 60 |
       +----+----+----+----+----+----+
```

With `lower_index` = 2 and `num_to_search` = 3, we are to process the values 30, 40 and 50 (i.e., `data[2]`, `data[3]` and `data[4]`). Look for the `// TODO: Task 1.3`.

Some things to keep in mind if you want all the tests to pass:

- If `lower_index` is less than 0, you should change it to 0 before processing the array
- If `num_to_search` takes you beyond the last valid index, only process elements in a valid range, i.e., don't try to access/process array elements that are out of the range of valid indexes.
- If `size` exceeds `NUM_ELEMENTS`, you should change it to `NUM_ELEMENTS`, i.e., don't let clients supply bad data!

If you want to test your solution, toggle the `TASK1_COMPLETED` macro declared in [csc232.h](include/csc232.h) from `FALSE` to `TRUE` and then build and execute the `lab02-tests` target.

Once you have completed this task, save your work and stage your changes (the only file that should be staged is [csc232.h](include/csc232.h)). Commit your changes using a log message that is some facsimile of "Completed Task 1." and push them to GitHub.

### Task 2 - Finding the sum of the elements in a one-dimensional array

**Before you start this task**, toggle the `WORKING_ON_TASK2` macro declared in [csc232.h](include/csc232.h) from `FALSE` to `TRUE`.

Replace the stub implementation of the `find_sum` function with a correct solution. Use the Doxygen comments as a guide for how the parameters should be used in your implementation.

If you want to test your solution, toggle the `TASK2_COMPLETED` macro declared in [csc232.h](include/csc232.h) from `FALSE` to `TRUE` and then build and execute the `lab02-tests` target.

Once you have completed this task, save your work and stage your changes (again, the only file that should be staged is [csc232.h](include/csc232.h)). Commit your changes using a log message that is some facsimile of "Completed Task 2." and push them to GitHub.

### Task 3 - Printing the elements of a two-dimensional array in tabular fashion

**Before you start this task**, toggle the `WORKING_ON_TASK3` macro declared in [csc232.h](include/csc232.h) from `FALSE` to `TRUE`.

**Step 1**: Declare a static constant integer named `ORDER` initialized to 15; look for the `// TODO: Task 1.1`.

**Step 2**: Declare a new type named `TwoDimArray` to be a two-dimensinoal array of integers to hold `ORDER` rows and `ORDER` columns; look for the `// TODO: Task 3.2`. Be sure to do this with the `using` keyword as discussed above.

**Step 3**: Replace the stub implementation of the `print_table` function with a correct solution. Use the Doxygen comments as a guide for how the parameters should be used in your implementation. Note: To process an entire two-dimensional array with `NUM_ROWS` rows and `NUM_COLUMNS` columns, you'll need a nested-loop like:

```c+++
for (int row{0}; row < NUM_ROWS; ++row)
{
    for (int column{0}; column < NUM_COLUMNS; ++column)
    {
        // process array[row][column] as needed...
    }
}
```

NOTE: to set the width of a field, use the `iomanip` manipulator `setw`. Here is [an example](https://www.cplusplus.com/reference/iomanip/setw/).

If you want to test your solution, toggle the `TASK3_COMPLETED` macro declared in [csc232.h](include/csc232.h) from `FALSE` to `TRUE` and then build and execute the `lab02-tests` target.

Once you have completed this task, save your work and stage your changes (again, the only file that should be staged is [csc232.h](include/csc232.h)). Commit your changes using a log message that is some facsimile of "Completed Task 3." and push them to GitHub.

## Submission Details

Before submitting your assignment, be sure you have pushed all your changes to GitHub. If this is the first time you're pushing your changes (which if you've followed the directions, it _shouldn't_ be), the push command will look like:

```bash
git push -u origin develop
```

If you've already set up remote tracking (using the `-u origin develop` switch), then all you need to do is type

```bash
git push
```

As usual, prior to submitting your assignment on Blackboard, be sure that you have committed and pushed your final changes to GitHub. Once your final changes have been pushed, create a pull request that seeks to merge the changes in your `develop` branch into your `trunk` branch. Once your pull request has been created, submit the URL of your assignment _repository_ (i.e., _not_ the URL of the pull request) Blackboard using a Text Submission. Please note: the timestamp of the submission on Blackboard is used to assess any late penalties if and when warranted, _not_ the date/time you create your pull request. **No exceptions will be granted for this oversight**.

### Due Date

Your assignment submission is due by 11:59 PM, Friday, 11-February.

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
