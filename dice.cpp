#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
using namespace std;

int num,md,rn,r1,r2,r3,lc;
int nroll=0;
int troll=0;
int roll=-1;
string input ;
bool run=true;



void start(){
    system("clear");
    cout<<"==========================================================="<<endl<<"### Dice player"<<endl<<endl;
    cout<<"# modes: 1) single_player.  2) 2_player.(under_devlopment)"<<endl<<"# enter mode number:";
    cin>>md;
    system("clear"); 
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}


void grid(){

    string row0 [6]={"_ _ _",
                        "# _ _",
                        "_ _ #",
            			"_ # _",
            			"# _ #",
            			"# # #"   
                    };

    switch (rn){
        case 1: r1=0; r2=3; r3=0; break; 
        case 2: r1=1; r2=0; r3=2; break; 
        case 3: r1=1; r2=3; r3=2; break; 
        case 4: r1=4; r2=0; r3=4; break; 
        case 5: r1=4; r2=3; r3=4; break; 
        case 6: r1=4; r2=4; r3=4; break;
    };

    cout<<endl;
    cout<<row0[r1]<<endl;
    cout<<row0[r2]<<endl;
    cout<<row0[r3]<<endl<<endl;
}

/////////////
float one=0;
float two=0;
float thr=0;
float fur=0;
float fiv=0;
float six=0;

void statcount(){ num=rn; if (num==1){ one++; }
                            else if (num==2){ two++; }
                            else if (num==3){ thr++; }
                            else if (num==4){ fur++; }
                            else if (num==5){ fiv++; }
                            else if (num==6){ six++; };
}
/////////////

void statprint(){
                cout<<endl;
                cout<<"(1)--> "<<one<<"/"<<troll<<"         "<<one/troll*100<<"%"<<endl;
                cout<<"(2)--> "<<two<<"/"<<troll<<"         "<<two/troll*100<<"%"<<endl;
                cout<<"(3)--> "<<thr<<"/"<<troll<<"         "<<thr/troll*100<<"%"<<endl;
                cout<<"(4)--> "<<fur<<"/"<<troll<<"         "<<fur/troll*100<<"%"<<endl;
                cout<<"(5)--> "<<fiv<<"/"<<troll<<"         "<<fiv/troll*100<<"%"<<endl;
                cout<<"(6)--> "<<six<<"/"<<troll<<"         "<<six/troll*100<<"%"<<endl;

} 


void inputr(){

    statprint();
    cout<<"-------------------------------------------------------";    
    cout<<endl<<"# press enter to roll the dice (or number of the times you want):";
    getline(cin,input);

    if (input==""){ input="1"; };
    
    if (input=="q" || input=="Q"){ cout<<endl<<"quiting..."<<endl; run=false; }

    else { nroll = stoi(input); };
  
    
     
    if (nroll > 0 ){
            
        for (roll = 1; roll <= nroll; roll++){
            troll++;              
            rn=rand()%6+1;                
            statcount();
            
        };
    };
}

void twoinputr(){}

void moad1(){

    system("clear");
    cout<<"==========================================================="<<endl<<"### Dice player"<<endl<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"# mode 1) single_player. "<<endl;
    cout<<"-----------------------------------------------------------";

    grid();
    
    cout<<"-----------------------------------------------------------";
    inputr();
    
}


void moad2(){ cout<<"";
            
    system("clear");
    cout<<"==========================================================="<<endl<<"### Dice player"<<endl<<endl;
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"# mode 2) Two_player. "<<endl;
    cout<<"-----------------------------------------------------------";
    cout<<"-------------------under devlopment------------------------";
    grid();
    
    cout<<"-----------------------------------------------------------";
    twoinputr(); 
            }


int main(){

srand (time(0));

start();
    if (md==1) {
                do {  moad1();  }
                while (input!="0" && run==true); 
                }

     else if (md==2) { moad2(); }

    else { cout<<" #### not avlable ! "; };

cout<<endl;
return 0;
}