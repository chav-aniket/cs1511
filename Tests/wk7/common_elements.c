//Made by Aniket Chavan (z5265106) (chavaniket@outlook.com)
//Made on 08/04/2019
//This program 

// copy all of the values in source1 which are also found in source2 into destination
// return the number of elements copied into destination

int common_elements(int length, int source1[length], int source2[length], int destination[length]) {
    // PUT YOUR CODE HERE (you must change the next line!)
    int counter = 0;
    for (int i = 0;i<length;i++) {
        for (int j = 0;j<length;j++) {
            if(source1[i] == source2[j]) {
                destination[counter] = source1[i];
                counter++;
                break;
            }
        }
    }
    return counter;
}

// You may optionally add a main function to test your common_elements function.
// It will not be marked.
// Only your common_elements function will be marked.
