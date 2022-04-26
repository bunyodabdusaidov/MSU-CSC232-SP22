[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7683239&assignment_repo_type=AssignmentRepo)
# LAB10 - Testing the List Interface

This is a non-graded lab wherein we explore group projects in the context of Chapter 8.

## Background

Before proceeding with this lab, the student should take the time to read

* this
* that 
* and the other thing

## Objective

Upon successful completion of this lab, the student has learned how to

* do this
* do that
* do another thing

## Getting Started

After accepting this assignment with the provided [GitHub Classroom Assignment link](https://classroom.github.com/fill-me-in), clone this repository. If you have cloned the repository from the command line prompt, navigate into the newly created directory

```bash
cd labn-github-username
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

This lab consists of three tasks:

* Task 1: Fill in comments on methods
* Task 2: Create stubbed-out implementation named ListImpl
* Task 3: Create Unit Tests for List Interface Axioms

Pol, neuter abactor!

### Task 1: Fill in comments on methods

Use your text from Chapter 8 to fill in the Doxygen comments. This will help you recall the details of the List Interface, if not, lead you to questions of clarification on the interface itself. Bottomline: We're developing an _understanding_ of the `ListInterface`.

### Task 2: Create stubbed-out implementation named ListImpl

Next, in the space indicated in `csc232.h`, create a stubbed-out implementation of the `ListInterface` named `ListImpl`.

### Task 3: Create Unit Tests for List Interface Axioms

Recall the axioms:

```c++
 1. (List()).isEmpty() = true
 2. (List()).getLength() = 0
 3. aList.getLength() = (aList.insert(i, item)).getLength() - 1
 4. aList.getLength() = (aList.remove(i)).getLength() + 1
 5. (aList.insert(i, item)).isEmpty() = false
 6. (List()).remove(i) = false
 7. aList.insert(i, item).remove(i) = true
 8. aList.insert(i, item).remove(i) = aList
 9. (List()).getEntry(i) ==> error
10. (aList.insert(i, item)).getEntry(i) = item
11. aList.getEntry(i) = (aList.insert(i, item)).getEntry(i + 1)
12. aList.getEntry(i + 1) = (aList.remove(i)).getEntry(i)
13. (List()).replace(i, item) ==> error
14. (aList.replace(i, item)).getEntry(i) = item
```

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

Your assignment submission is due by 11:59 PM, ....

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
