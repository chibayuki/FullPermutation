/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Copyright © 2020 chibayuki@foxmail.com

FullPermutation
Version 20.1.16.0000

This file is part of FullPermutation

FullPermutation is released under the GPLv3 license
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>

#include "FullPermutation.h"

using namespace std;

StageInt::StageInt(size_t size) :
	_Size(size),
	_Min(true),
	_Max(false)
{
	_Data = new int[_Size];
	memset(_Data, 0, _Size * sizeof(int));
}

StageInt::StageInt(const StageInt& other) :
	_Size(other._Size),
	_Min(other._Min),
	_Max(other._Max)
{
	_Data = new int[_Size];
	memcpy(_Data, other._Data, _Size * sizeof(int));
}

StageInt::StageInt(StageInt&& other) :
	_Size(other._Size),
	_Min(other._Min),
	_Max(other._Max),
	_Data(other._Data)
{
	other._Data = nullptr;
}

StageInt& StageInt::operator=(const StageInt& other)
{
	if (this == &other)
	{
		return *this;
	}

	_Size = other._Size;
	_Min = other._Min;
	_Max = other._Max;

	_Data = new int[_Size];
	memcpy(_Data, other._Data, _Size * sizeof(int));

	return *this;
}

StageInt& StageInt::operator=(StageInt&& other)
{
	if (this == &other)
	{
		return *this;
	}

	_Size = other._Size;
	_Min = other._Min;
	_Max = other._Max;

	_Data = other._Data;
	other._Data = nullptr;

	return *this;
}

StageInt::~StageInt()
{
	if (_Data)
	{
		delete[] _Data;
	}
}

void StageInt::Reset()
{
	_Min = true;
	_Max = false;

	memset(_Data, 0, _Size * sizeof(int));
}

bool StageInt::Next()
{
	if (_Max)
	{
		return false;
	}
	else
	{
		if (_Min)
		{
			_Min = false;
		}

		int i = 0;

		do
		{
			_Data[i]++;

			if (_Data[i] > i + 1)
			{
				_Data[i] = 0;
				i++;

				if (i >= _Size)
				{
					_Max = true;

					break;
				}
			}
			else
			{
				break;
			}
		} while (true);

		return true;
	}
}

FullPermutation::FullPermutation()
{
}

FullPermutation::FullPermutation(const FullPermutation&)
{
}

FullPermutation& FullPermutation::operator=(const FullPermutation&)
{
	return *this;
}

FullPermutation::~FullPermutation()
{
}

void FullPermutation::Execute(const vector<int>& values)
{
	size_t size = values.size();

	StageInt s = StageInt(size - 1);

	vector<size_t> indices;

	for (size_t i = 0; i < size; i++)
	{
		indices.push_back(i);
	}

	vector<int> result;

	while (!s.IsMax())
	{
		vector<size_t> i = indices;

		for (size_t j = 0; j < size - 1; j++)
		{
			size_t k = s[size - j - 2];

			result.push_back(values[i[k]]);
			i.erase(i.begin() + k);
		}

		result.push_back(values[i[0]]);

		for (vector<int>::iterator j = result.begin(); j != result.end(); j++)
		{
			cout << (*j) << ' ';
		}

		cout << endl;

		result.clear();

		s.Next();
	}

	cout << endl;
}

void FullPermutation::Execute(const vector<char>& values)
{
	size_t size = values.size();

	StageInt s = StageInt(size - 1);

	vector<size_t> indices;

	for (size_t i = 0; i < size; i++)
	{
		indices.push_back(i);
	}

	vector<char> result;

	while (!s.IsMax())
	{
		vector<size_t> i = indices;

		for (size_t j = 0; j < size - 1; j++)
		{
			size_t k = s[size - j - 2];

			result.push_back(values[i[k]]);
			i.erase(i.begin() + k);
		}

		result.push_back(values[i[0]]);

		for (vector<char>::iterator j = result.begin(); j != result.end(); j++)
		{
			cout << (*j) << ' ';
		}

		cout << endl;

		result.clear();

		s.Next();
	}

	cout << endl;
}
