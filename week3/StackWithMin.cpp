//��Ŀ������ջ�����ݽṹ�����ڸ�������ʵ��һ���õ�ջ��СԪ�ص�min�������ڸ�ջ�С�����min, push��pop��ʱ�临�Ӷȶ���O��1����
//��ʵ������˼·���Ǻܴ��ڵĿռ任ȡʱ���ϵ�Ч�ʡ���Ϊջ���Ƚ�����ļ�¼ʽ���ݽṹ�������ڲ���ĳ��״ֵ̬��ʱ��������Ҫ�˽⵱ǰ�ṹ�е����������������������С����ǽ�����һ���ռ�����¼��Сֵ�ǲ����еġ���Ϊ��һ�����ݳ�ջ��������Сֵ��Ȼ��ʣ�µ���Сֵ��˭�أ�
//����������Ҫ��һ������ĸ���ջȥ��¼��ǰ����Сֵ��
//����˼·���ˡ�������Ҫʵ�־ͺܼ��ˡ�
//ֱ�������룺
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