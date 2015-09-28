template <class T>
C<T>::C(const T val)
{
	mystery = val;
}

template <class T>
T C<T>::getMe()
{
	return mystery;
}
