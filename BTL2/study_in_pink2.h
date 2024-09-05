#ifndef _H_STUDY_IN_PINK_2_H_
#define _H_STUDY_IN_PINK_2_H_

#include "main.h"

// Forward declaration
class MovingObject;
class Position;
// class Character;
// class Configuration;
// class Map;

// class Criminal;
// class RobotS;
// class RobotW;
// class RobotSW;
// class RobotC;

// class ArrayMovingObject;
// class StudyPinkProgram;

class BaseItem;
// class BaseBag;
// class SherlockBag;
// class WatsonBag;

int checkEXP(int exp); // hàm kiểm tra exp tối thiểu và tối đa
int checkHP(int hp); // hàm kiểm tra hp tối thiểu và tối đa

string cutstring(int n, string chuoi);
Position * getArr(string str);
int countPos (string str);
int sochudao(const int n);
int roundUp(float n);

class TestStudyInPink;

enum ItemType { MAGIC_BOOK, ENERGY_DRINK, FIRST_AID, EXCEMPTION_CARD, PASSING_CARD };
enum ElementType { PATH, WALL, FAKE_WALL };
enum RobotType { C=0, S, W, SW };
enum Person { SHERLOCk, WATSON, CRIMINAL };

class MapElement {
    friend class TestStudyInPink;
protected:
    ElementType type;
public:
    MapElement(ElementType in_type);
    virtual ~MapElement(){};
    virtual ElementType getType () const;
};

class Path : public MapElement {
    friend class TestStudyInPink;
public:
    Path();
};

class Wall : public MapElement {
    friend class TestStudyInPink;
public:
    Wall();
};

class FakeWall : public MapElement {
    friend class TestStudyInPink;
private:
    int req_exp;
public:
    FakeWall(int in_req_exp);
    int getReqExp () const;
};

class Position {
    friend class TestStudyInPink;
private:
    int r, c;
public:
    static const Position npos;
    #define npos Position(-1,-1)

    Position(int row=0, int col=0);
    Position(const string & str_pos);
    int getRow() const;
    int getCol() const;
    void setRow(int r);
    void setCol(int c);
    string str() const;
    bool isEqual(int in_r, int in_c) const;
    bool isEqual(Position pos) const;   // add function
};

class Map {
    friend class TestStudyInPink;
private:
    int num_rows, num_cols;
    MapElement ***map ;
public:
    Map(int num_rows, int num_cols, int num_walls, Position * array_walls, int num_fake_walls, Position * array_fake_walls);
    ~Map();
    int getNumRows();   // add function
    int getNumCols();   // add function
    ElementType getMapElement(int r, int c);    // add function
    bool isValid ( const Position & pos , MovingObject * mv_obj ) const;
    int distance(Position pos1, Position pos2) const;   // add function
};

class MovingObject {
    friend class TestStudyInPink;
protected:
    int index;
    Position pos;
    Map * map;
    string name;
public:
    MovingObject(int index, const Position pos, Map * map, const string & name="");
    virtual ~MovingObject(){};
    virtual Position getNextPosition() = 0;
    Position getCurrentPosition() const;
    virtual void move() = 0;
    virtual string str() const = 0;
    string getname();       // add function
    int getindex() const;   // add function
    int getRow() const;     // add function
    int getCol() const;     // add function
    void setRow(int r);     // add function
    void setCol(int c);     // add function
};

class Character : public MovingObject {
    friend class TestStudyInPink;
protected:
    Person character;
public:
    Character(int index, const Position pos, Map * map, const string & name="");
    virtual ~Character(){};
    Person getCharacter();
    virtual int getEXP() const = 0;  // add function
    virtual void setEXP(int exp) {}; // add function
    virtual int getHP() const = 0;   // add function
    virtual void setHP(int hp) {};   // add function
    virtual void move() = 0;
    virtual string str() const = 0;
    virtual Position getNextPosition() = 0;
};

class Sherlock : public Character {
    friend class TestStudyInPink;
private: 
    string moving_rule;
    int hp, exp;
    int she_step;
public:
    Sherlock(int index, const string & moving_rule, const Position & init_pos, Map * map, int init_hp, int init_exp);
    Position getNextPosition() override;
    void move() override;
    string str() const override;
    int getEXP() const;     // add function
    void setEXP (int exp);  // add function
    int getHP() const;      // add function
    void setHP (int hp);    // add function
};

