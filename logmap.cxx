#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ofstream out ("HA2_out.dat");
	int Nskip = 100; //Number of iterations to skip
	int Nend  = 200; //Number of total iterations
	int N = Nend - Nskip; // Number of iterations, die ausgegeben werden sollen 
			      //(erste 100 sollen abgeschnitten werden)
	double X[N];  	
	double x0= 0.5;	//initial x


	  for(double r=0; r <= 4; r += 0.001){
	    double x = x0;
	    for(int i=1; i <= Nskip; i++)
		   x = r*x*(1-x);
	    for(int i=Nskip+1; i <= Nend; i++){
	   		   x= r*x*(1-x);
	   		   X[i-Nskip-1] = x; //speichert errechnetes x in array X
			   
   	   }
   	   for (int n = 0 ; n<N;n++){
	    out << r << "\t" << X[n] << endl;//gibt r und dazugehörigen x wert in Datei aus
	  
	}
	}
	
	
	  

	out.close(); //schließt Datei
	return 0;
}
