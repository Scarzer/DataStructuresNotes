# Running Time Analysi - Big O notation

## Time Analysis

### Example: Stair Counting Problem
* Find it out your self!
    * Method 1: Walk down and keep a tally
    * Method 2: Walk down, but let Judy keep the tally
    * Method 3: Jervis to the rescue! Some shmuck downstairs who has the answer already

    So how many operations are there?
    * 1 > Each time a step is take, make a mark [2689 steps down + 2689 steps up + 2689 marks = 8067]  | O(3n)
    * 2 > For each step, go back, make the ball and chain take a mark, and repeat [Down: 3615705 (1 + 2 + 3 ... + 2889) | Up: 3615705 | Marks: 2689 ] = 7236099 | O(n^2+2n)
    * 3 > Mark each digit in (2689) | O(log(n) + 1)

* How to measure the time?
    * Just measure the actual time
        * vary from peron to person
        * derpending on many factors

### Example - Quiz
    * Printout all item in an interger array of saize N

    ``` 
    for (int i = 0; i < N; i++){
        val = a[i];
        cout << val;
    }
    ```

    * Frequent linear pattern
        * A loop that does a fixed amount of operations N times requires O(N) time

    * Another example
    ``` 
    for(int i = 0; i < strlen(str); i++){
    c = str[i];
    cout << c;
    }
    ```
        * This example is horrible because there is a function call inside!    
    

### Worst Case, Average Case, and Best Case
    * Search a number x in an interger array of size N
    ```
    for(int i = 0; (i<N)&&(a[i] != x); i++){
    if (i<N) cout << "Number " << x << "is at location " << i << endl;
    else cout << "Not Found!" << endl;
    }
    ```

