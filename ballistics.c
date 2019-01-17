/** Creates a ballistics table.
  */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**The gravitational constant of Earth. */
#define G_CONSTANT 9.81

/** Calculates the total flight time.
  * @param angle - The angle of launch.
  * @param v0 - the initial velocity.
  */
double flightTime( int angle, double v0 )
{
  double total_time = 0;
  double rad_angle = angle * (M_PI / 180);
  total_time = (2 * (v0 * sin(rad_angle))) / G_CONSTANT;
  return total_time;
}

/** Prints a row of the table.
  * @param angle - The angle of launch.
  * @param v0 - The initial velocity.
  * @param t - The total flight time.
  */
void tableRow( int angle, double v0, double t )
{
  double rad_angle = angle * (M_PI / 180);
  double distance = v0 * t * cos(rad_angle);
  printf("%10d | %10.3lf | %10.3lf | %10.3lf", angle, v0, t, distance);
}

/** Main.
  */
int main()
{
  double initVelocity;
  printf("V0: ");
  scanf("%lf", &initVelocity);

  printf("\n%10s | %10s | %10s | %10s\n", "angle", "v0", "time", "distance");
  printf("-----------+------------+------------+-----------");
  
  double flight_time = 0;
  for(int angle = 0; angle <= 90; angle += 5){
    putchar('\n');
    flight_time = flightTime(angle, initVelocity);    
    tableRow(angle, initVelocity, flight_time);
  }
  putchar('\n');
  return 0;
}
