/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Copyright © 2020 chibayuki@foxmail.com

FullPermutation
Version 20.1.16.0000

This file is part of FullPermutation

FullPermutation is released under the GPLv3 license
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#pragma once

#define DEBUG (1)

#include <vector>

using std::vector;

// 阶梯进位制整数
class StageInt
{
private:
	size_t _Size;
	bool _Min, _Max;
	int* _Data;

public:
	StageInt(size_t size);
	StageInt(const StageInt& other);
	StageInt(StageInt&& other);
	StageInt& operator=(const StageInt& other);
	StageInt& operator=(StageInt&& other);
	virtual ~StageInt();

	inline size_t Size() const
	{
		return _Size;
	}

	inline int operator[](size_t index) const
	{
		if (index >= _Size)
		{
			return -1;
		}

		return _Data[index];
	}

	inline bool IsMin() const
	{
		return _Min;
	}

	inline bool IsMax() const
	{
		return _Max;
	}

	void Reset();
	bool Next();
};

// 全排列
class FullPermutation
{
private:
	FullPermutation();
	FullPermutation(const FullPermutation&);
	FullPermutation& operator=(const FullPermutation&);
	virtual ~FullPermutation();

public:
	static void Execute(const vector<int>& values);
	static void Execute(const vector<char>& values);
};