class Watson : public Character {
    friend class TestStudyInPink;
private:
    string moving_rule;
    int hp, exp;
    int wat_step;
public:
    Watson(int index, const string & moving_rule, const Position & init_pos, Map * map, int init_hp, int init_exp);
    Position getNextPosition();
    void move();
    string str() const override;
    int getEXP() const;     // add function
    void setEXP(int exp);   // add function
    int getHP() const;      // add function
    void setHP(int hp);     // add function
};

class Criminal : public Character {
    friend class TestStudyInPink;
private:
    Sherlock * sherlock;
    Watson * watson;
    int cri_step;
    Position prepos; // biến lưu vị trí trước đó tên tội phạm để tạo robot
public:
    
    Criminal(int index, const Position & init_pos, Map * map, Sherlock * sherlock, Watson * watson);
    int distance(Position p);   // add function
    int getCri_step() const;    // add function
    Position getNextPosition();
    Position getPrePosition();
    int getEXP() const {return 0;}; 
    int getHP() const {return 0;}; 
    void move();
    string str() const override;
};

class ArrayMovingObject {
    friend class TestStudyInPink;
private:
    MovingObject ** arr_mv_objs;
    int count = 0;
    int capacity = 0;
public:
    ArrayMovingObject(int capacity);
    ~ArrayMovingObject();
    bool isFull() const;
    bool add(MovingObject * mv_obj);
    MovingObject * get(int index) const;
    string str() const;
    int getCapacity() const;        // add function
    int getCount() const;
};

class Configuration {
    friend class StudyPinkProgram;
    friend class TestStudyInPink;
private:
    int map_num_rows;
    int map_num_cols;
    int max_num_moving_objects;
    int num_walls;
    Position * arr_walls;
    int num_fake_walls;
    Position * arr_fake_walls;
    string sherlock_moving_rule;
    Position sherlock_init_pos;
    int sherlock_init_hp;
    int sherlock_init_exp;
    string watson_moving_rule;
    Position watson_init_pos;
    int watson_init_hp;
    int watson_init_exp;
    Position criminal_init_pos;
    int num_steps;
    string * conf = new string[20] ; 
    string * testconf = new string[20];
public:
    Configuration(const string & filepath);
    ~Configuration();
    string str() const;
};

class Robot : public MovingObject {
    friend class TestStudyInPink;
protected:
    RobotType robot_type;
    BaseItem * item;
public:
    Robot(RobotType robotype);      // add function
    Robot( int index , Position pos , Map * map );
    virtual RobotType getRobotType() const;        // add function
    BaseItem * getItem();                           // add function
    Robot * createRobot(int index,  Map * map , Sherlock * sherlock , Watson * watson , Criminal * criminal);
    virtual Position getNextPosition() override = 0;
    virtual void move() override = 0;
    virtual int getDistance() const = 0;
    virtual string str() const override = 0;
    ~Robot();
};

class RobotC : public Robot {
    friend class TestStudyInPink;
private:
    Criminal * criminal;
public:
    RobotC ( int index , const Position & init_pos , Map * map , Criminal * criminal ) ;
    int distance(Position p , Sherlock * sherlock) const;   // add function
    int distance(Position p , Watson * watson) const;       // add function
    Position getNextPosition();
    void move();
    string str() const override;
    int getDistance(Sherlock * sherlock) const;
    int getDistance() const override;
    int getDistance(Watson * watson) const;
};

class RobotS : public Robot {
    friend class TestStudyInPink;
private:
    Criminal * criminal;
    Sherlock * sherlock;
public:
    RobotS ( int index , const Position & init_pos , Map * map , Criminal * criminal , Sherlock * sherlock ) ;
    int distance(Position p) const;
    int getDistance() const override;
    Position getNextPosition();
    void move();
    string str() const override;
};

class RobotW : public Robot {
   friend class TestStudyInPink;
private:
    Criminal * criminal;
    Watson * watson;
public:
    RobotW ( int index , const Position & init_pos , Map * map , Criminal * criminal , Watson * watson ) ;
    int distance(Position p) const;
    int getDistance() const override;
    Position getNextPosition();
    void move();
    string str() const override;
};

class RobotSW : public Robot {
    friend class TestStudyInPink;
private:
    Criminal * criminal;
    Sherlock * sherlock;
    Watson * watson;
public:
    RobotSW ( int index , const Position & init_pos , Map * map , Criminal * criminal , Sherlock * sherlock , Watson * watson ) ;
    int distance(Position p) const;
    int getDistance() const override;
    Position getNextPosition();
    void move();
    string str() const override;
};

