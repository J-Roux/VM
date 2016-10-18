/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   command.h
 * Author: pavel
 *
 * Created on October 18, 2016, 4:32 PM
 */

#ifndef COMMAND_H
#define COMMAND_H
#include "config.h"

enum COMMAND
{
    START,
    END,
    
    PUSH,
    
    
    ADD,
    MUL,
    SUB,
    DIV
};

static u8 command = { START, PUSH, MUL, END};

#endif /* COMMAND_H */

