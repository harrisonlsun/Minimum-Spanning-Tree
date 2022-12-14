/**
 * Author: Harrison Sun (sun.har@northeastern.edu)
 * EECE7205 - Professor Shelley Lin
 * Date: 2019-10-15
 * Homework 4
 * 
 * This program runs Prim's Algorithm using an adjacency list with binary heap for priority queue.
 */

#pragma once

#include <iostream>
#include <limits>
#include <stdio.h>
#include <vector>

/**
 * generateHeap
 * @param - int numVertices - the number of vertices in the graph
 * @param - int numEdges - the number of edges in the graph
 * @param - int maxWeight - the maximum weight of an edge in the graph
 * 
 * This function generates a random heap for a graph with numVertices vertices and numEdges edges. The maximum weight of an edge is maxWeight.
 * The heap is represented as a vector of vectors of pairs. The first elements of the pairs are the vertices they are connected to, and the second elements are the weights of the edges.
 */

std::vector<std::vector<std::pair<int, int>>> heap(int numVertices, int numEdges, int maxWeight)
{
	std::vector<std::vector<std::pair<int, int>>> heap;
	for (int i = 0; i < numVertices; i++)
	{
		std::vector<std::pair<int, int>> temp;
		heap.push_back(temp);
	}
	int numEdgesAdded = 0;
	while (numEdgesAdded < numEdges)
	{
		int i = rand() % numVertices;
		int j = rand() % numVertices;
		if (i != j)
		{
			int weight = rand() % maxWeight + 1;
			std::pair<int, int> temp1 = std::make_pair(j, weight);
			std::pair<int, int> temp2 = std::make_pair(i, weight);
			heap[i].push_back(temp1);
			heap[j].push_back(temp2);
			numEdgesAdded++;
		}
	}
	/** Print the generated heap. */
	std::cout << "The generated heap: \n";
	for (int i = 0; i < numVertices; i++)
	{
		for (int j = 0; j < heap[i].size(); j++)
		{
			std::cout << heap[i][j].first << " " << heap[i][j].second << " ";
		}
		std::cout << "\n";
	}
	return heap;
}

class PrimHeap
{
public:
	PrimHeap(int numVertices, std::vector<std::vector<std::pair<int, int>>> heap);
	~PrimHeap();
	void runPrim();
	void printMST();
private:
	int numVertices;
	std::vector<std::vector<std::pair<int, int>>> heap;
	int* parent;
	int* key;
	bool* inMST;
};

/**
 * PrimHeap
 * @param - int numVertices - number of vertices in the graph
 * @param - std::vector<std::vector<std::pair<int, int>>> heap - the heap
 * @return none
 * 
 * This is the constructor.
 */

PrimHeap::PrimHeap(int numVertices, std::vector<std::vector<std::pair<int, int>>> heap)
{
	this->numVertices = numVertices;
	this->heap = heap;
	parent = new int[numVertices];
	key = new int[numVertices];
	inMST = new bool[numVertices];
	for (int i = 0; i < numVertices; i++)
	{
		key[i] = std::numeric_limits<int>::max();
		inMST[i] = false;
	}
}

/**
 * ~PrimHeap
 * @param none
 * @return none
 * 
 * This is the destructor. It frees up memory by deleting parent, key, and inMST.
 */

PrimHeap::~PrimHeap()
{
	delete[] parent;
	delete[] key;
	delete[] inMST;
}

/**
 * runPrim()
 * @param none
 * @return void
 * 
 * This function runs Prim's Algorithm on the heap.
 */

void PrimHeap::runPrim()
{
	key[0] = 0;
	parent[0] = -1;
	for (int i = 0; i < numVertices - 1; i++)
	{
		int minKey = std::numeric_limits<int>::max();
		int minKeyIndex;
		for (int j = 0; j < numVertices; j++)
		{
			if (inMST[j] == false && key[j] < minKey)
			{
				minKey = key[j];
				minKeyIndex = j;
			}
		}
		inMST[minKeyIndex] = true;
		for (int j = 0; j < heap[minKeyIndex].size(); j++)
		{
			int v = heap[minKeyIndex][j].first;
			int weight = heap[minKeyIndex][j].second;
			if (inMST[v] == false && weight < key[v])
			{
				parent[v] = minKeyIndex;
				key[v] = weight;
			}
		}
	}
}

/**
 * printMST()
 * @param none
 * @return void
 * 
 * This function prints the minimum spanning tree.
 */

void PrimHeap::printMST()
{
	std::cout << "The MST: \n";
	for (int i = 1; i < numVertices; i++)
	{
		std::cout << parent[i] << " " << i << " " << key[i] << "\n";
	}
}


