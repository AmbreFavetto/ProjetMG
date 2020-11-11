#include <iostream>
#include <string.h>

using namespace std;


int * posChosen(string choice) {

    static int mrp_array[2];

	if (choice == "a1") {
        mrp_array[0] = 0;
        mrp_array[1] = 0;
    } else if (choice == "a2"){
        mrp_array[0] = 0;
        mrp_array[1] = 1;
    } else if (choice == "a3") {
        mrp_array[0] = 0;
        mrp_array[1] = 2;
    } else if (choice == "b1") {
        mrp_array[0] = 1;
        mrp_array[1] = 0;
    } else if (choice == "b2") {
        mrp_array[0] = 1;
        mrp_array[1] = 1;
    } else if (choice == "b3") {
        mrp_array[0] = 1;
        mrp_array[1] = 2;
    } else if (choice == "c1") {
        mrp_array[0] = 2;
        mrp_array[1] = 0;
    } else if (choice == "c2") {
        mrp_array[0] = 2;
        mrp_array[1] = 1;
    } else if (choice == "c3") {
        mrp_array[0] = 2;
        mrp_array[1] = 2;
    } else {
        mrp_array[1] = 9;
        mrp_array[0] = 9; //this will be used to check if the pos is invalid
	}

    return mrp_array;
}