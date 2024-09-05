#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M2,
        int & E1,
        int & E2,
        int & E3
) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    }
    else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
void lamtronso(float &b){
    int term;
    term=round(b);
    if ((term-b)<0) b=term+1;
    else if((term-b)==0) b=term;
	else b=term;
}
void checkexp(float & m){
    if(m>600) m=600;
    else if(m<=0) m=0;
    else m=m;
}
void checkhp(float & m){
    if(m>666) m=666;
    else if(m<=0) m=0;
    else m=m;
}
void checkm(int & m){
    if(m>3000) m=3000;
    else if(m<=0) m=0;
    else m=m;
}
int xacdinhhangDonvi(int a) {
    while (a>10)
    {a-=10;}
    return a;
}
int tonglayhangdonvi(int n)
{
    int a=0,b;
    while(n-10>0) {
        n-=10;
        a++;
    }
    b=n;
    int s=a+b;
    while(s-10>0) {
        s-=10;
    }
    return (s);
    
}
int tonghaichuSo(int n)
{
    int a=0,b;
    while(n-10>0) {
        n-=10;
        a++;
    }
    b=n;
    int s=a+b;
    int count=0;
    while(s-10>=0) {
        s-=10;
        count++;
    };
    return (s+count);
    
}
int chinhphuongGannhat(int n){
	float soCan=sqrt(n);
    int a=round(soCan);
    int S=a*a;
    return (S);
}
int maxCheo(int i, int j, int E3) // i,j là c?t và hàng d? tìm giá tr? l?n nh?t c?a các du?ng chéo
{
    int P[10][10];
    for (int a=0;a<10;a++)
    for (int b=0;b<10;b++)
    {
    P[a][b] = ((E3*b)+(a*2))*(a-b); 
	}
	    int max=P[i][j];
        int a=i;
        int b=j;
        int c=i;
        int d=j;
        int e=i;
        int f=j;
        int g=i;
        int h=j;
    while (a<10 && b<10)
    {
        if (max<P[a][b]) max=P[a][b];
        a++;
        b++; 
    };
    while (c>=0 && d>=0)
    {
        if (max<P[c][d]) max=P[c][d];
        c--;
        d--;
    }; // tìm max du?ng chéo trái
    while (e<10 && f>=0)
    {
        if (max<P[e][f]) max=P[e][f];
        e++;
        f--;
    }; 
    while (g>=0 && h<10)
    {
        if (max<P[g][h]) max=P[g][h];
        g--;
        h++;
    }; // tìm max du?ng chéo ph?i
    return max;
}
bool kiemtraKytu(char s)
{
if (s=='0'||s=='1'||s=='2'||s=='3'||s=='4'||s=='5'||s=='6'||s=='7'||s=='8'||s=='9') return true;
else if (s=='a'||s=='b'||s=='c'||s=='d'||s=='e'||s=='f'||s=='g'||s=='h'||s=='i'||s=='j'||s=='k'||s=='l'||s=='m'||s=='n'||s=='o'||s=='p'||s=='q'||s=='r'||s=='s'||s=='t'||s=='u'||s=='v'||s=='w'||s=='x'||s=='y'||s=='z') return true;
else if (s=='A'||s=='B'||s=='C'||s=='D'||s=='E'||s=='F'||s=='G'||s=='H'||s=='I'||s=='J'||s=='K'||s=='L'||s=='M'||s=='N'||s=='O'||s=='P'||s=='Q'||s=='R'||s=='S'||s=='T'||s=='U'||s=='V'||s=='W'||s=='X'||s=='Y'||s=='Z') return true;
else if (s=='@'||s=='#'||s=='%'||s=='$'||s=='!') return true;
else return  false;
} // kiểm tra ký tự có phải ký tự được dùng trong chuỗi không
bool checkChuoi(string s){
    for (int i=0;i<s.length();i++)
    if (!kiemtraKytu(s[i])) return false;
    return true; 
}/// kiểm tra một chuỗi có ký tự đặc biệt nào khác đã cho không
bool checkkytuDacbiet(char s)
{
if (s=='@'||s=='!'||s=='#'||s=='$'||s=='%') return true;
else return  false;
} /// kiểm tra xem một char có phải ký tự đặc biệt không
bool khongcokytuDacbiet(string s)
{
    int count=0;
    for (int i=0;i<s.length();i++){
    if (checkkytuDacbiet(s[i])) count++;
    }
    if(count==0) return true;
    else  return false;
} /// kiểm tra có ký tự đặc biệt nào không
bool cokytulientiep(string s){
    for(int i=0;i<s.length()-1;i++)
    {
        if (s[i]==s[i+1]) return true;
    }
    return false;
} /// tìm xem có hai ký tự liên tiếp không
bool chuase(string se, string s)
{
    int m=s.find(se);
    if  (m==-1) return false;
    else return true;
}
bool dacbietduynhat(string s){
    int count=0;
    for (int i=0;i<s.length();i++){
    if (checkkytuDacbiet(s[i])) count++;
    }
    if(count==1) return true;
    else  return false;
}
int dokytu(string s){
    int a;
    for  (int i=0;i<s.length();i++)
    if(!kiemtraKytu(s[i])) {
	a=i;
	break;}
    return a;
}/// kiểm tra ký tự không thỏa mãn ở vị trí nào
// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    if(E1<0 || E1>99) return -99;
    float exp1=EXP1; checkexp(exp1);
    float exp2=EXP2; checkexp(exp2);
    if(E1>=0 && E1<=3){
        if(E1==0) {exp2=exp2+29;checkexp(exp2);}
        else if(E1==1) {exp2=exp2+45;checkexp(exp2);}
        else if(E1==2) {exp2=exp2+75;checkexp(exp2);}
        else {exp2=exp2+149;checkexp(exp2);}
        int D=E1*3+exp1*7;
        if(D%2==0) {exp1=exp1 + D/200.00; lamtronso(exp1);checkexp(exp1);}
        else {exp1=exp1-D/100.00; lamtronso(exp1);checkexp(exp1);}

        }
    else {
        if((E1-4)*(E1-19)<=0) {exp2=exp2+E1/4.00+19; lamtronso(exp2);checkexp(exp2);}
        else if((E1-20)*(E1-49)<=0) {exp2=exp2+E1/9.00+21; lamtronso(exp2);checkexp(exp2);}
        else if((E1-50)*(E1-65)<=0) {exp2=exp2+E1/16.00+17; lamtronso(exp2);checkexp(exp2);}
        else if((E1-66)*(E1-79)<=0) {exp2=exp2+E1/4.00+19; lamtronso(exp2);checkexp(exp2); if (exp2>200) { exp2=exp2+E1/9.00+21; lamtronso(exp2);checkexp(exp2); }}
        else{ exp2=exp2+E1/4.00+19; lamtronso(exp2);checkexp(exp2); exp2=exp2+E1/9.00+21; lamtronso(exp2);checkexp(exp2); if(exp2>400) {exp2=exp2+E1/16.00+17; lamtronso(exp2);checkexp(exp2); exp2=exp2+15.00/100.00*exp2;lamtronso(exp2);checkexp(exp2); }}
        exp1-=E1;
    }
    checkexp(exp1);
    checkexp(exp2);
    EXP1=exp1;
    EXP2=exp2;
    if (EXP1<=0) EXP1=0;
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2<0 || E2>99) return -99;
    float hp1=HP1;checkhp(hp1);
    float exp1=EXP1;checkexp(exp1);
    checkm(M1);
    float P1;
    int S1=chinhphuongGannhat(exp1);
    if (exp1>=S1) P1=100;
    else P1=((float)exp1/S1+80.00)/123.00*100; lamtronso(P1);
    //////////Con đường 1

    int startMoney=M1;
    if(E2%2!=0) {
        for(int i=1;i<=20;i++)
        {
            if(M1==0) break;
            if(hp1<200) {hp1=hp1+30.00/100*hp1;lamtronso(hp1);checkhp(hp1); M1-=150;checkm(M1);}
            else {hp1=hp1+10.00/100*hp1;lamtronso(hp1);checkhp(hp1);M1-=70;checkm(M1);};
            if(startMoney-M1>50.00/100.00*startMoney) break; 
            // ăn uống
            if(exp1<400) {M1-=200;checkm(M1);}
            else {M1-=120;checkm(M1);};
            exp1=exp1+13.00/100.00*exp1;lamtronso(exp1);checkexp(exp1);
            if(startMoney-M1>50.00/100.00*startMoney) break;
            // Xe
            if(exp1<300) {M1-=100;checkm(M1);}
            else {M1-=120;checkm(M1);};
            exp1=exp1-10.00/100.00*exp1;lamtronso(exp1);checkexp(exp1);
            if(startMoney-M1>50.00/100.00*startMoney) break;
            // Vô gia cư
        }
        hp1=hp1-17.00/100*hp1;lamtronso(hp1);checkhp(hp1);
        exp1=exp1+17.00/100*exp1;lamtronso(exp1);checkexp(exp1);
    }
    else{
        for(int i=0;i<1;i++)
        {
            if(M1==0) break;
            if(hp1<200) {hp1=hp1+30.00/100*hp1;lamtronso(hp1);checkhp(hp1); M1-=150;checkm(M1);}
            else {hp1=hp1+10.00/100*hp1;lamtronso(hp1);checkhp(hp1);M1-=70;checkm(M1);};
            checkm(M1); if (M1==0) break;
            // ăn uống 
            if(exp1<400) {M1-=200;checkm(M1);}
            else {M1-=120;checkm(M1);};
            exp1=exp1+13.00/100.00*exp1;lamtronso(exp1);checkexp(exp1);
            checkm(M1); if (M1==0) break; 
            // Xe
            if(exp1<300) {M1-=100;checkm(M1);}
            else {M1-=120;checkm(M1);};
            exp1=exp1-10.00/100.00*exp1;lamtronso(exp1);checkexp(exp1);
            checkm(M1); if (M1==0) break;
            // Vô gia cư
        }
        hp1=hp1-17.00/100*hp1;lamtronso(hp1);checkhp(hp1);
        exp1=exp1+17.00/100*exp1;lamtronso(exp1);checkexp(exp1);
    };
    float P2;
    int S2=chinhphuongGannhat(exp1);
    if (exp1>=S2) P2=100;
    else P2=(exp1/S2+80.00)/123.00*100; lamtronso(P2);
    //////////Con đường 2
    
    int P[10]={32,47,28,79,100,50,22,83,64,11};
    int i;
    float P3;
    if(E2-10<0) {i=E2;P3=P[i];}
    else {i=tonglayhangdonvi(E2);P3=P[i];};
    // Xác định P3
    if(P1==P2 && P2==P3 && P3==100) {exp1=exp1-25.00/100*exp1;lamtronso(exp1);checkexp(exp1);}
    else {
        float Pcuoi=(P1+P2+P3)/3.00;lamtronso(Pcuoi);
        if(Pcuoi<50) {hp1=hp1-15.00/100*hp1;lamtronso(hp1);checkhp(hp1);exp1=exp1+15.00/100*exp1;lamtronso(exp1);checkexp(exp1);}
        else {hp1=hp1-10.00/100*hp1;lamtronso(hp1);checkhp(hp1);exp1=exp1+20.00/100*exp1;lamtronso(exp1);checkexp(exp1);}
    }
    HP1=hp1;
    EXP1=exp1;

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0 || E3>99) return -99;
    float hp1=HP1;checkhp(hp1);
    float exp1=EXP1;checkexp(exp1);
    float hp2=HP2;checkhp(hp2);
    float exp2=EXP2;checkexp(exp2);
    int M[10][10]={};

    int P[10][10];  // điểm của taxi
    int Pabs[10][10]; // giá trị tuyệt đối điểm taxi
    for (int i=0;i<10;i++)
    for (int j=0;j<10;j++){
    P[i][j] = ((E3*j)+(i*2))*(i-j);
    Pabs[i][j] = abs(P[i][j]);
    }

    int Sherlockpoint[10][10]; // điểm của sherlock
    int Sherlockpointabs[10][10];// giá trị tuyệt đối điểm của sherlock
    for (int i=0;i<10;i++)
    for (int j=0;j<10;j++){
    Sherlockpoint[i][j] = maxCheo(i,j,E3);
    Sherlockpointabs[i][j]=abs(Sherlockpoint[i][j]);
    }
    int a=0,b=0; // biến đếm
    for (int i=0;i<10;i++)
    for (int j=0;j<10;j++){
        if(P[i][j]>(E3*2)) a++;
        if(P[i][j]<-E3) b++;
        a=tonghaichuSo(a);
        b=tonghaichuSo(b);
    } // xác định xong điểm gặp nhau

    if(Pabs[a][b]>Sherlockpoint[a][b]) {exp1=88.00/100*exp1;lamtronso(exp1);checkexp(exp1);hp1=90.00/100*hp1;lamtronso(hp1);checkhp(hp1);exp2=88.00/100*exp2;lamtronso(exp2);checkexp(exp2);hp2=90.00/100*hp2;lamtronso(hp2);checkhp(hp2);}
    else {exp1=112.00/100*exp1;lamtronso(exp1);checkexp(exp1);hp1=110.00/100*hp1;lamtronso(hp1);checkhp(hp1);exp2=112.00/100*exp2;lamtronso(exp2);checkexp(exp2);hp2=110.00/100*hp2;lamtronso(hp2);checkhp(hp2);}
    EXP1=exp1;
    EXP2=exp2;
    HP1=hp1;
    HP2=hp2;

    if(Pabs[a][b]>Sherlockpointabs[a][b]) return (P[a][b]);
    else return (Sherlockpointabs[a][b]);
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se ;
	string ss=&*s;
	string emails=&*email;
	for (int i=0;i<emails.length();i++)
    {
        if (emails[i]=='@') {
        	break;
		}
		se=se+emails[i];
    } // tách chu?i se
	 // chu?i password là ss; 
    if((ss.length()>=8 && ss.length()<=20) && checkChuoi(ss) && (!chuase(se,ss)) && (!cokytulientiep(ss)) && (!khongcokytuDacbiet(ss)) ) return -10;
    else if (ss.length()<8) return -1;
    else if(ss.length()>20) return -2;
    else if(chuase(se,ss)) {
        int sei = ss.find(se);
        return (-(300+sei));
    }
    else if(cokytulientiep(ss)) {
        int sci;
	    for(int i=0;i<ss.length()-1;i++)
        {
            if (s[i]==s[i+1]) { sci=i; break;}
        }
        return (-(400+sci));
    } 
    else if(khongcokytuDacbiet(ss)) return -5;
    else return(dokytu(ss));
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string mang[30];
    for (int i=0; i<num_pwds;i++)
    {
        mang[i]=&*arr_pwds[i];
    }
    int demGiatri[30]={};
    for (int i=0;i<num_pwds;i++)
    {
        for (int j=0;j<=i;j++)
        {
            if (mang[i]==mang[j]) {demGiatri[j]++;break;}
        }
    }
    int maxxuathien=demGiatri[0];
    int maxdodaimang;
    string maycorrectPassword[30]={};
    int a;
    for (int i=0;i<num_pwds;i++)
    {
        if (maxxuathien<demGiatri[i]) { 
		maxxuathien=demGiatri[i];
        maxdodaimang=mang[i].length();
		}
    }
    for (int i=0;i<num_pwds;i++)
    {
        if (demGiatri[i]==maxxuathien) { 
			maycorrectPassword[i] = mang[i];
			if(maxdodaimang<maycorrectPassword[i].length()) {
			maxdodaimang=maycorrectPassword[i].length();
			}
		}
    }
    for (int i=0;i<num_pwds;i++)
    {
        if (maxdodaimang==maycorrectPassword[i].length()) { a=i; break;}
    }
    return a;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////