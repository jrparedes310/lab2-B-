#include <iostream>
#include "DoubleLinkedList.cpp"
using namespace std;

int main(){
    DoubleLinkedList<int> list;
    /*
    list.push_back(1);
    list.push_back(2);
    list.print();
    list.insert(3,2);
    list.insert(4,-4);
    list.insert(5,0);
    list.print();
    list.delete_by_value(4);
    list.print();
    cout<<"Pase 1"<<endl;
    list.delete_by_value(5);
    list.print();
    cout<<"Pase 2"<<endl;
    list.delete_by_position(-4);
    list.print();
    cout<<"Pase 3"<<endl;
    list.delete_by_position(15);
    list.print();
    cout<<"Pase 4"<<endl;
    */
   list.push_back(5);
   list.push_back(4);
   list.push_back(7);
   list.push_back(8);
   list.push_back(2);
   //cout<<list.maximo_recursive(list.getSize(),list.getHead())<<endl;
   //cout<<list.maximo_iterative()<<endl;
   //list.print();
   //list.recursive_print_begin_end(list.getHead());
   //list.recursive_print_end_begin(list.getHead());
   //list.iterative_print_end_begin();//funca
   //cout<<list.count_even_numbers();//funca
   list.print();
   list.sort_descendent(0, list.getSize()-1);
   cout<<"Pase e sort"<<endl;
   list.print();
   
}