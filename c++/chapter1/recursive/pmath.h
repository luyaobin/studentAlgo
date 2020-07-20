#pragma once

int factorial(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * factorial(n - 1);
}

template<class T>
T sum(T a[], int n)
{
	T theSum = 0;
	for (int i = 0; i < n; ++i)
		theSum += a[i];
	return theSum;

// return accumulate(a, a + n, theSum);
}

template<class T>
T product(T a[], int n)
{
	T theProduct = 0;
	return accumulate(a, a + n, theProduct, multiplies<T>());
}

template<class T>
T rSum(T a[], int n)
{
	if (n > 0)
		return rSum(a, n - 1) + a[n - 1];
	return 0;
}

template<class T>
void permutations(T list[], int k, int m)
{
	if (k == m)
		copy(list, list + m + 1,
			ostream_iterator<T>(cout, ""));
	else {
		for (int i = k; i <= m; ++i) {
			swap(list[k], list[i]);
			permutations(list, k + 1, m);
			swap(list[k], list[i]);
		}
	}
}

template<class T>
void stlpermuttions(T list[], int k, int m)
{
	do{
		copy(list, list + m + 1,
			ostream_iterator<T>(cout, "");
		cout << endl;
	}while (next_permutation(list, list + m + 1));
}
