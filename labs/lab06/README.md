[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7273359&assignment_repo_type=AssignmentRepo)
# LAB06 - Writing Bag Client Functions

In this lab we write code that works with the ADT Bag. Specifically, the student shall implement the client functions called for in Exercises 3.1, 3.2, and 3.7 found in our textbook and echoed here for your convnience.

## Background

Before proceeding with this lab, the student should take the time to read and/or review

* [Chapter 3: Array-based implementations](https://online.vitalsource.com/reader/books/9780134477473/epubcfi/6/84%5B%3Bvnd.vst.idref%3DP7001011925000000000000000001209%5D!/4/2%5BP7001011925000000000000000001209%5D/4%5BP700101192500000000000000000120C%5D/2%5BP7001011925000000000000000009AA2%5D/4%5BP7001011925000000000000000009AA4%5D/2%5BP7001011925000000000000000009AA5%5D/4%5BP7001011925000000000000000009AAD%5D/4%5BP7001011925000000000000000009AAF%5D/8%5BP7001011925000000000000000009AB6%5D/2%5BP7001011925000000000000000009AB7%5D)

## Objective

Upon successful completion of this lab, the student has learned how to

* Write client functions that use the ADT ArrayBag

## Getting Started

After accepting this assignment with the provided [GitHub Classroom Assignment link](https://classroom.github.com/a/OXRQTQjn), clone this repository. If you have cloned the repository from the command line prompt, navigate into the newly created directory

```bash
cd lab06-github-username
```

Next, create a branch named `develop`. Please note: The name of this branch **must** be as specified and will be, to the grading scripts, case-sensitive.

```bash
git checkout -b develop
```

Make sure you are on the `develop` branch before you get started. Make all your commits on the `develop` branch.

```bash
git status
```

_You may have to type the `q` character to get back to the command line prompt after viewing the status._

## Tasks

There are three tasks in this lab that correspond to the solutions for the three exercises found at the end of Chapter 3. All tasks will involve writing functions in the [include/csc232.h](include/csc232.h) header file.

### Task 1: Exercise 3.1

Consider a bag of integers. Write a client function that computes the sum of integers in the bag `aBag`.

1. Toggle the macro definition of `TEST_TASK1` from `FALSE` to `TRUE`.
2. Locate the `TODO` identifying the location where you are to write the client function for this task.
3. Implement your function.
4. Use the `google-tests` target to test your solution.
5. When you have completed this task to your satisfaction, stage, commit and push your changes to GitHub.

**Development Notes**

- the name of this function shall be `sum_contents_of`
- the function shall have one parameter, passed by const ref, of type `ArrayBag<T>`, where `T` is a function template parameter
- the function shall return a value of type `int`
- if the given `ArrayBag` parameter is empty, the function shall return a value of 0

### Task 2: Exercise 3.2

Write a client function that replaces a given item with another given item. The function should return a boolean value to indicate whether the replacement was successful.

1. Toggle the macro definition of `TEST_TASK2` from `FALSE` to `TRUE`.
2. Locate the `TODO` identifying the location where you are to write the client function for this task.
3. Implement your function.
4. Use the `google-tests` target to test your solution.
5. When you have completed this task to your satisfaction, stage, commit and push your changes to GitHub.

**Development Notes**

- the name of this function shall be `replace_item`
- the function shall have three parameters,
  - the first shall be passed by ref, of type `ArrayBag<T>`, where `T` is a function template parameter
  - the second shall be passed by const ref of type `T` that is the target to be replaced
  - the third shall be passed by const ref of type `T` that is the replacement for the given target
- the function shall return a value of type `bool` which will be `true` if the replacement was successful; `false` otherwise

### Task 3: Exercise 3.7

Write a client function that merges two bags into a new third bag. Do not destroy the original two bags.

1. Toggle the macro definition of `TEST_TASK3` from `FALSE` to `TRUE`.
2. Locate the `TODO` identifying the location where you are to write the client function for this task.
3. Implement your function.
4. Use the `google-tests` target to test your solution.
5. When you have completed this task to your satisfaction, stage, commit and push your changes to GitHub.

**Development Notes**

- the name of this function shall be `merge`
- the function shall have two parameters, both passed by const ref, of type `ArrayBag<T>`
- the function shall return a third bag, also of type `ArrayBag<T>` whose contents is the result of merging the contents of the two given bags.
- if the two given bags contain the same item, the merged bag shall contain both (duplicate) items. That is, think of the merge as the [union](https://en.wikipedia.org/wiki/Union_(set_theory)) of the two given bags.
- a precondition of this method is that the number of items in both bags does not exceed the maximum capacity of the ArrayBag ADT.

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

Your assignment submission is due by 11:59 PM, Saturday, 12 March 2022.

### Grading Rubric

This assignment is worth **3 points**.

| Criteria           | Exceeds Expectations         | Meets Expectations                  | Below Expectations                  | Failure                                        |
|--------------------|------------------------------|-------------------------------------|-------------------------------------|------------------------------------------------|
| Pull Request (20%) | Submitted early, correct url | Submitted on-time; correct url      | Incorrect URL                       | No pull request was created or submitted       |
| Code Style (20%)   | Exemplary code style         | Consistent, modern coding style     | Inconsistent coding style           | No style whatsoever or no code changes present |
| Correctness^ (60%) | All unit tests pass          | At least 80% of the unit tests pass | At least 60% of the unit tests pass | Less than 50% of the unit tests pass           |

^ _The Google Test unit runner will calculate the correctness points based purely on the fraction of tests passed_.

### Late Penalty

* In the first 24-hour period following the due date, this lab will be penalized 0.6 point meaning the grading starts at 2.4 (out of 3 total possible) points.
* In the second 24-hour period following the due date, this lab will be penalized 1.2 points meaning the grading starts at 1.8 (out of 3 total possible) points.
* After 48 hours, the assignment will not be graded and thus earns no points, i.e., 0 out of 3 possible points.

