#include "study_in_pink2.h"

int checkEXP(int exp){
       if (exp>900) return 900;
       else if(exp<0) return 0;
       else return exp;
    }

int checkHP(int hp){
    if (hp>500) return 500;
    else if(hp<0) return 0;
    else return hp;
}

int countPos (string str){
    int count = 0;
    for (int i = 0 ; i <= str.length() ; i++){
        if(str[i] == ';' || str[i] == ']') count++;
    }
    return count;
}

int sochudao(const int n){
    string x = to_string(n);
    int m = n;
    while(m>=10){
        m = 0;
        for(int i = 0 ; i <= x.length()-1 ; i++){
            m = m + int(x[i]) - '0';
        }
        x = to_string(m);   
    }
    return m;
}

int roundUp(float n){
    int m = round(n);
    if( m - n > 1e-99) return n;
    else return n+1;
}

string cutstring(int n, string chuoi){
    string temp = "";
    for (int i = n ; i <= chuoi.length()-1 ; i ++){
        temp = temp + chuoi[i];
    }
    return temp;
}

MapElement :: MapElement(ElementType in_type){
    this->type = in_type;
}

ElementType MapElement :: getType() const {
    return this->type;
} 

Path :: Path() : MapElement(PATH){}

Wall :: Wall() : MapElement(WALL){}

FakeWall :: FakeWall(int in_req_exp) : MapElement(FAKE_WALL) {
    this->req_exp = in_req_exp;
}

int FakeWall :: getReqExp () const {
    return this->req_exp;
}

Map :: Map(int num_rows , int num_cols , int num_walls , Position * array_walls , int num_fake_walls , Position * array_fake_walls ) {
    this->num_rows = num_rows;
    this->num_cols = num_cols;

    map = new MapElement ** [num_rows];
    for (int i = 0 ; i < num_rows ; i++){
        map[i] = new MapElement * [num_cols];
    }   // Tạo cấp phát động

    for (int i = 0 ; i < num_rows ; i++)
    for (int j = 0 ; j < num_cols ; j++){
        map[i][j] = new Path;
    } // Khởi tạo tất cả các phần tử ban đầu là Path

    for (int i = 0 ; i < num_walls ; i++){
        delete map[array_walls[i].getRow()][array_walls[i].getCol()];
        map[array_walls[i].getRow()][array_walls[i].getCol()] = new Wall;
    } // Khởi tạo các phần tử Wall

    for (int i = 0 ; i < num_fake_walls ; i++){
        delete map[array_fake_walls[i].getRow()][array_fake_walls[i].getCol()];
        map[array_fake_walls[i].getRow()][array_fake_walls[i].getCol()] = new FakeWall((array_fake_walls[i].getRow() * 257 + array_fake_walls[i].getCol() * 139 + 89)%900 + 1);
    } // Khởi tạo các phần tử Fakewall
}

Map :: ~Map() {
    for (int i = 0 ; i < num_rows ; i++){
        for (int j = 0 ; j < num_cols ; j++){
            delete map[i][j];  // Xóa cấp phát động của mảng hai chiều
        }
        delete[] map[i];  // Xóa cấp phát động của mảng một chiều
    }
    delete[] map; //// Xóa cấp phát động của map
}

bool Map :: isValid ( const Position & pos , MovingObject * mv_obj ) const {
    if(pos.getRow()<0 || pos.getCol()<0 || pos.getRow()>=num_rows || pos.getCol()>=num_cols) return false;
    if(map[pos.getRow()][pos.getCol()]->getType() == PATH ) return true;
    else if(map[pos.getRow()][pos.getCol()]->getType() == WALL ) return false;
    else if(map[pos.getRow()][pos.getCol()]->getType() == FAKE_WALL ) {
        FakeWall * fakewall = dynamic_cast<FakeWall*>(map[pos.getRow()][pos.getCol()]);
        if(mv_obj->getname() == "Watson") {
            Watson * watson = dynamic_cast<Watson*>(mv_obj);
            if(watson->getEXP() > fakewall->getReqExp()) return true;
            else return false;
        }
        else return true;
    }
    return false;
}

int Map :: distance(Position pos1, Position pos2) const{
    return abs(pos1.getCol() - pos2.getCol()) + abs(pos1.getRow()-pos2.getRow());
}

int Map :: getNumRows(){
    return this->num_rows;
}

int Map :: getNumCols(){
    return this->num_cols;
}

ElementType Map :: getMapElement(int r, int c){
    return map[r][c]->getType();
}

Position :: Position ( int r /*=0*/ , int c /*=0*/) {
    this->r = r;
    this->c = c;
}

Position :: Position (const string & str_pos){
    string r1 = "",c1 = "";
    int n = 1;
    while(str_pos[n] != ',') {
        r1 = r1 + str_pos[n];
        n++;
    }
    n++;
    while(str_pos[n] != ')') {
        c1 = c1 + str_pos[n];
        n++;
    }
    r = stoi(r1);
    c = stoi(c1);
}

int Position :: getRow() const{
	return this->r;
}

int Position :: getCol() const{
	return this->c;
}

void Position :: setRow(int r){
    this->r = r;
}

void Position :: setCol(int c){
    this->c = c;
}

string Position :: str() const{
    string chuoi = '(' + to_string(r) + ',' + to_string(c) + ')' ;
    return chuoi;
}

bool Position :: isEqual (int in_r , int in_c ) const{
    if((this->r == in_r) && (this->c == in_c)) return true;
    else return false;
}

bool Position :: isEqual(Position pos) const{
    if(this->r == pos.getRow() && this->c == pos.getCol()) return true;
    else return false;
}

MovingObject :: MovingObject (int index , const Position pos , Map * map , const string & name /*=""*/){
    this->index = index;
    this->pos = pos;
    this->map = map;
    this->name = name;
}

Position MovingObject :: getCurrentPosition () const {
    return this->pos;
}

string MovingObject :: getname(){
    return this->name;
}

int MovingObject :: getRow() const{
    return pos.getRow();
}
int MovingObject :: getCol() const{
    return pos.getCol();
}
void MovingObject :: setRow(int r){
    pos.setRow(r);
}
void MovingObject :: setCol(int c){
    pos.setCol(c);
}

int MovingObject :: getindex() const{
    return this->index;
}

Character :: Character(int index, const Position pos, Map * map, const string & name) : MovingObject( index , pos , map , name) {
}

