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
#include <utility>
#include "heap.h"
#include "header.h"

 /**
  * Prim's Algorithm with Adjacency List
  */

class PrimList {
public:
	PrimList(int numVertices, std::vector<std::vector<std::pair<int, int>>>* adjList);
	~PrimList();
	void runPrimList();
	void printDistance();
private:
	int numVertices;
	std::vector<std::vector<std::pair<int, int>>>* adjList;
	int* distance;
	bool* sptSet;
};

/**
 * PrimList
 * @param - int numVertices - number of vertices in the graph
 * @param - std::vector<std::vector<std::pair<int, int>>>* adjList - adjacency list of the graph
 * @return none
 */

PrimList::PrimList(int numVertices, std::vector<std::vector<std::pair<int, int>>>* adjList) {
	this->numVertices = numVertices;
	this->adjList = adjList;
	distance = new int[numVertices];
	sptSet = new bool[numVertices];
}

/**
 * ~PrimList
 * @param none
 * @return none
 */

PrimList::~PrimList() {
	delete[] distance;
	delete[] sptSet;
}

/**
 * runPrimList
 * @param none
 * @return none
 *
 * This function runs Prim's Algorithm using an adjacency list with binary heap for priority queue.
 */

void PrimList::runPrimList() {
	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < numVertices; i++) {
		distance[i] = std::numeric_limits<int>::max();
		sptSet[i] = false;
	}

	// Distance of source vertex from itself is always 0
	distance[0] = 0;

	// Create a min heap of size numVertices
	Heap* heap = new Heap(numVertices);

	// Insert all vertices into the min heap
	for (int i = 0; i < numVertices; i++) {
		heap->insert(i, distance[i]);
	}

	// Find shortest path for all vertices
	while (!heap->isEmpty()) {
		// Extract the vertex with minimum distance value
		int u = heap->extractMin();

		// Mark the extracted vertex as processed
		sptSet[u] = true;

		// Update distance value of the adjacent vertices of the extracted vertex
		for (int i = 0; i < adjList->at(u).size(); i++) {
			int v = adjList->at(u).at(i).first;
			int weight = adjList->at(u).at(i).second;

			// Update distance[v] only if is not in sptSet, there is an edge from u to v, and total weight of path from src to v through u is smaller than current value of distance[v]
			if (!sptSet[v] && heap->contains(v) && distance[u] != std::numeric_limits<int>::max() && distance[u] + weight < distance[v]) {
				distance[v] = distance[u] + weight;
				heap->decreaseKey(v, distance[v]);
			}
		}
	}
}

/**
 * printDistance
 * @param none
 * @return none
 *
 * This function prints the distance array.
 */

void PrimList::printDistance() {
	std::cout << "The distance array:" << std::endl;
	for (int i = 0; i < numVertices; i++) {
		std::cout << distance[i] << "\t";
	}
	std::cout << "\n";
}
