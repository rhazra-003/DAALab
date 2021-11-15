#include <iostream>

using namespace std;

// Node declaration
struct Node {
   int priority;
   int val;
   struct Node *l;
};

class PriorityQueue {
private:
   // Declare a front pointer and initialize it to NULL.
   Node *front;
public:
   // Constructor
   PriorityQueue();

   // Insert in queue with priority
   void insert(int item, int priority);

   // Delete the highest priority item
   void del();

   // Display queue
   void display();
};

PriorityQueue::PriorityQueue() : front{nullptr} {}

void PriorityQueue::insert(int item, int priority) {
   Node *t, *q;
   t = new Node;
   t->val = item;
   t->priority = priority;

   if(front == nullptr || priority < front->priority) 
   {
       t->l = front;
       front = t;
   }
   else {
       q = front;
       while (q->l != nullptr && q->l->priority <= priority)
           q = q->l;
       t->l = q->l;
       q->l = t;
   }

   cout << "Item successfully inserted in queue\n";
}

void PriorityQueue::del() {
   Node *temp;
   // If queue is empty
   if (front == nullptr)
       cout << "Queue Underflow\n";
   else 
   {
       temp = front;
       cout << "Deleted item is: " << temp->val << endl;
       front = front->l;
       delete temp;
   }
}

void PriorityQueue::display() {
   Node *ptr;
   ptr = front;
   if (front == nullptr)
       cout << "Queue is empty\n";
   else 
   {
       cout << "Queue is :\n";
       cout << "    Priority   Item\n";
       while (ptr != nullptr) 
       {
           cout << "\t" << ptr->priority << "\t" << ptr->val <<
                endl;
           ptr = ptr->l;
       }
   }
}


int main() {
   int ch, index, priority;
   PriorityQueue pQueue;
   do {
       cout << "\n----------------------MENU----------------------\n";
       cout << "1.Insert\n";
       cout << "2.Delete\n";
       cout << "3.Display\n";
       cout << "4.Exit\n";
       cout << "Enter your choice: ";
       cin >> ch;
       switch (ch) {
           case 1:
               cout << "Input the item value: ";
               cin >> index;
               cout << "Enter its priority: ";
               cin >> priority;
               pQueue.insert(index, priority);
               break;
           case 2:
               pQueue.del();
               break;
           case 3:
               pQueue.display();
               break;
           case 4:
               cout << "Exiting....\n";
               break;
           default:
               cout << "Wrong choice\n";
       }
   } 
   while (ch != 4);
   
   return 0;
}