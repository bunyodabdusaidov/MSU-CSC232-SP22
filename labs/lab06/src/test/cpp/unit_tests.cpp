/**
 * CSC232 - Data Structures
 * Missouri State University, Spring 2022
 *
 * @file    unit-tests.cpp
 * @author  Jim Daehn <jdaehn@missouristate.edu>
 * @brief   Google Unit tests.
 * @version 0.2021.11.21
 * @date    2021-11-21
 *
 * @copyright Copyright (c) 2021 James R. Daehn
 */

#include <gtest/gtest.h>
#include "csc232.h"
#include "array_bag.h"

static int possiblePoints { 0 };
static int earnedPoints { 0 };
static const int PC_POINTS { 2 }; // Set to 2 for labs, 3 for homework

namespace
{
#if TEST_TASK1

    TEST(Task1TestFixture, ValidateSumOfEmptyBag)
    {
        possiblePoints += 1;

        ArrayBag<int> empty{};
        int expected{0};
        int actual{csc232::sum_contents_of(empty)};

        EXPECT_EQ(expected, actual);

        if ( !HasFailure( ) )
        {
            earnedPoints += 1;
        }
    }

    TEST(Task1TestFixture, ValidateSumOfBagWithOneItem)
    {
        possiblePoints += 1;

        ArrayBag<int> bag{};
        int expected{5};
        bag.add(expected);
        int actual{csc232::sum_contents_of(bag)};

        EXPECT_EQ(expected, actual);

        if ( !HasFailure( ) )
        {
            earnedPoints += 1;
        }
    }

    TEST(Task1TestFixture, ValidateSumOfFullBag)
    {
        possiblePoints += 1;

        ArrayBag<int> bag{};
        int expected{0};
        for ( int entry{ 0}; entry < 6; ++entry)
        {
            expected += entry;
            bag.add(entry);
        }
        int actual{csc232::sum_contents_of(bag)};

        EXPECT_EQ(expected, actual);

        if ( !HasFailure( ) )
        {
            earnedPoints += 1;
        }
    }

    TEST(Task1TestFixture, ValidateSumOfBagWhoseContentsAddToZero)
    {
        possiblePoints += 1;

        ArrayBag<int> bag{};
        int expected{0};
        bag.add(1);
        bag.add(-1);
        bag.add(2);
        bag.add(-2);
        bag.add(3);
        bag.add(-3);
        int actual{csc232::sum_contents_of(bag)};

        EXPECT_EQ(expected, actual);

        if ( !HasFailure( ) )
        {
            earnedPoints += 1;
        }
    }

    TEST(Task1TestFixture, ValidateSumOfBagWhoseSumIsNegative)
    {
        possiblePoints += 1;

        ArrayBag<int> bag{};
        int expected{-6};
        for ( int entry{ 0}; entry < 6; ++entry)
        {
            bag.add(-1);
        }
        int actual{csc232::sum_contents_of(bag)};

        EXPECT_EQ(expected, actual);

        if ( !HasFailure( ) )
        {
            earnedPoints += 1;
        }
    }

#endif

#if TEST_TASK2

    TEST(Task2TestFixture, ValidateSuccessfulReplacement)
    {
        possiblePoints += 1;

        ArrayBag<std::string> bag{};
        std::string target{"CSC232"};
        std::string replacement{"Data Structures"};
        bag.add(target);
        bool result{csc232::replace_item(bag, target, replacement)};

        EXPECT_TRUE(result);

        if ( !HasFailure( ) )
        {
            earnedPoints += 1;
        }
    }

    TEST(Task2TestFixture, ValidateUnsuccessfulReplacementInEmptyBag)
    {
        possiblePoints += 1;

        ArrayBag<std::string> bag{};
        std::string target{"CSC232"};
        std::string replacement{"Data Structures"};
        bool result{csc232::replace_item(bag, target, replacement)};

        EXPECT_FALSE(result);

        if ( !HasFailure( ) )
        {
            earnedPoints += 1;
        }
    }

    TEST(Task2TestFixture, ValidateUnsuccessfulReplacementOfMissingTarget)
    {
        possiblePoints += 1;

        ArrayBag<std::string> bag{};
        std::string item{"csc232"};
        bag.add(item);
        std::string target{"CSC232"};
        std::string replacement{"Data Structures"};
        bool result{csc232::replace_item(bag, target, replacement)};

        EXPECT_FALSE(result);
        EXPECT_FALSE(bag.contains(target));
        EXPECT_FALSE(bag.contains(replacement));
        EXPECT_TRUE(bag.contains(item));

        if ( !HasFailure( ) )
        {
            earnedPoints += 1;
        }
    }

#endif

#if TEST_TASK3

