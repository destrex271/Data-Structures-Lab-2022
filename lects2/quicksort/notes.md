# Quick sort 

 - Divide and Conquer only, No Combination.
 - Same as Merge sort but no use of third array, inplace sorting occues.

# Concept

## Element in the middle, Sorting about pivot.(Left -> small, Right -> greater)
Worst case: O(n^2)
Best case: O(nlogn)

				  fib(4)
			/							\
		fib(3)				fib(2)
		/    \				/      \
	fib(2)  fib(1) fib(1)  fib(0)
	/    \
fib(1) fib(0) 


# Randomized QuickSort
if p<r
	then q <- Radnomized
