const int MAX_ITEMS = 50;
typedef int ItemType;

class PQ
{
public:
	PQ();
	void MakeEmpty();
	bool IsEmpty() const;
	bool IsFull() const;
	void Enqueue(ItemType newItem);
	void Dequeue(ItemType& item);
	void Print() const;
	const ItemType *GetHeap() const;
	int GetLength();
private:
	void ReheapDown(int root, int bottom);
	void ReheapUp(int root, int bottom);
	ItemType elements[MAX_ITEMS];
	int length;
};

