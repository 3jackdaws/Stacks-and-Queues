//
//  main.cpp
//  StackA Array
//
//  Created by Ian Murphy on 1/29/16.
//  Copyright © 2016 Ian Murphy. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;

#include <string>

#include "StackA.h"
#include <chrono>
using timepoint = std::chrono::high_resolution_clock::time_point;

const int STACK_SIZE = 10000;

//#define _CRTDBG_MAP_ALLOC
int main(int argc, const char * argv[]) {
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    StackA<int> stack(STACK_SIZE);
    cout<<"Pushing 10000 elements"<<endl;
    timepoint start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i<STACK_SIZE; i++)
    {
        stack.Push(i);
    }
    timepoint stop = std::chrono::high_resolution_clock::now();
    double duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
    cout<<"Is empty?"<<endl;
    cout<<stack.isEmpty()<<endl;
    cout<<"Is Full?"<<endl;
    cout<<stack.isFull()<<endl;
    cout<<"Pushing 1 more element"<<endl;
    
    try
    {
        stack.Push(100);
    } catch (Exception e)
    {
        cout<<e.getMessage()<<endl;
    }

    cout<<"Popping 10000 elements"<<endl;
    
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i<STACK_SIZE; i++)
    {
        stack.Pop();
    }
    stop = std::chrono::high_resolution_clock::now();
    duration += std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count();
    cout<<"Is empty?"<<endl;
    cout<<stack.isEmpty()<<endl;
    cout<<"Is Full?"<<endl;
    cout<<stack.isFull()<<endl;
    cout<<"Popping 1 more element"<<endl;
    try
    {
        stack.Pop();
    } catch (Exception e)
    {
        cout<<e.getMessage()<<endl;
    }
    
    cout<<duration/1000<<" milliseconds required to push and pop 10000 elements"<<endl;
    cout<<"Pushing 500 elements"<<endl;
    for (int i = 0; i<500; i++)
    {
        stack.Push(i);
    }
    cout<<"Is empty?"<<endl;
    cout<<stack.isEmpty()<<endl;
    cout<<"Is Full?"<<endl;
    cout<<stack.isFull()<<endl;
    cout<<"Peeking at top of stack\nTop of stack: "<<stack.Peek()<<endl;
    cout<<"Size of stack: "<<stack.Size()<<endl;
    
    StackA<int> stack2(stack);
    stack2.Push(100);
    cout<<stack2.Size()<<endl;
    stack = stack2;
    cout<<stack.Size()<<endl;
    
    
    return 0;
}
