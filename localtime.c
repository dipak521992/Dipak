#include <stdlib.h> 
#include <stdio.h> 
#include <time.h> 
#define LMS_PLAN_DATE_L 8
#define LMS_START_TIME_L 6
struct test {
time_t  it1;
};
int main()
{
 char lms_start_time[LMS_START_TIME_L + 1] = {0};
 char lms_plan_date [LMS_PLAN_DATE_L+1] = {0};
 time_t lt;
 int it;
 struct test test1;
 lt = time(0);
 strftime(lms_plan_date,sizeof(lms_plan_date), "%m%d%Y",
                                                    localtime(&lt));
 strftime(lms_start_time, sizeof(lms_start_time), "%H""%M""%S",
                                                     localtime(&lt));
 printf("%s\n",lms_plan_date);
 printf("%s\n",lms_start_time);


 test1.it1= time(0);
 /* memset(lms_plan_date,NULL,sizeof(lms_plan_date));
 memset(lms_start_time,NULL,sizeof(lms_start_time));*/
 strftime(lms_plan_date,sizeof(lms_plan_date), "%m%d%Y",
                                                    localtime(&test1.it1));
 strftime(lms_start_time, sizeof(lms_start_time), "%H""%M""%S",
                                                    localtime(&test1.it1));
 printf("%s\n",lms_plan_date);
 printf("%s\n",lms_start_time);
 printf("    rs.plan_tm = %d\n", test1.it1);

 return 0;
}
