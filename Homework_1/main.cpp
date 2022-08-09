/*
 Name - Takao Oba
 UID - 205615894
 Homework 1
 */

#include "LinkedList.h"
#include <cassert>

using namespace std;

int main(){
    
     cout << "Below, we will be checking the insetToFront function:" << endl;
     LinkedList ls;
     ls.insertToFront("Hawkeye");
     ls.insertToFront("Thor");
     ls.insertToFront("Hulk");
     ls.insertToFront("Black Widow");
     ls.insertToFront("Iron Man");
     ls.insertToFront("Captain America");
     for (int k = 0; k < ls.size(); k++)
     {
         string x;
         ls.get(k, x); // returns true or false
         cout << x << endl;
     }
     cout << "Test Case Sucess!" << endl;
    
     cout << "\nBelow we will be checking if we can print the list and reverse the list:" << endl;
     LinkedList ls1;
     ls1.insertToFront("The Mandalorian");
     ls1.insertToFront("Baby Yoda");
     ls1.insertToFront("Cara Dune");
     ls1.insertToFront("Greef Karga");
     ls1.printList();
     ls1.printReverse();
     cout << "Test Case Sucess!" << endl;
     
     cout << "\nBelow we will be checking what happens to the two linked lists:" << endl;
     LinkedList e1;
     e1.insertToFront("Athos");
     e1.insertToFront("Porthos");
     e1.insertToFront("Aramis");
     LinkedList e2;
     e2.insertToFront("Robin");
     e2.insertToFront("Batman");
     e1.append(e2); // adds contents of e2 to the end of e1
     string s;
     assert(e1.size() == 5 && e1.get(3, s) && s == "Batman");
     assert(e2.size() == 2 && e2.get(1, s) && s == "Robin");
     cout << "Test Case Sucess!" << endl;
    
     cout << "\nBelow we will be checking if we can successfully reverse a list:";
     LinkedList f1;
     f1.insertToFront("Jim");
     f1.insertToFront("Oz");
     f1.insertToFront("Paul");
     f1.insertToFront("Kevin");
     f1.reverseList(); // reverses the contents of e1
     string t;
     assert(f1.size() == 4 && f1.get(0, t) && t == "Jim");
     cout << "Test Case Sucess!" << endl;
     
     cout << "\nBelow we will be checking if we can successfully swap the two functions:" << endl;
     LinkedList g1;
     g1.insertToFront("A");
     g1.insertToFront("B");
     g1.insertToFront("C");
     g1.insertToFront("D");
     LinkedList g2;
     g2.insertToFront("X");
     g2.insertToFront("Y");
     g2.insertToFront("Z");
     g1.swap(g2); // exchange contents of e1 and e2
     string u;
     assert(g1.size() == 3 && g1.get(0, u) && u == "Z");
     assert(g2.size() == 4 && g2.get(2, u) && u == "B");
     cout << "Test Case Sucess!" << endl;
    
     cout << "\nAll test cases succeeded!" << endl;
    
    return 0;
}
