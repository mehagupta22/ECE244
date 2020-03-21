//ECE244 Lab 3 shapes.cpp (implementation file)
//Created by Meha Gupta on 2019-10-18

#include <iostream>
#include <string>
using namespace std;

#include "shape.h"

//constructor

shape::shape(string n, string t, int x_loc, int y_loc, int x_sz, int y_sz){
    name=n;
    type=t;
    x_location=x_loc;
    y_location=y_loc;
    x_size=x_sz;
    y_size=y_sz;
}

//accessors

string shape::getType(){
    return type;
}

string shape::getName(){
    return name;
}

int shape::getXlocation(){
    return x_location;
}

int shape::getYlocation(){
    return y_location;
}

int shape::getXsize(){
    return x_size;
}

int shape::getYsize(){
    return y_size;
}

//mutators

void shape::setType(string t){
    type=t;
}

void shape::setName(string n){
    name=n;
}

void shape::setXlocation(int x_loc){
    
    x_location=x_loc;
}

void shape::setYlocation(int y_loc){
    y_location=y_loc;
}

void shape::setXsize(int x_sz){
    x_size=x_sz;
}

void shape::setYsize(int y_sz){
    y_size=y_sz;
}

void shape::setRotate(int angle){
    rotation=angle;
}

//utility methods

void shape::draw(){
    cout << name << ": " << type << " " << x_location << " "  << y_location << " "  << x_size << " " << y_size << endl; 
}