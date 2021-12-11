#include"sort.hpp"
#include"search.hpp"
#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include <chrono>
using namespace std ;

void search(int arr[], int repetitions, int size,
    uint8_t is_successful, time_stat* timings)
{
    //int arrSize = sizeof(arr)/sizeof(arr[0]); 
    for (auto i = repetitions; i > 0; --i) {

        int value =
            is_successful ? abs(2 * rand() + 1) % size
            : abs(2 * rand()) % size;

        
        auto t1 = chrono::high_resolution_clock::now();
        binarySearch(arr,size,value, &timings->bin_comp_num);
        auto t2 = chrono::high_resolution_clock::now();

        auto ns_int = chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1);
        timings->etime_bin += ns_int.count() / repetitions;

       
        auto tt1 = chrono::high_resolution_clock::now();
        linearSearch(arr,size,value,&timings->linear_comp_num);
        auto tt2 = chrono::high_resolution_clock::now();

        
        auto ns_int_lin = chrono::duration_cast<std::chrono::nanoseconds>(tt2 - tt1);
        timings->etime_linear += ns_int_lin.count() / repetitions;
    }
    timings->linear_comp_num /= repetitions;
    timings->bin_comp_num /= repetitions;
}

void printArray(int a[], int n){
    for (int i = 0; i < n; i++){
    	cout << a[i] << " ";
	}
	cout << endl;
}

void group3()
 {
     int data_size = 0, elems_num = 0;
     cout << "Enter the data size:\n";
     cin >> data_size ;
     cout << "Enter the number of elements you want to print:\n";
     cin >> elems_num; 
     cout << endl;
     //vector<int> vec(data_size);
     //vec.reserve(data_size);

     int *arr ;
     arr = new int[data_size];

     for (int i = 0; i < data_size; i++) {
         arr[i] = rand() % 100000;
     }

     cout << "Before sort:" << endl;
     for (auto i = 0; i < elems_num; i++) {
         cout << arr[i] << ' ';
     }

     insertionSort(arr, data_size);    

     cout << "\n\nAfter sort:" << endl;
     for (auto i = 0; i < elems_num; i++) {
         cout << arr[i] << ' ';
     }
     cout << endl;
      delete []arr ;
     //return 0;
 }

void group1()
{
    auto data_size = 0, key = 0, i = -1;
    int odd = -1 ;
    cout << "Enter the data size:\n";
    cin >> data_size;
    cout << endl;
    int* group1_arr;
    group1_arr = new int [data_size];
    for (int i = 0 ; i < data_size ; i++) {
        odd = odd + 2 ;
        group1_arr[i] = odd  ;
    }
   

    cout << "\nEnter the value you are looking for.\n" <<
        "If you want pause the program, enter negative value.\n" << std::endl;

    while (true) {
        cin >> key;
        if (key < 0) break;
        // auto pos = linear_search(vec, key);
        auto pos = linearSearch(group1_arr,data_size,key);
       
        if (pos >= 0) {
            cout << "Search finished successfully. Value " <<
                key << " found on position " << pos << ".\n";
        } else {
            cout << "Search failed. Value was not found.\n";
        }
    }
    delete [] group1_arr;
    
}

void group2()
{
    auto data_size = 0, repetitions = 0, key = 0, odd = -1;
    cout << "Enter the data size and the number of run time:\n";
    cin >> data_size >> repetitions;
    cout << std::endl;
    int* group2_arr;
    group2_arr = new int [data_size];
    for (int i = 0 ; i < data_size ; i++) {
        odd = odd + 2 ;
        group2_arr[i] = odd  ;
    }

    time_stat successful;
    search(group2_arr, repetitions,data_size, 1, &successful);
    

    time_stat unsuccessful;
    search(group2_arr, repetitions,data_size, 0, &unsuccessful);


    cout << "Linear search:\n" << string(20, '-')
         << "\nStatus: Successful\n" << "Elapsed per search: "
         << successful.etime_linear << "[ns]\n"
         << "Comparisons per search: " << successful.linear_comp_num
         << "\nSearches: " << repetitions << "\n\nStatus: Unsuccessful\n"
         << "Elapsed per search: " << unsuccessful.etime_linear << "[ns]\n"
         << "Comparisons per search: " << unsuccessful.linear_comp_num
         << "\nSearches: " << repetitions << "\n\n\n";

    cout<< "Iterative binary search:\n" << std::string(30, '-')
        << "\nStatus: Successful\n" << "Elapsed per search: "
        << successful.etime_bin << "[ns]\n"
        << "Comparisons per search: " << successful.bin_comp_num
        << "\nSearches: " << repetitions << "\n\nStatus: Unsuccessful\n"
        << "Elapsed per search: " << unsuccessful.etime_bin << "[ns]\n"
        << "Comparisons per search: " << unsuccessful.bin_comp_num
        << "\nSearches: " << repetitions << std::endl;

    delete [] group2_arr;    
}

void group4() {
    int data_size = 0, elems_num = 0;
     cout << "Enter the data size:\n";
     cin >> data_size ;
     cout << "Enter the number of elements you want to print:\n";
     cin >> elems_num; 
     cout << endl;
     //vector<int> vec(data_size);
     //vec.reserve(data_size);

     int *arr ;
     arr = new int[data_size];

     for (int i = 0; i < data_size; i++) {
         arr[i] = rand() % 100000;
     }

     cout << "Before sort:" << endl;
     for (auto i = 0; i < elems_num; i++) {
         cout << arr[i] << ' ';
     }

     //insertionSort(arr, data_size);  
     mergeSort(arr,0,data_size);  

     cout << "\n\nAfter sort:" << endl;
     for (auto i = 0; i < elems_num; i++) {
         cout << arr[i] << ' ';
     }
     cout << endl;
      delete []arr ;
     //return 0;
}

void instructions() {
    cout << "The program can run \n"
        << "Please enter a valid command:\n"     
        << "[1] For group 1: linear search and the result output tp screen\n"
        << "[2] For group 2: linear search and binary search and output the\n" 
        << "comparison of performance\n"
        << "[3] For group 3: insertion sort\n"
        << "[4] For group 4: merge sort n*log(n)  \n"
        << "[Q]uit.\n";
}

char get_command()
{
    char command;
    bool waiting = true;
    cout << "Select command and press <Enter>:";

    while (waiting)
    {
        cin >> command;
        command = tolower(command);
        if (command == '1' || command == '2' || command == '3' ||
            command == '4' || command == 'q' )
            waiting = false;

        else
        {
            instructions();
        }
    }
    return command;
}

bool do_command(char command)
{
    double p, q;
    
    
    switch (command)
    {
    case '1':
       group1();
       break;
    case '2':
        group2();
        break;
    case '3':
        group3();
        break;
    case '4':
        group4();
        break;
    case 'q':
        cout << "Calculation finished.\n";
        return false;

    }
    

    return true;
}

int main(int argc, char* argv[]){
    instructions();
    while (do_command(get_command()));

    return 0 ;
}