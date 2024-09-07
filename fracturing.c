#include <stdio.h>
#include <math.h>
#define PI 3.14159
//********************************************************
// fracturing.c
// Author: Jaedyn Quinlan-Sadler
// UCFID: 5666720
// Date: 9/4/24
// Class: COP 3223C, Professor Parra
// Purpose: Understanding 'fracturing' code.
// Input: Various x-values and y-values
//
// Output: The distance between two points, the area and perimeter of a circle relative to two points, as well as the width/height between two points
// //********************************************************
/* IMPORTANT NOTE, add the "-lm" switch to the end of the terminal input to compile in order to let the compiler know that an additional header
is being used on top of standard library.
It should look like this
gcc -o fracturing fracturing.c -lm
 */ 
double calculateDistance(){
    // variable initialization for the x-value and y-value of the two user-inputted points respectively.
    double xOne,yOne;
    double xTwo,yTwo;
    printf("Select x-value #1: ");
    scanf("%lf", &xOne);
    printf("Select x-value #2: ");
    scanf("%lf", &xTwo);
    printf("Select y-value #1: ");
    scanf("%lf", &yOne); 
    printf("Select y-value #2: ");
    scanf("%lf", &yTwo);
    // The mathematical operations that are in-line with the formula for calculating the distance between two points.
    double xValSquared=(xTwo-xOne)*(xTwo-xOne);
    double yValSquared=(yTwo-yOne)*(yTwo-yOne);
    double underRoot=xValSquared+yValSquared;
    double distanceResult=sqrt(underRoot);
    // Print statements that tell user the points they inputted, and the distance between them.
    printf("Point #1 entered: \nx1 = %lf; ",xOne);
    printf("y1 = %lf \n", yOne);
    printf("Point #2 entered: \nx2 = %lf; ",xTwo);
    printf("y2 = %lf \n", yTwo);
    printf("The distance between the two points is %lf \n", distanceResult);
    // Returns the value of the distance to be used in other functions.
    return distanceResult;
}
double calculatePerimeter(){
    // Call for the calculateDistance function, to use the value of distance in the next series of mathematical operations.
    double perimeterDistanceResult=calculateDistance();
    // Conversion of the distance between two points on a circle, from diameter to radius, to insure that it isn't multiplied 4x instead of 2x.
    perimeterDistanceResult=(perimeterDistanceResult/2);
    // Perimeter, or circumference, of the circle formula.
    double perimeterComputedAnswer=(2*PI*perimeterDistanceResult);
    // Print statement that prints the perimeter/circumference of the circle.
    printf("The perimeter of the city encompassed by your request is %lf \n", perimeterComputedAnswer);
    return 2.5;
}
double calculateArea(){
    // Call for the calculateDistance function, to use the value of distance in the next series of mathematical operations.
    double areaDistanceResult=calculateDistance();
    // Halving and then squaring of the distance in order to get the radius, and then radius squared. 
    areaDistanceResult=(areaDistanceResult/2);
    areaDistanceResult*=areaDistanceResult;
    // Area of a circle formula.
    double areaComputedAnswer=PI*areaDistanceResult;
    // Print statement that prints the area of the circle.
    printf("The area of the city encompassed by your request is %lf \n", areaComputedAnswer);
    return 2.0;
}
double calculateWidth(){
    // variable initialization for the x-values and their respective width of the x-values.
    double widthComputed;
    double widthXOne,widthXTwo;
    // Input statements for the user to type out values
    printf("Select x-value #1: ");
    scanf("%lf", &widthXOne);
    printf("Select x-value #2: ");
    scanf("%lf", &widthXTwo);
    // Computes the width between the x-values.
    widthComputed=(widthXOne-widthXTwo);
    // Checks if the computed value is negative, correcting it to get the absolute value if it IS negative.
    if (widthComputed<0){
        widthComputed=(-1*widthComputed);
    }   
    printf("The width of the city encompassed by your request is %lf \n", widthComputed);
    return 1.0;
}
double calculateHeight(){
    // variable initialization for the y-values and their respective height of the y-values.
    double heightComputed;
    double heightYOne,heightYTwo;
    // Input statements for the user to type out values
    printf("Select y-value #1: ");
    scanf("%lf", &heightYOne); 
    printf("Select y-value #2: ");
    scanf("%lf", &heightYTwo);
    // Computes the height between the y-values.
    heightComputed=(heightYOne-heightYTwo);
    // Checks if the computed value is negative, correcting it to get the absolute value if it IS negative.
    if (heightComputed<0){
        heightComputed=(-1*heightComputed);
    }   
    printf("The height of the city encompassed by your request is %lf \n", heightComputed);
    return 1.0;
}
int main(int argc, char **argv){
    // Main function that is used to call the other functions, as seen below.
    calculateDistance();
    calculatePerimeter();
    calculateArea();
    calculateWidth();
    calculateHeight();
    // return 0 value, meant to be for the autograder to work.
    return 0;
}