#pragma once
#include "DynArray.h"
#include <iostream>
template <typename Type>
class BinaryHeap :protected DynArray<Type>
{
public:
		/////////////////////////////////////////////////////////////////////////////
		// Function : enqueue
		// Parameters : v - the item to add to the heap
		// Notes : after the new item is added, this function ensures that the 
		//	smallest value in the heap is in [0]
		/////////////////////////////////////////////////////////////////////////////
		void enqueue(const Type& v);

		/////////////////////////////////////////////////////////////////////////////
		// Function : dequeue 
		// Return : the item that was located at [0]
		// Notes : after the smallest item is dequeued, this function ensures that 
		//	the smallest item is in [0]. DynArray may need to be modified to change
		//	Size's access type to protected so it can be decremented here
		/////////////////////////////////////////////////////////////////////////////
		Type dequeue();

		///////////////////////////////////////////////////////////////////////////////
		// Function : operator[]
		// Parameters : index - the index to access
		// Return : Type& - the item in the index
		// Notes: calls parent operator[]
		/////////////////////////////////////////////////////////////////////////////
		Type& operator[](int index);

		/////////////////////////////////////////////////////////////////////////////
		// Function : clear	
		// Notes : calls parent clear()
		/////////////////////////////////////////////////////////////////////////////
		void clear();

		///////////////////////////////////////////////////////////////////////////////
		// Function : size
		// Return : the number of valid items in the heap
		// Notes: calls parent size()
		/////////////////////////////////////////////////////////////////////////////
		unsigned int size();

		int getParent(int i) { return (i - 1) / 2; }
		int getChild1(int i) { return (i * 2) + 1; }
		int getChild2(int i) { return (i * 2) + 2; }
};

template<typename Type>
inline void BinaryHeap<Type>::enqueue(const Type& v)
{
	
	DynArray<Type>::append(v);
	int num = DynArray<Type>::size() - 1;

	while (num != 0)
	{
		
		int parent = getParent(num);
		if (DynArray<Type>::array[parent] > DynArray<Type>::array[num])
		{
			swap(DynArray<Type>::array[num], DynArray<Type>::array[parent]);
			num = parent;
			parent = getParent(num);
		}
		else
			break;
		
		
	}
	

}

template<typename Type>

inline Type BinaryHeap<Type>::dequeue()
{

	if (DynArray<Type>::Size != 0)
	{
		int current = 0;
		int child1 = getChild1(current);
		int child2 = getChild2(current);
		
		DynArray<Type>::array[current] = DynArray<Type>::array[DynArray<Type>::Size - 1];

		while ((unsigned)child1 < size())
		{
			if (DynArray<Type>::array[current] > DynArray<Type>::array[child1] && DynArray<Type>::array[child1] <= DynArray<Type>::array[child2])
			{
				std::swap(DynArray<Type>::array[current], DynArray<Type>::array[child1]);
				current = child1;
				child1 = getChild1(current);
				child2 = getChild2(current);
				
			}
			else if (DynArray<Type>::array[current] > DynArray<Type>::array[child2] && DynArray<Type>::array[child2] < DynArray<Type>::array[child1])
			{
				std::swap(DynArray<Type>::array[current], DynArray<Type>::array[child2]);
				current = child2;
				child1 = getChild1(current);
				child2 = getChild2(current);
			}
			else
			{
				break;
			}
		}
			
			
			


	}
	
		DynArray<Type>::Size--;
		return DynArray<Type>::array[0];
	
}

template<typename Type>
inline Type& BinaryHeap<Type>::operator[](int index)
{
	return DynArray<Type>::operator[](index);
}

template<typename Type>
inline void BinaryHeap<Type>::clear()
{
	DynArray<Type>::clear();
}

template<typename Type>
inline unsigned int BinaryHeap<Type>::size()
{
	return DynArray<Type>::size();
}




