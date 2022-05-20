#include <iostream>
#include <cstdlib>
#include <stdexcept>

#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
#include "Print.hpp"
#include "Sequence.hpp"

int main () {
    size_t exit1 = 1, exit2 = 0, count = 0, index = 0;
    int item = 0; int items[count];
    char command1 = 0, command2 = 0;
    Print p;

    p.Hello();

    while (exit1) {
        p.Choose();
        std::cin >> command1;
        exit2 = 1;
        
        switch (command1) {
        case '1':{
            p.Count(); std::cin >> count;
            p.Items();
            for (int i = 0; i < count; i++) {std::cin >> items[i];}

            ArraySequence<int> array(items, count);
            
            while (exit2) {
                p.Info();
                std::cin >> command2;

                switch (command2) {
                case 'i': {
                    p.MenueArray();
                    break;
                } case '1': {
                    p.Index(); 
                    std::cin >> index;
                    try {
                        item = array.Get(index);
                    } catch (std::runtime_error &e) {
                        puts(e.what());
                    };
                    std::cout<<item;
                    break;
                } case '2': {
                    p.Index(); std::cin >> index;
                    p.Item(); std::cin >> item;
                    try {
                        array.InsertAt(item, index);
                    } catch (std::runtime_error &e) {
                        puts(e.what());
                    }
                    break;
                } case '3': {
                    p.Item(); std::cin >> item;
                    array.Prepend(item);
                    break;
                } case '4': {
                    p.Item(); std::cin >> item;
                    array.Append(item);
                    break;
                } case '5': {
                    array.Print();
                    break;
                } case '6': {
                    exit2 = 0;
                    break;
                }}
            }
            break;
        } case '2': {
            p.Size(); std::cin >> count;
            int items_list[count]; p.Items();
            for (int i = 0; i < count; i++) {std::cin >> items[i];}

            LinkedListSequence<int> list(items, count);
            LinkedListSequence<int>* sub_list;

            while (exit2) {
            p.Info();
                std::cin >> command2;

                switch (command2) {
                case 'i': {
                    p.MenueList();
                    break;
                } case '1': {
                    p.Index(); 
                    std::cin >> index;
                    try {
                        item = list.Get(index);
                    } catch (std::runtime_error &e) {
                        puts(e.what());
                    };
                    std::cout<<item;
                    break;
                } case '2': {
                    p.Index(); std::cin >> index;
                    p.Item(); std::cin >> item;
                    try {
                        list.InsertAt(item, index);
                    } catch (std::runtime_error &e) {
                        puts(e.what());
                    }
                    break;
                } case '3': {
                    p.Item(); std::cin >> item;
                    list.Prepend(item);
                    break;
                } case '4': {
                    p.Item(); std::cin >> item;
                    list.Append(item);
                    break;
                } case '5': {
                    list.Print();
                    break;
                } case '6': {
                    size_t indexes[2]; p.Index(); std::cin >> indexes[0] >> indexes[1];
                    
                    try {
                        sub_list = list.GetSubList(indexes[0], indexes[1]);
                    } catch (std::runtime_error &e) {
                        puts(e.what());
                    }
                    sub_list->Print();
                    delete sub_list;
                    break;
                } case '7': {
                    p.EnterNewList();
                    p.Size(); std::cin >> count;
                    int items_sublist[count]; p.Items();
                    for (int i = 0; i < count; i++) {std::cin >> items[i];}
                    LinkedListSequence<int>* con_list = new LinkedListSequence<int>(items, count);
                    list.Concat(con_list);
                    delete con_list;
                    break;
                } case '8': {
                    exit2 = 0;
                    break;                    
                }}
            }
            break;
        } case '3': {
            exit1 = 0;
            break;     
        }}
    }

    return 0;
}