Person Character :: getCharacter(){
    return this-> character;
}

Sherlock :: Sherlock(int index, const string & moving_rule, const Position & init_pos, Map * map, int init_hp, int init_exp) : Character( index , pos , map , "Sherlock") {
    this->moving_rule = moving_rule;
    this->pos = init_pos;
    this->exp = init_exp;
    this->hp = init_hp;
    this->character = SHERLOCk;
    she_step = 0;
}

Position Sherlock :: getNextPosition(){
    if (she_step==moving_rule.length()) she_step = 0;

    if (moving_rule[she_step]=='U') { if(map->isValid(Position(pos.getRow()-1,pos.getCol()),this)) return (Position(pos.getRow()-1,pos.getCol()));else return npos;}
    else if (moving_rule[she_step]=='D') { if(map->isValid(Position(pos.getRow()+1,pos.getCol()),this)) return (Position(pos.getRow()+1,pos.getCol()));else return npos;}
    else if (moving_rule[she_step]=='L') { if(map->isValid(Position(pos.getRow(),pos.getCol()-1),this)) return (Position(pos.getRow(),pos.getCol()-1));else return npos;}
    else if (moving_rule[she_step]=='R') { if(map->isValid(Position(pos.getRow(),pos.getCol()+1),this)) return (Position(pos.getRow(),pos.getCol()+1));else return npos;}
    else return npos;
}

void Sherlock :: move() {
    Position position = getNextPosition();
    if(!position.isEqual(npos)) pos = position;
    she_step++;
}

string Sherlock :: str() const {
    string s = "Sherlock[index=" + to_string(index) + ";pos=" + pos.str() + ";moving_rule=" + moving_rule +']';
    return s;
}

int Sherlock :: getEXP() const{
    return this->exp;
}

void Sherlock :: setEXP(int exp){
    this->exp = exp;
}

int Sherlock :: getHP() const{
    return this->hp;
}

void Sherlock :: setHP(int hp){
    this->hp =hp;
}

Watson :: Watson(int index, const string & moving_rule, const Position & init_pos, Map * map, int init_hp, int init_exp) : Character ( index , pos , map , "Watson") {
    this->pos = init_pos; 
    this->hp = init_hp;
    this->exp = init_exp;
    this->moving_rule = moving_rule;
    this->character = WATSON;
    wat_step = 0;
}

Position Watson :: getNextPosition(){
    if (wat_step == moving_rule.length()) wat_step = 0;
    if (moving_rule[wat_step]=='U') { if(map->isValid(Position(pos.getRow()-1,pos.getCol()),this)) return (Position(pos.getRow()-1,pos.getCol())); else return npos;}
    else if (moving_rule[wat_step]=='D') { if(map->isValid(Position(pos.getRow()+1,pos.getCol()),this)) return (Position(pos.getRow()+1,pos.getCol())); else return npos;}
    else if (moving_rule[wat_step]=='L') { if(map->isValid(Position(pos.getRow(),pos.getCol()-1),this)) return (Position(pos.getRow(),pos.getCol()-1)); else return npos;}
    else if (moving_rule[wat_step]=='R') { if(map->isValid(Position(pos.getRow(),pos.getCol()+1),this)) return (Position(pos.getRow(),pos.getCol()+1)); else return npos;}
    else return npos;
}

void Watson :: move(){
    Position position = getNextPosition();
    if(!position.isEqual(npos.getRow(),npos.getCol())) pos = position;
    wat_step++;
}
    
string Watson :: str() const{
    string s = "Watson[index=" + to_string(index) + ";pos=" + pos.str() + ";moving_rule=" + moving_rule +']';
    return s;
}

int Watson :: getEXP() const{
    return this->exp;
}

void Watson :: setEXP(int exp){
    this->exp = exp;
}

int Watson :: getHP() const{
    return this->hp;
}

void Watson :: setHP(int hp){
    this->hp = hp;
}

Criminal :: Criminal(int index, const Position & init_pos, Map * map, Sherlock * sherlock, Watson * watson) : Character( index , pos , map , "Criminal") {
    this->pos = init_pos;
    this->sherlock = sherlock;
    this->watson = watson;
    this->character = CRIMINAL;
    cri_step = 0;
    prepos = npos;
}

int Criminal :: distance(Position p){
    int dis = abs(p.getRow() - sherlock->getRow()) + abs(p.getCol() - sherlock->getCol()) + abs(p.getRow() - watson->getRow()) + abs(p.getCol() - watson->getCol());
    return dis ;
};

Position Criminal :: getNextPosition(){
    int udis,ddis,ldis,rdis;
    Position upos,dpos,lpos,rpos;
    upos = Position(pos.getRow()-1,pos.getCol()); if(map->isValid(upos,this)) udis=distance(upos); else udis=0;
    dpos = Position(pos.getRow()+1,pos.getCol()); if(map->isValid(dpos,this)) ddis=distance(dpos); else ddis=0;
    lpos = Position(pos.getRow(),pos.getCol()-1); if(map->isValid(lpos,this)) ldis=distance(lpos); else ldis=0;
    rpos = Position(pos.getRow(),pos.getCol()+1); if(map->isValid(rpos,this)) rdis=distance(rpos); else rdis=0;

    int max1,max2,max;
    if(udis >= ddis) max1 = udis;
    else max1 = ddis;
    if(ldis >= rdis) max2 = ldis;
    else max2 = rdis;
    if(max1 >= max2) max = max1;
    else max = max2;

    if (max == 0) return npos;
    if (max == udis) return upos;
    if (max == ldis) return lpos;
    if (max == ddis) return dpos;
    if (max == rdis) return rpos;
    return npos;
}

void Criminal :: move(){
    Position position = getNextPosition();
    if(!position.isEqual(npos.getRow(),npos.getCol())) {
        prepos = pos;
        pos = position;
        cri_step++;
    }
}

string Criminal :: str() const {
    string s = "Criminal[index=" + to_string(index) + ";pos=" + pos.str() + ']';
    return s;
}

int Criminal :: getCri_step() const {
    return this->cri_step;
}

Position Criminal :: getPrePosition(){
    return this->prepos;
}

ArrayMovingObject :: ArrayMovingObject(int capacity){
    this->capacity = capacity;
    arr_mv_objs = new MovingObject * [capacity] ;
}

