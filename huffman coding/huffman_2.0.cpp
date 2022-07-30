// C++ (STL) PROGRAM FOR HUFFMAN CODING WITH STL 
#include <bits/stdc++.h>

using namespace std;

// A huffman tree node 
struct MinHeapNode {
	// One of the input characters
	char data;
	
	//Frequency of the character 
	unsigned freq;
	
	//Left snd right child 
	MinHeapNode *left, *right;
	
	MinHeapNode(char data, unsigned freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

// For comparison of 
// two heap nodes (needed in min heap)
struct compare {
	
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{
		return (l->freq > r->freq);
	}
};


// Prints huffman codes from 
// the root of huffman tree.
void printCodes(struct MinHeapNode* root, string str)
{
	if(!root)
		return;
	
	if (root->data != '$')
		cout<< root->data << ": " << str << "\n";
		
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

// The main function that builds a huffman Tree and 
// print codes by traversing the built huffman tree

void HuffmanCodes(char data[], int freq[], int size)
{
	struct MinHeapNode *left, *right, *top;
	
	//Create a min Heap and inserts all characters of data[]
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
	
	for (int i=0; i < size; ++i)
		minHeap.push(new MinHeapNode(data[i],freq[i]));
		
	// Iterate while size of heap doesnt become 1 
	while (minHeap.size() != 1) {
		
		// Extract the two minimum 
		// freq items from min heap
		left = minHeap.top();
		minHeap.pop();
		
		right = minHeap.top();
		minHeap.pop();
		
		//Create a new internal node with 
		// frequency equal to the sum of the 
		// two nodes frequencies.Make the 
		// two extracted node as left and right children 
		// of this new node . Add this node 
		// to the minHeap '$' is a special value
		// for internal nodes , not used 
		top = new MinHeapNode('$', left->freq + right->freq);
		
		top->left = left;
		top->right = right;
		
		minHeap.push(top);
	}
	
	// Print Huffman codes using
	// the huffman  tree built above 
	printCodes(minHeap.top(), "");
}

// Driver Code 
int main()
{
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f'};
	int freq[] = { 5, 9, 12, 13, 16, 45};
	
	int size = sizeof(arr) / sizeof(arr[0]);
	
	HuffmanCodes(arr, freq, size);
	return 0;
}