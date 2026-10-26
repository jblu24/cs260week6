#include "PQ.h"
#include <iostream>

void Swap(ItemType& one, ItemType& two)
{
  ItemType temp;
  temp = one;
  one = two;
  two = temp;
}

PQ::PQ()
{
	length = 0;
}

// Post: newItem is in the queue.
void PQ::Enqueue(ItemType newItem)
{
  if (!IsFull())
  {
    length++;
    elements[length-1] = newItem;
    ReheapUp(0, length-1);
  }
}

// Post: element with highest priority has been removed 
//       from the queue; a copy is returned in item.
void PQ::Dequeue(ItemType& item)
{
  if (!IsEmpty())
  {
    item = elements[0];
    elements[0] = elements[length-1];
    length--;
    ReheapDown(0, length-1);
  }
}

// Post: Returns true if the queue is empty; 
//false, otherwise.
bool PQ::IsEmpty() const
{
  return length == 0;
}

// Post: Returns true if the queue is full; 
//false, otherwise.
bool PQ::IsFull() const
{
  return length == MAX_ITEMS;
}

void PQ::Print() const
{
	if(!IsEmpty())
	{
		std::cout << "Items";
		for(int i=0; i < length; i++)
		{
			std::cout << " -> " << elements[i];
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "No item to print!" << std::endl;
	}
}

void PQ::MakeEmpty()
{
  length = 0;
}

const ItemType *PQ::GetHeap() const
{
	return elements;
}

int PQ::GetLength()
{
	return length;
}

// Post: Heap property is restored.
void PQ::ReheapUp(int rootIndex, int newNodeIndex)
{
  int parentIndex;
  
  if (newNodeIndex > rootIndex)	
	//i.e. new node is not the root
  {
    parentIndex = (newNodeIndex-1) / 2;
    if (elements[parentIndex] < elements[newNodeIndex])
    {
      Swap(elements[parentIndex], elements[newNodeIndex]);
      ReheapUp(rootIndex, parentIndex);
    }
  }
}

// Post: Heap property is restored.
void PQ::ReheapDown(int rootIndex, int bottomNodeIndex)
{
  //bottomNodeIndex never change
  //bottomNodeIndex is always length-1

  //check which child is larger, 
  //set larger child's index to maxChildIndex
  int maxChildIndex;
  int rightChildIndex;
  int leftChildIndex;

  leftChildIndex = rootIndex * 2 + 1;
  rightChildIndex = rootIndex * 2 + 2;
  //if root is a leaf, do nothing
  //i.e. if leftChildIndex <= bottom, then root has a left child
  if (leftChildIndex <= bottomNodeIndex)
  {
	//Determine the max child because the root is always max.
    if (leftChildIndex == bottomNodeIndex)
	  //i.e. there is only 2 nodes in this (sub)tree
	  //i.e. no right child
      maxChildIndex = leftChildIndex;
    else
    {
      if (elements[leftChildIndex] <= elements[rightChildIndex])
        maxChildIndex = rightChildIndex;
      else
        maxChildIndex = leftChildIndex;
    }
    if (elements[rootIndex] < elements[maxChildIndex])
    {
      Swap(elements[rootIndex], elements[maxChildIndex]);
      ReheapDown(maxChildIndex, bottomNodeIndex);
    }
  }
}