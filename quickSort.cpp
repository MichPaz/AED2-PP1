#include <iostream>
#include <vector>

void troca(int* x, int* y)
{
	int aux = *x;
	*x = *y;
	*y = aux;
}

int particao(std::vector<int>& A, int p, int r)
{
	int x = A[p];
	int tmp = A[r+1];
	A[r+1] = x;

	int i = p;
	int j = r+1;
	
	while (true){
		//I used do while because the while version wasn't working at all
		//Actually, I was just too dumb to understand that all I needed to do was use <= instead of <
		//fml
		do{
			i++;
		}while(A[i] < x);

		do{
			j--;
		}while(A[j] > x);

		if (i < j){
			troca(&A[i],&A[j]);
		}
		else{
			troca(&A[p],&A[j]);
			A[r+1] = tmp;
			break;
		}
	}
	return j;
}

void quickSort(std::vector<int>& A, int p, int r)
{
	if (p < r){
		int q = particao(A,p,r);
		quickSort(A,p,q-1);
		quickSort(A,q+1,r);
	}
}

int main(int argc, char* args[])
{
	std::vector<int> A = {3,0,4,1,2,5,6,8,9,7};

	for (int i = 0; i < A.size(); i++)
		std::cout << A[i] << " ";
	
	std::cout << std::endl;

	quickSort(A,0,A.size());

	for (int i = 0; i < A.size(); i++)
		std::cout << A[i] << " ";
	std::cout << std::endl;
	

	return 0;
}
