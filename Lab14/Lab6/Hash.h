#pragma once
#include <iostream>
#define SIZE 128
using namespace std;

struct HashTab {
	short year = 0;
	string NAME;
};

int Hash_Fun(short key);

void add(HashTab* Tab);
void find(HashTab* Tab);
void out(HashTab* Tab);
void del(HashTab* Tab);
