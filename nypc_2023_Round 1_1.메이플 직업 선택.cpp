#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    char arr[t][100]; 
    for (int i = 0; i < t; i++) {
        scanf("%s", arr[i]);
    }

    int k;
    scanf("%d", &k);
    char myjob[k][100];  

    for (int j = 0; j < k; j++) {
        scanf("%s", myjob[j]);
    }

    int newJobCount = 0;  
    char newJobs[t][100];
    
    for (int i = 0; i < t; i++) {
        int found = 0;  

        for (int j = 0; j < k; j++) {
            if (strcmp(arr[i], myjob[j]) == 0) {
                found = 1;
                break;  
            }
        }

        if (!found) {
            strcpy(newJobs[newJobCount], arr[i]);
            newJobCount++;
        }
    }

    printf("%d\n",newJobCount);
    for (int i = 0; i < newJobCount; i++) {
        printf("%s\n", newJobs[i]);
    }

    return 0;
} 
