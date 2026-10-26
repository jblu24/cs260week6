/*
	Program Name:	CS260 Heap Project
	Programmer:		Logan Dancer
	Date:			10/25/26
	Last Update:	10/25/26
*/

// Test driver
#include <cmath>
#include <iostream>
#include "PQ.h"

using namespace std;

// Function:		Print node(s) of a heap by level(s).
// Precondition:	N/A
// Postcondition: 	The node(s) of a heap by level(s) is printed to the console.
void PrintHeapByLevel(PQ pQueue);

// Function:		Count the number of leaf node(s) of a heap.
// Precondition:	N/A
// Postcondition: 	The number of leaf node(s) of a heap is returned.
int CountLeaf(PQ pQueue);

int main()
{
	/*
	==========================================================
	========== DO NOT CHANGE ANY CODE IN THE MAIN() ==========
	==========================================================
	*/
	PQ pQueue;
	
	//Print()
	cout << "Print node list: " << endl; pQueue.Print();
	cout << "Print nodes by level: " << endl; PrintHeapByLevel(pQueue);
	cout << "Leaf count: " << CountLeaf(pQueue) << endl;
	cout << endl;

	//Enqueue
	cout << endl;
	pQueue.Enqueue(10);
	pQueue.Enqueue(16);
	pQueue.Enqueue(7);
	pQueue.Enqueue(9);
	pQueue.Enqueue(14);
	cout << "Items added to the queue!" << endl;
	cout << endl;

	//Print()
	cout << endl;
	cout << "Print node list: " << endl; pQueue.Print();
	cout << "Print nodes by level: " << endl; PrintHeapByLevel(pQueue);
	cout << "Leaf count: " << CountLeaf(pQueue) << endl;
	cout << endl;

	//Dequeue
	cout << endl;
	ItemType item;
	pQueue.Dequeue(item);
	cout << item << " is removed from the priority queue!" << endl;
	pQueue.Dequeue(item);
	cout << item << " is removed from the priority queue!" << endl;
	pQueue.Dequeue(item);
	cout << item << " is removed from the priority queue!" << endl;
	cout << endl;

	//Print()
	cout << endl;
	cout << "Print node list: " << endl; pQueue.Print();
	cout << "Print nodes by level: " << endl; PrintHeapByLevel(pQueue);
	cout << "Leaf count: " << CountLeaf(pQueue) << endl;
	cout << endl;

	//GetLength & GetHeap
	//Print all nodes in the heap
	cout << endl;
	const int ARRAY_LENGTH = pQueue.GetLength();
	const ItemType *Q_ARRAY = pQueue.GetHeap();
	for(int i=0; i<ARRAY_LENGTH; i++)
	{
		cout << Q_ARRAY[i] << endl;
	}
	cout << endl;

	cout << "Testing complete!" << endl;	

	return 0;
}

void PrintHeapByLevel(PQ pQueue)
{
	int length = pQueue.GetLength();
	int nodesInLevel = 1;
	int start = 0;
	int end = start + nodesInLevel;
	const ItemType* heap = pQueue.GetHeap();

	while (start < length) 
	{
		int end = start + nodesInLevel;
		if (end > length)
		{
			end = length;
		}

		for (int i = start; i < end; i++)
		{
			cout << heap[i] << " ";
		}
		
		cout << endl;
		start = start + nodesInLevel;
		nodesInLevel = nodesInLevel * 2;
	}	
}



int CountLeaf(PQ pQueue)
{
	int length = pQueue.GetLength();
	int counter = 0;
	
	for (int i = 0; i < length; i++) 
	{
		if (((2 * i) + 1) >= length)
		{
			counter++;
		}
	}
	return counter;
}