ArrayMovingObject :: ~ArrayMovingObject() {
    for(int i=3; i < count; i++){
        delete arr_mv_objs[i];
    }
    delete[] arr_mv_objs;
}

bool ArrayMovingObject :: isFull() const {
    if (count==capacity) return true;
    else return false;
}

bool ArrayMovingObject :: add(MovingObject * mv_obj) {
    if(!isFull()) {
        arr_mv_objs[count] = mv_obj ;
        count ++;
        return true;
    }
    else return false;
}

string ArrayMovingObject :: str() const{
    string str = "ArrayMovingObject[count=" + to_string(count) + ";capacity=" + to_string(capacity) ;
    for(int i = 0 ; i < count ; i++) {
        str = str + ";" + arr_mv_objs[i]->str();
    }
    str = str +"]";
    return str;
};

MovingObject * ArrayMovingObject :: get(int index) const{
    for(int i = 0 ; i < count ; i++) {
        if(i == index) return arr_mv_objs[i];
    }
    return nullptr;
}

int ArrayMovingObject :: getCapacity() const{
    return this->capacity;
}

int ArrayMovingObject :: getCount() const{
    return this->count;
}

Position * getArr(string str) {
    int n = countPos(str);
    Position * arr = new Position [n];
    string s;

    int x = 1;
    int count = 0;
    while(x < str.length()){
        while (str[x]!=';' && str[x]!=']'){
            s = s + str[x];
            x++;
        }
        arr[count] = Position(s);
        s = "";
        count++;
        x++;
    }
    return arr;
}

Configuration :: Configuration(const string & filepath){
    ifstream inputfile(filepath);
    string * mang = new string[20];
    int count = 0;

    while(!inputfile.eof())	
        {
            getline(inputfile,mang[count]);
            count++;
        }

    string * kiemtra = new string[20];
    int j = 0;
    for (int i = 0 ; i < count ; i++){
        if(mang[i]=="") {}
        else {
            while (mang[i][j] != '='){
                kiemtra[i] = kiemtra[i] + mang[i][j];
                j++;
            }
            j = 0;
        }
    }

    for (int i = 0 ; i < count ; i++){
        if (kiemtra[i]=="MAP_NUM_ROWS") map_num_rows=stoi(cutstring(13,mang[i]));
        if (kiemtra[i]=="MAP_NUM_COLS") map_num_cols=stoi(cutstring(13,mang[i]));
        if (kiemtra[i]=="MAX_NUM_MOVING_OBJECTS") max_num_moving_objects=stoi(cutstring(23,mang[i]));
        if (kiemtra[i]=="ARRAY_WALLS") {
            string str = cutstring(12,mang[i]);
            if(str=="[]") {
                num_walls=0;
            }
            else {
                num_walls = countPos(str);
                arr_walls = getArr(str);
            }
        }
        if (kiemtra[i]=="ARRAY_FAKE_WALLS") {
            string str = cutstring(17,mang[i]);
            if(str=="[]") {
                num_fake_walls=0;
            }
            else {
                num_fake_walls = countPos(str);
                arr_fake_walls = getArr(str);
            }
        }
        if (kiemtra[i]=="SHERLOCK_MOVING_RULE") sherlock_moving_rule = cutstring(21,mang[i]);
        if (kiemtra[i]=="SHERLOCK_INIT_POS") sherlock_init_pos = Position(cutstring(18,mang[i]));
        if (kiemtra[i]=="SHERLOCK_INIT_HP") sherlock_init_hp = stoi(cutstring(17,mang[i]));
        if (kiemtra[i]=="SHERLOCK_INIT_EXP") sherlock_init_exp = stoi(cutstring(18,mang[i]));
        if (kiemtra[i]=="WATSON_MOVING_RULE") watson_moving_rule = cutstring(19,mang[i]);
        if (kiemtra[i]=="WATSON_INIT_POS") watson_init_pos = Position(cutstring(16,mang[i]));
        if (kiemtra[i]=="WATSON_INIT_HP") watson_init_hp = stoi(cutstring(15,mang[i]));
        if (kiemtra[i]=="WATSON_INIT_EXP") watson_init_exp = stoi(cutstring(16,mang[i]));
        if (kiemtra[i]=="CRIMINAL_INIT_POS") criminal_init_pos = Position(cutstring(18,mang[i]));
        if (kiemtra[i]=="NUM_STEPS") num_steps = stoi(cutstring(10,mang[i]));
    }
    delete[] kiemtra;
    delete[] mang;
    inputfile.close();
};

Configuration :: ~Configuration(){
    delete[] arr_fake_walls;
    delete[] arr_walls;
};

string Configuration :: str() const{
    string strarraywall = "";
    for(int i = 0 ; i < num_walls ; i++){
        if (i==0) strarraywall = strarraywall + arr_walls[i].str();
        else strarraywall = strarraywall + ";" + arr_walls[i].str();
    }
    string strarrayfakewall="";
    for(int i = 0 ; i < num_fake_walls ; i++){
        if (i==0) strarrayfakewall = strarrayfakewall + arr_fake_walls[i].str();
        else strarrayfakewall = strarrayfakewall + ";" + arr_fake_walls[i].str();
    }
    string s = "";
    s = s + "Configuration[\n";
    s = s + "MAP_NUM_ROWS=" + to_string(map_num_rows) + "\n";
    s = s + "MAP_NUM_COLS=" + to_string(map_num_cols) + "\n";
    s = s + "MAX_NUM_MOVING_OBJECTS=" + to_string(max_num_moving_objects) + "\n";
    s = s + "NUM_WALLS=" + to_string(num_walls) + "\n";
    s = s + "ARRAY_WALLS=[" + strarraywall + "]\n";
    s = s + "NUM_FAKE_WALLS=" + to_string(num_fake_walls) + "\n";
    s = s + "ARRAY_FAKE_WALLS=[" + strarrayfakewall + "]\n";
    s = s + "SHERLOCK_MOVING_RULE=" + sherlock_moving_rule + "\n";
    s = s + "SHERLOCK_INIT_POS=" + sherlock_init_pos.str() + "\n";
    s = s + "SHERLOCK_INIT_HP=" + to_string(sherlock_init_hp) + "\n";
    s = s + "SHERLOCK_INIT_EXP=" + to_string(sherlock_init_exp) + "\n";
    s = s + "WATSON_MOVING_RULE=" + watson_moving_rule + "\n";
    s = s + "WATSON_INIT_POS=" + watson_init_pos.str() + "\n";
    s = s + "WATSON_INIT_HP=" + to_string(watson_init_hp) + "\n";
    s = s + "WATSON_INIT_EXP=" + to_string(watson_init_exp) + "\n";
    s = s + "CRIMINAL_INIT_POS=" + criminal_init_pos.str() + "\n";
    s = s + "NUM_STEPS=" + to_string(num_steps) + "\n";
    s = s + "]";
    return s;
}

