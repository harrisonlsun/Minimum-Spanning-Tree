/**
 * Author: Harrison Sun (sun.har@northeastern.edu)
 * EECE7205 - Professor Shelley Lin
 * Date: 2019-10-15
 * Homework 4
 *
 * This file contains the main function for the program. The program runs Prim's Algorithm using two methods: adjacency matrix with unsorted array for priority queue and adjacency list with binary heap for priority queue.
 * The program also implements Djikstra's Algorithm using adjacency matrix with unsorted array for priority queue and the Bellman-Ford Algorithm.
 */

#include <iostream>
#include "prim_matrix.h"
#include "prim_list.h"
#include "djikstra.h"
#include "bellman-ford.h"
#include "header.h"

/**
 * main
 * @param - int argc - the number of command line arguments
 * @param - char* argv[] - the command line arguments
 * 
 * This is the main function. It runs Prim's Algorithm using two methods: adjacency matrix with unsorted array for priority queue and adjacency list with binary heap for priority queue. It also implements Djikstra's Algorithm using 
 * adjacency matrix with unsorted array for priority queue and the Bellman-Ford Algorithm.
 */

int main(int argc, int* argv[])
{
	int numVertices = 5;
	int numEdges = 10;
	int maxWeight = 10;

	/** Prim's Algorithm with adjacency matrix. */
	std::cout << "Prim's Algorithm with adjacency matrix" << std::endl;
	/** Generate a random adjacency matrix. */
	int** matrix = generateMatrix(numVertices, numEdges, maxWeight);
	/** Run Prim's Algorithm with adjacency matrix. */
	PrimMatrix* primMatrix = new PrimMatrix(numVertices, matrix);
	primMatrix->runPrimMatrix();
	/** Print the MST. */
	primMatrix->printDistance();

	/** Prim's Algorithm with adjacency list. */
	std::cout << "\nPrim's Algorithm with adjacency list" << std::endl;
	/** Generate a random adjacency list. */
	std::vector<std::vector<std::pair<int, int>>> list = generateList(numVertices, numEdges, maxWeight);
	std::vector<std::vector<std::pair<int, int>>>* listPtr = &list;
	/** Run Prim's Algorithm with adjacency list. */
	PrimList* primList = new PrimList(numVertices, listPtr);
	primList->runPrimList();
	/** Print the MST. */
	primList->printDistance();	
	
	/** Dijkstra's Algorithm */
	std::cout << "\nDijkstra's Algorithm" << std::endl;
	/** Generate a random adjacency matrix. */
	int** matrixDJ = generateMatrix(numVertices, numEdges, maxWeight);
	/** Run Djikstra's Algorithm. */
	Dijkstra* dijkstra = new Dijkstra(numVertices, matrixDJ);
	dijkstra->runDjikstra();
	/** Print the shortest paths. */
	dijkstra->printDistance();

	/** Bellman-Ford Algorithm */
	std::cout << "\nBellman Ford\n";
	/** Generate a random adjacency matrix. */
	int** matrixBF = generateMatrix(numVertices, numEdges, maxWeight);
	/** Run Bellman-Ford Algorithm. */
	BellmanFord* bellmanFord = new BellmanFord(numVertices, matrixBF);
	
	return 0;
}