#pragma once

#include <iostream>

using namespace std;

class Print 
{
public:
    void Hello () {
        cout<<"◣◥◣◥◤◢◤◢◣◥◣◥◤◢◣◥◣◥◤◢◤◢◣◥ \n" 
            <<"   Welcome to Lab №2   \n"
            <<"◣◥◣◥◤◢◤◥◣◥◤◢◤◢◣◥◣◥◤◢◤◢◣◥ \n";
    };

    void Info () {
        cout<<"\n"
            <<"╔══════════════════════════════╗ \n"
            <<"║   Enter i for information.   ║ \n"
            <<"╚══════════════════════════════╝ \n"
            <<"Enter: ";
    };

    void Choose () {
        cout<<"\n"
            <<"╔═══════════════════════════════╗ \n"
            <<"║    1   ==>   Dynamic array.   ║ \n"
            <<"║ ───────────────────────────── ║ \n"
            <<"║    2   ==>   Linked list.     ║ \n"
            <<"║ ───────────────────────────── ║ \n"
            <<"║    3   ==>   Exit.            ║ \n"
            <<"╚═══════════════════════════════╝ \n"
            <<"Enter: ";
    };

    void MenueArray () {
        cout<<"\n"
            <<"╔══════════════════════════════════════════════╗ \n"
            <<"║    1   ==>   Get elem by index.              ║ \n"
            <<"║ ──────────────────────────────────────────── ║ \n"
            <<"║    2   ==>   Set elem by index.              ║ \n"
            <<"║ ──────────────────────────────────────────── ║ \n"
            <<"║    3   ==>   Add an elem at the beginning.   ║\n"
            <<"║ ──────────────────────────────────────────── ║ \n"
            <<"║    4   ==>   Add an elem at the end.         ║ \n"
            <<"║ ──────────────────────────────────────────── ║ \n"
            <<"║    5   ==>   Print.                          ║ \n"
            <<"║ ──────────────────────────────────────────── ║ \n"
            <<"║    6   ==>   Back to selection.              ║ \n"
            <<"╚══════════════════════════════════════════════╝ \n";
    };

    void MenueList () {
        cout<<"\n"
            <<"╔══════════════════════════════════════════════╗ \n"
            <<"║    1   ==>   Get elem by index.              ║ \n"
            <<"║ ──────────────────────────────────────────── ║ \n"
            <<"║    2   ==>   Set elem by index.              ║ \n"
            <<"║ ──────────────────────────────────────────── ║ \n"
            <<"║    3   ==>   Add an elem at the beginning.   ║\n"
            <<"║ ──────────────────────────────────────────── ║ \n"
            <<"║    4   ==>   Add an elem at the end.         ║ \n"
            <<"║ ──────────────────────────────────────────── ║ \n"
            <<"║    5   ==>   Print.                          ║ \n"
            <<"║ ──────────────────────────────────────────── ║ \n"
            <<"║    6   ==>   Get sublist.                    ║ \n"
            <<"║ ──────────────────────────────────────────── ║ \n"
            <<"║    7   ==>   Concatinate lists.              ║ \n"
            <<"║ ──────────────────────────────────────────── ║ \n"
            <<"║    8   ==>   Back to selection.              ║ \n"
            <<"╚══════════════════════════════════════════════╝ \n";
    };
    

    void Count () {
        cout<<"\n"
            <<"╔═══════════════════════════════╗ \n"
            <<"║   Enter the count of array.   ║ \n"
            <<"╚═══════════════════════════════╝ \n"
            <<"Enter: ";
    }

    void Size () {
        cout<<"\n"
            <<"╔═════════════════════════════╗ \n"
            <<"║   Enter the size of list.   ║ \n"
            <<"╚═════════════════════════════╝ \n"
            <<"Enter: ";
    }

    void Items () {
        cout<<"\n"
            <<"╔══════════════════╗ \n"
            <<"║   Enter items.   ║ \n"
            <<"╚══════════════════╝ \n"
            <<"Enter: ";
    }

    void Index () {
        cout<<"\n"
            <<"╔══════════════════╗ \n"
            <<"║   Enter index:   ║ \n"
            <<"╚══════════════════╝ \n"
            <<"Enter: ";
    }

    void Item () {
        cout<<"\n"
            <<"╔══════════════════════════╗ \n"
            <<"║   Enter item of array.   ║ \n"
            <<"╚══════════════════════════╝ \n"
            <<"Enter: ";
    }

    void Good () {
        cout<<"\n"
            <<"╔═══════════════════╗ \n"
            <<"║   Successfully.   ║ \n"
            <<"╚═══════════════════╝ \n";
    }

    void EnterNewList () {
        cout<<"\n"
            <<"╔═════════════════════╗ \n"
            <<"║   Enter new list.   ║ \n"
            <<"╚═════════════════════╝ \n";
    }
};