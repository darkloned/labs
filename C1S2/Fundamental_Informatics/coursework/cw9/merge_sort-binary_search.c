#include<stdio.h>
#include<stdbool.h>

typedef struct
{
	int key;
	int value;
} Pair;

// merge map[l..m] and map[m + 1..r]
void merge(Pair map[], int l, int m, int r)
{
	int nLeft = m - l + 1;
	int nRight = r - m;

	Pair left[nLeft], right[nRight];

	for (int i = l; i <= m; ++i)
		left[i - l] = map[i];

	for (int i = m + 1; i <= r; ++i)
		right[i - m - 1] = map[i];

	int i = 0, j = 0, k = l;

	// merge back to map[l..m]
	while (i < nLeft || j < nRight)
	{
		if (j >= nRight || (i < nLeft && left[i].key <= right[j].key))
		{
			map[k] = left[i];
			i++;
		}
		else
		{
			map[k] = right[j];
			j++;
		}

		k++;
	}
}

void mergeSort(Pair map[], int l, int r)
{
	if (l < r)
	{
		// in case l and r are too large
		int m = l + (r - l) / 2;

		// divide and rule!
		mergeSort(map, l, m);
		mergeSort(map, m + 1, r);

		merge(map, l, m, r);
	}
}

// find key in map and return its value
int binSearch(Pair map[], int l, int r, int wanted_key)
{ 
	if (r >= l)
	{
		// again, in case l and r are too large
		int m = l + (r - l) / 2;

		if (map[m].key == wanted_key)
		{
			// we need to get first wanted key's ID
			// (assuming that it can be several of them)
			if (l == m)
				return m;
			else
				return binSearch(map, l, m, wanted_key);
		}


		if (map[m].key > wanted_key)
			return binSearch(map, l, m - 1, wanted_key);

		return binSearch(map, m + 1, r, wanted_key);
	}
	
	return -1; // if not found
}

/* Input:
 * n
 * n lines of int <key, value>
 * m
 * m keys
 */

/* Output:
 * n lines of sorted map by key
 * m corresponding values
 */

int main()
{
	int n;

	scanf("%d", &n);

	Pair map[n];

	for (int i = 0; i < n; ++i)
	{
		Pair pair;

		scanf("%d %d", &pair.key, &pair.value);

		map[i] = pair;
	}

	int m;

	scanf("%d", &m);

	int wanted_keys[m];

	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &wanted_keys[i]);
	}

	mergeSort(map, 0, n - 1);

	printf("Sorted map by key:\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d %d\n", map[i].key, map[i].value);
	}

	for (int i = 0; i < m; ++i)
	{
		int keyID = binSearch(map, 0, n - 1, wanted_keys[i]);

		if (keyID == -1)
			printf("Key (%d) is not found\n", wanted_keys[i]);
		else
			printf("Value of key (%d) is (%d)\n", wanted_keys[i], map[keyID].value);
	}	

	return 0;
}
