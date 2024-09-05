#include "study_in_pink2.h"

void g_satc_02() { // global
    cout << "----- Sample Testcase 02 -----" << endl;
    Configuration * config = new Configuration("sa_tc_02_config");
    cout << config->str() << endl;
    delete config;
}


class TestConfig {
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
    static void satc_02() {
        g_satc_02();
    }
};