    TEST(Task3TestFixture, ValidateMergeOfEmptyBags)
    {
        possiblePoints += 1;

        ArrayBag<double> bag1;
        ArrayBag<double> bag2;

        ArrayBag<double> merged{csc232::merge(bag1, bag2)};

        EXPECT_TRUE(merged.isEmpty());

        if ( !HasFailure( ) )
        {
            earnedPoints += 1;
        }
    }

    TEST(Task3TestFixture, ValidateMergeOfEmptyBagWithNonEmptyBag)
    {
        possiblePoints += 1;

        ArrayBag<double> bag1;
        ArrayBag<double> bag2;
        double item{3.14};
        bag2.add(item);

        ArrayBag<double> merged{csc232::merge(bag1, bag2)};

        EXPECT_FALSE(merged.isEmpty());
        EXPECT_TRUE(merged.contains(item));

        if ( !HasFailure( ) )
        {
            earnedPoints += 1;
        }
    }

    TEST(Task3TestFixture, ValidateMergeOfNonEmptyBagWithEmptyBag)
    {
        possiblePoints += 1;

        ArrayBag<double> bag1;
        ArrayBag<double> bag2;
        double item{3.14};
        bag1.add(item);

        ArrayBag<double> merged{csc232::merge(bag1, bag2)};

        EXPECT_FALSE(merged.isEmpty());
        EXPECT_TRUE(merged.contains(item));

        if ( !HasFailure( ) )
        {
            earnedPoints += 1;
        }
    }

    TEST(Task3TestFixture, ValidateMergeOfNonEmptyBags)
    {
        possiblePoints += 1;

        ArrayBag<double> bag1;
        ArrayBag<double> bag2;
        double item{3.14};
        bag1.add(item);
        bag2.add(item);

        ArrayBag<double> merged{csc232::merge(bag1, bag2)};

        EXPECT_FALSE(merged.isEmpty());
        EXPECT_TRUE(merged.contains(item));
        EXPECT_EQ(merged.getFrequencyOf(item), 2);

        if ( !HasFailure( ) )
        {
            earnedPoints += 1;
        }
    }

#endif

#if EXECUTE_TEST_FIXTURE
    class ArrayBagTestFixture : public ::testing::Test
    {
    protected:
        /**
         * Code here will be called immediately after the constructor
         * right before each test...
         */
        void SetUp ( ) override
        {
            possiblePoints += 1;
            test_bag = new ArrayBag<std::string> { };
        }

        /**
         * Code here will be called immediately after each test
         * right before the destructor...
         */
        void TearDown ( ) override
        {
            if ( nullptr != test_bag )
            {
                delete test_bag;
            }

            if ( !HasFailure( ) )
            {
                earnedPoints += 1;
            }
        }

        // Objects declared below can be used by all tests in this test fixture.
        Bag<std::string>* test_bag;
    };

    TEST_F( ArrayBagTestFixture, InitiallyArrayBagIsEmpty )
    {
        // When a bag is created in the Setup
        // Then I expect it to be empty
        EXPECT_TRUE( test_bag->isEmpty( ) );
    } // TEST_F

    TEST_F( ArrayBagTestFixture, AddingAnItemIncreasesSize )
    {
        // Given an originally empty bag created in the Setup
        // When I add an item to that bag
        test_bag->add( "one" );

        // Then the number of items in the bag is 1
        EXPECT_TRUE( test_bag->getCurrentSize( ) == 1 );

        // And when I add another item to the bag
        test_bag->add( "two" );
        // Then the number of items in the bag is now 2
        EXPECT_TRUE( test_bag->getCurrentSize( ) == 2 );
    }

    TEST_F( ArrayBagTestFixture, CanAddItemsToAlmostFullBag )
    {
        // Given: Enough items to fill a bag leaving room for one more item
        std::vector<std::string> expected { "one", "two", "three", "four", "five" };
        for ( auto item: expected )
        {
            test_bag->add( item );
        }

        // When I try to add another item
        auto result { test_bag->add( "Primus sucks!" ) };

        // Then I expect the addition failed
        EXPECT_TRUE( result );
    }

    TEST_F( ArrayBagTestFixture, CannotAddItemsToFullBag )
    {
        // Given: Enough items to completely fill a bag
        std::vector<std::string> expected { "one", "two", "three", "four", "five", "one" };
        for ( auto item: expected )
        {
            test_bag->add( item );
        }

        // When I try to add another item
        auto result { test_bag->add( "Primus sucks!" ) };

        // Then I expect the addition failed
        EXPECT_FALSE( result );
    }

