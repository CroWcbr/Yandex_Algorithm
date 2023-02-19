#include <iostream>
#include <vector>

class Heap
{
private:
	std::vector<int>	_data;

private:
	void	HeapifyUp(int k, int index)
	{
		while (index > 0 and k > _data[(index - 1) / 2]) 
		{
			std::swap(_data[(index - 1) / 2], _data[index]);
			index = (index - 1) / 2;
		}
	}

	void	HeapifyDown(size_t index)
	{
		size_t child;
		size_t left = Left(index);
		size_t right = Right(index);
		if (left <= _data.size() - 1) 
		{
			if (right <= _data.size() - 1 and _data[right] > _data[left])
				child = right;
			else
				child = left;
			if (_data[child] > _data[index]) 
			{
				std::swap(_data[child], _data[index]);
				HeapifyDown(child);
			}
		}
	}

public:
	Heap() {};
	Heap(const Heap &copy) = delete;
	Heap &operator=(const Heap &copy) = delete;
	~Heap() {};

	size_t Left(size_t index) { return index * 2 + 1; }
	size_t Right(size_t index) { return index * 2 + 2; }

	void	insert(int k)
	{
		_data.push_back(k);
		HeapifyUp(k, _data.size() - 1);
	}

	int		extract()
	{
		int largest = _data.front();
		if (_data.size() != 0)
		{
			std::swap(_data.back(), _data.front());
			_data.pop_back();
			HeapifyDown(0);
		}
		return largest;
	}
};

int main()
{
	int	n;
	std::cin >> n;

	int		_op;
	Heap	_heap;
	for (int i = 0; i < n; ++i) 
	{
		std::cin >> _op;
		if (_op == 0) {
			int k;
			std::cin >> k;
			_heap.insert(k);
		}
		else
			std::cout << _heap.extract() << std::endl;
	}
	return 0;
}
