#include "study_in_pink2.h"
class TestRobot {
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
    static void satc_03() {
        // Sample test for RobotC
        cout << "----- Sample Testcase 03 -----" << endl;
        int num_walls = 3;
        Position arr_walls[] = {Position(1, 2), Position(2, 3), Position(3, 4)};
        int num_fake_walls = 1;
        Position arr_fake_walls[] = {Position(2, 0)};

        Map * map = new Map(10, 10, num_walls, arr_walls, num_fake_walls, arr_fake_walls);

        Sherlock * sherlock = new Sherlock(1, "RUU", Position(1, 3), map, 250, 450);
        Watson * watson = new Watson(2, "LU", Position(2, 1), map, 300, 350);
        Criminal * criminal = new Criminal(0, Position(8, 9), map, sherlock, watson);

        RobotC * robotC = new RobotC(3, Position(4,8), map, criminal);
        // RobotS * robotS = new RobotS(4, Position(2,5), map, criminal, sherlock);
        // RobotW * robotW = new RobotW(5, Position(6,4), map, criminal, watson);
        // RobotSW * robotSW = new RobotSW(6, Position(7,3), map, criminal, sherlock, watson);

        // cout << "Current position of Criminal: " << criminal->str() << endl;
        // cout << "Criminal makes a move" << endl;
        // criminal->move();
        // cout << "New position of Criminal: " << criminal->str() << endl;
        // cout << "Current position of robotC: " << robotC->str() << endl;
        // cout << "RobotC makes a move" << endl;
        // robotC->move();
        // cout << "New position of robotC: " << robotC->str() << endl << endl << endl;

        // cout << "Current position of Sherlock: " << sherlock->str() << endl;
        // cout << "Sherlock makes a move" << endl;
        // sherlock->move();
        // cout << "New position of Sherlock: " << sherlock->str() << endl;
        // cout << "Current position of robotS: " << robotS->str() << endl;
        // cout << "RobotS makes a move" << endl;
        // robotS->move();
        // cout << "New position of robotS: " << robotS->str() << endl << endl << endl;


        // cout << "Current position of Watson: " << watson->str() << endl;
        // cout << "Watson makes a move" << endl;
        // criminal->move();
        // cout << "New position of Watson: " << watson->str() << endl;
        // cout << "Current position of robotW: " << robotW->str() << endl;
        // cout << "RobotW makes a move" << endl;
        // robotW->move();
        // cout << "New position of robotW: " << robotW->str() << endl << endl << endl;


        // cout << "New position of Sherlock: " << sherlock->str() << endl;
        // cout << "New position of Watson: " << watson->str() << endl;
        // cout << "Current position of robotSW: " << robotSW->str() << endl;
        // cout << "RobotSW makes a move" << endl;
        // robotSW->move();
        // cout << "New position of robotW: " << robotSW->str() << endl;
        cout << robotC->getItem()->str();
        PassingCard * pc = dynamic_cast<PassingCard*>(robotC->getItem());
        cout << pc->challenge;

        delete sherlock;
        delete watson;
        delete criminal;
        delete map;
        delete robotC;
        // delete robotS;
        // delete robotW;
        // delete robotSW;
    }
};