Robot :: Robot(RobotType robottype) : MovingObject(index, pos, map, name) {
    this->robot_type = robottype;
}

Robot :: Robot( int index , Position pos , Map * map ) : MovingObject(index, pos, map, "Robot"){
    int p = this->pos.getRow() * this->pos.getCol();
    int s = sochudao(p);
    if(s>=0 && s<=1) item = new MagicBook;
    else if(s>=2 && s<=3) item = new EnergyDrink;
    else if(s>=4 && s<=5) item = new FirstAid;
    else if(s>=6 && s<=7) item = new ExcemptionCard;
    else{
        int t = (pos.getRow() * 11 + pos.getCol()) % 4;
        switch (t) {
            case 0 : {PassingCard  * passingcard1 = new PassingCard("RobotS");item=passingcard1;break;}
            case 1 : {PassingCard  * passingcard2 = new PassingCard("RobotC");item=passingcard2;break;}
            case 2 : {PassingCard  * passingcard3 = new PassingCard("RobotSW");item=passingcard3;break;}
            case 3 : {PassingCard  * passingcard4 = new PassingCard("all");item=passingcard4;break;}
        }
    }
}

Robot * Robot :: createRobot(int index , Map * map, Sherlock * sherlock, Watson * watson , Criminal * criminal){
    if(criminal->getCri_step()==3) {
        RobotC * robotC = new RobotC(index,criminal->getPrePosition(),map,criminal);
        return robotC;
    }
    else if(criminal->getCri_step()%3==0){
        if(map->distance(criminal->getCurrentPosition(),sherlock->getCurrentPosition()) < map->distance(criminal->getCurrentPosition(),watson->getCurrentPosition())){
            RobotS  * robots = new RobotS(index,criminal->getPrePosition(),map,criminal,sherlock);
            return robots;
        }
        else if(map->distance(criminal->getCurrentPosition(),sherlock->getCurrentPosition()) > map->distance(criminal->getCurrentPosition(),watson->getCurrentPosition())){
            RobotW  * robotw = new RobotW(index,criminal->getPrePosition(),map,criminal,watson);
            return robotw;
        }
        else {
            RobotSW  * robotsw = new RobotSW(index,criminal->getPrePosition(),map,criminal,sherlock,watson);
            return robotsw;
        }
    }
    return NULL;
}

Robot :: ~Robot(){
    delete item;
}

RobotType Robot :: getRobotType() const{
    return robot_type;
}

BaseItem * Robot :: getItem(){
    return this->item;
}

RobotC :: RobotC ( int index , const Position & init_pos , Map * map , Criminal * criminal ) : Robot(index, init_pos, map) {
    this->pos = init_pos;
    this->criminal = criminal;
    this->robot_type = C;
    this->name = "RobotC";
}

int RobotC :: distance(Position p ,Sherlock * sherlock) const {
    return abs(p.getCol()-sherlock->getCol()) + abs(p.getRow()-sherlock->getRow());
}

int RobotC :: distance(Position p, Watson * watson) const {
    return abs(p.getCol()-watson->getCol()) + abs(p.getRow()-watson->getRow());
}

Position RobotC :: getNextPosition(){
    return criminal->getPrePosition();
}

void RobotC :: move(){
    Position position = getNextPosition();
    if(!position.isEqual(npos.getRow(),npos.getCol())) pos = position;
}

string RobotC :: str() const{
    string s = "Robot[pos=" + pos.str() + ";type=C;dist=" + "]";
    return s;
}

int RobotC :: getDistance(Sherlock * sherlock) const{
    return abs(pos.getCol()-sherlock->getCol()) + abs(pos.getRow()-sherlock->getRow());
}

int RobotC :: getDistance() const {return 0;}

int RobotC :: getDistance(Watson * watson) const{
    return abs(pos.getCol()-watson->getCol()) + abs(pos.getRow()-watson->getRow());
}

RobotS :: RobotS ( int index , const Position & init_pos , Map * map , Criminal * criminal , Sherlock * sherlock ) : Robot(index, init_pos, map) {  
    this->criminal = criminal;
    this->sherlock = sherlock;
    this->robot_type = S;
    this->name = "RobotS";
}

int RobotS :: distance(Position p) const{
    return abs(p.getCol()-sherlock->getCol()) + abs(p.getRow()-sherlock->getRow());
}

Position RobotS :: getNextPosition(){
    int udis,ddis,ldis,rdis;
    Position upos,dpos,lpos,rpos;
    upos = Position(pos.getRow()-1,pos.getCol()); if(map->isValid(upos,this)) udis=distance(upos); else udis=999;
    dpos = Position(pos.getRow()+1,pos.getCol()); if(map->isValid(dpos,this)) ddis=distance(dpos); else ddis=999;
    lpos = Position(pos.getRow(),pos.getCol()-1); if(map->isValid(lpos,this)) ldis=distance(lpos); else ldis=999;
    rpos = Position(pos.getRow(),pos.getCol()+1); if(map->isValid(rpos,this)) rdis=distance(rpos); else rdis=999;
    int min1,min2,min;
    if(udis <= ddis) min1 = udis;
    else min1 = ddis;
    if(ldis <= rdis) min2 = ldis;
    else min2 = rdis;
    if(min1 <= min2) min = min1;
    else min = min2;

    if (min == 999) return npos;
    else if (min == rdis) return rpos;
    else if (min == ddis) return dpos;
    else if (min == ldis) return lpos;
    return npos;
}

void RobotS :: move(){
    Position position = getNextPosition();
    if(!position.isEqual(npos.getRow(),npos.getCol())) pos = position;
}

string RobotS :: str() const{
    string s = "Robot[pos=" + pos.str() + ";type=S;dist=" + to_string(distance(pos)) + "]";
    return s;
}

