#include "study_in_pink2.h"
class TestRun {
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
public:
    static void satc_05() {
        cout << "----- Sample Testcase 05 -----" << endl;
        StudyPinkProgram stpp = StudyPinkProgram("sa_tc_02_config");
        stpp.run(true);
    }
};