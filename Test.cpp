#include "doctest.h"
#include "Board.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include "Direction.hpp"
using ariel::Direction;
using namespace std;
using namespace ariel;


TEST_CASE("Reading empty board"){
    Board b;
    //h//
    CHECK(b.read(0,0,Direction::Horizontal, 1) == "_");
    CHECK(b.read(10,20,Direction::Horizontal, 13) == "_____________");
    CHECK(b.read(100,200,Direction::Horizontal, 9) == "_________");

    //v//
    CHECK(b.read(0,0,Direction::Vertical, 2) == "__");
    CHECK(b.read(10,20,Direction::Vertical, 11) == "___________");
    CHECK(b.read(100,200,Direction::Vertical, 5) == "_____");
}
TEST_CASE("check size 0"){
    Board b;
    CHECK(b.read(1,1, Direction::Horizontal, 0) == "");
    CHECK(b.read(12, 3, Direction::Horizontal, 0) == "");
    CHECK(b.read(5, 2, Direction::Horizontal, 0) == "");
    CHECK(b.read(5, 2, Direction::Vertical, 0) == "");
    CHECK(b.read(1,1, Direction::Vertical, 0) == "");
    CHECK(b.read(3, 12, Direction::Vertical, 0) == "");
}
    
TEST_CASE("check post and read"){
    Board b;
    //check Horizontal
    b.post(0, 0, Direction::Horizontal, "hello teacher");
    CHECK(b.read(0, 0, Direction::Horizontal, 5) == "hello");

    b.post(0, 0, Direction::Horizontal, "hello teacher");
    CHECK(b.read(0, 0, Direction::Horizontal, 13) == "hello_teacher");

    b.post(0, 8, Direction::Horizontal, "hello stav");
    CHECK(b.read(0, 0, Direction::Horizontal, 10) == "_____hello");

    b.post(100, 100, Direction::Horizontal, "hello stav");
    CHECK(b.read(100, 100, Direction::Horizontal, 5) == "hello");

    b.post(100, 100, Direction::Horizontal, "hello mom");
    CHECK(b.read(100, 100, Direction::Horizontal, 10) == "hello_mom_");

    b.post(100, 6, Direction::Horizontal, "hello world");
    CHECK(b.read(100, 100, Direction::Horizontal, 10) == "_____hello");

 //check Vertical
    b.post(0, 0, Direction::Vertical, "hello teacher");
    CHECK(b.read(0, 0, Direction::Vertical, 5) == "hello");

    b.post(0, 0, Direction::Vertical, "hello teacher");
    CHECK(b.read(0, 0, Direction::Vertical, 13) == "hello_teacher");

    b.post(0, 8, Direction::Vertical, "hello stav");
    CHECK(b.read(0, 0, Direction::Vertical, 10) == "_____hello");

    b.post(100, 100, Direction::Vertical, "hello stav");
    CHECK(b.read(100, 100, Direction::Vertical, 5) == "hello");

    b.post(100, 100, Direction::Vertical, "hello mom");
    CHECK(b.read(100, 100, Direction::Vertical, 10) == "hello_mom_");

    b.post(100, 6, Direction::Vertical, "hello world");
    CHECK(b.read(100, 100, Direction::Vertical, 10) == "_____hello");

}