    TEST_F( ArrayBagTestFixture, BagContentsAvailableInVectorForm )
    {
        // Given: Enough items to completely fill a bag
        std::vector<std::string> expected { "one", "two", "three", "four", "five", "one" };
        for ( auto item: expected )
        {
            test_bag->add( item );
        }

        // When I get a vector copy of the bag contents
        std::vector<std::string> actual { test_bag->toVector( ) };

        // The vector contains all the items I expected to see
        EXPECT_TRUE( actual == expected );
    }

    TEST_F( ArrayBagTestFixture, BagProvidesNumberOfItems )
    {
        // Given a bag stuffed with three items
        std::vector<std::string> sample { "one", "two", "three" };
        for ( auto item: sample )
        {
            test_bag->add( item );
        }

        // When I query for the number of items in the bag
        auto actual { test_bag->getCurrentSize( ) };
        int expected { static_cast<int>(sample.size( )) };
        EXPECT_EQ( expected, actual );
    }

    /*
     * bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
     *  - remove existing (true result)
     *  - remove from empty bag (false result)
     *  - remove non-existent item (false result)
     */
    TEST_F( ArrayBagTestFixture, ValidateRemovalOfExistingItem )
    {
        // Given a bag stuffed with three items
        std::vector<std::string> sample { "one", "two", "three" };
        for ( auto item: sample )
        {
            test_bag->add( item );
        }

        // When I try to remove item "two"
        auto result { test_bag->remove( "two" ) };

        // Then I'm greeted with the joy and happiness
        EXPECT_TRUE( result );
    }

    TEST_F( ArrayBagTestFixture, ValidateInabilityToRemoveFromEmptyBag )
    {
        // Given an empty bag from the Setup
        // When I try to remove "Jim" from it
        auto result { test_bag->remove( "Jim" ) };

        // Then I'm mocked and ridiculed for such madness!
        // How can you remove that which does not exist, Jim?
        EXPECT_FALSE( result );
    }

    TEST_F( ArrayBagTestFixture, ValidateInabilityToRemoveNonExistentItem )
    {
        // Given a bag stuffed with three items
        std::vector<std::string> sample { "one", "two", "three" };
        for ( auto item: sample )
        {
            test_bag->add( item );
        }

        // When I try to remove item "Jim"
        auto result { test_bag->remove( "Jim" ) };

        // Then I'm mocked and ridiculed for such madness!
        // How can you remove that which does not exist, Jim?
        EXPECT_FALSE( result );
    }

    /*
     * void ArrayBag<ItemType>::clear()
     * - Clearing an empty bag leaves a bag with no items
     * - Clearing a bag with originally one item leaves a bag with no items
     * - Clearing a nearly full bag leaves a bag with no items
     * - Clearing a full bag leaves a bag with no items
     */

    TEST_F( ArrayBagTestFixture, ValidateClearingOfEmptyBag )
    {
        // Given an empty bag from the Setup
        // When I clear that bag
        test_bag->clear( );

        // Then I expect that bag to be empty
        EXPECT_TRUE( test_bag->isEmpty( ) );
    }

    TEST_F( ArrayBagTestFixture, ValidateClearingBagContainingOneItem )
    {
        // Given an empty bag from the Setup that has one item added to it
        test_bag->add( "Calgon, take me away!" );

        // When I clear that bag
        test_bag->clear( );

        // Then I expect that bag to be empty
        EXPECT_TRUE( test_bag->isEmpty( ) );
    }

    TEST_F( ArrayBagTestFixture, ValidateClearingOfNearlyFullBag )
    {
        // Given a bag stuffed with five items
        std::vector<std::string> sample { "one", "two", "three", "four", "five" };
        for ( auto item: sample )
        {
            test_bag->add( item );
        }

        // When I clear that bag
        test_bag->clear( );

        // Then I expect that bag to be empty
        EXPECT_TRUE( test_bag->isEmpty( ) );
    }

    TEST_F( ArrayBagTestFixture, ValidateClearingOfFullBag )
    {
        // Given a bag stuffed to the gills with items
        std::vector<std::string> sample { "one", "two", "three", "four", "five", "six" };
        for ( auto item: sample )
        {
            test_bag->add( item );
        }

        // When I clear that bag
        test_bag->clear( );

        // Then I expect that bag to be empty
        EXPECT_TRUE( test_bag->isEmpty( ) );
    }

    /*
     * bool ArrayBag<ItemType>::contains(const ItemType& target) const
     * - Searching for an existing item yields joy and happiness
     * - Searching for a non-existent item in an empty bag leads to mockery and ridicule
     * - Searching for a non-existent item in a bag with items also leads to mockery and ridicule
     */
    TEST_F( ArrayBagTestFixture, ValidateSearchingForExistingItem )
    {
        // Given a bag stuffed to the gills with items
        std::vector<std::string> sample { "one", "two", "three", "four", "five", "six" };
        for ( auto item: sample )
        {
            test_bag->add( item );
        }
        bool item_found{ true };

        // When I search for an existing items
        for (auto item : sample)
        {
            if (!test_bag->contains(item))
            {
                item_found = false;
                break;
            }
        }
        // Then I expect they were found
        EXPECT_TRUE(item_found);
    }

