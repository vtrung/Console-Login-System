//
//  LoginSystem.cpp
//  project8
//
//  Created by Ving Trung on 7/18/14.
//  Copyright (c) 2014 Ving Trung. All rights reserved.
//

#include "LoginSystem.h"

LoginSystem::LoginSystem(){
    //Create 2D array with numLab rows and numComp columns
    labs = new string*[numLab];
    for(int i = 0; i < (numLab); i++){
        labs[i] = new string[numComp];
        for(int j = 0; j < numComp; j++){
            labs[i][j] = "";
        }
    }
}

LoginSystem::~LoginSystem(){
    //Delete dynamic 2D array
    for(int i = 0; i < (numLab); i++){
        delete [] labs[i];
        labs[i] = nullptr;
    }
    delete [] labs;
    labs = nullptr;
}

void LoginSystem::showStatus(){
    cout << "STATUS" << endl;
    cout << "Lab#" << setw(11) << "Computers" << endl;
    for(int i = 0; i < numLab; i++){
        cout << i+1 << setw(5);
        for(int j = 0; j < numComp; j++){
            cout << " " << j+1 << ":";
            if(labs[i][j].empty())
                cout << "empty" ;
            else
                cout << labs[i][j];
        }
        cout << endl;
    }
    cout << endl;
}


void LoginSystem::showMenu(){
    cout << "SELECTION MENU" << endl;
    cout << "1. LOGIN" << endl;
    cout << "2. LOGOUT" << endl;
    cout << "3. SEARCH" << endl;
    cout << "4. QUIT" << endl;
    cout << endl;
}

void LoginSystem::login(){
    string logname;
    string labnum, compnum;
    cout << "\n\nLOGIN" << endl;
    //READ LOGNAME
    do{
        cout << "Enter your 5-character ID to login: ";
        getline(cin, logname);
        if(logname.length() != 5)
            cout << "  Invalid Entry  " << endl;
    } while(logname.length() != 5);
    //READ LAB NUMBER
    do{
        cout << "Enter the Lab #: " << endl;
        getline(cin, labnum);
        if(atoi(labnum.c_str()) < 1 || atoi(labnum.c_str()) > numLab)
            cout << "  Invalid Entry  " << endl;
    } while (atoi(labnum.c_str()) < 1 || atoi(labnum.c_str()) > numLab);
    //READ COMPUTER NUMBER
    do{
        cout << "Enter the Computer #: " << endl;
        if(!(getline(cin, compnum)))
            if( atoi(compnum.c_str()) < 1 || atoi(compnum.c_str()) > numComp)
                cout << "  Invalid Entry  " << endl;
    } while (atoi(compnum.c_str()) < 1 || atoi(compnum.c_str()) > numComp);
    
    labs[atoi(labnum.c_str())-1][atoi(compnum.c_str())-1] = logname;
    cout << "\n\n";
    
}

void LoginSystem::logout(){
    string logname;
    bool found = false;
    cout << "\n\nLOGOUT" << endl;
    //READ LOG NAME
    while(!found){
    do{
        cout << "Enter your 5-character ID to logout: ";
        getline(cin, logname);
        if(logname.length() != 5)
            cout << "  Invalid Entry  " << endl;
    } while(logname.length() != 5);
    //SCAN FOR LOGNAME
    for(int i = 0; i < numLab; i++){
        for(int j = 0; j < numComp; j++){
            //IF FOUND
            if(labs[i][j] == logname){
                labs[i][j] = "";
                found = true;
                cout << "User "<< logname <<" is logged out" << endl;
                break;
            }
        }
        if(found)
            break;
    }
    if(!found){
        cout << "That user is not logged in." << endl;
    }
    //WHILE LOOP END BELOW IF FOUND
    }
    cout << endl;
}

void LoginSystem::search(){
    string logname;
    bool found = false;
    cout << "\n\nSEARCH" << endl;
    while(!found){
        do{
            cout << "Enter your 5-character ID: ";
            getline(cin, logname);
            if(logname.length() != 5)
                cout << "  Invalid Entry  " << endl;
        } while(logname.length() != 5);
        for(int i = 0; i < numLab; i++){
            for(int j = 0; j < numComp; j++){
                if(labs[i][j] == logname){
                    cout << "User " <<  logname << " is in Lab #" << i+1 << " Computer #" << j+1 << "\n\n" <<endl;
                    found = true;
                    //break out of secondloop
                    break;
                }
            }
            //break out of first loop
            if(found)
                break;
        }
        if(!found)
            cout << "User " << logname << " not found." << endl;
    }
}