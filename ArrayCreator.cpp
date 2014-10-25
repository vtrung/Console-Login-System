//
//  ArrayCreator.cpp
//  project8
//
//  Created by Ving Trung on 7/18/14.
//  Copyright (c) 2014 Ving Trung. All rights reserved.
//

#include "ArrayCreator.h"

ArrayCreator::ArrayCreator(){
    create2DArray();
    init2DArray();
}

ArrayCreator::ArrayCreator(int r, int c){
    row = r;
    column = c;
    create2DArray();
    init2DArray();
}

ArrayCreator::~ArrayCreator(){
    destroy2DArray();
}

void ArrayCreator::create2DArray(){
    stringArr = new string*[row];
    for(int i = 0; i < (row); i++){
        stringArr[i] = new string[column];
    }
}

void ArrayCreator::destroy2DArray(){
    for(int i = 0; i < (row); i++){
        delete [] stringArr[i];
        stringArr[i] = nullptr;
    };
    delete [] stringArr;
    stringArr = nullptr;
    //cout << "destroyed" << endl;
};

void ArrayCreator::init2DArray(){
    for(int i = 0; i < (row); i++){
        for(int j = 0; j < column; j++){
            stringArr[i][j] = "";
        }
    }
}