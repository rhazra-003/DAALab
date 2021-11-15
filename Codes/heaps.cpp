#include <iostream>
#include <climits>

using namespace std;

// A utility function to swap two elements
void swap(int *x, int *y) {
   int temp = *x;
   *x = *y;
   *y = temp;
}

// Min Heap class
class MinHeap {
   int *hArr;    // pointer to array of elements in heap
   int capacity; // maximum possible size of min heap
   int heapSize; // Current number of elements in min heap
public:
   // Constructor: Builds a heap from a given array a[] of given size
   MinHeap(int capacity);

   // Recursive method to heapify a subtree with the root at given index
   void MinHeapify(int);

   int parent(int i) { return (i - 1) / 2; }

   int left(int i) { return (2 * i + 1); }

   int right(int i) { return (2 * i + 2); }

   // Method to remove minimum element (or root) from min heap
   int extractMin();

   // Decreases key value of key at index 'i' to newVal
   void decreaseKey(int i, int newVal);

   // Returns the minimum key (key at root) from min heap
   int getMin() { return hArr[0]; }

   // Deletes a key stored at index i
   void deleteKey(int i);

   // Inserts a new key 'k'
   void insertKey(int k);
};


MinHeap::MinHeap(int cap) {
   heapSize = 0;
   capacity = cap;
   hArr = new int[cap];
}

void MinHeap::insertKey(int k) {
   if (heapSize == capacity) {
       cout << "\nOverflow: Could not insert Key\n";
       return;
   }

   // First insert the new key at the end
   heapSize++;
   int i = heapSize - 1;
   hArr[i] = k;

   // Fix the min heap property if it is violated
   while (i != 0 && hArr[parent(i)] > hArr[i]) {
       swap(&hArr[i], &hArr[parent(i)]);
       i = parent(i);
   }

   cout << "Key successfully inserted\n";
}

void MinHeap::decreaseKey(int i, int newVal) {
   hArr[i] = newVal;
   while (i != 0 && hArr[parent(i)] > hArr[i]) {
       swap(&hArr[i], &hArr[parent(i)]);
       i = parent(i);
   }
}

int MinHeap::extractMin() {
   if (heapSize <= 0)
       return INT_MAX;
   if (heapSize == 1) {
       heapSize--;
       return hArr[0];
   }

   // Store the minimum value, and remove it from heap
   int root = hArr[0];
   hArr[0] = hArr[heapSize - 1];
   heapSize--;
   MinHeapify(0);

   return root;
}

void MinHeap::deleteKey(int i) {
   decreaseKey(i, INT_MIN);
   extractMin();
   cout << "Key successfully deleted\n";
}

void MinHeap::MinHeapify(int i) {
   int l = left(i);
   int r = right(i);
   int smallest = i;
   if (l < heapSize && hArr[l] < hArr[i])
       smallest = l;
   if (r < heapSize && hArr[r] < hArr[smallest])
       smallest = r;
   if (smallest != i) {
       swap(&hArr[i], &hArr[smallest]);
       MinHeapify(smallest);
   }
}


// Main function
int main() {
   int size{};
   cout << "Enter the size of the heap: ";
   cin >> size;
   MinHeap hp(size);

   int ch{};
   do {
       cout << "\n----------------------MENU----------------------\n";
       cout << "1. Insert key\n2. Delete key\n3. Extract minimum element from heap\n4. Get minimum element from heap\n";
       cout << "5. Decrease value at index 'i'\n6. Exit\n";
       cout << "Enter choice: ";
       cin >> ch;

       switch(ch) {
           case 1:
               int k;
               cout << "Enter key: ";
               cin >> k;
               hp.insertKey(k);
               break;
           case 2:
               cout << "Enter key: ";
               cin >> k;
               hp.deleteKey(k);
               break;
           case 3:
               cout << "Extracted minimum element from heap is: " << hp.extractMin() << endl;
               break;
           case 4:
               cout << "Minimum element in heap is: " << hp.getMin() << endl;
               break;
           case 5:
               int index;
               cout << "Enter index: ";
               cin >> index;
               cout << "Enter new value: ";
               cin >> k;
               hp.decreaseKey(index, k);
               break;
           case 6:
               cout << "Exiting....." << endl;
               break;
           default: cout << "Incorrect input!" << endl;
       }

   } while(ch != 6);
   return 0;
}