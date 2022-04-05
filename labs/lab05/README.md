[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7222189&assignment_repo_type=AssignmentRepo)
# LAB05 - Compiling Class Templates

Today we examine three different ways to organize class templates and compile them.

## Background

Before proceeding with this lab, the student should take the time to read

* Appendix A in Weiss text (see `Weiss-DataStructures-4e.PDF` in Teams Course Materials)

## Objective

Upon successful completion of this lab, the student has learned how to

* organize and compile class templates in C++

## Getting Started

After accepting this assignment with the provided [GitHub Classroom Assignment link](https://classroom.github.com/a/QhrK--GK), clone this repository. If you have cloned the repository from the command line prompt, navigate into the newly created directory

```bash
cd lab05-github-username
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

We have three tasks today:

1. Work with an inline class template
1. Work with class templates similar to the book
1. Work with class templates by declaring their use separately.

### Task 1

1. Create a new folder in the `include` folder named `task1`.
1. Add a new file named `memory_cell.h`
1. Follow along with the instructor for the source code.
1. Update `CMakeLists.txt` as prescribed by your instructor.

### Task 2

1. Create a new folder in the `include` folder named `task2`.
1. Add a new file named `memory_cell.h`
1. Follow along with the instructor for the source code.
1. Add a new file named `memory_cell.cpp`
1. Follow along with the instructor for the source code
1. Update `CMakeLists.txt` as prescribed by your instructor.

### Task 3

1. Create a new folder in the `include` folder named `task3`.
1. Add a new file named `memory_cell.h`
1. Follow along with the instructor for the source code.
1. Add a new file named `memory_cell.cpp`
1. Follow along with the instructor for the source code
1. Update `CMakeLists.txt` as prescribed by your instructor.

## Submission Details

Before submitting your assignment, be sure you have pushed all your changes to GitHub. If this is the first time you're pushing your changes, the push command will look like:

```bash
git push -u origin develop
```

If you've already set up remote tracking (using the `-u origin develop` switch), then all you need to do is type

```bash
git push
```

As usual, prior to submitting your assignment on Blackboard, be sure that you have committed and pushed your final changes to GitHub. Once your final changes have been pushed, create a pull request that seeks to merge the changes in your `develop` branch into your `master` branch. Once your pull request has been created, submit the URL of your assignment _repository_ (i.e., _not_ the URL of the pull request) Blackboard using a Text Submission. Please note: the timestamp of the submission on Blackboard is used to assess any late penalties if and when warranted, _not_ the date/time you create your pull request. **No exceptions will be granted for this oversight**.

### Due Date

Your assignment submission is due by 11:59 PM, Saturday, 05-March, 2022.

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
