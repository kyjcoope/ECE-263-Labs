/*
Program Name: Lab 1
Author's Name: Kyle Cooper
Class, day, & time: ECE 263, Friday, 1:00pm-3:50pm
ID: 0003304926

Description: Allows you to enter cost per square foot of watered lawn,
lenght of lawn, and width of lawn; minus total area of
objects/buildings in lawn. To find out how much watering the lawn would cost.
*/

   #include <stdio.h>

   /* Constants */

   #define PI 3.1416
   #define dog_house_top 12
   #define dog_house_base 34
   #define dog_house_height 8
   #define vaule_a_fountain 4
   #define vaule_b_fountain 3
   #define storage_left_side 10
   #define storage_right_side 3
   #define storage_top 8
   #define storage_bottom 22
   #define garage_side 9
   #define garage_top 16
   #define pool_radius 13.32

   int main()
{
   /* Variable Decleration */

   float area_dog_house;

   float area_fountain;

   float area_storage_square;
   float area_storage_triangle;
   float area_storage_rectangle;

   float area_garage;

   float area_pool;

   float water_cost;

   float lawn_lengh;
   float lawn_width;

   /*Areas*/


    //Area for Dog House
   area_dog_house = ((dog_house_top+dog_house_base) * dog_house_height)/2;

   // Area for Fountain
   area_fountain = PI * vaule_a_fountain * vaule_b_fountain;

   //Area for Storage
   area_storage_square = storage_left_side * storage_top;
   area_storage_triangle = ((storage_left_side - storage_right_side)*
   (storage_bottom - storage_top)) / 2;
   area_storage_rectangle = (storage_bottom - storage_top)*storage_right_side;

   //Area for Garage
   area_garage = garage_top * garage_side;

   //Area for Pool
   area_pool = PI * pool_radius * pool_radius;


   /*Enter Cost of Water, lawn Lengh, and lawn Width*/
   printf ("Enter cost of water per square foot of lawn: $");
   scanf  ("%f", &water_cost);
   printf ("Enter lawn lenght in feet:");
   scanf  ("%f", &lawn_lengh);
   printf ("Enter lawn height in feet:");
   scanf  ("%f", &lawn_width);

   /*Show total cost to water lawn*/

   printf("Total cost = $%f\n", ((lawn_lengh*lawn_width)-
   (area_dog_house+area_fountain+area_storage_rectangle+area_storage_square
   +area_storage_triangle+area_garage+area_pool))*water_cost);

   return 0;

 }