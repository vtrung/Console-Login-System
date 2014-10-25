//
//  main.cpp
//  project8
//
//  Created by Ving Trung on 7/18/14.
//  Copyright (c) 2014 Ving Trung. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include "LoginSystem.h"

using namespace std;

int main(int argc, const char * argv[])
{
    LoginSystem* logsys = new LoginSystem;
    string ans;
    do{
        logsys->showStatus();
        logsys->showMenu();
        getline(cin, ans);
        
        switch(ans[0]){
            case '1':
                logsys->login();
                break;
            case '2':
                logsys->logout();
                break;
            case '3':
                logsys->search();
                break;
            case '4':
                logsys->~LoginSystem();
                delete logsys;
                logsys = nullptr;
                break;
            default:
                cout << "Invalid Entry: Please enter 1-4\n\n";
        }
    } while(ans[0] != '4');
   
    return 0;
}

