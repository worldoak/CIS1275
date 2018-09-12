//MeadowsP1 was written by Gavin Meadows, who can be reached at gmeadows@cnm.edu

#include <iostream>
using namespace std;

int main()
{
	const double pi = 3.14159, packingFactor = 0.8; //setting pi and the value used to account for empty space in the jar
	float jarHeight, jarDiameter, jarThickness; //dimensions of the jar to be obtained from user
	float beanLength = 0.625, beanDiameter = 0.25; //known dimensions of the beans to be used
	double jarRadius, jarVolume, beanVolume, nBeans; //calculations might result in very precise values, so these are given more room
	
	//display basic header:
	cout << "This is MeadowsP1, the Jelly Bean Counter" << endl
		<< "With a few measurements from you, this program" << endl
		<< "will help you estimate the number of jelly" << endl
		<< "beans that fit in a given jar. By Gavin Meadows" << endl;

	//ask the user for values needed for calculation
	cout << "\nFirst, please enter the height of the jar in inches:" << endl;

	cin >> jarHeight;

	cout << "\nThanks! Now enter the diameter of the jar:" << endl;

	cin >> jarDiameter;

	cout << "\nAwesome, just one more, how thick is the glass?" << endl;

	cin >>  jarThickness;

	//all necessary variables are now populated, this next section will do all of the math
	jarRadius = (jarDiameter / 2.0) - jarThickness; //the 'internal' radius needs to be adjusted for glass thickness
	jarVolume = pi * (jarRadius * jarRadius) * jarHeight; //pi times radius squared times height is the total internal volume
	beanVolume = beanLength * (beanDiameter * beanDiameter) * (4.0 / 3.0) * pi; //find a single bean's volume with 4/3 pi times length and diameter squared 
	nBeans = (packingFactor * jarVolume) / beanVolume; //how many bean volumes fit in the jar after accounting for air space

	//begin output to user, in segments
	cout << "\nOkay, let's see here..." << endl
		<< "\nThe jar is " << jarHeight << " inches tall, and " << jarDiameter << " inches across." << endl
		<< "If the glass is " << jarThickness << " inches thick," << endl
		<< "that leaves an internal volume of " << jarVolume << " cubic inches." << endl; //summarize inputs and jar calculations
	
	cout << "\nJelly beans are " << beanLength << " inches long and " << beanDiameter << " inches across." << endl
		<< "Meaning each one takes up just " << beanVolume << " cubic inches." << endl; //reveal internal variables related to bean size

	cout << "\nSince the beans will have a bit of air around them, we estimate" << endl
		<< "that they will fill about " << packingFactor * 100 << "% of the total space in the jar" << endl; //explain the packing factor

	cout << "\nThat means your jar will hold right around " << static_cast<int>(nBeans) << " jelly beans!" << endl
		<< "\nHave fun winning the contest, and if you want to check another jar" << endl
		<< "you can always run this program again. Goodbye!" << endl; //print the answer, casted to an int to avoid partial beans, then give goodbye message

	return 0; //if user needs additional calculations, they can run the program again, for now we exit after one iteration
}