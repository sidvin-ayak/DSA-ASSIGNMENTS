//To implement Priority Queue using Max Heap
#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

public:
    int insert(int value);
    int del();
    void display();
    int search(int num);
    vector<int> sort();
};

void menu() {
    cout << "1. Insert" << endl;
    cout << "2. Delete" << endl;
    cout << "3. Display" << endl;
    cout << "4. Search" <<endl;
    cout << "5. Sort" <<endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    PriorityQueue pq;
    int choice, num,result;
    vector<int> sort_res;

    do {
        menu();
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter the number: ";
            cin >> num;
            result=pq.insert(num);
            if(result==1){
                cout << "Inserted: " << num << endl;
            }
            break;
        case 2:
            result=pq.del();
            if(result==-1){
                cout << "Heap is empty!" << endl;
            }
            else{
                cout << "Deleted max: " << result << endl;
            }
            break;
        case 3:
            pq.display();
            break;
        case 4:
            cout << "Enter the number: ";
            cin >> num;
            result=pq.search(num);
            if(result==-1){
                cout<<"Element Not Found"<<endl;
            }
            else{
                cout<<"Element Found at index :"<<result<<endl;
            }
            break;
        case 5:
            sort_res=pq.sort();
            if (sort_res.empty()) {
                cout << "Empty Heap" << endl;
            }
            else{
                for(int val: sort_res){
                    cout<<val<<" ";
                }
                cout<<endl;
            }
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}

//Function To Insert 
int PriorityQueue::insert(int value) {
    heap.push_back(value);
    int i = heap.size() - 1;


    while (i != 0 && heap[i] > heap[(i - 1) / 2]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    return 1;
   
}

//Function to delete the maximum element
int PriorityQueue::del() {
    int size = heap.size();
    int dele;
    if (size == 0) {
        
        return -1;
    }
    dele=heap[0];

    heap[0] = heap[size - 1];
    heap.pop_back();
    size--;

    int i = 0;
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < size && heap[left] > heap[largest]){
            largest = left;

        } 
        if (right < size && heap[right] > heap[largest]){
             largest = right;
        }
        if (largest != i) {
            swap(heap[i], heap[largest]);
            i = largest;
        } else {
            break;
        }
    }
    return dele;
}

//Function TO search for a given element
int PriorityQueue::search(int num){
    for(int i=0;i<heap.size();i++){
        if (heap[i]==num){
            return i;
        }
    }
    return -1;

}


void PriorityQueue::display() {
    if (heap.empty()) {
        cout << "Heap is empty!" << endl;
        return;
    }

    cout << "Current Heap: ";
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}

int heap_sort(vector<int>&temp) {
    int size = temp.size();
    int dele;
    if (size == 0) {
        
        return -1;
    }
    dele=temp[0];

    temp[0] = temp[size - 1];
    temp.pop_back();
    size--;

    int i = 0;
    while (true) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < size && temp[left] > temp[largest]){
            largest = left;

        } 
        if (right < size && temp[right] > temp[largest]){
             largest = right;
        }
        if (largest != i) {
            swap(temp[i], temp[largest]);
            i = largest;
        } else {
            break;
        }
    }
    return dele;
}

//FunctO sort the elements(Max Heap-->Descending order)
vector<int> PriorityQueue::sort(){
    vector<int>res;
    vector<int> tempHeap = heap;  
    

    for(int val:tempHeap){
        res.push_back(heap_sort(tempHeap));
    }

    return res;
}