[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-f059dc9a6f8d3a56e377f745f24479a46679e63a5d9fe6f495e02850cd0d8118.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7204179&assignment_repo_type=AssignmentRepo)
# HW03 - Further Explorations in Dynamic Programming

A homework assignment related to dynamic programming in CSC232.

## Background

Before proceeding with this lab, the student should take the time to read

* Simplifying Dynamic Programming - PDF located in Teams > General > Files > Class Materials > Simplifying Dynamic Programming.pdf
  * The Jump It Game
  * Robot in a Grid
* Section C2.5 - Dynamic Allocation of Arrays (this section is found in C++ Interlude 2); this assignment allocates two-dimensional arrays dynamically in `main` and `google-tests` targets. Thus, if any of this code is confusing, look here for support.

### Maximum Number of Golden Coins

A table is composed of m x n cells. Each cell contains a number of golden coins. An example is as follows:

```c++
5    3    9
7    2    2
2    3    1
```

You start at the upper-left cell and want to reach the bottom-right cell. At each step, you can go either down or right one cell. Write a program that uses dynamic programming to find the maximum number of golden coins you can collect.  

The output from your program should display the cache table where the maximum number of golden coins collected on a path from the top-left cell to cell (r, c) is stored in cell (r, c). Also output a message indicating the maximum number of coins on a path from the top-left cell to the right-bottom cell. Sample output for the above grid is as follows (**Note**: you do not have to show borders around the cells, and the leading zeros shown in the first row are just an artifact needed for proper column alignment in this simplified markdown format. Your output **shall not** contain these leading zeros and yet still be right-aligned.):

```bash
05  08  17
12  14  19
14  17  20

Maximum number of golden coins we can collect is 20
```

The program should read input from an input file. The file contains the description of an unspecified number of tables. The data for each table starts with two numbers representing the number of rows and columns in the table. This is followed by the number of coins on each row. For example, the top table is represented as follows:

```c++
3  3
5  3  9
7  2  2
2  3  1
```

Another sample input file with three tables is as follows:

```c++
3  3
5  3  9
7  2  2
2  3  1
2  3
7  2  4
1  5  1
4  5
7  3  4  5  3
2  1  4  8  2
9  2  4  3  1
1  2  3  4  6
```

Ultimately, for the `main` target, you want to meet the following specification: For each input table, display that table. Also display the corresponding cache table followed by a message indicating the maximum number of golden coins that we can collect.

The following shows the expected output of the `main` target when you have successfully completed this assignment. The tables shown here are the "cost matrices," where each cell contains the maximum number of gold coins that could have been collected on a journey to that cell starting from (0, 0).

```text
For the following grid of gold coins:

    5    3    9
    7    2    2
    2    3    1

we obtain the following total cost table:

    5    8   17
   12   14   19
   14   17   20

Maximum number of golden coins we can collect is 20

For the following grid of gold coins:

    7    2    4
    1    5    1

we obtain the following total cost table:

    7    9   13
    8   14   15

Maximum number of golden coins we can collect is 15

For the following grid of gold coins:

    7    3    4    5    3
    2    1    4    8    2
    9    2    4    3    1
    1    2    3    4    6

we obtain the following total cost table:

    7   10   14   19   22
    9   11   18   27   29
   18   20   24   30   31
   19   22   27   34   40

Maximum number of golden coins we can collect is 40

```

## Objective

Upon successful completion of this assignment, the student should know or understand

* that problems exhibiting overlapping sub-problems and optimal substructure lend themselves to dynamic programming techniques
* how to develop state expression used in the development of a dynamic programming solution
* that either a top-down (memoization) or bottom-up (tabulation) approach may be applied to their solutions which often transform naive recursive solutions into extremely efficient solutions

## Getting Started

After accepting this assignment with the provided [GitHub Classroom Assignment link](https://classroom.github.com/a/KU0MhHnk), clone this repository. If you have cloned the repository from the command line prompt, navigate into the newly created directory

```bash
cd hw03-github-username
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

This assignment contains essentially two tasks:

1. Provide an implementation of the `Display` function to display the contents of a two-dimensional array in a neat, tabular fashion (with each table value printing in a field width of 5 spaces, right-aligned)
2. Provide an implementation of the `MaxNumCoins` using Dynamic Programming techniques.

Compare this problem to the goal of the Jump It game. Use the development of the solution to that game outlined in our lectures to devise a Dynamic Programming solution to this problem. Note the differences too; in the Jump It game, the goal was to _minimize_ a "cost" and here the goal is to _maximize_ a "cost." Also think about your approach: Do you want to tackle this using _memoization_ or _tabulation_? How does that choice affect your design decisions?

Look for and address all the `TODO` comments in the project; implement the functions in [csc232.h](include/csc232.h). Be sure to remove the `TODO` comments once you've completed the requested task.

Once you have made your final changes, commit and push them to GitHub and supply the URL of your repository to the Teams assignment.

There is a GitHub Action that is triggered when you push your commits to GitHub. If you would like to see firsthand what the outcome of that action will be _prior_ to committing/pushing your changes, you can always just run the `run_ctests.sh` script from the command line. NOTE: This assumes you're doing this from a Linux-based shell, e.g., an Ubuntu WSL installation, or a Macintosh terminal window.

```bash
./run_ctest.sh
```

Alternatively, you can always just run the `google-tests` target too as this is effectively what `ctest` is doing.

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

Your assignment submission is due by 11:59 PM, Saturday, 05-March, 2022.

### Grading Rubric

This assignment is worth **5 points**.

Criteria          | Exceeds Expectations        | Meets Expectations             | Below Expectations | Failure                                                 |
------------------|-----------------------------|--------------------------------|--------------------|---------------------------------------------------------|
Pull Request (20%)| Submitted early, correct url| Submitted on-time; correct url | Incorrect URL            | No pull request was created or submitted          |
Code Style (20%)  | Exemplary code style        | Consistent, modern coding style    | Inconsistent coding style| No style whatsoever or no code changes present|
Correctness^ (60%)| All unit tests pass         | At least 80% of the unit tests pass| At least 60% of the unit tests pass| Less than 50% of the unit tests pass|

^ _The Google Test unit runner will calculate the correctness points based purely on the fraction of tests passed_.

### Late Penalty

* In the first 24 hour period following the due date, this assignment will be penalized 1 point meaning the grading starts at 4 (out of 5 total possible) points.
* In the second 24 hour period following the due date, this assignment will be penalized 2 points meaning the grading starts at 3 (out of 5 total possible) points.
* After 48 hours, the assignment will not be graded and thus earns no points, i.e., 0 out of 5 possible points.
