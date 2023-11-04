# Execution time of sorting algorithms
This article describes the use of sorting algorithms in Python to help you understand how data sorting works in programming and which approach is optimal in various scenarios. It covers a range of sorting algorithms, including Selection, Insertion, Binary Insertion, Bubble, Shaker, Shell, Heap, Merge, Quick, Counting, Radix, and Flash. The goal is to help you grasp how each algorithm operates and its performance in different use cases.

You can explore specific examples of implementing these algorithms in Python and how to choose the appropriate algorithm for your task. Sorting data is an essential part of programming, and a clear understanding of these algorithms will make you a better programmer.
# Statistical Tabel
| Input State | Input Size | Selection | Insertion | Binary Insertion | Bubble | Shaker | Shell | Heap  | Merge | Quick | Counting | Radix | Flash |
|-------------|------------|-----------|-----------|------------------|--------|--------|-------|-------|-------|-------|----------|-------|-------|
| Random      | 1000       | 0.000     | 0.000     | 0.000            | 0.000  | 0.000  | 0.000 | 0.000 | 0.000 | 0.000 | 0.000    | 0.000 | 0.000 |
| Random      | 3000       | 0.015     | 0.000     | 0.000            | 0.016  | 0.016  | 0.000 | 0.000 | 0.000 | 0.000 | 0.000    | 0.000 | 0.015 |
| Random      | 10000      | 0.072     | 0.031     | 0.032            | 0.218  | 0.201  | 0.000 | 0.015 | 0.000 | 0.000 | 0.000    | 0.000 | 0.032 |
| Random      | 30000      | 0.487     | 0.312     | 0.235            | 2.201  | 1.966  | 0.005 | 0.007 | 0.004 | 0.004 | 0.000    | 0.002 | 0.341 |
| Random      | 100000     | 5.944     | 3.694     | 2.744            | 27.524 | 21.152 | 0.016 | 0.029 | 0.015 | 0.011 | 0.001    | 0.006 | 3.853 |
| Sorted      | 1000       | 0.001     | 0.000     | 0.000            | 0.000  | 0.000  | 0.000 | 0.000 | 0.000 | 0.000 | 0.000    | 0.000 | 0.000 |
| Sorted      | 3000       | 0.006     | 0.000     | 0.000            | 0.006  | 0.000  | 0.000 | 0.000 | 0.000 | 0.000 | 0.001    | 0.000 | 0.000 |
| Sorted      | 10000      | 0.061     | 0.000     | 0.001            | 0.068  | 0.000  | 0.000 | 0.002 | 0.000 | 0.000 | 0.000    | 0.001 | 0.000 |
| Sorted      | 30000      | 0.542     | 0.000     | 0.001            | 0.587  | 0.000  | 0.001 | 0.004 | 0.000 | 0.000 | 0.000    | 0.000 | 0.000 |
| Sorted      | 100000     | 5.728     | 0.000     | 0.006            | 6.138  | 0.000  | 0.009 | 0.015 | 0.010 | 0.000 | 0.000    | 0.005 | 0.005 |
| Reversed    | 1000       | 0.000     | 0.000     | 0.000            | 0.011  | 0.000  | 0.000 | 0.000 | 0.000 | 0.000 | 0.000    | 0.000 | 0.004 |
| Reversed    | 3000       | 0.007     | 0.008     | 0.005            | 0.019  | 0.016  | 0.000 | 0.000 | 0.000 | 0.000 | 0.000    | 0.000 | 0.016 |
| Reversed    | 10000      | 0.062     | 0.078     | 0.047            | 0.235  | 0.234  | 0.000 | 0.000 | 0.000 | 0.000 | 0.000    | 0.000 | 0.078 |
| Reversed    | 30000      | 0.501     | 0.625     | 0.469            | 2.099  | 2.206  | 0.001 | 0.005 | 0.002 | 0.001 | 0.000    | 0.001 | 0.672 |
| Reversed    | 100000     | 6.041     | 7.060     | 5.351            | 25.023 | 24.861 | 0.006 | 0.018 | 0.006 | 0.003 | 0.001    | 0.003 | 7.482 |

# Summary
- Random Input: When the input data is in a random order, the runtimes for most sorting algorithms vary significantly with the input size. Bubble sort and Quick sort tend to have higher runtimes compared to other algorithms as the input size increases. Counting sort, Radix sort, and Flash sort show consistently low runtimes even for larger input sizes.

- Sorted Input: When the input data is already sorted, some algorithms perform exceptionally well, such as Selection sort, Insertion sort, and Binary Insertion sort. They have very low runtimes. On the other hand, algorithms like Shaker sort and Shell sort have increased runtimes with larger input sizes.

- Reversed Input: When the input data is in reversed order, the performance of sorting algorithms varies similarly to random input, but the runtimes tend to be slightly higher.

- Overall Analysis: Counting sort, Radix sort, and Flash sort consistently demonstrate low runtimes regardless of the input type. Bubble sort and Quick sort are less efficient, especially for larger input sizes. Selection sort, Insertion sort, and Binary Insertion sort perform well with sorted input but are not as efficient with random or reversed input.

In summary, the choice of a sorting algorithm should consider the characteristics of the input data. Counting sort, Radix sort, and Flash sort are good choices for general-purpose sorting tasks, while Selection sort, Insertion sort, and Binary Insertion sort perform well with already sorted data. The specific choice depends on the nature of the data and the desired sorting performance.
