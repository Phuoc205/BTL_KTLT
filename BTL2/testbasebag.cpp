#include "study_in_pink2.h"
class TestBaseBag {
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
    static void satc_04() {
        cout << "----- Sample Testcase 04 -----" << endl;
        int num_walls = 3;
        Position arr_walls[] = {Position(1, 2), Position(2, 3), Position(3, 4)};
        int num_fake_walls = 1;
        Position arr_fake_walls[] = {Position(2, 0)};

        Map * map = new Map(10, 10, num_walls, arr_walls, num_fake_walls, arr_fake_walls);
        
        Sherlock * sherlock = new Sherlock(1, "RUU", Position(1, 3), map, 96, 349);
        Watson * watson = new Watson(2, "LU", Position(2, 1), map, 100, 351);

        MagicBook magicbook;
        EnergyDrink energydrink;
        FirstAid firstaid;
        ExcemptionCard excemptioncard;
        PassingCard passingcard("all");    
        SherlockBag * sherlockbag = new SherlockBag(sherlock);
        WatsonBag * watsonbag = new WatsonBag(watson);
        BaseItem * mbook = &magicbook;
        BaseItem * edrink = &energydrink;
        BaseItem * faid = &firstaid;
        BaseItem * ecard = &excemptioncard;
        BaseItem * pcard = &passingcard;

        // sherlockbag->insert(pcard);
        // sherlockbag->insert(mbook);
        // sherlockbag->insert(faid);
        // sherlockbag->insert(edrink);
        // sherlockbag->insert(pcard);
        // sherlockbag->insert(ecard);
        // sherlockbag->insert(mbook);
        // sherlockbag->insert(ecard);
        // sherlockbag->insert(pcard);
        // sherlockbag->insert(ecard);

        watsonbag->insert(edrink);
        watsonbag->insert(pcard);
        watsonbag->insert(ecard);
        watsonbag->insert(edrink);
        watsonbag->insert(ecard);
        watsonbag->insert(ecard);
        watsonbag->insert(faid);
        watsonbag->insert(faid);
        watsonbag->insert(edrink);
        watsonbag->insert(faid);

        cout << "Tui do cua sherlock truoc khi hoan doi la:" << endl;
        cout << sherlockbag->str() << endl;
        cout << "Tui do cua watson truoc khi hoan doi la:" << endl;
        cout << watsonbag->str() << endl;
        bool check;

        ItemType item1 = sherlockbag->findItem(check);
        if(!check) sherlockbag->get(item1);
        

        cout << "Tui do cua sherlock sau khi hoan doi la:" << endl;
        cout << sherlockbag->str() << endl;
        cout << "Tui do cua watson sau khi hoan doi la:" << endl;
        cout << watsonbag->str() << endl;

        delete sherlockbag;
        delete watsonbag;
        delete map;
        delete sherlock;
        delete watson;
        return ;
    }
};