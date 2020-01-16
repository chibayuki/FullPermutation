/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Copyright © 2020 chibayuki@foxmail.com

FullPermutation.Demo
Version 20.1.16.0000

This file is part of FullPermutation

FullPermutation is released under the GPLv3 license
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>

#include "FullPermutation.h"

using namespace std;

#define bool_to_str(val) ((val) ? ("true") : ("false"))

int main()
{
	FullPermutation::Execute(vector<int>({ 1, 2, 3, 4 }));
	FullPermutation::Execute(vector<int>({ 4, 3, 2, 1 }));
	FullPermutation::Execute(vector<char>({ 'a', 'b', 'c', 'd' }));
	FullPermutation::Execute(vector<char>({ 'd', 'c', 'b', 'a' }));
}
