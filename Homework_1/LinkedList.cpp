#include "LinkedList.h"

using namespace std;

// default constructor
LinkedList::LinkedList(){
    head = nullptr;
    m_size = 0;
}

// copy constructor
LinkedList::LinkedList(const LinkedList& rhs){
    head = nullptr;
    // check here if copy constructor doesn't work
    this->append(rhs);
}

// Destroys all the dynamically allocated memory in the list
LinkedList::~LinkedList(){
    Node *p;
    p = head;
    while (p != nullptr) {
        Node *n = p -> next;
        delete p;
        p = n;
    }
}

// assignment operator
const LinkedList& LinkedList::operator=(const LinkedList& rhs){
    if (&rhs == this) {
        return *this;
    }
    //check to make sure the nodes are the same
    //delete if not
    if(&rhs != this){
        Node *curr = head;
        
        while(curr != nullptr){
            head = head->next;
            delete curr;
            curr = head;
        }
        
        //take the rhs list and put it into this!
        
        append(rhs);
    }
    
    
    return *this; // We need this because assignment operator
}

// inserts val at the front of the list
void LinkedList::insertToFront(const ItemType &val){
    Node *p;
    p = new Node;
    p -> value = val;
    p -> next = head;
    head = p;
    ++m_size;
}

// prints the LinkedList
void LinkedList::printList() const{
    Node *p;
    p = head;
    
    while (p != nullptr) {
        cout << p->value << " ";
        p = p->next;
    }
    cout << endl;
}

// Sets item to the value at position i in this LinkedList and return true, return false if there is no element i
bool LinkedList::get(int i, ItemType& item) const{
    Node *curr = head;
    int pos = 0;
    while (curr != nullptr) {
        if (pos == i) {
            item = curr->value;
            return true;
        }
        curr = curr -> next;
        ++pos;
    }
    return false;
}

// Reverses the LinkedList
void LinkedList::reverseList(){
    Node *p = nullptr;
    Node *curr = head;
    Node *n = nullptr;
    
    while(curr != nullptr){
        n = curr->next;
        curr->next = p;
        p = curr;
        curr = n;
    }
    head = p;
    cout << endl;
}


// Prints the LinkedList in reverse order
void LinkedList::printReverse() const{
    for(int i = m_size; i >= 0; --i){
        ItemType k;
        get(i, k);
        cout << k << " ";
    }
    cout << endl;
}

// Appends the values of other onto the end of this LinkedList
void LinkedList::append(const LinkedList &other){
    Node *curr = head;
    
    while (curr->next != nullptr){
        curr = curr->next;
    }

    Node *t = other.head;

    while(t != nullptr){
        curr->next = new Node;
        curr->next->value = t->value;
        curr = curr->next;
        t = t->next;
    }
    
    m_size += other.size();



}

// Exchange the contents of this LinkedList with the other one
void LinkedList::swap(LinkedList &other){
    
    int tempSize = other.size();
    other.m_size = this->size();
    m_size = tempSize;
    
    Node *tempHead = other.head;
    other.head = this->head;
    this->head = tempHead;
    
    
}

// Returns the number of items in the LinkedList
int LinkedList::size() const{
    return m_size;
}