    TEST_F( ArrayBagTestFixture, ValidateSearchingForItemInEmptyBag )
    {
        // Given an empty bag from our Setup
        // When I search for an item
        bool result{test_bag->contains("Jim")};

        // Then I expect mockery and ridicule
        EXPECT_FALSE(result);
    }

    TEST_F( ArrayBagTestFixture, ValidateSearchingForNonexistentItemInBagWithItems )
    {
        // Given a bag stuffed to the gills with items
        std::vector<std::string> sample { "one", "two", "three", "four", "five", "six" };
        for ( auto item: sample )
        {
            test_bag->add( item );
        }

        // When I search for a non-existent item
        bool result{test_bag->contains("Jim")};

        // Then I expect mockery and ridicule
        EXPECT_FALSE(result);
    }

    /*
     * int ArrayBag<ItemType>::getFrequencyOf(const ItemType& target) const
     * - Getting the frequency of an item that exists only once is possible
     * - Getting the frequency of an item that occurs more than one is possible
     * - Getting the frequency of an item from an empty bag ..., bad, bad idea
     * - Getting the frequency of item that does not exist is also possible; it's just 0
     */
    TEST_F( ArrayBagTestFixture, ValidateFrequencyOfItemOccuringOnceInBag )
    {
        // Given a bag stuffed to the gills with items
        std::vector<std::string> sample { "one", "two", "three", "four", "five", "six" };
        for ( auto item: sample )
        {
            test_bag->add( item );
        }
        const int EXPECTED_FREQUENCY{ 1 };
        bool expectations{ true };

        // When I query the frequency for existing items
        for (auto item : sample)
        {
            if (test_bag->getFrequencyOf(item) != EXPECTED_FREQUENCY)
            {
                expectations = false;
                break;
            }
        }

        // Then I expect they occurred the anticipated number of times
        EXPECT_TRUE(expectations);
    }

    TEST_F( ArrayBagTestFixture, ValidateFrequencyOfItemOccuringTwiceInBag )
    {
        // Given a bag stuffed to the gills with items, one of which occurs twice
        std::vector<std::string> sample { "one", "two", "three", "four", "five", "one" };
        for ( auto item: sample )
        {
            test_bag->add( item );
        }
        const int EXPECTED_FREQUENCY{ 2 };

        // When I get the frequency of the item that occurs twice
        int result{ test_bag->getFrequencyOf( "one" ) };

        // Then I expect it occurred the anticipated number of times
        EXPECT_EQ( result, EXPECTED_FREQUENCY);
    }

    TEST_F( ArrayBagTestFixture, ValidateFrequencyOfItemInEmptyBag )
    {
        // Given an empty bag from Setup
        const int EXPECTED_FREQUENCY{ 0 };

        // When I get the frequency of a non-existent item
        int result{ test_bag->getFrequencyOf( "seven" ) };

        // Then I expect it occurred the anticipated number of times
        EXPECT_EQ( result, EXPECTED_FREQUENCY);
    }

    TEST_F( ArrayBagTestFixture, ValidateFrequencyOfNonExistentItemInBagOfItems )
    {
        // Given a bag stuffed to the gills with items
        std::vector<std::string> sample { "one", "two", "three", "four", "five", "six" };
        for ( auto item: sample )
        {
            test_bag->add( item );
        }
        const int EXPECTED_FREQUENCY{ 0 };

        // When I get the frequency of a non-existent item
        int result{ test_bag->getFrequencyOf( "seven" ) };

        // Then I expect it occurred the anticipated number of times
        EXPECT_EQ( result, EXPECTED_FREQUENCY);
    }

#endif // EXECUTE_TEST_FIXTURE

} // namespace for fixture


int main ( int argc, char** argv )
{
    ::testing::InitGoogleTest( &argc, argv );
    int result { RUN_ALL_TESTS( ) };

    std::cout << "Earned Points:       " << std::right << std::setw( 4 ) << earnedPoints << std::endl;
    std::cout << "Possible Points:     " << std::right << std::setw( 4 ) << possiblePoints << std::endl;
    double correctness_points { 0 };
    if ( possiblePoints != 0 )
    {
        correctness_points = ( static_cast<double>(earnedPoints) / possiblePoints ) * PC_POINTS;
    }

    std::cout << "Correctness Points:  " << std::fixed << std::setprecision( 2 )
              << correctness_points << std::endl;
    return result;
}
