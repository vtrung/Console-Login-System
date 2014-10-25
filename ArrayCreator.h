//
//  ArrayCreator.h
//  project8
//
//  Created by Ving Trung on 7/18/14.
//  Copyright (c) 2014 Ving Trung. All rights reserved.
//

#ifndef __lab17__ArrayCreator__
#define __lab17__ArrayCreator__

#include <iostream>

using namespace std;

class ArrayCreator{
    int column = 20, row = 5;
    
public:
    string** stringArr = nullptr;
    
    ArrayCreator();
    ArrayCreator(int row, int column);
    ~ArrayCreator();
    
    void create2DArray();
    void destroy2DArray();
    void init2DArray();
    
};

#endif /* defined(__lab17__ArrayCreator__) */