int RobotS :: getDistance() const {
    return abs(pos.getCol()-sherlock->getCol()) + abs(pos.getRow()-sherlock->getRow());
}

RobotW :: RobotW ( int index , const Position & init_pos , Map * map , Criminal * criminal , Watson * watson ) : Robot(index, init_pos, map) {
    this->criminal = criminal;
    this->watson = watson;
    this->robot_type = W;
    this->name = "RobotW";
}

int RobotW :: distance(Position p) const{
    return abs(p.getCol()-watson->getCol()) + abs(p.getRow()-watson->getRow());
}

Position RobotW :: getNextPosition(){
    int udis,ddis,ldis,rdis;
    Position upos,dpos,lpos,rpos;
    upos = Position(pos.getRow()-1,pos.getCol()); if(map->isValid(upos,this)) udis=distance(upos); else udis=999;
    dpos = Position(pos.getRow()+1,pos.getCol()); if(map->isValid(dpos,this)) ddis=distance(dpos); else ddis=999;
    lpos = Position(pos.getRow(),pos.getCol()-1); if(map->isValid(lpos,this)) ldis=distance(lpos); else ldis=999;
    rpos = Position(pos.getRow(),pos.getCol()+1); if(map->isValid(rpos,this)) rdis=distance(rpos); else rdis=999;
    int min1,min2,min;
    if(udis <= ddis) min1 = udis;
    else min1 = ddis;
    if(ldis <= rdis) min2 = ldis;
    else min2 = rdis;
    if(min1 <= min2) min = min1;
    else min = min2;

    if (min == 999) return npos;
    if (min == udis) return upos;
    else if (min == rdis) return rpos;
    else if (min == ddis) return dpos;
    else if (min == ldis) return lpos;
    return npos;
}

void RobotW :: move(){
    Position position = getNextPosition();
    if(!position.isEqual(npos.getRow(),npos.getCol())) pos = position;
}

string RobotW :: str() const{
    string s = "Robot[pos=" + pos.str() + ";type=W;dist=" + to_string(distance(pos)) + "]";
    return s;
}

int RobotW :: getDistance() const {
    return abs(pos.getCol()-watson->getCol()) + abs(pos.getRow()-watson->getRow());
}

RobotSW :: RobotSW ( int index , const Position & init_pos , Map * map , Criminal * criminal , Sherlock * sherlock , Watson * watson ) : Robot(index, init_pos, map) {
    this->sherlock = sherlock;
    this->criminal = criminal;
    this->watson = watson;
    this->robot_type = SW;
    this->name = "RobotSW";
}

int RobotSW :: distance(Position p) const{
    return abs(p.getCol()-watson->getCol()) + abs(p.getRow()-watson->getRow()) + abs(p.getCol()-sherlock->getCol()) + abs(p.getRow()-sherlock->getRow());
}

Position RobotSW :: getNextPosition(){
    int uudis,rudis,rrdis,rddis,dddis,lddis,lldis,ludis;
    Position uupos,rupos,rrpos,rdpos,ddpos,ldpos,llpos,lupos;
    uupos = Position(pos.getRow()-2,pos.getCol());  if(map->isValid(uupos,this)) uudis=distance(uupos); else uudis=999; 
    rupos = Position(pos.getRow()-1,pos.getCol()+1);if(map->isValid(rupos,this)) rudis=distance(rupos); else rudis=999;
    rrpos = Position(pos.getRow(),pos.getCol()+2);  if(map->isValid(rrpos,this)) rrdis=distance(rrpos); else rrdis=999;
    rdpos = Position(pos.getRow()+1,pos.getCol()+1);if(map->isValid(rdpos,this)) rddis=distance(rdpos); else rddis=999;
    ddpos = Position(pos.getRow()+2,pos.getCol());  if(map->isValid(ddpos,this)) dddis=distance(ddpos); else dddis=999;
    ldpos = Position(pos.getRow()+1,pos.getCol()-1);if(map->isValid(ldpos,this)) lddis=distance(ldpos); else lddis=999;
    llpos = Position(pos.getRow(),pos.getCol()-2);  if(map->isValid(llpos,this)) lldis=distance(llpos); else lldis=999;
    lupos = Position(pos.getRow()-1,pos.getCol()-1);if(map->isValid(lupos,this)) ludis=distance(lupos); else ludis=999;

    int min1 = (uudis <= rudis) ? uudis : rudis;
    int min2 = (rrdis <= rddis) ? rrdis : rddis;
    int min3 = (dddis <= lddis) ? dddis : lddis;
    int min4 = (lldis <= ludis) ? lldis : ludis;
    int min5 = (min1 <= min2) ? min1 : min2;
    int min6 = (min3 <= min4) ? min3 : min4;
    int min = (min5 <= min6) ? min5 : min6;

    if (min == 999) return npos;
    if (min == uudis) return uupos;
    else if (min == rudis) return rupos;
    else if (min == rrdis) return rrpos;
    else if (min == rddis) return rdpos;
    else if (min == dddis) return ddpos;
    else if (min == lddis) return ldpos;
    else if (min == lldis) return llpos;
    else if (min == ludis) return lupos;
    return npos;
}

void RobotSW :: move(){
    Position position = getNextPosition();
    if(!position.isEqual(npos.getRow(),npos.getCol())) pos = position;
}

string RobotSW :: str() const{
    string s = "Robot[pos=" + pos.str() + ";type=SW;dist=" + to_string(distance(pos)) + "]";
    return s;
}
    
int RobotSW :: getDistance() const {
    return abs(pos.getCol()-sherlock->getCol()) + abs(pos.getRow()-sherlock->getRow()) + abs(pos.getCol()-watson->getCol()) + abs(pos.getRow()-watson->getRow());
}

BaseItem :: BaseItem (ItemType itemtype){
    this->itemtype =itemtype;
}

ItemType BaseItem :: getType() const{
    return this->itemtype;
}

MagicBook :: MagicBook() : BaseItem(MAGIC_BOOK){}

EnergyDrink :: EnergyDrink() : BaseItem(ENERGY_DRINK){}

FirstAid :: FirstAid() : BaseItem(FIRST_AID){}

ExcemptionCard :: ExcemptionCard() : BaseItem(EXCEMPTION_CARD){}

PassingCard :: PassingCard(string challenge) : BaseItem(PASSING_CARD){
    this->challenge = challenge;
}

