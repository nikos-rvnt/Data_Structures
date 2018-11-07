


# Data_Structures

## Merge-Sort, Different Searching Algorithms and Red-Black Tree structure implementation 




1. Firstly integer numbers are read from "integers.txt" file using ifstream objects. 

2. Then these numbers are getting sorted using Merge Sort algorithm. Merge Sort algorithm can be described from the next steps : 

   - If the list contains only one number then there is no reason for sorting, return.
  
   - Divide the list into two halves until it can no more be divided.
  
   - Merge the smaller lists into new lists in sorted order. 
  
   The next image (taken from [GeeksforGeeks](https://www.geeksforgeeks.org/merge-sort/)) describes very well the whole merge sort process:
  
   # ![Alt text](https://www.geeksforgeeks.org/wp-content/uploads/Merge-Sort-Tutorial.png) 


3. Then time metrics are counted for each searching algorithm of the following :

   - Linear Search: definitely, the simplest searching algorithm but not the optimum. It can be described from the following steps:
   
     - Starting from the first element of the list check one by one all the elements and see if there is a match.
     
     - If there is a match return the index of the matched element, if not return null.
   
   - Binary Search: definitely faster than linear search (O(logn) time complexity) but needs data to be sorted. It follows the next steps:
   
     - Check the middle element of the list. 
     
     - If it matches then return the middle index. If not and is greater from the middle check on the right subarray. Else, check on the left subarray.
     
     - Continue till it is found or till all subarrays are checked and if not found return null. 
   
   - Interpolation Search: better version of binary search but its drawback is that it needs the data to be sorted and uniformly distributed. The searching process is described as:
   
     - Define pos as, pos = [ (x-arr[lo])*(hi-lo) / (arr[hi]-arr[Lo]) ], where x is the element to be searched, lo and hi are the first and the last array index respectively.
   
     - In a loop, calculate the value of pos using the probe position formula.

     - If it is a match, return the index of the item, and exit.

     - If the item is less than arr[pos], calculate the probe position of the left sub-array. Otherwise calculate the same in the right sub-array.

     - Repeat until a match is found or the sub-array reduces to zero.
   
   - Red-Black Tree(Insertion/Searching): Red-Black trees are actually a more specific case of Binary Search Trees. The advantage of Red-Black trees is that the time complexity is O(logn) where n is the number of nodes, when a Binary Search Tree needs O(h) where h is the height of the tree. A Red-Black Tree follows the following four rules:
   
     - Every node is either red or black,
     
     - Root node is black,
     
     - There are no two adjacent nodes,
     
     - Every path from a node (including root) to any of its descendant NULL node has the same number of black nodes.
     
     The Red-Black here is implemented in order to support Insert and Search operations. Insertion operation is described by the following (let x be the newly inserted node):
     
     1) Perform standard BST insertion and make the color of newly inserted nodes as RED.

     2) If x is root, change color of x as BLACK (Black height of complete tree increases by 1).

     3) Do following if color of x’s parent is not BLACK or x is not root.
     
        a) If x’s uncle is RED (Grand parent must have been black from property 4)
           - Change color of parent and uncle as BLACK.
           - color of grand parent as RED.
           - Change x = x’s grandparent, repeat steps 2 and 3 for new x.

        b) If x’s uncle is BLACK, then there can be four configurations for x, x’s parent (p) and x’s grandparent (g) (This is similar to AVL Tree)
           - Left Left Case (p is left child of g and x is left child of p)
           - Left Right Case (p is left child of g and x is right child of p)
           - Right Right Case (Mirror of case a)
           - Right Left Case (Mirror of case c)
     
     Search operation as defined on Binary Search Trees can be described as:
     
     - Start searching from the root node. 
     
     - If not found start searching on the left subtree.
     
     - Otherwise, start searching on the right subtree.
     
     - Repeat, till a Null-child node is reached, then the value is not contained in the tree.
   
   <br />
   <br />
   
   Time metrics are estimated using *ctime* library and creating *clock_t*  objects to keep the starting and ending time point of the respective algorithm run. Each searching algo is looking for a random number generated between 10 and 490000 that is the minimum and the maximum indexed integer numbers of the "integers.txt" file.
   
   Running the Data_Struct_Times.cpp (main) file will produce something like this:
   
      # ![Alt text](https://github.com/nikos-rvnt/Data_Structures/blob/master/Time%20Complexity%20of%20Searching%20Algorithms/time_search_metrics.jpg) 
