//
//  LoginSystem.h
//  project8
//
//  Created by Ving Trung on 7/18/14.
//  Copyright (c) 2014 Ving Trung. All rights reserved.
//

#ifndef __project8__LoginSystem__
#define __project8__LoginSystem__

#include <iostream>
#include <iomanip>

using namespace std;

class LoginSystem {
    // 2D array holding Lab#s and corresponding Computer#s!
    string** labs;
    int numLab = 4;
    int numComp = 10;
    
public:
    LoginSystem();
    ~LoginSystem();
    
    void showStatus();
    void showMenu();
    void login();
    void logout();
    void search();
};
#endif /* defined(__project8__LoginSystem__) */
