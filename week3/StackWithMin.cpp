//题目：定义栈的数据结构，请在该类型中实现一个得到栈最小元素的min函数。在该栈中。调用min, push及pop的时间复杂度都是O（1）；
//其实这个题的思路就是很大众的空间换取时间上的效率。因为栈是先进后出的记录式数据结构。所以在查找某种状态值的时候我们需要了解当前结构中的整体情况。所以在这个题中。我们仅仅用一个空间来记录最小值是不可行的。因为当一个数据出栈后。他是最小值。然后剩下的最小值是谁呢？
//所以我们需要有一个跟随的辅助栈去记录当前的最小值。
//所以思路有了。我们想要实现就很简单了。
//直接来代码：
template<typename T>
void StackWithMin<T>::push(const T& value)
{
	mData.push(value);

	if (mMin.size() == 0 || value<mMin.top())
	{
		mMin.push(value);
	}
	else
	{
		mMin.push(mMin.top());
	}
}

template<typename T>
void StackWithMin<T>::pop()
{
	assert(mData.size() > 0 && mMin.size() > 0)

		mData.pop();
	mMin.pop();
}

template<typename T>
const T& StackWithMin<T>::min() const
{
	assert(mData.size() > 0 && mMin.size > 0);

	return mMin.top();
}