#include <stdio.h> 

// This function recives real number x, x >= 0, and returns the next smallest perfect square.
// Example: x = 37, a = 36;
int findStartNumber(double x){

	int a = 0;

	while (a*a < x){

		if((a+1)*(a+1) > x) break;

		a++;	

	}

	return a;

}

// This function recives real number 'target', target >=0; integer a >= 0; real number dx > 0;
// The var 'target' is the number we want to find the square root.
// The var 'a' is the next smallest perfect square from 'target'
// The var 'dx' is the increase from f(x) = squareroot(x); 
double findSquareRoot(double target, int a, double dx){

	double x = (double) a*a, aprox = (double) a;
			
	while (x+dx < target){

		// dy is calculated by the differential of f(x) = squareroot(x)
		double dy = (aprox * dx) / (2*x);

		x+=dx;

		aprox+=dy;

	}

	return aprox;

}

int main(){
	
	double x;
	
	printf("Enter a number x > 0 to calculate the square root: ");
	scanf("%lf", &x);
	int a = findStartNumber(x);

	double result = findSquareRoot(x, a, 0.000001f);

	printf("\n\n---------- RESULTS ----------\n\n"); 
	printf("Raiz quadrada de %lf = %.12lf\n", x, result);
	printf("VERIFICANDO: %.12lf * %.12lf = %.12lf", result, result, (result*result)); 
	printf("\n\n-----------------------------\n\n");

	return 0;

}