bool MagicBook :: canUse ( Character * obj , Robot * robot){
    if((obj->getname() == "Sherlock" || obj->getname() == "Watson") && obj->getEXP() <= 350) return true;
    else return false;
}

void MagicBook :: use ( Character * obj , Robot * robot){
    if(canUse(obj,robot)) obj->setEXP(checkEXP(roundUp(obj->getEXP() * 125.0 / 100.0)));
}

bool EnergyDrink :: canUse ( Character * obj , Robot * robot){
    if((obj->getname() == "Sherlock" || obj->getname() == "Watson") && obj->getHP() <=100) return true;
    else return false;
}

void EnergyDrink :: use ( Character * obj , Robot * robot){
    if(canUse(obj,robot)) obj->setHP(checkHP(roundUp(obj->getHP() * 120.0 / 100.0)));
}

bool FirstAid :: canUse ( Character * obj , Robot * robot){
    if((obj->getname() == "Sherlock" || obj->getname() == "Watson") && (obj->getEXP() <= 350 || obj->getHP() <=100)) return true;
    else return false;
}

void FirstAid :: use ( Character * obj , Robot * robot){
    if(canUse(obj,robot)) obj->setHP(checkHP(roundUp(obj->getHP() * 150.0 / 100.0)));
}

bool ExcemptionCard :: canUse ( Character * obj , Robot * robot){
    if(obj->getname() == "Sherlock" && (obj->getHP() % 2 != 0)) return true;
    else return false;
}

void ExcemptionCard :: use ( Character * obj , Robot * robot){}

bool PassingCard :: canUse ( Character * obj , Robot * robot){
    if(obj->getname() == "Watson" && (obj->getHP() % 2 == 0)) return true;
    else return false;
}

void PassingCard :: use ( Character * obj , Robot * robot){
    if(challenge == "RobotS" && robot->getRobotType() == S){}
    else if(challenge == "RobotSW" && robot->getRobotType() == SW){}
    else if(challenge == "RobotC" && robot->getRobotType() == C){}
    else if(challenge == "all"){}
    else obj->setEXP(checkEXP(obj->getEXP()-50));
}

string MagicBook :: str() const {
    return "MagicBook";
}

string EnergyDrink :: str() const{
    return "EnergyDrink";
}

string FirstAid :: str() const{
    return "FirstAid";
}

string ExcemptionCard :: str() const{
    return "ExcemptionCard";
}

string PassingCard :: str() const{
    return "PassingCard";
}

BaseBag :: BaseBag(Character * character) {
    this->character = character;
}

BaseBag :: ~BaseBag() {
    while(head != nullptr){
        Item * temp = head;
        head = head->next;
        delete temp;
    }
}

Item * BaseBag :: getHead() const{
    return this->head;
}

void BaseBag :: setHead(Item * setItem){
    this->head = setItem;
}

int BaseBag :: getCount() const{
    return this->c;
}

void BaseBag :: setCount(int n) {
    this->c = n;
}

bool BaseBag :: insert ( BaseItem * item ) {
    if(c < capacity){
        Item * newItem = new Item;
        if(head == NULL) {
            newItem->baseitem = item;
            newItem->next = NULL;
            head = newItem;
            c++;
        }
        else {
            newItem->baseitem = item;
            newItem->next = head;
            head = newItem;
            c++;
        }
        return true;
    }
    else return false;
}

ItemType BaseBag :: findItem (bool &getfail) {
    Item * temp = head;
    while(temp!=NULL){
        if(temp->baseitem->canUse(character) && (temp->baseitem->getType()==MAGIC_BOOK || temp->baseitem->getType()==ENERGY_DRINK || temp->baseitem->getType()==FIRST_AID)) return temp->baseitem->getType();
        else temp = temp->next;
    }
    getfail = true;
    return MAGIC_BOOK;
}

BaseItem * BaseBag :: get () {
    if(head == NULL) return NULL;
    if(getCount() == 1 && head->baseitem->canUse(character)) {
        BaseItem * x = head->baseitem;
        delete head;
        head = NULL;
        c--;
        return x;
    }
    else if(getCount() == 1 && !head->baseitem->canUse(character)) return NULL;
    Item * count = head;     
    Item * pre;                                 // count là biến con trỏ thay đổi giá trị
    Item * a = head->next;                      // a lưu giữ thông tin của đồ vật đứng thứ 2
    while(count!=NULL){
        if(count->baseitem->canUse(character,NULL)) {
            if(count == head) break;
            if(count == head->next) {
                head->next = a->next;
                a->next = head;
                head = a;
            }
            else{
                pre->next = head;
                head->next = count->next;
                count->next = a;
                head = count;
                break;
            }
        }
        else {
            pre = count;
            count = count->next;
        } 
    }

    if(count==NULL){ return NULL; }
    else {
        BaseItem * temp = head->baseitem;
        Item * x = head;
        head = head->next;
        c--;
        delete x;
        return temp;
    }
}

BaseItem * BaseBag :: get (ItemType itemtype){
    if(head == NULL) return NULL;
    if(getCount() == 1 && head->baseitem->getType() == itemtype) {
        BaseItem * x = head->baseitem;
        delete head;
        head = NULL;
        c--;
        return x;
    }
    else if(getCount() == 1 && head->baseitem->getType() != itemtype) return NULL;
    Item * count = head;
    Item * pre;
    Item * a = head->next;
    while(count!=NULL){
        if(count->baseitem->getType() == itemtype) {
            if(count == head) break;
            else if(count == head->next) {
                head->next = a->next;
                a->next = head;
                head = a;
            }
            else {
                pre->next = head;
                head->next = count->next;
                count->next = a;
                head = count;
                break;
            }
        }
        else {
            pre = count;
            count = count->next;
        }
    } 

    if(count==NULL){ return NULL; }
    else {
        BaseItem *temp = head->baseitem;
        Item * x = head;
        head = head->next;
        c--;
        delete x;
        return temp;
    }
}

string BaseBag :: str() const{
    string s="";
    string str="";
    Item * count = head;
    while(count != NULL){
        if (count == head) s = s + count->baseitem->str();
        else s = s + "," + count->baseitem->str();
        count = count->next;
    }
    str = str + "Bag[count=" + to_string(c) + ";" + s + "]";
    return str;
}

