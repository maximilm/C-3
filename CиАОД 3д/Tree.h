#pragma once
#include <iostream>
#include "Knot.cpp"
using namespace std;
class Tree {
	Knot* root;
public:
	void averageLeft(Knot** key, float& sum, int& k);
	void averageRight(Knot** key, float& sum, int& k);
	void deleteTree(Knot** key);
	Knot** getRoot();
	void printTree(Knot** key, int l);
	void createTree(int n, Knot** root);
};
