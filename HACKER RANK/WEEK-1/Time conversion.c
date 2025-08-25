#include <stdio.h>
#include <string.h>

void convertTo24HourFormat(char *inputTime) {
    int hr;
    char am_pm[3];
    char convertedTime[9];

    sscanf(inputTime,"%2d:%*2d:%*2d%2s", &hr, am_pm);

    if (strcmp(am_pm,"AM")==0) {
        if (hr==12)hr=0;  
    } else {
        if (hr!=12)hr+=12;  
    }

    // Format the result
    sprintf(convertedTime,"%02d", hr);
    strncat(convertedTime,inputTime + 2, 6);  

    printf("%s\n",convertedTime);
}

int main() {
    char timeString[11];  
    scanf("%s",timeString);

    convertTo24HourFormat(timeString);

    return 0;
}