SherlockBag :: SherlockBag( Sherlock * sherlock ) : BaseBag (character){
    character = sherlock;
    this->capacity = 13;
}

WatsonBag :: WatsonBag( Watson * watson) : BaseBag (character){
    character = watson;
    capacity = 15;
}

StudyPinkProgram :: StudyPinkProgram(const string & config_file_path) {
    config = new Configuration(config_file_path);
    arr_mv_objs = new ArrayMovingObject(config->max_num_moving_objects);

    map = new Map(config->map_num_rows,config->map_num_cols,config->num_walls,config->arr_walls,config->num_fake_walls,config->arr_fake_walls);

    sherlock = new Sherlock(1,config->sherlock_moving_rule,config->sherlock_init_pos,map,config->sherlock_init_hp,config->sherlock_init_exp);
    watson = new Watson(2,config->watson_moving_rule,config->watson_init_pos,map,config->watson_init_hp,config->watson_init_exp);
    criminal = new Criminal(0,config->criminal_init_pos, map, sherlock, watson);

    arr_mv_objs->add(criminal);
    arr_mv_objs->add(sherlock);
    arr_mv_objs->add(watson);

    bagSherlock = new SherlockBag(sherlock);
    bagWatson = new WatsonBag(watson);
}

StudyPinkProgram :: ~StudyPinkProgram(){
    delete bagWatson;
    delete bagSherlock;
    delete map;
    delete arr_mv_objs;
    delete config;
}

void StudyPinkProgram :: printResult() const {
    if (sherlock->getCurrentPosition().isEqual(Position(criminal->getCurrentPosition()).getRow(),Position(criminal->getCurrentPosition()).getCol())) {
        cout << "Sherlock caught the criminal" << endl;
    }
    else if (watson->getCurrentPosition().isEqual(Position(criminal->getCurrentPosition()).getRow(),Position(criminal->getCurrentPosition()).getCol())) {
        cout << "Watson caught the criminal" << endl;
    }
    else {
        cout << "The criminal escaped" << endl;
    }
}

void StudyPinkProgram :: printStep(int si) const {
    cout << "Step: " << setw(4) << setfill('0') << si
         << "--"
         << sherlock->str() << "--|--" << watson->str() << "--|--" << criminal->str() << endl;
}

bool StudyPinkProgram :: isStop() const{
    if(sherlock->getHP()==1 || watson->getHP()==1 || sherlock->getCurrentPosition().isEqual(criminal->getCurrentPosition()) || watson->getCurrentPosition().isEqual(criminal->getCurrentPosition())){
        return true;
    }
    else return false;
}

void exchangeCard(SherlockBag * bagsherlock , WatsonBag * bagwatson ){
    while(bagwatson->getCount()!=15){
        BaseItem * item1 = bagsherlock->get(PASSING_CARD);
        if(item1 == NULL){break;}
        else bagwatson->insert(item1);
    }
    while(bagsherlock->getCount()!=13){
        BaseItem * item2 = bagwatson->get(EXCEMPTION_CARD);
        if(item2 == NULL){break;}
        else bagsherlock->insert(item2);
    }
}

void StudyPinkProgram :: sherlock_meet(MovingObject * mv_objs, bool &SfightR){
    int n = arr_mv_objs->getCount();
    if(mv_objs==watson) {
        exchangeCard(bagSherlock,bagWatson);
    }

    if(mv_objs==criminal) {}

    if(mv_objs!=watson && mv_objs!=sherlock && mv_objs!=criminal) {
        Robot * robot = dynamic_cast<Robot*>(mv_objs);
        bool except = false;
        SfightR=true;
        bool getfail = false;

        // Sherlock sử dụng item lần đầu
        BaseItem * item1 = NULL;
        if(sherlock->getHP()%2!=0) item1 = bagSherlock->get(EXCEMPTION_CARD);
        if(item1==NULL){}
        else {
            if(item1->canUse(sherlock,robot)) {
                item1->use(sherlock,robot);
                except = true;
            }
        }

        if(robot->getRobotType()==S) {
            if(sherlock->getEXP() > 400) bagSherlock->insert(robot->getItem()); 
            else {
                if(!except) sherlock->setEXP(checkEXP(roundUp(sherlock->getEXP()*90.0/100.0)));
                else {}
            }
        }
        else if(robot->getRobotType()==W) {
            bagSherlock->insert(robot->getItem());
        }
        else if(robot->getRobotType()==SW) {
            if(sherlock->getEXP() > 300 && sherlock->getHP() > 335) bagSherlock->insert(robot->getItem());
            else {
                if(!except) {sherlock->setEXP(checkEXP(roundUp(sherlock->getEXP()*85.0/100.0)));
                sherlock->setHP(checkHP(roundUp(sherlock->getHP()*85.0/100.0)));}
            }
        }
        else if(robot->getRobotType()==C) {
            if(sherlock->getEXP()>500) {sherlock->setRow(criminal->getRow());sherlock->setCol(criminal->getCol());}
            else bagSherlock->insert(robot->getItem());
        }

        // Sử dụng item lần 2
        ItemType itemtype2 = bagSherlock->findItem(getfail);
        if(!getfail) bagSherlock->get(itemtype2)->use(sherlock);
    }
}

void StudyPinkProgram :: watson_meet(MovingObject * mv_objs , bool &WfightR){
    int n = arr_mv_objs->getCount();
    if(mv_objs==sherlock) {
        exchangeCard(bagSherlock,bagWatson);
    }

    if(mv_objs==criminal){};

    if(mv_objs!=sherlock && mv_objs!=watson && mv_objs!=criminal) {
        Robot * robot = dynamic_cast<Robot*>(mv_objs);
        bool pass = false;
        WfightR = true;
        bool getfail = false;

        // Watson sử dụng item lần đầu
        BaseItem * item1 = NULL;
        if(watson->getHP()%2==0) item1 = bagWatson->get(PASSING_CARD);
        if(item1==NULL){}
        else {
            if(item1->canUse(watson,robot)){
                item1->use(watson,robot);
                pass = true;
            }
        }

        if(!pass) {
            if(robot->getRobotType()==W) {
                if(watson->getEXP() > 350) bagWatson->insert(robot->getItem());
                else watson->setHP(checkHP(roundUp(watson->getHP()*95.0/100.0)));
            }
            else if(robot->getRobotType()==S) {return;}
            else if(robot->getRobotType()==C) {
                bagWatson->insert(robot->getItem());
                return;
            }
            else if(robot->getRobotType()==SW) {
                if(watson->getEXP() > 600 && watson->getHP() > 165) bagWatson->insert(robot->getItem());
                else {watson->setEXP(checkEXP(roundUp(watson->getEXP()*85.0/100.0)));watson->setHP(checkHP(roundUp(watson->getHP()*85.0/100.0)));}
            }
        }

        // Watson sử dụng item lần thứ hai
        ItemType itemtype2 = bagWatson->findItem(getfail);
        if(!getfail) bagWatson->get(itemtype2)->use(watson);
    }
}

