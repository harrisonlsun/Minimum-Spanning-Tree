#pragma once

/** 
 * Implement Heap
 */

class Heap {
public:
	Heap(int numVertices);
	~Heap();
	void insert(int vertex, int distance);
	void decreaseKey(int vertex, int distance);
	int extractMin();
	bool isEmpty();
	bool contains(int v);
	void printHeap();
private:
	int numVertices;
	int* heap;
	int* position;
	int* distance;
	int heapSize;
	void minHeapify(int vertex);
	int parent(int vertex);
	int left(int vertex);
	int right(int vertex);
};

/**
 * Heap
 * @param - int numVertices - number of vertices in the graph
 * @return none
 */

Heap::Heap(int numVertices) {
	this->numVertices = numVertices;
	heap = new int[numVertices];
	position = new int[numVertices];
	distance = new int[numVertices];
	heapSize = 0;
}

/**
 * ~Heap
 * @param none
 * @return none
 */

Heap::~Heap() {
	delete[] heap;
	delete[] position;
	delete[] distance;
}

/**
 * insert
 * @param - int vertex - vertex to be inserted
 * @param - int distance - distance of the vertex
 * @return none
 *
 * This function inserts a vertex into the heap.
 */

void Heap::insert(int vertex, int distance) {
	heapSize++;
	int i = heapSize - 1;
	heap[i] = vertex;
	position[vertex] = i;
	this->distance[vertex] = distance;
	while (i != 0 && this->distance[heap[parent(i)]] > this->distance[heap[i]]) {
		std::swap(heap[i], heap[parent(i)]);
		std::swap(position[heap[i]], position[heap[parent(i)]]);
		i = parent(i);
	}
}

/**
 * decreaseKey
 * @param - int vertex - vertex to be decreased
 * @param - int distance - new distance of the vertex
 * @return none
 *
 * This function decreases the distance of a vertex.
 */

void Heap::decreaseKey(int vertex, int distance) {
	int i = position[vertex];
	this->distance[vertex] = distance;
	while (i != 0 && this->distance[heap[parent(i)]] > this->distance[heap[i]]) {
		std::swap(heap[i], heap[parent(i)]);
		std::swap(position[heap[i]], position[heap[parent(i)]]);
		i = parent(i);
	}
}

/**
 * extractMin
 * @param none
 * @return - int - vertex with the minimum distance
 *
 * This function extracts the vertex with the minimum distance.
 */

int Heap::extractMin() {
	if (heapSize <= 0) {
		return -1;
	}
	if (heapSize == 1) {
		heapSize--;
		return heap[0];
	}
	int root = heap[0];
	heap[0] = heap[heapSize - 1];
	position[heap[0]] = 0;
	heapSize--;
	minHeapify(0);
	return root;
}

/**
 * isEmpty
 * @param none
 * @return - bool - true if heap is empty, false otherwise
 *
 * This function checks if the heap is empty.
 */

bool Heap::isEmpty() {
	return heapSize == 0;
}

/**
 * contains
 * @param - int v - vertex to be checked
 * @return - bool - true if heap contains vertex, false otherwise
 *
 * This function checks if the heap contains a vertex.
 */

bool Heap::contains(int v) {
	if (position[v] < heapSize) {
		return true;
	}
	return false;
}

/**
 * printHeap
 * @param none
 * @return none
 *
 * This function prints the heap.
 */

void Heap::printHeap() {
	for (int i = 0; i < heapSize; i++) {
		std::cout << heap[i] << " ";
	}
	std::cout << std::endl;
}

/**
 * minHeapify
 * @param - int vertex - vertex to be heapified
 * @return none
 *
 * This function heapifies the heap.
 */

void Heap::minHeapify(int vertex) {
	int l = left(vertex);
	int r = right(vertex);
	int smallest = vertex;
	if (l < heapSize && distance[heap[l]] < distance[heap[vertex]]) {
		smallest = l;
	}
	if (r < heapSize && distance[heap[r]] < distance[heap[smallest]]) {
		smallest = r;
	}
	if (smallest != vertex) {
		std::swap(heap[vertex], heap[smallest]);
		std::swap(position[heap[vertex]], position[heap[smallest]]);
		minHeapify(smallest);
	}
}

/**
 * parent
 * @param - int vertex - vertex to find the parent of
 * @return - int - parent of the vertex
 *
 * This function finds the parent of a vertex.
 */

int Heap::parent(int vertex) {
	return (vertex - 1) / 2;
}

/**
 * left
 * @param - int vertex - vertex to find the left child of
 * @return - int - left child of the vertex
 *
 * This function finds the left child of a vertex.
 */

int Heap::left(int vertex) {
	return 2 * vertex + 1;
}

/**
 * right
 * @param - int vertex - vertex to find the right child of
 * @return - int - right child of the vertex
 *
 * This function finds the right child of a vertex.
 */

int Heap::right(int vertex) {
	return 2 * vertex + 2;
}

