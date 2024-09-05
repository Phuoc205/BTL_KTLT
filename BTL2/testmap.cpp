#include "study_in_pink2.h"
#include <vector>
#include <iomanip>
class TestMap {
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
    TestMap() =default;

    static void test_01(){
        cout << "----- Sample Testcase 01 -----" << endl;
        int num_walls = 3;
        Position arr_walls[] = {Position(7, 7), Position(8, 3), Position(3, 3)};
        int num_fake_walls = 1;
        Position arr_fake_walls[] = {Position(1, 3)};

        Map * map = new Map(10, 10, num_walls, arr_walls, num_fake_walls, arr_fake_walls);
        
        Sherlock * sherlock = new Sherlock(1, "RUU", Position(7, 4), map, 250, 450);
        cout << sherlock->str() << endl;

        Watson * watson = new Watson(2, "LU", Position(5, 3), map, 300, 765);
        cout << watson->str() << endl;

        Criminal * criminal = new Criminal(0, Position(8, 4), map, sherlock, watson);
        cout << criminal->str() << endl;

        cout << "* Sherlock makes a move" << endl;
        sherlock->move();
        cout << sherlock->str() << endl;

        cout << "* Watson makes a move" << endl;
        watson->move();
        cout << watson->str() << endl;

        cout << "* Criminal makes a move" << endl;
        criminal->move();
        cout << criminal->str() << endl;

        RobotC * robotC = new RobotC(3, Position(7,9), map, criminal);
        RobotS * robotS = new RobotS(4, Position(2,5), map, criminal, sherlock);
        RobotW * robotW = new RobotW(5, Position(6,4), map, criminal, watson);
        RobotSW * robotSW = new RobotSW(6, Position(7,3), map, criminal, sherlock, watson);

        ArrayMovingObject * arr_mv_objs = new ArrayMovingObject(10);
        arr_mv_objs->add(criminal);
        arr_mv_objs->add(sherlock);
        arr_mv_objs->add(watson);
        arr_mv_objs->add(robotC);
        arr_mv_objs->add(robotS);
        arr_mv_objs->add(robotSW);
        arr_mv_objs->add(robotW);
        // cout << arr_mv_objs->str() << endl;
        cout << map->isValid(Position(1,3),watson);
        
        delete arr_mv_objs;
        delete sherlock;
        delete watson;
        delete criminal;
        delete map;
    }
    // static void showmap(const string & config_file_path){
    //     StudyPinkProgram test = StudyPinkProgram(config_file_path);
    //     RobotC * robotC = new RobotC(3, Position(7,8), test.map, test.criminal);
    //     RobotS * robotS = new RobotS(4, Position(5,1), test.map, test.criminal, test.sherlock);
    //     RobotW * robotW = new RobotW(5, Position(6,4), test.map, test.criminal, test.watson);
    //     RobotSW * robotSW = new RobotSW(6, Position(7,3), test.map, test.criminal, test.sherlock, test.watson);
    //     test.arr_mv_objs->add(robotC);
    //     test.arr_mv_objs->add(robotS);
    //     test.arr_mv_objs->add(robotSW);
    //     test.arr_mv_objs->add(robotW);
    //     test.show();
    //     delete robotC;
    //     delete robotS;
    //     delete robotSW;
    //     delete robotW;
    // }
    // void comparefile(int start,  int end);
    // void test(string inputfile);
};
void abc(){

// /*
//  * Hướng dẫn chạy testcase
//  * Chạy 2 lệnh sau trong terminal
//  *
//  * Lệnh 1:
//  * g++ -o main main.cpp
//  *
//  * Lệnh 2:
//  * Chạy full 200 test
//  * ./main
//  *
//  * Chạy test chỉ định
//  * ./main <test>
//  * VD: ./main 111
//  *
//  * Chạy cụm test
//  * ./main <from> <to>
//  * VD: ./main 1 10
//  */


// void TestMap :: comparefile(int start, int end)
// {
//     vector<int> result;
//     for (int i = start; i <= end; i++)
//     {
//         string outputFile = "testcase/output/output" + to_string(i) + ".txt";
//         string expectFile = "testcase/expect/expect" + to_string(i) + ".txt";
//         ifstream read_output(outputFile);
//         ifstream read_expect(expectFile);
//         if (read_expect.fail())
//         {
//             cout << "Error reading file - " << i << endl;
//             return;
//         }
//         string s1, s2;
//         while (read_output >> s1 && read_expect >> s2)
//         {
//             if (s1 != s2)
//             {
//                 result.push_back(i);
//                 break;
//             }
//         }
//         if (read_output >> s1 || read_expect >> s2)
//         {
//             if (result.getCount() == 0 || result.getCount() > 0 && result[result.getCount() - 1] != i)
//                 result.push_back(i);
//         }
//     }

//     if (result.getCount() == 0)
//     {
//         cout << "Success: test " << start << " to " << end << endl;
//     }
//     else
//     {
//         cout << "percent success : " << (1 - result.getCount() * 1.0 / (end - start + 1)) * 100 << "%" << endl;
//         cout << "Fail : test [";
//         for (int i = 0; i < result.getCount() - 1; i++)
//         {
//             cout << result[i] << ", ";
//         }
//         cout << result[result.getCount() - 1] << "]\n";
//         cout << "link check comparefile: https://www.diffchecker.com/text-compare/" << endl;
//     }
// }
// void TestMap :: test(string inputFile)
// {
//     // ! Position constructor get set str isEqual
//     Configuration configuration = Configuration(inputFile);
//     sherlock_init_pos[0]=configuration.sherlock_init_pos.getRow();
//     sherlock_init_pos[1]=configuration.sherlock_init_pos.getCol();
//     watson_init_pos[0]=configuration.watson_init_pos.getRow();
//     watson_init_pos[1]=configuration.watson_init_pos.getCol();
//     criminal_init_pos[0]=configuration.criminal_init_pos.getRow();
//     criminal_init_pos[1]=configuration.criminal_init_pos.getCol();
//     num_walls=configuration.num_walls;
//     num_fake_walls=configuration.num_fake_walls;
//     map_num_cols=configuration.map_num_cols;
//     map_num_rows=configuration.map_num_rows;
//     max_num_moving_objects=configuration.max_num_moving_objects;
//     sherlock_init_exp=configuration.sherlock_init_exp;
//     sherlock_init_hp=configuration.sherlock_init_hp;
//     sherlock_moving_rule=configuration.sherlock_moving_rule;
//     watson_moving_rule=configuration.watson_moving_rule;
//     watson_init_exp=configuration.watson_init_exp;
//     watson_init_hp=configuration.watson_init_hp;
//     num_steps=configuration.num_steps;
//     for(int i=0; i<num_walls ; i++){
//         arr_walls[i][0] = configuration.arr_walls[i].getRow();
//         arr_walls[i][1] = configuration.arr_walls[i].getCol();
//     }
//     for(int i=0; i<num_fake_walls ; i++){
//         arr_fake_walls[i][0] = configuration.arr_fake_walls[i].getRow();
//         arr_fake_walls[i][1] = configuration.arr_fake_walls[i].getCol();
//     }
//     Map * maps = new Map(configuration.map_num_rows,configuration.map_num_cols,configuration.num_walls,configuration.arr_walls,configuration.num_fake_walls,configuration.arr_fake_walls);
//     Sherlock * sherlock = new Sherlock(1,configuration.sherlock_moving_rule,configuration.sherlock_init_pos,maps,configuration.sherlock_init_hp,configuration.sherlock_init_exp);
//     Watson * watson = new Watson(2,configuration.watson_moving_rule,configuration.watson_init_pos,maps,configuration.watson_init_hp,configuration.watson_init_exp);
//     Criminal * criminal = new Criminal(0,configuration.criminal_init_pos, maps, sherlock, watson);

//     string posStrSher = "(" + to_string(sherlock_init_pos[0]) + "," + to_string(sherlock_init_pos[1]) + ")";
//     string posStrWat = "(" + to_string(watson_init_pos[0]) + "," + to_string(watson_init_pos[1]) + ")";
//     Position posSher(posStrSher);
//     OUTPUT << "Position string constructor : ";
//     OUTPUT << "Pos " + posStrSher << endl
//            << "Get row col : (" << posSher.getRow() << "," << posSher.getCol() << ")" << endl;
//     OUTPUT << "Set " + posStrWat << endl;
//     posSher.setRow(watson_init_pos[0]);
//     posSher.setCol(watson_init_pos[1]);
//     OUTPUT << "Get row col : (" << posSher.getRow() << "," << posSher.getCol() << ")" << endl;
//     OUTPUT << "Position str : " << posSher.str() << endl;

//     OUTPUT << "IsEqual old Position: " << ((posSher.isEqual(sherlock_init_pos[0], sherlock_init_pos[1])) ? "True" : "False") << endl;
//     OUTPUT << "IsEqual Watson Position: " << ((posSher.isEqual(watson_init_pos[0], watson_init_pos[1])) ? "True" : "False") << endl;

//     // ! Map test

//     Position posWall[100];
//     for (int i = 0; i < num_walls; i++)
//     {
//         posWall[i] = Position(arr_walls[i][0], arr_walls[i][1]);
//     }
//     Position posFakeWall[100];
//     for (int i = 0; i < num_fake_walls; i++)
//     {
//         posFakeWall[i] = Position(arr_fake_walls[i][0], arr_fake_walls[i][1]);
//     }

//     Map map = Map(map_num_rows, map_num_cols, num_walls, posWall, num_fake_walls, posFakeWall);
//     OUTPUT << "Map Check : " << map.getNumRows() << "x" << map.getNumCols() << endl;
//     for (int i = -1; i < map_num_cols; i++)
//     {
//         if (i == -1)
//             OUTPUT << setw(5) << "";
//         else
//             OUTPUT << setw(5) << i;
//     }
//     OUTPUT << endl;
    // for (int i = 0; i < map.getNumRows(); i++)
    // {
    //     OUTPUT << setw(5) << i;
    //     for (int j = 0; j < map.getNumCols(); j++)
    //     {
    //         int idx = (int)map.getType();
    //         string nameElement[3] = {".", "W", "F"};
    //         OUTPUT << setw(5) << nameElement[idx];
    //     }
    //     OUTPUT << endl;
    // }
    // // ! isValid
    // OUTPUT << "IsValid (" << -1 << "," << map_num_cols / 2 << ",Watson," << 0 << ") : "
    //        << ((map.isValid(-1, map_num_cols / 2, MovingObject::WATSON, 0))
    //                ? "True"
    //                : "False")
    //        << endl;
    // OUTPUT << "IsValid (" << map_num_rows / 2 << "," << -1 << ",Watson," << 0 << ") : "
    //        << ((map.isValid(map_num_rows / 2, -1, MovingObject::WATSON, 0))
    //                ? "True"
    //                : "False")
    //        << endl;
    // OUTPUT << "IsValid (" << 0 << "," << map_num_cols << ",Watson," << 0 << ") : "
    //        << ((map.isValid(0, map_num_cols, MovingObject::WATSON, 0))
    //                ? "True"
    //                : "False")
    //        << endl;
    // OUTPUT << "IsValid (" << map_num_rows << "," << 0 << ",Watson," << 0 << ") : "
    //        << ((map.isValid(map_num_rows, 0, MovingObject::WATSON, 0))
    //                ? "True"
    //                : "False")
    //        << endl;

    // OUTPUT << "IsValid (" << -1 << "," << -1 << ",UNKNORW," << 0 << ") : "
    //        << ((map.isValid(-1, -1, MovingObject(4), 0))
    //                ? "True"
    //                : "False")
    //        << endl;
    // OUTPUT << "IsValid (" << 0 << "," << 0 << ",UNKNORW," << 0 << ") : "
    //        << ((map.isValid(0, 0, MovingObject(4), 0))
    //                ? "True"
    //                : "False")
    //        << endl;

    // OUTPUT << "IsValid (" << 0 << "," << 0 << ",Watson," << 0 << ") : "
    //        << ((map.isValid(0, 0, MovingObject::WATSON, 0))
    //                ? "True"
    //                : "False")
    //        << endl;
    // OUTPUT << "IsValid (" << 0 << "," << 0 << ",Sherlock," << 0 << ") : "
    //        << ((map.isValid(0, 0, MovingObject::SHERLOCK, 0))
    //                ? "True"
    //                : "False")
    //        << endl;
    // OUTPUT << "IsValid (" << 0 << "," << 0 << ",Criminal," << 0 << ") : "
    //        << ((map.isValid(0, 0, MovingObject::CRIMINAL, 0))
    //                ? "True"
    //                : "False")
    //        << endl;

    // OUTPUT << "IsValid (" << 0 << "," << 0 << ",Robot," << 0 << ") : "
    //        << ((map.isValid(0, 0, MovingObject::ROTBOT, 0))
    //                ? "True"
    //                : "False")
    //        << endl;

    // if (num_walls != 0)
    // {
    //     OUTPUT << "Wall Check : " << endl;
    //     OUTPUT << "IsValid (" << arr_walls[0][0] << "," << arr_walls[0][1] << ",Sherlock," << 0 << ") : "
    //            << ((map.isValid(arr_walls[0][0], arr_walls[0][1], MovingObject::SHERLOCK, 0))
    //                    ? "True"
    //                    : "False")
    //            << endl;

    //     OUTPUT << "IsValid (" << arr_walls[0][0] << "," << arr_walls[0][1] << ",Watson," << 0 << ") : "
    //            << ((map.isValid(arr_walls[0][0], arr_walls[0][1], MovingObject::WATSON, 0))
    //                    ? "True"
    //                    : "False")
    //            << endl;

    //     OUTPUT << "IsValid (" << arr_walls[0][0] << "," << arr_walls[0][1] << ",Criminal," << 0 << ") : "
    //            << ((map.isValid(arr_walls[0][0], arr_walls[0][1], MovingObject::CRIMINAL, 0))
    //                    ? "True"
    //                    : "False")
    //            << endl;

    //     OUTPUT << "IsValid (" << arr_walls[0][0] << "," << arr_walls[0][1] << ",Robot," << 0 << ") : "
    //            << ((map.isValid(arr_walls[0][0], arr_walls[0][1], MovingObject::ROTBOT, 0))
    //                    ? "True"
    //                    : "False")
    //            << endl;
    // }
    // if (num_fake_walls != 0)
    // {
    //     OUTPUT << "FakeWall Check : " << endl;

    //     OUTPUT << "IsValid (" << arr_fake_walls[0][0] << "," << arr_fake_walls[0][1] << ",Sherlock," << 0 << ") : "
    //            << ((map.isValid(arr_fake_walls[0][0], arr_fake_walls[0][1], MovingObject::SHERLOCK, 0))
    //                    ? "True"
    //                    : "False")
    //            << endl;
    //     OUTPUT << "IsValid (" << arr_fake_walls[0][0] << "," << arr_fake_walls[0][1] << ",Criminal," << 0 << ") : "
    //            << ((map.isValid(arr_fake_walls[0][0], arr_fake_walls[0][1], MovingObject::CRIMINAL, 0))
    //                    ? "True"
    //                    : "False")
    //            << endl;
    //     OUTPUT << "IsValid (" << arr_fake_walls[0][0] << "," << arr_fake_walls[0][1] << ",Robot," << 0 << ") : "
    //            << ((map.isValid(arr_fake_walls[0][0], arr_fake_walls[0][1], MovingObject::ROTBOT, 0))
    //                    ? "True"
    //                    : "False")
    //            << endl;

    //     OUTPUT << "IsValid (" << arr_fake_walls[0][0] << "," << arr_fake_walls[0][1] << ",Watson," << 0 << ") : "
    //            << ((map.isValid(arr_fake_walls[0][0], arr_fake_walls[0][1], MovingObject::WATSON, 0))
    //                    ? "True"
    //                    : "False")
    //            << endl;
    //     OUTPUT << "IsValid (" << arr_fake_walls[0][0] << "," << arr_fake_walls[0][1] << ",Watson," << 900 << ") : "
    //            << ((map.isValid(arr_fake_walls[0][0], arr_fake_walls[0][1], MovingObject::WATSON, 900))
    //                    ? "True"
    //                    : "False")
    //            << endl;
    // }
//     delete maps;
//     delete sherlock;
//     delete watson;
//     delete criminal;
// }

// int main(int argc, char *argv[])
// {
//     cout << "Start program assignments 1 DSA" << endl;
//     int start = 0, end = 0;
//     if (argc == 1)
//     {
//         start = 1;
//         end = 200;
//     }
//     else if (argc == 2)
//     {
//         start = stoi(argv[1]);
//         end = stoi(argv[1]);
//     }
//     else if (argc == 3)
//     {
//         start = stoi(argv[1]);
//         end = stoi(argv[2]);
//     }
//     for (int i = start; i <= end; i++)
//     {
//         // cout << i << " ";
//         string folderr = "testcase/output/output";
//         // string folderr = "testcase/expect/expect";
//         string inputFile = "testcase/input/input" + to_string(i) + ".txt";
//         string outputFile = folderr + to_string(i) + ".txt";
//         configuration(inputFile);
//         OUTPUT.open(outputFile);
//         test(inputFile);
//         OUTPUT.close();
//     }
//     comparefile(start, end);
// }

}

