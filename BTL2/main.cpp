#include "study_in_pink2.h"
#include "testmap.cpp"
#include "testrun.cpp"
#include "testbasebag.cpp"
#include "testrobot.cpp"
#include "testconfig.cpp"
using namespace std;

class TestStudyInPink {
    friend class Position;
    friend class MovingObject;
    friend class Character;
    friend class Configuration;
    friend class Map;

    friend class Criminal;
    friend class RobotS;
    friend class RobotW;
    friend class RobotSW;
    friend class RobotC;
    friend class ArrayMovingObject;
    friend class StudyPinkProgram;

    friend class BaseItem;
    friend class BaseBag;
    friend class SherlockBag;
    friend class WatsonBag;

    friend class TestMap;
    friend class TestRun;
    friend class TestBaseBag;
    friend class TestRobot;
    friend class TestConfig;
public:

    TestStudyInPink() = default;

    static void satc_01() {
        TestMap::test_01();
        // TestMap::showmap("sa_tc_02_config");
    }

    static void satc_02() {
        TestConfig::satc_02();
    }

    static void satc_03() {
        TestRobot::satc_03();
    }
    static void satc_04() {
        TestBaseBag::satc_04();
    }
    static void satc_05() {
        TestRun::satc_05();
    }

};



int main(int argc, const char * argv[]) {
    // TestStudyInPink::satc_01();     // test map
    // TestStudyInPink::satc_02();     // test config 
    // TestStudyInPink::satc_03();     // test robot
    // TestStudyInPink::satc_04();     // test basebag
    TestStudyInPink::satc_05();     // test run

    return 0;
}


