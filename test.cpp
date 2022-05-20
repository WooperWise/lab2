
#include <iostream>
#include <cstdlib>

#include "ArraySequence.hpp"
#include "LinkedListSequence.hpp"
#include "Sequence.hpp"


int main() {
    int primary[5] = {1, 2, 3, 4, 5};
    ArraySequence<int> test_arr(primary, 5);
    LinkedListSequence<int> test_list(primary, 5);
    LinkedListSequence<int>* test_sub_list;
    int get_ind[3] = {0, 2, 4}, get_ind_ans[3] = {1, 3, 5}, subseq_ind[2] = {1, 3};
    int ans_length = 5, arr_get_first = 1, arr_get_last = 5, 
        prepend_num = 6, append_num = 9, insert_ind = 3, insert_num = 8;
    std::cout << "Starting ArraySequenceTests.\n";
    if (test_arr.GetLength() != ans_length){
        throw std::runtime_error("getLength test failed\n");
    }
    if (test_arr.GetFirst() != arr_get_first){
        throw std::runtime_error("getFirst test failed\n");
    }
    if (test_arr.GetLast() != arr_get_last){
        throw std::runtime_error("getLast test failed\n");
    }
    if (test_arr.Get(get_ind[0]) != get_ind_ans[0]){
        throw std::runtime_error("get1 test failed\n");
    }
    if (test_arr.Get(get_ind[1]) != get_ind_ans[1]){
        throw std::runtime_error("get2 test failed\n");
    }
    if (test_arr.Get(get_ind[2]) != get_ind_ans[2]){
        throw std::runtime_error("get3 test failed\n");
    }
    test_arr.Prepend(prepend_num); 
    if(test_arr.GetFirst() != prepend_num){
        throw std::runtime_error("prepend test failed\n");
    }
    test_arr.Append(append_num);
    if(test_arr.GetLast() != append_num){
        throw std::runtime_error("append test failed\n");
    }
    test_arr.InsertAt(insert_num, insert_ind);
    if(test_arr.Get(insert_ind) != insert_num){
        throw std::runtime_error("insertAt test failed\n");
    }
    std::cout << "ArraySequenceTests passed!\n";

    std::cout << "Starting LinkedListSequenceTests\n";
    if (test_list.GetLength() != ans_length){
        throw std::runtime_error("getLength test failed\n");
    }
    if (test_list.GetFirst() != arr_get_first){
        throw std::runtime_error("getFirst test failed\n");
    }
    if (test_list.GetLast() != arr_get_last){
        throw std::runtime_error("getLast test failed\n");
    }
    if (test_list.Get(get_ind[0]) != get_ind_ans[0]){
        throw std::runtime_error("get1 test failed\n");
    }
    if (test_list.Get(get_ind[1]) != get_ind_ans[1]){
        throw std::runtime_error("get2 test failed\n");
    }
    if (test_list.Get(get_ind[2]) != get_ind_ans[2]){
        throw std::runtime_error("get3 test failed\n");
    }
    test_list.Prepend(prepend_num); 
    if(test_list.GetFirst() != prepend_num){
        throw std::runtime_error("prepend test failed\n");
    }
    test_list.Append(append_num);
    if(test_list.GetLast() != append_num){
        throw std::runtime_error("append test failed\n");
    }
    test_list.InsertAt(insert_num, insert_ind);
    if(test_list.Get(insert_ind) != insert_num){
        throw std::runtime_error("insertAt test failed\n");
    }
    test_sub_list = test_list.GetSubList(1, 3);
    if(test_sub_list->Get(0) != 1) { 
        throw std::runtime_error("getSubsequence test failed\n");
    }
    if(test_sub_list->Get(1) != 2) {
        throw std::runtime_error("getSubsequence test failed\n");
    }
    if(test_sub_list->Get(2) != 8){
        throw std::runtime_error("getSubsequence test failed\n");
    }
    std::cout <<"LinkedListSequence tests passed\n";
    delete test_sub_list;
    return 0;
}