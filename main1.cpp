#include <iostream>
#include  <GL/freeglut.h>
#include <ctime>
#include <cstdlib>
#include <cmath>


using namespace std;
double **arr;
double ** arr_left;
double ** arr_right;
int n=0, b=0;


void read_from_con();
void sort();
void renderScene(void);
void out_from_consol();
void read_rand();
void postroenie ();

/*void onKey(char key, int x, int y)
{
	if(key == 'a') {
		arr
	}
	glutPostRedisplay();
}		*/

int main(int argc, char **argv) {
 

	double x,y;
	cin >> n;
	arr= new double* [n];
	for (int i=0; i < n ; i++)
		arr[i] = new double [2];
	for (int i=0; i < n ; i++)
		arr[i][0]= arr[i][1] = 0;
//	read_from_con();

	

	read_rand();
	out_from_consol();
	sort();
	postroenie();
	
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,600);
	glutCreateWindow("Урок 1");
	gluOrtho2D(1, 80, 1, 60);
	
	//glutKeyboardFunc(onKey);


	glutDisplayFunc(renderScene);
	


	glutMainLoop();
 
	return 0;
}

void read_from_con()
{
	for (int i=0; i < n; i++)
			cin >> arr[i][0] >> arr[i][1];

}

void sort()
{
	double * t = NULL;
	for(int i=1; i < n-1; ++i)
		for (int j=0; j < n-i;++j)
			if (arr[j][1] > arr[j+1][1])
				{
				t = arr[j];
				arr[j] = arr[j+1];
				arr[j+1]= t;
				t = NULL;
				}
}

void out_from_consol()
{
	for (int i=0; i < n; i++)
		cout << arr[i][0] << " ; " << arr[i][1] << endl;
}

void read_rand()
{
	srand(time(NULL));
	for (int i=0; i < n; i++)
		{
			arr[i][0] = static_cast<double>(rand()%790)/10 +1;
			arr[i][1] = static_cast<double>(rand()%590)/10 +1;
		}

}



