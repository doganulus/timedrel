#include "catch.hpp"
#include "timedrel/zone_set.hpp"
#include "timedrel/utils.hpp"

using namespace timedrel;

// TEST_CASE( "Construction" ) {

//     SECTION( "Normalization 1" ) {

//         auto zs1 = zone_set<int>();

//         zs.add(zone<int>::make({2,8,2,8,0,6}));

//     }

// }

TEST_CASE( "Insertion" ) {

    SECTION( "Don't add already included regions" ) {

        auto zs = zone_set<int>();

        zs.add({0,9,0,9,0,9});
        zs.add({0,6,0,6,0,6});
        zs.add({2,8,2,8,0,6});

        zs = zone_set<int>::filter(zs);

        auto expected = zone_set<int>();
        expected.add({0,9,0,9,0,9});

        CHECK( zs == expected );

    }

    // SECTION( "Include" ) {

    //     auto zs = zone_set<int>();

    //     zs.add({0,6,0,6,0,6});
    //     zs.add({2,8,2,8,0,6});

    //     zs = zone_set<int>::filter(zs);

    //     auto expected = zone_set<int>();
    //     expected.add({2,8,2,8,0,6});
    //     expected.add({0,6,0,6,0,6});

    //     CHECK( zs == expected );

    // }

    SECTION( "Remove included zones" ) {

        auto zs = zone_set<int>();

        zs.add({2,8,2,8,0,6});
        zs.add({0,6,0,6,0,6});
        zs.add({0,9,0,9,0,9});

        zs = zone_set<int>::filter(zs);

        auto expected = zone_set<int>();
        expected.add({0,9,0,9,0,9});

        CHECK( zs == expected );

    }

}

TEST_CASE( "Intersection" ) {

    SECTION( "Intersecting Boxes" ) {

        auto zs1 = zone_set<int>();
        auto zs2 = zone_set<int>();

        zs1.add({0,6,9,16,3,16});
        zs1.add({8,16,18,24,2,16});

        zs2.add({4,10,13,21,3,17});
        zs2.add({14,20,22,28,2,14});

        auto result = zone_set<int>::intersect(zs1, zs2);

        auto expected = zone_set<int>();
        expected.add({4,6,13,16,7,12});
        expected.add({8,10,18,21,8,13});
        expected.add({14,16,22,24,6,10});

        CHECK( result == expected );

    }

}

TEST_CASE( "Concatenation" ) {

    SECTION( "Self-Concatenation" ) {

        auto zs1 = zone_set<int>();
        auto zs2 = zone_set<int>();

        zs1.add({0,10,0,10,3,4});
        zs2.add({0,10,0,10,3,4});

        auto result = zone_set<int>::concatenate(zs1, zs2);

        auto expected = zone_set<int>();
        expected.add({0,10,0,10,6,8});

        CHECK( result == expected );
    }

    SECTION( "Single Closure" ) {

        auto zs1 = zone_set<int>();
        zs1.add({0,20,0,20,3,4});

        auto result = zone_set<int>::closure(zs1);

        auto expected = zone_set<int>();
        expected.add({0,20,0,20,3,4});
        expected.add({0,20,0,20,6,8});
        expected.add({0,20,0,20,9,12});
        expected.add({0,20,0,20,12,16});
        expected.add({0,20,0,20,15,20});

        CHECK( result == expected );

    }

}

TEST_CASE( "General" ) {

    SECTION( "rvalues" ) {

        auto zs1 = zone_set<int>();
        auto zs2 = zone_set<int>();

        zs1.add({0,10,0,10,3,4});
        zs2.add({0,10,0,10,0,10});

        auto result = zone_set<int>::concatenate(zs1, zone_set<int>::constrain(zs2,3,4));

        auto expected = zone_set<int>();
        expected.add({0,10,0,10,6,8});

        CHECK( result == expected );
    }

}