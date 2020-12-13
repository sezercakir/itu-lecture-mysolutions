#include <stdio.h>
#include <stdlib.h>

int main()
{
    int year;
    int month;
    int day;
    printf("Enter date [year month day]: ");
    scanf("%d %d %d", &year, &month, &day);

    int max_days = 0;
    if (month == 2) {
        max_days = 28;
    } else if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
        max_days = 30;
    } else {
        max_days = 31;
    }

    if (day > max_days || day <1 || month>12 || month<1) {
        printf("Invalid date.\n");
        return EXIT_FAILURE;
    }

    int end_year;
    printf("Enter end year: ");
    scanf("%d", &end_year);
    
    if(end_year <= year){
	printf("Invalid date.\n");
	return EXIT_FAILURE;
    }
    

    int y = month < 3 ? year - 1 : year;
    int m = month < 3 ? month + 12 : month;
    int q = day;

    int j = y / 100;
    int k = y % 100;
    int h = (q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    switch (h) {
        case 0:
            printf("It's a Saturday.\n");
            break;
        case 1:
            printf("It's a Sunday.\n");
            break;
        case 2:
            printf("It's a Monday.\n");
            break;
        case 3:
            printf("It's a Tuesday.\n");
            break;
        case 4:
            printf("It's a Wednesday.\n");
            break;
        case 5:
            printf("It's a Thursday.\n");
            break;
        case 6:
            printf("It's a Friday.\n");
            break;
      }

    int counter = 0;
    for (int y = year + 1; y <= end_year; y++) {
        int jj = y / 100;
        int kk = y % 100;
        int hh = (q + 13 * (m + 1) / 5 + kk + kk / 4 + jj / 4 + 5 * jj) % 7;
        if (hh == h) {
            counter++;
        }
    }
    printf("Same day-and-month on same weekday between %d and %d: %d\n",
           year + 1, end_year, counter);
    return EXIT_SUCCESS;
}
