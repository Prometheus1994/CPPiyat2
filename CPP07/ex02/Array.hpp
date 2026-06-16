template <class T>
class Array
{
	T *arr;
	unsigned int _size;

	public:
	Array()
	{
		arr = NULL;
		_size = 0;
	}
	Array(unsigned int n)
	{
		_size = n;
		arr = new T[n];
	}
	Array(const Array &other)
	{
		_size = other._size;
		arr = new T[_size];
		int i = 0;
		while (i < other._size)
		{
			arr[i] = other.arr[i];
			i++;
		}
	}
	Array& operator=(const Array &other)
	{
		if (this == &other)
			return *this;
		delete[] arr;
		_size = other._size;
		arr = new T[_size];
		unsigned int i = 0;
		while (i < other._size)
		{
			arr[i] = other.arr[i];
			i++;
		}
		return *this;	
	}
	~Array()
	{
		delete[] arr;
	}

	T& operator[](unsigned int index)
	{
		if (index >= _size)
			throw (std::exception());
		return arr[index];
	}
	unsigned int size() const
	{
		return _size;
	}
};