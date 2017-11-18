#include <iostream>
#include  <GL/freeglut.h>
#include <ctime>
#include <cstdlib>
#include <cmath>


using namespace std;
double **arr;
double ** arr_x;
double ** arr_y;
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
			if (arr[j][0] > arr[j+1][0])
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
    int storona =0;
    int tochka=0;
    int x_y =1;
	arr_x= new double* [n*n];
	for (int i=0; i < n*n ; i++)
		arr_x[i] = new double [2];
	for (int i=0; i < n*n ; i++)
		arr_x[i][0]= arr_x[i][1] = 0;
	arr_y= new double* [n*n];
	for (int i=0; i < n*n ; i++)
		arr_y[i] = new double [2];
	for (int i=0; i < n*n ; i++)
		arr_y[i][0]= arr_y[i][1] = 0;
	b=0;
    for (int i=0; i < n ; i++)
        {   
            storona =0;
            for (int j=0; j < n; j++)
                {
                    storona =0;
                    x_y=1;
                    for (int k=0; k < n; k++)
                        {
                            tochka = (arr[i][1] - arr[j][1])*arr[k][0] + (arr[j][0] - arr[i][0])*arr[k][1] + (arr[i][0]*arr[j][1] - arr[j][0]*arr[i][1] );
                          //  cout << tochka << " && ";
                            if (tochka > 0 && storona ==0)
                                {
                                    storona =1;
                                }
                            if (tochka < 0 && storona ==0)
                            {
                                storona =-1;                        
                            }
                            if (tochka*storona < 0)
                                {
                                    x_y=-1;
                                }

                        }
                    if (x_y > 0)
                        {
                            arr_x[b][0] = arr[i][0];
                            arr_x[b][1] = arr[i][1];
                            arr_y[b][0] = arr[j][0];
                            arr_y[b][1] = arr[j][1];
                            b++;
                        }
                }

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

for (int i=0; i < b; i++)
	{
        glVertex2f(arr_x[i][0],arr_x[i][1]);
        glVertex2f(arr_y[i][0],arr_y[i][1]);
    }



glEnd(); 

glutSwapBuffers();

}




