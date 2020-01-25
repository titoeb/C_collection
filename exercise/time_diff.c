#include <stdio.h>

struct time_date{
    int seconds;
    int minutes;
    int hours;
    int days;
    int month;
    int years;
};
void time_diff(struct time_date time1, struct time_date time2);

int main(void){
    struct time_date date1 = {10, 50, 12, 1, 10, 2018};
    struct time_date date2 = {05, 50, 12, 1, 10, 2018};
    
    time_diff(date1, date2);
	return 0;
}

void time_diff(struct time_date time1, struct time_date time2){
    printf("The difference between the two dates are %d years, %d months, %d days, %d hours, %d minutes and %d seconds",
    time1.years - time2.years, time1.month - time2.month, time1.days - time2.days, time1.hours - time2.hours,
    time1.minutes - time2.minutes, time1.seconds - time2.seconds);
}