void StudyPinkProgram :: run(bool verbose) {
    for (int istep = 0; istep < config->num_steps; ++istep) {
        bool addrobot = false;
        bool SfightR = false;
        bool WfightR = false;
        int a;
        cin >> a;
        for (int i = 0; i < arr_mv_objs->getCount(); ++i) {

            // Di chuyển đối tượng 
            if(arr_mv_objs->get(i)==sherlock || arr_mv_objs->get(i)==watson) {
                Character * character = dynamic_cast<Character*>(arr_mv_objs->get(i));
                if(character->getEXP()==0) {}
                else character->move();
            }
            else arr_mv_objs->get(i)->move();

            // Đối tượng gặp nhau
            if(!SfightR){
                if(arr_mv_objs->get(i)->getCurrentPosition().isEqual(sherlock->getCurrentPosition())) {
                    sherlock_meet(arr_mv_objs->get(i),SfightR);
                }
            }
            if(!WfightR){
                if(arr_mv_objs->get(i)->getCurrentPosition().isEqual(watson->getCurrentPosition())) {
                    watson_meet(arr_mv_objs->get(i),WfightR);
                }
            }

            // Kiểm tra điều kiện dừng
            if (isStop()) {
                printStep(istep);
                break;
            }
            if (verbose) {
                printStep(istep);
            }

            // Tạo robot 1 con cho 1 step
            if(!addrobot){
                Robot * robot = nullptr;
                robot = robot->createRobot(arr_mv_objs->getCount(),map,sherlock,watson,criminal);
                if(robot != NULL) {
                    arr_mv_objs->add(robot);
                }
                addrobot = true;
            }
        }
        if(isStop()) break;
        show();
    }
    printResult();
}
// for test
void StudyPinkProgram :: show(){
    ofstream outputFile;
    outputFile.open("output.txt");
    outputFile << "MAP:" << endl;
    outputFile << setw(10);
    for(int i=0 ; i < config->map_num_cols ; i++){
        outputFile << i << setw(5) << right ;
    }
    outputFile << endl;
    for(int i=0 ; i < config->map_num_rows ; i++){
        outputFile<< i << setw(5) << right;
        for(int j=0 ; j < config->map_num_cols ; j++){
            bool check = false;
            for(int k = 0 ; k < arr_mv_objs->getCount() ; k++){
                if(Position(i,j).isEqual(arr_mv_objs->get(k)->getCurrentPosition())) {
                    if(arr_mv_objs->get(k)->getname()=="Sherlock") {outputFile << "Sh" << setw(5) << right; check = true;}
                    else if(arr_mv_objs->get(k)->getname()=="Watson") {outputFile << "Wa" << setw(5) << right; check=true;}
                    else if(arr_mv_objs->get(k)->getname()=="Criminal") {outputFile << "Cr" << setw(5) << right; check=true;}
                    else if(arr_mv_objs->get(k)->getname()=="RobotC") {outputFile << "RC" << setw(5) << right; check=true;}
                    else if(arr_mv_objs->get(k)->getname()=="RobotS") {outputFile << "RS" << setw(5) << right; check=true;}
                    else if(arr_mv_objs->get(k)->getname()=="RobotW") {outputFile << "RW" << setw(5) << right; check=true;}
                    else if(arr_mv_objs->get(k)->getname()=="RobotSW") {outputFile << "SW" << setw(5) << right; check=true;}
                    break;
                }
            }
            if(check) continue;
            if(map->getMapElement(i,j)==WALL) outputFile << "W" << setw(5) << right;
            if(map->getMapElement(i,j)==FAKE_WALL) outputFile << "F" << setw(5) << right;
            if(map->getMapElement(i,j)==PATH) outputFile << "." << setw(5) << right;
        }
        outputFile << endl;
    }
    outputFile << endl;
    outputFile << "INFORMATION: " << endl;
    for(int i = 0 ; i < arr_mv_objs->getCount() ; i++){
        if(arr_mv_objs->get(i) == sherlock || arr_mv_objs->get(i) == watson) { 
            Character *character = dynamic_cast<Character*>(arr_mv_objs->get(i));
            outputFile << character->str() ;
            outputFile << "___EXP=" << character->getEXP() ;
            outputFile << ";___HP="<< character->getHP() << ";___";
            if(arr_mv_objs->get(i)==sherlock)  outputFile << bagSherlock->str() << endl;
            else if(arr_mv_objs->get(i)==watson)  outputFile << bagWatson->str() << endl;
        }
        else if(arr_mv_objs->get(i)->getindex() != 0 && arr_mv_objs->get(i)->getindex() != 1 && arr_mv_objs->get(i)->getindex() != 2){
            Robot * robot = dynamic_cast<Robot*>(arr_mv_objs->get(i));
            outputFile << arr_mv_objs->get(i)->str() ;
            outputFile << "___Item=" ;
            if(robot->getItem()->getType() == MAGIC_BOOK) outputFile <<"MAGIC_BOOK" << endl;
            if(robot->getItem()->getType() == ENERGY_DRINK) outputFile <<"ENERGY_DRINK" << endl;
            if(robot->getItem()->getType() == FIRST_AID) outputFile <<"FIRST_AID" << endl;
            if(robot->getItem()->getType() == EXCEMPTION_CARD) outputFile <<"EXCEMPTION_CARD" << endl;
            if(robot->getItem()->getType() == PASSING_CARD) {outputFile <<"PASSING_CARD";
                PassingCard * passingcard = dynamic_cast<PassingCard*>(robot->getItem());
                outputFile << ";___challenge=" << passingcard->challenge << endl;
            }
        }
        else outputFile << arr_mv_objs->get(i)->str() << endl;

    }
    outputFile.close();
}