class BaseItem{
    friend class TestStudyInPink;
protected:
    ItemType itemtype;
    Position init_pos;
public:
    BaseItem(){};
    BaseItem (ItemType itemtype);
    virtual bool canUse ( Character * obj , Robot * robot = NULL ) = 0;
    virtual void use ( Character * obj , Robot * robot = NULL) = 0;
    virtual ItemType getType() const;
    virtual string str() const = 0;
};

class MagicBook : public BaseItem{
    friend class TestStudyInPink;
public:
    MagicBook();
    ~MagicBook(){
        delete this;
    }
    bool canUse ( Character * obj , Robot * robot = NULL ) override;
    void use ( Character * obj , Robot * robot = NULL) override;
    string str() const override;
};

class EnergyDrink : public BaseItem{
    friend class TestStudyInPink;
public:
    EnergyDrink();
    ~EnergyDrink(){
        delete this;
    }
    bool canUse ( Character * obj , Robot * robot = NULL ) override;
    void use ( Character * obj , Robot * robot = NULL) override;
    string str() const override;
};

class FirstAid : public BaseItem{
    friend class TestStudyInPink;
public:
    FirstAid();
    ~FirstAid(){
        delete this;
    }
    bool canUse ( Character * obj , Robot * robot = NULL ) override;
    void use ( Character * obj , Robot * robot = NULL) override;
    string str() const override;
};

class ExcemptionCard : public BaseItem{
    friend class TestStudyInPink;
public:
    ExcemptionCard();
    ~ExcemptionCard(){
        delete this;
    }
    bool canUse ( Character * obj , Robot * robot = NULL ) override;
    void use ( Character * obj , Robot * robot = NULL) override;
    string str() const override;
};

class PassingCard : public BaseItem{
    friend class TestStudyInPink;
public:
    string challenge;
    PassingCard(string challenge);
    ~PassingCard(){
        delete this;
    }
    bool canUse ( Character * obj , Robot * robot = NULL ) override;
    void use ( Character * obj , Robot * robot = NULL) override;
    string str() const override;
};

struct Item {
    BaseItem * baseitem;
    Item * next;
};

class BaseBag {
    friend class TestStudyInPink;
protected:
    Character* character;
    Item * head = NULL;
    int capacity = 0;
    int c = 0;
public:
    BaseBag(Character * character) ;
    ~BaseBag();
    ItemType findItem(bool &getfail); // Tìm món đồ có thể sử dụng được lần 2 và trả ra tên món đồ đó
    Item * getHead() const ;
    void setHead(Item * setItem) ;
    int getCount() const ;
    void setCount(int n) ;
    virtual bool insert ( BaseItem * item ) ;
    virtual BaseItem * get () ;
    virtual BaseItem * get ( ItemType itemType ) ;
    virtual string str () const ;
};

class SherlockBag : public BaseBag {
    friend class TestStudyInPink;
public:
    SherlockBag( Sherlock * sherlock);
};

class WatsonBag : public BaseBag {
    friend class TestStudyInPink;
public:
    WatsonBag( Watson * watson);
};

void exchangeCard(SherlockBag * bagsherlock , WatsonBag * bagwatson );

class StudyPinkProgram {
    friend class TestStudyInPink;
private:  //////////// chuyển về private
    // Sample attributes
    Configuration * config;
    Sherlock * sherlock;
    Watson * watson;
    Criminal * criminal;
    Map * map;
    ArrayMovingObject * arr_mv_objs;
    SherlockBag * bagSherlock;
    WatsonBag * bagWatson;
public:
    StudyPinkProgram(const string & config_file_path);
    bool isStop() const;

    void printResult() const ;
    void printStep(int si) const ;
    void run(bool verbose);
    ~StudyPinkProgram();
    // hàm chức năng
    // void addRobot( ArrayMovingObject * &arr_mv_objs , Map * map , Criminal * criminal , Sherlock * sherlock , Watson * watson);
    // void exchangeCard(SherlockBag * bagsherlock , WatsonBag * bagwatson );
    void sherlock_meet(MovingObject * mv_objs, bool &SfightR);
    void watson_meet(MovingObject * mv_objs, bool &WfightR);
    void show(); // for test
};



#endif /* _H_STUDY_IN_PINK_2_H_ */