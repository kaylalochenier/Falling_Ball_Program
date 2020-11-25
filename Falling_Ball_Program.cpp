/*
Kayla Chenier
20871506
SYDE 121 Assignment 2 Question 2
Filename: a2_q2

I hearby declare that this code, submitted for credit for the course
SYDE121, is a product of my own efforts. This coded solution has
not been plagirised from other sources and not been knowingly
plagitized by others.

Project: Baseball falling from drone
Purpose: Write a program that will output the distance the ball has fallen in each 1-second 
interval when dropped from a drone.
Due Date Friday October 9,2020
*/
/*Testing: i used 1500 for most of my testing, escpecially in Stem 2, but i also made sure it worked at bigger 
numbers (15,000 and 20,000) as well as smaller numbers (10, and 50)
Here ar the results for 1500 (Step 2- with the smaller intervals once close to ground:
time (in sec):          distance during interval (in m):        total distance (in m):
1                       4.903                                   4.903
2                       14.710                                  19.613
3                       24.517                                  44.130
4                       34.323                                  78.453
5                       44.130                                  122.583
6                       53.937                                  176.520
7                       63.743                                  240.263
8                       73.550                                  313.813
9                       83.357                                  397.169
10                      93.163                                  490.332
11                      102.970                                 593.302
12                      112.776                                 706.079
13                      122.583                                 828.662
14                      132.390                                 961.052
15                      142.196                                 1103.248
16                      152.003                                 1255.251
17                      161.810                                 1417.061
18                      171.616                                 1588.677
19                      181.423                                 1770.100
20                      191.230                                 1961.330
21                      201.036                                 2162.366
22                      210.843                                 2373.209
23                      220.650                                 2593.859
24                      230.456                                 2824.315
25                      240.263                                 3064.578
26                      250.070                                 3314.648
27                      259.876                                 3574.524
28                      269.683                                 3844.207
29                      279.490                                 4123.696
30                      289.296                                 4412.992
31                      299.103                                 4712.095
32                      308.909                                 5021.005
33                      318.716                                 5339.721
34                      328.523                                 5668.244
35                      338.329                                 6006.573
36                      348.136                                 6354.709
37                      357.943                                 6712.652
38                      367.749                                 7080.401
39                      377.556                                 7457.957
40                      387.363                                 7845.320
41                      397.169                                 8242.489
42                      406.976                                 8649.465
43                      416.783                                 9066.248
44                      426.589                                 9492.837
45                      436.396                                 9929.233
46                      446.203                                 10375.436
47                      456.009                                 10831.445
48                      465.816                                 11297.261
49                      475.623                                 11772.883
50                      485.429                                 12258.313
51                      495.236                                 12753.548
52                      505.042                                 13258.591
53                      514.849                                 13773.440
54                      524.656                                 14298.096
55                      534.462                                 14832.558
55.1                    53.986                                  14886.544
55.2                    108.069                                 14940.627
55.3                    162.251                                 14994.809
55.4                    167.442                                 15000.000*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/*	Step 1: calculate the distance fallen over the firt 30 seconds
	Step 2: calculate it's fall from 1500 meters*/

//create a function that will calculate the distance the baseball drops in ech time interval
void num() {
	/*create variables for the distance from ground (1500m), the distance the ball has travveled, 
	the distance the ball has fallen in that interval, the time the ball had been falling, and the 
	a temporary varible for the cummulative distance the ball has dropped, */
	double distance_from_ground = 15000;
	double cummulative_distance = 0;
	double interval_distance = 0;
	double time = 0;
	double last_cummulative_distance= 0;

	//output the column titles
	cout << "time (in sec):\t\tdistance during interval (in m):\ttotal distance (in m):";

	//Step 1: caluclate the distance the fall falls over the first 30 seconds in one second interval
	//Step 2: calculate the distance fallen until it gets close to the ground- aka when it is less than
	//one second from the ground
	//Step 1: create a while loop that will repeat 30 times
	//Step 2: edit the for loop to last until the ball is less than a second from hitting the ground
	while (cummulative_distance < distance_from_ground) {
		//increase time by one second
		time++;
		//make the temp cummulative distance variable equal the current cummulative distance value then update the 
		//new cummulative distance value
		last_cummulative_distance = cummulative_distance;
		cummulative_distance = (.5) * (9.80665) * (pow(time, 2));
		//use the temp cummulative distance and the new one to find the distance it travelled in the last interval
		interval_distance = cummulative_distance - last_cummulative_distance;
		// output the varibles if it still isn't on the ground
		if (cummulative_distance < distance_from_ground) {
			cout << "\n" << fixed << setprecision(0) << time << "\t\t\t" << fixed << setprecision(3) << interval_distance << "\t\t\t\t\t" << cummulative_distance;
		}
	}
	//Step 2: when the ball is less that a second from the ground, decrese the time interval to .1 second intervals
	//undo the last time interval
	time --;
	cummulative_distance = (.5) * (9.80665) * (pow(time, 2));
	
	//repeat the above while loop but for .1 second intervals
	while (cummulative_distance < distance_from_ground) {
		time += .1;
		cummulative_distance = (.5) * (9.80665) * (pow(time, 2));
		interval_distance = cummulative_distance - last_cummulative_distance;
		if (cummulative_distance < distance_from_ground) {
			cout << "\n" << fixed << setprecision(1) << time << "\t\t\t" << fixed << setprecision(3) << interval_distance << "\t\t\t\t\t" << cummulative_distance;
		}
	}
	//when less than .1 seconds from ground, jst outout the time it took for the ball to is the ground
	interval_distance = distance_from_ground - last_cummulative_distance;
	cout << "\n" << fixed << setprecision(1) << time << "\t\t\t" << fixed << setprecision(3) << interval_distance << "\t\t\t\t\t" << distance_from_ground;
} 

//create a main function
int main() {
	//call the function
	num();
}