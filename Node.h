class Node {
private:
	//Each node contains a value (int) and a pointer to the next node
	int value;
	Node *next;
public:
	//constructor
	Node(int v);
	//getters and setters
	//For functions that are not expected to
	//alter the instance, we use const:
	void setNext(Node *n);
	Node* getNext() const;
	int getValue() const;
	virtual ~Node();
};
