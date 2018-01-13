
#include <iostream>
#include <fstream>

#include "Pack.h"
#include "DefenceGroup.h"
#include "AttackGroup.h"
#include "WarZone.h"
#include "Sizes.h"
#include "Node.h"
#include "LinkedList.h"

using namespace std;



int main( int argv,char **argc)
{
    AttackGroup ag;          //attack packs
    DefenceGroup dg;         //defence packs
    WarZone war;            //where interactions between packs take place
    ifstream config;        //config.dat file
    ifstream offence;       //offence.dat file
    int packLen;            //one pack's length as given in 'config.dat'
    int numOfTackle;        //number of tackle packs in defence as given in 'config.dat'
    int numOfLineBack;        //number of LineBack packs in defence as given in 'config.dat'
    int numOfCornerBack;        //number of CornerBack packs in defence as given in 'config.dat'
    int timeCycles;         //number of cycles as given in 'config.dat'
    
    if (argv < 3)           //if not enough arguments given by user
    {
        cout << "ERROR: Invalid input.";
        exit(1);
    }
    
    config.open(argc[1]);       //open file config.dat
    
    if (!config.is_open())  //if file does not exist
    {
        cout << "ERROR: Invalid input.";
        exit(1);
    }
    
    config >> packLen;
    config >> numOfTackle;
    config >> numOfLineBack;
    config >> numOfCornerBack;
    config >> timeCycles;
    
    
    //if statement sets defence's number of packs and pack length
    //if one or more of the arguments given in 'config.dat' is invalid, program terminates  
    try{
        if (!dg.setPackLen(packLen) || !dg.setDefenceSize(numOfTackle,numOfLineBack,numOfCornerBack) || timeCycles < Sizes::MIN_CYCLES || timeCycles > Sizes::MAX_CYCLES)
        {
            cout << "ERROR: Invalid input.";
            exit(1);
        }
    } catch (exception &e){
        cout << "ERROR: " << e.what() << endl;
    }
    
    offence.open(argc[2]); //open file 'offence.dat'
    
    ag.setPackLen(packLen);
    
    //if statement extracts information from 'offence.dat'. 
    //if data in 'offence.dat' isn't as required program terminates
    try{
        if (!ag.setPacks(offence)) 
        {
            cout << "ERROR: Invalid input.";
            exit(1);
        }
    } catch (exception &e){
        cout << "ERROR: " << e.what() << endl;
    }
    
    war.checkDefencePower(ag,dg);   //each of the defence packs in dp is checked against all other packs in ap and sets its power accordingly
    dg.orginizeGroupByPower();
    
    int i;
    for(i=0; i<timeCycles && dg.strongestPack() != packLen; i++)
    {
        dg.updatePacks();        
        war.checkDefencePower(ag,dg);
        dg.orginizeGroupByPower();
    }
    
    cout << i << endl; //number of cycles
    dg.print();
    return 0;
}
