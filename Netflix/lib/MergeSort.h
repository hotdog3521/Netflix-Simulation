#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

class MergeSort {
  public:
    template <class T>
    static vector<T> sort (vector<T> a) {
      

	MergeSort(a, 0, a.size()-1);
	

	return a;

    }



template<class T>
MergeSort(vector<T>& a, int l, int r)
{	
	if (l<r)
	{
		int m = (l+r)/2;
		MergeSort(a, l, m);
		MergeSort(a, m+1, r);
		Merge(a, l, r, m);
	}
}

template<class T>	
static void Merge (vector<T> & a, int l, int r, int m)
{
	//T temp[r-l+1];
	T * temp = new T[r-l+1];
	
	int i = l, j = m+1, k = 0;
	while (i <= m || j <= r)
	{
		if (i <= m && (j > r || a[i] < a[j]))
		{ 
			temp[k] = a[i];
			i ++; k ++;
		}
		else
		{
			temp[k] = a[j];
			 j ++; k ++;
		}
		
	}
	for (k = 0; k < r-l+1; k ++)
	{
		a[k+l] = temp[k];
	}

}
};

