//Made by Aniket Chavan (z5265106) (chavaniket@outlook.com)
//Made on the 16-04-19
//Function returns the number of even values in an array

int count_even(int length,int array[length]);

int main(void) {
    return 0;
}

int count_even(int length, int array[length]) {
    int counter = 0;
    for (int i = 0;i < length;i++) {
        if(array[i]%2==0) {
            counter++;
        }
    }
    return counter;
}
