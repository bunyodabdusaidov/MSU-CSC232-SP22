/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2019
 *
 * @file      LinkedBagsGoogleTest.cpp
 * @authors   Jim Daehn <jdaehn@missouristate.edu>
 * @brief     Google Test implementation template.
 */

#include <iomanip>
#include <iostream>
#include <vector>
#include "gtest/gtest.h"
#include "csc232.h"

static int possiblePoints{0};

static int earnedPoints{0};

namespace
{
class LabTestFixture: public ::testing::Test
{
protected:
    void SetUp() override
    {
        possiblePoints += 1;
    }

    void TearDown() override
    {
        if (!HasFailure()) {
            earnedPoints += 1;
        }
    }
};

TEST_F(LabTestFixture, TestThrowTargetNotFoundException)
{
    EXPECT_THROW({
                     try {
                         ThrowTargetNotFoundException("Wine glass");
                     }
                     catch (const TargetNotFoundException &exception) {
                         EXPECT_STREQ("Target not found: Wine glass", exception.what());
                         throw;
                     }
                     catch (const std::exception &e) {
                         FAIL() << "Expected TargetNotFoundException";
                     }
                 }, TargetNotFoundException);
}

#if TEST_INVALID_TARGET_EXCEPTION
TEST_F(LabTestFixture, TestThrowInvalidTargetException)
{
    EXPECT_THROW({
                     try {
                         ThrowInvalidTargetException("Wine glass");
                     }
                     catch (const InvalidTargetException &exception) {
                         EXPECT_STREQ("Invalid target: Wine glass", exception.what());
                         throw;
                     }
                     catch (const std::exception &e) {
                         FAIL() << "Expected InvalidTargetException";
                     }
                 }, InvalidTargetException);
}

#endif

#if TEST_UNEXPECTED_ERROR_EXCEPTION
TEST_F(LabTestFixture, TestThrowUnexpectedErrorException) {
    EXPECT_THROW({
                     try
                     {
                         ThrowUnexpectedErrorException("processing targets");
                     }
                     catch (const UnexpectedErrorException &exception)
                     {
                         EXPECT_STREQ("An unexpected error occurred during runtime while processing targets", exception.what());
                         throw;
                     }
                     catch (const std::exception &e)
                     {
                         FAIL() << "Expected UnexpectedErrorException";
                     }
                 }, UnexpectedErrorException);
}
#endif

#if TEST_INVALID_RANGE_EXCEPTION
TEST_F(LabTestFixture, TestThrowInvalidRangeException) {
    EXPECT_THROW({
                     try
                     {
                         ThrowInvalidRangeException("processing targets");
                     }
                     catch (const InvalidRangeException &exception)
                     {
                         EXPECT_STREQ("An invalid range was encountered while processing targets", exception.what());
                         throw;
                     }
                     catch (const std::exception &e)
                     {
                         FAIL() << "Expected InvalidRangeException";
                     }
                 }, InvalidRangeException);
}
#endif

} // namespace

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int result{RUN_ALL_TESTS()};

    std::cout << "Earned Points:       " << earnedPoints << std::endl;
    std::cout << "Possible Points:     " << possiblePoints << std::endl;
    double correctnessPoints{possiblePoints != 0 ? (static_cast<double>(earnedPoints) / possiblePoints) * 2 : 0};
    std::cout << "Correctness Points:  " << std::fixed << std::setprecision(2) << correctnessPoints << std::endl;
    return result;
}
