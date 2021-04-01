#include<iostream>
#include<cmath>
#include<vector>
#include<random>
#include<cstdlib>

void print(std::vector <int> &a, int N);
bool boundaries(std::vector <int> &a, int x, int y, int N);

int main(int argc, char* argv[])
{
    int size = std::atoi(argv[1]);
    std::vector<int> a(size*size, 0);

    std::mt19937 gen(1);
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    int a1=int(0.5*size), a2=int(0.5*size);
    for (int ii=0; ii<size; ii++){
        //a[int((size*size/2))+ii]=1;
    }

    a[a1*size+a2]=1;
    int N_par=10000; //particulas a depositar
    for(int ii=0; ii<N_par; ii++){
        double x =dis(gen)*2*M_PI;
        a1=int(std::sin(x)*size/2+size/2);
        a2=int(std::cos(x)*size/2+size/2);
        while(boundaries(a, a1, a2, size)==false)
        {
            int random = rand() % 3;
            a1=(a1+random-1+size)%size;
            random = rand() % 3;
            a2=(a2+random-1+size)%size;
        }
        a[a1*size+a2]=1;
        //boundaries
    }

    print(a, size);
    return 0;
    
}

void print(std::vector <int> &a, int N)
{
    for(int i=0;i<N;i++)
    {
      for(int ii=0;ii<N;ii++)
	{
	  std::cout<<i<<" "<<ii<<" "<<a[i*N+ii]<<" "<<std::endl;
	}
     
    }

}

bool boundaries(std::vector <int> &a, int x, int y, int N)
{
    int b1=(x+1)%N, b2=(x+N-1)%N, b3=(y+1)%N, b4=(y+N-1)%N;
        if(a[x*N+b3]==1) return true;
        else if( a[x*N+b4]==1) return true;
        else if( a[b1*N+y]==1) return true;
        else if (a[b2*N+y]==1) return true;
        else return false;
}