void postroenie ()
{
	int a=0, maxi, mini, k=0 , l=0;
	double  max, min;
	arr_left= new double* [n];
	for (int i=0; i < n ; i++)
		arr_left[i] = new double [2];
	for (int i=0; i < n ; i++)
		arr_left[i][0]= arr_left[i][1] = 0;
	arr_right= new double* [n];
	for (int i=0; i < n ; i++)
		arr_right[i] = new double [2];
	for (int i=0; i < n ; i++)
		arr_right[i][0]= arr_right[i][1] = 0;
	
	while (a < n)
	{
		max = arr[a][0];
		min = arr[a][0];
		maxi = mini= a;
		a++;
		if (a < n)
		{
			while ((arr[a][1] == arr[a-1][1]))
				{
					cout << a << " ^ " << arr[a][0] << " ^ " << arr[a][1]<< endl;
					if (max < arr[a][0])
						{
							max = arr[a][0];
							maxi= a;
						}
					if (min > arr[a][0])
						{
							min  = arr[a][0];
							mini= a;
						}
					
					a++;
					if (a == n)
						break;
				}	 
		}
		arr_right[b][0] = arr[maxi][0];
		arr_right[b][1] = arr[maxi][1];
		arr_left[b][0]  = arr[mini][0];
		arr_left[b][1]  = arr[mini][1];
		b++;


	}

	cout << "----------------------" << endl;
	for (int i=0; i < b; i++)
	cout << arr_right[i][0] << " ; " << arr_right[i][1] << endl;
	cout << "----------------------" << endl;
	for (int i=0; i < b; i++)
	cout << arr_left[i][0] << " ; " << arr_left[i][1] << endl;
	double * t = NULL;

/*	while (k < b-2)
	{
		if (arr_left[k+1][0] >= ((arr_left[k+1][1]-arr_left[k][1])*(arr_left[k+2][0]-arr_left[k][0])/(arr_left[k+2][1]-arr_left[k][1])+arr_left[k][0]))
			{
				arr_left[k+1][0] = arr_left[k+1][1]=0; 
				for(int i=1; i < b-1; ++i)
				for (int j=0; j < b-i;++j)
					if (arr_left[j][1] > arr_left[j+1][1])
						{
						t = arr_left[j];
						arr_left[j] = arr_left[j+1];
						arr_left[j+1]= t;
						t = NULL;
						}
				k++;
			}
		else k++;
	}
	k=0;
	while (k < b-2)
	{
		if (arr_right[k+1][0] <= ((arr_right[k+1][1]-arr_right[k][1])*(arr_right[k+2][0]-arr_right[k][0])/(arr_right[k+2][1]-arr_right[k][1])+arr_right[k][0]))
			{
				arr_right[k+1][0] = arr_right[k+1][1]=0; 
				for(int i=1; i < b-1; ++i)
				for (int j=0; j < b-i;++j)
					if (arr_right[j][1] > arr_right[j+1][1])
						{
							t = arr_right[j];
							arr_right[j] = arr_right[j+1];
							arr_right[j+1]= t;
							t = NULL;
						}
				k++;
			}
		else k++;
	}
	
	for(int i=1; i < b-1; ++i)
		for (int j=0; j < b-i;++j)
			if (arr_left[j][1] > arr_left[j+1][1])
				{
				t = arr_left[j];
				arr_left[j] = arr_left[j+1];
				arr_left[j+1]= t;
				t = NULL;
				}
	for(int i=1; i < b-1; ++i)
		for (int j=0; j < b-i;++j)
			if (arr_right[j][1] > arr_right[j+1][1])
				{
					t = arr_right[j];
					arr_right[j] = arr_right[j+1];
					arr_right[j+1]= t;
					t = NULL;
				} */
	
	double ugol = 0, max_ugol=0; 
	double c1=0,c2=0;
	int maxi_ugol =0;
	while (k < b-1)
		{
			max_ugol =0;
			for (int i=k+1; i < b; i++)
				{
					c1 = arr_right[i][1]-arr_right[k][1];
					c2 = pow (pow (arr_right[i][1]-arr_right[k][1], 2)+ pow(arr_right[i][0]-arr_right[k][0], 2), 0.5);
					if (arr_right[k][0] < arr_right[i][0])
						ugol = M_PI - asin(c1/c2);
					else ugol = asin(c1/c2);
					if (ugol > max_ugol)
						{
							max_ugol = ugol;
							maxi_ugol = i;
						}
				}
			for (int i=k+1; i < maxi_ugol; i++)
				{
					arr_right[i][1]= arr_right[i][0] = 0;
				}
		
			for(int i=1; i < b-1; ++i)
		 		for (int j=0; j < b-i;++j)
					if (arr_right[j][1] > arr_right[j+1][1])
						{
							t = arr_right[j];
							arr_right[j] = arr_right[j+1];
							arr_right[j+1]= t;
							t = NULL;
						}
			k = maxi_ugol;
			for (int i=0; i < b ; i++)
						cout << arr_right[i][0] << " , " << arr_right[i][1] << " :: " ;
			cout << endl;
		}			
	
		k=0;
		c1 = c2 =0;
		ugol = 0;
		double min_ugol=2*M_PI;
		int mini_ugol =0;

		while (k < b-1)
		{
			min_ugol=2*M_PI;
			for (int i=k+1; i < b; i++)
				{
					c1 = arr_left[i][1]-arr_left[k][1];
					c2 = pow (pow (arr_left[i][1]-arr_left[k][1], 2)+ pow(arr_left[i][0]-arr_left[k][0], 2), 0.5);
					if (arr_left[k][0] < arr_left[i][0])
					ugol = M_PI - asin(c1/c2);
				else ugol = asin(c1/c2);
					if (ugol < min_ugol)
						{
							min_ugol = ugol;
							mini_ugol = i;
						}
				}
			for (int i=k+1; i < mini_ugol; i++)
				{
					arr_left[i][1]= arr_left[i][0] = 0;
				}
		
			for(int i=1; i < b-1; ++i)
		 		for (int j=0; j < b-i;++j)
					if (arr_left[j][1] > arr_left[j+1][1])
						{
							t = arr_left[j];
							arr_left[j] = arr_left[j+1];
							arr_left[j+1]= t;
							t = NULL;
						}
			k = mini_ugol;
			for (int i=0; i < b ; i++)
			cout << arr_left[i][0] << " , " << arr_left[i][1] << " && " ;
cout << endl;
		}			

}




void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 

glPointSize(5);
glBegin (GL_POINTS);
glColor3f(1.0, 0.0, 0.0);

for (int i=0; i < n; i++)
	glVertex2f(arr[i][0],arr[i][1]);

glEnd();

glBegin(GL_LINES);
glColor3f(0.0, 1.0, 0.0);

for (int i=0; i < b-1; i++)
	{
		if (arr_left[i][1]!=0)
			{
				glVertex2f(arr_left[i][0],arr_left[i][1]);
				glVertex2f(arr_left[i+1][0],arr_left[i+1][1]);
			}
		if (arr_right[i][1]!=0)
		{
			glVertex2f(arr_right[i][0],arr_right[i][1]);
			glVertex2f(arr_right[i+1][0],arr_right[i+1][1]);
		}
	}
int k=0, l=0;;
while (arr_left[k][1] == 0)
	k++;
while (arr_right[l][1] == 0)
	l++;


glVertex2f(arr_right[l][0],arr_right[l][1]);
glVertex2f(arr_left[k][0],arr_left[k][1]);

glVertex2f(arr_right[b-1][0],arr_right[b-1][1]);
glVertex2f(arr_left[b-1][0],arr_left[b-1][1]);


glEnd(); 

glutSwapBuffers();

}




