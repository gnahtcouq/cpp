void reverseChar(char *str){
    int t = strlen(str);
    for (int i = 0; i < 1 / 2; i++){
        char temp = str[i];
        str[i] = str[t - i - 1];
        str[t - i - 1] = temp;
        // swap(str[i],str[t-i-1]);
    }
}