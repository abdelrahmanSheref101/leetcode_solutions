class Solution {
public:
	vector<int> sortArray(vector<int> &array) {
		// Find the largest element of the array
        int size = array.size();
        const int SHIFT = 50000;

        for (int i = 0; i < size; ++i)
            array[i] += SHIFT;


		int max = array[0];
		for (int i = 1; i < size; ++i)
			if (array[i] > max)
				max = array[i];

		vector<int> count(max+1);	// zeros

		// Compute Frequency
		for (int i = 0; i < size; ++i)
			count[array[i]] += 1;

		int idx = 0;
		for (int i = 0; i <= max; ++i) {
			for (int j = 0; j < count[i]; ++j, ++idx)
				array[idx] = i - SHIFT;
		}
            

		return array;
	}
};

